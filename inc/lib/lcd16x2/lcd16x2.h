#ifndef _LCD_16X2_H_
#define _LCD_16X2_H_

// This would require the Clock frquency at which the processor operates
// That is passed through the flags in GCC compiler invocation
#ifndef _UTIL_DELAY_H_ // This gets defined as we include <util/delay.h>
#include <util/delay.h>
#endif

#ifndef _MEMORYMAP_H_ // Access the Memory map
#include "./../../atmega328p/memorymap.h"
#endif

// Used for LCD 16x2 8 bit dataline object initialization
typedef struct lcd16x2_8data{
    // data_port and control_port are pointer of the port register
    // For example, if we define PORTD as data pins, then data_port is initialized with &PORTD
    volatile unsigned char* data_port; // Data port
    volatile unsigned char* control_port; // Control wire port
    unsigned char rs_bit; // Register select bit location (0 to 7) with respect to control wire port
    unsigned char rw_bit; // Read Write bit location (0 to 7) with respect to control wire port
    unsigned char enable_bit; // Enable bit location (0 to 7) with respect to control wire port
} lcd16x2_8data;

void init_display(lcd16x2_8data* display); // Initialize the display
void command_write(lcd16x2_8data* display,unsigned char data); // Write Command to display
void data_write(lcd16x2_8data* display, unsigned char data); // Write Data to display
void blinky_onboard_led(); // Debug purpose (onboard led blinking)

#endif