/*
 * eeprom.h
 *
 * Created: 6/29/2014 1:43:09 PM
 *  Author: mohamed fawzy
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_
#define F_CPU 8000000UL
#include <avr/io.h>


void EepromWrite(uint16_t address,uint8_t data);
uint8_t EeprimRead(uint16_t address);


#endif /* EEPROM_H_ */
