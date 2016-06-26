//////////////////////////////////////////////////////////////////////////////
///
///                              TFTP.C
///
/// Implements a TFTP server.  
///
/// **** CONFIGURATION ****
///
/// STACK_USE_CCS_TFTP_SERVER - Define this before you include stacktsk.c
///        in your application.  Defining this will cause
///        the stack to include the TFTP portion and execute the init
///        and process any TFTP tasks.
///
/// TFTP_REQUIRE_FNAME1, TFTP_REQUIRE_FNAME2 - if you only want to allow
///   certain filenames to be uploaded, define these filenames.  Then also
///   define TFTP_REQUIRE_LOC1 and TFTP_REQUIRE_LOC2 to denote where these
///   files go.
///
/// END_OF_MPFS_POINTER, TFTP_REQUIRE_LOC1, TFTP_REQUIRE_LOC2 -
///   User must define these values.
///   The place where files that get uploaded are stored.
///   If you are not using forced filenames, all uploads goto 
///   END_OF_MPFS_POINTER.
///   The first 4 bytes of this location is used by the TFTP server as an 
///   EOF marker.  The actual contents of this file are placed after
///   this marker.
///
/// TFTPS_STARTED_FILE(x) - Macro x called when a new upload is started.
///   if TFTP_REQUIRE_FNAME1 or TFTP_REQUIRE_FNAME2 is defined, then x
///   will be either 0 or 1.  If they are not defined, x will always be 0.
///
/// TFTPS_FINISHED_FILE(x) - Similar to TFTPS_STARTED_FILE(x), but called when file
///   is finished.
///
/// TFTP_PORT - The TCP/IP port the TFTP server will listen to for TFTP
///        connections.  Port 69 is almost exclusively used for TFTP traffic
///
/// TFTP_MAX_HEADER_LENGTH - Maximum length of the TFTP header portion of the
///        incoming packet.  This does not include the data in a TFTP data packet
///
/// TFTP_MAX_DATA_LENGTH - Defines the length of the data portion of a complete
///        TFTP data packet.  This should generally not be modified unless you
///        really know what you are doing.  TFTP uses this length to determine
///        when to terminate a file transfer connection. 
///        TFTP specification says that if a TFTP datagram is less than 516 bytes
///        in length, then it is the last packet of a file transfer.
///
///
/// **** HOW IT WORKS ****
/// TFTP is a very simple (trivial) form of the File Transfer Protocol (FTP).  
/// TFTP is designed to operate on top of the UDP protocol (although it isn't
/// required to do so).  Only requests for file writing from the client 
/// to the server are granted by the server.  Write requests will automatically
/// overwrite an existing file on the server's MMC (no append).  In the case
/// that a file does not exist, one will be created.  Specify the path and
/// file name in the destination field of your TFTP client.  Filenames without
/// a path will be stored in the root directory of the MMC.  Keep filenames
/// to the DOS-style (8.3) format.  All files should be sent in octec (binary,
/// image) mode (-i option in Windows' command-line TFTP program).
///
/// MPFSPut() is very slow, for speed increase this library uses 
/// SPIFlashWriteBytes() directly.
///
///
////////////////////////////////////////////////////////////////////////////////
///
/// * Author         Date              Comment
/// *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
///
/// * Nick LaBonte   Feb 15 2007       Initial version
/// * Nick LaBonte   Feb 22 2007       MPFS support, cleanup
/// * Darren Rook    Apr 16 2011       Added TCP/IP V5 support, 
///                                    TFTPS_FINISHED_FILE(), 
///                                    TFTPS_STARTED_FILE(),
///                                    TFTP_REQUIRE_FNAMEx,
///                                    GENERIC_SCRATCH_BUFFER support.
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
#ifndef THIS_IS_TFTP_C
#define THIS_IS_TFTP_C

#if 0
//#if STACK_USE_WIFI
   #define TFTPS_Disable_TCPIP_ISR()   WF_EintDisable()
   #define TFTPS_Enable_TCPIP_ISR()    WF_EintEnable()
#else
   #define TFTPS_Disable_TCPIP_ISR()
   #define TFTPS_Enable_TCPIP_ISR()
#endif

#if 0
//#if STACK_USE_WIFI
   #define TFTPS_Wait_For_Flush()   while(!MACIsTxReady())
#else
   #define TFTPS_Wait_For_Flush()
#endif


#ifndef debug_tftp
 #define debug_tftp_putc(c)
 #define debug_tftp(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z)
#endif

#if !defined(MPFS_USE_SPI_FLASH) && !defined(STACK_USE_MPFS)
 #error MPFS with SPI Flash library required.
#endif

#ifndef TFTP_WRITE_ENABLED
#define TFTP_WRITE_ENABLED 1
#endif

#ifndef TFTP_READ_ENABLED
#define TFTP_READ_ENABLED 1
#endif

#ifndef TFTPS_FINISHED_FILE
#define TFTPS_FINISHED_FILE(x)
#endif

#ifndef TFTPS_STARTED_FILE
#define TFTPS_STARTED_FILE(x)
#endif

#define MPFS_CLEAR_BLOCK() mpfsFlags.bits.bNotAvailable = 0
#define MPFS_SET_BLOCK()   mpfsFlags.bits.bNotAvailable = 1

static TICK             TFTPlastActivity;   // Timeout keeper.

UDP_SOCKET       TFTPSocket;
SM_TFTP          smTFTP;

unsigned int16            last_block;
unsigned int16            last_sent;
int1             bad_block=0;   

#if TFTP_READ_ENABLED
unsigned int32            last_mem_begin;
unsigned int32            end_of_mpfs;
#endif

unsigned int32            TFTPaddy;

TFTP_EC          TFTPec;

int1             TFTPconnected = 0;
int1             received_final_packet=0;

#if defined(GENERIC_SCRATCH_BUFFER)
#define TFTPS_SCRATCH_BUFFER   GENERIC_SCRATCH_BUFFER
#else
char TftpsScratchBuffer[TFTP_BUFFER_SIZE];
#define TFTPS_SCRATCH_BUFFER TftpsScratchBuffer
#endif

#if sizeof(TFTPS_SCRATCH_BUFFER) < TFTP_BUFFER_SIZE
 #error Generic scratch buffer isnt' big enough
#endif


void execute_tftp_command(void);
void send_data(void);


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
void TFTPSInit(void)
{
   uint16_t port;
   port = TFTP_PORT;
   if (port != 0)
   {
      TFTPSocket       = UDPOpen(port, NULL, INVALID_UDP_SOCKET);
      smTFTP           = SM_TFTP_WAIT;
   }
   else
   {
      smTFTP = SM_TFTP_HOLD;
   }
}

unsigned int8 g_TFTPFilename = -1;   //-1 if invalid

// given chosen filename, starting location in eeprom/flash.
// this location holds 4byte size marker.
// after this marker is where the file got uploaded
unsigned int32 TFTPFileFileStart(void)
{
   unsigned int32 ret;
   
           #if defined(TFTP_REQUIRE_FNAME1) || defined(TFTP_REQUIRE_FNAME2)
            #if defined(TFTP_REQUIRE_FNAME1)
             if (g_TFTPFilename == 0)
               ret = TFTP_REQUIRE_LOC1;
            #endif
            #if defined(TFTP_REQUIRE_FNAME2)
             if (g_TFTPFilename == 1)
               ret = TFTP_REQUIRE_LOC2;
            #endif            
           #else
            ret = END_OF_MPFS_POINTER;
           #endif
            
   return(ret);
}

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
void TFTPSTask(void)
{  
   //int16 i=0;
   TICK currentTick;
    
   switch(smTFTP){
   
   case SM_TFTP_WAIT:
      if(UDPIsGetReady(TFTPSocket)){
         TFTPconnected = 1;
         TFTPlastActivity  = TickGet();
         execute_tftp_command();
         UDPDiscard();
      }else if(TFTPconnected) {
         currentTick = TickGet();
         currentTick = TickGetDiff(currentTick, TFTPlastActivity);
         if ((currentTick >= TFTP_TIMEOUT) && UDPIsPutReady(TFTPSocket))
         {
             TFTPlastActivity                = TickGet();
             if(received_final_packet)
             {
                smTFTP                      = SM_TFTP_END;
             }
            #if TFTP_READ_ENABLED
             else
             {
               debug_tftp(debug_tftp_putc, "\r\nTFTPS Wait send_data() ");
               send_data();
             }
            #endif
         }
      }
      
      break;
   
   case SM_TFTP_ACK:
         if(!bad_block)
         {
            for(;;)
            {
               TFTPS_Disable_TCPIP_ISR();
               if (UDPIsPutReady(TFTPSocket) >= 4)
               {
                  UDPPut(0);
                  UDPPut(TFTP_OPCODE_ACK);
                  UDPPut(make8(last_block,1));
                  UDPPut(make8(last_block,0));
                  UDPFlush();
                  TFTPS_Enable_TCPIP_ISR(); 
                  debug_tftp(debug_tftp_putc, "\r\nTFTPS Write ACK %LX ", last_block);
                  TFTPS_Wait_For_Flush();
                  break;
               }
               TFTPS_Enable_TCPIP_ISR(); 
            }
         } 
         if(received_final_packet)
         {
            unsigned int32 startAddy;
          #if TFTP_WRITE_ENABLED
            startAddy = TFTPFileFileStart();
            debug_tftp(debug_tftp_putc, "\r\nTFTPS Write EOF Marker=0x%LX @ 0x%LX ", TFTPaddy, startAddy);
            SPIFlashWriteBytes(startAddy, &TFTPaddy, 4); //write eof marker
            MPFS_CLEAR_BLOCK();
            TFTPS_FINISHED_FILE(g_TFTPFilename);
          #endif
            smTFTP = SM_TFTP_END;
         }
         else
         {
            smTFTP = SM_TFTP_WAIT;

         }
     // }
      break;
      
   case SM_TFTP_ERROR:
      for(;;)
      {
         TFTPS_Disable_TCPIP_ISR(); 
         if(UDPIsPutReady(TFTPSocket) >= 30)
         {
            UDPPut(0);
            UDPPut(TFTP_OPCODE_ERROR);
            UDPPut(0);
            UDPPut(TFTPec);
         
            switch(TFTPec){
            case TFTP_EC_GENERIC:
               printf(UDPPut, "Undefined Error");
               break;
               
            case TFTP_EC_BAD_CMD:
               printf(UDPPut, "Command Not Supported");
               break;
               
            case TFTP_EC_ACCESS:
               printf(UDPPut, "Memory Access Violation");
               break;
               }
            
            UDPPut(0);
            UDPFlush();
            TFTPS_Enable_TCPIP_ISR();            
            debug_tftp(debug_tftp_putc, "\r\nTFTPS ERROR %X ", TFTPec);            
            TFTPS_Wait_For_Flush();
            break;
         }
         TFTPS_Enable_TCPIP_ISR();
      }
      smTFTP = SM_TFTP_END;
      
   //no break needed
   case SM_TFTP_END:
      received_final_packet = 0;
      TFTPconnected=0;
      last_block=0;
      last_sent=0;
      smTFTP = SM_TFTP_WAIT;
      break;
   
   case SM_TFTP_HOLD:
   default:
      break;
   }//switch(SM_TFTP)

}//TFTPTask()

void _TFTPGetFilename(void)
{
#if defined(TFTP_REQUIRE_FNAME1) || defined(TFTP_REQUIRE_FNAME2)
   char c;
   unsigned int8 j=0;
   
   UDPGet(&c);
   if(c=='/')
      UDPGet(&c);
      
   j=0;
   while(c!=0&&c!='/'){
      TFTPS_SCRATCH_BUFFER[j++]=c;
      UDPGet(&c);
   }
   TFTPS_SCRATCH_BUFFER[j] = 0;
   
   g_TFTPFilename = -1;
   
  #if defined(TFTP_REQUIRE_FNAME1)
   if (stricmp(TFTPS_SCRATCH_BUFFER, TFTP_REQUIRE_FNAME1) == 0)
   {
      g_TFTPFilename = 0;
   }
  #endif
  #if defined(TFTP_REQUIRE_FNAME2)
   if (stricmp(TFTPS_SCRATCH_BUFFER, TFTP_REQUIRE_FNAME2) == 0)
   {
      g_TFTPFilename = 1;
   }
  #endif
#else
   g_TFTPFilename = 0;
#endif
}

//execute_tftp_command()
//used by TFTPTask() to parse and act on a received TFTP packet
void execute_tftp_command(void){
   BYTE op;
   char c;
   union
   {
      unsigned int8 b[2];
      unsigned int16 w;
   } block;
   unsigned int32 j=0;
   unsigned int32 k;
   UDPGet(&op);//first byte is 0
   UDPGet(&op);
   
   
   switch (op){
   case TFTP_OPCODE_RRQ:
  #if TFTP_READ_ENABLED
      _TFTPGetFilename();
      if (g_TFTPFilename == -1)
      {
         TFTPec=TFTP_EC_GENERIC;
         smTFTP=SM_TFTP_ERROR;      
         debug_tftp(debug_tftp_putc, "\r\nTFTPS RRQ Invalid Filename");
      }
      else
      {
         if(last_block!=0)
         {
            smTFTP = SM_TFTP_ERROR;
            TFTPec = TFTP_EC_GENERIC;
         }
         else
         {
            SPIFlashReadArray(TFTPFileFileStart(), &end_of_mpfs, 4);
            debug_tftp(debug_tftp_putc, "\r\nTFPTS Get Marker=%LX @ 0x%LX ", end_of_mpfs, TFTPFileFileStart());
            last_sent=1;
            last_mem_begin=TFTPFileFileStart()+4;
            send_data();
         }
      }
  #else
      smTFTP = SM_TFTP_ERROR;
      TFTPec = TFTP_EC_BAD_CMD; 
  #endif
   break;
   
   
   case TFTP_OPCODE_WRQ:
  #if TFTP_WRITE_ENABLED
      _TFTPGetFilename();
      if (g_TFTPFilename == -1)
      {
         TFTPec=TFTP_EC_GENERIC;
         smTFTP=SM_TFTP_ERROR;      
         debug_tftp(debug_tftp_putc, "\r\nTFTPS WRQ Invalid Filename");
      }
      else
      {
         TFTPS_STARTED_FILE(g_TFTPFilename);
         TFTPaddy = TFTPFileFileStart()+4;
         debug_tftp(debug_tftp_putc, "\r\nTFTPS New file (%u) Marker=0x%LX ", g_TFTPFilename, TFTPaddy-4);
         MPFS_SET_BLOCK();
         smTFTP = SM_TFTP_ACK;
         last_block= 0;
         bad_block=0;
      }
  #else
      smTFTP = SM_TFTP_ERROR;
      TFTPec = TFTP_EC_BAD_CMD; 
  #endif
   break;

case TFTP_OPCODE_DATA:
      smTFTP = SM_TFTP_ACK;
      UDPGet(&block.b[1]);
      UDPGet(&block.b[0]);
      if(block.w==last_block)
      {
         bad_block = 0; //just ack the repeat block
         UDPDiscard();
      }
      else if(block.w==(last_block+1))
      {
         bad_block=0;
         last_block++;
         k = 0;
         for(;;)
         {
            j=0;
            while(UDPGet(&c)){
               TFTPS_SCRATCH_BUFFER[j++]=c;
               if(j==TFTP_BUFFER_SIZE)
                  break;
            }

            k+=j;
            TFTPaddy+=j;
            SPIFlashWriteBytes((TFTPaddy-j), TFTPS_SCRATCH_BUFFER, j);
            debug_tftp(debug_tftp_putc, "\r\nTFTPS WriteBlock (%LU) Size=%LU @ 0x%LX ", block.w, j, TFTPaddy-j);
            if(!UDPIsGetReady(TFTPSocket))
               break;
         } 

         //FTPWriteMMC=1;
         if(k<TFTP_MAX_DATA_LENGTH){
            received_final_packet= 1;
         }
      }
      else
      {
         bad_block=1;
      }
      break;
   
   case TFTP_OPCODE_ACK:
   #if TFTP_READ_ENABLED
      UDPGet(&block.b[1]);
      UDPGet(&block.b[0]);

      debug_tftp(debug_tftp_putc, "\r\nTFTPS Opcode Ack (%LU) last=%lu ", block.w last_sent);

      if(block.w==(last_sent)){
         last_sent++;
      }
      if(!received_final_packet){
        send_data(); 
      }else
         smTFTP=SM_TFTP_END;
   #else
      smTFTP = SM_TFTP_ERROR;
      TFTPec = TFTP_EC_BAD_CMD;
   #endif
   break;
   
   case TFTP_OPCODE_ERROR:
      smTFTP = SM_TFTP_END;
   break;
   
   default:
      smTFTP = SM_TFTP_ERROR;
      TFTPec = TFTP_EC_GENERIC;
   
   }
   
}

#if TFTP_READ_ENABLED
void send_data(void){
   unsigned int32  j=0;
   unsigned int32  i=0;
   unsigned int32  k=0;
   
   TFTPS_Disable_TCPIP_ISR();
   if (UDPIsPutReady(TFTPSocket) < TFTP_MAX_DATA_LENGTH)
   {
      TFTPS_Enable_TCPIP_ISR();
      return;
   }
   
   UDPPut(0);
   UDPPut(3);
   UDPPut(make8(last_sent,1));
   UDPPut(make8(last_sent,0));
 
   for(;;)
   {
      j= TFTP_BUFFER_SIZE > (end_of_mpfs-last_mem_begin) ? end_of_mpfs-last_mem_begin : TFTP_BUFFER_SIZE;
      j= k+j > TFTP_MAX_DATA_LENGTH ? TFTP_MAX_DATA_LENGTH-k : j;
      SPIFlashReadArray(last_mem_begin, TFTPS_SCRATCH_BUFFER, j);
      debug_tftp(debug_tftp_putc, "\r\nTFTPS (%lu) ReadBlock Size=%LU @ 0x%LX ", last_sent, j, last_mem_begin);

      k+=j;
      last_mem_begin+=j;
      
      for(i=0; i<j; ++i)
         UDPPut(TFTPS_SCRATCH_BUFFER[i]);
      
      if(k==TFTP_MAX_DATA_LENGTH)
         break;
         
      if(j<TFTP_BUFFER_SIZE)
         break;
   }
   if(k<TFTP_MAX_DATA_LENGTH)
      received_final_packet=1;
   
   debug_tftp(debug_tftp_putc, "\r\nTFTPS ReadBlock Flush %LX (%U) ", last_sent, received_final_packet);
   
   UDPFlush();
   TFTPS_Enable_TCPIP_ISR();
   TFTPS_Wait_For_Flush();

   smTFTP=SM_TFTP_WAIT;
}
#endif

#endif
