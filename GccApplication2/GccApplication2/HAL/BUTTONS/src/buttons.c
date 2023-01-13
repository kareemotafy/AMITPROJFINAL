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
		if (((setting==1)&&(!GetBit(PIND,0))&&(settemp<maxTemp)&&!(count==1))||((setting==1)&&(!GetBit(PIND,0))&&(settemp<maxTemp)&&(iteration>=5)))
		{
			settemp+=5;
			eeprom_write_byte((int*) 0x55,settemp);
			iteration=0;

			
		}
		if (((setting==1)&&(!GetBit(PIND,1))&&(settemp>miniTemp)&&!(count==1))||((setting==1)&&(!GetBit(PIND,1))&&(settemp>miniTemp)&&(iteration>=5)))
		{
			settemp-=5;
			eeprom_write_byte((int*) 0x55,settemp);
			iteration=0;
		}
		setting=1;
		count=0;
		settemp=eeprom_read_byte((int*)0x55);
		
	}
}
