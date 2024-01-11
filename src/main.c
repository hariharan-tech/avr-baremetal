#include "./../inc/atmega328p/memorymap.h" // Register Memory map file
#include "./../inc/lib/lcd16x2/lcd16x2.h" // Functions for accessing LCD displays

// #include <avr/io.h> // Exposes GPIO functions and registers
// #include <util/delay.h> // Exposes the delay function

#define RS_BIT 0
#define RW_BIT 1
#define ENBL 2

int main(){
	lcd16x2_8data(.data_port(PORTD),
				.control_port(PORTC),
				.rs_bit(RS_BIT),
				.rw_bit(RW_BIT),
				.enable_bit(ENBL)
				);
	clear_display();
	// DDRB |= (1<<5); // Making PORTB 5th bit as an output bit
	// while(1){ // Infinite loop
	// 	PORTB |= (1<<5); // Setting the 5th bit of Port B
	// 	_delay_ms(100); // 1000 ms delay
	// 	PORTB &= ~(1<<5); // Clearing the 5th Bit of Port B
	// 	_delay_ms(100); // 1000 ms delay
	// }
	return 0;
}
