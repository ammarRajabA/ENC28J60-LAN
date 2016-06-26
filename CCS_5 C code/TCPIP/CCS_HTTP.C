//////////////////////////////////////////////////////////////////////////////
///
///                              HTTP.C
///
/// Simple webserver for the Microchip TCP/IP stack.
/// NOTE: THIS IS A DIFFERENT HTTP.C THAN WHAT MICROCHIP PROVIDES
///
/// **** CONFIGURATION ****
///
/// STACK_USE_HTTP - Define this to be true before you include stacktsk.c
///        in your application.  Defining this to be true will cause
///        the stack to include the HTTP portion and execute the init
///        and process any HTTP tasks.
///
/// HTTP_PORT - The TCP/IP port the HTTP server will listen to for HTTP
///        connections.
///
/// HTTP_NUM_SOCKETS - Number of sockets the stack will open for the
///        HTTP server.  You probably will be fine with just 1.  The
///        more sockets you use the more RAM is used to hold buffers
///        and state configuration.
///
/// HTTP_GET_PARAM_MAX_SIZE - This defines the maximum size of several
///        buffers.  This limits the size of your GET or POST requests
///        and all CGI POST data:
///            If using GET, then max amount of cgi data is this value
///            minus everything else on the initial GET command (which
///            also includes the filename).  I believe the max specified
///            by W3C is 255.
///            If using POST, then this is the maximum size for one
///            key=value pair (including the '=' sign).
///        These values do not inlude any escape characters.
///
/// HTTP_USE_CHUNKS - Set to TRUE to make the HTTP server 1.1 compliant
///      and will use Transfer-Encoding: chunked.  Default is FALSE.
///
/// HTTP_USE_DOUBLE_ESCAPE - If your HTTP pages need more escape
///      chars, set this to TRUE.  When set to TRUE your HTTP pages have
///      two escape characters after the %.  An example of each:
///         If FALSE: %A
///         If TRUE: %0A
///
/// HTTP_USE_CONTENT_TYPE - Set to TRUE if your http_get_page() has a third
///      parameter which is the content-type of the requested page.
///
/// **** HOW IT WORKS ****
///
/// The TCP/IP stack will open sockets to the desired ports.  It will
/// then listen for GET or POST requests.  When it gets a GET or POST
/// request it passes the page request to the callback function
/// http_get_page() which then returns 0 if the page doesn't exist, or
/// a pointer to the constant memory area that holds the page in program
/// memory.  If it was a POST request it waits until the HTTP header is
/// done and then saves the POST data into a buffer, and passes the
/// buffer to the callback function http_exec_cgi().  http_exec_cgi() will
/// parse the CGI post data and act upon it.  When done, the HTTP
/// server then responds by sending the page.  If the page is to have
/// variable data, it can be represented by an escape code - %0 or %1
/// for example.  When the HTTP stack sees such an escape code it calls
/// the callback function http_format_char() to format the escape code
/// into the needed variable data (such as ADC readings).  After the
/// HTTP stack is done sending the request it will close the port.
/// If the page didn't exist in program memory it will send a 404 File
/// not found error.  If there was a problem/timeout parsing the request
/// the HTTP stack will send a 500 Internal Server Error response.
///
/// **** CALL BACK FUNCTIONS ****
///
/// Your main application must provide the following callback functions to
/// fill application dependent needs:
///
/// http_get_page(char *file);
///    If HTTP_USE_CONTENT_TYPE is FALSE, this is the proper prototype.  Else,
///    if HTTP_USE_CONTENT_TYPE is TRUE then see the next paragraph.
///    A call-back function provided by your application that finds the
///    required file.  If the file exists, returns address to page in
///    program memory.  If it doesn't exist, returns 0.
///
/// http_get_page(char *file_str, unsigned int32 *retAddress, char *retStr);
///    If HTTP_USE_CONTENT_TYPE is TRUE, this is the proper prototype.  Else,
///    if HTTP_USE_CONTENT_TYPE is FALSE then see the previous paragraph.
///    A call-back function provided by your application that finds the
///    required file.  If the file exists, saves value to retAddress.  If
///    the file doesn't exist, will save 0 to retAddress.  retStr is the
///    content-type (text/html, text/xml, etc).
///
/// http_exec_cgi(unsigned int32 file, char *key, char *val);
///    A call-back function provided by your application that processes incoming
///    CGI commands.  key and val are the incoming key=val CGI pairs.  file is
///    the file address as returned by http_get_page().
///
/// int http_format_char(unsigned int32 file, char id, char *str, unsigned int8 max_ret);
///    Given an escaped character in the program memory HTTP file, convert to
///    variable data.  id is the escaped character, *str is where to save the
///    result.  max_ret is the maximum amount of bytes you can save to *str.
///    Returns the number of bytes written to *str.  file is
///    the file address as returned by http_get_page().
///
/// **** LIMITATIONS ****
///
/// When creating web pages with forms, keep your form names (keys) simple
/// because the HTTP stack does not format the escape characters.  For example,
/// when sending "Pass+Word" the HTTP client will parse it out as "Pass%2bWord".
/// The HTTP stack will correctly parse out the escape chars when retrieving
/// the value, but not the key.  Therefore keep your keys simple.
///
///////////////////////////////////////////////////////////////////////////
///
/// * Author         Date           Comment
/// *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
///
/// * Darren Rook    Oct 05 2006    Bug fix involving POST
///
/// * Darren Rook    Summer 2006    Large parts of this rewritten to fix
///                                 many bugs.  The biggest bug is that
///                                 it can send pages and receive CGI that
///                                 is larger than 1 TCP packet.  Also
///                                 added the HTTP_USE_CHUNKS,
///                                 HTTP_USE_DOUBLE_ESCAPE and
///                                 HTTP_USE_CONTENT_TYPE paremeters.
///
///////////////////////////////////////////////////////////////////////////
////        (C) Copyright 1996,2006 Custom Computer Services           ////
//// This source code may only be used by licensed users of the CCS C  ////
//// compiler.  This source code may only be distributed to other      ////
//// licensed users of the CCS C compiler.  No other use, reproduction ////
//// or distribution is permitted without written permission.          ////
//// Derivative programs created using this software in object code    ////
//// form are not restricted in any way.                               ////
///////////////////////////////////////////////////////////////////////////

#ifndef __CCS_HTTP1_C__
#define __CCS_HTTP1_C__

//#define debug_http   printf
#define debug_http(a,b,c,d,e,f,g,h,i,k,l,m,n,o,p,q,r,s,t,u)

rom char http_404_error[]="<HTML><BODY><H1>404 Error</H1><HR><P>File Not found.</BODY></HTML>";
rom char http_500_error[]="<HTML><BODY><H1>500 Error</H1><HR><P>Internal Server Error</BODY></HTML>";

//key=val pair string, & delimited
void http_parse_cgi_str(unsigned int32 file, char *cgistr);

unsigned int8 http_socket[HTTP_NUM_SOCKETS]={INVALID_SOCKET};

enum {
   HTTP_DISABLED = 0xFF,
   HTTP_IGNORE,
   HTTP_LISTEN_WAIT,
   HTTP_CONNECTED,
   HTTP_GET_HEADERS,
   HTTP_GET_POST,
   HTTP_GET_POST_CONTINUE,
   HTTP_SEND_RESPONSE,
   HTTP_SEND_RESPONSE_CONTINUE,
   HTTP_CLOSE,
   HTTP_CLOSE_WAITING,
   HTTP_CLOSED
} http_state[HTTP_NUM_SOCKETS]={HTTP_IGNORE};

//strips out any escape characters that the HTTP client may have inserted.
// (+ is replaced with space)
// (%xx is replaced with character representation of xx)
char * http_escape_chars(char *str)
{
   char *ostr;
   char new[3];
   char c;
   char val;

   new[2]=0;

   ostr = str;

   while((c=*str) != 0)
   {
      if (c=='+')
         *str++=' ';
      else if (c=='%')
      {
         memcpy(new, str + 1, 2);
         val = strtoul(new, 0, 16);
         *str++ = val;
         memmove(str, str + 2, strlen(str) - 1);
      }
      else
         str++;
   }

   return(ostr);
}

void http_parse_cgi_string(unsigned int32 file, char *ptr)
{
   char *pKey, *pValue, c;

   pKey=ptr;
   pValue=0;

   while(TRUE)
   {
      c = *ptr;
      if ((c=='&') || (c==0))
      {
         *ptr=0;
         http_escape_chars(pKey);
         http_escape_chars(pValue);
         http_exec_cgi(file, pKey, pValue);
         pKey=ptr+1;
         pValue=0;
         if (c==0)
            break;
      }
      else if (c=='=')
      {
         *ptr=0;
         pValue=ptr+1;
      }
      ptr++;
   }
}

unsigned int8 _httpPutcSocket;

#define tcp_http_tx_left()  TCPIsPutReady(_httpPutcSocket)

void set_tcp_http_putc(unsigned int8 newSocket)
{
   _httpPutcSocket=newSocket;
}

int tcp_http_putc(char c)
{
   return(TCPPut(_httpPutcSocket,c));
}

unsigned int32 lastHTTPPutConstPos[HTTP_NUM_SOCKETS];
char * lastHTTPPutVarPos[HTTP_NUM_SOCKETS];

#if HTTP_USE_CHUNKS
void TCPPutFileChunkStart(unsigned int16 count)
{
   printf(tcp_http_putc, "%04LX\r\n", count);
}

void TCPPutFileChunkStop(void)
{
   tcp_http_putc('\r');
   tcp_http_putc('\n');
}
#else
 #define TCPPutFileChunkStart(x)
 #define TCPPutFileChunkStop()
#endif

typedef enum
{
   TCP_PUT_CONST_EC_FINISH = 0,
   TCP_PUT_CONST_EC_CONTINUE,
   TCP_PUT_CONST_EC_ESCAPE
} TCP_PUT_CONST_EC;

//////////////////////////////////////////////////////////////////////////////
//
// TCPPutFileVarChunk(ptr)
//
// send a chunked response from ram
//
// ptr - data to send (well be sent as an http/1.1 chunk).  It will be updated
//          with the continue position before exit.
//
// Returns a status code:
//    TCP_PUT_CONST_EC_FINISH - The whole chunk was completed
//    TCP_PUT_CONST_EC_CONTINUE - The chunk needs to be continued
//
//////////////////////////////////////////////////////////////////////////////
//TCP_PUT_CONST_EC TCPPutFileVarChunk(char **retPtr)
//because of a compiler error i had to make this double pointer an int16, when
//it should be a char.
TCP_PUT_CONST_EC TCPPutFileVarChunk(unsigned int16 **retPtr)
{
   unsigned int16 txLeft, n;
   char *ptr, ec;

   ptr=*retPtr;

   n=strlen(ptr);

   if (!n)
      return(TCP_PUT_CONST_EC_FINISH);

   txLeft = tcp_http_tx_left();

  #if HTTP_USE_CHUNKS
   if (txLeft > 8)
      txLeft -= 8;   //save space for 2x CRLF and 4 chars
   else
      return(TCP_PUT_CONST_EC_CONTINUE);
  #else
   if (!txLeft)
      return(TCP_PUT_CONST_EC_CONTINUE);
  #endif

   if (n > txLeft)
   {
      ec = TCP_PUT_CONST_EC_CONTINUE;
   }
   else
   {
      txLeft = n;
      ec = TCP_PUT_CONST_EC_FINISH;
   }

   TCPPutFileChunkStart(txLeft);

   while (txLeft--)
   {
      tcp_http_putc(*ptr++);
   }

   TCPPutFileChunkStop();

   *retPtr=ptr;

   return(ec);
}

//////////////////////////////////////////////////////////////////////////////
//
// TCPPutFileParseConst(addy, n, doSend)
//
// Reads file from Const memory.  Stops when it reaches an escape sequence,
// n chars or an end of file
//
// addy - data to read (well be sent as an http/1.1 chunk).  This address
//        will be updated for the next call.
//
// n - max number of chars to read from file.  will save the total number
//    of chars passed to this pointer.
//
// doSend - if TRUE, then send data to TCP socket
//
// returns the last char read
//
//////////////////////////////////////////////////////////////////////////////
char TCPPutFileParseConst(unsigned int32 *retAddy, unsigned int16 *n, unsigned int8 doSend)
{
   char stopC, checkC;
   unsigned int16 fileSize = 0, max;
   unsigned int32 addy;
   int1 premature = TRUE;

   max = *n;
   addy = *retAddy;

   while (TRUE)
   {
      read_program_memory(addy++, &stopC, 1);
      if (stopC == '%')
      {
         read_program_memory(addy++, &checkC, 1);
         if (checkC == '%')
         {
            if (fileSize < max)
            {
               if (doSend)
                  tcp_http_putc('%');
               fileSize++;
            }
            else
               break;
         }
         else
            break;   //ESCAPE
      }
      else if (stopC)
      {
         if (fileSize < max)
         {
            if (doSend)
               tcp_http_putc(stopC);
            fileSize++;
         }
         else
            break;
      }
      else
      {
         premature = FALSE;
         break;   //EOF (stopC == 0)
      }
   }

   if (premature)
      addy--;

   *n = fileSize;
   *retAddy = addy;

   return(stopC);
}

//////////////////////////////////////////////////////////////////////////////
//
// TCPPutFileConstChunk(*addy)
//
// send a chunked response from constant memory
//
// addy - data to send (well be sent as an http/1.1 chunk).  This address
//        will be updated for the next call.
//
// returns a response:
//    TCP_PUT_CONST_EC_CONTINUE: we ran out of space to put more data, continue
//                            from this position on next call.
//    TCP_PUT_CONST_EC_ESCAPE:   an escape character
//    TCP_PUT_CONST_EC_FINISH:   we finished reading the chunk, end of file.
//
//////////////////////////////////////////////////////////////////////////////
TCP_PUT_CONST_EC TCPPutFileConstChunk(unsigned int32 *retAddy)
{
   char stopC;
   unsigned int32 addy;
   unsigned int16 fileSize = 0, txLeft;
   TCP_PUT_CONST_EC ec;

   txLeft = tcp_http_tx_left();

 #if HTTP_USE_CHUNKS
   if (txLeft > 8)
      txLeft -= 8;   //save space for 2x CRLF and 4 chars
   else
      return(TCP_PUT_CONST_EC_CONTINUE);
 #else
   if (!txLeft)
      return(TCP_PUT_CONST_EC_CONTINUE);
 #endif

   addy = *retAddy;

   fileSize = 0xFFFF;
   stopC = TCPPutFileParseConst(&addy, &fileSize, FALSE);

   if (!fileSize && (stopC!='%'))
      return(TCP_PUT_CONST_EC_FINISH);

   //TODO: optimize
   if (fileSize > txLeft)
   {
      fileSize = txLeft;
//      if (stopC == '%')
//         ec = TCP_PUT_CONST_EC_ESCAPE;
//      else
         ec = TCP_PUT_CONST_EC_CONTINUE;
   }
   else
   {
      if (stopC == '%')
         ec = TCP_PUT_CONST_EC_ESCAPE;
      else if (stopC)
         ec = TCP_PUT_CONST_EC_CONTINUE;
      else
         ec = TCP_PUT_CONST_EC_FINISH;
   }

   TCPPutFileChunkStart(fileSize);

   TCPPutFileParseConst(retAddy, &fileSize, TRUE);

   TCPPutFileChunkStop();

   return(ec);
}

int TCPPutFileConstGetEscape(unsigned int32 addy)
{
#if HTTP_USE_DOUBLE_ESCAPE
   char str[3];
   int ret;

   read_program_memory(addy, &str[0], 2);
   str[2] = 0;
   ret = strtol(str, 0, 16);
#else
   char ret;
   read_program_memory(addy, &ret, 1);
#endif

   return(ret);
}

int1 tcp_http_put_file(unsigned int8 which, unsigned int16 errorCode, unsigned int32 file, char *contentType)
{
   static char str[40];
   unsigned int8 socket;
   char ec;
   int escaped;

   static enum
   {
      HTTP_PUT_FILE_INIT = 0,
      HTTP_PUT_FILE_CONTINUE,
      HTTP_PUT_FILE_CHUNK_END,
      HTTP_PUT_FILE_DONE
   } status;

   socket=http_socket[which];

   set_tcp_http_putc(socket);

   if (lastHTTPPutConstPos[which] == 0)
   {
      lastHTTPPutVarPos[which] = 0;
      lastHTTPPutConstPos[which] = file;
      status = HTTP_PUT_FILE_CONTINUE;

    #if HTTP_USE_CHUNKS
      printf(tcp_http_putc,"HTTP/1.1 %LU ", errorCode);
    #else
      printf(tcp_http_putc,"HTTP/1.0 %LU ", errorCode);
    #endif

      switch(errorCode)
      {
         case 200:
            printf(tcp_http_putc,"OK");
            break;
         case 404:
            printf(tcp_http_putc,"Not found");
            break;
         case 500:
            printf(tcp_http_putc,"Server Error");
            break;
         default:
            break;
      }

      printf(tcp_http_putc, "\r\nContent-Type: ");
      if (contentType)
         printf(tcp_http_putc, "%s", contentType);
      else
         printf(tcp_http_putc,"text/html");

    #if HTTP_USE_CHUNKS
      printf(tcp_http_putc, "\r\nConnection: close");
      printf(tcp_http_putc, "\r\nTransfer-Encoding: chunked");
    #endif

      printf(tcp_http_putc, "\r\n\r\n");
   }

   if (lastHTTPPutVarPos[which])
   {
      TCPPutFileVarChunk(&lastHTTPPutVarPos[which]);
      lastHTTPPutVarPos[which] = 0;
   }

   if (status == HTTP_PUT_FILE_CONTINUE)
   {
      do {
         ec = TCPPutFileConstChunk(&lastHTTPPutConstPos[which]);

         if (ec == TCP_PUT_CONST_EC_ESCAPE)
         {
            escaped = TCPPutFileConstGetEscape(lastHTTPPutConstPos[which]);
           #if HTTP_USE_DOUBLE_ESCAPE
            lastHTTPPutConstPos[which] += 2;
           #else
            lastHTTPPutConstPos[which] += 1;
           #endif
            http_format_char(file, escaped, &str[0], sizeof(str)-1);
            lastHTTPPutVarPos[which] = &str[0];
            ec = TCPPutFileVarChunk(&lastHTTPPutVarPos[which]);
            if (ec == TCP_PUT_CONST_EC_FINISH)
               lastHTTPPutVarPos[which] = 0;
            else
               break;
         }
         else
         {
            if (ec == TCP_PUT_CONST_EC_FINISH)
               status = HTTP_PUT_FILE_CHUNK_END;
            break;
         }
      } while (TRUE);
   }

   if (status == HTTP_PUT_FILE_CHUNK_END)
   {
     #if HTTP_USE_CHUNKS
      if (tcp_http_tx_left() > 8)
      {
         TCPPutFileChunkStart(0);
         TCPPutFileChunkStop();
         status = HTTP_PUT_FILE_DONE;
      }
     #else
      status = HTTP_PUT_FILE_DONE;
     #endif
   }


   TCPFlush(socket);

   return(status == HTTP_PUT_FILE_DONE);
}

//initializes the HTTP state machine.  called automatically by the TCP/IP stack
void HTTPInit(void) {
   unsigned int8 i;
   debug_http("\r\nHTTP OPENING");
   if (HTTP_PORT != 0)
   {
      for (i=0;i<HTTP_NUM_SOCKETS;i++)
      {
         http_socket[i] = TCPOpen(0, TCP_OPEN_SERVER, HTTP_PORT, TCP_PURPOSE_HTTP_SERVER);
         debug_http("\r\nHTTP SOCKET=%X", http_socket[i]);
         if (http_socket[i]!=INVALID_SOCKET)
         {
            http_state[i]=HTTP_LISTEN_WAIT;
         }
      }
   }
   else
   {
      debug_http("\r\nHTTP DISABLED");
      for (i=0;i<HTTP_NUM_SOCKETS;i++)
      {
            http_state[i]=HTTP_DISABLED;
      }
   }
}

void HTTPServer(void) {
   static char tokens_header[]=" ";
   static char tokens_get[]="?";
   static char http_get_str[]="GET";
   static char http_post_str[]="POST";
   static char http_len_str[]="Content-Length:";
   //static char http_keepalive_str[]="keep-alive";
   //static char http_connection_str[]="Connection";

   static char buffer[HTTP_NUM_SOCKETS][HTTP_GET_PARAM_MAX_SIZE];

   static unsigned int8 i[HTTP_NUM_SOCKETS];
   static enum {HTTP_REQ_GET=1, HTTP_REQ_POST=2, HTTP_REQ_UNKOWN=0} http_cmd[HTTP_NUM_SOCKETS]={0};
   static unsigned int32 http_page_req[HTTP_NUM_SOCKETS];
   static unsigned int16 http_post_len[HTTP_NUM_SOCKETS]={0};
   static TICK http_timer[HTTP_NUM_SOCKETS];
 #if HTTP_USE_CONTENT_TYPE
   static char contentType[HTTP_NUM_SOCKETS][12];
 #endif

   int1 doneSend, postContinue;

   char c, *pKey, *pValue;
   unsigned int8 hs, currSocket;

   for (hs=0; hs<HTTP_NUM_SOCKETS; hs++)
   {
      if (http_state[hs]==HTTP_DISABLED)
         return;

      currSocket=http_socket[hs];

      if (!TCPIsConnected(currSocket))
         http_state[hs]=HTTP_LISTEN_WAIT;

      switch(http_state[hs])
      {
         case HTTP_LISTEN_WAIT:
            if (!TCPIsConnected(currSocket))
               break;
            debug_http("HTTP %U CONNECTED\r\n", hs);

         //wait until we get '\r\n\r\n', which marks the end of the HTTP request header
         case HTTP_CONNECTED:
            debug_http("HTTP %U LISTENING\r\n", hs);
            buffer[hs][0]=0;
            i[hs]=0;
            http_state[hs]=HTTP_GET_HEADERS;
            http_timer[hs]=TickGet();
            http_page_req[hs]=0;
            http_post_len[hs]=0;
            //http_got_headers[hs]=FALSE;
            //http_isKeepAlive[hs]=FALSE;

         case HTTP_GET_HEADERS:
            postContinue=FALSE;
            while (TCPIsGetReady(currSocket) && TCPGet(currSocket, &c))
            {
               //http_got_headers[hs]=TRUE;
               if ( (c >= 0x20) && (i[hs] < HTTP_GET_PARAM_MAX_SIZE - 2) )
               {
                  buffer[hs][i[hs]++]=c;
               }
               if (c=='\n')
               {
                  buffer[hs][i[hs]]=0;
                  if (
                       ( ( pKey = strtok(&buffer[hs][0], tokens_header) ) !=0 ) &&
                       ( ( pValue = strtok(0, tokens_header) ) !=0 )
                     )
                  {
                     debug_http("HTTP %U PAIR %s = %s\r\n", hs, pKey, pValue);
                     if ( (strcmp(pKey, http_get_str)==0) || (strcmp(pKey, http_post_str)==0) )
                     {
                        pValue=strtok(pValue, tokens_get);  //chop the file after a ?
                        http_escape_chars(pValue);
                       #if HTTP_USE_CONTENT_TYPE
                        http_get_page(pValue, &http_page_req[hs], &contentType[hs][0]);
                       #else
                        http_page_req[hs] = http_get_page(pValue);
                       #endif
                        debug_http("HTTP %U FILE %s = %lx\r\n", hs, pValue, http_page_req[hs]);
                        pValue=strtok(0, tokens_get);
                        if (pValue)
                           http_parse_cgi_string(http_page_req[hs], pValue);

                        if (strcmp(pKey, http_get_str)==0)
                           http_cmd[hs]=HTTP_REQ_GET;
                        else
                           http_cmd[hs]=HTTP_REQ_POST;
                     }
                     else if (http_cmd[hs] != HTTP_REQ_UNKOWN)   //we processed a GET or POST
                     {
                        //if you want to parse HTTP headers, do it here.
                        //pKey and pVal hold the individual headers.

                        //this driver only parses the Content-Length header.
                        if (strcmp(pKey, http_len_str)==0)
                        {
                           http_post_len[hs]=atol(pValue);
                        }
                     }
                  }
                  else if (i[hs] == 0)
                  {
                     //got a double \r\n
                     debug_http("HTTP %U GET HEADER DONE\r\n", hs);
                     if (http_cmd[hs] == HTTP_REQ_POST)
                     {
                        http_state[hs]=HTTP_GET_POST;
                        postContinue=TRUE;
                     }
                     else
                     {
                        http_state[hs]=HTTP_SEND_RESPONSE;
                        TCPDiscard(currSocket);
                     }
                     break;   //break out of read from ethernet loop
                  }
                  i[hs]=0;
               }
            }
            if (TickGetDiff(TickGet(),http_timer[hs]) > TICKS_PER_SECOND*20)
            {
               //if (http_got_headers[hs])
               //{
                  debug_http("HTTP %U GET HEADER TIMEOUT\r\n", hs);
                  http_page_req[hs]=0xFFFFFFFF;
                  http_state[hs]=HTTP_SEND_RESPONSE;
               //}
               //else
               //{
               //   http_state[hs]=HTTP_CLOSE;
               //}
            }
            if (!postContinue)
               break;

         case HTTP_GET_POST:
            debug_http("HTTP %U GET POST %LU\r\n", hs, http_post_len[hs]);
            http_state[hs]=HTTP_GET_POST_CONTINUE;
            http_timer[hs]=TickGet();
            i[hs]=0;

         case HTTP_GET_POST_CONTINUE:
            while (
                     TCPIsGetReady(currSocket) &&
                     TCPGet(currSocket, &c) &&
                     (http_post_len[hs] != 0)
                  )
            {
               http_post_len[hs] -= 1;

               if (c!='&')
               {
                  buffer[hs][i[hs]++]=c;
               }

               if ( (c=='&') || (http_post_len[hs] == 0) )
               {
                  buffer[hs][i[hs]]=0;

                  debug_http("%lu - %s\r\n", http_post_len[hs], &buffer[hs][0]);

                  http_parse_cgi_string(http_page_req[hs], &buffer[hs][0]);
                  if (http_post_len[hs] == 0)
                  {
                     http_state[hs]=HTTP_SEND_RESPONSE;
                     TCPDiscard(currSocket);
                     break;
                  }
                  else
                     i[hs]=0;
               }
            }
            if (TickGetDiff(TickGet(),http_timer[hs]) > TICKS_PER_SECOND*20)
            {
               debug_http("HTTP %U GET POST TIMEOUT\r\n", hs);
               http_page_req[hs]=0xFFFFFFFF;
               http_state[hs]=HTTP_SEND_RESPONSE;
            }
            break;

         case HTTP_SEND_RESPONSE:
            debug_http("HTTP %U SEND RESPONSE\r\n", hs);
            lastHTTPPutConstPos[hs]=0;
            http_state[hs]=HTTP_SEND_RESPONSE_CONTINUE;

         case HTTP_SEND_RESPONSE_CONTINUE:
            TCPDiscard(currSocket);
            if (TCPIsPutReady(currSocket))
            {
               http_timer[hs]=TickGet();
               debug_http("\r\nPUTTING HTTP SEG\r\n");
               if (http_page_req[hs]==0xFFFFFFFF)
                  doneSend=tcp_http_put_file(hs, 500, &http_500_error[0], 0);
               else if (http_page_req[hs])
                #if HTTP_USE_CONTENT_TYPE
                  doneSend=tcp_http_put_file(hs, 200, http_page_req[hs], &contentType[hs][0]);
                #else
                  doneSend=tcp_http_put_file(hs, 200, http_page_req[hs], 0);
                #endif
               else
                  doneSend=tcp_http_put_file(hs, 404, &http_404_error[0], 0);

               if (doneSend)
               {
                  //if (http_isKeepAlive[hs])
                  //   http_state[hs]=HTTP_CONNECTED;
                  //else
                  //   http_state[hs]=HTTP_CLOSE;
                  http_state[hs] = HTTP_CLOSE;
                  debug_http("HTTP %U RESPONSE SENT\r\n", hs);
               }
            }
            if ((TickGet() - http_timer[hs]) >= (TICK)15*TICKS_PER_SECOND)
            {
               http_state[hs] = HTTP_CLOSE;
            }
            /*else
            {
               debug_http("\r\nNR => RW=%LX B=%X IS=%U\r\n",
                     TCB[currSocket].RemoteWindow,
                     TCB[currSocket].TxBuffer,
                     TCB[currSocket].Flags.bIsPutReady
                  );
               delay_ms(100);
            }*/
            break;

         case HTTP_CLOSE:
            //since we set connection: close in the header, the client
            //should automatically close.  but after so many seconds we
            //shall kill the connection
            http_state[hs]=HTTP_CLOSE_WAITING;
            http_timer[hs]=TickGet();

         case HTTP_CLOSE_WAITING:
            TCPDiscard(currSocket);
            if (
                  (TCPGetTxFIFOFull(currSocket) == 0) ||
                  (TickGetDiff(TickGet(),http_timer[hs]) > (TICKS_PER_SECOND*8))
               )
            {
               debug_http("HTTP %U FORCE CLOSED\r\n", hs);
               if (TCPGetTxFIFOFull(currSocket) != 0)
               {
                  //socket is messed up.  just kill it by calling TCPDisconnect() twice.
                  TCPDisconnect(currSocket);
               }
               TCPDisconnect(currSocket);
               http_state[hs]=HTTP_CLOSED;
            }
            break;

         case HTTP_CLOSED: //do nothing until socket actually closes
         default:
            break;
      }
   }
}

#endif
