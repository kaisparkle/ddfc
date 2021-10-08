// Project: ddfc_fx
// Purpose: RX main functions, handles receiving data from vehicle

#include <Arduino.h>
#include <SPI.h>
#include <nrf.h>

packet_frame previous_packet;
packet_frame received_packet;

void setup() {
    Serial.begin(115200);

    nrf_rx_setup();
}

void loop() {
    received_packet = nrf_read();

    // make sure the packet is new
    if(received_packet.timestamp != previous_packet.timestamp) {
        // write the entire packet as raw bytes and terminate with newline
        Serial.write((uint8_t*)&received_packet, sizeof(received_packet));
    }
    previous_packet = received_packet;
}