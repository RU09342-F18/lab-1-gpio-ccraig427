## Button Blink 
In this exercise, a button was implemented as a switch to control whether the LED is on or off. In the G2553, the button was connected to P1.3. In the F5529, the button used was connected to P1.1. 
A new register was used in this exercise called P1REN. This register controls the pull-up resistor connected to the button. In this exercise, we set the resistor to be normally high through the line P1REN = BIT3 corresponding to P1.3 for the G2553. In the F5529, the line of code to add a pull-up resistor to the button would be P1REN = BIT1. 
