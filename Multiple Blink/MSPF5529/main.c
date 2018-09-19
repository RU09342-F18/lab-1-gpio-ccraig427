#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	P1DIR |= BIT0; //assigns BIT0 to have an output direction
	P1SEL &= ~BIT0; //assigns value of 0 to Pin1 in P1SEL SFR
	P4DIR |= BIT7;
	P4SEL &= ~BIT7;
	
	int a = 0;
	int b = 0;
	while(1)
	{
	     a += 1;
	     b += 1;
	     __delay_cycles(50000);
	     if (a == 25)
	     {
	         P1OUT ^= BIT0;
	         a = 0;
	     }
	     if (b == 10)
	     {
	         P4OUT ^= BIT7;
	         b = 0;
	     }
	}
	return 0;
}
