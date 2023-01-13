/*
 * TCS.c
 *
 * Created: 1/5/2023 11:04:25 PM
 *  Author: Kareem
 */ 

#include <avr/io.h>
#include "BitMath.h"
#include "LM35.h"
#include "EEPROM.h"

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

short temp_reading_counter = 0;
short temp_reading[10] = {};
char current_temp = 0;
char settemp;
void update_temp_reading(){
	if (temp_reading_counter < 10)
	{
		temp_reading[temp_reading_counter] = LM35_Read();
		temp_reading_counter++;
	}
	else
	{
		temp_reading_counter = 0;
	}

	for (int i = 0; i < 10; i++)
	{
		current_temp += temp_reading[i];
	}
	current_temp /= 10;
	//EEPROM_writeByte(current_temp,0xC7);
}