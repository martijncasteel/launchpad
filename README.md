# push-to-talk
A simple macro keyboard designed for using USB HID protocol. 

My first approach was to use the USB HID protocol in full and specifically the USB HID Telephone pages, unfortunately, Microsoft Teams does not support the Telephone page. These pages seem to work with Facetime on an iPad however this is not the intended purpose. The goal is to mute and unmute the microphone on Teams on a laptop, even when teams is not in focus. 

This project directory contains the entire project, [/pcb](/martijncasteel/launchpad/tree/main/pcb) contains the schematics and design of the board. In used [Kicad](https://www.kicad.org/) for this. The gerber files and other nessecities for manufacturing are located in the [/assembly](/martijncasteel/launchpad/tree/main/assembly) folder.

The board is designed to have six regular 1u keycaps, and one 2u keycap. All use regular cherry mx key switches. The board has an ATmega32u4 with native usb support. The ICSP connector can be used to flash the microcontroller. 

![3D render](https://github.com/martijncasteel/launchpad/blob/main/images/3d-front.png?raw=true)

The [software](/martijncasteel/launchpad/tree/main/code) is written in C and built using avr-gcc. Using avrdude to flash the microcontroller as well as setting some fuses. In my search on how other have done this, I haven't found a lot of sources. To help you further along I added loads of comments. 

<br /><br /><!-- spacing for header -->

## The story so far
During my study I did a lot of software engineering but never went further than using arduino's. So my goal was to learn more about hardware. A lot of youtube videos brought me so far. [Ben Eater](https://youtu.be/wdgULBpRoXk) has some great videos explaining the USB protocol. [Mitch Davis](https://youtu.be/Q2DakPocvfs) goes into more detail about programming Atmega microcontrollers.

Using schematics from arduino I was able to create a schematic quite easily. Of course, also looked at the datasheets to have a better understanding.

After creating the [assembly](/martijncasteel/launchpad/tree/main/assembly), I uploaded the files to a pcb manufactorer and also let them populate the board. I had some issues with the USB port since the wrong one was in the BOM. Finally I started [coding](/martijncasteel/launchpad/tree/main/code), at first with the arduino IDE. But quickly realised that I wanted to do it from scratch. Down the rabbit hole, I went!