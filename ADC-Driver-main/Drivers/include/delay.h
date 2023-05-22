#ifndef INC_DELAYH
#define INC_DELAYH
#include"stm32f4xx.h"

__IO time_us, time_ms;

void DELAY_INIT(void);
void delay_us(uint32_t);
void DELAY_ms(uint32_t);
#endif / INC_DELAYH */
