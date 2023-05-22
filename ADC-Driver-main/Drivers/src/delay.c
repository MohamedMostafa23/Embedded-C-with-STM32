#include"delay.h"

void DELAY_INIT()
{
	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock/1000000);
}
void delay_us(uint32_t us_value)
{
	time_us = us_value;
	while(time_us);

}

void DELAY_ms(uint32_t ms_value)
{
	time_ms = ms_value;
	while(time_ms--)
		delay_us(1000);

}


SysTick_Handler()
{
	if(time_us)
	{
		time_us--;
	}
}
