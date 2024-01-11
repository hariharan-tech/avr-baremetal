#include "lcd16x2.h"


// LCD Command write
void command_write(lcd16x2_8data* display, unsigned char data){
	// * is used to de-reference and write to the value (and not the memory location)
	*display->data_port = data; // Float the data in the data_port
	*display->control_port &= (~(1<<display->rs_bit)); // Clear the Register Select bit
	*display->control_port &= (~(1<<display->rw_bit)); // Clear the Read/Write bit
	*display->control_port |= (1<<display->enable_bit); // Pull high the Enable bit 
	_delay_ms(50); // 50ms delay
	*display->control_port &= (~(1<<display->enable_bit)); // Clear the Enable bit to write the data
	_delay_ms(50); // 50ms delay

	// // Reference
	// PORTD = data;
	// PORTB &= (~(1<<display->rs_bit));
	// PORTB &= (~(1<<display->rw_bit));
	// PORTB |= (1<<display->enable_bit);
	// _delay_ms(50);
	// PORTB &= (~(1<<display->enable_bit));
	// _delay_ms(50);
}


// Write data to the display
void data_write(lcd16x2_8data* display, unsigned char data){
	*display->data_port = data; // Float the data in the data_port
	*display->control_port |= ((1<<display->rs_bit)); // Pull high the Register Select bit
	*display->control_port &= (~(1<<display->rw_bit)); // Clear the Read/Write bit
	*display->control_port |= (1<<display->enable_bit); // Pull high the Enable bit 
	_delay_ms(50); // 50ms delay
	*display->control_port &= (~(1<<display->enable_bit)); // Clear the Enable bit to write the data
	_delay_ms(50); // 50ms delay

	// // Reference
	// PORTD = data;
	// PORTB |= (1<<display->rs_bit);
	// PORTB &= (~(1<<display->rw_bit));
	// PORTB |= (1<<display->enable_bit);
	// _delay_ms(50);
	// PORTB &= (~(1<<display->enable_bit));
	// _delay_ms(50);
}


// Initialize the display
void init_display(lcd16x2_8data* display){
	command_write(display,0x30); // Initialize the display
	command_write(display,0x30); // Initialize the display
	command_write(display,0x30); // Initialize the display
	command_write(display,0x38); // 0011 1000 => Display lines = 8bits; N=1 => 16x2 display configuration
	command_write(display,0x08); // Display OFF
	command_write(display,0x01); // Clear the display
	command_write(display,0x06); // Increment cursor in right I/D = 1 and dont shift the display S = 0
	command_write(display,0x0C); // Display turn on, no cursor
}


// Blink on-board LED (used for debug)
void blinky_onboard_led(){
    DDRB |= (1<<5); // Making PORTB 5th bit as an output bit
	while(1){ // Infinite loop
		PORTB |= (1<<5); // Setting the 5th bit of Port B
		_delay_ms(800); // 1000 ms delay
		PORTB &= ~(1<<5); // Clearing the 5th Bit of Port B
		_delay_ms(800); // 1000 ms delay
	}
}