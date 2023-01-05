/*
 * ADC.h
 *
 * Created: 1/5/2023 11:10:15 PM
 *  Author: Kareem
 */ 


#ifndef ADC_H_
#define ADC_H_



#include "ADC_HW.h"

void ADC_Init(ADC_ConfigStruct* ptr);
unsigned short int ADC_Read(ADC_Channel channel);




#endif /* ADC_H_ */