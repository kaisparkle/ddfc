// Project: avionics_tx
// Purpose: TX main functions, handles module data collection and transmit

#include <Arduino.h>
#include <config.h>
#include <printf.h>
#include <arming.h>
#include <nrf.h>
#include <module_dummy.h>
#include <module_gps.h>

void setup() {
    Serial.begin(9600);
    printf_begin();

    #if ARMING_ENABLE
        // pause execution until armed
        arming_wait();
        // once the wait is done, inform of arming
        arming_arm();
    #endif

    nrf_tx_setup();
    module_dummy_setup();
    module_gps_setup();
}

void loop() {
    if(module_dummy_ready()) {
        packet_frame dummy = module_dummy_get();
        bool result = nrf_send(dummy);
        if(!result) {
            Serial.println("TX failed");
        }
    }

    if(module_gps_ready()) {
        packet_frame gps = module_gps_get();
        bool result = nrf_send(gps);
        if(!result) {
            Serial.println("TX failed");
        }
    }
}