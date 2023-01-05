/*
 * ADC_HW.h
 *
 * Created: 1/5/2023 11:10:53 PM
 *  Author: Kareem
 */ 


#ifndef ADC_HW_H_
#define ADC_HW_H_



#include "BitMath.h"

#define ADMUX_REG (*(volatile unsigned char*) 0x27)
#define ADLAR_BIT 5
#define REFS0_BIT 6
#define REFS1_BIT 7

#define ADCSRA_REG (*(volatile unsigned char*) 0x26)
#define ADEN_BIT 7
#define ADSC_BIT 6
#define ADATE_BIT 5
#define ADIF_BIT 4
#define ADIE_BIT 3



#define ADCH_REG (*(volatile unsigned char*) 0x25)
#define ADCL_REG (*(volatile unsigned char*) 0x24)
#define SFIOR_REG (*(volatile unsigned char*) 0x50)

typedef enum{
	ADC_Channel0=0,
	ADC_Channel1,
	ADC_Channel2,
	ADC_Channel3,
	ADC_Channel4,
	ADC_Channel5,
	ADC_Channel6,
	ADC_Channel7
}ADC_Channel;

typedef enum{
	PSC_2=1,
	PSC_4,
	PSC_8,
	PSC_16,
	PSC_32,
	PSC_64,
	PSC_128
}ADC_PSC;

typedef enum{
	Polling,
	Interrupt
}ADC_RMODE;


typedef enum {
	AREF=0,
	AVCC,
	VInternal=3,
}ADC_REFV;


typedef struct{
	ADC_PSC PSC;
	ADC_RMODE RMode;
	ADC_REFV VRef;
	ADC_Channel Channel;
}ADC_ConfigStruct;




#endif /* ADC_HW_H_ */