#include <stdint.h>
#include "stm32f4xx.h"
#include "gpio.h"


int main(void)
{
    int outputColorsControl = 0, outputColorsControl_shifted_5bits;

	//Set Mode to output of pins 5,6,7 GPIOB and enable clock to GBIOB
    GPIO_Init(GPIOB,5,1,1);
    GPIO_Init(GPIOB,6,1,1);
    GPIO_Init(GPIOB,7,1,1);

    //Set Mode to input of pin 3 GPIOB
    GPIO_Init(GPIOB,3,0,1);

    //Set input Mode to (pull-up mode)  of pin 3 GPIOB
    GPIO_PUPDR(GPIOB,3,1);

	// super loop
	while(1)
	{
	    if(!(GPIO_Read(GPIOB,3))){
	    	outputColorsControl=outputColorsControl+1;

		    if(outputColorsControl == 8){
		    	outputColorsControl = 0;
			}

		    outputColorsControl_shifted_5bits =(outputColorsControl<<5);

		    GPIO_Write(GPIOB,5,(outputColorsControl_shifted_5bits)&(1<<5));
		    GPIO_Write(GPIOB,6,(outputColorsControl_shifted_5bits)&(1<<6));
		    GPIO_Write(GPIOB,7,(outputColorsControl_shifted_5bits)&(1<<7));

		    while(!(GPIO_Read(GPIOB,3)));

	    }

	}

}
