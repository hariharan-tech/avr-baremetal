// Register memory map file
#ifndef _MEMORYMAP_H_
#define _MEMORYMAP_H_

// 13.4.3 DDRB – The Port B Data Direction Register
#define DDRB *((volatile unsigned char *) 0x24)

// 13.4.2 PORTB – The Port B Data Register
#define PORTB *((volatile unsigned char *) 0x25)

// 13.4.4 PINB – The Port B Input Pins Address
#define PINB *((volatile unsigned char*) 0x23)

// 13.4.6 DDRC – The Port C Data Direction Register
#define DDRC *((volatile unsigned char*)0x27)

// 13.4.5 PORTC – The Port C Data Register
#define PORTC *((volatile unsigned char*)0x28)

// 13.4.7 PINC – The Port C Input Pins Address
#define PINC *((volatile unsigned char*)0x26)

// 13.4.9 DDRD – The Port D Data Direction Register
#define DDRD *((volatile unsigned char*)0x2A)

// 13.4.8 PORTD – The Port D Data Register
#define PORTD *((volatile unsigned char*)0x2B)

// 13.4.10 PIND – The Port D Input Pins Address
#define PIND *((volatile unsigned char*)0x29)

#endif