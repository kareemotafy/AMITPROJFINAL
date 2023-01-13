/*
 * EEPROM.c
 *
 * Created: 1/5/2023 10:31:12 PM
 *  Author: Kareem
 */
#include "I2C.h"
#include "EEPROM.h"

EEPROM_RetType EEPROM_writeByte(char Data, unsigned short int word)
{
	EEPROM_RetType EERet_local = noError;
	Uint8 address = 0b01010000 | ((Uint8)word >> 8);
	/*Send Start condition*/
	TWI_sendStartCondition();
	/*Send Device address with Write and sequence*/
	TWI_sendSlaveAddressWrite(address);
	/*Send the rest of the word address*/
	TWI_MasterWriteData((Uint8)word);
	/*Write Data Byte*/
	TWI_MasterWriteData(Data);
	/*Delay 5 ms to write*/
	_delay_ms(5);
	/*Send Stop condition*/
	TWI_sendStopCondition();
	return EERet_local;
}

EEPROM_RetType EEPROM_ReadByte(char *Data, unsigned short int word)
{

	Uint8 address = 0b01010000 | ((Uint8)word >> 8);
	/*Send Start condition*/
	TWI_sendStartCondition();
	/*Send Device address with Write and sequence*/
	TWI_sendSlaveAddressWrite(address);
	/*Send the rest of the word address*/
	TWI_MasterWriteData((Uint8)word);
	/*Send repeated start condition*/
	TWI_sendRepeatedStartCondition();
	/*Send Device Address with read*/
	TWI_sendSlaveAddressRead(address);
	/*calling the master read function*/
	TWI_MasterReadData(Data);
	/*send stop condition*/
	TWI_sendStopCondition();
	
}