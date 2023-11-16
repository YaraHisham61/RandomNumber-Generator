#include "../include/seven_segment.h"
#include "../include/adc.h"
#include "../include/timer0.h"
#include "../include/timer1.h"
#include "../include/timer1_reg.h"
#include "../include/led.h"
#include "../include/uart.h"
#include "../include/push_button.h"
#include <avr/interrupt.h>

volatile uint16 randomDigit = 0;
volatile uint16 randomNumber [5] = {0,0,0,0,0};

int main() {
  cli();
  TIMER1_initOVF();
  sevenSegment_init(SEVEN_SEGMENT_TYPE_CATHODE);
  ADC_initRand();
  LED_init(PORTC_ID, PIN1_ID);
  LED_init(PORTC_ID, PIN2_ID);
  LED_init(PORTC_ID, PIN3_ID);
  sei();
  uart_init();

  
  while (1) {
    uint8 x = uart_receive();

    if(x == 'g'){
      LED_on(PORTC_ID, PIN1_ID);

  // Use Timer1 value as seed to update randomDigit
      randomDigit += TCNT1;

  for (uint8 i = 0 ; i<5 ; i++ ){
    randomNumber[i] = ((randomDigit ^ TCNT1) % 10);
    }
    TIMER0_delay_ms_POLLING(1000);
      LED_on(PORTC_ID, PIN2_ID);
      uart_transmit('s');
      uart_transmit(randomNumber[4]);
      uart_transmit(randomNumber[3]);
      uart_transmit(randomNumber[2]);
      uart_transmit(randomNumber[1]);
      uart_transmit(randomNumber[0]);
      TIMER0_delay_ms_POLLING(1000);
      LED_on(PORTC_ID, PIN3_ID);
      TIMER0_delay_ms_POLLING(1000);
      LED_off(PORTC_ID, PIN1_ID);
      LED_off(PORTC_ID, PIN2_ID);
      LED_off(PORTC_ID, PIN3_ID);

      if(uart_checkErrors()){
        for(uint8 i = 0 ; i<10 ; i++){
        LED_toggle(PORTC_ID, PIN1_ID);
        LED_toggle(PORTC_ID, PIN1_ID);
        LED_toggle(PORTC_ID, PIN1_ID);
        TIMER0_delay_ms_POLLING(500);
        }
      }
    }
    // Use the generated random number as needed
    // ...
  }
  
  return 0;
}

// ADC conversion complete interrupt service routine
ISR(ADC_vect) {
  // Read ADC result
  uint16 adcValue = ADC;
  
  // Use ADC value to further update randomDigit
  randomDigit ^= adcValue;
  
  // Start new ADC conversion
  ADCSRA |= (1 << 6);
}
