// Project: ddfc_navrec
// Purpose: NAVREC main functions, handles SD data logging and GPS data

#include <Arduino.h>
#include <SPI.h>
#include <SD.h>
#include <config.h>
#include <packet.h>
#include <module_gps.h>
#include <i2c.h>

File sd_file;

void setup() {
    Serial.begin(9600);

    Serial.println("NAVREC starting");
    module_gps_setup();
    i2c_setup();
    if(!SD.begin(SD_CS_PIN)) {
        Serial.println("WARNING: SD init failed");
    }

    Serial.println("Waiting for GPS lock...");
}

void loop() {
    if(i2c_ready()) {
        packet_frame received = i2c_get();
        sd_file = SD.open("flight.dat", FILE_WRITE);
        sd_file.write((const uint8_t*)&received, sizeof(packet_frame));
        sd_file.close();
        Serial.print("I2C packet: ");
        Serial.write((uint8_t*)&received, sizeof(received));
        Serial.print('\n');
    }
    if(module_gps_ready()) {
        packet_frame gps = module_gps_get();
        sd_file = SD.open("flight.dat", FILE_WRITE);
        sd_file.write((const uint8_t*)&gps, sizeof(packet_frame));
        sd_file.close();
        Serial.print("GPS packet: ");
        Serial.write((uint8_t*)&gps, sizeof(gps));
        Serial.print('\n');
        i2c_send(gps);
    }
}