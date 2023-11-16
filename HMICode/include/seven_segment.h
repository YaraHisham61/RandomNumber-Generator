 /******************************************************************************
 *
 * Module: SEVEN SEGMENT
 *
 * File Name: seven_segment.h
 *
 * Description: Header file for the AVR 7 segment driver
 *
 * Author: Yara Hisham
 *
 *******************************************************************************/

#ifndef SEVEN_SEGMENT_H_
#define SEVEN_SEGMENT_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define SEVEN_SEGMENT_TYPE_CATHODE (0u)
#define SEVEN_SEGMENT_TYPE_ANODE (1u)


/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
void sevenSegment_init(uint8 t);
void sevenSegment_displayNumber(uint16 number);
void sevenSegment_off();
#endif /*SEVEN_SEGMENT_H_*/

