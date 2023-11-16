 /******************************************************************************
 *
 * Module: LED
 *
 * File Name: led.h
 *
 * Description: Header file for led interface wih AVR 
 *
 * Author: Yara Hisham
 *
 *******************************************************************************/


#ifndef LED_H_
#define LED_H_

/*******************************************************************************
 *                              Includes                                       *
 *******************************************************************************/
#include "std_types.h"

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
    * Description :
    * Initialize the LED pin as output pin.
    * Set the LED pin initial value to off.
*/
void LED_init(uint8 port_num, uint8 pin_num);


/*
    * Description :
    * Initialize multiple the LED pins as output pins.
    * Set the initial value of all pins to off.
*/
void LED_initMultiple(uint8 port_num, uint8 pin_num, uint8 number);

/*
    * Description :
    * Turn the LED ON.
    * If the port number or pin number are not correct, The function will not handle the request.
    * If the LED is already ON, The function will not handle the request.
    * If the pin is input pin, The function will not handle the request.
*/
void LED_on(uint8 port_num, uint8 pin_num);

/*
    * Description :
    * Turn the LED OFF.
    * If the input port number or pin number are not correct, The function will not handle the request.
*/
void LED_off(uint8 port_num, uint8 pin_num);

/*
    * Description :
    * Toggle the LED.
    * If the input port number or pin number are not correct, The function will not handle the request.
*/
void LED_toggle(uint8 port_num, uint8 pin_num);


/*
    * Description :
    * Display binary represntation of a number on 4 leds.
    * If the input port number or pin number are not correct, The function will not handle the request.
*/
void LED_displayNumber(uint8 port_num, uint8 pin_num, uint8 number);

#endif /* LED_H_ */