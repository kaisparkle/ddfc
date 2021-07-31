#ifndef NRF_H
#define NRF_H

#include <stdint.h>

// chip-enable and chip-select-not pins
#define NRF_CE_PIN  9
#define NRF_CSN_PIN 10

// enables data write logging
#define NRF_DEBUG true

// retry delay in multiples of 250us
#define RETRY_DELAY 4
#define RETRY_COUNT 5

// max packet size is 32 bytes
const uint8_t PACKET_SIZE = 32;

struct packet_frame {
    // 2 byte packet magic
    uint16_t packet_magic = 0xA4EE;
    // 1 byte module identifier
    uint8_t module_id;
    // 4 byte microsecond timestamp
    uint32_t timestamp;
    // 1 byte data length
    uint8_t data_length;
    // 24 byte data
    uint8_t data[24];
};

// address of the modules
const uint8_t address[5] = {0xe7, 0xe7, 0xe7, 0xe7, 0xe7};

// transmit interval in microseconds
const unsigned long tx_interval = 1000000;

bool nrf_send(packet_frame packet);
packet_frame nrf_read();
void nrf_tx_setup();
void nrf_rx_setup();

#endif