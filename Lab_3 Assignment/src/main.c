#include<stdint.h>

// GPIOB address
#define GPIOB_BASE  (uint32_t)0x40020400

//Get Moder register address
#define MODER_OFFSET (uint32_t)0x00
#define MODER_ADD (*((uint32_t*)(GPIOB_BASE+MODER_OFFSET)))

//Get Output type register address
#define OYTPUTTYPE_OFFSET (uint32_t)0x04
#define OYTPUTTYPE_ADD (*((uint32_t*)(GPIOB_BASE+OYTPUTTYPE_OFFSET)))

//Get Input type register address
#define INPUTTYPE_OFFSET (uint32_t)0x0C
#define INPUTTYPE_ADD (*((uint32_t*)(GPIOB_BASE+INPUTTYPE_OFFSET)))

//Get Output data register address
#define OUTDATA_OFFSET (uint32_t)0x14
#define OUTDATA_ADD (*((uint32_t*)(GPIOB_BASE+OUTDATA_OFFSET)))

//Get Input data register address
#define INPUT_OFFSET (uint32_t)0x10
#define INPUT_ADD (*((uint32_t*)(GPIOB_BASE+INPUT_OFFSET)))

//Rcc base address
#define	RCC_BASE 0x40023800

// Get AHB1EN Register address
#define AHB1ENR_OFFSET 0x30
#define AHB1ENR_ADD (*((uint32_t*)(RCC_BASE+AHB1ENR_OFFSET)))

int main(void)
{
    int outputColorsControl = 0, outputColorsControl_shifted_5bits;

	//Enable clock to GBIOB
	AHB1ENR_ADD |=(1<<1);

	// Set Mode to output of pins 5,6,7 GPIOB
	MODER_ADD |=(1<<10)|(1<<12)|(1<<14);
	MODER_ADD &=~((1<<11)|(1<<13)|(1<<15));

	//Set output Mode to (push-pull mode)  of pins 5,6,7 GPIOB
	OYTPUTTYPE_ADD &=~((1<<5)|(1<<6)|(1<<7));

    // Set Mode to input of pin 3 GPIOB
	MODER_ADD &=~((1<<6)|(1<<7));

    //Set input Mode to (pull-up mode)  of pin 3 GPIOB
	INPUTTYPE_ADD |=(1<<6);
    INPUTTYPE_ADD &=~(1<<7);

	// super loop
	while(1)
	{
	    if(!(INPUT_ADD & (1<<3))){
	    	outputColorsControl=outputColorsControl+1;

		    if(outputColorsControl == 8){
		    	outputColorsControl = 0;
			}

		    outputColorsControl_shifted_5bits =(outputColorsControl<<5);

		    OUTDATA_ADD = outputColorsControl_shifted_5bits;

		    while(!(INPUT_ADD & (1<<3)));

	    }

	}

}




