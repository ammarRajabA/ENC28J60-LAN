///////////////////////////////////////////////////////////////////////////
///                                                                     ///
///                            CCS_SNTP.H                               ///
///                                                                     ///
/// Simple Network Time Protocol  for the Microchip TCP/IP stack.       ///
/// NOTE: THIS IS A DIFFERENT SNTP.H THAN WHAT MICROCHIP PROVIDES       ///
///                                                                     ///
/// See CCS_SNTP.C for documenation                                     ///
///                                                                     ///
///////////////////////////////////////////////////////////////////////////
////        (C) Copyright 1996,2006 Custom Computer Services           ////
//// This source code may only be used by licensed users of the CCS C  ////
//// compiler.  This source code may only be distributed to other      ////
//// licensed users of the CCS C compiler.  No other use, reproduction ////
//// or distribution is permitted without written permission.          ////
//// Derivative programs created using this software in object code    ////
//// form are not restricted in any way.                               ////
///////////////////////////////////////////////////////////////////////////

#ifndef __CCS_SNTP_H__
#define __CCS_SNPT_H__

void NTPInit(void);
void NTPTask(void);
DWORD NTPGetUTCSeconds(void);
int1 NTPOk(void); //time stored is valid.
int1 NTPBusy(void);

#endif
