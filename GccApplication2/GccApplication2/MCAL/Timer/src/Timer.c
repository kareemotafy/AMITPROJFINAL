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
	
	TIMSK=(1<<TOIE0);  	/* Enable Timer0 overflow interrupts */
	
	TCNT0 = 8;  		/* Load TCNT0, count for 10ms*/
	TCCR0 = (1<<CS02) | (1<<CS00); /* Start timer0 with /1024 prescaler*/
	
}

void INIT_Timer1()
{
	TCCR1A = 0x00;
	TCCR1B |= (1 << CS12)|(1 << CS10);
	
	TCNT1 = 57723;
	
	TIMSK |= (1 << TOIE1);
	
}