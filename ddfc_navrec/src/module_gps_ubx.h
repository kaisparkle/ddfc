// Project: ddfc_navrec
// Purpose: GPS module header

#ifndef MODULE_GPS_H
#define MODULE_GPS_H

#include <Arduino.h>
#include <packet.h>

// GPS data container
struct gps_data {
    // date variables
    uint16_t year;
    uint8_t month;
    uint8_t day;
    // time variables
    uint8_t hours;
    uint8_t minutes;
    uint8_t seconds;
    // position
    long latitude; // deg 1e-7
    long longitude; // deg 1e-7
    long altitude; // mm above mean sea level
    long speed; // mm per sec ground speed
};

packet_frame module_gps_get();
void module_gps_setup();
bool module_gps_ready();

#endif