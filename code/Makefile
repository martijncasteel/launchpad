# Launchpad makefile to compile and flash c code
# Author: Martijn Casteel

TARGET 		= bin/launchpad.hex
MCU 			= atmega32u4
CLK		 		= 16000000UL

SRCDIR 		= src
BUILDDIR 	= build

CC 				= avr-gcc -mmcu=$(MCU) -DF_CPU=$(CLK) -Wall# -DDEBUG
AVRDUDE 	= avrdude -v -carduino -p$(MCU) -P/dev/ttyUSB0 -b19200
OBJCOPY 	= avr-objcopy

SOURCES 	:= $(shell find $(SRCDIR) -type f -name '*.c')
OBJECTS 	:= $(patsubst $(SRCDIR)/%, $(BUILDDIR)/%, $(SOURCES:.c=.o))

# avr-gcc -DF_CPU=8000000 -mmcu=attiny85 -Os -c led_flash.c
# avr-gcc -DF_CPU=8000000 -mmcu=attiny85 -o led_flash.elf led_flash.o
# avr-objcopy -O ihex led_flash.elf led_flash.hex


$(TARGET): $(BUILDDIR)/main.elf
	$(OBJCOPY) -O ihex $< $@

$(BUILDDIR)/main.elf: $(OBJECTS)
	$(CC) -o $@ $^

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(BUILDDIR)
	$(CC) -Iinclude -Os -c -o $@ $^

flash:
	$(AVRDUDE) -U flash:w:$(TARGET):i

# write arduino standard fuses, read fuses following line
# $(AVRDUDE) -U lfuse:r:-:i -U hfuse:r:-:i -U efuse:r:-:i
fuses:
	$(AVRDUDE) -U lfuse:w:0xFF:m -U hfuse:w:0xD8:m -U efuse:w:0xCB:m

clean:
	-rm -r $(BUILDDIR) $(TARGET)

.PHONY: clean flash fuses