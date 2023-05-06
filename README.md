# push-to-talk
A simple macro keyboard designed for using USB HID protocol. 

My first approach was to use the USB HID protocol in full and specifically the USB HID Telephone pages, unfortantly Microsoft Teams does not support the Telephone page. These pages seem to work with Facetime on an ipad however this is not the intended purpose. The goal is to mute and unmute the microphone on Teams on a laptop, even when teams is not in focus. 

This project directory contains the entire project, [/pcb](/martijncasteel/launchpad/tree/main/pcb) contains the schematics and design of the board. In used [Kicad](https://www.kicad.org/) for this. The gerber files and other nessecities for manufacturing are located in the [/assembly](/martijncasteel/launchpad/tree/main/assembly) folder.

The board is designed to have six regular 1u keycaps, and one 2u keycap. All use a regular cherry mx key switches. The board has a ATmega32u4 with native usb usb support. The ICSP connector can be used to flash the microcontroller. 

![3D render](https://github.com/martijncasteel/launchpad/blob/main/images/3d-front.png?raw=true)

<br /><!-- spacing for header -->

## Different approaches so far
The software is written in C and build using avr-gcc. Using avrdude to flash the microcontroller as well as setting some fuses. There are a few different branches with different approaches. 

> [USB HID Telephone pages](/martijncasteel/launchpad/tree/main) <br />
>The original idea, using USB HID Telephone pages to control the microphone. *This is currently not supported!*

> [USB Keyboard shortcuts](/martijncasteel/launchpad/tree/shortcuts) <br/>
> A workaround using the Teams shortcuts such as the spacebar. This does not meet all requirements.

<br /><br /><!-- spacing for header -->

## The story so far
During my study I did a lot of software engineering but never went further than using arduino's. So my goal was to learn more about hardware. A lot of youtube videos brought me so far. [Ben Eater](https://youtu.be/wdgULBpRoXk) has some great videos explaining the USB protocol. [Mitch Davis](https://youtu.be/Q2DakPocvfs) goes into more detail of programming Atmega microcontrollers.

Using schematics from arduino I was able to create a schematic quite easily. Offcourse also looked at the datasheets to have a better understanding of the crystal setup.

After creating the [assembly](/martijncasteel/launchpad/tree/main/assembly), I uploaded the files to a pcb manufactorer and also let them populate the board. Then finally I started [coding](/martijncasteel/launchpad/tree/main/code), at first with the arduino IDE. But quickly realised that I wanted to do it from scratch. Down the rabbit hole I went!