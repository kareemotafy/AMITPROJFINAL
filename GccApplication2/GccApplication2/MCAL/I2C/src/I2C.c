/*
 * I2C.c
 *
 * Created: 1/5/2023 10:39:26 PM
 *  Author: Kareem
 */ 
#include <avr/io.h>
#include "I2C.h"

void TWI_MasterInit(char Address){
	/*setting the Frequency pre-scalar*/
	TWBR_REG = 2; // Frequency 8 MHZ
	// TWBR_REG = 12 // Frequency 16 MHZ
	/*Clearing the TWPS bits in TWSR*/
	ClearBit(TWSR_REG,TWPS0_BIT);
	ClearBit(TWSR_REG,TWPS1_BIT);
	/*Enabling the TWI*/
	SetBit(TWCR_REG,TWEA_BIT);
	SetBit(TWCR_REG,TWE_BIT);
	if(Address != 0x00){
		// Do nothing
		
		}else{
		
		TWAR_REG = Address<<7;
	}
}
void TWI_SlaveInit(unsigned char Address){
	/*Set slave Address*/
	TWAR_REG = Address<<1;
	/*Enabling the TWI*/
	SetBit(TWCR_REG,TWEA_BIT);
	SetBit(TWCR_REG,TWE_BIT);
}

TWI_RetErr TWI_sendStartCondition(void){
	TWI_RetErr RetVar = noError ;
	SetBit(TWCR_REG,TWSTA_BIT);
	/*clearing the TWINT FLAG*/
	SetBit(TWCR_REG,TWINT_BIT);
	while(GetBit(TWCR_REG,TWINT_BIT)==0);
	
	if(TWSR_REG & 0xf8 != 0x08){
		RetVar = startConditionErr;
		}else{
		// Do Nothing
	}
	return RetVar;
}
TWI_RetErr TWI_sendRepeatedStartCondition(void){
	TWI_RetErr RetVar = noError ;
	SetBit(TWCR_REG,TWSTA_BIT);
	/*clearing the TWINT FLAG*/
	SetBit(TWCR_REG,TWINT_BIT);
	while(GetBit(TWCR_REG,TWINT_BIT)==0);
	if(TWSR_REG & 0xf8 != 0x10){
		RetVar = repeatStartCondErr;
		}else{
		// Do Nothing
	}
	return RetVar;
	
}
TWI_RetErr TWI_sendStopCondition(void){
	TWI_RetErr RetVar = noError ;
	SetBit(TWCR_REG,TWSTO_BIT);
	/*clearing the TWINT FLAG*/
	SetBit(TWCR_REG,TWINT_BIT);
	while(GetBit(TWCR_REG,TWINT_BIT)==0);
	return RetVar;
}
TWI_RetErr TWI_sendSlaveAddressWrite(char Address){
	TWI_RetErr RetVar = noError ;
	TWDR_REG = Address<<1;
	ClearBit(TWDR_REG,0);
	ClearBit(TWCR_REG,TWSTA_BIT);
	/*clearing the TWINT FLAG*/
	SetBit(TWCR_REG,TWINT_BIT);
	while(GetBit(TWCR_REG,TWINT_BIT)==0);
	if(TWSR_REG & 0xf8 != 0x18){
		RetVar = slaveAddressWriteErr;
		}else{
		// Do Nothing
	}
	return RetVar;
}
TWI_RetErr TWI_sendSlaveAddressRead(char Address){
	TWI_RetErr RetVar = noError ;
	TWDR_REG = Address<<1;
	SetBit(TWDR_REG,0);
	/*Clearing the Start Bit*/
	ClearBit(TWCR_REG,TWSTA_BIT);
	/*clearing the TWINT FLAG*/
	SetBit(TWCR_REG,TWINT_BIT);
	/*waiting for the process to finish*/
	while(GetBit(TWCR_REG,TWINT_BIT)==0);
	if(TWSR_REG & 0xf8 != 0x40){
		RetVar = slaveAddressReadErr;
		}else{
		// Do Nothing
	}
	return RetVar;
}
TWI_RetErr TWI_MasterWriteData(unsigned char Data){
	TWI_RetErr RetVar = noError;
	TWDR_REG = Data;
	/*clearing the TWINT FLAG*/
	SetBit(TWCR_REG,TWINT_BIT);
	/*waiting for the process to finish*/
	while(GetBit(TWCR_REG,TWINT_BIT)==0);
	if(TWSR_REG & 0xf8 != 0x28){
		RetVar = masterWriteByteErr;
		}else{
		// Do Nothing
	}
	return RetVar;
}
TWI_RetErr TWI_MasterReadData(unsigned char* Data){
	TWI_RetErr RetVar = noError ;
	/*clearing the TWINT FLAG*/
	SetBit(TWCR_REG,TWINT_BIT);
	/*waiting for the process to finish*/
	while(GetBit(TWCR_REG,TWINT_BIT)==0);
	if(TWSR_REG & 0xf8 != 0x50){
		RetVar = masterReadByteErr;
		}else{
		*Data = TWDR_REG;
	}
}