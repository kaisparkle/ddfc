#include <Arduino.h>
#include <nrf.h>
#include <module_dummy.h>

packet_frame dummy;

// fill packet buffer with 32 bytes of random data
packet_frame module_dummy_get() {
    // update the timestamp to time of fetch
    dummy.timestamp = micros();
    // max data length
    dummy.data_length = 25;

    // fill data
    for(int i = 0; i < dummy.data_length; i++) {
        dummy.data[i] = rand();
    }

    return dummy;
}

void module_dummy_setup() {
    // do setup things
    dummy.module_id = MODULE_DUMMY_ID;

    // seed the RNG with analog noise
    srand(analogRead(0));
}