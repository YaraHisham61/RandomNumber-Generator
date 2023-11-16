#include "../include/uart.h"
#include "../include/uart_reg.h"
#include "../include/common_macros.h"

void uart_init(void){
UCSR0A = 0 ; //Clear all error flags
SET_BIT(UCSR0B,4); //Enable RX
SET_BIT(UCSR0B,3); //Enable TX
SET_BIT(UCSR0C,1); SET_BIT(UCSR0C,2); //8-bit data
UBRR0H = 0; UBRR0L = 103; //9600 baud rate
}

void uart_transmit(uint8 data){
    while (!(UCSR0A & (1 << 5)));
    // while(READ_BIT(UCSR0A,5) == 0); //Wait until TX buffer is empty
    UDR0 = data;
}

uint8 uart_receive(void){
    while ( !(UCSR0A & (1<<7)) );
    // while(READ_BIT(UCSR0A,7) == 0); //Wait until RX buffer is empty
    uint8 data = UDR0;
    SET_BIT(UCSR0A,7); //Clear RX flag
    return data;
}