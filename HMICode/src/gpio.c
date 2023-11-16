#include "../include/gpio.h"
#include "../include/common_macros.h"
#include "../include/gpio_reg.h"


/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
void GPIO_setupPinDirection(uint8 port_num, uint8 pin_num, GPIO_PinDirectionType direction){
    if(port_num > NUM_OF_PORTS)
    return;

switch (port_num)
{
case PORTB_ID:
    if(pin_num >= NUM_OF_PINS_PER_PORTB)
    return;
    if(direction == PIN_OUTPUT)
    {
        SET_BIT(DDRB,pin_num);
    }
    else
    {
        CLR_BIT(DDRB,pin_num);
    }
    break;

    case PORTC_ID:
    if(pin_num >= NUM_OF_PINS_PER_PORTC)
    return;
     if(direction == PIN_OUTPUT)
    {
        SET_BIT(DDRC,pin_num);
    }
    else
    {
        CLR_BIT(DDRC,pin_num);
    }
    break;
    case PORTD_ID:
    if(pin_num >= NUM_OF_PINS_PER_PORTD)
    return;

     if(direction == PIN_OUTPUT)
    {
        SET_BIT(DDRD,pin_num);
    }
    else
    {
        CLR_BIT(DDRD,pin_num);
    }
break;

}
}

/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 * If the pin is input, this function will enable/disable the internal pull-up resistor.
 */
void GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 value){
    if(port_num > NUM_OF_PORTS)
    return;
    switch (port_num)
    {
        case PORTB_ID:
           if(pin_num >= NUM_OF_PINS_PER_PORTB)
    return;
        if(value == LOGIC_HIGH)
            SET_BIT(PORTB,pin_num);
        else
            CLR_BIT(PORTB,pin_num);
        break;
        case PORTC_ID:
           if(pin_num >= NUM_OF_PINS_PER_PORTC)
    return;
 if(value == LOGIC_HIGH)
            SET_BIT(PORTC,pin_num);
        else
            CLR_BIT(PORTC,pin_num);
        break;
        case PORTD_ID:
           if(pin_num >= NUM_OF_PINS_PER_PORTD)
    return;
 if(value == LOGIC_HIGH)
            SET_BIT(PORTD,pin_num);
        else
            CLR_BIT(PORTD,pin_num);
        break;
    
    default:
        break;
    }
}

/*
 * Description :
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 * If the input port number or pin number are not correct, The function will return Logic Low.
 */
uint8 GPIO_readPin(uint8 port_num, uint8 pin_num){
    if(port_num > NUM_OF_PORTS)
    return 0;
    uint8 port_val= LOGIC_LOW;

    switch (port_num)
    {
        case PORTB_ID:
           if(pin_num >= NUM_OF_PINS_PER_PORTB)
    return 0;
        port_val = READ_BIT(PORTB,pin_num);
        break;
        case PORTC_ID:
           if(pin_num >= NUM_OF_PINS_PER_PORTC)
    return 0;
        port_val = READ_BIT(PORTC,pin_num);

        break;
        case PORTD_ID:
           if(pin_num >= NUM_OF_PINS_PER_PORTD)
    return 0;

        port_val = READ_BIT(PORTD,pin_num);
        break;

    }
    return port_val;
}


/*
 * Description :
 * Read then toggle the value for the required pin.
 * If the input port number or pin number are not correct, The function will return Logic Low.
 */
void GPIO_togglePin(uint8 port_num, uint8 pin_num){

   if(port_num > NUM_OF_PORTS)
    return;

    switch (port_num)
    {
        case PORTB_ID:
           if(pin_num >= NUM_OF_PINS_PER_PORTB)
    return;
        if(READ_BIT(PORTB,pin_num) != LOGIC_HIGH)
            SET_BIT(PORTB,pin_num);
        else
            CLR_BIT(PORTB,pin_num);
        break;
        case PORTC_ID:
           if(pin_num >= NUM_OF_PINS_PER_PORTC)
                return;
        if(READ_BIT(PORTC,pin_num) != LOGIC_HIGH)

            SET_BIT(PORTC,pin_num);
        else
            CLR_BIT(PORTC,pin_num);
        break;

        case PORTD_ID:
           if(pin_num >= NUM_OF_PINS_PER_PORTD)
                return;
        if(READ_BIT(PORTD,pin_num) != LOGIC_HIGH)

            SET_BIT(PORTD,pin_num);
        else
            CLR_BIT(PORTD,pin_num);
        break;
    
    default: break;
    }

}

/*
 * Description :
 * Setup the direction of the required port all pins input/output.
 * If the direction value is PORT_INPUT all pins in this port should be input pins.
 * If the direction value is PORT_OUTPUT all pins in this port should be output pins.
 * If the input port number is not correct, The function will not handle the request.
 */
void GPIO_setupPortDirection(uint8 port_num, uint8 direction){
   if(port_num > NUM_OF_PORTS)
    return;
       switch (port_num)
    {
        case PORTB_ID:
            DDRB = direction;      
        break;
        case PORTC_ID:

         DDRC = direction;
        break;
        case PORTD_ID:

   DDRD = direction;
           break;

    }
}

/*
 * Description :
 * Write the value on the required port.
 * If any pin in the port is output pin the value will be written.
 * If any pin in the port is input pin this will activate/deactivate the internal pull-up resistor.
 * If the input port number is not correct, The function will not handle the request.
 */
void GPIO_writePort(uint8 port_num, uint8 value){
 if(port_num > NUM_OF_PORTS)
    return;
    switch (port_num)
    {
        case PORTB_ID:
            PORTB = value;      
        break;
        case PORTC_ID:

            PORTC = value;      

        break;
        case PORTD_ID:

            PORTD = value;      
           break;
    
    default:
        break;
    }
}

/*
 * Description :
 * Read and return the value of the required port.
 * If the input port number is not correct, The function will return ZERO value.
 */
uint8 GPIO_readPort(uint8 port_num){
 if(port_num > NUM_OF_PORTS)
    return 0;
uint8 port_val = 0;

    switch (port_num)
    {
        case PORTB_ID:
           port_val = PINB;   
        break;
        case PORTC_ID:
           port_val = PINC;   

        break;
        case PORTD_ID:

           port_val = PIND;   
           break;
    }
    return port_val;
}

GPIO_PinDirectionType GPIO_readPinDirection(uint8 port_num, uint8 pin_num){

    GPIO_PinDirectionType pin_dir = PIN_INPUT;

    if(port_num > NUM_OF_PORTS)
    return pin_dir;
    switch (port_num)
    {
        case PORTB_ID:
           if(pin_num >= NUM_OF_PINS_PER_PORTB)
                pin_dir = PIN_INPUT;
        pin_dir = READ_BIT(DDRB,pin_num);
        break;

        case PORTC_ID:
           if(pin_num >= NUM_OF_PINS_PER_PORTC)
                pin_dir = PIN_INPUT;
        pin_dir = READ_BIT(DDRC,pin_num);
        break;

        case PORTD_ID:
           if(pin_num >= NUM_OF_PINS_PER_PORTD)
                pin_dir = PIN_INPUT;
        pin_dir = READ_BIT(DDRD,pin_num);
        break;

    }
    return pin_dir;
}
