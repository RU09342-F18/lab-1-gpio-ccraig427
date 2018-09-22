#include <msp430.h> 
/* 
*File: main.c For Button blink on MSP430G2553
*Created On: 9/17/2018
*Last Edited:
*Author: Colin Craig
*/

int main(void) 
{ 
  WDTCTL = WDTPW + WDTHOLD; //Disables the watchdog timer using the WDTHOLD 
  P1DIR = BIT0; //Sets Bit 0 of Port 1 to be an output 
  P1REN = BIT3; //Adds a pull-up resistor to Port 1.3 (Button) so it's state is normally high 
  P1OUT = BIT3; //Assigns connectivity of pull-up resistor to high voltage 
//P1OUT != BIT3; //Assigns to ground
  while(1)
  {
    if ((P1IN & BIT3) != BIT3) 
    {
      P1OUT ^= BIT0; //toggles the LED
	    __delay_cycles(500000);
	  }
  }
	return 0;
}
  
