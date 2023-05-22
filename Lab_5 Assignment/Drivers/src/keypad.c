#include <stdint.h>
#include "stm32f4xx.h"
#include "gpio.h"
#include "keypad.h"

const int no_raws = 4;
const int no_cols = 3;
char rows[4]={12,13,14,15}; //fill the array
char cols[3]={8,9,10}; //fill the array

char lookupTable[4][3]={{1,2,3},{4,5,6},{7,8,9},{'*',0,'#'}};// fill the array

char currentvalue;

void KeyPad_INIT()
{
	// set input and ouput pins
		for (int i =0;i<4;i++){
			// get pins from row and set it as input and pull down
			GPIO_Init(GPIOB,rows[i],0,1);
			GPIO_PUPDR(GPIOB,rows[i],0);
			// setting 7 segment pins as output
			GPIO_Init(GPIOB,i,1,1);
		}
		// get pins from cols and set it as output
		for(int i = 0;i<3;i++){
			GPIO_Init(GPIOB,cols[i],1,1);
		}
}

void KeyPad_MANAGE()
{
	//nested for loop to check which button is pressed
	for (int i = 0;i<no_cols;i++){
		GPIO_Write(GPIOB,cols[i],1);

		for (int j = 0;j<no_raws;j++){
			if (GPIO_Read(GPIOB,rows[j])){

				//if pressed wait until released then change the value
				while(GPIO_Read(GPIOB,rows[j]));

				if (lookupTable[j][i]<=9 && lookupTable[j][i]>=0){
					currentvalue = lookupTable[j][i];

					//call KeypadCallouts_KeyPressNotificaton
					KeypadCallouts_KeyPressNotificaton();
				}
			}
		}
		GPIO_Write(GPIOB,cols[i],0);
	}
}

char KeyPad_GET_VALUE()
{
	return currentvalue;
}

void KeypadCallouts_KeyPressNotificaton(void)
{
	// set seven segment
	int sevenSegmentValue = KeyPad_GET_VALUE();
    GPIO_Write(GPIOB,0,(sevenSegmentValue)&(1<<0));
    GPIO_Write(GPIOB,1,(sevenSegmentValue)&(1<<1));
    GPIO_Write(GPIOB,2,(sevenSegmentValue)&(1<<2));
    GPIO_Write(GPIOB,3,(sevenSegmentValue)&(1<<3));
}
