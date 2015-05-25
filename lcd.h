/*
 * LCD.h
 * Created: 12/10/2013 2:52:02 AM
 *  Author: mohamed fawzy
 */ 

#ifndef LCD_H_
#define LCD_H_

#include <avr/io.h>
#define RS					     PINC0
#define RW						 PINC1
#define EN						 PINC2
#define LCD_PORT				 PORTC
#define DDR_LCD_PORT			 DDRC
#define _lcd_clear				 0x01
#define _lcd_cursor_off			 0x0C
#define _lcd_underline_cursor	 0x0E
#define _shift_cursor_left       0x10
#define _shift_cursor_right      0x14

/*********************************************************
this function send some data to LCD
auther:mohamed fawzy
tester:mohamed fawzy
@input:char to be sent
@output:void
**********************************************************/
void lcd_write(unsigned char data);

/*********************************************************
this function send command to be executed on LCD
auther:mohamed fawzy
tester:mohamed fawzy
@input:char represent command
@output:void
**********************************************************/
void lcd_cmd(unsigned char cmd);

/*********************************************************
this function send data to be displayed on LCD
auther:mohamed fawzy
tester:mohamed fawzy
@input:char represent command
@output:void
**********************************************************/
void lcd_data(unsigned char data);

/*********************************************************
this function send string to be displayed on LCD
auther:mohamed fawzy
tester:mohamed fawzy
@input:string to be displayed
@output:void
**********************************************************/
void lcd_puts(char *str);

/*********************************************************
this function used to locate cursor
auther:mohamed fawzy
tester:mohamed fawzy
@input:row number, column number
@output:void
**********************************************************/
void lcd_goto_row_column(unsigned char row,unsigned char column);

/*********************************************************
this function used to initialze LCD controller
auther:mohamed fawzy
tester:mohamed fawzy
@input:row number, column number
@output:void
**********************************************************/
void lcd_init();


#endif /* LCD_H_ */
