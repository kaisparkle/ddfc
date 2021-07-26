#ifndef MODULE_DUMMY_H
#define MODULE_DUMMY_H

#include <stdint.h>
#include <nrf.h>

#define MODULE_DUMMY_ID 0xAA

packet_frame module_dummy_get();
void module_dummy_setup();

#endif