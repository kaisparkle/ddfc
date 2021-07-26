#include <Arduino.h>
#include <SPI.h>

#include <nrf.h>
#include <RF24.h>
#include <nRF24L01.h>

// define new radio
RF24 radio(NRF_CE_PIN, NRF_CSN_PIN);

bool nrf_send(packet_frame packet) {
    bool result;
    result = radio.write(&packet, PACKET_SIZE);
    
    #ifdef NRF_DEBUG
        Serial.print("Data sent: ");
        Serial.print(packet.packet_id, HEX);
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
    bool new_data = false;
    packet_frame packet;

    if(radio.available()) {
        radio.read(&packet, PACKET_SIZE);
        new_data = true;
    }

    #ifdef NRF_DEBUG
        if(new_data == true) {
            Serial.print("Data received: ");
            Serial.print(packet.packet_id, HEX);
            Serial.print(packet.module_id, HEX);
            Serial.print(packet.timestamp, HEX);
            Serial.print(packet.data_length, HEX);
            for(int i = 0; i < packet.data_length; i++) {
                Serial.print(packet.data[i], HEX);
            }
            Serial.print('\n');
        }
    #endif

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
    radio.openWritingPipe(address);
    #ifdef NRF_DEBUG
        // dump module details
        radio.printDetails();
    #endif
}

void nrf_rx_setup() {
    Serial.println("RX starting");
    radio.begin();

    // for bench use
    radio.setPALevel(RF24_PA_LOW);
    radio.setChannel(0);

    // 250Kbps offers the theoretically highest range
    radio.setDataRate(RF24_250KBPS);
    radio.openReadingPipe(0, address);
    radio.startListening();
    #ifdef NRF_DEBUG
        // dump module details
        radio.printDetails();
    #endif
}