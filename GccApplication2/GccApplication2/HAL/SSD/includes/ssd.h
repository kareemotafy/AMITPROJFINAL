/*
 * ssd.h
 *
 * Created: 1/13/2023 1:34:11 AM
 *  Author: omar
 */ 


#ifndef SSD_H_
#define SSD_H_
#include <avr/io.h>
#define F_CPU 8000000ul
#include <util/delay.h>
#include "BitMath.h"
#define SSD_port PORTB
#define Display1Port PORTA
#define Display1Pin 1
#define Display2Port PORTA
#define Display2Pin 2
#define MultiplexDelay 10


	void SSD_write(char num);
	void SSD_OFF();
	void INIT_SSD();
	void SSD_blink(char num);




#endif /* SSD_H_ */