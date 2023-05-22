#include "stm32f4xx.h"
#include "gpio.h"

void GPIO_Init (GPIO_TypeDef * GPIOx,char pin,char dir,char enable_pin)
{
	//Enable clock to GBIOx
	RCC->AHB1ENR |= (1u<<enable_pin);

	if(dir == 1)
	{


		GPIOx->MODER |= (1u<<(2*pin));
		GPIOx->MODER &=~(1u<<(2*pin+1));
	}
	else if(dir == 0)
	{
		GPIOx->MODER &=~(1u<<(2*pin));
		GPIOx->MODER &=~(1u<<(2*pin+1));
//		pull up
		GPIOx->PUPDR |= (1u<<(2*pin));
		GPIOx->PUPDR &=~(1u<<(2*pin+1));
	}
	else
		{
			GPIOx->MODER |= (1u<<(2*pin));
			GPIOx->MODER |= (1u<<(2*pin+1));
			GPIOx->PUPDR &=~(1u<<(2*pin));
			GPIOx->PUPDR &=~(1u<<(2*pin+1));
		}

}

char GPIO_Write(GPIO_TypeDef * GPIOx,char pin,char state)
{
	if (GPIOx->MODER & (1u<<(2*pin)))
	{
		if(state)
			{
				GPIOx->ODR |=(1u<<pin);
			}
			else
			{
				GPIOx->ODR &=~(1u<<pin);
			}
		return 0;
	}
	else
	{
		return 1;
	}
}
char GPIO_Read(GPIO_TypeDef * GPIOx,char pin)
{
	if (((GPIOx->MODER & (1u<<(2*pin))) || (GPIOx->MODER & (1u<<(2*pin+1)))) == 0)
	{
		if(GPIOx->IDR & 1u<<pin){
			return 1;
		}else{
			return 0;
		}
	}
	else
	{
		return (GPIOx->ODR && 1u<<pin); //read output
	}
}


