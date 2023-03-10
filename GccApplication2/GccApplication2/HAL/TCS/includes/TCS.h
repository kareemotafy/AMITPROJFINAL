/*
 * TCS.h
 *
 * Created: 1/5/2023 11:03:26 PM
 *  Author: Kareem
 */

#ifndef TCS_H_
#define TCS_H_

#include <avr/io.h>
#include "BitMath.h"
#include "LM35.h"
#include "EEPROM.h"
#define heaterPort PORTD
#define heaterDDR DDRD
#define heaterPin 7
#define coolerPort PORTD
#define coolerDDR DDRD
#define coolerPin 6
#define ledPin 3
#define ledPort PORTD
#define ledDDR DDRD

void INIT_HeaterCooler();

void COOLER_ON();

void COOLER_OFF();

void HEATER_ON();

void HEATER_OFF();

void LED_OFF();

void TCS_Handler();

void TCS_Actuator();

#endif /* TCS_H_ */