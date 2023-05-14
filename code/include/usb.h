/**
 * @file usb.h
 * @brief Header file containing the USB descriptors
 * 
 * This header file is used to make code more readible and is used
 * for the several descriptors it has to provide.
 * 
 * @author Martijn Casteel
 * @date 2022-12-22
*/

#include <avr/pgmspace.h>

#ifndef USB_H
#define USB_H

/**
 * Struct used to encapsulate in and outgoing report in a single memory 
 * location. See report_descriptor and board.h for mapping. 40 bits long
 * 
 * @param din is used for incoming reports for led status.
 * @param dout holds the report towards the host holding the key presses.
 */
typedef struct Data{
  uint8_t din;
  uint32_t dout;
} data_t;

data_t* usb_init();

int8_t send_pgm_data(uint8_t* descriptor, uint8_t length, uint16_t wLength);
int8_t send_uint16_data(uint16_t* data, uint8_t length, uint16_t wLength);
int8_t send_dout_data(uint32_t* data);

// request types, see table 9-2 of USB2.0 specification
// HOST-TO-DEVICE -> IN, DEVICE-TO-HOST -> OUT
#define DEVICE_IN         0x00
#define DEVICE_OUT        0x80

#define INTERFACE_IN      0x01
#define INTERFACE_OUT     0x81
#define CLASS             0x20
// interface out | class -> 0xa1

// request codes, see table 9-4 of USB2.0 specification
#define GET_STATUS        0x00
#define CLEAR_FEATURE     0x01
#define SET_FEATURE       0x03
#define SET_ADDRESS       0x05
#define GET_DESCRIPTOR    0x06
#define GET_CONFIGURATION 0x08
#define SET_CONFIGURATION 0x09
#define GET_INTERFACE     0x0a
#define SET_INTERFACE     0x0b

// hid class-specific request codes
#define GET_REPORT        0x01
#define GET_IDLE          0x02
#define GET_PROTOCOL      0x03
#define SET_REPORT        0x09
#define SET_IDLE          0x0a
#define SET_PROTOCOL      0x0b

// descriptor types used for descriptors, see table 9-5
#define DEVICE            0x01
#define CONFIGURATION     0x02
#define STRING            0x03
#define INTERFACE         0x04
#define ENDPOINT          0x05
#define QUALIFIER         0x06
#define HID_DESCRIPTOR    0x21
#define REPORT            0x22


#define MANUFACTORER  u"Martijn Casteel"
#define PRODUCTNAME   u"Launchpad"

// microchip does free sublicensing of their VID
#define VENDORID  0x04d8    // Microchip Technology, inc.
#define PRODUCTID 0xe6d5    // Launchpad

// #define VENDORID  0x03eb    // Atmel Corp.
// #define PRODUCTID 0x2ff4    // atmega32u4 DFU bootloader

// #define VENDORID  0x2341    // Arduino LCC
// #define PRODUCTID 0x0037    // Arduino Micro


// max length a packet send to host on config endpoint
#define PACKETSIZE 0x20

// defined length of configuration and report descriptor
#define CONFIG_SIZE 34
#define REPORT_SIZE 89


// Stored in PROGMEM (Program Memory) Flash
static const uint8_t device_descriptor[] PROGMEM = {
  0x12,         // bLength, 18 bytes
  0x01,         // bDescriptorType, device
  0x00, 0x02,   // bcdUSB, 2.0
  0x00,         // bDeviceClasss, HID will specifiy this
  0x00,         // bDeviceSubClass
  0x00,         // bDeviceProtocol
  PACKETSIZE,   // bMaxPacketSize0, 32 bytes
  (VENDORID & 255), ((VENDORID >> 8) & 255), 
  (PRODUCTID & 255), ((PRODUCTID >> 8) & 255), 
  0x00, 0x01,   // bcdDevice, revision 1.0
  0x01,         // iManufacturer string descriptor 
  0x02,         // iProduct string descriptor
  0x00,         // iSerialNumber string descriptor
  0x01          // bNumConfigurations
};


static const uint8_t configuration_descriptor[] PROGMEM = {
  0x09,         // bLength, default configuration descriptor length
  0x02,         // bDescriptorType, configuration
  (CONFIG_SIZE & 255), ((CONFIG_SIZE >> 8) & 255), // wTotalLength
  0x01,         // bNumInterfaces
  0x01,         // bConfigurationValue
  0x00,         // iConfiguration, no string discriptor for this config
  0b10000000,   // bmAttributes
  0x32,         // bMaxPower, 100 mA

  // interface descriptor
  0x09,         // bLength
  0x04,         // bDescriptorType, interface
  0x00,         // bInterfaceNumber
  0x00,         // bAlternateSetting
  0x01,         // bNumEndpoints
  0x03,         // bInterfaceClass, HID class
  0x00,         // bInterfaceSubClass
  0x00,         // bInterfaceProtocol, 1 -> keyboard
  0x00,         // iInterface

  // HID descriptor
  0x09,         // bLength
  0x21,         // bDescriptorType, HID
  0x11, 0x01,   // bcdHID, HID Class Specification 1.11
  0x00,         // bCountryCode
  0x01,         // bNumDescriptors
  0x22,         // bDescriptorType - report
  (REPORT_SIZE & 255), ((REPORT_SIZE >> 8) & 255), // wDescriptorLength

  // endpoint descriptor
  0x07,         // bLength
  0x05,         // bDescriptorType, endpoint
  0x81,         // bEndpointAddress, IN, interrupt
  0x03,         // bmAttributes, interrupt
  0x08, 0x00,   // wMaxPacketSize - The size of the keyboard banks
  0x12          // wInterval, poll every 18 ms
};


/**
 * This is the report descriptor, the message it send is defined here
 * lsb is the first defined. Pretty easy mapping from the PINB register.
 * 
 * see board.h for mapping of buttons and mapping the push-to-talk logic
 * for BTN6 or the first two bits of this report.
 * 
 * @note change REPORT_SIZE if changed
 */
static const uint8_t report_descriptor[] PROGMEM = {
  0x05, 0x01,   // usage page (generic desktop)
  0x09, 0x07,   // usage (keypad)
  0xA1, 0x01,   // collection (application)

  0x05, 0x07,   // usage page (modifier keys)
  0x19, 0xE0,   // usage minimum
  0x29, 0xE7,   // usage maximum
  0x15, 0x01,   // logical minimum
  0x25, 0x01,   // logical maximum
  0x75, 0x01,   // report size 1
  0x95, 0x08,   // report count 8
  0x81, 0x02,   // input (data, var, absolute)

  0x05, 0x07,   // usage page (keycodes)
  0x19, 0x00,   // usage minimum
  0x29, 0x65,   // usage maximum
  0x15, 0x00,   // logical minimum
  0x25, 0x65,   // logical maximum
  0x75, 0x08,   // report size 8
  0x95, 0x02,   // report count 2
  0x81, 0x00,   // input (data, array)

  
  0x05, 0x0c,   // usage Page (consumer)
  0x15, 0x00,   // logical minimum (0)
  0x25, 0x01,   // logical maximum (1)
  0x09, 0xea,   // usage (Volume Decrement, RTC) - BTN3
  0x09, 0xe9,   // usage (Volume Increment, RTC) - BTN2
  0x75, 0x01,   // report size (1)
  0x95, 0x02,   // report count (2)
  0x81, 0x02,   // input (data, var, absolute, preferred state)

  0x75, 0x06,   // report size (6)
  0x95, 0x01,   // report count (1)
  0x91, 0x01,   // output (const, padding)


  0x05, 0x08,   // usage page (Led page)
  0x15, 0x00,   // logical minimum (0)
  0x25, 0x01,   // logical maximum (1)
  0x09, 0x09,   // usage (mute)
  0x09, 0x17,   // usage (off-hook)
  0x09, 0x18,   // usage (ring)
  0x09, 0x20,   // usage (hold)
  0x09, 0x21,   // usage (microphone)
  0x75, 0x01,   // report size (1)
  0x95, 0x01,   // report count (5)
  0x91, 0x22,   // output (data, absolute, no preffered)

  0x75, 0x03,   // report size (3)
  0x95, 0x01,   // report count (1)
  0x91, 0x01,   // output (const, padding)

  0xc0         // end collection
};

#endif