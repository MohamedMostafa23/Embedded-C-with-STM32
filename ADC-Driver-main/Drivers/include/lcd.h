#ifndef INCLUDE_LCD_H_
#define INCLUDE_LCD_H_

void lcd_sendCommand(unsigned char cmd);
void LCD_DISP_CHAR(unsigned char data);
void LCD_INIT(void);
void LCD_GOTOXY(unsigned char x , unsigned char y );
void lcd_clrScreen(void);
void LCD_DISPLAYSTR(char * ptr);
void lcd_disp_string_xy(char * ptr , int y , int x);

#endif /* INCLUDE_LCD_H_ */
