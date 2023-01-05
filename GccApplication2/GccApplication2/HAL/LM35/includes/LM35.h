/*
 * LM35.h
 *
 * Created: 1/5/2023 11:08:30 PM
 *  Author: Kareem
 */ 


#ifndef LM35_H_
#define LM35_H_
#include "ADC.h"

void LM35_Init(ADC_Channel channel);
unsigned short int LM35_Read(void);

#endif /* LM35_H_ */