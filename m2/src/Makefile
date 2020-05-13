#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = HOST
TARGET = c1m2

ifeq ($(PLATFORM), HOST)
	CC = gcc
	CFLAGS = -Wall -Werror -g -O0 -std=c99
	CPPFLAGS = -DHOST $(INCLUDES)
	LDFLAGS = -Wl,-Map=c1m2.map
	SIZE = size
endif

ifeq ($(PLATFORM), MSP432)
	LINKER_FILE = -T msp432p401r.lds
	LINKER_PATH = -L ../
	CPU = cortex-m4
	ARCH = armv7e-m
	SPECS = nosys.specs
	OTHER_FLAGS = -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16
	CC = arm-none-eabi-gcc
	CFLAGS = -Wall -Werror -g -O0 -std=c99 $(OTHER_FLAGS) -mcpu=$(CPU) -march=$(ARCH) --specs=$(SPECS)
	CPPFLAGS = -DMSP432 $(INCLUDES)
	LDFLAGS = -Wl,-Map=c1m2.map $(LINKER_PATH) $(LINKER_FILE)
	SIZE = arm-none-eabi-size
endif

OBJS = $(SOURCES:.c=.o)
DEPS = $(SOURCES:.c=.d)
ASMS = $(SOURCES:.c=.asm)
PRES = $(SOURCES:.c=.i)

%.o : %.c
	$(CC) -c $< $(CPPFLAGS) $(CFLAGS) -o $@

%.asm : %.c
	$(CC) -S $< $(CPPFLAGS) $(CFLAGS) -o $@

%.i : %.c
	$(CC) -E $< $(CPPFLAGS) -o $@

%.d : %.c
	$(CC) -E -M $< $(CPPFLAGS) -o $@

.PHONY: compile-all
compile-all:$(OBJS)

.PHONY: build
build: $(DEPS)
build: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@
	$(SIZE) $@

.PHONY: clean
clean:
	rm -f $(OBJS) $(DEPS) $(ASMS) $(PRES) $(TARGET).out $(TARGET).map
