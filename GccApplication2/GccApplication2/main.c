/*
 * GccApplication2.c
 *
 * Created: 1/5/2023 10:27:39 PM
 * Author : Kareem
 */
//
#include <avr/io.h>
#include <avr/interrupt.h>
char setting=0;
char settemp=60;
char count=0;
char iteration;
#include "buttons.h"
#include "ssd.h"
#include "LM35.h"
#include "I2C.h"
#include "ADC.h"
#include "TCS.h"
#include "Timer.h"
char on = 0;  // variable to hold button state (0 or 1)

ISR(INT0_vect)
{
	on=~on;		
	_delay_ms(50);  	/* Software debouncing control delay */
	
}

int main(void) {
	
	eeprom_write_byte ((int*)0x55,settemp);
	INIT_buttons();
	INIT_SSD();
	sei();
	LM35_Init(ADC_Channel0);
	while (1)
	 {	
		
		if (on)
		{
			
			UpdateSetTemp();
			
			if(!setting)
			{
				SSD_write(LM35_Read());
			}
			else
			{
					SSD_OFF();
					_delay_ms(200);
					SSD_write(settemp);
				
					
					
					if (count==25)
					{
						setting=0;
					}
					
					
					if ((count==0)&&(setting==1))
					{
						iteration++;
					}
					count++;
			}
			
			
			
		}
		else
		{
			SSD_OFF();
			setting=0;
			count=0;
		}
		
		
		
		
		
	}
}