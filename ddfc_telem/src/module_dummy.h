// Project: ddfc_telem
// Purpose: Dummy module header

#ifndef MODULE_DUMMY_H
#define MODULE_DUMMY_H

#include <stdint.h>
#include <packet.h>

packet_frame module_dummy_get();
void module_dummy_setup();
bool module_dummy_ready();

#endif