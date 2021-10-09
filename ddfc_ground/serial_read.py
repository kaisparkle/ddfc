import serial
import struct


class SerialReader:
    # reads the packet stream from serial and provides functions to get module data
    def __init__(self, port):
        # open serial port
        self.receiver = serial.Serial(port, 115200)

        # module IDs
        self.__MODULE_DUMMY_ID = 0
        self.__MODULE_GPS_ID = 1
        self.__MODULE_BMP_ID = 2

        # define empty dicts for data handling
        self.__packet_frame = {
            "magic",
            "module_id",
            "timestamp",
            "data_length",
            "data"
        }
        self.__bmp_data = {
            "temperature": 0.0,
            "pressure": 0,
            "altitude_from_pad": 0.0,
            "timestamp": 0
        }

        self.__gps_data = {
            "year": 0,
            "month": 0,
            "day": 0,
            "hours": 0,
            "minutes": 0,
            "seconds": 0,
            "latitude": 0.0,
            "longitude": 0.0,
            "altitude": 0.0,
            "speed": 0.0
        }

    def run(self):
        # pyserial will block until new data is received, so just loop
        while True:
            # do nothing until the first magic byte is found
            while self.receiver.read() != b'\xee':
                pass

            # make sure the next byte corresponds to the second packet magic byte
            if self.receiver.read() == b'\xa4':
                # ingest each section
                packet = self.receiver.read(30)
                self.__packet_frame = {
                    "magic": b'\xa4\xee',
                    "module_id": packet[0],
                    "timestamp": packet[1:5],
                    "data_length": packet[5],
                    "data": packet[6:31]
                }

                # BMP180
                if self.__packet_frame['module_id'] == self.__MODULE_BMP_ID:
                    # unpack the data as float, uint, and float
                    self.__bmp_data = {
                        # unpack outputs a tuple even if only one value, so only take the first tuple value
                        "temperature": struct.unpack('<f', self.__packet_frame['data'][0:4])[0],
                        "pressure": struct.unpack('<I', self.__packet_frame['data'][4:8])[0],
                        "altitude_from_pad": struct.unpack('<f', self.__packet_frame['data'][8:12])[0],
                        "timestamp": struct.unpack('<I', self.__packet_frame['timestamp'])[0]
                    }

                    print(f"Temperature: {self.__bmp_data['temperature']:.2f} degrees Celsius\n"
                          f"Pressure: {self.__bmp_data['pressure']} Pascal\n"
                          f"Altitude from pad: {self.__bmp_data['altitude_from_pad']:.2f} meters\n")

                # GPS
                if self.__packet_frame['module_id'] == self.__MODULE_GPS_ID:
                    print("GPS:" + hex(self.__packet_frame['data']))

    def get_bmp_pressure(self):
        return self.__bmp_data['pressure']

    def get_bmp_timestamp(self):
        return self.__bmp_data['timestamp']
