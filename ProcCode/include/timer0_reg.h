#ifdef TIMER0_REG_H
#define TIMER0_REG_H

#define SREG  (*((volatile char *)0x5F))

/*******************************************************************************
 *                               TIMER0 REGISTERS                              *
 *******************************************************************************/
#define TIFR0  (*((volatile char *)0x35))

#define TCCR0B (*((volatile char *)0x44))
#define TCCR0A (*((volatile char *)0x45)) 

#define TCNT0  (*((volatile char *)0x46)) //Timer/Counter0 (8-bit)

#define OCR0A  (*((volatile char *)0x47)) //Timer/Counter0 Output Compare Register A
#define OCR0B  (*((volatile char *)0x48)) //Timer/Counter0 Output Compare Register B

#define TIMSK0 (*((volatile char *)0x6E))


#endif /*_TIMER_REG_H*/
