#ifndef INCLUDE_ADC_H_
#define INCLUDE_ADC_H_
#include"stm32f4xx.h"
#define USE_POLLING 0

typedef enum {
	twelve = 0x03000000,
	ten = 0x02000000,
	eight = 0x01000000,
	six = 0x00000000
}resolution;

typedef enum {
	single = ~(0x00000002),
	continous = 0x00000002
}conv_mode;


typedef struct{
	resolution res_val;
	conv_mode mode;
}ADCConfigType;


void ADC_Init(ADCConfigType* );
void ADC_StartConv(unsigned char ChannelNum);
char ADC_GetConversionState(unsigned char* ConversionStatePtr);
unsigned char ADC_ReadData(unsigned short int* DataPtr);
void ISR_OF_IQR(void);
#endif /* INCLUDE_ADC_H_ */
