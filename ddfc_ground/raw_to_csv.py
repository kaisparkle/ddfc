import argparse
import os
import sys
import struct
import csv

DATA_HEADER = b"Flight Data:\x0a"
PACKET_HEADER = b"\xa4\xee"

# module IDs
MODULE_GPS_ID = 1
MODULE_BMP_ID = 2
MODULE_HMC_ID = 3
MODULE_MPU_ID = 4

# define empty dicts for data handling
packet_frame = {
    "magic",
    "module_id",
    "timestamp",
    "data_length",
    "data"
}

gps_data = {
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

bmp_data = {
    "temperature": 0.0,
    "pressure": 0,
    "altitude_from_pad": 0.0,
    "timestamp": 0
}

hmc_data = {
    "mag_x": 0.0,
    "mag_y": 0.0,
    "mag_z": 0.0,
    "timestamp": 0
}

mpu_data = {
    "gyro_x": 0.0,
    "gyro_y": 0.0,
    "gyro_z": 0.0,
    "accel_x": 0.0,
    "accel_y": 0.0,
    "accel_z": 0.0,
    "timestamp": 0
}

bmp_csv_header = ["timestamp", "temperature", "pressure", "altitude"]
hmc_csv_header = ["timestamp", "mag_x", "mag_y", "mag_z"]
mpu_csv_header = ["timestamp", "gyro_x", "gyro_y", "gyro_z", "accel_x", "accel_y", "accel_z"]
flight_start_timestamp = 0


def handle_bmp(packet_frame, output_writer):
    # unpack the data as float, uint, and float
    bmp_data = {
        # unpack outputs a tuple even if only one value, so only take the first tuple value
        "temperature": struct.unpack('<f', packet_frame['data'][0:4])[0],
        "pressure": struct.unpack('<I', packet_frame['data'][4:8])[0],
        "altitude_from_pad": struct.unpack('<f', packet_frame['data'][8:12])[0],
        "timestamp": packet_frame['timestamp']
    }

    if bmp_data['timestamp'] >= flight_start_timestamp:
        output_writer.writerow([bmp_data['timestamp'] - flight_start_timestamp,
                                bmp_data['temperature'],
                                bmp_data['pressure'],
                                bmp_data['altitude_from_pad']])


def handle_hmc(packet_frame, output_writer):
    hmc_data = {
        "mag_x": struct.unpack('<f', packet_frame['data'][0:4])[0],
        "mag_y": struct.unpack('<f', packet_frame['data'][4:8])[0],
        "mag_z": struct.unpack('<f', packet_frame['data'][8:12])[0],
        "timestamp": packet_frame['timestamp']
    }

    if hmc_data['timestamp'] >= flight_start_timestamp:
        output_writer.writerow([hmc_data['timestamp'] - flight_start_timestamp,
                                hmc_data['mag_x'],
                                hmc_data['mag_y'],
                                hmc_data['mag_z']])


def handle_mpu(packet_frame, output_writer):
    mpu_data = {
        "gyro_x": struct.unpack('<f', packet_frame['data'][0:4])[0],
        "gyro_y": struct.unpack('<f', packet_frame['data'][4:8])[0],
        "gyro_z": struct.unpack('<f', packet_frame['data'][8:12])[0],
        "accel_x": struct.unpack('<f', packet_frame['data'][12:16])[0],
        "accel_y": struct.unpack('<f', packet_frame['data'][16:20])[0],
        "accel_z": struct.unpack('<f', packet_frame['data'][20:24])[0],
        "timestamp": packet_frame['timestamp']
    }

    if mpu_data['timestamp'] >= flight_start_timestamp:
        output_writer.writerow([mpu_data['timestamp'] - flight_start_timestamp,
                                mpu_data['gyro_x'],
                                mpu_data['gyro_y'],
                                mpu_data['gyro_z'],
                                mpu_data['accel_x'],
                                mpu_data['accel_y'],
                                mpu_data['accel_z']])


if __name__ == "__main__":
    # parse cmdline arguments
    arg_parser = argparse.ArgumentParser(description="Converts raw DDFC flight data to CSVs.")
    arg_parser.add_argument("Path", metavar="path", type=str, help="path to raw data")
    arg_parser.add_argument("Start", metavar="start", type=int, help="timestamp of start of flight")
    args = arg_parser.parse_args()

    # store start timestamp
    flight_start_timestamp = args.Start

    # check if the file exists
    input_path = args.Path
    if not os.path.exists(input_path):
        print("The file specified does not exist.")
        sys.exit()

    # open file and check if the header is correct
    input_file = open(input_path, "rb")
    header = input_file.read(13)
    if header != DATA_HEADER:
        print("Header missing, invalid data.")
        sys.exit()

    # open output files
    bmp_output_file = open("bmp.csv", "w", newline="")
    bmp_csv_writer = csv.writer(bmp_output_file)
    bmp_csv_writer.writerow(bmp_csv_header)
    hmc_output_file = open("hmc.csv", "w", newline="")
    hmc_csv_writer = csv.writer(hmc_output_file)
    hmc_csv_writer.writerow(hmc_csv_header)
    mpu_output_file = open("mpu.csv", "w", newline="")
    mpu_csv_writer = csv.writer(mpu_output_file)
    mpu_csv_writer.writerow(mpu_csv_header)

    # read in packets
    packet_counter = 0
    bad_packet_counter = 0
    packet = input_file.read(32)
    while packet:
        packet_counter += 1

        packet_frame = {
            "magic": packet[0:2],
            "module_id": int(packet[2]),
            "timestamp": int.from_bytes(packet[3:7], "little"),
            "data_length": int(packet[7]),
            "data": packet[8:32]
        }

        # check if the packet magic is correct
        if packet_frame['magic'] != PACKET_HEADER:
            # incorrect magic, skip packet
            print(f"{packet_counter}: bad packet!")
            bad_packet_counter += 1
            packet = input_file.read(32)
            pass

        if packet_frame['module_id'] == MODULE_BMP_ID:
            # write packet to CSV
            handle_bmp(packet_frame, bmp_csv_writer)
        elif packet_frame['module_id'] == MODULE_HMC_ID:
            handle_hmc(packet_frame, hmc_csv_writer)
        elif packet_frame['module_id'] == MODULE_MPU_ID:
            handle_mpu(packet_frame, mpu_csv_writer)

        packet = input_file.read(32)

    print(f"Read {packet_counter} packets, {bad_packet_counter} were bad.")
    bmp_output_file.close()
    hmc_output_file.close()
    mpu_output_file.close()
