/*
 * GccApplication2.c
 *
 * Created: 1/5/2023 10:27:39 PM
 * Author : Kareem
 */
//
#include <avr/io.h>
#include <avr/interrupt.h>
#include "LM35.h"
#include "I2C.h"
#include "ADC.h"
#include "TCS.h"
#include "Clock.h"
#include "Timer.h"
#include "ssd.h"
char on = 0;  // variable to hold button state (0 or 1)
char count=0;
char setting=0;

ISR(INT0_vect)
{
	on=~on;		
	_delay_ms(50);  	/* Software debouncing control delay */
	
}

int main(void) {
	// Configure button as input
	DDRD=0;  // set PD2 as input
	PORTD=0xff;  // enable pull-up resistor on PD2
	DDRB=0xff;
	PORTB=0;
	GICR = 1<<INT0;		/* Enable INT0*/
	MCUCR = 1<<ISC01 | 1<<ISC00;  /* Trigger INT0 on rising edge */
	
	sei();
	char settemp;
	LM35_Init(ADC_Channel0);
	while (1) {	
		if ((!GetBit(PIND,0))||(!GetBit(PIND,1)))
		{
			setting=1;
			count=0;
		}
		if (on)
		{
			if(!setting)
			{
				SSD_write(LM35_Read());
			}
			else
			{
				
				SSD_OFF();
				_delay_ms(1000);
				SSD_write(EEPROM_ReadByte(settemp,0x00));
				
				
				
				if (count==5)
				{
					setting=0;
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