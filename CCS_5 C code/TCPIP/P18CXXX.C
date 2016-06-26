// CCS PCH C Compiler to Microchip C18 Compiler compatability layer.

#ifndef __P18CXXXX_C__
#define __P18CXXXX_C__

#include "p18cxxx.h"
/* STRING.H already has this exact function
signed int8 memcmppgm2ram(void * s1, rom char *s2, unsigned int8 n)
{
  #if 1
   char *su1;
   rom char *su2;
   
   for(su1=s1, su2=s2; 0<n; ++su1, ++su2, --n)
   {
      if(*su1!=*su2)
         return ((*su1<*su2)?-1:+1);
   }
   return 0;
  #else
   #error///warning memcmppgm2ram disabled
  #endif
}*/

#if 0 //this is in string.h and helpers.c
char* strupr(char *s)
{
   char *p;
   
   p=s;
   
   while(*p)
   {
      *p = toupper(*p++);
   }
   return(s);
}
#endif

void memcpypgm2ram(unsigned int8 *d, __ADDRESS__ s, unsigned int16 n)
{
   //printf("ROM_0x%LX-to-0x%LX ", d, s);
  #if (getenv("PROGRAM_MEMORY") > 0x10000)
   #warning temporary ccs bug fix
   s |= 0x10000;
  #endif
   read_program_memory(s, d, n);
}

void strcpypgm2ram(char *d, __ADDRESS__ s)
{
   char c;
   do
   {
      memcpypgm2ram(&c, s++, 1);
      *d++ = c;
   } while(c);
}

#if 0
signed int8 strcmppgm2ram(char *s1, rom char *s2)
{
   for (; *s1 == *s2; s1++, s2++)
      if (*s1 == '\0')
         return(0);
   return((*s1 < *s2) ? -1: 1);
}
#endif

char *strchrpgm(rom char *s, unsigned int8 c)
{
   for (; *s != c; s++)
      if (*s == '\0')
         return(0);
   return(s);
}

char *strstrrampgm(char *s1,__ADDRESS__ s2)
{
   char *s;
   rom char *t;

   #ifdef FASTER_BUT_MORE_ROM
   if (*s2 == '\0')
         return(s1);
   #endif

   while (*s1)
   {
      for(s = s1, t = s2; *t && (*s == *t); ++s, ++t);

      if (*t == '\0')
         return s1;
      ++s1;
      #ifdef FASTER_BUT_MORE_ROM
         while(*s1 != '\0' && *s1 != *s2)
            ++s1;
      #endif
   }
   return 0;
}

unsigned int8 strlenpgm( __ADDRESS__ s)
{
   char c;
   char counter = 0;
   do{
      memcpypgm2ram(&c,s++,1);
      counter++;
   }while(c != 0);
   return(counter - 1);
}
//#endif   //if 0

#endif
