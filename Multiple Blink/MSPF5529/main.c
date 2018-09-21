#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	P1DIR |= BIT0; //assigns P1.0 to have an output direction
	P1SEL &= ~BIT0; //assigns value of 0 to Pin1 in P1SEL SFR
	P4DIR |= BIT7; //assigns P4.7 to have an output direction 
	P4SEL &= ~BIT7; //assigns value of 0 to Pin7 in P4SEL SFR
	
	int a = 0; //sets counter variable to 0
	int b = 0;  //sets counter variable to 0
	while(1)
	{
	     a += 1; //increments counter variable 
	     b += 1; //increments counter variable
	     __delay_cycles(50000); //delays the while loop by 50,000 clock cycles
	     if (a == 25)
	     {
	         P1OUT ^= BIT0; //toggles BIT0 between 0 and 1
	         a = 0; //resets counter variable
	     }
	     if (b == 10)
	     {
	         P4OUT ^= BIT7; //toggles BIT7 between 0 and 1 
	         b = 0; //resets counter variable
	     }
	}
	return 0;
}
