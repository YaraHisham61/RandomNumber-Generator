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
 *                              Functions Prototypes                           *
 *******************************************************************************/

void TIMER1_initPWM();
void TIMER1_initOVF();
void TIMER1_setDutyCycleA(float32 a_dutyCycle);
void TIMER1_setDutyCycleB(float32 b_dutyCycle);

#endif // TIMER1_H_//