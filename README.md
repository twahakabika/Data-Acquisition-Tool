#  Physiological Data Acquisition Tool for Low Cost Computer Systems 

Project Setup: 
To ease the use of this application during the practical classes and the development of the new or modified application by the University Student or young developers, the template project is provided. The students just need to follow few steps in order to successfully use this application. Therefore, a description of how to download and set up the template project is given first. This step by step walk-through is based on using Qt Application version 4.8.6 on a Raspberry Pi Unix based system.

 Hardware Connection: 
 Before doing anything it’s important to know the hardware connection between the Raspberry Pi and BITalino board, because without a correctly connection none of the coming step will mean anything.
 
 Raspberry Pi	: BITalino Board
Pin Number	: Description: 	Wire	: Description
Pin 2	:  VCC: 	Red	: VCC, 
Pin 6:	GND	: Black :	GND, 
Pin 8	:Tx	: White	: Rx, 
Pin 10	:Rx	: Yellow	: Tx, 
Pin 11	 :GND	: Black	: GND, 
Pin 20	:GND	: Black	: CTS.

Project Environment Setup: 
In order for Raspberry Pi to be ready for running the application, the gcc, g++ software and Qt cross-platform application must be properly installed. Detailed informations are included on the Setup file.
