// Project: avionics_tx
// Purpose: Module for testing radio transmit with random data

#include <Arduino.h>
#include <config.h>
#include <nrf.h>
#include <module_dummy.h>

uint32_t dummy_last_run_time = millis();

packet_frame dummy;

// fill packet buffer with 32 bytes of random data
packet_frame module_dummy_get() {
    // update the timestamp to time of fetch
    dummy.timestamp = millis();
    // max data length
    dummy.data_length = 24;

    // fill data
    for(int i = 0; i < dummy.data_length; i++) {
        dummy.data[i] = rand();
    }

    dummy_last_run_time = millis();

    return dummy;
}

void module_dummy_setup() {
    // do setup things
    dummy.module_id = MODULE_DUMMY_ID;

    // seed the RNG with analog noise
    srand(analogRead(0));
}

bool module_dummy_ready() {
    if(millis() - dummy_last_run_time >= DUMMY_FETCH_INTERVAL) {
        return true;
    } else {
        return false;
    }
}