#include <msp430.h> 
/* 
*File: main.c For Simple blink on MSP430F5529
*Created On: 9/19/2018
*Last Edited: 9/19/2018
*Author: Colin Craig
*/

int main(void)
{
  WDTCTL = WDTPW + WDTHOLD; //Disables the watchdog timer within the microcontroller 
  
  P1SEL &= ~BIT0; //Selects P1.0 by negating the least significant bit in the P1SEL register
  P1DIR |= BITO0; //Selects output of P1.0 by turning on the least significant bit of P1DIR register
  
  while(1) //Initiate an infinite while loop 
  { 
    P1OUT ^= BIT0; //Toggles least significant bit of P1OUT on and off
    __delaY_cycles(1000000); //Delays 1,000,000 clock cycles between each while loop 
  }
  return 0; 
}

