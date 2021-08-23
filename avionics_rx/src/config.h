// Project: avionics
// Purpose: Configuration constants for various modules

#ifndef CONFIG_H
#define CONFIG_H

// NRF
const uint8_t NRF_CE_PIN = 9;
const uint8_t NRF_CSN_PIN = 10;
// enables data write logging
#define NRF_DEBUG false
// retry delay in multiples of 250us
const uint8_t RETRY_DELAY = 4;
const uint8_t RETRY_COUNT = 5;
// max packet size is 32 bytes
const uint8_t PACKET_SIZE = 32;
// address of the modules
const uint8_t ADDRESS[5] = {0xe7, 0xe7, 0xe7, 0xe7, 0xe7};

#endif