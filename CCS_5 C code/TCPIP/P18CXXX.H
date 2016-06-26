// CCS PCH C Compiler to Microchip C18 Compiler compatability layer.

#ifndef __P18CXXXX_H__
#define __P18CXXXX_H__

#ifndef __18CXX
#define __18CXX
#endif

//#zero_local_ram
#zero_ram


#device PASS_STRINGS=IN_RAM
#device CONST=READ_ONLY

#case
#type signed
#type short=16 int=16 long=32

#define _asm #asm
#define _endasm #endasm

/* usualy
#define GetSystemClock()      getenv("CLOCK")
#define GetInstructionClock()   (GetSystemClock()/4)
#define GetPeripheralClock()   (unsigned int32)GetInstructionClock()
*/

#if getenv("DEVICE") == "PIC18F97J60"
 #define __18F97J60
 #include "PIC18F87J60_registers.h"
#elif getenv("DEVICE") == "PIC18F96J65"
 #define __18F96J65)
#elif getenv("DEVICE") == "PIC18F96J60"
 #define __18F96J60
#elif getenv("DEVICE") == "PIC18F87J60"
 #define __18F87J60
 #include "PIC18F87J60_registers.h"
#elif getenv("DEVICE") == "PIC18F86J65"
 #define __18F86J65
#elif getenv("DEVICE") == "PIC18F86J65"
 #define __18F86J65
#elif getenv("DEVICE") == "PIC18F86J60"
 #define __18F86J60
#elif getenv("DEVICE") == "PIC18F67J60"
 #define __18F67J60
 #include "PIC18F67J60_registers.h"
#elif getenv("DEVICE") == "PIC18F66J65"
 #define __18F66J65
#elif getenv("DEVICE") == "PIC18F66J60"
 #define __18F66J60
#elif getenv("DEVICE") == "PIC18F67K22"
 #define __18F67K22
 #include "PIC18F67K22_registers.h"
#elif getenv("DEVICE") == "PIC18F4620"
 #define __18F4620
 #include "PIC18F4620_registers.h"
#else
 #include "PIC18F4585_registers.h"
#endif

#if defined(__18F97J60) || defined(__18F96J65) || defined(__18F96J60) || defined(__18F87J60) || defined(__18F86J65) || defined(__18F86J60) || defined(__18F67J60) || defined(__18F66J65) || defined(__18F66J60)
   #reserve 0xE80:0xEFF
   #reserve 0xF00:0xFFF
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

      #define Reset()            reset_cpu()
        #define far
        #define ClrWdt()         restart_wdt()
      #define Nop()            delay_cycles(1)

#define __CCS__

//signed int8 memcmppgm2ram(void * s1, rom char *s2, unsigned int8 n);
signed int8 strcmppgm2ram(char *s1, __ADDRESS__ s2);
char *strchrpgm(rom char *s, unsigned int8 c);
char *strstrrampgm(char *s1, __ADDRESS__ s2);
unsigned int8 strlenpgm(__ADDRESS__ s);
void memcpypgm2ram(unsigned int8 *d, __ADDRESS__ s, unsigned int16 n);
//char* strupr(char *s);   now in string.h
void strcpypgm2ram(char *d, __ADDRESS__ s);
#endif
