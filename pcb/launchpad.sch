EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "launchpad"
Date "2021-03-21"
Rev "1.0"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MCU_Microchip_ATmega:ATmega32U4-MU U1
U 1 1 604E5D6A
P 2750 4800
F 0 "U1" H 3200 6550 50  0000 C CNN
F 1 "ATmega32U4-MUR" H 3150 3050 50  0000 C CNN
F 2 "Package_DFN_QFN:QFN-44-1EP_7x7mm_P0.5mm_EP5.2x5.2mm" H 2750 4800 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7766-8-bit-AVR-ATmega16U4-32U4_Datasheet.pdf" H 2750 4800 50  0001 C CNN
F 4 "C45874" H 2750 4800 50  0001 C CNN "LCSC Part #"
F 5 "C45874" H 2750 4800 50  0001 C CNN "LCSC"
	1    2750 4800
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x03_Odd_Even J2
U 1 1 604E7E64
P 5450 3900
F 0 "J2" H 5550 4100 50  0000 C CNN
F 1 "ICSP" H 5500 3700 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x03_P2.54mm_Vertical" H 5450 3900 50  0001 C CNN
F 3 "~" H 5450 3900 50  0001 C CNN
	1    5450 3900
	1    0    0    -1  
$EndComp
$Comp
L CherryMX:CherryMX SW0
U 1 1 604E8A0D
P 7750 4900
F 0 "SW0" V 7796 4852 50  0000 R CNN
F 1 "CherryMX" V 7705 4852 50  0000 R CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX_1.00u_PCB" H 7750 4925 50  0001 C CNN
F 3 "" H 7750 4925 50  0001 C CNN
	1    7750 4900
	0    1    1    0   
$EndComp
Text GLabel 1750 4300 0    50   Input ~ 0
USB_D+
Text GLabel 1750 4400 0    50   Input ~ 0
USB_D-
$Comp
L Device:R_Small R2
U 1 1 604E9E7C
P 1950 4300
F 0 "R2" V 2000 4200 50  0000 C CNN
F 1 "22" V 2000 4450 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 1950 4300 50  0001 C CNN
F 3 "~" H 1950 4300 50  0001 C CNN
F 4 "C23345" H 1950 4300 50  0001 C CNN "LCSC"
	1    1950 4300
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R3
U 1 1 604EA8D4
P 1950 4400
F 0 "R3" V 2000 4300 50  0000 C CNN
F 1 "22" V 2000 4550 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 1950 4400 50  0001 C CNN
F 3 "~" H 1950 4400 50  0001 C CNN
F 4 "C23345" H 1950 4400 50  0001 C CNN "LCSC"
	1    1950 4400
	0    1    1    0   
$EndComp
Wire Wire Line
	2150 4400 2050 4400
Wire Wire Line
	1850 4400 1750 4400
Wire Wire Line
	1750 4300 1850 4300
Wire Wire Line
	2050 4300 2150 4300
Text GLabel 2150 3500 0    50   Input ~ 0
HSE_IN
Text GLabel 2150 3700 0    50   Input ~ 0
HSE_OUT
$Comp
L Device:C_Small C2
U 1 1 604F0E7A
P 1950 4600
F 0 "C2" V 1900 4500 50  0000 C CNN
F 1 "1uF" V 2000 4500 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 1950 4600 50  0001 C CNN
F 3 "~" H 1950 4600 50  0001 C CNN
F 4 "C15849" H 1950 4600 50  0001 C CNN "LCSC"
	1    1950 4600
	0    1    1    0   
$EndComp
Wire Wire Line
	2050 4600 2150 4600
Wire Wire Line
	2150 3900 2050 3900
$Comp
L power:GND #PWR0101
U 1 1 604F34E1
P 1250 4850
F 0 "#PWR0101" H 1250 4600 50  0001 C CNN
F 1 "GND" H 1255 4677 50  0000 C CNN
F 2 "" H 1250 4850 50  0001 C CNN
F 3 "" H 1250 4850 50  0001 C CNN
	1    1250 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	1850 4600 1250 4600
Wire Wire Line
	1250 4600 1250 4850
Wire Wire Line
	1850 3900 1250 3900
Wire Wire Line
	1250 3900 1250 4600
Connection ~ 1250 4600
Text GLabel 3350 3400 2    50   Input ~ 0
SCLK
Text GLabel 3350 3500 2    50   Input ~ 0
MOSI
Text GLabel 3350 3600 2    50   Input ~ 0
MISO
Text GLabel 3350 5100 2    50   Input ~ 0
BTN0
Text GLabel 3350 5200 2    50   Input ~ 0
BTN1
Text GLabel 3350 5000 2    50   Input ~ 0
BTN2
Text GLabel 3350 4900 2    50   Input ~ 0
BTN3
Text GLabel 3350 4700 2    50   Input ~ 0
BTN4
Text GLabel 3350 4800 2    50   Input ~ 0
BTN5
Text GLabel 3350 4600 2    50   Input ~ 0
BTN6
$Comp
L Device:R_Small R4
U 1 1 604F4947
P 3500 5400
F 0 "R4" V 3600 5400 50  0000 C CNN
F 1 "10K" V 3400 5400 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 3500 5400 50  0001 C CNN
F 3 "~" H 3500 5400 50  0001 C CNN
F 4 "C25804" H 3500 5400 50  0001 C CNN "LCSC"
	1    3500 5400
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 604F719A
P 2700 6700
F 0 "#PWR0102" H 2700 6450 50  0001 C CNN
F 1 "GND" H 2705 6527 50  0000 C CNN
F 2 "" H 2700 6700 50  0001 C CNN
F 3 "" H 2700 6700 50  0001 C CNN
	1    2700 6700
	1    0    0    -1  
$EndComp
Wire Wire Line
	2650 6600 2650 6650
Wire Wire Line
	2650 6650 2700 6650
Wire Wire Line
	2750 6650 2750 6600
Wire Wire Line
	2700 6650 2700 6700
Connection ~ 2700 6650
Wire Wire Line
	2700 6650 2750 6650
Text GLabel 1750 3300 0    50   Input ~ 0
RESET
$Comp
L Device:R_Small R1
U 1 1 604FC317
P 1950 3050
F 0 "R1" H 2009 3096 50  0000 L CNN
F 1 "10K" H 2009 3005 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 1950 3050 50  0001 C CNN
F 3 "~" H 1950 3050 50  0001 C CNN
F 4 "C25804" H 1950 3050 50  0001 C CNN "LCSC"
	1    1950 3050
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0103
U 1 1 604FEAD4
P 1950 2800
F 0 "#PWR0103" H 1950 2650 50  0001 C CNN
F 1 "+5V" H 1965 2973 50  0000 C CNN
F 2 "" H 1950 2800 50  0001 C CNN
F 3 "" H 1950 2800 50  0001 C CNN
	1    1950 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	1950 3300 2150 3300
Wire Wire Line
	3650 6250 3650 6200
Wire Wire Line
	3650 5950 3650 6000
$Comp
L power:GND #PWR0104
U 1 1 604EE3C5
P 3650 6250
F 0 "#PWR0104" H 3650 6000 50  0001 C CNN
F 1 "GND" H 3655 6077 50  0000 C CNN
F 2 "" H 3650 6250 50  0001 C CNN
F 3 "" H 3650 6250 50  0001 C CNN
	1    3650 6250
	1    0    0    -1  
$EndComp
$Comp
L Device:LED_Small D2
U 1 1 604EB1C3
P 3650 6100
F 0 "D2" V 3696 6030 50  0000 R CNN
F 1 "RED" V 3605 6030 50  0000 R CNN
F 2 "LED_SMD:LED_0603_1608Metric" V 3650 6100 50  0001 C CNN
F 3 "~" V 3650 6100 50  0001 C CNN
F 4 "C2286" H 3650 6100 50  0001 C CNN "LCSC"
	1    3650 6100
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_Small R5
U 1 1 604ED075
P 3650 5850
F 0 "R5" H 3709 5896 50  0000 L CNN
F 1 "1K" H 3709 5805 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 3650 5850 50  0001 C CNN
F 3 "~" H 3650 5850 50  0001 C CNN
F 4 "C21190" H 3650 5850 50  0001 C CNN "LCSC"
	1    3650 5850
	1    0    0    -1  
$EndComp
Wire Wire Line
	3650 5700 3650 5750
Wire Wire Line
	3350 5700 3650 5700
$Comp
L power:GND #PWR0105
U 1 1 60509124
P 3650 5450
F 0 "#PWR0105" H 3650 5200 50  0001 C CNN
F 1 "GND" H 3655 5277 50  0000 C CNN
F 2 "" H 3650 5450 50  0001 C CNN
F 3 "" H 3650 5450 50  0001 C CNN
	1    3650 5450
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 5400 3350 5400
Wire Wire Line
	3600 5400 3650 5400
Wire Wire Line
	3650 5400 3650 5450
NoConn ~ 3350 3300
NoConn ~ 3350 3700
NoConn ~ 3350 3800
NoConn ~ 3350 3900
NoConn ~ 3350 4000
NoConn ~ 3350 4200
NoConn ~ 3350 4300
NoConn ~ 3350 5500
NoConn ~ 3350 4500
NoConn ~ 3350 5800
NoConn ~ 3350 5900
NoConn ~ 3350 6000
NoConn ~ 3350 6100
NoConn ~ 3350 6200
Text GLabel 5250 3900 0    50   Input ~ 0
SCLK
Text GLabel 5750 3900 2    50   Input ~ 0
MOSI
Text GLabel 5250 3800 0    50   Input ~ 0
MISO
Text GLabel 5250 4000 0    50   Input ~ 0
RESET
$Comp
L power:GND #PWR0106
U 1 1 60510144
P 5800 4050
F 0 "#PWR0106" H 5800 3800 50  0001 C CNN
F 1 "GND" H 5805 3877 50  0000 C CNN
F 2 "" H 5800 4050 50  0001 C CNN
F 3 "" H 5800 4050 50  0001 C CNN
	1    5800 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	5750 4000 5800 4000
Wire Wire Line
	5800 4000 5800 4050
Text GLabel 8000 2050 0    50   Input ~ 0
USB_D+
Text GLabel 8000 2150 0    50   Input ~ 0
USB_D-
Text GLabel 9400 2150 2    50   Input ~ 0
USB_D-
Text GLabel 9400 2250 2    50   Input ~ 0
USB_D+
NoConn ~ 8000 2250
NoConn ~ 9400 2050
$Comp
L power:GND #PWR0107
U 1 1 605123A1
P 7550 2300
F 0 "#PWR0107" H 7550 2050 50  0001 C CNN
F 1 "GND" H 7555 2127 50  0000 C CNN
F 2 "" H 7550 2300 50  0001 C CNN
F 3 "" H 7550 2300 50  0001 C CNN
	1    7550 2300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0108
U 1 1 605127B2
P 9950 3100
F 0 "#PWR0108" H 9950 2850 50  0001 C CNN
F 1 "GND" H 9955 2927 50  0000 C CNN
F 2 "" H 9950 3100 50  0001 C CNN
F 3 "" H 9950 3100 50  0001 C CNN
	1    9950 3100
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R6
U 1 1 60513034
P 7550 2100
F 0 "R6" H 7609 2146 50  0000 L CNN
F 1 "5.1K" H 7609 2055 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 7550 2100 50  0001 C CNN
F 3 "~" H 7550 2100 50  0001 C CNN
F 4 "C23186" H 7550 2100 50  0001 C CNN "LCSC"
	1    7550 2100
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R7
U 1 1 605178D0
P 9700 2350
F 0 "R7" V 9800 2250 50  0000 C CNN
F 1 "5.1K" V 9800 2450 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 9700 2350 50  0001 C CNN
F 3 "~" H 9700 2350 50  0001 C CNN
F 4 "C23186" H 9700 2350 50  0001 C CNN "LCSC"
	1    9700 2350
	0    1    1    0   
$EndComp
Wire Wire Line
	9400 2350 9600 2350
Wire Wire Line
	9800 2350 9950 2350
Wire Wire Line
	9400 2550 9500 2550
Wire Wire Line
	9500 2550 9500 2650
Wire Wire Line
	9500 2850 9400 2850
Wire Wire Line
	9400 2750 9500 2750
Connection ~ 9500 2750
Wire Wire Line
	9500 2750 9500 2850
Wire Wire Line
	9500 2650 9400 2650
Connection ~ 9500 2650
Wire Wire Line
	9400 2950 9500 2950
Wire Wire Line
	9400 3050 9500 3050
Wire Wire Line
	9500 3050 9500 2950
Wire Wire Line
	8000 1950 7550 1950
$Comp
L Device:Fuse_Small F1
U 1 1 6052A2AF
P 9700 1750
F 0 "F1" H 9700 1650 50  0000 C CNN
F 1 "500mA" H 9700 1850 50  0000 C CNN
F 2 "Fuse:Fuse_0603_1608Metric" H 9700 1750 50  0001 C CNN
F 3 "~" H 9700 1750 50  0001 C CNN
F 4 "C261937" H 9700 1750 50  0001 C CNN "LCSC"
	1    9700 1750
	-1   0    0    1   
$EndComp
$Comp
L power:+5V #PWR0111
U 1 1 6052C012
P 9950 1500
F 0 "#PWR0111" H 9950 1350 50  0001 C CNN
F 1 "+5V" H 9965 1673 50  0000 C CNN
F 2 "" H 9950 1500 50  0001 C CNN
F 3 "" H 9950 1500 50  0001 C CNN
	1    9950 1500
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0112
U 1 1 60532E2F
P 2750 2800
F 0 "#PWR0112" H 2750 2650 50  0001 C CNN
F 1 "+5V" H 2765 2973 50  0000 C CNN
F 2 "" H 2750 2800 50  0001 C CNN
F 3 "" H 2750 2800 50  0001 C CNN
	1    2750 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	2650 2900 2750 2900
Wire Wire Line
	2850 2900 2850 3000
Wire Wire Line
	2650 2900 2650 3000
Wire Wire Line
	2750 3000 2750 2900
Connection ~ 2750 2900
Wire Wire Line
	2750 2900 2850 2900
Wire Wire Line
	2750 2800 2750 2900
$Comp
L power:+5V #PWR0113
U 1 1 6053BEBC
P 2250 1200
F 0 "#PWR0113" H 2250 1050 50  0001 C CNN
F 1 "+5V" H 2265 1373 50  0000 C CNN
F 2 "" H 2250 1200 50  0001 C CNN
F 3 "" H 2250 1200 50  0001 C CNN
	1    2250 1200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0114
U 1 1 6053C357
P 2250 1950
F 0 "#PWR0114" H 2250 1700 50  0001 C CNN
F 1 "GND" H 2255 1777 50  0000 C CNN
F 2 "" H 2250 1950 50  0001 C CNN
F 3 "" H 2250 1950 50  0001 C CNN
	1    2250 1950
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C3
U 1 1 6053CC31
P 1450 1550
F 0 "C3" H 1542 1596 50  0000 L CNN
F 1 "0.1uF" H 1542 1505 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 1450 1550 50  0001 C CNN
F 3 "~" H 1450 1550 50  0001 C CNN
F 4 "C14663" H 1450 1550 50  0001 C CNN "LCSC"
	1    1450 1550
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C7
U 1 1 6053D4BC
P 3050 1550
F 0 "C7" H 3142 1596 50  0000 L CNN
F 1 "10uF" H 3142 1505 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 3050 1550 50  0001 C CNN
F 3 "~" H 3050 1550 50  0001 C CNN
F 4 "C19702 " H 3050 1550 50  0001 C CNN "LCSC"
	1    3050 1550
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C4
U 1 1 6053DF51
P 1850 1550
F 0 "C4" H 1942 1596 50  0000 L CNN
F 1 "0.1uF" H 1942 1505 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 1850 1550 50  0001 C CNN
F 3 "~" H 1850 1550 50  0001 C CNN
F 4 "C14663" H 1850 1550 50  0001 C CNN "LCSC"
	1    1850 1550
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C6
U 1 1 6053E1FB
P 2650 1550
F 0 "C6" H 2742 1596 50  0000 L CNN
F 1 "0.1uF" H 2742 1505 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 2650 1550 50  0001 C CNN
F 3 "~" H 2650 1550 50  0001 C CNN
F 4 "C14663" H 2650 1550 50  0001 C CNN "LCSC"
	1    2650 1550
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C5
U 1 1 6053E48A
P 2250 1550
F 0 "C5" H 2342 1596 50  0000 L CNN
F 1 "0.1uF" H 2342 1505 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 2250 1550 50  0001 C CNN
F 3 "~" H 2250 1550 50  0001 C CNN
F 4 "C14663" H 2250 1550 50  0001 C CNN "LCSC"
	1    2250 1550
	1    0    0    -1  
$EndComp
Wire Wire Line
	1450 1450 1450 1350
Wire Wire Line
	1450 1350 1850 1350
Wire Wire Line
	3050 1350 3050 1450
Wire Wire Line
	2250 1450 2250 1350
Connection ~ 2250 1350
Wire Wire Line
	2250 1350 2650 1350
Wire Wire Line
	2250 1200 2250 1350
Wire Wire Line
	1850 1450 1850 1350
Connection ~ 1850 1350
Wire Wire Line
	1850 1350 2250 1350
Wire Wire Line
	2650 1450 2650 1350
Connection ~ 2650 1350
Wire Wire Line
	2650 1350 3050 1350
Wire Wire Line
	1450 1650 1450 1800
Wire Wire Line
	1450 1800 1850 1800
Wire Wire Line
	3050 1800 3050 1650
Wire Wire Line
	2650 1650 2650 1800
Connection ~ 2650 1800
Wire Wire Line
	2650 1800 3050 1800
Wire Wire Line
	2250 1650 2250 1800
Connection ~ 2250 1800
Wire Wire Line
	2250 1800 2650 1800
Wire Wire Line
	1850 1650 1850 1800
Connection ~ 1850 1800
Wire Wire Line
	1850 1800 2250 1800
Wire Wire Line
	2250 1950 2250 1800
$Comp
L Device:Crystal_GND24_Small Y1
U 1 1 6058336E
P 5500 5750
F 0 "Y1" H 5550 5900 50  0000 L CNN
F 1 "Crystal_GND24_Small" H 5600 5100 50  0000 L CNN
F 2 "Crystal:Crystal_SMD_3225-4Pin_3.2x2.5mm" H 5500 5750 50  0001 C CNN
F 3 "~" H 5500 5750 50  0001 C CNN
F 4 "C13738" H 5500 5750 50  0001 C CNN "LCSC"
	1    5500 5750
	1    0    0    -1  
$EndComp
Text GLabel 5150 5500 1    50   Input ~ 0
HSE_IN
Text GLabel 5850 5500 1    50   Input ~ 0
HSE_OUT
$Comp
L Device:C_Small C8
U 1 1 6058547C
P 5150 6050
F 0 "C8" H 5000 6000 50  0000 C CNN
F 1 "22pF" H 4950 6100 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 5150 6050 50  0001 C CNN
F 3 "~" H 5150 6050 50  0001 C CNN
F 4 "C1653" H 5150 6050 50  0001 C CNN "LCSC"
	1    5150 6050
	-1   0    0    1   
$EndComp
$Comp
L Device:C_Small C9
U 1 1 60585CD9
P 5850 6050
F 0 "C9" H 5700 6000 50  0000 C CNN
F 1 "22pF" H 5650 6100 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 5850 6050 50  0001 C CNN
F 3 "~" H 5850 6050 50  0001 C CNN
F 4 "C1653" H 5850 6050 50  0001 C CNN "LCSC"
	1    5850 6050
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR0115
U 1 1 60586037
P 5500 6500
F 0 "#PWR0115" H 5500 6250 50  0001 C CNN
F 1 "GND" H 5505 6327 50  0000 C CNN
F 2 "" H 5500 6500 50  0001 C CNN
F 3 "" H 5500 6500 50  0001 C CNN
	1    5500 6500
	1    0    0    -1  
$EndComp
Wire Wire Line
	5150 6150 5150 6350
Wire Wire Line
	5850 6350 5850 6150
Wire Wire Line
	5500 5650 5500 5550
Wire Wire Line
	5500 5550 5350 5550
Wire Wire Line
	5350 5550 5350 5950
Wire Wire Line
	5350 5950 5500 5950
Connection ~ 5500 5950
Wire Wire Line
	5500 5950 5500 5850
Wire Wire Line
	5400 5750 5150 5750
Wire Wire Line
	5150 5750 5150 5950
Wire Wire Line
	5600 5750 5850 5750
Wire Wire Line
	5850 5750 5850 5950
Wire Wire Line
	5500 5950 5500 6350
Wire Wire Line
	5150 6350 5500 6350
Connection ~ 5500 6350
Wire Wire Line
	5500 6350 5500 6500
Wire Wire Line
	5500 6350 5850 6350
Wire Wire Line
	5150 5500 5150 5750
Connection ~ 5150 5750
Wire Wire Line
	5850 5500 5850 5750
Connection ~ 5850 5750
Text GLabel 7650 4600 0    50   Input ~ 0
BTN0
Wire Wire Line
	7750 4700 7750 4600
Wire Wire Line
	7750 4600 7650 4600
Wire Wire Line
	7750 5200 7750 5100
$Comp
L CherryMX:CherryMX SW4
U 1 1 605FAFFD
P 9050 4900
F 0 "SW4" V 9096 4852 50  0000 R CNN
F 1 "CherryMX" V 9005 4852 50  0000 R CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX_1.00u_PCB" H 9050 4925 50  0001 C CNN
F 3 "" H 9050 4925 50  0001 C CNN
	1    9050 4900
	0    1    1    0   
$EndComp
Text GLabel 8950 4600 0    50   Input ~ 0
BTN4
Wire Wire Line
	9050 4700 9050 4600
Wire Wire Line
	9050 4600 8950 4600
Wire Wire Line
	9050 5200 9050 5100
$Comp
L CherryMX:CherryMX SW6
U 1 1 605FB00D
P 9700 4900
F 0 "SW6" V 9746 4852 50  0000 R CNN
F 1 "CherryMX" V 9655 4852 50  0000 R CNN
F 2 "Custom:SW_Cherry_MX_2.00u_Vertical_PCB_unsupported" H 9700 4925 50  0001 C CNN
F 3 "" H 9700 4925 50  0001 C CNN
	1    9700 4900
	0    1    1    0   
$EndComp
Text GLabel 9600 4600 0    50   Input ~ 0
BTN6
Wire Wire Line
	9700 4700 9700 4600
Wire Wire Line
	9700 4600 9600 4600
Wire Wire Line
	9700 5200 9700 5100
$Comp
L CherryMX:CherryMX SW1
U 1 1 606006A4
P 7750 5850
F 0 "SW1" V 7796 5802 50  0000 R CNN
F 1 "CherryMX" V 7705 5802 50  0000 R CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX_1.00u_PCB" H 7750 5875 50  0001 C CNN
F 3 "" H 7750 5875 50  0001 C CNN
	1    7750 5850
	0    1    1    0   
$EndComp
Text GLabel 7650 5550 0    50   Input ~ 0
BTN1
Wire Wire Line
	7750 5650 7750 5550
Wire Wire Line
	7750 5550 7650 5550
Wire Wire Line
	7750 6150 7750 6050
$Comp
L CherryMX:CherryMX SW3
U 1 1 606006B4
P 8400 5850
F 0 "SW3" V 8446 5802 50  0000 R CNN
F 1 "CherryMX" V 8355 5802 50  0000 R CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX_1.00u_PCB" H 8400 5875 50  0001 C CNN
F 3 "" H 8400 5875 50  0001 C CNN
	1    8400 5850
	0    1    1    0   
$EndComp
Text GLabel 8300 5550 0    50   Input ~ 0
BTN3
Wire Wire Line
	8400 5650 8400 5550
Wire Wire Line
	8400 5550 8300 5550
Wire Wire Line
	8400 6150 8400 6050
$Comp
L CherryMX:CherryMX SW5
U 1 1 606006C4
P 9050 5850
F 0 "SW5" V 9096 5802 50  0000 R CNN
F 1 "CherryMX" V 9005 5802 50  0000 R CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX_1.00u_PCB" H 9050 5875 50  0001 C CNN
F 3 "" H 9050 5875 50  0001 C CNN
	1    9050 5850
	0    1    1    0   
$EndComp
Text GLabel 8950 5550 0    50   Input ~ 0
BTN5
Wire Wire Line
	9050 5650 9050 5550
Wire Wire Line
	9050 5550 8950 5550
Wire Wire Line
	9050 6150 9050 6050
$Comp
L power:+5V #PWR0123
U 1 1 60606693
P 5800 3750
F 0 "#PWR0123" H 5800 3600 50  0001 C CNN
F 1 "+5V" H 5815 3923 50  0000 C CNN
F 2 "" H 5800 3750 50  0001 C CNN
F 3 "" H 5800 3750 50  0001 C CNN
	1    5800 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	5800 3750 5800 3800
Wire Wire Line
	5800 3800 5750 3800
$Comp
L power:+5V #PWR0124
U 1 1 6060CCFC
P 2100 4050
F 0 "#PWR0124" H 2100 3900 50  0001 C CNN
F 1 "+5V" H 2000 4000 50  0000 C CNN
F 2 "" H 2100 4050 50  0001 C CNN
F 3 "" H 2100 4050 50  0001 C CNN
	1    2100 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	2100 4050 2100 4100
Wire Wire Line
	2100 4100 2150 4100
Wire Wire Line
	9950 1500 9950 1750
Wire Wire Line
	9950 1750 9800 1750
Wire Wire Line
	9400 1750 9500 1750
Wire Wire Line
	9400 1850 9500 1850
Wire Wire Line
	9500 1850 9500 1750
Connection ~ 9500 1750
Wire Wire Line
	9500 1750 9600 1750
Wire Wire Line
	1750 3300 1950 3300
Connection ~ 1950 3300
Text Label 9450 1750 0    50   ~ 0
VBUS
$Comp
L TYPE-C-31-M-12:TYPE-C-31-M-12 J1
U 1 1 604E6CC6
P 8700 2150
F 0 "J1" H 8700 2817 50  0000 C CNN
F 1 "TYPE-C-31-M-12" H 8700 2726 50  0000 C CNN
F 2 "Custom:HRO_TYPE-C-31-M-12" H 8700 2150 50  0001 L BNN
F 3 "" H 8700 2150 50  0001 L BNN
F 4 "A" H 8700 2150 50  0001 L BNN "PARTREV"
F 5 "3.31mm" H 8700 2150 50  0001 L BNN "MAXIMUM_PACKAGE_HEIGHT"
F 6 "Manufacturer Recommendations" H 8700 2150 50  0001 L BNN "STANDARD"
F 7 "HRO Electronics" H 8700 2150 50  0001 L BNN "MANUFACTURER"
F 8 "C165948" H 8700 2150 50  0001 C CNN "LCSC"
	1    8700 2150
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C1
U 1 1 604F1B66
P 1950 3900
F 0 "C1" V 1900 3800 50  0000 C CNN
F 1 "0.1uF" V 2000 3750 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 1950 3900 50  0001 C CNN
F 3 "~" H 1950 3900 50  0001 C CNN
F 4 "C14663" H 1950 3900 50  0001 C CNN "LCSC"
	1    1950 3900
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0109
U 1 1 605C701B
P 7750 5200
F 0 "#PWR0109" H 7750 4950 50  0001 C CNN
F 1 "GND" H 7755 5027 50  0000 C CNN
F 2 "" H 7750 5200 50  0001 C CNN
F 3 "" H 7750 5200 50  0001 C CNN
	1    7750 5200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0110
U 1 1 605C7687
P 9050 5200
F 0 "#PWR0110" H 9050 4950 50  0001 C CNN
F 1 "GND" H 9055 5027 50  0000 C CNN
F 2 "" H 9050 5200 50  0001 C CNN
F 3 "" H 9050 5200 50  0001 C CNN
	1    9050 5200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0116
U 1 1 605C7919
P 9700 5200
F 0 "#PWR0116" H 9700 4950 50  0001 C CNN
F 1 "GND" H 9705 5027 50  0000 C CNN
F 2 "" H 9700 5200 50  0001 C CNN
F 3 "" H 9700 5200 50  0001 C CNN
	1    9700 5200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0117
U 1 1 605C7C17
P 9050 6150
F 0 "#PWR0117" H 9050 5900 50  0001 C CNN
F 1 "GND" H 9055 5977 50  0000 C CNN
F 2 "" H 9050 6150 50  0001 C CNN
F 3 "" H 9050 6150 50  0001 C CNN
	1    9050 6150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0118
U 1 1 605C80C2
P 8400 6150
F 0 "#PWR0118" H 8400 5900 50  0001 C CNN
F 1 "GND" H 8405 5977 50  0000 C CNN
F 2 "" H 8400 6150 50  0001 C CNN
F 3 "" H 8400 6150 50  0001 C CNN
	1    8400 6150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0119
U 1 1 605C84A0
P 7750 6150
F 0 "#PWR0119" H 7750 5900 50  0001 C CNN
F 1 "GND" H 7755 5977 50  0000 C CNN
F 2 "" H 7750 6150 50  0001 C CNN
F 3 "" H 7750 6150 50  0001 C CNN
	1    7750 6150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0120
U 1 1 605C72EE
P 8400 5200
F 0 "#PWR0120" H 8400 4950 50  0001 C CNN
F 1 "GND" H 8405 5027 50  0000 C CNN
F 2 "" H 8400 5200 50  0001 C CNN
F 3 "" H 8400 5200 50  0001 C CNN
	1    8400 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	8400 5200 8400 5100
Wire Wire Line
	8400 4600 8300 4600
Wire Wire Line
	8400 4700 8400 4600
Text GLabel 8300 4600 0    50   Input ~ 0
BTN2
$Comp
L CherryMX:CherryMX SW2
U 1 1 605EEA54
P 8400 4900
F 0 "SW2" V 8446 4852 50  0000 R CNN
F 1 "CherryMX" V 8355 4852 50  0000 R CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX_1.00u_PCB" H 8400 4925 50  0001 C CNN
F 3 "" H 8400 4925 50  0001 C CNN
	1    8400 4900
	0    1    1    0   
$EndComp
Wire Wire Line
	9500 2650 9500 2750
Wire Wire Line
	9950 2350 9950 2750
Wire Wire Line
	9500 2850 9500 2950
Connection ~ 9500 2850
Connection ~ 9500 2950
Wire Wire Line
	9500 2750 9950 2750
Wire Wire Line
	9950 2750 9950 3100
Connection ~ 9950 2750
Wire Wire Line
	7550 2300 7550 2200
Wire Wire Line
	7550 2000 7550 1950
Wire Wire Line
	1950 3150 1950 3300
Wire Wire Line
	1950 2800 1950 2950
$EndSCHEMATC
