// Project: ddfc_navrec
// Purpose: NAVREC main functions, handles SD data logging and GPS data

#include <Arduino.h>
#include <SPI.h>
#include <SD.h>
#include <config.h>
#include <packet.h>
#include <module_gps.h>

void setup() {
    Serial.begin(9600);

    Serial.println("NAVREC starting");
    module_gps_setup();
    Serial.println("Waiting for GPS lock...");
}

void loop() {
    if(module_gps_ready()) {
        packet_frame gps = module_gps_get();
        Serial.print("GPS packet: ");
        Serial.write((uint8_t*)&gps, sizeof(gps));
        Serial.print('\n');
    }
}