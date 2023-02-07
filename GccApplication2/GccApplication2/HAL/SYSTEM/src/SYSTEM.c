/*
 * SYSTEM.c
 *
 * Created: 2/7/2023 1:45:02 AM
 *  Author: Kareem
 */

#include "SYSTEM.h"

char setting = 0;
char count = 0;
char settingCounter = 0;
char timer0Count = 0;
char timer0CountSSD = 0;
char ledStatus = 0;
char SSDMultiplex = 1;
char settemp = 60;

// system initialization for all modules
void SYSTEM_init()
{
	INIT_eeprom();
	INIT_buttons();
	INIT_SSD();
	INIT_Timer0();
	INIT_HeaterCooler();
	LM35_Init(ADC_Channel0);
};

void SYSTEM_timer()
{
	// multiplexing for dual panel SSD
	if (timer0CountSSD >= 1)
	{
		if (SSDMultiplex == 1)
		{
			SSDMultiplex = 0;
		}
		else
		{
			SSDMultiplex = 1;
		}
		timer0CountSSD = 0;
	}

	// used for tcs
	// counts for overflows at 100ms
	timer0Count++;

	// detect when to switch ssd panels
	// counts for overflows at ~30ms
	timer0CountSSD++;

	// used for ssd blinking
	// counts for overflows at 1s
	settingCounter++;

	if (settingCounter >= 30)
	{
		ledStatus = ~ledStatus;
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
		settingCounter = 0;
	}

	if (timer0Count >= 3)
	{
		timer0Count = 0;
		TCS_Handler();
	}
};

void SYSTEM_OFF()
{
	SSD_OFF();
	HEATER_OFF();
	LED_OFF();
	COOLER_OFF();
	setting = 0;
	count = 1;
}

void SYSTEM_loop()
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
