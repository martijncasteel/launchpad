# push-to-talk - code

In this README the code directory is explained in more detail. 

## setting up dev environment

```bash
sudo apt update
sudo apt install binutils gcc-avr avr-libc avrdude make
```

The [binaries](bin/) can be flashed on the board using the Makefile in the respective directories. As mentioned in the README there are two approaches right now to use the board. 

```bash
# built intermediates in /build and binary in ../bin
make

# flash to microcontroller
make flash PORT=/dev/ttyUSB0

# set fuses on microcontroller
make fuses PORT=/dev/ttyUSB0

# remove intermediates and binary
make clean
```

<br /><!-- spacing for header -->

> [USB HID Telephone pages](/martijncasteel/launchpad/tree/main/code/usb-hid-telephone) <br />
> The original idea, using USB HID Telephone pages to control the microphone. *This is currently not supported!*

> [USB Keyboard shortcuts](/martijncasteel/launchpad/tree/main/code/teams-shortcuts) <br/>
> A workaround using the Teams shortcuts such as the spacebar. This does not meet all requirements.

<br /><!-- spacing for header -->

## USB HID Telephone pages
This approach uses a custom report descriptor defined in [usb.h](/martijncasteel/launchpad/tree/main/code/usb-hid-telephone/include/usb.h) which is mapped on the pins used by the buttons. For the bigger button, there is some additional code to set either one of the two least significant bits. When the button is pressed the microphone is unmuted, when released the microphone is muted. 

There are more buttons to toggle to mute the microphone and a button to mute the speakers. There are two buttons to increase or decrease the volume, and also a button to hang up the phone. The complete button map is described in [board.h](/martijncasteel/launchpad/tree/main/code/usb-hid-telephone/include/board.h)

> This is my preferred implementation, it is pretty neat. Unfortunately, it is not working since Teams is not supporting the USB HID Telephone pages. <br />
> Microsoft has chosen to only allow certified paying manufacturers to create integrated hardware.

<br /><!-- spacing for header -->

## Teams shortcuts implementation
This looks more like a regular keyboard. This approach uses the buttons as shortcuts, for example <kbd>Space</kbd> toggles the mute of the microphone.

<br /><!-- spacing for header -->

## documentation
In [/docs](docs/) there are several relevant files for using USB HID and the ATMega32u4 microcontroller. Furthermore, there are some links below that have some more information
* https://docs.rs/atmega32u4/0.1.2/atmega32u4/usb/struct.UEINTX.html