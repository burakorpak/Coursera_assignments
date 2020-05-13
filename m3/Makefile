include sources.mk

LINKER_FILE = msp432p401r.lds
CPU = cortex-m4
ARCH = thumb
SPECS = nosys.specs
BASENAME = main
TARGET = $(BASENAME).out
CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
LDFLAGS = -Wl,-Map=$(BASENAME).map
CFLAGS = -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) -Wall
OBJS = $(SOURCES: .c = .o)
%.o=%.c
	$(cc) -c $< $(LDFLAGS) $(CFLAGS) -o $@
.PHONY: build
build: all
.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJS)
	$(cc) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET) $(BASENAME).map
