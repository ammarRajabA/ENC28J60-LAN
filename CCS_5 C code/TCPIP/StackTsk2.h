// 'glue' file for using Microchip's TCP/IP stack inside CCS C Compiler without
// a linker.  
// Also includes some macros/defines for porting older V3 stack to this current
// stack.
// Also provides extra routines written by CCS to improve the stack.

#ifndef __CCS_STACKTSK2_H__
#define __CCS_STACKTSK2_H__

#if !defined(debug_mpfs2)
 #define debug_mpfs2(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q)
#else
 #define __DO_DEBUG_MPFS2
#endif

#if defined(__PCH__) && !defined(__18CXX)
 #define __18CXX
#endif

#define SIZEOF_MAC_HEADER 14

// override delay.c/delay.h with CCS compatible code
#define __DELAY_H
#define Delay10us(x) delay_us((uint16_t)10*(uint16_t)x)
#define DelayMs(x)   delay_ms(x)

#define __WF_DEBUG_STRINGS_H  //don't include this file

#include "TCPIP Stack/TCPIP.h"

#if defined(MRF24WG)
 #define WF_DisplayModuleAssertInfo()
#endif

#if defined(STACK_USE_CCS_SCAN_TASK)
   #include "ccs_wifiscan.h"
#endif

#if defined(STACK_USE_CCS_HTTP1_SERVER)
   #include "ccs_HTTP.h"
#endif

#if defined(STACK_USE_CCS_HTTP2_SERVER)
   #include "ccs_HTTP2.h"
#endif

#if defined(STACK_USE_CCS_TWITTER)
   #include "ccs_twitter.h"
#endif

#if defined(STACK_USE_CCS_SMTP)
   #include "ccs_SMTP.h"
#endif

#if defined(STACK_USE_CCS_TFTP_SERVER)
   #include "ccs_TFTPs.h"
#endif

#if defined(STACK_USE_CCS_SNTP_CLIENT)
   #include "ccs_SNTP.h"
#endif

#if defined(STACK_USE_CCS_GRATUITOUS_ARP)
   #include "ccs_gratarp.h"
#endif

#define TickGetDiff(a, b)  (a-b)

#define MY_MAC_BYTE1                    AppConfig.MyMACAddr.v[0]
#define MY_MAC_BYTE2                    AppConfig.MyMACAddr.v[1]
#define MY_MAC_BYTE3                    AppConfig.MyMACAddr.v[2]
#define MY_MAC_BYTE4                    AppConfig.MyMACAddr.v[3]
#define MY_MAC_BYTE5                    AppConfig.MyMACAddr.v[4]
#define MY_MAC_BYTE6                    AppConfig.MyMACAddr.v[5]

#define MY_MASK_BYTE1                   AppConfig.MyMask.v[0]
#define MY_MASK_BYTE2                   AppConfig.MyMask.v[1]
#define MY_MASK_BYTE3                   AppConfig.MyMask.v[2]
#define MY_MASK_BYTE4                   AppConfig.MyMask.v[3]

#define MY_IP                           AppConfig.MyIPAddr

#define MY_IP_BYTE1                     AppConfig.MyIPAddr.v[0]
#define MY_IP_BYTE2                     AppConfig.MyIPAddr.v[1]
#define MY_IP_BYTE3                     AppConfig.MyIPAddr.v[2]
#define MY_IP_BYTE4                     AppConfig.MyIPAddr.v[3]

#define MY_GATE_BYTE1                   AppConfig.MyGateway.v[0]
#define MY_GATE_BYTE2                   AppConfig.MyGateway.v[1]
#define MY_GATE_BYTE3                   AppConfig.MyGateway.v[2]
#define MY_GATE_BYTE4                   AppConfig.MyGateway.v[3]

#if defined(STACK_USE_CCS_SNTP_CLIENT)
       #if !defined(STACK_USE_DNS)
           #define STACK_USE_DNS
       #endif
       #if !defined(STACK_USE_UDP)
           #define STACK_USE_UDP
       #endif       
#endif

#if defined(STACK_USE_CCS_HTTP2_SERVER)
   #ifndef STACK_USE_MPFS
      #define STACK_USE_MPFS
    #endif
#endif

#if defined(STACK_USE_CCS_SNTP_CLIENT)
   #if !defined(STACK_CLIENT_MODE)
       #define STACK_CLIENT_MODE
   #endif
#endif

#if STACK_USE_WIFI
   // if defined, MyWFIsConnected() won't return TRUE in AdHoc mode until after
   // it receives some IP traffic.  It will then stay connected until after 5
   // minutes of no activity.
   #define WIFI_ADHOC_CONNECTION_TIMER ((TICK)TICKS_PER_SECOND * 300)
   
   extern unsigned int8 g_connectionProfileID;
   
   #if defined(WIFI_ADHOC_CONNECTION_TIMER)
   extern int1 g_WifiAdhocIsConn;
   extern TICK g_WifiAdhocTickConn;
   #endif
   
   // this is optional
   extern tWFDeviceInfo g_tWFDeviceInfo;
   #define WIFI_GET_VERSION_INFO g_tWFDeviceInfo
   
   extern unsigned int8 WIFI_channelList[16];
   extern unsigned int8 WIFI_numChannelsInList;
   extern unsigned int8 WIFI_region;
   extern int1 g_WifiConnectFail;
   
   // this is similar to MACIsLinked() and WFisConnected().  this one has some
   // filters and extra UI logic to better represent link status to the user.
   // use this for UI displays.
   // REMOVED - Use IsLinked() instead
   //int1 MyWFisConnected(void);
   
   // This routine does a few things:
   //  * Reset WIFI unit if no it goes a long time without a connection,
   //       because old modules would hang on WPA connect failure.
   //  * Ad-Hoc connection timer support (WIFI_ADHOC_CONNECTION_TIMER)
   //  * LED Traffic flickering and LED connection status
   void WIFIConnectTask(void);
   void WIFIConnectInitStates(void);
   
   #if defined(WF_FORCE_NO_PS_POLL)
      void WF_CCS_PsPollDisable(void);
   #endif
#endif

int1 DHCPBoundOrDisabled(void);

// A higher level version of MACIsLinked().
//  - returns FALSE if MACIsLinked() is TRUE -but- DHCP is enabled and not
//       bound.
//  - returns FALSE in WIFI if using AdHoc mode and it has been a while
//       since no traffic
//  - else, returns MACIsLinked()
int1 IsLinked(void);

//this macro called by stack when new tcp/ip traffic tx/rx.
#if STACK_USE_WIFI
   #define STACK_USE_CCS_TX_EVENT()  LinkTraffic(TRUE)
   #define STACK_USE_CCS_RX_EVENT()  LinkTraffic(FALSE)
   void LinkTraffic(int1 isTx);
   
   #define WF_SECURITY_NUM_CHOICES  (WF_SECURITY_WEP_AUTO+1)
#endif

#if defined(STACK_USE_MPFS)
   #include "TCPIP Stack/mpfs.h"
   
   extern MPFS _MpfsEofLoc;
   
   //returns number of bytes read before EOF.
   //if it returns n then no EOF.
   unsigned int16 MPFSGetBytes(unsigned int8 *pDest, unsigned int16 n);
#endif

#if defined(__PCH__)
TICK TickGetSafe(void);
#endif

BYTE GenerateRandomByteFromTimers(void);

#endif
