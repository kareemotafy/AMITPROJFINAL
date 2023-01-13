/*
 * buttons.c
 *
 * Created: 1/13/2023 5:03:25 AM
 *  Author: omar
 */ 

#include "buttons.h"

char setting;
char settemp;
char count;
char iteration;



void INIT_buttons()
{
		SetBit(OnOffPort,OnOffPin);  
		ClearBit(OnOffDDR,OnOffPin);
		SetBit(upPort,upPin); 
		ClearBit(upDDR,upPin);
		SetBit(downPort,downPin);  
		ClearBit(downDDR,downPin);
		GICR = 1<<INT0;		/* Enable INT0*/
		MCUCR = 1<<ISC01 | 1<<ISC00;  /* Trigger INT0 on rising edge */
		sei();
}

void UpdateSetTemp()
{
	
	if ((!GetBit(PIND,0))||(!GetBit(PIND,1)))
	{
		if ((setting==1)&&(!GetBit(PIND,0))&&(count>0))
		{
			if (!(settemp>=maxTemp))
			{
				settemp+=5;
			}
			while (!GetBit(PIND,0))
			{
				SSD_write(settemp);
			}
			
			
		}
		if ((setting==1)&&(!GetBit(PIND,1))&&(settemp>miniTemp)&&(count>0))
		{
			if (!(settemp<=miniTemp))
			{
				settemp-=5;
			}
			while (!GetBit(PIND,1))
			{
				SSD_write(settemp);
			}
		}
		eeprom_write_byte((int*) 0x55,settemp);
		setting=1;
		count=0;
		settemp=eeprom_read_byte((int*)0x55);
		
	}
}
