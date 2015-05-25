/********************************************
 * LCD.c
 * Created: 12/10/2013 2:51:48 AM
 *  Author: mohamed fawzy
 *  Tester: mohamed fawzy
 ******************************************/ 
#define F_CPU 11059200UL
#include <util/delay.h>
#include "LCD.h"
/*Macro for executing enable pulse*/
#define Enable_Pulse()\
        {\
	      LCD_PORT|=(1<<EN);    /*set enable pin*/\
	      _delay_us(1);\
	      LCD_PORT&=~(1<<EN);   /*clear enable pin*/\
	     _delay_ms(5);\
       }\
	   
void lcd_write(unsigned char data)
{
	LCD_PORT=(LCD_PORT&0X0F)|(data&0xf0);
	Enable_Pulse();
	_delay_ms(5);
	LCD_PORT=(LCD_PORT&0X0F)|(data<<4);
	Enable_Pulse();
	_delay_ms(5);
}

void lcd_cmd(unsigned char cmd)
{
	LCD_PORT&=~(1<<RW);  //write mode
	LCD_PORT&=~(1<<RS);  //cmd mode
	lcd_write(cmd);
}


void lcd_data(unsigned char data)
{
	LCD_PORT&=~(1<<RW);  //write mode
	LCD_PORT|=(1<<RS);  //cmd mode
	lcd_write(data);
}

void lcd_puts(char *str)
{
	while(*str !='\0')
	{
		lcd_data(*str++);
	}
}

void lcd_goto_row_column(unsigned char row,unsigned char column)
   {
	column--;
	switch (row)
	   {
		case 1:
		      lcd_cmd(0x80+column);
		      break;
		case 2:
		      lcd_cmd(0xC0+column);
		      break;
		case 3:
		      lcd_cmd(0x94+column);
		      break;
		case 4:
		      lcd_cmd(0xD4+column);
		      break;
	   }
    }
	
void lcd_init()
{
	/*configure micro controller pins*/
	DDR_LCD_PORT=0xFF;
	LCD_PORT=0x00;
	LCD_PORT|=(1<<PINC3);
	MCUCSR = 0x80;
	MCUCSR = 0x80;

	/*initialize LCD*/
	_delay_ms(10);
	LCD_PORT&=~(1<<RW);  //write mode
	LCD_PORT&=~(1<<RS);  //cmd mode
	
	LCD_PORT|=(1<<PINC4);
	LCD_PORT|=(1<<PINC5);
	
	Enable_Pulse();
	Enable_Pulse();
	Enable_Pulse();
	
	LCD_PORT&=~(1<<PINC4); //clear enable pin
	Enable_Pulse();
	lcd_cmd(0x28);
	lcd_cmd(0x0F);    //display on cursor off
	lcd_cmd(0xF0);
	lcd_cmd(0x01);   //clear LCD
	lcd_cmd(0x06);  //increment cursor (shift cursor to right)
}
