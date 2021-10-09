// Project: ddfc_telem
// Purpose: Module for handling inertial data from HMC5883L and MPU6050

#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>
#include <Adafruit_MPU6050.h>
#include <Wire.h>
#include <module_imu.h>
#include <packet.h>
#include <config.h>

// stores the time in ms from execution start when data was last fetched
uint32_t hmc_last_run_time = millis();
uint32_t mpu_last_run_time = millis();

// flags set if the modules are set up
bool hmc_ready = false;
bool mpu_ready = false;

// data storage
hmc_data hmc_struct;
mpu_data mpu_struct;
packet_frame hmc_packet;
packet_frame mpu_packet;
sensors_event_t hmc_event;
sensors_event_t mpu_event_accel;
sensors_event_t mpu_event_gyro;
// currently not used due to packet size constraints
sensors_event_t mpu_event_temp;

// instantiate sensors
Adafruit_HMC5883_Unified hmc = Adafruit_HMC5883_Unified(0);
Adafruit_MPU6050 mpu;

packet_frame module_imu_hmc_get() {
    // get data from sensor
    hmc.getEvent(&hmc_event);
    // fill struct
    hmc_struct.magnetometer.x = hmc_event.magnetic.x;
    hmc_struct.magnetometer.y = hmc_event.magnetic.y;
    hmc_struct.magnetometer.z = hmc_event.magnetic.z;

    // fill packet frame
    hmc_packet.module_id = MODULE_HMC_ID;
    hmc_packet.timestamp = millis();
    hmc_packet.data_length = sizeof(hmc_struct);

    // iterate through each byte in the HMC struct and add it to data
    uint8_t* hmc_struct_ptr = (uint8_t*)&hmc_struct;
    for(uint8_t i = 0; i < sizeof(hmc_struct); i++) {
        hmc_packet.data[i] = *hmc_struct_ptr++;
    }

    // update the time
    hmc_last_run_time = millis();

    return hmc_packet;
}

packet_frame module_imu_mpu_get() {
    // get data from sensor
    mpu.getEvent(&mpu_event_accel, &mpu_event_gyro, &mpu_event_temp);
    // fill struct
    mpu_struct.accelerometer.x = mpu_event_accel.acceleration.x;
    mpu_struct.accelerometer.y = mpu_event_accel.acceleration.y;
    mpu_struct.accelerometer.z = mpu_event_accel.acceleration.z;
    mpu_struct.gyroscope.x = mpu_event_gyro.gyro.x;
    mpu_struct.gyroscope.y = mpu_event_gyro.gyro.y;
    mpu_struct.gyroscope.z = mpu_event_gyro.gyro.z;

    // fill packet frame
    mpu_packet.module_id = MODULE_MPU_ID;
    mpu_packet.timestamp = millis();
    mpu_packet.data_length = sizeof(mpu_struct);

    // iterate through each byte in the HMC struct and add it to data
    uint8_t* mpu_struct_ptr = (uint8_t*)&mpu_struct;
    for(uint8_t i = 0; i < sizeof(mpu_struct); i++) {
        mpu_packet.data[i] = *mpu_struct_ptr++;
    }

    // update the time
    mpu_last_run_time = millis();

    return mpu_packet;
}

void module_imu_hmc_setup() {
    // if the module is successfully set up, set the flag
    if(hmc.begin()) {
        hmc_ready = true;
    }
}

void module_imu_mpu_setup() {
    // if the module is successfully set up, set the flag
    if(mpu.begin()) {
        // configuration
        mpu.setAccelerometerRange(MPU6050_RANGE_16_G);
        // 1000 deg per second = 166.67 RPM
        mpu.setGyroRange(MPU6050_RANGE_1000_DEG);
        // low-pass filter bandwith - 5Hz incurs a ~19ms delay
        mpu.setFilterBandwidth(MPU6050_BAND_5_HZ);
        mpu_ready = true;
    }
}

bool module_imu_hmc_ready() {
    if(!hmc_ready) {
        return false;
    }
    // check if the fetch interval has been met
    if(millis() - hmc_last_run_time >= HMC_FETCH_INTERVAL) {
        return true;
    } else {
        return false;
    }
}

bool module_imu_mpu_ready() {
    if(!mpu_ready) {
        return false;
    }
    // check if the fetch interval has been met
    if(millis() - mpu_last_run_time >= MPU_FETCH_INTERVAL) {
        return true;
    } else {
        return false;
    }
}