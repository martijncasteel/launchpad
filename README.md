# push-to-talk
A simple macro keyboard designed for using USB HID protocol.

> Unfortantly I was not able to get the device working as intended. There is nothing wrong with the hardware or the code, it is just something I want I can't do without getting a certification with Microsoft. I did learn a lot, plugging in a USB device will never be the same!


My approach is to use the USB HID protocol in full and specifically the USB HID Telephone pages. The goal is to mute and unmute the microphone on Teams on a laptop, even when teams is not in focus.

```
 BTN0  - flash, end call
 BTN1  - camera toggle on/off
 BTN2  - volume increment
 BTN3  - volume decrement
 BTN4  - volume mute
 BTN5  - microphone mute toggle
 BTN6  - Hold to unmute microphone
```

This repository contains the entire project, [/pcb](https://github.com/martijncasteel/launchpad/tree/main/pcb) contains the schematics and design of the board. I used [Kicad](https://www.kicad.org/) for this. The gerber files and other nessecities for manufacturing are located in the [/assembly](https://github.com/martijncasteel/launchpad/tree/main/assembly) folder.

The board is designed to have six regular 1u keycaps, and one 2u keycap. All use regular cherry mx key switches. The board has an ATmega32u4 with native usb support. The ICSP connector can be used to flash the microcontroller. 

![3D render](https://github.com/martijncasteel/launchpad/blob/main/images/3d-front.png?raw=true)

The [software](https://github.com/martijncasteel/launchpad/tree/main/code) is written in C and built using avr-gcc. Using avrdude you can flash the microcontroller as well as setting some fuses. In my search on how other have done this, I haven't found a lot of sources on lowlevel programming with USB. To help you further along I added loads of comments. 

<br /><br /><!-- spacing for header -->

## My story so far
During my study I did a lot of software engineering but never went further than using arduino's. So my goal was to learn more about hardware. A lot of youtube videos brought me so far. [Ben Eater](https://youtu.be/wdgULBpRoXk) has some great videos explaining the USB protocol. [Mitch Davis](https://youtu.be/Q2DakPocvfs) goes into more detail about programming Atmega microcontrollers.

Using schematics from arduino I was able to create a schematic quite easily. Of course, also looked at the datasheets to have a better understanding.

After creating the [assembly](https://github.com/martijncasteel/launchpad/tree/main/assembly), I uploaded the files to a pcb manufactorer and also let them populate the board. I had some issues with the USB port since the wrong one was in the BOM. Finally I started [coding](https://github.com/martijncasteel/launchpad/tree/main/code), at first with the arduino IDE. But quickly realised that I wanted to do it from scratch. Down the rabbit hole, I went!

<br /><br /><!-- spacing for header -->

## Where I am now
Well, the hardware went back in a drawer, I'm updating my README and that's it I guess. The buttons declared in the normal consumer control are working; volume up/down, and mute. The toggle camera is somewhat working, however teams just freezes the last frame and is not able to recover from it. More about the implementation in the [code](https://github.com/martijncasteel/launchpad/tree/main/code) directory.

![Launchpad photo](https://github.com/martijncasteel/launchpad/blob/main/images/image.jpeg?raw=true)

The buttons for the telephone page; mute microphone and flash are not working. The computer receives the commands fine but not actions is take by the OS or teams. It did cross my mind to implement it as a [generic keyboard](https://github.com/martijncasteel/launchpad/commit/3572334c3c04b70ffb8cd755422ddb2e0c5258f0) and use the teams shortcuts. The whole purpose was to be able to mute microsoft without having it in focus, so I scratched that idea. But it will work