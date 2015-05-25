/*
 * KEYPAD.h
 *
 * Created: 2/13/2014 12:12:46 PM
 *  Author: mohamed fawzy
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#define kpad_pin        PIND
#define kpad_port       PORTD
#define kpad_port_dir   DDRD
#include <avr/io.h>

void keypad_init(void);
unsigned char scan_keypad(void);
unsigned char key_pressed(void);




#endif /* KEYPAD_H_ */
