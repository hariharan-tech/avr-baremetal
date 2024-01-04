# Compiler
CC:=avr-gcc

# Source files
SRC_DIR := ./src/

# Microcontroller
MCU := atmega328p

# Library files
DEVICE_DIR := ./inc/$(MCU)/
UTIL_DIR := ./inc/lib/

DEVICE_LIB := $(shell find $(DEVICE_DIR) -name '*.h')
UTIL_LIB := $(shell find $(UTIL_DIR) -name '*.h')

DEVICE_C := $(shell find $(DEVICE_DIR) -name '*.c')
UTIL_C := $(shell find $(UTIL_DIR) -name '*.c')

DEPEN_C := $(DEVICE_C) $(UTIL_C)
DEPEN_O := $(patsubst %.c,%.o,$(DEPEN_C))


# Build directory
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
CCFLAGS+= -Wall -mmcu=$(MCU)

all: obj_build elf_build hex_build

$(DEPEN_O): $(DEPEN_C)
	$(CC) $(CCFLAGS) -c -o $(OBJ_DIR)$(notdir $@) $(patsubst %.o,%.c,$@)

obj_build: $(SRC_DIR)main.c $(DEPEN_O)
	$(CC) $(CCFLAGS) $(SRC_DIR)main.c -c $(shell find $(OBJ_DIR) -name '*.o') -o $(BUILD_DIR)main.o
	echo "\nDone Object file creation"

elf_build: $(BUILD_DIR)main.o obj_build
	$(CC) $(CCFLAGS) $(BUILD_DIR)main.o $(shell find $(OBJ_DIR) -name '*.o') -o $(BUILD_DIR)main.elf

hex_build: obj_build elf_build $(BUILD_DIR)main.elf
	avr-objcopy -j .text -j .data -O ihex $(BUILD_DIR)main.elf $(BUILD_DIR)main.hex
	
# lsusb -t -v

flash_mcu: hex_build
	avrdude -v -p $(MCU) -c $(PROGRAMMER) -P $(PORT_NO) -U flash:w:./build/main.hex:i

# find the programmers using avrdude -c randomdata
