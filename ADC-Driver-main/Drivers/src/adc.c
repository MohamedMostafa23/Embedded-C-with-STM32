#include "stm32f4xx.h"
#include "gpio.h"
#include "adc.h"
#include "lcd.h"
extern unsigned char conv;
void ADC_Init(ADCConfigType* ConfigParamPtr){

//	clk
	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
//	setting resolution
	ADC1->CR1 &= ~(ConfigParamPtr->res_val);
//  Setting alignment to right
	ADC1->CR2 &= ~ADC_CR2_ALIGN;


	if(USE_POLLING == 1){
		  ADC1->CR1 &=~ ADC_CR1_EOCIE; // Disable interrupt
	  }
	  else{
		  ConfigParamPtr->mode = single;
		  // Enable IRQ from nested vector table
		  NVIC->ISER[0]|=(1u<<(18));
		  // Enable interrupt at end of conversion
		  ADC1->CR1 |= ADC_CR1_EOCIE;
	  }


	if (ConfigParamPtr->mode == continous){
		// Set ADC in continuous mode
		ADC1->CR2 |= ConfigParamPtr->mode;
	}else{
		// Single mode
		ADC1->CR2 &= ConfigParamPtr->mode;
	}


	// ADC enable
	ADC1->CR2 |= ADC_CR2_ADON;

}

void ADC_StartConv(unsigned char ChannelNum){
	// Setting pin to analog mode to capture sensor reading
	GPIO_Init(GPIOA, ChannelNum, 3,0);
	// Start conversion of regular from analog to digital
	ADC1->CR2 |= ADC_CR2_SWSTART;
}

// This function is only available when interrupt is disable
#if(USE_POLLING == 1)
	char ADC_GetConversionState(unsigned char* ConversionStatePtr){
		// Check if the conversion is done
		if((ADC1->SR & ADC_SR_EOC) == ADC_SR_EOC){
			*ConversionStatePtr = (ADC1->SR & ADC_SR_EOC);
			return 1;
		}
		else{
			return 0;
		}
	}

#endif

unsigned char ADC_ReadData(unsigned short int* DataPtr){

	if(ADC_GetConversionState(&conv)){
		*DataPtr = (int)((ADC1->DR/(4095.0f))*(100*3.3));

		return 0;
	}else{
		return 1;
	}
}
