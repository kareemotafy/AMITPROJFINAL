/*
 * LM35.c
 *
 * Created: 1/5/2023 11:09:05 PM
 *  Author: Kareem
 */
#include "LM35.h"
void LM35_Init(ADC_Channel Channel_confg)
{
	ADC_ConfigStruct *ptr = (ADC_ConfigStruct *)(malloc(sizeof(ADC_ConfigStruct)));
	;
	ptr->PSC = PSC_64;
	ptr->RMode = Polling;
	ptr->VRef = VInternal;
	ptr->Channel = Channel_confg;
	ADC_Init(ptr);
}

unsigned short int LM35_Read(void)
{
	unsigned short int temp;

	temp = ADC_Read(ADC_Channel0) / 4;

	return temp;
}