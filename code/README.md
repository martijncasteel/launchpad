# push-to-talk - code

In this README the code directory is explained in more detail. 

## setting up dev environment

```bash
sudo apt update
sudo apt install binutils gcc-avr avr-libc avrdude make
```

The [binary](https://github.com/martijncasteel/launchpad/tree/main/code/bin) can be flashed on the board using the Makefile. The code is far from perfect, and there might be plenty of improvements, feel free to add a pull request! 

```bash
# built intermediates in /build and binary in /bin
# note; changes in header files are not picked up, use make clean
make

# flash to microcontroller
# note; /dev/ttyUSB0 is also the default port, argument can be omitted
make flash PORT=/dev/ttyUSB0

# set fuses on microcontroller
make fuses PORT=/dev/ttyUSB0

# remove intermediates and binary
make clean
```

<br /><!-- spacing for header -->

## USB HID Telephone pages
This approach uses a custom report descriptor defined in [usb.h](/martijncasteel/launchpad/tree/main/code/include/usb.h) which is mapped on the pins used by the buttons. For the bigger button, there is some additional code to set either one of the two least significant bits. When the button is pressed the microphone is unmuted, when released the microphone is muted. 

There are more buttons to toggle to mute the microphone and a button to mute the speakers. There are two buttons to increase or decrease the volume, and also a button to hang up the phone. The complete button map is described in [board.h](/martijncasteel/launchpad/tree/main/code/include/board.h)

> This is my preferred implementation, it is pretty neat. Unfortunately, it is not working yet since Teams is not supporting the USB HID Telephone pages.
> Microsoft has chosen to only allow certified paying manufacturers to create integrated hardware.

In trying to get it to work I have now created multiple reports with their own report id. Windows works better with volume control in a separate consumer control collection. Windows is also very picky in the byte alignment, you must add padding to get full bytes, otherwise Windows will throw an urb_fuction_abort error.

<br /><!-- spacing for header -->

## Debugging
After watching loads of [Ben Eater](https://www.youtube.com/watch?v=2lPzTU-3ONI) videos I used a [usb capture](https://wiki.wireshark.org/CaptureSetup/USB) extension for Wireshark. This allowed me to see the communication and the setup progress. There you'll find the first hints why stuff isn't working. In Windows the device manager can give you some more hints, especially the byte alignment is mentioned here, Linux doesn't throw an error if the alignment is off. In my board I did not include any pins for debugging using a wire protocol. This might it a bit tricky in the beginnen but with the single led I made it work.

<br /><!-- spacing for header -->

## Documentation
In [/docs](/martijncasteel/launchpad/tree/main/code/docs) there are several relevant files for using USB HID and the ATMega32u4 microcontroller. Furthermore, there are some links below that have some more information
* https://docs.rs/atmega32u4/0.1.2/atmega32u4/usb/struct.UEINTX.html