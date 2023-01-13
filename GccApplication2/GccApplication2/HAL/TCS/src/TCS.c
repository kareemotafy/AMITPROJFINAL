/*
 * TCS.c
 *
 * Created: 1/5/2023 11:04:25 PM
 *  Author: Kareem
 */ 

#include "TCS.h"

void INIT_HeaterCooler()
{
	SetBit(heaterDDR,heaterPin);
	SetBit(coolerDDR,coolerPin);
	
}

void COOLER_ON()
{
	SetBit(coolerPort, coolerPin);
}

void COOLER_OFF()
{
	ClearBit(coolerPort, coolerPin);
}
void HEATER_ON()
{
	SetBit(heaterPort, heaterPin);
}
void HEATER_OFF()
{
	ClearBit(heaterPort, heaterPin);
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