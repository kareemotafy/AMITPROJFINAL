/*
 * EEPROM.c
 *
 * Created: 1/5/2023 10:31:12 PM
 *  Author: Kareem
 */
#include "EEPROM.h"
extern char settemp;
void INIT_eeprom()
{
	if (eeprom_read_byte((int*)0x55)!=0xff)
	{
		settemp=eeprom_read_byte((int*)0x55);
	}
	else
	{
		eeprom_write_byte((int*)0x55, settemp);	
	}
	
		
	
}