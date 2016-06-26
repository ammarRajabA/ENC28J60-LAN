#include <18F4585.h>
#device ADC=16

/*
TCP/IP Stack enabled.
Many TCP/IP configuration settings (servers enabled, ports used,
etc) are defined in TCPIPConfig.h.
Many hardware configuration settings (SPI port and GPIO pins used)
are defined in HardwareProfile.h.
*/

#include "tcpip/p18cxxx.h"

#FUSES NOWDT                 	//No Watch Dog Timer
#FUSES WDT128                	//Watch Dog Timer uses 1:128 Postscale
#FUSES NOBROWNOUT            	//No brownout reset
#FUSES NOLVP                 	//No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O
#FUSES BBSIZ1K               	//1K words Boot Block size
#FUSES NOXINST               	//Extended set extension and Indexed Addressing mode disabled (Legacy mode)

#use delay(crystal=8MHz)


#if defined(__PCH__)
   #define GetSystemClock()       getenv("CLOCK")
   #define GetInstructionClock()  (GetSystemClock()/4)
   #define GetPeripheralClock()   (unsigned int32)GetInstructionClock()
#else
   #define GetSystemClock()       getenv("CLOCK")
   #define GetInstructionClock()  (GetSystemClock()/2)
   #define GetPeripheralClock()   (GetSystemClock()/2)
#endif

#define MIN(a,b)  ((a > b) ? b : a)

#include <stdint.h>
#include "tcpip/StackTsk2.h"
#include "tcpip/TCPIP Stack/TCPIPConfig.h"
#include "tcpip/TCPIP Stack/HardwareProfile.h"
#include "tcpip/StackTsk2.c"

