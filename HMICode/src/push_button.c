#include "../include/push_button.h"
#include "../include/gpio.h"

void BUTTON_init(uint8 port , uint8 pin){
    GPIO_setupPinDirection(port,pin,PIN_INPUT);
    GPIO_writePin(port,pin,LOGIC_HIGH); //pull up resistor
}

uint8 BUTTON_read(uint8 port , uint8 pin){
    return GPIO_readPin(port,pin);
}