#include "../include/adc.h"

void ADC_Init(ADC_Configurations * Config_Ptr)
{
    
}
void ADC_initRand(){
    // Select ADC reference voltage and resolution
  // For example, using AVCC as reference and 8-bit resolution
  ADMUX = (1 << 6) | (1 << 5);
  
  // Enable ADC, enable ADC interrupt, and start conversion
  ADCSRA |= (1 << 7) | (1 << 3) | (1 << 6);
}

