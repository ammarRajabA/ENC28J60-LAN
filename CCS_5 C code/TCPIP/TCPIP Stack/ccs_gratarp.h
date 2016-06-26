/*
   Gratuitous Arp
   
   Will send a Gratuitous Arp 3s after first link.  Then after 120s it will
   send a grat arp every 3s.
*/

#ifndef __CCS_GRATARP_H__
#define __CCS_GRATARP_H__

void GratArpInit(void);

// set forced mode (default is false).  when forced, will send grat arps every
// 3s even if it is seeing other arps.
void GratArpSetForced(int1 new);
int1 GratArpIsForced(void);

// set enabled mode (default is true).
void GratArpSetEnabled(int1 new);
int1 GratAprIsEnabled(void);

// reset the 120s timer so it will take a new 120s to send a gratuitous arp
void GratArpReset(void);

void GratArpTask(void);

#endif
