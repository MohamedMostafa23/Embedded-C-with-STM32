#include "stm32f4xx.h"
#include "gpio.h" //for some reason if this was included first it gives an error
extern ctr;
void sev_seg_init(GPIO_TypeDef * GPIOx, char x1,char x2,char x3,char x4,char e){
	GPIO_Init(GPIOx,x1,1,e);
	GPIO_Init(GPIOx,x2,1,e);
	GPIO_Init(GPIOx,x3,1,e);
	GPIO_Init(GPIOx,x4,1,e);
}


void sev_seg(GPIO_TypeDef * GPIOx, char pin[], char val){
	switch(val){
		case 0:
			GPIO_Write(GPIOx, pin[0], 0);
			GPIO_Write(GPIOx, pin[1], 0);
			GPIO_Write(GPIOx, pin[2], 0);
			GPIO_Write(GPIOx, pin[3], 0);
			break;
		case 1:
			GPIO_Write(GPIOx, pin[0], 1);
			GPIO_Write(GPIOx, pin[1], 0);
			GPIO_Write(GPIOx, pin[2], 0);
			GPIO_Write(GPIOx, pin[3], 0);
			break;
		case 2:
			GPIO_Write(GPIOx, pin[0], 0);
			GPIO_Write(GPIOx, pin[1], 1);
			GPIO_Write(GPIOx, pin[2], 0);
			GPIO_Write(GPIOx, pin[3], 0);
			break;
		case 3:
			GPIO_Write(GPIOx, pin[0], 1);
			GPIO_Write(GPIOx, pin[1], 1);
			GPIO_Write(GPIOx, pin[2], 0);
			GPIO_Write(GPIOx, pin[3], 0);
			break;
		case 4:
			GPIO_Write(GPIOx, pin[0], 0);
			GPIO_Write(GPIOx, pin[1], 0);
			GPIO_Write(GPIOx, pin[2], 1);
			GPIO_Write(GPIOx, pin[3], 0);
			break;
		case 5:
			GPIO_Write(GPIOx, pin[0], 1);
			GPIO_Write(GPIOx, pin[1], 0);
			GPIO_Write(GPIOx, pin[2], 1);
			GPIO_Write(GPIOx, pin[3], 0);
			break;
		case 6:
			GPIO_Write(GPIOx, pin[0], 0);
			GPIO_Write(GPIOx, pin[1], 1);
			GPIO_Write(GPIOx, pin[2], 1);
			GPIO_Write(GPIOx, pin[3], 0);
			break;
		case 7:
			GPIO_Write(GPIOx, pin[0], 1);
			GPIO_Write(GPIOx, pin[1], 1);
			GPIO_Write(GPIOx, pin[2], 1);
			GPIO_Write(GPIOx, pin[3], 0);
			break;
		case 8:
			GPIO_Write(GPIOx, pin[0], 0);
			GPIO_Write(GPIOx, pin[1], 0);
			GPIO_Write(GPIOx, pin[2], 0);
			GPIO_Write(GPIOx, pin[3], 1);
			break;
		case 9:
			GPIO_Write(GPIOx, pin[0], 1);
			GPIO_Write(GPIOx, pin[1], 0);
			GPIO_Write(GPIOx, pin[2], 0);
			GPIO_Write(GPIOx, pin[3], 1);
			break;

		default:
			if (val == 10){
				ctr = 0;
				GPIO_Write(GPIOx, pin[0], 0);
				GPIO_Write(GPIOx, pin[1], 0);
				GPIO_Write(GPIOx, pin[2], 0);
				GPIO_Write(GPIOx, pin[3], 0);
			}else{
				ctr = 9;
				GPIO_Write(GPIOx, pin[0], 1);
				GPIO_Write(GPIOx, pin[1], 0);
				GPIO_Write(GPIOx, pin[2], 0);
				GPIO_Write(GPIOx, pin[3], 1);
			}

			break;
	}
}

