#include "../include/timer0.h"
#include "../include/timer0_reg.h"
#include "../include/common_macros.h"
#include "../include/gpio.h"
#include <avr/interrupt.h>

/*******************************************************************************
 *                                 Global Vars                                 *
 *******************************************************************************/
static volatile void (*g_CallBackPtr_Timer0)(void);
volatile uint32 g_ticks=0;
static Timer0_Configurations * Timer0_Config_Ptr = NULL;
static uint32 ticks =0;
#define maxCount 4
Timer0_Tasks g_tasks [maxCount];

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

void TIMER0_init(Timer0_Configurations * Config_Ptr){

    switch (Config_Ptr->TimerMode)
    {
     case OVERFLOW:
        CLR_BIT(TCCR0A,0);
        CLR_BIT(TCCR0A,1);
        CLR_BIT(TCCR0B,3);
        break;
    case CTC:
        CLR_BIT(TCCR0A,0);
        SET_BIT(TCCR0A,1);
        CLR_BIT(TCCR0B,3);
        break;
    case PWM_PHASE_CORRECT:
    switch (Config_Ptr->TimerTopValue)
    {
    case MAX:
        SET_BIT(TCCR0A,0);
        CLR_BIT(TCCR0A,1);
        CLR_BIT(TCCR0B,3);
        break;
    case OCRA:
        // SET_BIT(TCCR0A,0);
        // CLR_BIT(TCCR0A,1);
        // SET_BIT(TCCR0B,3);
        break;
    default: break;
    }
        break;
    case FAST_PWM:
        switch (Config_Ptr->TimerTopValue)
        {
        case MAX:
            SET_BIT(TCCR0A,0);
            SET_BIT(TCCR0A,1);
            CLR_BIT(TCCR0B,3);
            break;
        case OCRA:
            SET_BIT(TCCR0A,0);
            SET_BIT(TCCR0A,1);
            SET_BIT(TCCR0B,3);
            break;
        default: break;
        }
        break;

    }
    switch (Config_Ptr->TimerClk)
    {
    case TIMER_NO_CLOCK:
        CLR_BIT(TCCR0B,0);
        CLR_BIT(TCCR0B,1);
        CLR_BIT(TCCR0B,2);
        break;
    case TIMER_F_CPU:
        SET_BIT(TCCR0B,0);
        CLR_BIT(TCCR0B,1);
        CLR_BIT(TCCR0B,2);
        break;
    case TIMER_F_CPU_8:
        CLR_BIT(TCCR0B,0);
        SET_BIT(TCCR0B,1);
        CLR_BIT(TCCR0B,2);
        break;
    case TIMER_F_CPU_64:
        SET_BIT(TCCR0B,0);
        SET_BIT(TCCR0B,1);
        CLR_BIT(TCCR0B,2);
        break;
    case TIMER_F_CPU_256:
        CLR_BIT(TCCR0B,0);
        CLR_BIT(TCCR0B,1);
        SET_BIT(TCCR0B,2);
        break;
    case TIMER_F_CPU_1024:
        SET_BIT(TCCR0B,0);
        CLR_BIT(TCCR0B,1);
        SET_BIT(TCCR0B,2);
        break;
    }
    switch (Config_Ptr->TimerCom)
    {
    case NORMAL:
        switch (Config_Ptr->TimerMatch)
        {
        case A:
            CLR_BIT(TCCR0A,7);
            CLR_BIT(TCCR0A,6);
            break;
        case B:
            CLR_BIT(TCCR0A,5);
            CLR_BIT(TCCR0A,4);
        }
        break;
    case TOGGLE:
        switch (Config_Ptr->TimerMatch)
        {
        case A:
            CLR_BIT(TCCR0A,7);
            SET_BIT(TCCR0A,6);
            break;
        case B:
            CLR_BIT(TCCR0A,5);
            SET_BIT(TCCR0A,4);
        }
        break;
    case NON_INVERTING:
        switch (Config_Ptr->TimerMatch)
        {
        case A:
            CLR_BIT(TCCR0A,7);
            SET_BIT(TCCR0A,6);
            break;
        case B:
            CLR_BIT(TCCR0A,5);
            SET_BIT(TCCR0A,4);
        }
        break;
    case INVERTING:
        switch (Config_Ptr->TimerMatch)
        {
        case A:
            SET_BIT(TCCR0A,7);
            SET_BIT(TCCR0A,6);
            break;
        case B:

            SET_BIT(TCCR0A,5);
            SET_BIT(TCCR0A,4);
        }
        break;
    }
    switch (Config_Ptr->TimerProcess)
    {
    case POLLING:
        CLR_BIT(TIMSK0,0);
        SET_BIT(TIFR0,0);
        CLR_BIT(SREG,7);
        break;
    case INTERRUPT:
        SET_BIT(TIMSK0,0);
        SET_BIT(TIFR0,0);
        SET_BIT(SREG,7);
        break;
    }
    TCNT0 = Config_Ptr->TimerInitialValue;
    OCR0A = Config_Ptr->TimerCompareValue;
    OCR0B = Config_Ptr->TimerCompareValue;
    // Timer0_Config_Ptr = Config_Ptr;
    g_ticks = 0;
}

void TIMER0_setCallBack(void(*a_ptr)(void)){
    g_CallBackPtr_Timer0 = (volatile void *)a_ptr;
}

void TIMER0_deinit(){
    TCNT0 = 0;
    OCR0A = 0;
    OCR0B = 0;
}

ISR (TIMER0_OVF_vect){
    g_ticks++; 
    SET_BIT(TIFR0,0);

    for (uint16 i = 0; i < maxCount; i++)
    {
        if(g_ticks %  g_tasks[i].delay_ms == 0){
            if(g_tasks[i].CallBackPtr_Ptr != NULL){
            (*g_tasks[i].CallBackPtr_Ptr)();
        }
    }
    }
}

void TIMER0_delay_ms_POLLING(uint32 n){
    Timer0_Configurations delay_Config = {OVERFLOW, TIMER_F_CPU_1024, NORMAL, POLLING, 0, 0, MAX, A};
    TIMER0_init(&delay_Config);
    float64 x = 1024.0/F_CPU;
    x*=255;
    ticks =(n/1000.0)/x;
    for (uint32 i = 0; i < ticks; i++)
    {
        while(READ_BIT(TIFR0,0)==0);
        SET_BIT(TIFR0,0);
    }
    // TIMER0_init(Timer0_Config_Ptr);
}

void TIMER0_delay_ms_INT(uint32 n){
    Timer0_Configurations delay_Config = {OVERFLOW, TIMER_F_CPU_1024, NORMAL, INTERRUPT, 0, 0, MAX, A};
    TIMER0_init(&delay_Config);
    float64 x = 1024.0/F_CPU;
    x*=255;
    ticks =(n/1000.0)/x;
}

void TIMER0_delay_us_POLLING(uint32 n){
    Timer0_Configurations delay_Config = {OVERFLOW, TIMER_F_CPU_1024, NORMAL, POLLING, 0, 0, MAX, A};
    TIMER0_init(&delay_Config);
    float64 x = 1024.0/F_CPU;
    x*=255;
    ticks =(n/1000000.0)/x;
    for (uint32 i = 0; i < ticks; i++)
    {
        while(READ_BIT(TIFR0,0)==0);
        SET_BIT(TIFR0,0);
    }
    TIMER0_init(Timer0_Config_Ptr);
}


void TIMER0_delay_us_INT(uint32 n){
    Timer0_Configurations delay_Config = {OVERFLOW, TIMER_F_CPU_1024, NORMAL, INTERRUPT, 0, 0, MAX, A};
    TIMER0_init(&delay_Config);
    float64 x = 1024.0/F_CPU;
    x*=255;
    ticks =(n/1000000.0)/x;
}

void TIMER0_delay_tasks(Timer0_Tasks Tasks []){
    for (uint16 i = 0; i < maxCount; i++){
    g_tasks[i] = Tasks[i];
    }
    // Timer0_Configurations delay_Config = {CTC, TIMER_F_CPU_1024, NORMAL, INTERRUPT, 0, 7, OCRA, A};
    // TIMER0_init(&delay_Config);
    float64 x = 1024.0/F_CPU;
    x*=255;
    // ticks =(1/1000000.0)/x; //generate delay every 1us 
    TCCR0A=0;TCCR0B=0;
    SET_BIT(TCCR0A,1);
    SET_BIT(TCCR0B,1);
    SET_BIT(TCCR0B,0);
    TCNT0=0;
    OCR0A=124; //1.024x10-3
    OCR0B=0;
    SET_BIT(TIMSK0,0);
    SET_BIT(TIFR0,0);
    SET_BIT(SREG,7);//generate delay every 1ms 

    for (uint16 i = 0; i < maxCount; i++)
    {
       Tasks[i].ticks = (Tasks[i].delay_ms);
    }
}