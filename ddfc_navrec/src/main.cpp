// Project: ddfc_navrec
// Purpose: NAVREC main functions, handles SD data logging and GPS data

#include <Arduino.h>
#include <SPI.h>
#include <SD.h>
#include <config.h>
#include <packet.h>
#include <module_gps_ubx.h>
#include <i2c.h>

File sd_file;

void setup() {
    Serial.begin(9600);
    Serial.println("NAVREC starting");

    // set up modules
    module_gps_setup();
    // begin two-way i2c comms
    i2c_setup();
    // set up SD card
    if(!SD.begin(SD_CS_PIN)) {
        Serial.println("WARNING: SD init failed");
    }
    // write SD file header
    sd_file = SD.open("flight.dat", FILE_WRITE);
    sd_file.println("Flight Data:");
    sd_file.close();

    Serial.println("Waiting for GPS lock...");
}

void loop() {
    if(i2c_ready()) {
        packet_frame received = i2c_get();
        sd_file = SD.open("flight.dat", FILE_WRITE);
        sd_file.write((const uint8_t*)&received, sizeof(packet_frame));
        sd_file.close();
    }

    if(module_gps_ready()) {
        packet_frame gps = module_gps_get();
        sd_file = SD.open("flight.dat", FILE_WRITE);
        sd_file.write((const uint8_t*)&gps, sizeof(packet_frame));
        sd_file.close();
        i2c_send(gps);
    }
}