#include "stm32f4xx.h"
#include "gpio.h"

void Interupt_init(void){

	RCC->APB2ENR|=(1u<<14);

	SYSCFG->EXTICR[0] |=(1u<<0);
	SYSCFG->EXTICR[0] &=~(1u<<1);
	SYSCFG->EXTICR[0] &=~(1u<<2);
	SYSCFG->EXTICR[0] &=~(1u<<3);

	SYSCFG->EXTICR[0] |=(1u<<4);
	SYSCFG->EXTICR[0] &=~(1u<<5);
	SYSCFG->EXTICR[0] &=~(1u<<6);
	SYSCFG->EXTICR[0] &=~(1u<<7);

	EXTI->IMR |=(1u<<0);
	EXTI->IMR |=(1u<<1);

	EXTI->FTSR |=(1u<<0);
	EXTI->FTSR |=(1u<<1);

	NVIC->ISER[0]|=(1u<<6);
	NVIC->ISER[0]|=(1u<<7);


}

