// Project: avionics_tx
// Purpose: BMP module header

#ifndef MODULE_BMP_H
#define MODULE_BMP_H

#include <Arduino.h>
#include <nrf.h>

struct bmp_data {
    float temperature;
    uint32_t pressure;
    // pad-relative altitude, based on pressure reading from initialization
    float altitude_from_pad;
};

packet_frame module_bmp_get();
void module_bmp_setup();
bool module_bmp_ready();

#endif