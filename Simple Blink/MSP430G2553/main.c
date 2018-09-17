#include <msp430.h>
/* 
*File: main.c For Simple blink on MSP430G2553
*Created On: 9/16/2018
*Last Edited:
*Author: Colin Craig
*/

int main(void) 
{ 
  WDTCTL = WDTPW + WDTHOLD; //Disables the watchdog timer using the WDTHOLD 
  
  P1SEL &= ~BITO; 
  P1DIR |= BITO0; 
  
  while(1) 
  { 
    P1OUT ^= BITO; 
    __delaY_cycles(1000000); 
  }
  return 0; 
}
  
  
  
