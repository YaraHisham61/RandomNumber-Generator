#ifndef UART_H_
#define UART_H_

#include "std_types.h"

void uart_init(void);
void uart_transmit(uint8 data);
uint8 uart_receive(void);
bool uart_checkErrors();
#endif