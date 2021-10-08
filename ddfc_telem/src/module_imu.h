// Project: ddfc_telem
// Purpose: IMU module header

#ifndef MODULE_IMU_H
#define MODULE_IMU_H

#include <Arduino.h>
#include <packet.h>

struct axis {
    float x;
    float y;
    float z;
};

struct hmc_data {
    // micro-tesla
    axis magnetometer;
};

struct mpu_data {
    // degrees
    axis gyroscope;
    // meters per second per second
    axis accelerometer;
};

packet_frame module_imu_hmc_get();
void module_imu_hmc_setup();
bool module_imu_hmc_ready();

packet_frame module_imu_mpu_get();
void module_imu_mpu_setup();
bool module_imu_mpu_ready();

#endif