#include <msp430.h> 
/* 
*File: main.c For Multiple blink on MSP430G2553
*Created On: 9/17/2018
*Last Edited:
*Author: Colin Craig
*/

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD; // stop watchdog timer
	P1DIR |= BIT0 | BIT6; //Gives P1DIR to be an output whenever BIT0 or BIT6 are 1
	P1SEL &= ~(BIT0 + BIT6); //assigns value of 0 to Pin1.0 and Pin1.6 in P1SEL SFR
	int a = 0; //sets counter variable to 1
	int b = 0; //sets counter variable to 1
	while(1)
	{
	    a += 1; //increments counter variable
	    b += 1; //increments counter variable
	    __delay_cycles(50000); //delays the while loop by 50,000 clock cycles
	    if (a == 25) 
	    {
	        P1OUT ^= BIT0; //toggles P1.0 LED
	        a = 0; //sets counter variable back to zero
	    }
	    if (b == 10) 
	    {
	        P1OUT ^= BIT6; //toggles P1.6 LED 
	        b = 0; //sets counter variable back to zero
	    }
	}
	return 0;
}
