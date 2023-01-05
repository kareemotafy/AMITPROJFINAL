/*
 * ADC.c
 *
 * Created: 1/5/2023 11:10:27 PM
 *  Author: Kareem
 */ 
#include "ADC.h"

static ADC_ConfigStruct ADC_InitStruct;


void ADC_Init(ADC_ConfigStruct* ptr){
	ADC_InitStruct.PSC = ptr->PSC;
	ADC_InitStruct.RMode = ptr->RMode;
	ADC_InitStruct.VRef = ptr->VRef;
	ADC_InitStruct.Channel = ptr->Channel;
	if(ADC_InitStruct.RMode == Interrupt){
		SetBit(ADCSRA_REG,ADIE_BIT);
		}else if(ADC_InitStruct.RMode == Polling){
		ClearBit(ADCSRA_REG,ADIE_BIT);
	}
	// Enabling the ADC
	SetBit(ADCSRA_REG,ADEN_BIT);
	// Setting System Clock pre-scalar
	ADCSRA_REG |= ADC_InitStruct.PSC;
	// Setting Vref
	//ADMUX_REG &= 0x3F;
	ADMUX_REG |= (ADC_InitStruct.VRef<<6);
	// Setting the ADC channel to be used
	ADMUX_REG |= (ADC_InitStruct.Channel);
}

unsigned short int ADC_Read(ADC_Channel channel){
	unsigned short Read=0;
	SetBit(ADCSRA_REG,ADSC_BIT);
	while(GetBit(ADCSRA_REG,ADIF_BIT)==0){
	}
	Read = ADCL_REG;
	Read |= ADCH_REG<<8;
	return Read;
}
