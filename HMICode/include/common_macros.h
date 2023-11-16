#ifndef COMMON_MACROS_H_
#define COMMON_MACROS_H_

#define SET_BIT(REG,BIT)(REG = (REG | (1<<BIT)))
#define CLR_BIT(REG,BIT)(REG = (REG & (~(1<<BIT))))
#define READ_BIT(REG,BIT)(REG & (1<<BIT))
#define TOGGLE_BIT(REG,BIT)(REG = (REG ^ (1<<BIT)))
#define ROR (REG,BIT)((REG>>BIT) | (REG << (8-BIT)))
#define ROL (REG,BIT)((REG<<BIT) | (REG >> (8-BIT)))

#endif /* COMMON_MACROS_H_ */