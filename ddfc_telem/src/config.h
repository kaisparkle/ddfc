// Project: ddfc_telem
// Purpose: Configuration constants for modules

#ifndef CONFIG_H
#define CONFIG_H

// NRF
const uint8_t NRF_CE_PIN = 7;
const uint8_t NRF_CSN_PIN = 8;
// enables data write logging
#define NRF_DEBUG false
// retry delay in multiples of 250us
const uint8_t RETRY_DELAY = 4;
const uint8_t RETRY_COUNT = 5;
// max packet size is 32 bytes
const uint8_t PACKET_SIZE = 32;
// address of the modules
const uint8_t ADDRESS[5] = {0xe7, 0xe7, 0xe7, 0xe7, 0xe7};

// dummy module
const uint8_t MODULE_DUMMY_ID = 0x00;
const uint16_t DUMMY_FETCH_INTERVAL = 500;

// BMP module
const uint8_t MODULE_BMP_ID = 0x02;
const uint16_t BMP_FETCH_INTERVAL = 50;

// IMU modules
const uint8_t MODULE_HMC_ID = 0x03;
const uint8_t MODULE_MPU_ID = 0x04;
const uint16_t HMC_FETCH_INTERVAL = 50;
const uint16_t MPU_FETCH_INTERVAL = 50;

// I2C
const uint8_t I2C_MASTER_ADDRESS = 1;
const uint8_t I2C_SLAVE_ADDRESS = 2;

#endif