// ccs_wifiscan.h
//
// Extra state-machine code for handling AP scanning and getting RSSI of 
// current connection.
//
// Normally, if you perform an AP scan then it will stop RSSI scanning.
// If you use CCS_WIFISCAN_EE_LOC to cache AP results to EE then RSSI
// will continue to happen.  Else, WIFIScanDiscard() will resume RSSI
// scanning.
//
// OPTIONS
// -----------------------------------------------------------------
//    CCS_WIFISCAN_DURING_ADHOC
//       Normally the background RSSI scanning will be disable in AdHoc mode.
//       If you want to turn it back on, define this. But it's probably a 
//       bad idea and might cause module lockups.
//
//    CCS_WIFISCAN_EE_LOC, CCS_WIFISCAN_EE_NUM, CCS_WIFISCAN_EE_SIZE - If 
//       defined then scan results will be immediately saved to the EEPROM.  
//       NUM results will be saved to LOC, where total size used is 
//       1+(NUM*SIZE).  This was implemented because on some B modules the 
//       memory would get corrupted if you start attempt to read scan results 
//       after you start a new connection.  If defined, WIFIScanGetResult() and 
//       WIFIScanGetNum() will read from EE memory instead.  When saved to
//       EE, results with blank SSIDs will be ignored.  The table will also
//       be sorted, highest RSSI first, to maximize the NUM of entries
//       saved to EE in the event your scan finds lots of results.
//
//    CCS_WIFISCAN_DONT_AUTO_CONNECT - If defined the statemachine won't 
//       automatically call WIFIConnectStart() when scan results are found.
//       This is an alternative to the EE method provided above as a
//       workaround to faulty B units.  The intention is that after scan
//       results are found, you would manually call WIFIConnectStart() 
//       after you read them.  WIFIScanDiscard() will always call 
//       WIFIConnectStart() if this is used.
//
//    CCS_WIFISCAN_FIXED_TYPE - If defined, when performing an AP
//       scan will only scan for a certain network type.  This can be
//       defined to WF_INFRASTRUCTURE or WF_ADHOC.  If this isn't defined,
//       WF_Scan will use WF_SCAN_ALL parameter, which will return
//       all types.
//
//    CCS_WIFISCAN_IMMEDIATE_READ - 
//       This doesn't work because of recursion.
//       If defined, on RSSI reads it will immediately pull the scan result
//          from WIFI memory when the event is called (doesn't look like
//          event is called during the ISR).
//       If defined and CCS_WIFISCAN_EE_LOC is defined, on AP scan results
//          it will immediately pull the results and saved to EE on the
//          event handler (doesn't look like
//          event is called during the ISR).
///////////////////////////////////////////////////////////////////////////
////        (C) Copyright 1996, 2013 Custom Computer Services          ////
//// This source code may only be used by licensed users of the CCS C  ////
//// compiler.  This source code may only be distributed to other      ////
//// licensed users of the CCS C compiler.  No other use, reproduction ////
//// or distribution is permitted without written permission.          ////
//// Derivative programs created using this software in object code    ////
//// form are not restricted in any way.                               ////
///////////////////////////////////////////////////////////////////////////

#ifndef __CCS_WIFISCAN_H__
#define __CCS_WIFISCAN_H__

//#define CCS_WIFISCAN_FIXED_TYPE WF_INFRASTRUCTURE
//#define CCS_WIFISCAN_DONT_AUTO_CONNECT
//#define CCS_WIFISCAN_EE_LOC   EE_LOC_RESERVED
//#define CCS_WIFISCAN_EE_SIZE   60
//#define CCS_WIFISCAN_EE_NUM  ((EE_SIZE_RESERVED-1) / CCS_WIFISCAN_EE_SIZE)
//#warning !!!! DEBUG SETTINGS

#ifndef WF_USE_SCAN_FUNCTIONS
#define WF_USE_SCAN_FUNCTIONS
#endif

#ifndef CCS_WIFISCAN_EE_SIZE
#define CCS_WIFISCAN_EE_SIZE  sizeof(tWFScanResult)
#endif

int1 WIFIRSSIIsValid(void);
unsigned int8 WIFIRSSIGet(void);

void WIFIScanStart(void);
int1 WIFIScanIsBusy(void);
int1 WIFIScanIsValid(void);
unsigned int8 WIFIScanGetNum(void);
void WIFIScanGetResult(unsigned int8 index, tWFScanResult *pResult);
unsigned int8 WIFIScanResultSecurityType(tWFScanResult *pResult);

// will cause WIFIScanIsValid() to return FALSE.
// if CCS_WIFISCAN_DONT_AUTO_CONNECT is used, this will call WIFIConnectStart().
// this will also resume RSSI scanning.
void WIFIScanDiscard(void);

// Init() and Task() automatically called by StackTask2.  
// WIFIScanResults() called at WF_EVENT_SCAN_RESULTS_READY.
// WIFIScanIgnoreResults() called if data buffer was cleared (DeallocateDataRxBuffer())
//DO NOT CALL THESE.
void WIFIScanInit(void);
void WIFIScanTask(void);
void WIFIScanIgnoreResults(void);
void WIFIScanResults(unsigned int8 num);

// these callbacks are required.  DO NOT CALL THESE.
void WIFIConnectStop(void);   //you cannot scan during a connection process, only when idle or connected.  this will stop the connect state machine from attempting a connection.  if in the middle of a connection, will reset the MAC with MacInit()
void WIFIConnectStart(void);  //undo a WIFIConnectStop(), called after scanning is done.

#endif
