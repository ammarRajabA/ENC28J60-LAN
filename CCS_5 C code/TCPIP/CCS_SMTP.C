// the documentation in this file may not be up to date
// add SMTPConnectHostname and SMTPConnect
// add SMTPConfigureBasic and SMTPConfigureLogin
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//                                 SMTP.C                                   //
//              SMTP Engine for Microchip TCP/IP Stack API                  //
//
// Define STACK_USE_SMTP to TRUE before including stacktsk.h in your code
// to enable this SMTP API.  Once enabled, you can use these functions:
//
// SMTPConnect(IP_ADDR ip, int16 port, char *from, char *to, char *subject)
//    Will open the IP address and TCP port (which should be your SMTP
//    server), and start the engine that will initiate SMTP connection.
//    The SMTP engine will then send the mail to: and rcpt from: command,
//    and create basic E-Mail headers.  Will return TRUE if successfully
//    started the engine, will return FALSE if a previous engine is still
//    running.
//    Once an engine is running, it will stop running once
//    SMTPIsPutReady() returns TRUE -OR- SMTPLastError() returns a
//    non-zero number.
//
// SMTPIsPutReady()
//    After a succesfull SMTPConnect(), the SMTP engine will be sending
//    SMTP commands.  You cannot start sending the body of the e-mail
//    until the SMTP engine has got the SMTP server in a state that is
//    ready for the body of the e-mail.  SMTPIsPutReady() returns TRUE
//    if the SMTP engine and the SMTP server is ready.
//
// SMTPLastError()
//    If there was an error with the SMTP, this will return non-zero.
//    Once this returns non-zero then you can try again by calling
//    SMTPConnect().
//
// SMTPPut(char c)
//    Puts this char into the body of the e-mail.  SMTPIsPutReady() must
//    return TRUE before this is called.
//
// SMTPDisconnect()
//    Close the e-mail and have the SMTP server send it.  SMTPIsPutReady()
//    must return TRUE before you call this.  After calling this, wait
//    until SMTPIsFree() returns TRUE and use SMTPLastError() to see
//    if the email was sent sucessfully.
//
// SMTPIsFree()
//    Will return TRUE if the SMTP engine is free for another connection.
//
// NOTE: You *MUST* use the SMTP server for your ISP.  If you do not know it
//  then ask your ISP.  The reason for this is that because of the war on
//  spam almost all SMTP servers block access to clients who aren't on their
//  network.
//
// NOTE: The SMTP engine can only handle one socket at a time.  Therefore you
//  cannot call a SMTPConnect() until the previous SMTPConnect() has been
//  disconnected.
//
// NOTE: Due to the war on spam many internet service providers are placing
//  restrictions upon SMTP servers.  Such restrictions may be authentication,
//  sender-id, message-id and max message-per-minute rate.  This engine
//  deals with none of those restrictions.  It's very likely in the future
//  that it will be impossible for a PIC to have the resources to send e-mail
//  using SMTP.
//
// NOTE: If you are using Ethernet, you will have to enable ARP!!!
//
///////////////////////////////////////////////////////////////////////////////

#ifndef debug_smtp
 #define __NO_SMTP_DEBUG_STREAM__
 #define debug_smtp(a,b,c,d,e,f,g,h,i,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z)
 #define debug_smtp_putc(c)
#endif

#ifndef MY_EMAIL_SUBJECT
#define MY_EMAIL_SUBJECT   "Default e-mail subject"
#endif

#ifndef STACK_USE_SMTP_VERBOSE
#define STACK_USE_SMTP_VERBOSE   FALSE
#endif

/*
enum {
   SMTP_STATE_WAITING=0, SMTP_STATE_START=1, SMTP_STATE_ARP_REQ=2,
   SMTP_STATE_ARP_WAIT=3, SMTP_STATE_CONNECT=4, SMTP_STATE_CONNECT_WAIT=5,
   SMTP_STATE_EHLO=6, SMTP_STATE_MAIL_FROM=7, SMTP_STATE_RCPT_TO=8,
   SMTP_STATE_DATA_START=9, SMTP_STATE_DO_CMD=10, SMTP_STATE_DO_CMD_GET_RESP=11,
   SMTP_STATE_PUT_HEADER=12, SMTP_STATE_PUT_BODY=13, SMTP_STATE_FINISH_EMAIL=14,
   SMTP_STATE_FINISH_EMAIL_WAIT=15, SMTP_STATE_EOM=16, SMTP_STATE_CLOSE=17,
   SMTP_STATE_FORCE_CLOSE=18, SMTP_STATE_RESET=19
} smtp_state;
*/

typedef enum {
   SMTP_STATE_IDLE=0,
   SMTP_STATE_START,
   SMTP_STATE_CONNECT, SMTP_STATE_CONNECT_WAIT, SMTP_STATE_EHLO,
   SMTP_STATE_POST_EHLO, SMTP_STATE_START_AUTH_LOGIN, 
   SMTP_STATE_AUTH_LOGIN_SEND_USERNAME,
   SMTP_STATE_AUTH_LOGIN_USERNAME_CONTINUE, 
   SMTP_STATE_AUTH_LOGIN_SEND_PASSWORD, 
   SMTP_STATE_AUTH_LOGIN_PASSWORD_CONTINUE,
   SMTP_STATE_AUTH_PLAIN_SEND, SMTP_STATE_AUTH_PLAIN_SEND_CONTINUE,
   SMTP_STATE_START_AUTH_PLAIN,
   SMTP_STATE_MAIL_FROM, SMTP_STATE_RCPT_TO, SMTP_STATE_DATA_START,
   SMTP_STATE_DO_CMD, SMTP_STATE_DO_CMD_GET_RESP, 
   SMTP_STATE_PUT_HEADER, SMTP_STATE_PUT_START, SMTP_STATE_PUT_BODY,
   SMTP_STATE_FINISH_EMAIL,
   SMTP_STATE_FINISH_EMAIL_WAIT, SMTP_STATE_EOM, SMTP_STATE_CLOSE,
   SMTP_STATE_FORCE_CLOSE, SMTP_STATE_RESET
} SMTP_STATE;

SMTP_STATE smtp_state;

#if STACK_USE_SMTP_AUTH
 int1 g_AUTHIsPlain;
 int1 g_AUTHIsLogin;
 char *g_SMTPUser;
 char *g_SMTPPwd;
 //char *g_SMTPAuthInfo[2];  //[0] holds user name, [1] holds password

//takes 3 characters from src and converts into 4 base64 encoded characters into dest
//if size=-1, then use strlen to determine size
void StringToBase64Block(char *dest, char *src, int16 size)
{
   ROM char lookupTable[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789 /";
   char orig[3];
   char enc[4];
   int8 i;
      
   memcpy(orig, src, 3);
      
   enc[0] = orig[0] >> 2;
   enc[1] = (orig[0] << 4) | (orig[1] >> 4);
   enc[2] = (orig[1] << 2) | (orig[2] >> 6);
   enc[3] = orig[2];
   
   //printf("[%X%X%X->%X%X%X%X]", orig[0], orig[1], orig[2], enc[0], enc[1], enc[2], enc[3]);
   
   for (i=0;i<4;i++)
   {
      enc[i] = lookupTable[enc[i] & 0x3F];
   }

   if (size==-1)
      size = strlen(src);

   if (size<3)
      enc[3]='=';
   if (size<2)
      enc[2]='=';
   
   memcpy(dest, enc, 4);
}

// StringToBase64XMIT()
//
// Encodes strings into base64 and then transmits them over TCP.
//
// This function was designed with the SMTP PLAIN authentication in mind,
// which required smushing two strings into one base64 encoded string,
// with a 0x00 encoded into the string before each string.  If you simply
// need to send on base64 encoded string (without the 0x00 added) then
// you can still use this function, just pass '1' into numSrc.
//
// srcs - a pointer to an array of strings.  these are the strings that
//        need to be base64 encoded and then transmitted.
// numSrcs - the number of strings that srcs holds
// TCPSocket - TCP socket to transmit encoded string. We make the assumption 
//             that the socket is ready for transmit and can send the whole 
//             encoded string.
//
// returns - returns TRUE if success, FAIL if error (we tried to send more
//           data than MAC could handle)
//srcs is actually a pointer to a poitner, but CCS is BUGGY!
int8 StringToBase64XMIT(int16 *srcs, int numSrc, int TCPSocket)
{
   int16 src;
   int len,i,pos;
   char blockIn[3], blockOut[4];
   int1 done = FALSE;

   pos = 0;
   if (numSrc > 1)
      blockIn[pos++]=0;
   src = *srcs;
   srcs++;
   numSrc--;
   len = strlen(src);

   while(!done)
   {           
      i = 3-pos;
      memcpy(&blockIn[pos], src, i);
      if (i > len)
      {
         pos += len;
         if (!numSrc)
            done = TRUE;
         else
         {
            blockIn[pos++]=0;
            src = *srcs;
            srcs++;
            numSrc--;
            len = strlen(src);
         }
      }
      else
      {
         src += i;
         pos += i;
         len -= i;
      }
      
      if ((done && (pos>0)) || (pos>=3))
      {
         StringToBase64Block(blockOut, blockIn, pos);
         if (TCPPutArray(TCPSocket, blockOut, 4) != 4)
            return(FALSE);
         pos = 0;
      }
   }
   return(TRUE);
}
#endif

TCP_SOCKET smtp_socket=INVALID_SOCKET;
NODE_INFO smtp_remote;
char *g_SMTPFrom;
char *g_SMTPTo;
char *g_SMTPSubject;
SMTP_EC smtp_last_error=0;
unsigned int16 smtp_engine_port;
unsigned int16 g_SMTPReplyCode;
#if defined(STACK_USE_DNS)
char *g_SMTPHostname;
#endif

int8 _SMTPOpenAndStart(IP_ADDR *ip, char *hostname, int16 port)
{
   if (SMTPIsFree()) 
   {
      if (ip)
      {
         memcpy(&smtp_remote.IPAddr, ip, sizeof(IP_ADDR));
      }
      else
      {
        #if defined(STACK_USE_DNS)
         g_SMTPHostname = hostname;
        #else
         smtp_last_error = SMTP_EC_INVALID_PARAMETERS;
         return(FALSE);
        #endif
      }
      smtp_last_error=0;
      smtp_engine_port=port;
      
     #if STACK_USE_SMTP_AUTH
      g_AUTHIsPlain=FALSE;
      g_AUTHIsLogin=FALSE;
     #endif

      smtp_state=SMTP_STATE_START;
      return(TRUE);
   }
   smtp_last_error=SMTP_EC_CLOSE_PREVIOUS;
   return(FALSE);
}

void SMTPConfigureBasic(char *to, char *from, char *subject)
{
   g_SMTPFrom = from;
   g_SMTPTo = to;
   g_SMTPSubject = subject;
}

#if STACK_USE_SMTP_AUTH
void SMTPConfigureLogin(char *user, char *pwd)
{
   g_SMTPUser = user;
   g_SMTPPwd = pwd;
}
#endif

int8 SMTPConnect(IP_ADDR *ip, int16 port)
{
   return(_SMTPOpenAndStart(ip,NULL,port));
}

int8 SMTPConnectHostname(char *hostname, int16 port)
{
   return(_SMTPOpenAndStart(NULL,hostname,port));
}

int8 SMTPIsFree(void) {
   return(smtp_socket==INVALID_SOCKET);
}

WORD SMTPIsPutReady(void) 
{
   if ((smtp_state != SMTP_STATE_PUT_BODY) || !TCPIsPutReady(smtp_socket))
      return(0);
   return(TCPIsPutReady(smtp_socket));
}

void SMTPPut(char c)
{
   if (SMTPIsPutReady())
      TCPPut(smtp_socket,c);
}

void SMTPFlush(void)
{
   if (TCPIsPutReady(smtp_socket))
      TCPFlush(smtp_socket);
}

void SMTPDisconnect(void) 
{
   /* pre STACK_USE_SMTP_AUTH
   if (smtp_state==SMTP_STATE_PUT_BODY)
      smtp_state = SMTP_STATE_FINISH_EMAIL;
   else if (smtp_socket!=INVALID_SOCKET)
      smtp_state=SMTP_STATE_CLOSE;
      */
      
   if (smtp_state==SMTP_STATE_PUT_BODY)
      smtp_state = SMTP_STATE_FINISH_EMAIL;
   else if (smtp_socket!=INVALID_SOCKET)
      smtp_state=SMTP_STATE_CLOSE;
   else
      SMTPInit();      
}

SMTP_EC SMTPLastError(void) 
{
   return(smtp_last_error);
}

//stack functions
void SMTPInit(void) 
{
   if (smtp_socket!=INVALID_SOCKET) 
   {
      TCPDisconnect(smtp_socket);
      TCPDisconnect(smtp_socket);
   }
   smtp_socket=INVALID_SOCKET;
   smtp_state=SMTP_STATE_IDLE;
  #if defined(STACK_USE_DNS)
   g_SMTPHostname = NULL;
  #endif
}


void SMTPError(SMTP_EC ec) 
{
  #if !defined(__NO_SMTP_DEBUG_STREAM__)
   char str[80];

   SMTPErrorReason(ec, str);
   
   debug_smtp(debug_smtp_putc, "\r\n*EMAIL: FAIL, %s\r\n", str);
  #endif
  
   smtp_last_error = ec;
   smtp_state = SMTP_STATE_RESET;
}

void SMTPErrorReason(SMTP_EC ec, char *str)
{
   sprintf(str, "FAIL, ");
   str += strlen(str);
   
   switch(ec)
   {
      case SMTP_EC_BAD_EHLO:
         sprintf(str, "EHLO");
         break;

      case SMTP_EC_BAD_AUTH_INIT:
         sprintf(str, "AUTH");
         break;
         
      case SMTP_EC_BAD_MAILFROM:
         sprintf(str, "FROM");
         break;
      
      case SMTP_EC_BAD_RCPTTO:
         sprintf(str, "RCPT");
         break;
      
      case SMTP_EC_BAD_WELCOME:
         sprintf(str, "WELCOME");
         break;
      
      case SMTP_EC_BAD_DATACMD:
         sprintf(str, "DATA");
         break;

      case SMTP_EC_BAD_AUTH_USERNAME:
         sprintf(str, "USER");
         break;
         
      case SMTP_EC_BAD_AUTH_PASSWORD:
         sprintf(str, "FAIL");
         break;
         
      case SMTP_EC_BODY_NOT_ACCEPTED:
         sprintf(str, "BODY");
         break;
         
      case SMTP_EC_PUT_HEADER:
      case SMTP_EC_MAC_TX_FAIL:  
         sprintf(str, "TX TIMEOUT");   
         break;
      
      case SMTP_EC_ARP_FAIL:
         sprintf(str, "ARP");
         break;
      
      case SMTP_EC_CONNECT_FAIL:
         sprintf(str, "CONNECT");
         break;
      
      default: sprintf(str, "0x%X", ec);  break;
   }
   
   str += strlen(str);
   
   sprintf(str, ", %LU", g_SMTPReplyCode);
}

void SMTPPutCmd(char c) {
   TCPPut(smtp_socket,c);
   debug_smtp_putc(c);
}

#define SMTP_TASK_GET_RESPONSE_SHORT(EXPECTED_RESULT, STATE_ON_ERROR, STATE_ON_GOOD)   \
               smtp_expected_result = EXPECTED_RESULT;   \
               on_err = STATE_ON_ERROR;   \
               next_state = STATE_ON_GOOD

#define SMTP_TASK_SEND_COMMAND(CMD, PARAMETER, EXPECTED_RESULT, STATE_ON_ERROR, STATE_ON_GOOD)  \
   sprintf(scrmsg, CMD);   \
   cmdptr2 = PARAMETER; \
   SMTP_TASK_GET_RESPONSE_SHORT(EXPECTED_RESULT, STATE_ON_ERROR, STATE_ON_GOOD); \
   smtp_state = SMTP_STATE_DO_CMD;  \
   lastTick = currTick; \
   lbContinue = TRUE

#define SMTP_TASK_GET_RESPONSE_COMMON()   \
               SMTPReadResultCodeReset(); \
               smtp_state = SMTP_STATE_DO_CMD_GET_RESP;  \
               getRespSeconds = 10; \
               lastTick = currTick; \
               lbContinue = TRUE

#define SMTP_TASK_GET_RESPONSE(EXPECTED_RESULT, STATE_ON_ERROR, STATE_ON_GOOD)   \
               SMTP_TASK_GET_RESPONSE_SHORT(EXPECTED_RESULT, STATE_ON_ERROR, STATE_ON_GOOD); \
               SMTP_TASK_GET_RESPONSE_COMMON()

/* void SMTPDEBUG(void)
{
   static int8 debug;
   
   if (debug != smtp_state)
   {
      printf(SerialPutc, "%U -> %U\r\n", debug, smtp_state);
      debug = smtp_state;
   }
} */
#define SMTPDEBUG()

void SMTPTask(void) {
   int1 authInfoValid;
   TICK currTick;
   static TICK lastTick;
   static int16 smtp_expected_result;

   static char scrmsg[12];
   #DEFINE SMTP_EHLO_MSG   "ehlo me"
   #DEFINE SMTP_DATA_MSG   "data"
   #DEFINE SMTP_MAIL_MSG   "mail from: "
   #DEFINE SMTP_RCPT_MSG   "rcpt to: "
   #DEFINE SMTP_AUTH_LOGIN_MSG   "AUTH LOGIN"
   #DEFINE SMTP_AUTH_PLAIN_MSG   "AUTH PLAIN"


   /*
   static char ehlomsg[]="ehlo me";
   static char datamsg[]="data";
   static char mailfrommsg[]="mail from:";
   static char rcpttomsg[]="rcpt to:";
   static char *cmdptr;
   */
   
   char* cmdptr2;
   static SMTP_EC on_err;
   static int8 next_state;
   static int8 getRespSeconds;
   BOOL lbContinue;

   currTick=TickGet();

   do {
   lbContinue = FALSE;
   SMTPDEBUG();

   switch(smtp_state) {
      case SMTP_STATE_IDLE:
         break;

      case SMTP_STATE_START:
         lastTick=currTick;
         smtp_state=SMTP_STATE_CONNECT;

      case SMTP_STATE_CONNECT:
        #if defined(STACK_USE_DNS)
         if (g_SMTPHostname)
         {
            smtp_socket = TCPOpen(g_SMTPHostname, TCP_OPEN_RAM_HOST, smtp_engine_port, TCP_PURPOSE_CCS_SMTP);
         }
         else
        #endif
         {
            smtp_socket = TCPOpen(smtp_remote.IPAddr.Val, TCP_OPEN_IP_ADDRESS, smtp_engine_port, TCP_PURPOSE_CCS_SMTP);
         }
         if (smtp_socket!=INVALID_SOCKET) {
            lastTick=currTick;
            smtp_state=SMTP_STATE_CONNECT_WAIT;
         }
         else {
//fprintf(USER, "SMT_STATE_CONNECT BAD SOCKET\r\n");
            SMTPError(SMTP_EC_INVALID_SOCKET);
         }
         break;

      case SMTP_STATE_CONNECT_WAIT:
         if (TCPIsConnected(smtp_socket)) 
         {
            SMTP_TASK_GET_RESPONSE(220, SMTP_EC_BAD_WELCOME, SMTP_STATE_EHLO);
            getRespSeconds = 30;
         }
         else if (TickGetDiff(currTick, lastTick) > (TICKS_PER_SECOND * 10)) {
//fprintf(USER, "SMT_STATE_CONNECT_WAIT NO CONNECTION\r\n");
            SMTPError(SMTP_EC_CONNECT_FAIL);
         }
         break;
   
      case SMTP_STATE_EHLO:
        #if STACK_USE_SMTP_AUTH
         SMTP_TASK_SEND_COMMAND(SMTP_EHLO_MSG, NULL, 250, SMTP_EC_BAD_EHLO, SMTP_STATE_POST_EHLO);
        #else
         SMTP_TASK_SEND_COMMAND(SMTP_EHLO_MSG, NULL, 250, SMTP_EC_BAD_EHLO, SMTP_STATE_MAIL_FROM);
        #endif
         break;

   #if STACK_USE_SMTP_AUTH
         case SMTP_STATE_POST_EHLO:
            authInfoValid = TRUE;
            if (!g_SMTPUser || !g_SMTPPwd)
               authInfoValid = FALSE;
            lbContinue = TRUE;
            debug_smtp(debug_smtp_putc, "EE=%U LOG=%U PLA=%U\r\n", authInfoValid, g_AUTHIsLogin, g_AUTHIsPlain);
            if (g_AUTHIsLogin && authInfoValid)
               smtp_state = SMTP_STATE_START_AUTH_LOGIN;
            else if (g_AUTHIsPlain && authInfoValid)
               smtp_state = SMTP_STATE_START_AUTH_PLAIN;
            else
               smtp_state = SMTP_STATE_MAIL_FROM;
           break;

         // --- login ---
         case SMTP_STATE_START_AUTH_LOGIN:
            SMTP_TASK_SEND_COMMAND(SMTP_AUTH_LOGIN_MSG, NULL, 334, SMTP_EC_BAD_AUTH_INIT, SMTP_STATE_AUTH_LOGIN_SEND_USERNAME);
            break;
              
         case SMTP_STATE_START_AUTH_PLAIN:
            SMTP_TASK_SEND_COMMAND(SMTP_AUTH_PLAIN_MSG, NULL, 334, SMTP_EC_BAD_AUTH_INIT, SMTP_STATE_AUTH_PLAIN_SEND);
            break;
         
         case SMTP_STATE_AUTH_LOGIN_SEND_USERNAME:
         case SMTP_STATE_AUTH_LOGIN_SEND_PASSWORD:
         case SMTP_STATE_AUTH_PLAIN_SEND:
            lastTick=currTick;
            smtp_state++;
         
         case SMTP_STATE_AUTH_LOGIN_USERNAME_CONTINUE:
         case SMTP_STATE_AUTH_LOGIN_PASSWORD_CONTINUE:
         case SMTP_STATE_AUTH_PLAIN_SEND_CONTINUE:
            TCPDiscard(smtp_socket);
            if (TCPIsPutReady(smtp_socket))
            {
               char *smtpAuthInfo[2];
               int numPtrs = 0;
               
               if (
                     (smtp_state == SMTP_STATE_AUTH_LOGIN_USERNAME_CONTINUE) || 
                     (smtp_state == SMTP_STATE_AUTH_PLAIN_SEND_CONTINUE)
                  )
               {
                  smtpAuthInfo[0] = g_SMTPUser;
                  numPtrs = 1;
               }
               if (
                     (smtp_state == SMTP_STATE_AUTH_LOGIN_PASSWORD_CONTINUE) || 
                     (smtp_state == SMTP_STATE_AUTH_PLAIN_SEND_CONTINUE)
                  )
               {
                  smtpAuthInfo[numPtrs] = g_SMTPPwd;
                  numPtrs++;
               }
               
               if (smtp_state == SMTP_STATE_AUTH_LOGIN_USERNAME_CONTINUE)
               {
                  SMTP_TASK_GET_RESPONSE_SHORT(334, SMTP_EC_BAD_AUTH_USERNAME, SMTP_STATE_AUTH_LOGIN_SEND_PASSWORD);
               }
               else
               {
                  SMTP_TASK_GET_RESPONSE_SHORT(235, SMTP_EC_BAD_AUTH_PASSWORD, SMTP_STATE_MAIL_FROM);
               }
               SMTP_TASK_GET_RESPONSE_COMMON();

               StringToBase64XMIT(&smtpAuthInfo[0], numPtrs, smtp_socket);
               SMTPPutCmd('\r');
               SMTPPutCmd('\n');
               TCPFlush(smtp_socket);
            }
            else if (TickGetDiff(currTick,lastTick) > (TICKS_PER_SECOND * 2)) 
            {
               SMTPError(SMTP_EC_MAC_TX_FAIL);
            }
            break;
  #endif


      case SMTP_STATE_MAIL_FROM:
//fprintf(USER, "SMTP_STATE_MAIL_FROM\r\n");
         SMTP_TASK_SEND_COMMAND(SMTP_MAIL_MSG, g_SMTPFrom, 250, SMTP_EC_BAD_MAILFROM, SMTP_STATE_RCPT_TO);
         break;

      case SMTP_STATE_RCPT_TO:
//fprintf(USER, "SMTP_STATE_RCPT_TO\r\n");
         SMTP_TASK_SEND_COMMAND(SMTP_RCPT_MSG, g_SMTPTo, 250, SMTP_EC_BAD_RCPTTO, SMTP_STATE_DATA_START);
         break;

      case SMTP_STATE_DATA_START:
//fprintf(USER, "SMTP_STATE_DATA_START\r\n");
         SMTP_TASK_SEND_COMMAND(SMTP_DATA_MSG, NULL, 354, SMTP_EC_BAD_DATACMD, SMTP_STATE_PUT_HEADER);
         break;

      case SMTP_STATE_DO_CMD:
         TCPDiscard(smtp_socket);
         if (TCPIsPutReady(smtp_socket)) {
           printf(SMTPPutCmd, "%s", scrmsg);
           if (cmdptr2)
           {
               printf(SMTPPutCmd, "<%s>", cmdptr2);
           }
           SMTPPutCmd('\r');
           SMTPPutCmd('\n');
           TCPFlush(smtp_socket);
           smtp_state=SMTP_STATE_DO_CMD_GET_RESP;
           getRespSeconds = 10;
           lastTick=currTick;
           SMTPReadResultCodeReset();
         }
         else if (TickGetDiff(currTick,lastTick) > (TICKS_PER_SECOND / 2)) {
            SMTPError(SMTP_EC_MAC_TX_FAIL);
//fprintf(USER, "SMT_STATE_DO_CMD TX TIMEOUT\r\n");            
         }
         break;

      case SMTP_STATE_DO_CMD_GET_RESP:
         TCPTouch(smtp_socket);
         if (TCPIsGetReady(smtp_socket)) {
            lastTick=currTick;
            if (SMTPReadResultCode()) {
               if (g_SMTPReplyCode==smtp_expected_result) {
                  lastTick=currTick;
                  smtp_state=next_state;
               }
               else {
//fprintf(USER, "SMTP_STATE_DO_CMD_GET_RESP BAD RESPONSE %LU!=%LU\r\n", g_SMTPReplyCode, smtp_expected_result);
                  SMTPError(on_err);
               }
            }
         }
         //else if (TickGetDiff(currTick, lastTick) > (TICKS_PER_SECOND * (TICK)10)) {
         else if (TickGetDiff(currTick, lastTick) >= TICKS_PER_SECOND * (TICK)getRespSeconds) 
         {
//fprintf(USER, "SMTP_STATE_DO_CMD_GET_RESP TIMEOUT %LU\r\n", smtp_expected_result);
               SMTPError(on_err);
         }
         break;

      case SMTP_STATE_PUT_HEADER:
         TCPDiscard(smtp_socket);
         if (TCPIsPutReady(smtp_socket)) 
         {
            printf(SMTPPutCmd, "To: %s\r\n", g_SMTPTo);
            
            printf(SMTPPutCmd, "From: %s\r\n", g_SMTPFrom);
            
            printf(SMTPPutCmd, "Subject: %s\r\n", g_SMTPSubject);
            
            TCPFlush(smtp_socket);
            smtp_state=SMTP_STATE_PUT_BODY;
            lastTick=currTick;
         }
         else if (TickGetDiff(currTick, lastTick) > (TICKS_PER_SECOND * 3)) {
//fprintf(USER, "SMTP_STATE_PUT_HEADER TIMEOUT\r\n");
            SMTPError(SMTP_EC_PUT_HEADER);
         }
         break;

      case SMTP_STATE_PUT_BODY:
         //sit in an infinite loop here.
         //now the user can add their own contents to the email by using SMTPPut().
         //but do a timeout check:
         TCPDiscard(smtp_socket);
         if (TickGetDiff(currTick, lastTick) > (TICKS_PER_SECOND * 15)) {
//fprintf(USER, "SMTP_STATE_PUT_BODY TIMEOUT\r\n");
            smtp_state=SMTP_STATE_FINISH_EMAIL;
         }
         else
            break;

      case SMTP_STATE_FINISH_EMAIL:
         lastTick=currTick;
         smtp_state=SMTP_STATE_FINISH_EMAIL_WAIT;

      case SMTP_STATE_FINISH_EMAIL_WAIT:
         TCPDiscard(smtp_socket);
         if (TCPIsPutReady(smtp_socket)) {
            TCPFlush(smtp_socket);
            smtp_state = SMTP_STATE_EOM;
            lastTick=currTick;
         }
         else if (TickGetDiff(currTick, lastTick) > (TICKS_PER_SECOND * 3)) {
//fprintf(USER, "SMTP_STATE_FINISH_EMAIL_WAIT TIMEOUT\r\n");
            smtp_state=SMTP_STATE_FORCE_CLOSE;
         }         
         break;
      
      case SMTP_STATE_EOM:
         TCPDiscard(smtp_socket);
         if (TCPIsPutReady(smtp_socket)) {
            SMTPPutCmd('\r');
            SMTPPutCmd('\n');
            SMTPPutCmd('.');
            SMTPPutCmd('\r');
            SMTPPutCmd('\n');
            TCPFlush(smtp_socket);

            smtp_state=SMTP_STATE_DO_CMD_GET_RESP;
            getRespSeconds = 30;
            smtp_expected_result=250;
            next_state=SMTP_STATE_CLOSE;
            on_err=SMTP_EC_BODY_NOT_ACCEPTED;
            lastTick=currTick;
            SMTPReadResultCodeReset();
//fprintf(USER, "SMTP_STATE_FINISH_EMAIL_WAIT GOOD!\r\n");
         }
         else if (TickGetDiff(currTick, lastTick) > (TICKS_PER_SECOND * 3)) {
//fprintf(USER, "SMTP_STATE_FINISH_EMAIL_WAIT TIMEOUT\r\n");
            smtp_state=SMTP_STATE_FORCE_CLOSE;
         }
         break;

      case SMTP_STATE_CLOSE:
         debug_smtp("\r\n*EMAIL: SUCCESS\r\n");
         TCPDiscard(smtp_socket);
         if (TCPGetTxFIFOFull(smtp_socket) == 0)
         {
//fprintf(USER, "SMTP GRACEFUL CLOSE\r\n");
            smtp_state=SMTP_STATE_FORCE_CLOSE;
         }
         else if (TickGetDiff(currTick, lastTick) > (TICKS_PER_SECOND * 8)) 
         {
//fprintf(USER, "SMTP FORCEFUL CLOSE\r\n");
            //socket is messed up.  call tcpdisconnect() twice to reset socket.
            smtp_state=SMTP_STATE_FORCE_CLOSE;
            TCPDisconnect(smtp_socket);
         }
         else
            break;

      case SMTP_STATE_FORCE_CLOSE:
         TCPDisconnect(smtp_socket);
         smtp_socket = INVALID_SOCKET;

      case SMTP_STATE_RESET:
         SMTPInit();
         break;
   }
SMTPDEBUG();   
   } while(lbContinue);
}

///*** read result code

#if STACK_USE_SMTP_AUTH
char smtp_last_word[20];
int smtp_last_word_idx;
int1 smtp_got_auth_resp;
#endif
int16 smtp_result_code_scratch;
char smtp_result_code_fnnc;   //first non-numeric char

void SMTPReadResultCodeReset(void) 
{
  #if STACK_USE_SMTP_AUTH
   smtp_last_word_idx=0;
   smtp_got_auth_resp=FALSE;
  #endif
   smtp_result_code_scratch=0;
   smtp_result_code_fnnc=0;
}

int8 SMTPReadResultCode(void) 
{
 #if STACK_USE_SMTP_AUTH
   char scratch[6];
 #endif
   char c;
   
   while (TCPGet(smtp_socket, &c)) 
   {
      if ( (c>='0') && (c<='9') && (smtp_result_code_fnnc==0) ) 
      {
         smtp_result_code_scratch*=10;
         smtp_result_code_scratch+=c-'0';
      }
      else if (smtp_result_code_fnnc==0) 
      {
         smtp_result_code_fnnc=c;
      }
     #if STACK_USE_SMTP_AUTH
      //if (smtp_result_code_fnnc=='-')
      else if ((smtp_result_code_fnnc=='-')||(smtp_result_code_fnnc==' '))
      {
         if (c<=' ')
         {
            debug_smtp(debug_smtp_putc, "'%s' ", smtp_last_word);
            if (smtp_got_auth_resp)
            {
               sprintf(scratch, "LOGIN");
               if (stricmp(scratch, smtp_last_word) == 0)
                  g_AUTHIsLogin=TRUE;   

               sprintf(scratch, "PLAIN");
               if (stricmp(scratch, smtp_last_word) == 0)
                  g_AUTHIsPlain=TRUE;     
            }
            else
            {
               sprintf(scratch, "AUTH");
               if (stricmp(scratch, smtp_last_word) == 0)
                  smtp_got_auth_resp=TRUE;
            }
            smtp_last_word_idx=0;
         }
         else
         {
            smtp_last_word[smtp_last_word_idx++] = c;
            if (smtp_last_word_idx >= sizeof(smtp_last_word)) 
               smtp_last_word_idx = sizeof(smtp_last_word)-1;
            smtp_last_word[smtp_last_word_idx] = 0;
         }
      }
     #endif
      if (c==0x0A) 
      {
         if (smtp_result_code_fnnc==' ') 
         {
            g_SMTPReplyCode=smtp_result_code_scratch;
            TCPDiscard(smtp_socket);
            return(TRUE);
         }
         else 
         {
            SMTPReadResultCodeReset(); //read next line (some commands have multi-line responses)
         }
      }
   }
   
   return(FALSE);
}

///*** read result code
