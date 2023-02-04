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

ISR(TIMER1_OVF_vect) // Timer1 ISR
{

	if (setting == 1)
	{
		PORTB = 0xff;

		if (count == 9)
		{
			setting = 0;
			count = 1;
		}
	}
	TCNT1 = 57723;
	count++;
}

ISR(TIMER0_OVF_vect) // Timer0 ISR
{
	TCS_Handler();
}

ISR(INT0_vect)
{
	on = ~on;
	_delay_ms(50); /* Software debouncing control delay */
}

int main(void)
{

	INIT_eeprom();
	INIT_buttons();
	INIT_SSD();
	INIT_Timer0();
	INIT_Timer1();
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
			}
		}
		else
		{
			SSD_OFF();
			HEATER_OFF();
			COOLER_OFF();
			setting = 0;
			count = 1;
		}
	}
}