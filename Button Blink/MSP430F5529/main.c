#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
        WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

        P1DIR = BIT0;              //Sets BIT 0 to be an output
        P1REN = BIT1;              //enables pull-up resistor so its normally high voltage
        P1OUT = BIT1;              //Assigns connection to BIT1

        while (1)
        {
        //if  (P1 is an output, and BIT1 is true) and is NOT BIT1
        if ((P1IN & BIT1) != BIT1)
        {
            //BIT0 is toggled
            P1OUT ^= BIT0;
            __delay_cycles(500000); //Delays 500000 cycles to slow down loop speed
        }

        }
    return 0;
}
