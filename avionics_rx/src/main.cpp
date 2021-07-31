#include <Arduino.h>
#include <SPI.h>
#include <printf.h>

#include <RF24.h>
#include <nRF24L01.h>
#include <nrf.h>

packet_frame previous_packet;
packet_frame received_packet;

void setup() {
    Serial.begin(9600);
    printf_begin();

    nrf_rx_setup();
}

void loop() {
    received_packet = nrf_read();

    // make sure the packet is new
    if(received_packet.timestamp != previous_packet.timestamp) {
        Serial.print("Packet ID: 0x");
        Serial.println(received_packet.packet_magic, HEX);
        Serial.print("Module ID: 0x");
        Serial.println(received_packet.module_id, HEX);
        Serial.print("Timestamp (us): ");
        Serial.println(received_packet.timestamp, DEC);
        Serial.print("Listed data length (bytes): ");
        Serial.println(received_packet.data_length, DEC);
        Serial.print("Actual data length (bytes): ");
        Serial.println(sizeof(received_packet.data), DEC);
        Serial.print("Data: 0x");
        for(int i = 0; i < received_packet.data_length; i++) {
            Serial.print(received_packet.data[i], HEX);
        }
        Serial.print('\n');
    }
    previous_packet = received_packet;
}