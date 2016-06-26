//////////////////////////////////////////////////////////////////////////////
///                                                                        ///
/// ccs_twitter.c - CCS Twitter Driver                                     ///
///                                                                        ///
/// This driver provides the functions and state machine needed to send a  ///
/// tweet to Twitter using a PIC capable of connecting to the internet.    ///
/// The keys, tokens, and secrets from your Twitter API application are    ///
/// passed into the TwitterInit(...) function.                             ///
///                                                                        ///
/// FUNCTIONS:                                                             ///
/// TwitterInit(...) - Initializes the driver and sets the pointers to the ///
///                 keys, tokens, and secrets for use when sending         ///
///                                                                        ///
/// TwitterTask() - State machine for connecting to the Twitter API and    /// 
///                 handles the sending of tweets                          ///
///                                                                        ///
/// int1 TwitterIsBusy() - Determines if this driver is busy connecting,   ///
///                 sending a tweet, or if an NTP connection is being found///
///                                                                        ///
/// TwitterSend(char *str) - if the driver is not busy, this will start the///
///                 tweet process, sending 'str' as a tweet to the API     ///
///                                                                        ///
/// TwitterCancel() - disconnects the socket and resets the state machine  ///
///                                                                        ///
/// TwitterIsError() - Returns if an error occured on the last tweet       ///
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

// THESE MUST BE DEFINED IN THE MAIN PROGRAM BEFORE 
// INCLUDING "ccstcpip.c". 
//define STACK_USE_TWITTER
//#define STACK_USE_ICMP_SERVER
//#define STACK_USE_TCP
//#define STACK_USE_UDP
//#define STACK_USE_DNS
//#define STACK_USE_CCS_SNTP_CLIENT

//#define TCP_ETH_RAM_SIZE   550

#ifndef TWITTER_HOST
#define TWITTER_HOST "api.twitter.com"
#endif

#ifndef TWITTER_PORT
#define TWITTER_PORT   (unsigned int16)80
#endif

#include "OAuth.c"

// global pointer to keys used by Twitter task
static char* ConsKey;    
static char* ConsSecr;
static char* Token;
static char* TokenSecr;
static char* Status;

int1 isError,send;

static TICK lastTick;        // tick timer
static TCP_SOCKET socket;    // socket for connecting to Twitter
int1 receivingStatus;        // flag for receiving
int8 countReceiving;         // counter for checking if we are receiving the response status code
int8 countResponse;          // counter for the actual response code
static char response[25];    // response received from Twitter
static char SendSuccess[] = "200 OK"; // this is the response Twitter will give when a tweet was successful

// TCP connection states
static enum {
      TWITTER_STATE_CONNECT=0, TWITTER_STATE_CONNECT_WAIT,
      TWITTER_STATE_CONNECTED
   } ConnectState=0;

// Message Sending States
static enum {
      STATE_SEND_0=0, STATE_SEND_1, STATE_SEND_2, STATE_SEND_3,
      STATE_SEND_4, STATE_SEND_5, STATE_SEND_6, STATE_SEND_7,
      STATE_SEND_8, STATE_SEND_9, STATE_SEND_10, STATE_SEND_11,
      STATE_SEND_12, STATE_SEND_13, STATE_SEND_14, STATE_SEND_15,
   } SendState=0;
   
void HTTPPut(char c) {
   TCPPut(socket, c);
}  

/* Initialize the driver with the keys/tokens, 
 * Reset the statemachine 
 */
void TwitterInit(char *ConsumerKey, char *ConsumerSecret, char *AccessToken, char *AccessTokenSecret){
   ConsKey = ConsumerKey;
   ConsSecr = ConsumerSecret;
   Token = AccessToken;
   TokenSecr = AccessTokenSecret;
   isError = FALSE;
   send = FALSE;
   TCPDisconnect(socket); 
   ConnectState = TWITTER_STATE_CONNECT;
   SendState = STATE_SEND_0;
   socket = INVALID_SOCKET;
   receivingStatus = FALSE;
   countReceiving = 0;
   countResponse = 0;
   response[0] = '\0';
}

void TwitterTask(void){

   TICK currTick;
   int8 dis;
   char c;
   static char server[] = TWITTER_HOST;

   currTick=TickGet();

   switch (ConnectState) 
   {
      case TWITTER_STATE_CONNECT:
         //lcdMessage = LCD_CONNECTING;
         //isBusy = TRUE;
         socket = TCPOpen(server, TCP_OPEN_RAM_HOST, TWITTER_PORT, TCP_PURPOSE_DEFAULT);
         if (socket!=INVALID_SOCKET) {
            lastTick=TickGet();
            ConnectState=TWITTER_STATE_CONNECT_WAIT;
         }
         break;

      case TWITTER_STATE_CONNECT_WAIT:
         if (TCPIsConnected(socket)) 
         {
            ConnectState=TWITTER_STATE_CONNECTED;
            //lcdMessage = LCD_TWEET_READY;
         }
         else if (TickGetDiff(currTick, lastTick) > (TICKS_PER_SECOND * 10)) 
         {
            TCPDisconnect(socket);
            ConnectState=TWITTER_STATE_CONNECT;
         }
         break;

      case TWITTER_STATE_CONNECTED:
         if (TCPIsConnected(socket)) {
            
            // first check if there is anything to receive
            if (TCPIsGetReady(socket)) {
               //lcdMessage = LCD_RECEIVING;
               // This will parse errors from the incoming xml reply from Twitter.
               // Nothing will be printed if no error was found.
               // If you want to view all of the xml data, comment out everything 
               // within this loop and uncomment the first line.
               while (TCPGet(socket, &c)) {
                  //printf("%c",c);
                  // find the response status message. 
                  // 200 = OK (sent successfully)
                  // 401 = Unauthorized (error in sending process or with user information)
                  // 403 = Forbidden (usually caused by a duplicate tweet)
                  if((c == 'S' && (countReceiving == 0)) || (c == 't' && (countReceiving == 1)) || 
                     (c == 'a' && (countReceiving == 2)) || (c == 't' && (countReceiving == 3)) || 
                     (c == 'u' && (countReceiving == 4)) || (c == 's' && (countReceiving == 5)) || 
                     (c == ':' && (countReceiving == 6)) || (c == ' ' && (countReceiving == 7)))
                  {
                     countReceiving++;
                     if(countReceiving == 8){  // we are now receiving the response code
                        receivingStatus = TRUE;
                        printf("\n\rStatus: ");
                     }
                  }
                  else
                     countReceiving = 0;

                  if(receivingStatus && ((c == '\n')||(c == '\r'))){ // end of response line
                     receivingStatus = FALSE;
                     printf("\r\n\n");
                     response[countResponse] = '\0'; // terminate the string
                     if (strcmp(SendSuccess,response) != 0)
                     {
                        isError = TRUE;
                        printf("ERROR!\r\n\n");
                     }
                  }
            
                  if(receivingStatus && (countReceiving != 8)){
                     printf("%c",c);
                     response[countResponse] = c; // save response character
                     countResponse++;
                  }
               }
            } // end of if IsGetReady
            
            // we want to send a message and still have a connection
            if(send && TCPIsConnected(socket)){
               switch(SendState){
                  case STATE_SEND_0:
                     isError = FALSE;
                     countResponse = 0;
                     response[0] = '\0';
                     
                     printf(HTTPPut,"POST /1/statuses/update.xml?include_entities=true HTTP/1.1");
                     printf("\r\n\n*** SENDING ***\r\n%s\r\n",Status);
                     delay_ms(80);
                     SendState++;
                     break;
                  case STATE_SEND_1:
                     printf(HTTPPut,"\r\nAccept: */*");
                     delay_ms(30);
                     SendState++;
                     break;
                  case STATE_SEND_2:
                     printf(HTTPPut,"\r\nConnection: close");
                     delay_ms(30);
                     SendState++;
                     break;
                  case STATE_SEND_3:
                     printf(HTTPPut,"\r\nUser-Agent: OAuth gem v0.4.4");
                     delay_ms(40);
                     SendState++;
                     break;
                  case STATE_SEND_4:
                     printf(HTTPPut,"\r\nContent-Type: application/x-www-form-urlencoded");
                     delay_ms(60);
                     SendState++;
                     break;
                  case STATE_SEND_5:
                     printf(HTTPPut,"\r\nAuthorization: OAuth ");
                     delay_ms(40);
                     SendState++;
                     break;
                  case STATE_SEND_6:
                     printf(HTTPPut,"oauth_consumer_key=\"%s\", ",ConsKey);
                     delay_ms(80);
                     SendState++;
                     break;
                  case STATE_SEND_7:
                     generate_nonce();
                     printf(HTTPPut,"oauth_nonce=\"%s\", ", get_nonce());
                     delay_ms(80);
                     SendState++;
                     break;
                  case STATE_SEND_8:
                     generate_timestamp();
                     printf(HTTPPut,"oauth_signature=\"%s\", ", generate_signature(ConsKey,ConsSecr,get_nonce(),get_timestamp(),Token,TokenSecr,Status));
                     delay_ms(80);
                     SendState++;
                     break;
                  case STATE_SEND_9:
                     printf(HTTPPut,"oauth_signature_method=\"HMAC-SHA1\", "); 
                     delay_ms(60);
                     SendState++;
                     break;
                  case STATE_SEND_10:
                     printf(HTTPPut,"oauth_timestamp=\"%s\", ",get_timestamp());
                     delay_ms(60);
                     SendState++;
                     break;
                  case STATE_SEND_11:
                     printf(HTTPPut,"oauth_token=\"%s\", ",Token);
                     delay_ms(80);
                     SendState++;
                     break;
                  case STATE_SEND_12:
                     printf(HTTPPut,"oauth_version=\"1.0\"");
                     delay_ms(40);
                     SendState++;
                     break;
                  case STATE_SEND_13:
                     // find the length of the percent encoded status
                     int8 len = 0;
                     char *d = Status;
                     while(*d != 0){
                        if(!reserved(*d))
                           len +=3;
                        else
                           len++;
                        d++;
                     }
                     printf(HTTPPut,"\r\nContent-Length: %u", (7+len));
                     delay_ms(40);
                     SendState++;
                     break;
                  case STATE_SEND_14:
                     printf(HTTPPut,"\r\nHost: ");
                     printf(HTTPPut, TWITTER_HOST);
                     delay_ms(40);
                     SendState++;
                     break;
                  case STATE_SEND_15:
                     printf(HTTPPut,"\r\n\r\nstatus=");
                     delay_ms(20);
                     // status needs to be percent encoded before sending
                     char *e = Status;
                     while(*e != 0){
                        if(!reserved(*e)){
                           char res[4];
                           sprintf(res,"%%%02X", *e);
                           printf(HTTPPut,"%s",res);
                           delay_ms(10);
                        }
                        // if reserved, just append
                        else{
                           printf(HTTPPut,"%c",*e);
                           delay_ms(5);
                        }
                        e++;
                     }
                     printf("\r\n\n*** RESPONSE ***\r\n");
                     TCPFlush(socket);
                     SendState = STATE_SEND_0;
                     send = FALSE;
                     break;
               
               }
            }
         }
         else { // lost TCP connection
            if(SendState > STATE_SEND_0) // lost connection while sending - Error
               isError = TRUE;
            ConnectState=TWITTER_STATE_CONNECT; // lost connection, reconnect
         }
         break;
   }
}

/* Determines if the system is busy
 * The system is not busy when a connection is made 
 */
int1 TwitterIsBusy(void){
   if 
   (
      (ConnectState != TWITTER_STATE_CONNECTED) || 
      (SendState != STATE_SEND_0) || 
      !NTPOk()
   )
      return TRUE;
   else
      return FALSE;
}


/* If TwitterIsBusy() is FALSE, then this starts the statemachine
 * for sending a Twitter update
 */
void TwitterSend(char *str){
   if (!TwitterIsBusy()){
      Status = str;
      send = TRUE;
   }
}

/* Cancels all Twitter operations and resets the 
 * statemachine and socket
 */
void TwitterCancel(void){
   isError = FALSE;
   send = FALSE;
   TCPDisconnect(socket); 
   ConnectState = TWITTER_STATE_CONNECT;
   SendState = STATE_SEND_0;
   socket = INVALID_SOCKET;
   receivingStatus = FALSE;
   countReceiving = 0;
   countResponse = 0;
   response[0] = '\0';
}

/* Determines if a post had an error.
 * Returns TRUE if an error occured, FALSE otherwise
 */
int1 TwitterIsError(void){
   return isError;
}
