// Project: ddfc
// Purpose: Defines packet frame struct

#ifndef PACKET_H
#define PACKET_H

#include <Arduino.h>

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

#endif