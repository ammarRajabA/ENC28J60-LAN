/******************************************************************************

 MRF24WB0M Driver Customization
 Module for Microchip TCP/IP Stack
  -Provides access to MRF24WB0M WiFi controller
  -Reference: MRF24WB0M Data sheet, IEEE 802.11 Standard

*******************************************************************************
 FileName:      WF_Config.h
 Dependencies:   TCP/IP Stack header files
 Processor:      PIC18, PIC24F, PIC24H, dsPIC30F, dsPIC33F, PIC32
 Compiler:      Microchip C32 v1.10b or higher
            Microchip C30 v3.22 or higher
            Microchip C18 v3.34 or higher
 Company:      Microchip Technology, Inc.

 Software License Agreement

 Copyright (C) 2002-2010 Microchip Technology Inc.  All rights reserved.

 Microchip licenses to you the right to use, modify, copy, and distribute:
 (i)  the Software when embedded on a Microchip microcontroller or digital
      signal controller product ("Device") which is integrated into
      Licensee's product; or
 (ii) ONLY the Software driver source files ENC28J60.c, ENC28J60.h,
      ENCX24J600.c and ENCX24J600.h ported to a non-Microchip device used in
     conjunction with a Microchip ethernet controller for the sole purpose
     of interfacing with the ethernet controller.

 You should refer to the license agreement accompanying this Software for
 additional information regarding your rights and obligations.

 THE SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
 KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY
 OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE AND
 NON-INFRINGEMENT. IN NO EVENT SHALL MICROCHIP BE LIABLE FOR ANY INCIDENTAL,
 SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST
 OF PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY OR SERVICES, ANY CLAIMS BY
 THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), ANY CLAIMS
 FOR INDEMNITY OR CONTRIBUTION, OR OTHER SIMILAR COSTS, WHETHER ASSERTED ON
 THE BASIS OF CONTRACT, TORT (INCLUDING NEGLIGENCE), BREACH OF WARRANTY, OR
 OTHERWISE.


 Author            Date      Comment
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 KH                 27 Jan 2010 Created for MRF24WB0M
******************************************************************************/


#ifndef __WF_CONFIG_H_
#define __WF_CONFIG_H_

#include "TCPIP Stack/WFApi.h"

/*
*********************************************************************************************************
*                                           DEFINES
*********************************************************************************************************
*/

/*----------------------------------------------------------------------------*/
/* This block of defines allows for code and data reduction by removing       */
/* WiFi driver code and or data that is not needed by the application.        */
/* Comment out those function blocks that are not needed.                     */
/*----------------------------------------------------------------------------*/
//#define WF_USE_SCAN_FUNCTIONS
//#define WF_USE_TX_POWER_CONTROL_FUNCTIONS
//#define WF_USE_POWER_SAVE_FUNCTIONS
//#define WF_USE_MULTICAST_FUNCTIONS
#define WF_USE_INDIVIDUAL_SET_GETS
//#define WF_USE_GROUP_SET_GETS
//#define WF_USE_DATA_TX_RX_FUNCTIONS
//#define USE_GRATUITOUS_ARP



/*= WF_ASSERT MACRO ==================================================================*/
/* Customize how the WiFi driver assert macro (WF_ASSERT) should operate.             */
/*  To DISABLE the WF_ASSERT macro: Comment out '#define WF_DEBUG'                    */
/*  To ENABLE the WF_ASSERT macro:  Unomment out '#define WF_DEBUG'                   */
/*====================================================================================*/
#ifndef WF_NO_DEBUG
//#define WF_DEBUG
#endif

/*--------------------------------------------*/
/* Default settings for Connection Management */
/*--------------------------------------------*/
#ifndef MY_DEFAULT_SSID_NAME
#define MY_DEFAULT_SSID_NAME                "MY_WIFI"
#endif


#ifndef MY_DEFAULT_ADHOC_SSID_NAME
#define MY_DEFAULT_ADHOC_SSID_NAME          "EZWEB"
#endif

#ifndef MY_DEFAULT_NETWORK_TYPE
#define MY_DEFAULT_NETWORK_TYPE             WF_INFRASTRUCTURE   /* WF_INFRASTRUCTURE or WF_ADHOC     */
#endif

#ifndef MY_DEFAULT_ADHOC_BEHAVIOR
#define MY_DEFAULT_ADHOC_BEHAVIOR           WF_ADHOC_CONNECT_THEN_START
#endif

#ifndef MY_DEFAULT_SCAN_TYPE
#define MY_DEFAULT_SCAN_TYPE                WF_ACTIVE_SCAN      /* WF_ACTIVE_SCAN or WF_PASSIVE_SCAN */
#endif

#ifndef MY_DEFAULT_CHANNEL_LIST
#define MY_DEFAULT_CHANNEL_LIST             {}            /* use {} to scan all channels       */
#endif

#ifndef MY_DEFAULT_LIST_RETRY_COUNT
#define MY_DEFAULT_LIST_RETRY_COUNT         (3)
#endif

#ifndef MY_DEFAULT_EVENT_NOTIFICATION_LIST
#define MY_DEFAULT_EVENT_NOTIFICATION_LIST  (WF_NOTIFY_CONNECTION_ATTEMPT_SUCCESSFUL  |         \
                                             WF_NOTIFY_CONNECTION_ATTEMPT_FAILED      |         \
                                             WF_NOTIFY_CONNECTION_TEMPORARILY_LOST    |         \
                                             WF_NOTIFY_CONNECTION_PERMANENTLY_LOST    |         \
                                             WF_NOTIFY_CONNECTION_REESTABLISHED)
#endif

#ifndef MY_DEFAULT_WIFI_SECURITY_MODE
#define MY_DEFAULT_WIFI_SECURITY_MODE        WF_SECURITY_OPEN
#endif

#ifndef MY_DEFAULT_WIFI_SECURITY_WEP_KEYTYPE
#define MY_DEFAULT_WIFI_SECURITY_WEP_KEYTYPE  WF_SECURITY_WEP_SHAREDKEY
#endif

#ifndef MY_DEFAULT_REGION
#define MY_DEFAULT_REGION                    WF_DOMAIN_FCC
#endif

#ifndef MY_DEFAULT_BEACON_TIMEOUT
#define MY_DEFAULT_BEACON_TIMEOUT            100
#endif

#if ((MY_DEFAULT_NETWORK_TYPE == WF_ADHOC) && (MY_DEFAULT_SECURITY_MODE > WF_SECURITY_WEP_104))
   #error ADHOC Mode only works with Open, WEP40, or WEP104 security
#endif

/*****************************************************************************/
/*****************************************************************************/
/*                             WIFI SECURITY COMPILE-TIME DEFAULTS           */
/*****************************************************************************/
/*****************************************************************************/
// Security modes available on WiFi network:
//   WF_SECURITY_OPEN                      : No security
//   WF_SECURITY_WEP_40                    : WEP Encryption using 40 bit keys
//   WF_SECURITY_WEP_104                   : WEP Encryption using 104 bit keys
//   WF_SECURITY_WPA_WITH_KEY              : WPA-PSK Personal where binary key is given to MRF24WB0M
//   WF_SECURITY_WPA_WITH_PASS_PHRASE      : WPA-PSK Personal where passphrase is given to MRF24WB0M and it calculates the binary key
//   WF_SECURITY_WPA2_WITH_KEY             : WPA2-PSK Personal where binary key is given to MRF24WB0M
//   WF_SECURITY_WPA2_WITH_PASS_PHRASE     : WPA2-PSK Personal where passphrase is given to MRF24WB0M and it calculates the binary key
//   WF_SECURITY_WPA_AUTO_WITH_KEY         : WPA-PSK Personal or WPA2-PSK Personal where binary key is given and MRF24WB0M will
//                                             connect at highest level AP supports (WPA or WPA2)
//   WF_SECURITY_WPA_AUTO_WITH_PASS_PHRASE : WPA-PSK Personal or WPA2-PSK Personal where passphrase is given to MRF24WB0M and it
//                                             calculates the binary key and connects at highest level AP supports (WPA or WPA2)

// Default pass phrase used for WF_SECURITY_WPA_WITH_PASS_PHRASE and
// WF_SECURITY_WPA2_WITH_PASS_PHRASE security modes
#if (((MY_DEFAULT_SECURITY_MODE == WF_SECURITY_WPA_WITH_PASS_PHRASE) ||    \
      (MY_DEFAULT_SECURITY_MODE == WF_SECURITY_WPA2_WITH_PASS_PHRASE) ||   \
      (MY_DEFAULT_SECURITY_MODE == WF_SECURITY_WPA_AUTO_WITH_PASS_PHRASE)) && \
      !defined(MY_DEFAULT_PSK_PHRASE))
#define MY_DEFAULT_PSK_PHRASE               "Microchip 802.11 Secret PSK Password"
#endif

// If using security mode of WF_SECURITY_WPA_WITH_KEY or WF_SECURITY_WPA2_WITH_KEY, then this section
// must be set to  match the key for MY_DEFAULT_SSID_NAME and MY_DEFAULT_PSK_PHRASE
// combination.  The values below are derived from the SSID "MicrochipDemoAP" and the pass phrase
// "Microchip 802.11 Secret PSK Password".
// The tool at http://www.wireshark.org/tools/wpa-psk.html can be used to generate this field.
#if (((MY_DEFAULT_SECURITY_MODE == WF_SECURITY_WPA_WITH_KEY) ||    \
      (MY_DEFAULT_SECURITY_MODE == WF_SECURITY_WPA2_WITH_KEY) ||   \
      (MY_DEFAULT_SECURITY_MODE == WF_SECURITY_WPA_AUTO_WITH_KEY)) && \
      !defined(MY_DEFAULT_PSK))
#define MY_DEFAULT_PSK "\x86\xC5\x1D\x71\xD9\x1A\xAA\x49\x40\xC8\x88\xC6\xE9\x7A\x4A\xD5\xE5\x6D\xDA\x44\x8E\xFB\x9C\x0A\xE1\x47\x81\x52\x31\x1C\x13\x7C"
#endif

//-----------------------------------------------------------------------------------
// Default WEP keys used in WF_SECURITY_WEP_40  and WF_SECURITY_WEP_104 security mode
//-----------------------------------------------------------------------------------
//#define MY_DEFAULT_WEP_PHRASE           "WEP Phrase"

// string 4 40-bit WEP keys -- corresponding to passphraseof "WEP Phrase"
#if ((MY_DEFAULT_SECURITY_MODE == WF_SECURITY_WEP_40) && !defined(MY_DEFAULT_WEP_KEYS_40))
#define MY_DEFAULT_WEP_KEYS_40 "\x5a\xfb\x6c\x8e\x77\xc1\x04\x49\xfd\x4e\x43\x18\x2b\x33\x88\xb0\x73\x69\xf4\x78"
#endif

// string containing 4 104-bit WEP keys -- corresponding to passphraseof "WEP Phrase"
#if ((MY_DEFAULT_SECURITY_MODE == WF_SECURITY_WEP_104) && !defined(MY_DEFAULT_WEP_KEYS_104))
#define MY_DEFAULT_WEP_KEYS_104 "\xdf\xdd\x34\x43\xf6\xd5\x4d\xd1\x4f\xa0\xfC\x7e\xb8\xdf\xdd\x34\x43\xf6\xd5\x4d\xd1\x4f\xa0\xfC\x7e\xb8\xdf\xdd\x34\x43\xf6\xd5\x4d\xd1\x4f\xa0\xfC\x7e\xb8\xdf\xdd\x34\x43\xf6\xd5\x4d\xd1\x4f\xa0\xfC\x7e\xb8"
#endif

/* Valid Key Index: 0, 1, 2, 3  */
#ifndef MY_DEFAULT_WEP_KEY_INDEX
#define MY_DEFAULT_WEP_KEY_INDEX        (0)
#endif


#endif /* __WF_CONFIG_H_ */


