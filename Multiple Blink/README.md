# Multiple Blink
In this exercise, I learned how to properly blink two different LED's on the development board at two different rates. Both LEDs blinked at a 50% duty cycle. To blink two different LEDs, I had to manipulate a seperate bit in the SFR registers. Like Simple Blink, BIT0 corresponded to P1.0 in the SFRs. In this exercise, we also manipulated the SFR registers with other bit indexes to correspond to different pins. The MSP430G2553 and MSP430F5529 microcontrollers were used for this exercise. 

## Code Analysis
In this exercise, there was a slight difference between code of the two microcontrollers. This is because the other LED on the F5529 is controlled by P4.7. This means that the same registers cant be used as the LED controlled by P1.0. In both microcontrollers, P1.0 controlled one of the LEDs. To control two different LEDS with different clock rates, two different counters were needed. As the while loop continued to loop, the counters would increment. Through if statements, we could toggle the LEDs corresponding bits when the counter reached a specific value. For example, by setting a counter of 25, the LED would toggle every 25 clock cycles if no delays were implemented. Without delays, the LED would toggle to fast for the user to see. To use P4.7 in the F5529, three lines of additional code were needed. 
### 1.) P4DIR |= BIT7; 
### 2.) P4SEL &= BIT7; 
### 3.) P4OUT ^= BIT7; 
