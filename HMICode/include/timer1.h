/******************************************************************************
 *
 * Module: TIMER1
 *
 * File Name: TIMER1.h
 *
 * Description: Header file for the AVR TIMER1 driver
 *
 * Author: Yara Hisham
 *
 *******************************************************************************/

#ifndef TIMER1_H_
#define TIMER1_H_

#include "std_types.h"

/*******************************************************************************
 *                              Static Definitions                             *
 *******************************************************************************/

#ifdef F_CPU
#define F_CPU 16000000UL
#endif

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
// typedef enum {
//     TIMER1_NO_CLOCK,TIMER1_F_CPU, TIMER1_F_CPU_8, TIMER1_F_CPU_64, TIMER1_F_CPU_256, TIMER1_F_CPU_1024
// }TIMER1_F_CLK;

// typedef enum {
//    OVERFLOW,CTC, PWM_PHASE_CORRECT, FAST_PWM
// }TIMER1_Mode;

// typedef enum {
//     NORMAL, TOGGLE, NON_INVERTING, INVERTING
// }TIMER1_COM_Mode;

// typedef enum {
//     POLLING, INTERRUPT
// }TIMER1_Process_Mode;

// typedef enum {
//     MAX, OCRA, ICR
// }TIMER1_Top_Value;

// typedef enum {
//     A,B
// }TIMER1_Compare_Match;

// /*******************************************************************************
//  *                             Dynamic Definitions                             *
//  *******************************************************************************/
// typedef struct 
// {
//     TIMER1_Mode TIMER1Mode;
//     TIMER1_F_CLK TIMER1Clk;
//     TIMER1_COM_Mode TIMER1Com;
//     TIMER1_Process_Mode TIMER1Process;
//     uint16 TIMER1InitialValue;
//     uint16 TIMER1CompareValue;
//     TIMER1_Top_Value TIMER1TopValue;
//     TIMER1_Compare_Match TIMER1Match;

// }TIMER1_Configurations;

// typedef struct 
// {
//     uint8 Day;
//     uint8 Hour;
//     uint8 Minute;
//     uint8 Second;
// }TIMER1_Time;

// typedef struct {
//     void (*CallBackPtr_Ptr)(void);
//     uint32 ticks;
//     uint32 delay_ms;
// }TIMER1_Tasks;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

void TIMER1_initPWM();
void TIMER1_setDutyCycleA(float32 a_dutyCycle);
void TIMER1_setDutyCycleB(float32 b_dutyCycle);

#endif // TIMER1_H_//