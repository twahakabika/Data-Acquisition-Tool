# Data-Acquisition-Tool
Physiological Data Acquisition Tool for Low Cost Computer Systems 

Project Setup
To ease the use of this application during the practical classes and the development of the new or modified application by the University Student or young developers, the template project is provided. The students just need to follow few steps in order to successfully use this application. Therefore, a description of how to download and set up the template project is given first. This step by step walk-through is based on using Qt Application version 4.8.6 on a Raspberry Pi Unix based system.

 Hardware Connection
 Before doing anything it’s important to know the hardware connection between the Raspberry Pi and BITalino board, because without a correctly connection none of the coming step will mean anything.
 
 Raspberry Pi	BITalino Board
Pin Number	Description	Wire	Description
Pin 2	 VCC	Red	VCC
Pin 6	GND	Black	GND
Pin 8	Tx	White	Rx
Pin 10	Rx	Yellow	Tx
Pin 11	GND	Black	GND
Pin 20	GND	Black	CTS

Project Environment Setup
In order for Raspberry Pi to be ready for running the application, the gcc, g++ software and Qt cross-platform application must be properly installed. The listings below show very specific how to download gcc 4.4 and g++ 4.4 and Qt 4.8.6 because are the versions of the software which were used during the implementation and testing of the developed application. Also the Raspberry Pi console must be disabled in order to allow the efficient use of the serial communication. This can be done by adding the line enable_uart = 1 at the bottom of the config.txt file, to reach this file, from the terminal type, sudo nano /boot/config.txt. This will basically set serial 1 or ttyS0 as Mini UART. But the baud rate of the mini UART is linked to the core frequency of the VPU on the VC4 GPU. This means that as the VPU frequency governor varies the core frequency, the baud rate of the UART also changes. This makes the UART of limited use in the default state. To overcome this challenge dtoverlay=pi3-miniuart-bt is added below the enable_uart = 1 on the config.txt.  This line switches the Raspberry Pi 3 Bluetooth function to use the mini UART (ttyS0), and restores UART (ttyAMA0) to GPIOs 14 and 15 which increase the maximum usability of baud rate to the GPIOs.
