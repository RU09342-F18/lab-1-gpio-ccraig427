#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	P1DIR |= BIT0 | BIT6; //assigns BIT0 and BIT6 to have an output direction
	P1SEL &= ~(BIT0 + BIT6); //assigns value of 0 to Pin1 and Pin6 in P1SEL SFR

    while(1)
	{
        P1OUT ^= BIT0 | BIT6; //toggles the output 
	__delay_cycles(500000); //delays the loop by 500,000 cycles
	}
	return 0;
}
