#ifndef CONFIG_H
#define CONFIG_H

// configuration defines

// arming
#define ARMING_ENABLE false
#define ARMING_SWITCH_PIN 2
#define ARMING_LED_PIN LED_BUILTIN
// delay in seconds until armed
#define ARMING_DELAY 5

// NRF
#define NRF_CE_PIN  9
#define NRF_CSN_PIN 10
// enables data write logging
#define NRF_DEBUG true
// retry delay in multiples of 250us
#define RETRY_DELAY 4
#define RETRY_COUNT 5
// max packet size is 32 bytes
#define PACKET_SIZE 32

// dummy module
#define MODULE_DUMMY_ID 0x0A
#define DUMMY_FETCH_INTERVAL 500

// GPS module
#define MODULE_GPS_ID 0x0B
#define GPS_TX_PIN 7
#define GPS_RX_PIN 8
// minimum interval between data fetches in milliseconds
// NEO-7M running at 5Hz
#define GPS_FETCH_INTERVAL 200

#endif