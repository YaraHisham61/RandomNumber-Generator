#ifndef EXT_INT_REG_H
#define EXT_INT_REG_H

#define SREG  (*((volatile char *)0x5F))
#define EICRA  (*((volatile char *)0x69))
#define EIMSK  (*((volatile char *)0x3D))
#define EIFR  (*((volatile char *)0x3C))
#define PCICR  (*((volatile char *)0x68))
#define PCMSK0  (*((volatile char *)0x6B))

#endif /* EXT_INT_REG_H */