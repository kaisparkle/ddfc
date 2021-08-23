// Project: avionics_tx
// Purpose: Module for handling GPS data from u-blox NEO-7M

#include <Arduino.h>
#include <SoftwareSerial.h>
#include <UbxGpsNavPvt.h>
#include <config.h>
#include <nrf.h>
#include <module_gps.h>

// stores the time in ms from execution start when data was last fetched
uint32_t gps_last_run_time = millis();

gps_data gps_struct;
packet_frame gps_packet;

// initialize software serial to communicate with module
SoftwareSerial gps_serial(GPS_RX_PIN, GPS_TX_PIN);
// initalize GPS module
UbxGpsNavPvt<SoftwareSerial> gps(gps_serial);

packet_frame module_gps_get() {
    // fill the data struct
    gps_struct.year = gps.year;
    gps_struct.month = gps.month;
    gps_struct.day = gps.day;
    gps_struct.hours = gps.hour;
    gps_struct.minutes = gps.min;
    gps_struct.seconds = gps.sec;
    gps_struct.latitude = gps.lat;
    gps_struct.longitude = gps.lon;
    gps_struct.altitude = gps.hMSL;
    gps_struct.speed = gps.gSpeed;

    // fill packet frame
    gps_packet.module_id = MODULE_GPS_ID;
    gps_packet.timestamp = millis();
    gps_packet.data_length = sizeof(gps_struct);

    // iterate through each byte in the GPS struct and add it to data
    uint8_t* gps_struct_ptr = (uint8_t*)&gps_struct;
    for(uint8_t i = 0; i < sizeof(gps_struct); i++) {
        gps_packet.data[i] = *gps_struct_ptr++;
    }

    // update the time
    gps_last_run_time = millis();

    return gps_packet;
}

void module_gps_setup() {
    // begin GPS serial comms
    gps.begin(115200);
}

bool module_gps_ready() {
    if(!gps.ready()) {
        return false;
    }
    // check if the fetch interval has been met
    if(millis() - gps_last_run_time >= GPS_FETCH_INTERVAL) {
        return true;
    } else {
        return false;
    }
}