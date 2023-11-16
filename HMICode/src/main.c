#include "../include/seven_segment.h"
#include "../include/timer0.h"
#include "../include/timer1.h"
#include "../include/led.h"
#include "../include/uart.h"
#include "../include/gpio_reg.h"
#include "../include/push_button.h"
#include <avr/interrupt.h>


volatile uint16 randomDigits [5] = {0,0,0,0,0};
volatile uint64 randomNumber = 0;
uint8 i = 0;
uint8 x = 0;
uint8 r = 0;
uint8 next = 0;
uint8 prev = 0;
float32 step =0;
uint8 digit = 0;

ISR (PCINT0_vect) {
prev=1;

}

ISR (INT1_vect){
next=1;
}

ISR (INT0_vect){
sevenSegment_off();
TIMER1_setDutyCycleA(0);
TIMER1_setDutyCycleB(0);
uart_transmit('g');
  while (uart_receive() != 's');
      randomDigits[4] = uart_receive();
      randomNumber *= 10;
      randomDigits[3] = uart_receive();
      randomNumber *= 10;
      randomDigits[2] = uart_receive();
      randomNumber *= 10;
      randomDigits[1] = uart_receive();
      randomNumber *= 10;
      randomDigits[0] = uart_receive();
      randomNumber += randomDigits[0] + randomDigits[1] * 10 + randomDigits[2] * 100 + randomDigits[3] * 1000 + randomDigits[4] * 10000;
      step = (randomNumber%180) / 5;
r=1;
i=0;
}

int main(void) {

  /* Here you can setup your MCU */

  sevenSegment_init(SEVEN_SEGMENT_TYPE_CATHODE);
  uart_init();
  LED_initMultiple(PORTC_ID, PIN0_ID, 5);

  TIMER1_initPWM();

  BUTTON_init(PORTD_ID, PIN2_ID);
  BUTTON_init(PORTD_ID, PIN3_ID);
  BUTTON_init(PORTB_ID, PIN0_ID);
  /* Here you implement the logic of your MCU's behavior */
    EXT_INT_Init();
  for (;;) {
    EXT_INT_Init();
    if(r == 0)
    { 
      if(prev == 1){
        i--;
        prev=0;
        r=1;
    }
    if(next == 1){
      next=0;
    }
    continue;
    }

    if(prev == 1){
      i-=2;
      if(i<0)
        i=0;
      prev=0;
      LED_offMultiple(PORTC_ID,PIN0_ID,5);
      continue;
      }

      sevenSegment_displayNumber(randomDigits[i]);
      LED_on(PORTC_ID, PIN0_ID + i);
      TIMER1_setDutyCycleA(randomDigits[i]/10.0);
      TIMER1_setDutyCycleB(step * i);

      if(next != 1){
        TIMER0_delay_ms_POLLING(500);
        }

      if(next != 1){
        TIMER0_delay_ms_POLLING(500);
      }
      next = 0;
      LED_offMultiple(PORTC_ID,PIN0_ID,5);
      i++;
      if(i == 5){
        sevenSegment_off();
        TIMER1_setDutyCycleA(randomNumber/65535.0);
        TIMER1_setDutyCycleB(step * i);

        r = 0;
      }
  }
  return 0;
}

