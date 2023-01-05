/*
 * TCS.c
 *
 * Created: 1/5/2023 11:04:25 PM
 *  Author: Kareem
 */ 

#include <avr/io.h>


void COOLER_ON()
{
	SetBit(PORTD, 6);
}

void COOLER_OFF()
{
	ClearBit(PORTD, 6);
}
void HEATER_ON()
{
	SetBit(PORTD, 7);
}
void HEATER_OFF()
{
	ClearBit(PORTD, 7);
}