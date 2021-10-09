#include <Arduino.h>
#include <Wire.h>
#include <i2c.h>
#include <config.h>
#include <packet.h>

// flag set if there is new data, and unset when read
bool i2c_data_ready = false;
packet_frame received;

void i2c_on_receive(int how_many) {
    // read 32 bytes from i2c and set ready flag
    Wire.readBytes((uint8_t*)&received, sizeof(packet_frame));
    i2c_data_ready = true;
}

void i2c_setup() {
    // begin i2c comms as the slave
    Wire.begin(I2C_MASTER_ADDRESS);
    // set up event handler for receive
    Wire.onReceive(i2c_on_receive);
}

void i2c_send(packet_frame packet) {
    // begin transmit and send packet up
    Wire.beginTransmission(I2C_SLAVE_ADDRESS);
    Wire.write((uint8_t*)&packet, sizeof(packet_frame));
    Wire.endTransmission();
}

bool i2c_ready() {
    return i2c_data_ready;
}

packet_frame i2c_get() {
    // unset ready flag and return packet
    i2c_data_ready = false;
    return received;
}