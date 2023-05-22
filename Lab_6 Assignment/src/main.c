#include "stm32f4xx.h"
#include "gpio.h"
#include "interrupt.h"

void ISR_OF_EXTI(void);
int seven_segment_current_number = 0;

int main(void)
{
	// set pin 0,1,2,3 port A as output and enable clock of GPIOA
	GPIO_Init(GPIOA,0,1,0);
	GPIO_Init(GPIOA,1,1,0);
	GPIO_Init(GPIOA,2,1,0);
	GPIO_Init(GPIOA,3,1,0);

	//Set pin 0,1 port B as input and enable clock of GPIOB
    GPIO_Init(GPIOB,0,0,1);
    GPIO_Init(GPIOB,1,0,1);

	////Set pin 0 port B into pull up mode
    GPIO_PUPDR(GPIOB,0,1);

	////Set pin 1 port B into pull up mode
    GPIO_PUPDR(GPIOB,1,1);

    //INIT EXTI0
    interrupt_bit_INIT(GPIOB,0,0);

    //INIT EXTI1
    interrupt_bit_INIT(GPIOB,0,1);

	while(1);
}

void ISR_OF_EXTI(void)
{
    GPIO_Write(GPIOA,0,(seven_segment_current_number)&(1<<0));
    GPIO_Write(GPIOA,1,(seven_segment_current_number)&(1<<1));
    GPIO_Write(GPIOA,2,(seven_segment_current_number)&(1<<2));
    GPIO_Write(GPIOA,3,(seven_segment_current_number)&(1<<3));
}

void EXTI0_IRQHandler(void){
	(seven_segment_current_number >= 9) ? 9:seven_segment_current_number++;

	//disable then enable the other interrupt to solve the racing problem
	NVIC->ICER[0] |= (1u<<7);
	ISR_OF_EXTI();
	NVIC->ISER[0] |= (1u<<7);
}

void EXTI1_IRQHandler(void){
	(seven_segment_current_number <= 0) ? 0:seven_segment_current_number--;

	//disable then enable the other interrupt to solve the racing problem
	NVIC->ICER[0] |= (1u<<6);
	ISR_OF_EXTI();
	NVIC->ISER[0] |= (1u<<6);
}
