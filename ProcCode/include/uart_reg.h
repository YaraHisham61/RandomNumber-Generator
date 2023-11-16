#ifndef UART_REG_H_
#define UART_REG_H_

#define UCSR0A   (*((volatile char*)0xC0))
#define UCSR0B   (*((volatile char*)0xC1))
#define UCSR0C   (*((volatile char*)0xC2))
#define UBRR0L   (*((volatile char*)0xC4))
#define UBRR0H   (*((volatile char*)0xC5))
#define UDR0     (*((volatile char*)0xC6)) //Buffer

#endif