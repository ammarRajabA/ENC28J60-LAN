//////////////////////////////////////////////////////////////////////////////
///                                                                        ///
///                          ccs_twitter.h                                 ///
///                                                                        ///
/// Provides the functions and state machine needed to send a              ///
/// tweet to Twitter using a PIC capable of connecting to the internet.    ///
///                                                                        ///
/// See ccs_twitter.c for documentation.                                   ///
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

#ifndef __TWITTER_H__
#define __TWITTER_H__

void TwitterInit(char *ConsumerKey, char *ConsumerSecret, char *AccessToken, char *AccessTokenSecret);

void TwitterTask(void);

int1 TwitterIsBusy(void);

void TwitterSend(char *str);

void TwitterCancel(void);

int1 TwitterIsError(void);

#endif
