/*
 * Timer.c
 *
 * Created: 1/5/2023 11:19:55 PM
 *  Author: Kareem
 */
#include "avr/interrupt.h"

// Timer counter value for 100ms interrupt frequency

void INIT_Timer0()
{
	// Set initial value of TCNT0
	TCNT0 = 142;

	// Set Timer0 to Normal mode with prescaler of 64
	TCCR0 = (1 << CS01) | (1 << CS00);

	// Enable Timer0 overflow interrupt
	TIMSK |= (1 << TOIE0);
}

void INIT_Timer1()
{
	TCCR1A = 0x00;
	TCCR1B |= (1 << CS12)|(1 << CS10);
	
	TCNT1 = 57723;
	
	TIMSK |= (1 << TOIE1);
	
}