//////////////////////////////////////////////////////////////////////////////
///                                                                        ///
/// ccs_SNTP.c - CCS Simple Network Time Protocol                          ///
///                                                                        ///
/// This is a modified version of the Microchip SNTP. It has been modified ///
/// to use the time drivers to keep time rather than Tick. All CCS time    ///
/// drivers function with this (uncomment the driver you want to use)      ///
///                                                                        ///
/// Locates the NTP Server defined below using DNS, requests the UTC time  ///
/// using NTP and updates the timer with the new time, and will            ///
/// periodically requery the server according to the NTP_QUERY_INTERVAL.   ///
///                                                                        ///
/// FUNCTIONS:                                                             ///
/// NTPTask() - State machine for processing NTP tasks                     ///
///                                                                        ///
/// DWORD NTPGetUTCSeconds() -  Returns the current UTC time from the timer///
///                                                                        ///
//////////////////////////////////////////////////////////////////////////////
////        (C) Copyright 1996,2006 Custom Computer Services              ////
//// This source code may only be used by licensed users of the CCS C     ////
//// compiler.  This source code may only be distributed to other         ////
//// licensed users of the CCS C compiler.  No other use, reproduction    ////
//// or distribution is permitted without written permission.             ////
//// Derivative programs created using this software in object code       ////
//// form are not restricted in any way.                                  ////
//////////////////////////////////////////////////////////////////////////////

#ifndef __CCS_SNTP_C__
#define __CCS_SNTP_C__

#ifndef debug_ntp
#define debug_ntp(a,b,c,d,e,f,g,h,i,j)
#endif

#include "TCPIP Stack/TCPIPConfig.h"
#include "TCPIP Stack/TCPIP.h"

#include <time.h>

#if 0   //set to 1 if you have an external DS1305 real time clock.
   #include <ds1305.c>
#elif 0 //set to 1 if you have a PIC with internal real time clock.
   #include <rtcperipheral.c>
#else
   // if you don't use one of the above real time clock devices, the
   // example will use a PIC timer.  this is the least accurate
   // but is compatabile with every PIC.
   
   // map rtcticks.c library to the already existing Tick system
   #define GET_RTC_TICKS   TickGet
   #define CLOCKS_PER_SECOND  TICKS_PER_SECOND
   
   #include <rtcticks.c>
#endif

#define NTP_EPOCH           (86400ul * (365ul * 70ul + 17ul)) // Reference Epoch (default: 01-Jan-1970 00:00:00)
#define NTP_QUERY_INTERVAL  (10ul * 60ul) // wait time before resynchronizing the date/time (default: 10 minutes)
#define NTP_WAIT_INTERVAL   (8)           // wait time before retrying an update after a failure. (default: 8 seconds)
#define NTP_REPLY_TIMEOUT   (6)           // wait time before assuming the query has failed (default: 6 seconds)
#define NTP_RESOLVE_TIMEOUT (5)           // wait time before assuming the DNS resolve has failed (default: 5 seconds)
#define NTP_ARP_TIMEOUT     (1)           // wait time before assuming the ARP request has failed (default: 1 second)
#define NTP_SERVER_PORT     (123ul)       // Port for contacting NTP servers
#define NTP_LOCAL_PORT      (7609ul)      // Local UDP Port


// These are normally available network time servers.
// Use the server for your region for best results
// *** NOTE ***
// *** If DNSResolve of the server name causes the program to
// *** crash, use the IP address of the pool instead. The IP
// *** of the server may change, so verify using the ping command.
#ifndef NTP_SERVER
//#define NTP_SERVER   "pool.ntp.org"    // global server
//#define NTP_SERVER     "64.85.168.205"
//#define NTP_SERVER   "europe.pool.ntp.org"
//#define NTP_SERVER     "178.209.40.108"
//#define NTP_SERVER   "asia.pool.ntp.org"
//#define NTP_SERVER     "103.12.12.122"
//#define NTP_SERVER   "oceania.pool.ntp.org"
//#define NTP_SERVER     "206.6.116.123"
//#define NTP_SERVER   "north-america.pool.ntp.org"
#define NTP_SERVER     "108.61.73.244"
//#define NTP_SERVER   "south-america.pool.ntp.org"
//#define NTP_SERVER     "200.1.19.4"
//#define NTP_SERVER   "africa.pool.ntp.org"
//#define NTP_SERVER     "41.216.193.26"
#endif

// Time of the last NTP update
static DWORD NTPLastUpdate = 0;

static NODE_INFO   Server;
static UDP_SOCKET  MySocket = INVALID_UDP_SOCKET;

static DWORD  rtcTimer;

int1 g_NTPOk = FALSE;

int1 NTPOk(void)
{
   return(g_NTPOk);
}

// Defines the structure of an NTP packet
typedef struct
{
   struct
   {
      BYTE mode           : 3;   // NTP mode
      BYTE versionNumber  : 3;   // SNTP version number
      BYTE leapIndicator  : 2;   // Leap second indicator
   } flags;                      // Flags for the packet

   BYTE stratum;                 // Stratum level of local clock
   CHAR poll;                    // Poll interval
   CHAR precision;               // Precision (seconds to nearest power of 2)
   DWORD root_delay;             // Root delay between local machine and server
   DWORD root_dispersion;        // Root dispersion (maximum error)
   DWORD ref_identifier;         // Reference clock identifier
   DWORD ref_ts_secs;            // Reference timestamp (in seconds)
   DWORD ref_ts_fraq;            // Reference timestamp (fractions)
   DWORD orig_ts_secs;           // Origination timestamp (in seconds)
   DWORD orig_ts_fraq;           // Origination timestamp (fractions)
   DWORD recv_ts_secs;           // Time at which request arrived at sender (seconds)
   DWORD recv_ts_fraq;           // Time at which request arrived at sender (fractions)
   DWORD tx_ts_secs;             // Time at which request left sender (seconds)
   DWORD tx_ts_fraq;             // Time at which request left sender (fractions)
} NTP_PACKET;

static enum
{
   NTP_HOME = 0,
   NTP_NAME_RESOLVE,
   NTP_ARP_START_RESOLVE,
   NTP_ARP_RESOLVE,
   NTP_ARP_START_RESOLVE2,
   NTP_ARP_RESOLVE2,
   NTP_ARP_START_RESOLVE3,
   NTP_ARP_RESOLVE3,
   NTP_ARP_RESOLVE_FAIL,
   NTP_UDP_SEND,
   NTP_UDP_RECV,
   NTP_SHORT_WAIT,
   NTP_WAIT
} NTPState = NTP_HOME; 


void NTPTask(void)
{
   NTP_PACKET         pkt;
   WORD               w;
   
   switch(NTPState)
   {
      case NTP_HOME:
         debug_ntp(debug_putc, "\r\n\nRefreshing Time\r\n");
         // Obtain ownership of the DNS resolution module
         if(!DNSBeginUsage())
            break;

         // Obtain the IP address associated with the server name
         DNSResolveROM((ROM BYTE*)NTP_SERVER, DNS_TYPE_A);
         rtcTimer = time(NULL);
         NTPState = NTP_NAME_RESOLVE;
         break;

      case NTP_NAME_RESOLVE:
         // Wait for DNS resolution to complete
         if(!DNSIsResolved(&Server.IPAddr)) 
         {
            if((time(NULL) - rtcTimer) >= NTP_RESOLVE_TIMEOUT)
            {
               DNSEndUsage();
               rtcTimer = time(NULL);
               NTPState = NTP_SHORT_WAIT;
            }
            break;
         }
         // Obtain DNS resolution result
         if(!DNSEndUsage())
         {
            // No valid IP address was returned from the DNS 
            // server.  Quit and fail for a while if host is not valid.
            rtcTimer = time(NULL);
            NTPState = NTP_SHORT_WAIT;
            break;
         }
         NTPState = NTP_ARP_START_RESOLVE;
         // No need to break

      case NTP_ARP_START_RESOLVE:
      case NTP_ARP_START_RESOLVE2:
      case NTP_ARP_START_RESOLVE3:
         // Obtain the MAC address associated with the server's IP address 
         ARPResolve(&Server.IPAddr);
         rtcTimer = time(NULL);
         NTPState++;
         break;

      case NTP_ARP_RESOLVE:
      case NTP_ARP_RESOLVE2:
      case NTP_ARP_RESOLVE3:
         // Wait for the MAC address to finish being obtained
         if(!ARPIsResolved(&Server.IPAddr, &Server.MACAddr))
         {
            // Time out if too much time is spent in this state
            if(time(NULL) - rtcTimer >= NTP_ARP_TIMEOUT)
            {
               // Retransmit ARP request by going to next SM_ARP_START_RESOLVE state or fail by going to SM_ARP_RESOLVE_FAIL state.
               NTPState++;
            }
            break;
         }
         NTPState = NTP_UDP_SEND;
         break;

      case NTP_ARP_RESOLVE_FAIL:
         // ARP failed after 3 tries, abort and wait for next time query
         rtcTimer = time(NULL);
         NTPState = NTP_SHORT_WAIT;
         break;

      case NTP_UDP_SEND:
         // Open up the sending UDP socket
         MySocket = UDPOpen(NTP_LOCAL_PORT, &Server, NTP_SERVER_PORT);
         if(MySocket == INVALID_UDP_SOCKET)
            break;

         // Make certain the socket can be written to
         if(!UDPIsPutReady(MySocket))
         {
            UDPClose(MySocket);
            break;
         }

         // Transmit a time request packet
         memset(&pkt, 0, sizeof(pkt));
         pkt.flags.versionNumber = 3;   // NTP Version 3
         pkt.flags.mode = 3;            // NTP Client
         pkt.orig_ts_secs = swapl(NTP_EPOCH);
         UDPPutArray((BYTE*) &pkt, sizeof(pkt));   
         UDPFlush();   
         
         //dwTimer = TickGet();
         rtcTimer = time(NULL);
         
         NTPState = NTP_UDP_RECV;      
         break;

      case NTP_UDP_RECV:
         // Look for a response time packet
         if(!UDPIsGetReady(MySocket)) 
         {
            if((time(NULL)) - rtcTimer >= NTP_REPLY_TIMEOUT)
            {
               // Abort the request and wait until the next timeout period
               UDPClose(MySocket);
               rtcTimer = time(NULL);
               NTPState = NTP_SHORT_WAIT;
               break;
            }
            break;
         }
         
         // Get the response time packet
         w = UDPGetArray((BYTE*) &pkt, sizeof(pkt));
         UDPClose(MySocket);
         rtcTimer = time(NULL);

         // Validate packet size
         if(w != sizeof(pkt)) 
         {
            NTPState = NTP_SHORT_WAIT;
            break;   
         }
         
         g_NTPOk = TRUE;
         NTPState = NTP_WAIT;
         
         // Set out local time to match the returned time
         NTPLastUpdate = swapl(pkt.tx_ts_secs) - NTP_EPOCH;
         // Do rounding.  If the partial seconds is > 0.5 then add 1 to the seconds count.
         if(((BYTE*)&pkt.tx_ts_fraq)[0] & 0x80)
            NTPLastUpdate++;
         SetTimeSec(NTPLastUpdate);
         break;

      case NTP_SHORT_WAIT:
         // Attempt to requery the NTP server after a specified NTP_FAST_QUERY_INTERVAL time (ex: 8 seconds) has elapsed.
         g_NTPOk = FALSE;
         if(time(NULL) - rtcTimer >= NTP_WAIT_INTERVAL)
            NTPState = NTP_HOME;   
         break;

      case NTP_WAIT:
         // Requery the NTP server after a specified NTP_QUERY_INTERVAL time (ex: 10 minutes) has elapsed.
         if(time(NULL) - NTPLastUpdate >= NTP_QUERY_INTERVAL)
            NTPState = NTP_HOME;   

         break;
   }
}

int1 NTPBusy(void)
{
   return(NTPState == NTP_WAIT);
}

DWORD NTPGetUTCSeconds(void)
{
   return time(NULL);
}

void NTPInit(void)
{
   NTPState = NTP_HOME;
   g_NTPOk = FALSE;
   TimeInit();
}

#endif //__CCS_SNTP_C__
