#ifndef PUSH_BUTTON_H_
#define PUSH_BUTTON_H_
#include "std_types.h"

void BUTTON_init(uint8 port , uint8 pin);
uint8 BUTTON_read(uint8 port , uint8 pin);

#endif /* PUSH_BUTTON_H_ */