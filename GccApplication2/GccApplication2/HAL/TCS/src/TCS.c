/*
 * TCS.c
 *
 * Created: 1/5/2023 11:04:25 PM
 *  Author: Kareem
 */

#include "TCS.h"

void INIT_HeaterCooler()
{
	SetBit(heaterDDR, heaterPin);
	SetBit(coolerDDR, coolerPin);
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
long int current_temp = 0;

void TCS_Actuator()
{
	char settemp = eeprom_read_byte((int *)0x55);
	int diff = settemp - current_temp;

	if (diff < -10)
	{
		COOLER_ON();
		HEATER_OFF();
	}
	else if (diff > 0)
	{
		HEATER_ON();
		COOLER_OFF();
	}
	else
	{
		HEATER_OFF();
		COOLER_OFF();
	}
}

void TCS_Handler()
{

	if (temp_reading_counter < 10)
	{
		temp_reading[temp_reading_counter] = LM35_Read();
		temp_reading_counter++;
	}
	else
	{
		temp_reading_counter = 0;
		for (int i = 0; i < 10; i++)
		{
			current_temp += temp_reading[i];
		}
		current_temp /= 10;
		TCS_Actuator();
	}
}
