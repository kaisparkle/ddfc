// Project: ddfc_tx
// Purpose: TX main functions, handles module data collection and transmit

#include <Arduino.h>
#include <config.h>
#include <nrf.h>
#include <module_dummy.h>
#include <module_gps.h>
#include <module_bmp.h>

void setup() {
    Serial.begin(9600);

    nrf_tx_setup();
    module_dummy_setup();
    module_gps_setup();
    module_bmp_setup();
}

void loop() {
    if(module_dummy_ready()) {
        packet_frame dummy = module_dummy_get();
        nrf_send(dummy);
    }

    if(module_gps_ready()) {
        packet_frame gps = module_gps_get();
        nrf_send(gps);
    }

    if(module_bmp_ready()) {
        packet_frame bmp = module_bmp_get();
        nrf_send(bmp);
    }
}