#ifndef ADC_H_
#define ADC_H_

#include "adc_reg.h"

/*******************************************************************************
 *                              Static Definitions                             *
 *******************************************************************************/
typedef enum {
    ADC_F_CPU_2, ADC_F_CPU_4, ADC_F_CPU_8, ADC_F_CPU_16, ADC_F_CPU_32, ADC_F_CPU_64, ADC_F_CPU_128
}ADC_F_CLK;

typedef enum {
    ADC0, ADC1, ADC2, ADC3, ADC4, ADC5, ADC6, ADC7
}ADC_Channel;

typedef enum {
    ADC_AREF, ADC_AVCC, ADC_INTERNAL
}ADC_Voltage_Ref;

typedef enum {
    ADC_LEFT, ADC_RIGHT
}ADC_Adjust;

typedef enum {
    ADC_8BIT, ADC_10BIT
}ADC_Resolution;

typedef enum {
    ADC_FREE_RUNNING, ADC_ANALOG_COMPARATOR, ADC_EXTERNAL_INTERRUPT_REQUEST_0, ADC_TIMER_COUNTER0_COMPARE_MATCH, ADC_TIMER_COUNTER0_OVERFLOW, ADC_TIMER_COUNTER_COMPARE_MATCH_B, ADC_TIMER_COUNTER1_OVERFLOW, ADC_TIMER_COUNTER1_CAPTURE_EVENT
}ADC_Trigger_Source;

/*******************************************************************************
 *                             Dynamic Definitions                             *
 *******************************************************************************/
typedef struct ADC_Configurations
{
    ADC_F_CLK ADC_Clk;
    ADC_Channel ADC_Ch;
    ADC_Voltage_Ref ADC_Vref;
    ADC_Adjust ADC_Adjustment;
    ADC_Resolution ADC_Res;
    ADC_Trigger_Source ADC_Trigger;

}ADC_Configurations;


/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

void ADC_Init(ADC_Configurations * Config_Ptr);

#endif /*ADC_H_*/