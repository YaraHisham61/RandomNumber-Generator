#include "../include/timer1.h"
#include "../include/gpio_reg.h"
#include "../include/timer1_reg.h"


void TIMER1_initPWM(){
  TCNT1 = 0;
  TCCR1A = 0b10100010; //phase correct PWM , Top in ICR1
  TCCR1B = 0b00010011;//phase correct PWM , Top in ICR1, prescaler = 1024
  TCCR1C = (1<<7)|(1<<6); //compare out a & b 
  DDRB |= (1 << 1);
  DDRB |= (1 << 2);
  ICR1 = 2500; //top value
  OCR1A = 0;
  OCR1B = 125;
}

void TIMER1_setDutyCycleA(float32 a_dutyCycle){
  OCR1A = a_dutyCycle * 2500;
}

void TIMER1_setDutyCycleB(float32 b_dutyCycle){
  b_dutyCycle *=125;
  b_dutyCycle /= 180;
  b_dutyCycle +=125;
  OCR1B = b_dutyCycle;
}