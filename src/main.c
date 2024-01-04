#define F_CPU 16000000 // 16MHz clock

// #include <avr/io.h> // Exposes GPIO functions and registers
#include <util/delay.h> // Exposes the delay function

#include "./../inc/atmega328p/memorymap.h"
// #include "./../inc/atmega328p/delay.h"

int main(){
	DDRB |= (1<<5); // Making PORTB 5th bit as an output bit
	while(1){ // Infinite loop
		PORTB |= (1<<5); // Setting the 5th bit of Port B
		_delay_ms(100); // 1000 ms delay
		PORTB &= ~(1<<5); // Clearing the 5th Bit of Port B
		_delay_ms(100); // 1000 ms delay
	}
	return 0;
}
