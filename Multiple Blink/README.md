# Multiple Blink
In this exercise, I learned how to properly blink two different LED's on the development board at two different rates. Both LEDs blinked at a 50% duty cycle. To blink two different LEDs, I had to manipulate a seperate bit in the SFR registers. Like Simple Blink, BIT0 corresponded to P1.0 in the SFRs. In this exercise, we also manipulated the SFR registers with other bit indexes to correspond to different pins. The MSP430G2553 and MSP430F5529 microcontrollers were used for this exercise. 

## Code Analysis
In this exercise, there was a slight difference between code of the two microcontrollers. This is because the other LED on the F5529 is controlled by P4.7. This means that the same registers cant be used as the LED controlled by P1.0. In both microcontrollers, P1.0 controlled one of the LEDs. To control two different LEDS with different clock rates, two different counters were needed. As the while loop continued to loop, the counters would increment. Through if statements, we could toggle the LEDs corresponding bits when the counter reached a specific value. For example, by setting a counter of 25, the LED would toggle every 25 clock cycles if no delays were implemented. Without delays, the LED would toggle to fast for the user to see. To use P4.7 in the F5529, three lines of additional code were needed. 
### 1.) P4DIR |= BIT7; 
### 2.) P4SEL &= BIT7; 
### 3.) P4OUT ^= BIT7; 
(1) allowed the direction of P4.7 to be an output. This is similar to the line of code for P1.0 except that the P4DIR register is being used and the most significant bit is getting changed in that register. (2) allows the function of that pin to be a general input output. Each pin has the ability to perform numerous functions and this register tells what function that pin will be performing. (3) toggles the most significant bit by XOR. This allows the LED to switch on and off based on the value of BIT7. 

In the MSP430G2553, the 2nd LED used was controlled by P1.6. The only difference with this simulatenous blinking of two LEDs is that we needed to allow P1SEL and P1DIR registers to be changed based on both BIT0 and BIT6. This was accomplished through parentheses as seen in the following line of code. 
### P1SEL &= ~(BIT0 + BIT6) 
