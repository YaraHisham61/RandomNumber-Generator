#include "../include/led.h"
#include "../include/gpio.h"


/*
    * Description :
    * Initialize the LED pin as output pin.
    * Set the LED pin initial value to off.
*/
void LED_init(uint8 port_num, uint8 pin_num){

    GPIO_setupPinDirection(port_num, pin_num, PIN_OUTPUT); // set pin as output
    GPIO_writePin(port_num, pin_num, LOGIC_LOW); //initially turn off the led
}


/*
    * Description :
    * Initialize multiple the LED pins as output pins.
    * Set the initial value of all pins to off.
*/
void LED_initMultiple(uint8 port_num, uint8 pin_num, uint8 number){

    uint8 i;
    for(i=0; i<number; i++){
        GPIO_setupPinDirection(port_num, pin_num+i, PIN_OUTPUT); // set pin as output
        GPIO_writePin(port_num, pin_num+i, LOGIC_LOW); //initially turn off the led
    }
}


/*
    * Description :
    * Turn the LED ON.
    * If the port number or pin number are not correct, The function will not handle the request.
    * If the LED is already ON, The function will not handle the request.
    * If the pin is input pin, The function will not handle the request.
*/
void LED_on(uint8 port_num, uint8 pin_num){

    if(GPIO_readPinDirection(port_num, pin_num) == PIN_INPUT) //check if the pin is output
        return; //do nothing

    if(GPIO_readPin(port_num, pin_num) == LOGIC_HIGH) //if the led is already on
        return; //do nothing

    GPIO_writePin(port_num, pin_num, LOGIC_HIGH); //turn on the led
}

/*
    * Description :
    * Turn the LED OFF.
    * If the port number or pin number are not correct, The function will not handle the request.
    * If the LED is already OFF, The function will not handle the request.
    * If the pin is input pin, The function will not handle the request.
*/
void LED_off(uint8 port_num, uint8 pin_num){
    
    if(GPIO_readPinDirection(port_num, pin_num) == PIN_INPUT) //check if the pin is output
        return; //do nothing
    
    if(GPIO_readPin(port_num, pin_num) == LOGIC_LOW) //if the led is already off
        return; //do nothing
    
    GPIO_writePin(port_num, pin_num, LOGIC_LOW); //turn off the led
}

/*
    * Description :
    * Turn mutiple LEDs OFF.
    * If the port number or pin number are not correct, The function will not handle the request.
    * If the a LED is already OFF, The function will continue to handle the others.
    * If the pin is input pin, The function will continue to handle the others.
*/
void LED_offMultiple(uint8 port_num, uint8 pin_num, uint8 number){
        
        uint8 i;
        for(i=0; i<number; i++){
            if(GPIO_readPinDirection(port_num, pin_num+i) == PIN_INPUT) //check if the pin is output
                continue; //do nothing
    
            if(GPIO_readPin(port_num, pin_num+i) == LOGIC_LOW) //if the led is already off
                continue; //do nothing
    
            GPIO_writePin(port_num, pin_num+i, LOGIC_LOW); //turn off the led
        }
}

/*
    * Description :
    * Toggle the LED.
    * If the input port number or pin number are not correct, The function will not handle the request.
*/ 
void LED_toggle(uint8 port_num, uint8 pin_num){
    
    if(GPIO_readPinDirection(port_num, pin_num) == PIN_INPUT) //check if the pin is output
        return; //do nothing
    
    GPIO_togglePin(port_num, pin_num); //toggle the led
}


/*
    * Description :
    * Display binary represntation of a number on 4 leds.
    * If the input port number or pin number are not correct, The function will not handle the request.
*/
void LED_displayNumber(uint8 port_num, uint8 pin_num, uint8 number){

    if(GPIO_readPinDirection(port_num, pin_num) == PIN_INPUT) //check if the pin is output
        return; //do nothing  
    if(GPIO_readPinDirection(port_num, pin_num+1) == PIN_INPUT) //check if the pin is output
        return; //do nothing
    if(GPIO_readPinDirection(port_num, pin_num+2) == PIN_INPUT) //check if the pin is output
        return; //do nothing
    if(GPIO_readPinDirection(port_num, pin_num+3) == PIN_INPUT) //check if the pin is output
        return; //do nothing        
    uint8 i;
    for(i=0; i<4; i++){
        if(number & (1<<i)) //check if the ith bit is 1
            LED_on(port_num, pin_num+i); //turn on the led
        else
            LED_off(port_num, pin_num+i); //turn off the led
    }
}
