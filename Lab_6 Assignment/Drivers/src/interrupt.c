#include <stdio.h>
#include <stdlib.h>
#include "stm32f4xx.h"
#include "gpio.h"
#include <math.h>
#include <string.h>

GPIO_TypeDef* mark[5] = {GPIOA, GPIOB, GPIOC, GPIOD, GPIOE};
char hexNum[6] ="0x";
char GPIO_Position[1];
void interrupt_bit_INIT( GPIO_TypeDef * GPIOx, int SYSCFG_Num, int pinNum){

	//Enable clock access to sysconf
	RCC->APB2ENR|=(1u<<14);
	int flag_Cont = 0;

	//to fill the hexNum with the right values accroding to my GPIO and pinNum
	for (int j = 3;j>=0;j--){
		if (j == pinNum){
			for (int k = 0;k<5;k++){
				if (GPIOx == mark[k]){
					itoa(k, GPIO_Position, 10);
					strcat(hexNum, GPIO_Position);
					flag_Cont = 1;
					continue;
				}
			}
		}
		if(flag_Cont){
		    flag_Cont=0;
			continue;
		}
		strcat(hexNum, "0");
	}

	int num = (int)strtol(hexNum, NULL, 16);  // number base 16

	// Set Selection lines of EXTI
	SYSCFG->EXTICR[SYSCFG_Num] |= num;

	//Configure the mask bit of EXTI
	EXTI->IMR |= (1u<<pinNum);
	//Configure the Trigger as falling trigger
	EXTI->FTSR |= (1u<<pinNum);

	//Enable EXTI interrupt from NVIC
	NVIC->ISER[0] |= (1u<<(6+pinNum)); //only for pins from 0 to 4

}


