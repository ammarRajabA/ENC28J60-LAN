// pcdxxxx.h
//
// Microchip C30 to CCS conversion library.
//
// Wrapper for p24Hxxxx.h, p24Fxxxx.h, p30Fxxxx.h and 
//
// __PIC24F__
// __PIC24H__
// __dsPIC30F__
// __dsPIC33F__

#ifndef __PCDXXXX_H__
#define __PCDXXXX_H__

#ifndef __C30__
#define __C30__
#endif

#zero_ram

#device PASS_STRINGS=IN_RAM
#device CONST=ROM
#device PSV=16

#case
#type signed
#type short=16 int=16 long=32

#case

#define _asm #asm
#define _endasm #endasm

/* usually
#define GetSystemClock()       getenv("CLOCK")
#define GetInstructionClock()  (GetSystemClock()/2)
#define GetPeripheralClock()   (GetSystemClock()/2)
*/

#if getenv("DEVICE") == "PIC24FJ256GA110"
   #define __PIC24FJ256GA110__
   #define __PIC24F__
   #include "24FJ256GA110_registers.h"
#elif getenv("DEVICE") == "PIC24FJ128GA010"
   #define __PIC24FJ128GA010__
   #define __PIC24F__
   #include "24FJ128GA010_registers.h"
#else
   #error do this for your chip
#endif

#if defined(TRUE)
#undef TRUE
#endif

#if defined(FALSE)
#undef FALSE
#endif

#if defined(BYTE)
#undef BYTE
#endif

#if defined(BOOLEAN)
#undef BOOLEAN
#endif

#define Reset()            reset_cpu()
#define FAR
#define ClrWdt()         restart_wdt()
#define Nop()            delay_cycles(1)

#warning need eds support
#define __eds__

#define __prog__  rom

#define __CCS__

#inline 
unsigned int16 __builtin_tblrdh(unsigned int16 addy)
{
   unsigned int16 ret;
   WREG5 = addy;
   WREG6 = &ret;
  #asm
   TBLRDH [W5], [W6]
  #endasm
   return(ret);
}

#inline 
unsigned int16 __builtin_tblrdl(unsigned int16 addy)
{
   unsigned int16 ret;
   WREG5 = addy;
   WREG6 = &ret;
  #asm
   TBLRDL [W5], [W6]
  #endasm
   return(ret);
}

#define  strcpypgm2ram  sprintf

#endif
