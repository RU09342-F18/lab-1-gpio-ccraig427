#include <msp430.h> 
/* 
*File: main.c For Multiple blink on MSP430G2553
*Created On: 9/17/2018
*Last Edited:
*Author: Colin Craig
*/

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	P1DIR |= BIT0 | BIT6; //assigns BIT0 and BIT6 to have an output direction
	P1SEL &= ~(BIT0 + BIT6); //assigns value of 0 to Pin1 and Pin6 in P1SEL SFR
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
	        P1OUT ^= BIT6;
	        b = 0;
	    }
	}
	return 0;
}
