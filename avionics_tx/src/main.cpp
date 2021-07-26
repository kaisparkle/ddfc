#include <Arduino.h>
#include <printf.h>

#include <nrf.h>
#include <module_dummy.h>

unsigned long current_micros;
unsigned long prev_micros;

void setup() {
    Serial.begin(9600);
    printf_begin();

    nrf_tx_setup();
    module_dummy_setup();
}

void loop() {
    // store the time at loop's start
    current_micros = micros();

    if(current_micros - prev_micros >= tx_interval) {
        // get module data
        packet_frame dummy = module_dummy_get();

        // send the packet frame if we're at our tx interval
        bool result = nrf_send(dummy);

        if(result) {
            Serial.print("Time since last packet: ");
            Serial.print(current_micros - prev_micros);
            Serial.println("us");
        } 
        else {
            Serial.println("TX failed");
        }
        prev_micros = micros();
    }
}