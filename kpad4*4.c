/*
 * KEYPAD.c
 *
 * Created: 2/13/2014 12:15:28 PM
 *  Author: mohamed fawzy
 */ 
#define F_CPU 11059200UL
#include <util/delay.h>
#include "KEYPAD.h"
void keypad_init(void)
{
	kpad_port_dir=0xf0;
	kpad_pin=0xF0;
	kpad_port=0x0F;
}
unsigned char scan_keypad(void)
{
	unsigned char result;
	kpad_port=0x0F;
	kpad_port|=(1<<4)| (1<<5)| (1<<6);
	__builtin_avr_delay_cycles(1);
	result=kpad_pin &0x0F;
	if(result != 0x0F)
	{
		result|=0x70;
		return result;
	}
	else
	{
		kpad_port=0x0F;
		kpad_port|=(1<<4)| (1<<5)| (1<<7);
		__builtin_avr_delay_cycles(1);
		result=kpad_pin &0x0F;
		if(result != 0x0F)
		{
			result|=0xB0;
			return result;
		}
		else
		{
			kpad_port=0x0F;
			kpad_port|=(1<<4)| (1<<6)| (1<<7);
			__builtin_avr_delay_cycles(1);
			result=kpad_pin &0x0F;
			if(result != 0x0F)
			{
				result|=0xD0;
				return result;
			}
			else
			{
				kpad_port=0x0F;
				kpad_port|=(1<<5)| (1<<6)| (1<<7);
				__builtin_avr_delay_cycles(1);
				result=kpad_pin &0x0F;
				if(result != 0x0F)
				{
					result|=0xE0;
					return result;
				}
				else return 0xff;
			}
		}
	}
}
unsigned char key_pressed(void)
{
	unsigned char kp=0;
	switch(scan_keypad())
	{
		//7   0111
		//b   1011
		//d   1101
		//e   1110
		case 0x77:
		kp=1;
		break;
		case 0x7B:
		kp=2;
		break;
		case 0x7D:
		kp=3;
		break;
		case 0x7E:
		kp=4;
		break;
		case 0xB7:
		kp=5;
		break;
		case 0xBB:
		kp=6;
		break;
		case 0xBD:
		kp=7;
		break;
		case 0xBE:
		kp=8;
		break;
		case 0xD7:
		kp=9;
		break;
		case 0xDB:
		kp=10;
		break;
		case 0xDD:
		kp=11;
		break;
		case 0xDE:
		kp=12;
		break;
		case 0xE7:
		kp=13;
		break;
		case 0xEB:
		kp=14;
		break;
		case 0xED:
		kp=15;
		break;
		case 0xEE:
		kp=16;
		break;
		case 0xFF:
		kp=0;
		break;
	}
	return kp;
}
