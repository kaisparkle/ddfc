// Project: avionics
// Purpose: Configuration constants for various modules

#ifndef CONFIG_H
#define CONFIG_H

// arming
#define ARMING_ENABLE false
const uint8_t ARMING_SWITCH_PIN = 2;
const uint8_t ARMING_LED_PIN = LED_BUILTIN;
// delay in seconds until armed
const uint8_t ARMING_DELAY = 5;

// NRF
const uint8_t NRF_CE_PIN = 9;
const uint8_t NRF_CSN_PIN = 10;
// enables data write logging
#define NRF_DEBUG true
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

// GPS module
const uint8_t MODULE_GPS_ID = 0x01;
const uint8_t GPS_TX_PIN = 7;
const uint8_t GPS_RX_PIN = 8;
// minimum interval between data fetches in milliseconds
// NEO-7M running at 5Hz
const uint16_t GPS_FETCH_INTERVAL = 200;

// BMP module
// running at 10Hz
const uint8_t MODULE_BMP_ID = 0x02;
const uint16_t BMP_FETCH_INTERVAL = 100;

#endif