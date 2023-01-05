/*
 * I2C_HW.h
 *
 * Created: 1/5/2023 10:35:41 PM
 *  Author: Kareem
 */ 

#ifndef I2C_HW_H_
#define I2C_HW_H_
#include "BitMath.h"
#define TWAR_REG (*(volatile unsigned char*) 0x22)
#define TWBR_REG (*(volatile unsigned char*) 0x20)
#define TWCR_REG (*(volatile unsigned char*) 0x56)
#define TWE_BIT 2
#define TWSTO_BIT 4
#define TWSTA_BIT 5
#define TWEA_BIT 6
#define TWINT_BIT 7

#define TWDR_REG (*(volatile unsigned char*) 0x23)
#define TWSR_REG (*(volatile unsigned char*) 0x21)

#define TWPS0_BIT 0
#define TWPS1_BIT 1


typedef enum{
	noError=1,
	startConditionErr,
	repeatStartCondErr,
	slaveAddressWriteErr,
	slaveAddressReadErr,
	masterWriteByteErr,
	masterReadByteErr,
} TWI_RetErr;




#endif /* I2C_HW_H_ */