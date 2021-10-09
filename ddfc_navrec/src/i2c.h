#ifndef I2C_H
#define I2C_H

#include <Arduino.h>
#include <packet.h>

void i2c_setup();
void i2c_send(packet_frame packet);
void i2c_on_receive();
bool i2c_ready();
packet_frame i2c_get();

#endif