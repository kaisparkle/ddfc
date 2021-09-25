EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L neo-7m_breakout:NEO-7M_Breakout GPS1
U 1 1 61499201
P 3425 5800
F 0 "GPS1" H 3600 6125 50  0000 C CNN
F 1 "NEO-7M_Breakout" H 3350 6050 50  0000 C CNN
F 2 "ddfc:NEO-7M_Breakout" H 3425 6050 50  0001 C CNN
F 3 "" H 3425 6050 50  0001 C CNN
	1    3425 5800
	1    0    0    -1  
$EndComp
$Comp
L mpu6050_breakout:MPU6050_Breakout MPU1
U 1 1 61499C51
P 6475 2475
F 0 "MPU1" H 6510 2950 50  0000 L CNN
F 1 "MPU6050_Breakout" H 6000 2875 50  0000 L CNN
F 2 "ddfc:MPU6050_Breakout" H 6475 2875 50  0001 C CNN
F 3 "" H 6475 2875 50  0001 C CNN
	1    6475 2475
	1    0    0    -1  
$EndComp
$Comp
L microsd_breakout:MicroSD_Breakout SD1
U 1 1 614A280D
P 3400 4600
F 0 "SD1" H 3525 5125 50  0000 L CNN
F 1 "MicroSD_Breakout" H 3000 5050 50  0000 L CNN
F 2 "avi:MicroSD_Breakout" H 3400 5050 50  0001 C CNN
F 3 "" H 3400 5050 50  0001 C CNN
	1    3400 4600
	1    0    0    -1  
$EndComp
$Comp
L nrf24l01+_breakout:NRF24L01+_Breakout RADIO1
U 1 1 614C14CE
P 3625 2100
F 0 "RADIO1" H 3750 2700 50  0000 C CNN
F 1 "NRF24L01+_Breakout" H 3475 2625 50  0000 C CNN
F 2 "ddfc:NRF24L01+_Breakout" H 3475 2625 50  0001 C CNN
F 3 "" H 3475 2625 50  0001 C CNN
	1    3625 2100
	1    0    0    -1  
$EndComp
NoConn ~ 4925 1525
NoConn ~ 5225 3225
NoConn ~ 5225 3125
NoConn ~ 5225 2825
NoConn ~ 5225 2725
NoConn ~ 5225 2625
NoConn ~ 5225 2525
NoConn ~ 5225 2325
NoConn ~ 5225 2025
NoConn ~ 5225 1925
NoConn ~ 4225 1925
NoConn ~ 4225 2025
NoConn ~ 4225 2125
NoConn ~ 4225 2225
NoConn ~ 4225 2825
NoConn ~ 4225 2925
NoConn ~ 6025 2725
NoConn ~ 6025 2625
NoConn ~ 6025 2525
NoConn ~ 6025 2425
NoConn ~ 3125 2225
NoConn ~ 3000 5700
$Comp
L Device:C C2
U 1 1 61550782
P 8425 2075
F 0 "C2" H 8540 2121 50  0000 L CNN
F 1 "22uF" H 8540 2030 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.18x1.45mm_HandSolder" H 8463 1925 50  0001 C CNN
F 3 "~" H 8425 2075 50  0001 C CNN
	1    8425 2075
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 6154E924
P 7425 1725
F 0 "C1" H 7540 1771 50  0000 L CNN
F 1 "10uF" H 7540 1680 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.18x1.45mm_HandSolder" H 7463 1575 50  0001 C CNN
F 3 "~" H 7425 1725 50  0001 C CNN
	1    7425 1725
	1    0    0    -1  
$EndComp
NoConn ~ 4825 1525
NoConn ~ 6025 3350
$Comp
L Regulator_Linear:AMS1117-3.3 REG1
U 1 1 614C77E7
P 8000 1575
F 0 "REG1" H 8000 1817 50  0000 C CNN
F 1 "AMS1117-3.3" H 8000 1726 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-223-3_TabPin2" H 8000 1775 50  0001 C CNN
F 3 "http://www.advanced-monolithic.com/pdf/ds1117.pdf" H 8100 1325 50  0001 C CNN
	1    8000 1575
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 614CD49E
P 8425 1775
F 0 "R1" H 8495 1821 50  0000 L CNN
F 1 "3R3" H 8495 1730 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 8355 1775 50  0001 C CNN
F 3 "~" H 8425 1775 50  0001 C CNN
	1    8425 1775
	1    0    0    -1  
$EndComp
NoConn ~ 4225 2325
NoConn ~ 4225 2425
NoConn ~ 4225 2525
NoConn ~ 4200 4500
NoConn ~ 4200 4600
NoConn ~ 4200 4700
NoConn ~ 4200 4800
NoConn ~ 4200 4900
NoConn ~ 4200 5200
NoConn ~ 4200 5300
NoConn ~ 4200 5400
NoConn ~ 5200 5800
NoConn ~ 5200 5700
NoConn ~ 5200 5400
NoConn ~ 5200 5300
NoConn ~ 5200 5200
NoConn ~ 5200 5100
Wire Wire Line
	8300 1575 8425 1575
Wire Wire Line
	8425 1575 8425 1625
$Comp
L Connector_Generic:Conn_01x02 BATT1
U 1 1 615D5177
P 9025 1850
F 0 "BATT1" H 8950 1950 50  0000 L CNN
F 1 "9V" H 8950 2025 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 9025 1850 50  0001 C CNN
F 3 "~" H 9025 1850 50  0001 C CNN
	1    9025 1850
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 61506E57
P 9225 1850
F 0 "#PWR0101" H 9225 1600 50  0001 C CNN
F 1 "GND" V 9230 1722 50  0000 R CNN
F 2 "" H 9225 1850 50  0001 C CNN
F 3 "" H 9225 1850 50  0001 C CNN
	1    9225 1850
	0    -1   -1   0   
$EndComp
$Comp
L power:+9V #PWR0102
U 1 1 61507AC8
P 9225 1750
F 0 "#PWR0102" H 9225 1600 50  0001 C CNN
F 1 "+9V" V 9240 1878 50  0000 L CNN
F 2 "" H 9225 1750 50  0001 C CNN
F 3 "" H 9225 1750 50  0001 C CNN
	1    9225 1750
	0    1    1    0   
$EndComp
$Comp
L power:+9V #PWR0103
U 1 1 61509CE4
P 4625 1525
F 0 "#PWR0103" H 4625 1375 50  0001 C CNN
F 1 "+9V" H 4640 1698 50  0000 C CNN
F 2 "" H 4625 1525 50  0001 C CNN
F 3 "" H 4625 1525 50  0001 C CNN
	1    4625 1525
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0104
U 1 1 6150A051
P 4825 3525
F 0 "#PWR0104" H 4825 3275 50  0001 C CNN
F 1 "GND" V 4830 3397 50  0000 R CNN
F 2 "" H 4825 3525 50  0001 C CNN
F 3 "" H 4825 3525 50  0001 C CNN
	1    4825 3525
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4725 3525 4825 3525
$Comp
L power:+9V #PWR0105
U 1 1 615155C9
P 7425 1575
F 0 "#PWR0105" H 7425 1425 50  0001 C CNN
F 1 "+9V" H 7440 1748 50  0000 C CNN
F 2 "" H 7425 1575 50  0001 C CNN
F 3 "" H 7425 1575 50  0001 C CNN
	1    7425 1575
	1    0    0    -1  
$EndComp
Wire Wire Line
	7425 1575 7700 1575
Connection ~ 7425 1575
$Comp
L power:GND #PWR0106
U 1 1 61518002
P 8000 1875
F 0 "#PWR0106" H 8000 1625 50  0001 C CNN
F 1 "GND" H 8005 1702 50  0000 C CNN
F 2 "" H 8000 1875 50  0001 C CNN
F 3 "" H 8000 1875 50  0001 C CNN
	1    8000 1875
	1    0    0    -1  
$EndComp
Wire Wire Line
	7425 1875 8000 1875
Connection ~ 8000 1875
Wire Wire Line
	8425 2225 8200 2225
Wire Wire Line
	8200 2225 8200 1875
Wire Wire Line
	8200 1875 8000 1875
$Comp
L power:+3V3 #PWR0107
U 1 1 6151D42A
P 8425 1575
F 0 "#PWR0107" H 8425 1425 50  0001 C CNN
F 1 "+3V3" H 8475 1775 50  0000 C CNN
F 2 "" H 8425 1575 50  0001 C CNN
F 3 "" H 8425 1575 50  0001 C CNN
	1    8425 1575
	1    0    0    -1  
$EndComp
Connection ~ 8425 1575
$Comp
L power:+3V3 #PWR0109
U 1 1 6151ED05
P 6675 2425
F 0 "#PWR0109" H 6675 2275 50  0001 C CNN
F 1 "+3V3" V 6675 2625 50  0000 C CNN
F 2 "" H 6675 2425 50  0001 C CNN
F 3 "" H 6675 2425 50  0001 C CNN
	1    6675 2425
	0    1    1    0   
$EndComp
$Comp
L power:+3V3 #PWR0110
U 1 1 615221EE
P 3650 4400
F 0 "#PWR0110" H 3650 4250 50  0001 C CNN
F 1 "+3V3" H 3525 4475 50  0000 C CNN
F 2 "" H 3650 4400 50  0001 C CNN
F 3 "" H 3650 4400 50  0001 C CNN
	1    3650 4400
	0    1    1    0   
$EndComp
$Comp
L power:+3V3 #PWR0111
U 1 1 61524D6C
P 3800 2025
F 0 "#PWR0111" H 3800 1875 50  0001 C CNN
F 1 "+3V3" H 3950 2100 50  0000 C CNN
F 2 "" H 3800 2025 50  0001 C CNN
F 3 "" H 3800 2025 50  0001 C CNN
	1    3800 2025
	0    1    1    0   
$EndComp
$Comp
L power:+3V3 #PWR0112
U 1 1 61527C68
P 3650 5850
F 0 "#PWR0112" H 3650 5700 50  0001 C CNN
F 1 "+3V3" H 3775 5925 50  0000 C CNN
F 2 "" H 3650 5850 50  0001 C CNN
F 3 "" H 3650 5850 50  0001 C CNN
	1    3650 5850
	0    1    1    0   
$EndComp
$Comp
L power:+3V3 #PWR0113
U 1 1 6152AB62
P 6725 3200
F 0 "#PWR0113" H 6725 3050 50  0001 C CNN
F 1 "+3V3" V 6725 3400 50  0000 C CNN
F 2 "" H 6725 3200 50  0001 C CNN
F 3 "" H 6725 3200 50  0001 C CNN
	1    6725 3200
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0115
U 1 1 6153162A
P 6675 2525
F 0 "#PWR0115" H 6675 2275 50  0001 C CNN
F 1 "GND" V 6675 2350 50  0000 C CNN
F 2 "" H 6675 2525 50  0001 C CNN
F 3 "" H 6675 2525 50  0001 C CNN
	1    6675 2525
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0116
U 1 1 61533F5D
P 3650 4500
F 0 "#PWR0116" H 3650 4250 50  0001 C CNN
F 1 "GND" H 3525 4425 50  0000 C CNN
F 2 "" H 3650 4500 50  0001 C CNN
F 3 "" H 3650 4500 50  0001 C CNN
	1    3650 4500
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0117
U 1 1 61536921
P 3800 1925
F 0 "#PWR0117" H 3800 1675 50  0001 C CNN
F 1 "GND" H 3925 1850 50  0000 C CNN
F 2 "" H 3800 1925 50  0001 C CNN
F 3 "" H 3800 1925 50  0001 C CNN
	1    3800 1925
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0118
U 1 1 615395BC
P 3650 5750
F 0 "#PWR0118" H 3650 5500 50  0001 C CNN
F 1 "GND" H 3775 5675 50  0000 C CNN
F 2 "" H 3650 5750 50  0001 C CNN
F 3 "" H 3650 5750 50  0001 C CNN
	1    3650 5750
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0119
U 1 1 6153BFF7
P 6725 3300
F 0 "#PWR0119" H 6725 3050 50  0001 C CNN
F 1 "GND" V 6725 3125 50  0000 C CNN
F 2 "" H 6725 3300 50  0001 C CNN
F 3 "" H 6725 3300 50  0001 C CNN
	1    6725 3300
	0    -1   -1   0   
$EndComp
Text GLabel 5225 2925 2    50   Input ~ 0
I2C_SDA
Text GLabel 5225 3025 2    50   Input ~ 0
I2C_SCL
Text GLabel 5200 5500 2    50   Input ~ 0
I2C_SDA
Text GLabel 5200 5600 2    50   Input ~ 0
I2C_SCL
Text GLabel 4200 5000 0    50   Input ~ 0
GPS_TX
Text GLabel 4200 5100 0    50   Input ~ 0
GPS_RX
Text GLabel 4225 2625 0    50   Input ~ 0
RADIO_CE
Text GLabel 4225 2725 0    50   Input ~ 0
RADIO_CSN
Text GLabel 4225 3025 0    50   Input ~ 0
RADIO_MOSI
Text GLabel 4225 3125 0    50   Input ~ 0
RADIO_MISO
Text GLabel 4225 3225 0    50   Input ~ 0
RADIO_SCK
Wire Wire Line
	4700 6100 4800 6100
$Comp
L power:+9V #PWR0120
U 1 1 61509299
P 4600 4100
F 0 "#PWR0120" H 4600 3950 50  0001 C CNN
F 1 "+9V" H 4615 4273 50  0000 C CNN
F 2 "" H 4600 4100 50  0001 C CNN
F 3 "" H 4600 4100 50  0001 C CNN
	1    4600 4100
	1    0    0    -1  
$EndComp
NoConn ~ 4900 4100
NoConn ~ 4800 4100
NoConn ~ 5200 4500
NoConn ~ 5200 4600
NoConn ~ 5200 4900
$Comp
L MCU_Module:Arduino_Nano_v3.x NAV/REC1
U 1 1 614E99DB
P 4700 5100
F 0 "NAV/REC1" H 4700 5475 50  0000 C CNN
F 1 "Arduino_Nano_v3.x" V 4600 5075 50  0000 C CNN
F 2 "ddfc:Arduino_Nano_Clone" H 4700 5100 50  0001 C CIN
F 3 "http://www.mouser.com/pdfdocs/Gravitech_Arduino_Nano3_0.pdf" H 4700 5100 50  0001 C CNN
	1    4700 5100
	1    0    0    -1  
$EndComp
Text GLabel 4200 5600 0    50   Input ~ 0
SD_MOSI
Text GLabel 4200 5700 0    50   Input ~ 0
SD_MISO
Text GLabel 4200 5800 0    50   Input ~ 0
SD_SCK
Text GLabel 4200 5500 0    50   Input ~ 0
SD_CS
Text GLabel 6025 3250 0    50   Input ~ 0
I2C_SDA
Text GLabel 6025 3150 0    50   Input ~ 0
I2C_SCL
Text GLabel 3000 5900 0    50   Input ~ 0
GPS_TX
Text GLabel 3000 5800 0    50   Input ~ 0
GPS_RX
Text GLabel 3125 2125 0    50   Input ~ 0
RADIO_MISO
Text GLabel 3125 2025 0    50   Input ~ 0
RADIO_MOSI
Text GLabel 3125 1925 0    50   Input ~ 0
RADIO_SCK
Text GLabel 3125 1825 0    50   Input ~ 0
RADIO_CSN
Text GLabel 3125 1725 0    50   Input ~ 0
RADIO_CE
Text GLabel 2975 4600 0    50   Input ~ 0
SD_MISO
Text GLabel 2975 4500 0    50   Input ~ 0
SD_MOSI
Text GLabel 2975 4400 0    50   Input ~ 0
SD_SCK
Text GLabel 2975 4300 0    50   Input ~ 0
SD_CS
Text GLabel 6025 2325 0    50   Input ~ 0
I2C_SDA
Text GLabel 6025 2225 0    50   Input ~ 0
I2C_SCL
Text GLabel 6025 1725 0    50   Input ~ 0
I2C_SCL
Text GLabel 6025 1825 0    50   Input ~ 0
I2C_SDA
$Comp
L power:GND #PWR0114
U 1 1 6152D7EE
P 6675 1825
F 0 "#PWR0114" H 6675 1575 50  0001 C CNN
F 1 "GND" V 6675 1650 50  0000 C CNN
F 2 "" H 6675 1825 50  0001 C CNN
F 3 "" H 6675 1825 50  0001 C CNN
	1    6675 1825
	0    -1   -1   0   
$EndComp
$Comp
L power:+3V3 #PWR0108
U 1 1 6151D93E
P 6675 1725
F 0 "#PWR0108" H 6675 1575 50  0001 C CNN
F 1 "+3V3" V 6675 1925 50  0000 C CNN
F 2 "" H 6675 1725 50  0001 C CNN
F 3 "" H 6675 1725 50  0001 C CNN
	1    6675 1725
	0    1    1    0   
$EndComp
$Comp
L bmp180_breakout:BMP180_Breakout BMP1
U 1 1 61498811
P 6350 1775
F 0 "BMP1" H 6580 2045 50  0000 C CNN
F 1 "BMP180_Breakout" H 6350 1975 50  0000 C CNN
F 2 "ddfc:BMP180_Breakout" H 6350 1975 50  0001 C CNN
F 3 "" H 6350 1975 50  0001 C CNN
	1    6350 1775
	1    0    0    -1  
$EndComp
$Comp
L hmc5883l_breakout:HMC5883L_Breakout HMC1
U 1 1 614B4AA4
P 6375 3250
F 0 "HMC1" H 6475 3550 50  0000 L CNN
F 1 "HMC5883L_Breakout" H 5875 3475 50  0000 L CNN
F 2 "ddfc:HMC5883L_Breakout" H 6375 3475 50  0001 C CNN
F 3 "" H 6375 3475 50  0001 C CNN
	1    6375 3250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0121
U 1 1 615FC678
P 4800 6100
F 0 "#PWR0121" H 4800 5850 50  0001 C CNN
F 1 "GND" V 4805 5972 50  0000 R CNN
F 2 "" H 4800 6100 50  0001 C CNN
F 3 "" H 4800 6100 50  0001 C CNN
	1    4800 6100
	0    -1   -1   0   
$EndComp
Connection ~ 4800 6100
Connection ~ 4825 3525
$Comp
L MCU_Module:Arduino_Nano_v3.x TELEM1
U 1 1 61488C0C
P 4725 2525
F 0 "TELEM1" H 4725 2900 50  0000 C CNN
F 1 "Arduino_Nano_v3.x" V 4625 2500 50  0000 C CNN
F 2 "ddfc:Arduino_Nano_Clone" H 4725 2525 50  0001 C CIN
F 3 "http://www.mouser.com/pdfdocs/Gravitech_Arduino_Nano3_0.pdf" H 4725 2525 50  0001 C CNN
	1    4725 2525
	1    0    0    -1  
$EndComp
Wire Notes Line
	7300 1200 9550 1200
Wire Notes Line
	9550 1200 9550 2300
Wire Notes Line
	9550 2300 7300 2300
Wire Notes Line
	7300 2300 7300 1200
Text Notes 7300 1175 0    50   ~ 0
Voltage Regulator
Wire Notes Line
	5650 6225 2525 6225
Wire Notes Line
	2525 6225 2525 3850
Wire Notes Line
	5650 3850 5650 6225
Wire Notes Line
	2525 1200 7100 1200
Wire Notes Line
	7100 1200 7100 3650
Wire Notes Line
	2525 1200 2525 3650
Wire Notes Line
	2525 3650 7100 3650
Wire Notes Line
	2525 3850 5650 3850
Text Notes 2525 1175 0    50   ~ 0
TELEM Computer
Text Notes 2525 3825 0    50   ~ 0
NAV/REC Computer
$EndSCHEMATC
