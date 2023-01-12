/*
 * GccApplication2.c
 *
 * Created: 1/5/2023 10:27:39 PM
 * Author : Kareem
 */
//
#include <avr/io.h>
#include <avr/interrupt.h>
#include "LM35.h"
#include "I2C.h"
#include "ADC.h"
#include "TCS.h"
#include "Clock.h"
#include "Timer.h"

// Timer interrupt service routine
ISR(TIMER0_OVF_vect)
{
	update_temp_reading();
}

int main(void)
{
	INIT_Timer0();
	LM35_Init(ADC_Channel0);
	// Enable global interrupts
	sei();
	while (1)
	{
		SetBit(PORTA, 7);
		_delay_ms(1000);
		ClearBit(PORTA, 7);
		_delay_ms(1000);
	}
}
