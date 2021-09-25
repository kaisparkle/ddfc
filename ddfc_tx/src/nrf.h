// Project: ddfc
// Purpose: NRF radio module header

#ifndef NRF_H
#define NRF_H

#include <stdint.h>

struct packet_frame {
    // 2 byte packet magic
    uint16_t packet_magic = 0xA4EE;
    // 1 byte module identifier
    uint8_t module_id;
    // 4 byte millisecond timestamp
    uint32_t timestamp;
    // 1 byte data length
    uint8_t data_length;
    // 24 byte data
    uint8_t data[24];
};

void nrf_send(packet_frame packet);
packet_frame nrf_read();
void nrf_tx_setup();
void nrf_rx_setup();

#endif