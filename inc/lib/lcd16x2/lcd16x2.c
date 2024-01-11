#include "lcd16x2.h"

// Clear the display screen
void clear_display(){
    DDRB |= (1<<5); // Making PORTB 5th bit as an output bit
	while(1){ // Infinite loop
		PORTB |= (1<<5); // Setting the 5th bit of Port B
		_delay_ms(800); // 1000 ms delay
		PORTB &= ~(1<<5); // Clearing the 5th Bit of Port B
		_delay_ms(800); // 1000 ms delay
	}
}