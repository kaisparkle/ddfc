// Project: ddfc_telem
// Purpose: TELEM main functions, handles module data collection and transmit

#include <Arduino.h>
#include <config.h>
#include <nrf.h>
#include <packet.h>
#include <module_bmp.h>
#include <module_imu.h>

void setup() {
    Serial.begin(9600);
    Serial.println("TELEM starting");

    nrf_tx_setup();
    module_imu_hmc_setup();
    module_imu_mpu_setup();
    module_bmp_setup();
}

void loop() {
    if(module_bmp_ready()) {
        packet_frame bmp = module_bmp_get();
        nrf_send(bmp);
    }
    if(module_imu_hmc_ready()) {
        packet_frame hmc = module_imu_hmc_get();
        nrf_send(hmc);
    }
    if(module_imu_mpu_ready()) {
        packet_frame mpu = module_imu_mpu_get();
        nrf_send(mpu);
    }
}