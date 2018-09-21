Student: Colin Craig 
Date Completed 9/17/2018

# Simple Blink
This portion of the lab was to demonstrate how to blink an LED on two of the development boards. The LED will blink at a specific rate depending on the delay of the clock cycles for the microcontroller. By completing this exercise, I was able to understand how to control a specific General Purpose Input/Output (GPIO) pin. For this exercise, I used the MSP430G2553 and MSP430F5529 microcontrollers. 

## Code Analysis
Performing logic operations with BIT0 makes up most of this code. BIT0 is defined as 0x01. P1SEL &= ~BIT0 allows the least significant bit of the P1SEL register to be 0. This selects Pin 1.0. 

