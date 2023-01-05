/*
 * I2C.h
 *
 * Created: 1/5/2023 10:34:57 PM
 *  Author: Kareem
 */ 


#ifndef I2C_H_
#define I2C_H_
#include "I2C_HW.h"

void TWI_MasterInit(char Address);
void TWI_SlaveInit(unsigned char Address);

TWI_RetErr TWI_sendStartCondition(void);
TWI_RetErr TWI_sendRepeatedStartCondition(void);
TWI_RetErr TWI_sendStopCondition(void);
TWI_RetErr TWI_sendSlaveAddressWrite(char Address);
TWI_RetErr TWI_sendSlaveAddressRead(char Address);
TWI_RetErr TWI_MasterWriteData(unsigned char Data);
TWI_RetErr TWI_MasterReadData(unsigned char* Data);




#endif /* I2C_H_ */