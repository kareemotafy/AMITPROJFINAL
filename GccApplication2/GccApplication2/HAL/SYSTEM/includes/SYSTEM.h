/*
 * SYSTEM.h
 *
 * Created: 2/7/2023 1:44:47 AM
 *  Author: Kareem
 */

#ifndef SYSTEM_H_
#define SYSTEM_H_
#include <avr/io.h>
#include "EEPROM.h"
#include "buttons.h"
#include "ssd.h"
#include "LM35.h"
#include "ADC.h"
#include "TCS.h"
#include "I2C.h"
#include "Timer.h"

void SYSTEM_init();

void SYSTEM_timer();

void SYSTEM_loop();

void SYSTEM_OFF();

#endif /* SYSTEM_H_ */