# Compiler
CC:=avr-gcc

# Source files
SRC_DIR := ./src/

# Microcontroller
MCU := atmega328p

# Clock frequency (16MHz clock chosen)
## To give user input F_CPU, write 'make hex_build "F_CPU=12E6"' for 12MHz clock
F_CPU = 16E6

# Library and other source files
## Directory
DEVICE_DIR := ./inc/$(MCU)/
UTIL_DIR := ./inc/lib/

## Library files location
DEVICE_LIB := $(shell find $(DEVICE_DIR) -name '*.h')
UTIL_LIB := $(shell find $(UTIL_DIR) -name '*.h')

## C files location
DEVICE_C := $(shell find $(DEVICE_DIR) -name '*.c')
UTIL_C := $(shell find $(UTIL_DIR) -name '*.c')

## Collecting all C files and O file names
DEPEN_C := $(DEVICE_C) $(UTIL_C)
DEPEN_O := $(patsubst %.c,%.o,$(DEPEN_C))


# Build and object directory
BUILD_DIR := ./build/
OBJ_DIR := $(BUILD_DIR)obj/

# C standard
STD_C := gnu99

# AVRDUDE Programmer
PROGRAMMER := arduino # Try with avrftdi to avoid using arduino bootloader

# USB Port Number
PORT_NO := /dev/ttyACM0 # works for arduino programmers
#PORT_NO ?= $(shell bash -c 'read -p "USB Port number: " port_no; echo $$port_no')

#Flags
CCFLAGS:= -std=$(STD_C)
CCFLAGS+= -Wall -mmcu=$(MCU) -F_CPU=$(F_CPU)

# Build All files
all: obj_build elf_build hex_build

# Build all dependency source files to object files
$(DEPEN_O): $(DEPEN_C)
	$(CC) $(CCFLAGS) -c -o $(OBJ_DIR)$(notdir $@) $(patsubst %.o,%.c,$@)

# Build main object file and dependency object files
obj_build: $(SRC_DIR)main.c $(DEPEN_O)
	$(CC) $(CCFLAGS) $(SRC_DIR)main.c -c $(shell find $(OBJ_DIR) -name '*.o') -o $(BUILD_DIR)main.o
	echo "\nDone Object file creation"

# Build ELF file
elf_build: $(BUILD_DIR)main.o obj_build
	$(CC) $(CCFLAGS) $(BUILD_DIR)main.o $(shell find $(OBJ_DIR) -name '*.o') -o $(BUILD_DIR)main.elf

# Build Intel Hex file format for avrdude flashing
hex_build: obj_build elf_build $(BUILD_DIR)main.elf
	avr-objcopy -j .text -j .data -O ihex $(BUILD_DIR)main.elf $(BUILD_DIR)main.hex
	
# lsusb -t -v

# Used for Flashing Microcontroller!
flash_mcu: hex_build
	avrdude -v -p $(MCU) -c $(PROGRAMMER) -P $(PORT_NO) -U flash:w:./build/main.hex:i

# find the programmers using avrdude -c randomdata

clean:
	rm ./build/main.*
