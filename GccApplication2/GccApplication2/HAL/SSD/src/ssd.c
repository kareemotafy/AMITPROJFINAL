/*
 * ssd.c
 *
 * Created: 1/13/2023 1:36:51 AM
 *  Author: omar
 */ 

#include "ssd.h"
char number[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
char units;
char tens;

	void SSD_OFF()
	{
		SSD_port=0x7f;
	}
	
	void INIT_SSD()
	{
		DDRB=0xff;
		PORTB=0;
	}
	
	void SSD_write(char num)
	{
			units=num%10;
			tens=num/10;
			
			SSD_port=number[units];
			_delay_ms(MultiplexDelay);
			ClearBit(Display1Port,Display1Pin);
			SetBit(Display2Port,Display2Pin);
			
			
			SSD_port=number[tens];
			_delay_ms(MultiplexDelay);	
			SetBit(Display1Port,Display1Pin);
			ClearBit(Display2Port,Display2Pin);	
	}
	
	