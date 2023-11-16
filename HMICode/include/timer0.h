/******************************************************************************
 *
 * Module: TIMER0
 *
 * File Name: timer0.h
 *
 * Description: Header file for the AVR TIMER0 driver
 *
 * Author: Yara Hisham
 *
 *******************************************************************************/

#ifndef TIMER0_H_
#define TIMER0_H_

#include "std_types.h"

/*******************************************************************************
 *                              Static Definitions                             *
 *******************************************************************************/
static uint8 TIMER0_OVF = 0; //number of overflows needed per second
static uint8 TIMER0_HalfOVF = 0; //number of overflows needed per half of second

#ifdef F_CPU
#define F_CPU 16000000UL
#endif

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
typedef enum {
    TIMER_NO_CLOCK,TIMER_F_CPU, TIMER_F_CPU_8, TIMER_F_CPU_64, TIMER_F_CPU_256, TIMER_F_CPU_1024
}TIMER0_F_CLK;

typedef enum {
   OVERFLOW,CTC, PWM_PHASE_CORRECT, FAST_PWM
}Timer0_Mode;

typedef enum {
    NORMAL, TOGGLE, NON_INVERTING, INVERTING
}TIMER0_COM_Mode;

typedef enum {
    POLLING, INTERRUPT
}TIMER0_Process_Mode;

typedef enum {
    MAX, OCRA, ICR
}TIMER0_Top_Value;

typedef enum {
    A,B
}TIMER0_Compare_Match;

/*******************************************************************************
 *                             Dynamic Definitions                             *
 *******************************************************************************/
typedef struct 
{
    Timer0_Mode TimerMode;
    TIMER0_F_CLK TimerClk;
    TIMER0_COM_Mode TimerCom;
    TIMER0_Process_Mode TimerProcess;
    uint16 TimerInitialValue;
    uint16 TimerCompareValue;
    TIMER0_Top_Value TimerTopValue;
    TIMER0_Compare_Match TimerMatch;

}Timer0_Configurations;

typedef struct 
{
    uint8 Day;
    uint8 Hour;
    uint8 Minute;
    uint8 Second;
}Timer0_Time;

typedef struct {
    void (*CallBackPtr_Ptr)(void);
    uint32 ticks;
    uint32 delay_ms;
}Timer0_Tasks;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

void TIMER0_init(Timer0_Configurations * Config_Ptr);
void TIMER0_setCallBack(void(*a_ptr)(void));
void TIMER0_deinit();

void TIMER0_delay_ms_INT(uint32 n);
void TIMER0_delay_us_INT(uint32 n);
void TIMER0_delay_ms_POLLING(uint32 n);
void TIMER0_delay_us_POLLING(uint32 n);

void TIMER0_delay_tasks(Timer0_Tasks Tasks []);

#endif // TIMER_H_//