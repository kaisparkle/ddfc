// Project: avionics_tx
// Purpose: Module for handling an on-board arm-once switch

#include <Arduino.h>
#include <config.h>
#include <arming.h>

bool is_armed() {
    // return true if the arming switch is active
    // high and low are reversed when using INPUT_PULLUP
    if(digitalRead(ARMING_SWITCH_PIN) == LOW) {
        return true;
    } else {
        return false;
    }
}

void arming_wait() {
    // set up our pins
    pinMode(ARMING_SWITCH_PIN, INPUT_PULLUP);
    pinMode(ARMING_LED_PIN, OUTPUT);
    // wait until the arming switch is active
    Serial.println("Waiting for arming...");
    while(!is_armed()) {
        // do nothing...
    }
}

void arming_arm() {
    // log the arming state
    Serial.print("ARMING IN ");
    Serial.print(ARMING_DELAY);
    Serial.println(" SECONDS...");
    // blink the LED each second
    for(int i = 0; i < ARMING_DELAY; i++) {
        digitalWrite(ARMING_LED_PIN, HIGH);
        delay(500);
        digitalWrite(ARMING_LED_PIN, LOW);
        delay(500);
    }
    Serial.println("ARMED.");
}