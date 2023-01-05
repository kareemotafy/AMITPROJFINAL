/*
 * Timer.c
 *
 * Created: 1/5/2023 11:19:55 PM
 *  Author: Kareem
 */ 
#include "avr/interrupt.h"

// Timer counter value for 100ms interrupt frequency
#define TIMER_COUNTER_VALUE 80000


void INIT_Timer1(void){
	// Set up timer in CTC mode
	TCCR1A = 0;
	TCCR1B = (1 << WGM12) | (1 << CS10);
	// Set timer counter value
	TCNT1 = TIMER_COUNTER_VALUE;

	// Enable timer compare interrupt
	TIMSK = (1 << OCIE1A);
}