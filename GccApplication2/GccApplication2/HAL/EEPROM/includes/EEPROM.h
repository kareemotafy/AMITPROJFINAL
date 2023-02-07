/*
 * EEPROM.h
 *
 * Created: 1/5/2023 10:30:38 PM
 *  Author: Kareem
 */

#ifndef EEPROM_H_
#define EEPROM_H_
#include "I2C.h"
#include "EEPROM.h"
#include <avr/eeprom.h>
#define F_CPU 8000000ul
#include <util/delay.h>

void INIT_eeprom();

#endif /* EEPROM_H_ */