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
        self.__MODULE_HMC_ID = 3
        self.__MODULE_MPU_ID = 4

        # define empty dicts for data handling
        self.__packet_frame = {
            "magic",
            "module_id",
            "timestamp",
            "data_length",
            "data"
        }

        self.__gps_data = {
            "year": 0,
            "month": 0,
            "day": 0,
            "hours": 0,
            "minutes": 0,
            "seconds": 0,
            "latitude": 0,
            "longitude": 0,
            "altitude": 0,
            "speed": 0,
            "timestamp": 0
        }

        self.__bmp_data = {
            "temperature": 0.0,
            "pressure": 0,
            "altitude_from_pad": 0.0,
            "timestamp": 0
        }

        self.__hmc_data = {
            "mag_x": 0.0,
            "mag_y": 0.0,
            "mag_z": 0.0,
            "timestamp": 0
        }

        self.__mpu_data = {
            "gyro_x": 0.0,
            "gyro_y": 0.0,
            "gyro_z": 0.0,
            "accel_x": 0.0,
            "accel_y": 0.0,
            "accel_z": 0.0,
            "timestamp": 0
        }

    def run(self):
        # create logging file
        log_file = open("pyflightdata.dat", "a")
        log_file.write("Flight Data:\n")
        log_file.close()
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

                # open file for append
                log_file = open("pyflightdata.dat", "ab")
                log_file.write(bytes(b'\xa4\xee' + packet))
                log_file.close()

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
                    self.__gps_data = {
                        "year": struct.unpack('<H', self.__packet_frame['data'][0:2])[0],
                        "month": struct.unpack('<c', self.__packet_frame['data'][2:3])[0],
                        "day": struct.unpack('<c', self.__packet_frame['data'][3:4])[0],
                        "hours": struct.unpack('<c', self.__packet_frame['data'][4:5])[0],
                        "minutes": struct.unpack('<c', self.__packet_frame['data'][5:6])[0],
                        "seconds": struct.unpack('<c', self.__packet_frame['data'][6:7])[0],
                        "latitude": struct.unpack('<l', self.__packet_frame['data'][7:11])[0],
                        "longitude": struct.unpack('<l', self.__packet_frame['data'][11:15])[0],
                        "altitude": struct.unpack('<l', self.__packet_frame['data'][15:19])[0],
                        "speed": struct.unpack('<l', self.__packet_frame['data'][19:23])[0],
                        "timestamp": struct.unpack('<I', self.__packet_frame['timestamp'])[0]
                    }

                    print(f"Latitude: {self.__gps_data['latitude']}\n"
                          f"Longitude: {self.__gps_data['longitude']}\n"
                          f"Altitude: {self.__gps_data['altitude']} mm\n"
                          f"Ground speed: {self.__gps_data['speed']} mm/s\n")

                # HMC
                if self.__packet_frame['module_id'] == self.__MODULE_HMC_ID:
                    self.__hmc_data = {
                        "mag_x": struct.unpack('<f', self.__packet_frame['data'][0:4])[0],
                        "mag_y": struct.unpack('<f', self.__packet_frame['data'][4:8])[0],
                        "mag_z": struct.unpack('<f', self.__packet_frame['data'][8:12])[0],
                        "timestamp": struct.unpack('<I', self.__packet_frame['timestamp'])[0]
                    }

                    print(f"Mag X: {self.__hmc_data['mag_x']} mT\n"
                          f"Mag Y: {self.__hmc_data['mag_y']} mT\n"
                          f"Mag Z: {self.__hmc_data['mag_z']} mT\n")

                # MPU
                if self.__packet_frame['module_id'] == self.__MODULE_MPU_ID:
                    self.__mpu_data = {
                        "gyro_x": struct.unpack('<f', self.__packet_frame['data'][0:4])[0],
                        "gyro_y": struct.unpack('<f', self.__packet_frame['data'][4:8])[0],
                        "gyro_z": struct.unpack('<f', self.__packet_frame['data'][8:12])[0],
                        "accel_x": struct.unpack('<f', self.__packet_frame['data'][12:16])[0],
                        "accel_y": struct.unpack('<f', self.__packet_frame['data'][16:20])[0],
                        "accel_z": struct.unpack('<f', self.__packet_frame['data'][20:24])[0],
                        "timestamp": struct.unpack('<I', self.__packet_frame['timestamp'])[0]
                    }

                    print(f"Gyro X: {self.__mpu_data['gyro_x']} rad/s\n"
                          f"Gyro Y: {self.__mpu_data['gyro_y']} rad/s\n"
                          f"Gyro Z: {self.__mpu_data['gyro_z']} rad/s\n"
                          f"Accel X: {self.__mpu_data['accel_x']} ms^-2\n"
                          f"Accel Y: {self.__mpu_data['accel_y']} ms^-2\n"
                          f"Accel Z: {self.__mpu_data['accel_z']} ms^-2\n")

    def get_bmp_pressure(self):
        return self.__bmp_data['pressure']

    def get_bmp_altitude(self):
        return self.__bmp_data['altitude_from_pad']

    def get_bmp_timestamp(self):
        return self.__bmp_data['timestamp']
