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

typedef struct lcd16x2_8data{
    volatile unsigned char* data_port;
    volatile unsigned char* control_port;
    unsigned char* rs_bit;
    unsigned char* rw_bit;
    unsigned char* enable_bit;
} lcd16x2_8data;

// void initialize_display(unsigned char data, volatile unsigned char * data_port );
void clear_display();

#endif