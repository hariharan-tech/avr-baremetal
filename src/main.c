#include "./../inc/atmega328p/memorymap.h" // Register Memory map file
#include "./../inc/lib/lcd16x2/lcd16x2.h" // Functions for accessing LCD displays

#define RS_BIT 0 // Define the Register Select bit location in PortB
#define RW_BIT 1 // Define the Read Write bit location in PortB 
#define ENBL 2 // Define the Enable bit location in PortB

int main(){
	DDRD = 0xff; DDRB = 0xff; // PORTD and PORTB as output ports
	PORTD = 0; PORTB = 0; // Initialize both to logic level 0
	
	// Create a object of the struct
	// We pass in address of PORTD and PORTB and not the value in PORTD or PORTB
	lcd16x2_8data LCD_Display = {&PORTD,&PORTB,RS_BIT,RW_BIT,ENBL};
	
	// As per datasheet we need to wait for 40ms until the voltage level stabilizes
	_delay_ms(40);

	// Call the initialize display function by passing the address of LCD_Display struct
	init_display(&LCD_Display);
	
	// An example text for displaying
	unsigned char name[] = {"AVR Baremetal!"};
	
	// We call this function as per the legnth of the array and display it
	for(int i=0;name[i]!='\0';i++)
		data_write(&LCD_Display,name[i]); // We pass in the struct and data we wish to print
	blinky_onboard_led(); // Infinite loop while blinking the onboard LED
	return 0;
}