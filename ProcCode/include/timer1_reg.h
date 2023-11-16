#ifndef _TIMER1_REG_H
#define _TIMER1_REG_H

#define SREG  (*((volatile char *)0x5F))

/*******************************************************************************
 *                               TIMER1 REGISTERS                              *
 *******************************************************************************/
#define TCCR1C (*((volatile char *)0x82))
#define TCCR1B (*((volatile char *)0x81))
#define TCCR1A (*((volatile char *)0x80)) 

#define TCNT1 (*((volatile short *)0x84)) 
#define ICR1  (*((volatile short *)0x86)) 


#define OCR1A  (*((volatile short *)0x88)) //Timer/Counter1 Output Compare Register A
#define OCR1B  (*((volatile short *)0x8A)) //Timer/Counter1 Output Compare Register B

#define TIMSK1 (*((volatile char *)0x6F)) //Timer/Counter1 Interrupt Mask Register

#endif /*_TIMER_REG_H*/
