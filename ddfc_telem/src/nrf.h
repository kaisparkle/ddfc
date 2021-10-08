// Project: ddfc
// Purpose: NRF radio module header

#ifndef NRF_H
#define NRF_H

#include <packet.h>

void nrf_send(packet_frame packet);
packet_frame nrf_read();
void nrf_tx_setup();
void nrf_rx_setup();

#endif