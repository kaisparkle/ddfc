// Project: ddfc_tx
// Purpose: Module for handling pressure and temp data from BMP180

#include <Arduino.h>
#include <Adafruit_BMP085.h>
#include <module_bmp.h>
#include <nrf.h>
#include <config.h>

// stores the time in ms from execution start when data was last fetched
uint32_t bmp_last_run_time = millis();

// BMP085 and BMP180 are compatible
Adafruit_BMP085 bmp;

bmp_data bmp_struct;
packet_frame bmp_packet;

// pressure at first run for pad-relative altitude calculation
uint32_t pad_pressure = 0;

// flag set if the BMP is set up
bool bmp_ready = false;

packet_frame module_bmp_get() {
    // fill data
    bmp_struct.temperature = bmp.readTemperature();
    bmp_struct.pressure = bmp.readPressure();
    bmp_struct.altitude_from_pad = bmp.readAltitude(pad_pressure);

    // fill packet frame
    bmp_packet.module_id = MODULE_BMP_ID;
    bmp_packet.timestamp = millis();
    bmp_packet.data_length = sizeof(bmp_struct);

    // iterate through each byte in the BMP struct and add it to data
    uint8_t* bmp_struct_ptr = (uint8_t*)&bmp_struct;
    for(uint8_t i = 0; i < sizeof(bmp_struct); i++) {
        bmp_packet.data[i] = *bmp_struct_ptr++;
    }

    // update the time
    bmp_last_run_time = millis();

    return bmp_packet;
}

void module_bmp_setup() {
    // if the module is successfully set up, set the flag
    if(bmp.begin()) {
        bmp_ready = true;
        // take the current pressure for relative altitude calculation
        pad_pressure = bmp.readPressure();
    }
}

bool module_bmp_ready() {
    if(!bmp_ready) {
        return false;
    }
    // check if the fetch interval has been met
    if(millis() - bmp_last_run_time >= BMP_FETCH_INTERVAL) {
        return true;
    } else {
        return false;
    }
}