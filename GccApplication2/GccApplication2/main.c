/*
 * GccApplication2.c
 *
 * Created: 1/5/2023 10:27:39 PM
 * Author : Kareem
 */
//
#include <avr/io.h>
char setting = 0;
char settemp = 60;
char count = 0;
char settingCounter=0;
char timer0Count = 0;
char timer0CountSSD = 0;
char ledStatus=0;
char SSDMultiplex=1;
char iteration;
#include "EEPROM.h"
#include "buttons.h"
#include "ssd.h"
#include "LM35.h"
#include "I2C.h"
#include "ADC.h"
#include "TCS.h"
#include "Timer.h"
char on = 0; // variable to hold button state (0 or 1)


ISR(TIMER0_OVF_vect) // Timer0 ISR
{
	if (timer0CountSSD>=1)
	{
		if (SSDMultiplex==1)
		{
			SSDMultiplex=0;
		}
		else
		{
			SSDMultiplex=1;
		}
		timer0CountSSD=0;
	}
	
	timer0Count++;
	timer0CountSSD++;
	settingCounter++;
	
	
	if (settingCounter>=30)
	{
		ledStatus=~ledStatus;
		if (setting == 1)
		{
			SSD_OFF();

			if (count == 9)
			{
				setting = 0;
				count = 1;
			}
		}
		count++;
		settingCounter=0;
	}
	
	if (timer0Count >= 3)
	{
		timer0Count = 0;
		TCS_Handler();
		
	}
	
	
}

ISR(INT0_vect)
{
	on = ~on;

}

int main(void)
{

	INIT_eeprom();
	INIT_buttons();
	INIT_SSD();
	INIT_Timer0();
	INIT_HeaterCooler();
	LM35_Init(ADC_Channel0);
	while (1)
	{
		

		if (on)
		{
			UpdateSetTemp();

			if (!setting)
			{
				SSD_write(LM35_Read());
			}
			else
			{
				if (count % 2 == 0)
				{
					SSD_write(settemp);
				}
				else
				{
					SSD_OFF();
				}
			}
		}
		else
		{
			SSD_OFF();
			HEATER_OFF();
			LED_OFF();
			COOLER_OFF();
			setting = 0;
			count = 1;
		}
	}
}