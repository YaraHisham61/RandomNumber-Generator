#ifndef ADC_REG_H_
#define ADC_REG_H_

#define DIDR0  (*((volatile char *)0x7E))
#define ADMUX  (*((volatile char *)0x7C))
#define ADCSRB (*((volatile char *)0x7B))
#define ADCSRA (*((volatile char *)0x7A))
#define ADC   (*((volatile short *)0x78))

#endif /*ADC_REG_H_*/