#include "../include/ext_int.h"
#include "../include/ext_int_reg.h"

void EXT_INT_Init(void){
    EICRA |= (0b1111);
    EIMSK |= 0b11;
    SREG |= (1<<7);
    PCICR |= 1; //Enable PCINT0
    PCMSK0 |= 1; //Enable PCINT0
}