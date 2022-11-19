# Launchpad makefile to compile and flash c code
# Author: Martijn Casteel

TARGET 		= bin/launchpad.hex
MCU 			= atmega32u4
CLK		 		= 16000000

SRCDIR 		= src
BUILDDIR 	= build

CC 				= avr-gcc -DF_CPU=$(CLK) -mmcu=$(MCU)
AVRDUDE 	= avrdude -v -c arduino -p $(MCU) -P /dev/tty.usb*
OBJCOPY 	= avr-objcopy

SOURCES 	:= $(shell find $(SRCDIR) -type f -name '*.c')
OBJECTS 	:= $(patsubst $(SRCDIR)/%, $(BUILDDIR)/%, $(SOURCES:.c=.o))


# avr-gcc -DF_CPU=8000000 -mmcu=attiny85 -Os -c led_flash.c
# avr-gcc -DF_CPU=8000000 -mmcu=attiny85 -o led_flash.elf led_flash.o
# avr-objcopy -O ihex led_flash.elf led_flash.hex


$(TARGET): $(BUILDDIR)/main.elf
	@echo "$(OBJCOPY) -O ihex $< $@"; $(OBJCOPY) -O ihex $< $@

$(BUILDDIR)/main.elf: $(OBJECTS)
	@echo "$(CC) -o $@ $^"; $(CC) -o $@ $^

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(BUILDDIR)
	@echo "$(CC) -Wall -Os -c -o $@ $^"; $(CC) -Wall -Os -c -o $@ $^


flash:
	$(AVRDUDE) -U flash:w:$(TARGET):i

clean:
	-rm -r $(BUILDDIR) $(TARGET)

.PHONY: clean flash