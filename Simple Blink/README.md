Student: Colin Craig 
Date Completed 9/17/2018

# Simple Blink
This portion of the lab was to demonstrate how to blink an LED on two of the development boards. The LED will blink at a specific rate depending on the delay of the clock cycles for the microcontroller. By completing this exercise, I was able to understand how to control a specific General Purpose Input/Output (GPIO) pin. For this exercise, I used the MSP430G2553 and MSP430F5529 microcontrollers. 

## Code Analysis
Performing logic operations with BIT0 makes up most of this code. BIT0 is defined as 0x01. P1SEL &= ~BIT0 allows the least significant bit of the P1SEL register to be 0. This selects Pin 1.0 by allowing only the manipulation of the first index or bit in the register. Each bit of the 8-bit P1SEL register corresponds with Pin's 1.0-1.7. P1DIR |= BIT0 allows the P1.0 to be distinguished as an output. If we wanted the port to be an input, we would want the first bit of the P1DIR register to be a 0. P1OUT ^= BIT0 toggles the first bit on and off. This allows the LED to continue to blink on and off in the infinite while loop. Putting a delay of 1000000 clock cycles after allows the user to visually see the LED toggle. Otherwise, it would switch too fast for us to see. 



