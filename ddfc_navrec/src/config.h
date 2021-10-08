// Project: ddfc_navrec
// Purpose: Configuration constants for modules

#ifndef CONFIG_H
#define CONFIG_H

// SD module
const uint8_t SD_CS_PIN = 10;

// GPS module
const uint8_t MODULE_GPS_ID = 0x01;
const uint8_t GPS_TX_PIN = 5;
const uint8_t GPS_RX_PIN = 6;
// minimum interval between data fetches in milliseconds
// NEO-7M running at 1Hz
const uint16_t GPS_FETCH_INTERVAL = 1000;
#define GPS_DEBUG true

#endif