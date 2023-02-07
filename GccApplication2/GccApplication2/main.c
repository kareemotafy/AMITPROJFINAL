/*
 * GccApplication2.c
 *
 * Created: 1/5/2023 10:27:39 PM
 * Author : Kareem
 */
//

#include "SYSTEM.h"

ISR(TIMER0_OVF_vect) // Timer0 ISR
{
	SYSTEM_timer();
}

// global device enable toggle
char on = 0;
ISR(INT0_vect)
{
	on = ~on;
}

int main(void)
{

	SYSTEM_init();

	while (1)
	{
		if (on)
		{
			SYSTEM_loop();
		}
		else
		{
			SYSTEM_OFF();
		}
	}
}