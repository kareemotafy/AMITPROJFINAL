/*
 * buttons.h
 *
 * Created: 1/13/2023 5:00:13 AM
 *  Author: omar
 */ 


#ifndef BUTTONS_H_
#define BUTTONS_H_
#define upPort PORTD
#define downPort PORTD
#define OnOffPort PORTD
#define upPin 0
#define downPin 1
#define OnOffPin 2
#define upDDR DDRD
#define downDDR DDRD
#define OnOffDDR DDRD
#define miniTemp 35
#define maxTemp 75
#include <avr/io.h>
#include <avr/eeprom.h>
#include "BitMath.h"
#include <avr/interrupt.h>
extern char setting;
extern char settemp;
extern char count;
extern char iteration;
void INIT_buttons();
void UpdateSetTemp();	



#endif /* BUTTONS_H_ */