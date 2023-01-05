/*
 * EEPROM.h
 *
 * Created: 1/5/2023 10:30:38 PM
 *  Author: Kareem
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include "I2C.h"
typedef unsigned char Uint8;
typedef enum{
	EE_noError,
	EE_error
}EEPROM_RetType;
EEPROM_RetType EEPROM_writeByte(char Data,unsigned short int word);
EEPROM_RetType EEPROM_ReadByte(char *Data,unsigned short int word);





#endif /* EEPROM_H_ */