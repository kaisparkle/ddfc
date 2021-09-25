// Project: ddfc_tx
// Purpose: GPS module header

#ifndef MODULE_GPS_H
#define MODULE_GPS_H

#include <Arduino.h>
#include <nrf.h>

// GPS data container
struct gps_data {
    // date variables
    uint8_t year;
    uint8_t month;
    uint8_t day;
    // time variables
    uint8_t hours;
    uint8_t minutes;
    uint8_t seconds;
    // position
    float latitude; // deg
    float longitude; // deg
    float altitude; // mm above mean sea level
    float speed; // mm per sec ground speed
};

packet_frame module_gps_get();
void module_gps_setup();
bool module_gps_ready();

#endif