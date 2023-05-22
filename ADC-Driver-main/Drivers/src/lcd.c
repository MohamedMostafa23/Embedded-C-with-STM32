#include "lcd.h"
#include"stm32f4xx.h"
#include"gpio.h"
#include"delay.h"



/////////////////////////////////////////////////////////////////////
//	lcd enable triggering function to make lcd aware about command or
//   data changes.
////////////////////////////////////////////////////////////////////
void enableTrigger(void)
{
	DELAY_INIT();

	GPIO_Write(GPIOB,2,0);
//	CLR_BIT(PORTB,2);

	DELAY_ms(1);
	GPIO_Write(GPIOB,2,1);
//	SET_BIT(PORTB,2);
	DELAY_ms(6);


}
///////////////////////////////////////////////////////////////////////////////////////
// LCD initialization API : set portB from pinB.4 to pinB.7 as o/p for data and commands
//							 and pinB.0 to pinB.2 o/p for control pins
//////////////////////////////////////////////////////////////////////////////////////
void LCD_INIT(void)
{
	for(int i = 0;i<=7;i++){
	GPIO_Init(GPIOB,i,1,1);
	}
//	DDRB=0xff; // init port B as O/P port
	GPIOB->ODR=0x04; // activate LCD enable

	lcd_sendCommand(0x33); // 4-bit mode
	lcd_sendCommand (0x32);
	lcd_sendCommand (0x28);



	lcd_sendCommand(0x0c); // turn on lcd


}


void lcd_sendCommand(unsigned char cmd)
{

//	unsigned char high_nibble , low_nibble ;
//
//	HIGH_NIBBLE(high_nibble,cmd);
//	LOW_NIBBLE(low_nibble,cmd);

	GPIO_Write(GPIOB,0,0);
//	CLR_BIT(PORTB,0); // to enable command mode
//	CLR_BIT(PORTB,1); // write signal to lcd

	GPIOB->ODR &=0x0f;
	GPIOB->ODR |=(0xF0 & cmd);// to send high nibble command
	enableTrigger(); // triggre lcd enable

	GPIOB->ODR &=0x0f;
	GPIOB->ODR |=(cmd<<4); // to send low nibble command
	enableTrigger();

}

void LCD_DISP_CHAR (unsigned char data)
{

//	unsigned char high_nibble , low_nibble ;

	GPIO_Write(GPIOB,0,1);
	GPIO_Write(GPIOB,1,0);
//	SET_BIT(PORTB,0); //  enable data mode
//	CLR_BIT(PORTB,1); // activate lcd write

//	HIGH_NIBBLE(high_nibble,data); // get high nibble data
//	LOW_NIBBLE(low_nibble,data); // get low nibble data

	GPIOB->ODR &= 0x0f;
	GPIOB->ODR |=(0xF0 & data);// to send high nibble data
	enableTrigger(); // triggre lcd enable

	GPIOB->ODR &=0x0f;
	GPIOB->ODR |=(data<<4); // to send low nibble data
	enableTrigger();


}


void LCD_GOTOXY(unsigned char y , unsigned char x )
{
	unsigned char position = 0x80;



	if(!y)
	{
		position=position+x;
	}
	else
	{
		position=0xc0;
		position=position+x;

	}

	lcd_sendCommand(position);


}


void lcd_clrScreen(void)
{

	lcd_sendCommand(0x01);


}


void LCD_DISPLAYSTR(char * ptr)
{

	while(* ptr!= '\0')
	{
		LCD_DISP_CHAR(* ptr);
		ptr++;

	}



}

void lcd_disp_string_xy(char * ptr , int y , int x)
{

	lcd_gotoxy(y,x);
	lcd_dispString(ptr);




}




