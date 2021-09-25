// Project: ddfc
// Purpose: Module for radio transmit over NRF24L01

#include <Arduino.h>
#include <SPI.h>
#include <config.h>
#include <nrf.h>
#include <RF24.h>
#include <nRF24L01.h>

// define new radio
RF24 radio(NRF_CE_PIN, NRF_CSN_PIN);

bool nrf_send(packet_frame packet) {
    bool result;
    result = radio.write(&packet, PACKET_SIZE);
    
    #if NRF_DEBUG
        Serial.print("Data sent: ");
        Serial.print(packet.packet_magic, HEX);
        Serial.print(packet.module_id, HEX);
        Serial.print(packet.timestamp, HEX);
        Serial.print(packet.data_length, HEX);
        for(int i = 0; i < packet.data_length; i++) {
            Serial.print(packet.data[i], HEX);
        }
        Serial.print('\n');
    #endif

    return result;
}

packet_frame nrf_read() {
    packet_frame packet;

    if(radio.available()) {
        radio.read(&packet, PACKET_SIZE);
    }

    return packet;
}

void nrf_tx_setup() {
    Serial.println("TX starting");
    radio.begin();

    // for bench use
    radio.setPALevel(RF24_PA_LOW);
    radio.setChannel(0);

    // 250Kbps offers the theoretically highest range
    radio.setDataRate(RF24_250KBPS);
    radio.setRetries(RETRY_DELAY, RETRY_COUNT);
    radio.openWritingPipe(ADDRESS);
}

void nrf_rx_setup() {
    radio.begin();

    // for bench use
    radio.setPALevel(RF24_PA_LOW);
    radio.setChannel(0);

    // 250Kbps offers the theoretically highest range
    radio.setDataRate(RF24_250KBPS);
    radio.openReadingPipe(0, ADDRESS);
    radio.startListening();
}