/**
 * @file usb.c
 * @brief USB controller initialization, sending descriptors, and handle interrupts.
 * 
 * This contains all the logic for creating a usb hid device, the descriptors are 
 * placed in usb.h. At first the init command should be called to initialize the 
 * usb handshake, after that interrupts will be handeld to send data to the host.
 * 
 * @author Martijn Casteel
 * @date 2022-12-22
*/

#include "usb.h"
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>

int8_t configuration;

/**
 * 
 *
int init2() {
  cli();                                  // global interrrupt disabled

  USBCON &= ~(1 << USBE);                 // reset USB controller
  USBCON |= (1 << USBE);

  USBCON &= ~(1 << FRZCLK);               // unfreeze the clock
  UHWCON |= (1 << UVREGE);                // enable USB pads regulator
  // PLLCSR |= (1 << PINDIV) | (1 << PLLE);  // use 16 MHz oscillator

  // while (!(PLLCSR & (1 << PLOCK)))
  //   ;                                     // wait until oscillator is stabilized

  USBCON |= (1 << USBE) | (1 << OTGPADE); // enable USB Controller and power
  UDIEN |= (1 << EORSTE) | (1 << SOFE);   // enable interrupts

  UDCON &= ~(1 << LSM);                   // use full speed mode
  USBCON |= (1 << VBUSTE);                // VBUS interrupt enabled
  UDCON &= ~(1 << DETACH);                // pull D+ high for attaching to host

  configuration = 0;
  
  sei();                                  // globla interrupt enabled
  return 0;
}
 */
int init() {
  cli();                                  // global interrrupt disabled

  UHWCON |= (1 << UVREGE);                // enable USB pads regulator

  PLLCSR |= (1 << PINDIV) | (1 << PLLE);  // use 16 MHz oscillator
  while (!(PLLCSR & (1 << PLOCK)))
    ;                                     // wait until oscillator is stabilized

  USBCON |= (1 << USBE) | (1 << OTGPADE); // enable USB Controller and power
  USBCON &= ~(1 << FRZCLK);               // unfreeze the clock
  
  UDCON &= ~(1 << LSM);                   // use full speed mode
  UDCON &= ~(1 << DETACH);                // pull D+ high for attaching to host

  UDIEN |= (1 << EORSTE) | (1 << SOFE);   // enable interrupts

  configuration = 0;
  
  sei();                                  // global interrupt enabled
  return 0;
}


/**
 * The interrupts of the USB controller are covered here. As soon as the VBUS 
 * interrupt is triggered the PLL is configured. 
 * 
 * Sends the data buffer based on actual state of the pressed buttons.
 * Within USB the host starts all communication, this interrupt will do
 * just that. After sending data buffer is cleared.
 * 
 */
ISR(USB_GEN_vect){

  // /**
  //  * VBUS interrupt is performed when connecting to the device
  //  */
  // if (USBINT & (1 << VBUSTI)) {           // VBUS interrupt is active
  //   USBINT &= ~(1 << VBUSTI);             // clear interrupt flag
  //   if (USBSTA & (1 << VBUS)){            // check if device is connected
  //     PLLCSR |= (1 << PINDIV) |           // use 16 MHz oscillator
  //       (1 << PLLE);                      // enable PLL upscaler

  //     while (!(PLLCSR & (1 << PLOCK)))    // wait until stabilized
  //       ;

  //     // device is powered!
  //     UDIEN |= (1 << EORSTE) | (1 << SOFE);   // enable end of reset interrupt
      
  //   } else {
  //     // device is unattached
  //     PLLCSR = 0x00;

  //   }
  // }


  uint8_t udint = UDINT;                   // read register once
  UDINT = 0;                               // TODO clear interrupts
  
  /**
   * End of reset interupt
   */
  if (udint & (1 << EORSTI)) {
    UDINT &= ~(1 << EORSTI);              // reset configuration version

    UENUM = 0x00;                            // select endpoint 0
    UECONX = (1 << EPEN);                 // enable the endpoint
    UECFG0X = 0; //&= ~(1 << EPDIR);             // OUT endpoint
    UECFG1X |= (1 << EPSIZE1) |           // 32 bytes endpoint
      (1 << ALLOC);                       // allocate it
    
    configuration = 0;      

    if (!(UESTA0X & (1 << CFGOK)))
      return;                             // UECFG1X should be reprogrammed
    
    UERST = 0x01;                         // reset endpoint
    UERST = 0x00;

    UEIENX = (1 << RXSTPE);               // enable receive setup packet interrupt
    return;
  }
  

  /**
   * Start of frame interrupt if usb is configured correctly.
   */
  if (configuration && (udint & (1 << SOFI))){ 
    UDINT &= ~(1 << SOFI);                // clear interrupt flag
    UENUM = 0x01;                         // endpoint #1 for reports

    if (UEINTX & (1 << RWAL)) {           // check if banks are writeable
      UEDATX = 0x00;                      // create report

      // UEINTX = 0b00111010; // TODO is this correct? 
      UEINTX = (1 << RWAL) | (1 << NAKOUTI) | (1 << RXSTPI);
    }

    return;
  }
}


/**
 * USB communication request, used for setting up the handshake. Either a request
 * for (1) setting the address, (2) device descriptor, (3) string descriptors,
 * (4) configuration descriptor having a reference to an interface descriptor, 
 * a HID descriptor, and an endpoint descriptor.
 * 
 * After setting up the device and configuration, the interface (5) will be 
 * specified using the interface as recipient and using a report descriptor.
 * 
 *  
 */
ISR(USB_COM_vect) {
  UENUM = 0; // endpoint number is 0, 0 is the default configuration endpoint

  // USB endpoint interrupt and setup interrupt flag, setup interrupt flag is set
  // for every message the host initiates. Setup contains requesttype, request, 
  // value, index, and length.
  if (UEINTX & (1 << RXSTPI)) {  

    // UADATX reads data byte for byte, see table 9-2 of USB2.0 spec
    // decoding the setup package below.
    uint8_t bmRequestType = UEDATX;
    uint8_t bRequest = UEDATX;

    uint16_t wValue = UEDATX;
    wValue |= UEDATX << 8;
      
    uint16_t wIndex = UEDATX;
    wIndex |= UEDATX << 8;

    // wlenght is the expected length of the responce for this request
    uint16_t wLength = UEDATX; 
    wLength |= UEDATX << 8;
  
    // Clear the interrupts, ensure to do this after reading UEDATX since they 
    // will be cleared. received setup interrupt flag, received out data interrupt 
    // flag, ready interrupt flag
    UEINTX &= ~((1 << RXSTPI) | (1 << RXOUTI) | (1 << TXINI)); 


    // SET_ADDRESS for this device
    if (bRequest == SET_ADDRESS) {

      UEINTX &= ~(1 << TXINI);
      while (!(UEINTX & (1 << TXINI)))
        ;  // Wait until the banks are ready

      UDADDR = wValue | (1 << ADDEN);  // Set the device address
      return;
    } 
    

    // GET_DESCRIPTOR for a specified report
    if (bRequest == GET_DESCRIPTOR) {

      // get type and index from value
      uint8_t type = (wValue >> 8);
      uint8_t index = wValue; 

      // request device descriptor, only one present
      if(type == DEVICE) {
        send_pgm_data(device_descriptor, pgm_read_byte(device_descriptor), wLength);
        return;

      } else if (type == QUALIFIER){
        // request error USB2.0 9.6.2, we only need full-speed
        UECONX |= (1 << STALLRQ) | (1 << EPEN);
        return;

      } else if (type == CONFIGURATION) {
        send_pgm_data(configuration_descriptor, CONFIG_SIZE, wLength);
        return;

      } else if (type == HID_DESCRIPTOR) {
        // offset used to retrieve the hid descriptor part from the config descriptor
        const uint8_t* hid_descriptor = configuration_descriptor + 18;
        send_pgm_data(hid_descriptor, pgm_read_byte(hid_descriptor), wLength);
        return;

      } else if (type == REPORT) {
        send_pgm_data(report_descriptor, REPORT_SIZE, wLength);
        return;

      } else if (type == STRING) {

        if (index == 0) {         // return language code

        }else if (index == 1){    // iManufacturer string descriptor

          uint16_t manufactorer[] = MANUFACTORER;
          send_raw_data(manufactorer, sizeof(manufactorer) - 1, wLength);
          return;

        } else if (index == 2){   // iProduct string descriptor

          uint16_t name[] = PRODUCTNAME;
          send_raw_data(name, sizeof(name) - 1, wLength);
          return;
      
        }
      }

      // host made an invalid request, stall
      UECONX |= (1 << STALLRQ) | (1 << EPEN);
      return;
    }


    if (bRequest == SET_CONFIGURATION && bmRequestType == 0x00) {
      configuration = wValue;

      UEINTX &= ~(1 << TXINI);

      UENUM = 0x01;
      UECONX = (1 << EPEN);

      UECFG0X |= (1 << EPDIR) |           // IN endpoint
        (1 << EPTYPE1) | (1 << EPTYPE0);  // interrupt endpoint
      UECFG1X |= (1 << EPBK0) |           // double bank
        (1 << ALLOC);                     // allocate 8 bytes

      UERST = 0x1E;                       // reset all endpoints
      UERST = 0;

      return;
    }

    if (bRequest == GET_CONFIGURATION && bmRequestType == 0x80) {
      // Wait for banks to be ready for data transmission
      while (!(UEINTX & (1 << TXINI)))
        ;  

      UEDATX = configuration;             // send current configuration value
      UEINTX &= ~(1 << TXINI);

      return;
    }


    if (bRequest == GET_STATUS) {
      while (!(UEINTX & (1 << TXINI)))
        ;
      UEDATX = 0;
      UEDATX = 0;
      UEINTX &= ~(1 << TXINI);
      return;
    }
  }
}


/**
 * Sends descriptors stored in PROGMEM (program memory)
 * 
 * @param descriptor pointer to PROGMEM data
 * @param length number of bytes
 * @param wLength requested length from host
 */
int send_pgm_data(uint8_t* descriptor, uint8_t length, uint8_t wLength) {
  uint8_t* data = descriptor;
  uint8_t lbyte = length > wLength ? wLength : length; // only send what is asked for

  while (lbyte > 0) {

    // Wait for banks to be ready for data transmission
    while (!(UEINTX & (1 << TXINI)))
      ;
    
    if (UEINTX & (1 << RXOUTI))
      return;  // If there is another packet, exit to handle it

    // split it up in packages
    uint8_t packet = lbyte > PACKETSIZE ? PACKETSIZE: lbyte; 

    for (int i = 0; i < packet; i++) {
      // data is stored in flash so read using pgm_read_byte
      UEDATX = pgm_read_byte(data + i);
    }

    lbyte -= packet;
    data += packet; // move pointer
    UEINTX &= ~(1 << TXINI);
  }

  return;
}


/**
 * Send raw data in *one* packet with the string descriptor, could be 
 * expanded. Current implementation allows reports up to PACKETSIZE
 * bytes.
 * 
 * @param data pointer to actual data 
 * @param length number of bytes
 * @param wLength requested length from host
*/
int send_raw_data(uint16_t* data, uint8_t length, uint8_t wLength) {
  uint16_t* d = data;
  uint8_t lbyte = (length * 2 + 2) > wLength ? wLength : (length * 2 + 2);
  uint8_t lchar = (lbyte - 2) / 2;

  // Wait for banks to be ready for data transmission
  while (!(UEINTX & (1 << TXINI)))
    ;

  if (UEINTX & (1 << RXOUTI))
    return;  // If there is another packet, exit to handle it

  UEDATX = lbyte;
  UEDATX = (uint8_t)0x03; // string descriptor

  for (int i = 0; i < lchar; i++) {
    uint16_t character = (uint16_t)(d + i); // two byte unicode

    UEDATX = (uint8_t)(character & 255);
    UEDATX = (uint8_t)(character >> 8) & 255;
  }

  UEINTX &= ~(1 << TXINI);
  return;
}