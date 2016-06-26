// document TFTP_REQUIRE_FNAME1, TFTP_REQUIRE_LOC1, TFTP_REQUIRE_FNAME2, TFTP_REQUIRE_LOC2
//////////////////////////////////////////////////////////////////////////////
///
///                              TFTP.H
///
/// Function definitions for a TFTP server.
///
/// Based loosely on the CCS implementation of the Microchip FTP server.
///
/// ****Function Descriptions****
/// void TFTPSInit(void) - Opens a UDP socket on port 69 for TFTP transfers.
///                       Must be called prior to calling any other TFTP functions.
///                       UDP layer must be initialized before calling this.
///
/// void TFTPSTask(void) - Processes any incoming TFTP packets and sends any 
///                       necessary replies.  Works like a task in a multi-process
///                       RTOS; this function must be called routinely.  May not
///                       be called until after TFTPInit() is called.
///      
////////////////////////////////////////////////////////////////////////////////
///
/// * Author         Date              Comment
/// *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
///
/// * Nick LaBonte   Feb 15 2007       Initial version
/// * Nick LaBonte   Feb 22 2007       MPFS implemented, cleanup
///
///////////////////////////////////////////////////////////////////////////
////        (C) Copyright 1996,2007 Custom Computer Services           ////
//// This source code may only be used by licensed users of the CCS C  ////
//// compiler.  This source code may only be distributed to other      ////
//// licensed users of the CCS C compiler.  No other use, reproduction ////
//// or distribution is permitted without written permission.          ////
//// Derivative programs created using this software in object code    ////
//// form are not restricted in any way.                               ////
///////////////////////////////////////////////////////////////////////////
#ifndef TFTP_H
#define TFTP_H

//#if STACK_USE_TFTP
#ifndef TFTP_PORT
#define TFTP_PORT 69
#endif

#define TFTP_MAX_HEADER_LENGTH   32
#define TFTP_MAX_DATA_LENGTH     512
#define TFTP_BUFFER_SIZE         120

#if (TFTP_BUFFER_SIZE>TFTP_MAX_DATA_LENGTH)
   #undefine TFTP_BUFFER_SIZE
   #define TFTP_BUFFER_SIZE      TFTP_MAX_DATA_LENGTH
#endif

/*
#if STACK_USE_MPFS
   #define FILE   MPFS
   #define fatputc(x,y)    MPFSPut(x)
   //#define MPFS_Size       MPFSReserveBlock
#endif
*/

typedef enum _SM_TFTP
{
    SM_TFTP_WAIT=0,
    SM_TFTP_ACK,
    SM_TFTP_ERROR,
    SM_TFTP_END,
    SM_TFTP_HOLD
} SM_TFTP;

typedef int8 TFTP_EC;

#define TFTP_EC_GENERIC    0
#define TFTP_EC_ACCESS     2
#define TFTP_EC_BAD_CMD    4

#define TFTP_OPCODE_RRQ    1
#define TFTP_OPCODE_WRQ    2
#define TFTP_OPCODE_DATA   3
#define TFTP_OPCODE_ACK    4
#define TFTP_OPCODE_ERROR  5

/*
#if !STACK_USE_HTTP2
   static int1 FTPWriteMMC = 0;
#endif
*/



#define TFTP_WRITE_ENABLED    TRUE

#define TFTP_TIMEOUT       (TICK)((TICK)180 * TICK_SECOND)

/*********************************************************************
 * Function:        void TFTPInit(void)
 *
 * PreCondition:    UDP module is already initialized.
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        Opens a UDP socket for use by TFTP
 *
 * Note:
 ********************************************************************/
void TFTPSInit(void);


/*********************************************************************
 * Function:        void TFTPTask(void)
 *
 * PreCondition:    TFTPInit() must already be called.
 *
 * Input:           None
 *
 * Output:          Opened TFTP connections are served.
 *
 * Side Effects:    None
 *
 * Overview:
 *
 * Note:            This function acts as a task (similar to one in
 *                  RTOS).  This function performs its task in
 *                  co-operative manner.  Main application must call
 *                  this function repeatdly to ensure all open
 *                  or new connections are served on time.
 ********************************************************************/
void TFTPSTask(void);


#endif

