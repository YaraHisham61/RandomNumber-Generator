#include "../include/seven_segment.h"
#include "../include/gpio.h"
#include "../include/gpio_reg.h"

static uint8 type;

void sevenSegment_init(uint8 t)
{
    type=t;
    GPIO_setupPinDirection(PORTD_ID,4,PIN_OUTPUT);
    GPIO_setupPinDirection(PORTD_ID,5,PIN_OUTPUT);
    GPIO_setupPinDirection(PORTD_ID,6,PIN_OUTPUT);
    GPIO_setupPinDirection(PORTD_ID,7,PIN_OUTPUT);
    GPIO_setupPinDirection(PORTB_ID,5,PIN_OUTPUT);
    GPIO_setupPinDirection(PORTB_ID,3,PIN_OUTPUT);
    GPIO_setupPinDirection(PORTB_ID,4,PIN_OUTPUT);
}

void sevenSegment_displayNumber(uint16 number){
    if(type == SEVEN_SEGMENT_TYPE_CATHODE)
        switch (number)
        {
        case 0:
        GPIO_writePin(PORTD_ID,4,LOGIC_HIGH);
        GPIO_writePin(PORTD_ID,5,LOGIC_HIGH);
        GPIO_writePin(PORTD_ID,6,LOGIC_HIGH);
        GPIO_writePin(PORTD_ID,7,LOGIC_HIGH);
        GPIO_writePin(PORTB_ID,5,LOGIC_HIGH);
        GPIO_writePin(PORTB_ID,3,LOGIC_HIGH);
        GPIO_writePin(PORTB_ID,4,LOGIC_LOW);
            break;
        case 1:
        GPIO_writePin(PORTD_ID,4,LOGIC_LOW);
        GPIO_writePin(PORTD_ID,5,LOGIC_HIGH);
        GPIO_writePin(PORTD_ID,6,LOGIC_HIGH);
        GPIO_writePin(PORTD_ID,7,LOGIC_LOW);
        GPIO_writePin(PORTB_ID,5,LOGIC_LOW);
        GPIO_writePin(PORTB_ID,3,LOGIC_LOW);
        GPIO_writePin(PORTB_ID,4,LOGIC_LOW);
            break;
        case 2:
        GPIO_writePin(PORTD_ID,4,LOGIC_HIGH);
        GPIO_writePin(PORTD_ID,5,LOGIC_HIGH);
        GPIO_writePin(PORTD_ID,6,LOGIC_LOW);
        GPIO_writePin(PORTD_ID,7,LOGIC_HIGH);
        GPIO_writePin(PORTB_ID,5,LOGIC_HIGH);
        GPIO_writePin(PORTB_ID,3,LOGIC_LOW);
        GPIO_writePin(PORTB_ID,4,LOGIC_HIGH);
            break;
        case 3:
        GPIO_writePin(PORTD_ID,4,LOGIC_HIGH);
        GPIO_writePin(PORTD_ID,5,LOGIC_HIGH);
        GPIO_writePin(PORTD_ID,6,LOGIC_HIGH);
        GPIO_writePin(PORTD_ID,7,LOGIC_HIGH);
        GPIO_writePin(PORTB_ID,5,LOGIC_LOW);
        GPIO_writePin(PORTB_ID,3,LOGIC_LOW);
        GPIO_writePin(PORTB_ID,4,LOGIC_HIGH);
            break;
        case 4:
        GPIO_writePin(PORTD_ID,4,LOGIC_LOW);
        GPIO_writePin(PORTD_ID,5,LOGIC_HIGH);
        GPIO_writePin(PORTD_ID,6,LOGIC_HIGH);
        GPIO_writePin(PORTD_ID,7,LOGIC_LOW);
        GPIO_writePin(PORTB_ID,5,LOGIC_LOW);
        GPIO_writePin(PORTB_ID,3,LOGIC_HIGH);
        GPIO_writePin(PORTB_ID,4,LOGIC_HIGH);
            break;
        case 5:
        GPIO_writePin(PORTD_ID,4,LOGIC_HIGH);
        GPIO_writePin(PORTD_ID,5,LOGIC_LOW);
        GPIO_writePin(PORTD_ID,6,LOGIC_HIGH);
        GPIO_writePin(PORTD_ID,7,LOGIC_HIGH);
        GPIO_writePin(PORTB_ID,5,LOGIC_LOW);
        GPIO_writePin(PORTB_ID,3,LOGIC_HIGH);
        GPIO_writePin(PORTB_ID,4,LOGIC_HIGH);
            break;
        case 6:
        GPIO_writePin(PORTD_ID,4,LOGIC_HIGH);
        GPIO_writePin(PORTD_ID,5,LOGIC_LOW);
        GPIO_writePin(PORTD_ID,6,LOGIC_HIGH);
        GPIO_writePin(PORTD_ID,7,LOGIC_HIGH);
        GPIO_writePin(PORTB_ID,5,LOGIC_HIGH);
        GPIO_writePin(PORTB_ID,3,LOGIC_HIGH);
        GPIO_writePin(PORTB_ID,4,LOGIC_HIGH);
            break;
        case 7:
        GPIO_writePin(PORTD_ID,4,LOGIC_HIGH);
        GPIO_writePin(PORTD_ID,5,LOGIC_HIGH);
        GPIO_writePin(PORTD_ID,6,LOGIC_HIGH);
        GPIO_writePin(PORTD_ID,7,LOGIC_LOW);
        GPIO_writePin(PORTB_ID,5,LOGIC_LOW);
        GPIO_writePin(PORTB_ID,3,LOGIC_LOW);
        GPIO_writePin(PORTB_ID,4,LOGIC_LOW);         
            break;
        case 8:
        GPIO_writePin(PORTD_ID,4,LOGIC_HIGH);
        GPIO_writePin(PORTD_ID,5,LOGIC_HIGH);
        GPIO_writePin(PORTD_ID,6,LOGIC_HIGH);
        GPIO_writePin(PORTD_ID,7,LOGIC_HIGH);
        GPIO_writePin(PORTB_ID,5,LOGIC_HIGH);
        GPIO_writePin(PORTB_ID,3,LOGIC_HIGH);
        GPIO_writePin(PORTB_ID,4,LOGIC_HIGH);
            break;
        case 9:
        GPIO_writePin(PORTD_ID,4,LOGIC_HIGH);
        GPIO_writePin(PORTD_ID,5,LOGIC_HIGH);
        GPIO_writePin(PORTD_ID,6,LOGIC_HIGH);
        GPIO_writePin(PORTD_ID,7,LOGIC_HIGH);
        GPIO_writePin(PORTB_ID,5,LOGIC_LOW);
        GPIO_writePin(PORTB_ID,3,LOGIC_HIGH);
        GPIO_writePin(PORTB_ID,4,LOGIC_HIGH);
            break;
        default:
        break;
        }

    else if(type == SEVEN_SEGMENT_TYPE_ANODE)
       switch (number)
       {
      case 0:
        GPIO_writePin(PORTD_ID,4,~LOGIC_HIGH);
        GPIO_writePin(PORTD_ID,5,~LOGIC_HIGH);
        GPIO_writePin(PORTD_ID,6,~LOGIC_HIGH);
        GPIO_writePin(PORTD_ID,7,~LOGIC_HIGH);
        GPIO_writePin(PORTB_ID,5,~LOGIC_HIGH);
        GPIO_writePin(PORTB_ID,3,~LOGIC_HIGH);
        GPIO_writePin(PORTB_ID,4,~LOGIC_LOW);
            break;
        case 1:
        GPIO_writePin(PORTD_ID,4,~LOGIC_LOW);
        GPIO_writePin(PORTD_ID,5,~LOGIC_HIGH);
        GPIO_writePin(PORTD_ID,6,~LOGIC_HIGH);
        GPIO_writePin(PORTD_ID,7,~LOGIC_LOW);
        GPIO_writePin(PORTB_ID,5,~LOGIC_LOW);
        GPIO_writePin(PORTB_ID,3,~LOGIC_LOW);
        GPIO_writePin(PORTB_ID,4,~LOGIC_LOW);
            break;
        case 2:
        GPIO_writePin(PORTD_ID,4,~LOGIC_HIGH);
        GPIO_writePin(PORTD_ID,5,~LOGIC_HIGH);
        GPIO_writePin(PORTD_ID,6,~LOGIC_LOW);
        GPIO_writePin(PORTD_ID,7,~LOGIC_HIGH);
        GPIO_writePin(PORTB_ID,5,~LOGIC_HIGH);
        GPIO_writePin(PORTB_ID,3,~LOGIC_LOW);
        GPIO_writePin(PORTB_ID,4,~LOGIC_HIGH);
            break;
        case 3:
        GPIO_writePin(PORTD_ID,4,~LOGIC_HIGH);
        GPIO_writePin(PORTD_ID,5,~LOGIC_HIGH);
        GPIO_writePin(PORTD_ID,6,~LOGIC_HIGH);
        GPIO_writePin(PORTD_ID,7,~LOGIC_HIGH);
        GPIO_writePin(PORTB_ID,5,~LOGIC_LOW);
        GPIO_writePin(PORTB_ID,3,~LOGIC_LOW);
        GPIO_writePin(PORTB_ID,4,~LOGIC_HIGH);
            break;
        case 4:
        GPIO_writePin(PORTD_ID,4,~LOGIC_LOW);
        GPIO_writePin(PORTD_ID,5,~LOGIC_HIGH);
        GPIO_writePin(PORTD_ID,6,~LOGIC_HIGH);
        GPIO_writePin(PORTD_ID,7,~LOGIC_LOW);
        GPIO_writePin(PORTB_ID,5,~LOGIC_LOW);
        GPIO_writePin(PORTB_ID,3,~LOGIC_HIGH);
        GPIO_writePin(PORTB_ID,4,~LOGIC_HIGH);
            break;
        case 5:
        GPIO_writePin(PORTD_ID,4,~LOGIC_HIGH);
        GPIO_writePin(PORTD_ID,5,~LOGIC_LOW);
        GPIO_writePin(PORTD_ID,6,~LOGIC_HIGH);
        GPIO_writePin(PORTD_ID,7,~LOGIC_HIGH);
        GPIO_writePin(PORTB_ID,5,~LOGIC_LOW);
        GPIO_writePin(PORTB_ID,3,~LOGIC_HIGH);
        GPIO_writePin(PORTB_ID,4,~LOGIC_HIGH);
            break;
        case 6:
        GPIO_writePin(PORTD_ID,4,~LOGIC_HIGH);
        GPIO_writePin(PORTD_ID,5,~LOGIC_LOW);
        GPIO_writePin(PORTD_ID,6,~LOGIC_HIGH);
        GPIO_writePin(PORTD_ID,7,~LOGIC_HIGH);
        GPIO_writePin(PORTB_ID,5,~LOGIC_HIGH);
        GPIO_writePin(PORTB_ID,3,~LOGIC_HIGH);
        GPIO_writePin(PORTB_ID,4,~LOGIC_HIGH);
            break;
        case 7:
        GPIO_writePin(PORTD_ID,4,~LOGIC_HIGH);
        GPIO_writePin(PORTD_ID,5,~LOGIC_HIGH);
        GPIO_writePin(PORTD_ID,6,~LOGIC_HIGH);
        GPIO_writePin(PORTD_ID,7,~LOGIC_LOW);
        GPIO_writePin(PORTB_ID,5,~LOGIC_LOW);
        GPIO_writePin(PORTB_ID,3,~LOGIC_LOW);
        GPIO_writePin(PORTB_ID,4,~LOGIC_LOW);         
            break;
        case 8:
        GPIO_writePin(PORTD_ID,4,~LOGIC_HIGH);
        GPIO_writePin(PORTD_ID,5,~LOGIC_HIGH);
        GPIO_writePin(PORTD_ID,6,~LOGIC_HIGH);
        GPIO_writePin(PORTD_ID,7,~LOGIC_HIGH);
        GPIO_writePin(PORTB_ID,5,~LOGIC_HIGH);
        GPIO_writePin(PORTB_ID,3,~LOGIC_HIGH);
        GPIO_writePin(PORTB_ID,4,~LOGIC_HIGH);
            break;
        case 9:
        GPIO_writePin(PORTD_ID,4,~LOGIC_HIGH);
        GPIO_writePin(PORTD_ID,5,~LOGIC_HIGH);
        GPIO_writePin(PORTD_ID,6,~LOGIC_HIGH);
        GPIO_writePin(PORTD_ID,7,~LOGIC_HIGH);
        GPIO_writePin(PORTB_ID,5,~LOGIC_LOW);
        GPIO_writePin(PORTB_ID,3,~LOGIC_HIGH);
        GPIO_writePin(PORTB_ID,4,~LOGIC_HIGH);
            break;
        default:
        break;
       }
}

void sevenSegment_off(){

        GPIO_writePin(PORTD_ID,4,LOGIC_LOW);
        GPIO_writePin(PORTD_ID,5,LOGIC_LOW);
        GPIO_writePin(PORTD_ID,6,LOGIC_LOW);
        GPIO_writePin(PORTD_ID,7,LOGIC_LOW);
        GPIO_writePin(PORTB_ID,5,LOGIC_LOW);
        GPIO_writePin(PORTB_ID,3,LOGIC_LOW);
        GPIO_writePin(PORTB_ID,4,LOGIC_LOW);
}