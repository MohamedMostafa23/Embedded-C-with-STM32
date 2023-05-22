#include<stdint.h>
#include<stdlib.h>
#include<stdio.h>
#include "stm32f4xx.h"
#include "gpio.h"
#include "lcd.h"
#include "adc.h"
#include "delay.h"
unsigned short int Data;
unsigned char conv;
int main(void)
{
	//Initialization of LCD and delay function
	DELAY_INIT();
	LCD_INIT();
	DELAY_ms(70);

	//Creating an instance of ADC configuration structure
	ADCConfigType parameter;
	parameter.res_val = twelve; // Choose resolution
	parameter.mode = continous; // Choose mode
	ADC_Init(&parameter);

	//	if you are using the single mode and want continuous reading call ADC_STARTCONVERISION
	ADC_StartConv(0);

	char STR_TEMP[50]; // Will store the STR_TEMPerature as string to display
	LCD_DISPLAYSTR("TEMP:"); // Will be constantly displayed
	DELAY_ms(10);

	// super loop
	while(1)
	{
		// Polling enabled
		if(USE_POLLING == 1){
			if(ADC_GetConversionState(&conv)){

//			ADC_StartConv(0); Enable if need continuous mode using single
			ADC_ReadData(&Data);
			snprintf(STR_TEMP, 7, "%d", Data);

			LCD_GOTOXY(1,0);
			LCD_DISPLAYSTR(STR_TEMP);
			// When the temperature is updated from two digits to one, the tens are removed
			LCD_DISPLAYSTR("    ");

			}

		}else{
			// Polling equal 0 interrupt mode
			ADC_StartConv(0);
			int temperature = (int)((ADC1->DR/(4095.0f))*(100*3.3));
			snprintf(STR_TEMP, 7, "%d", temperature);

			// Setting the cursor at row 1 and col 0
			LCD_GOTOXY(1,0);
			LCD_DISPLAYSTR(STR_TEMP);
			LCD_DISP_CHAR('\0');
		}
	}

}

// Interrupt ISR for ADC
void ADC_IRQHandler(void){
	Data = ADC1->DR;
}
