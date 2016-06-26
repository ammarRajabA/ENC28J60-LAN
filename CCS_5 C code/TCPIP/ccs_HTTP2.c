//////////////////////////////////////////////////////////////////////////////
///
///                              HTTP2.C
///
/// Simple webserver for the Microchip TCP/IP stack. Using web pages
/// stored on a MultiMediaCard.
/// NOTE: THIS IS A DIFFERENT HTTP.C THAN WHAT MICROCHIP PROVIDES
///
/// **** CONFIGURATION ****
///
/// STACK_USE_HTTP - Define this to be true before you include stacktsk.c
///        in your application.  Defining this to be true will cause
///        the stack to include the HTTP portion and execute the init
///        and process any HTTP tasks.
///
///
/// STACK_USE_HTTP2 - Same as STACK_USE_HTTP except this will cause
///         web pages to be loaded from files stored on the MMC, not
///        stored in program memory.
///
/// HTTP_USE_AUTHENTICATION - If set to TRUE (default is FALSE), you can
///      have some websites password protected.  In your file system (FAT
///      or MPFS) create a new file at the root called 'htaccess.txt'.  The
///      format of this file should be as follows:
///         user|password|file1|file2|file3
///      You can password protect entire directories (if your file system 
///      provides directory support).  To password protect the entire file
///      system then use / as your filename.  Even though you can provide a
///      user name and password into htaccess.txt file, the HTTP stack will also
///      call http_check_authentication() to verify the username and password.
///      It will check both locations, and if the username/password from the
///      file matches the user input, or http_check_authentication() returns
///      TRUE then authentication is granted.  The reason it checks both is in
///      case you want ot password protect a file in the field without having
///      to re-program the firmware, you just have to modify htaccess.txt to
///      add authentication.  If you want to have the HTTP stack ignore the
///      username/password from htaccess.txt then leave those fields blank.
///
///      If authentication fails the webserver will display the error401.htm
///      page.
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
/// HTTP_ESCAPED_STR_SIZE - Size allocated, per socket, for http_format_char()
///         results.
///
///
/// HTTP_USE_DOUBLE_ESCAPE - If your HTTP pages need more escape
///      chars, set this to TRUE.  When set to TRUE your HTTP pages have
///      two escape characters after the %.  An example of each:
///         If FALSE: %A
///         If TRUE: %0A
///
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
/// If the page didn't exist it will send a 404 File
/// not found error.  If there was a problem/timeout parsing the request
/// the HTTP stack will send a 500 Internal Server Error response.
///
/// **** CALL BACK FUNCTIONS ****
///
/// Your main application must provide the following callback functions to
/// fill application dependent needs:
///
/// http_exec_cgi(char* file, char *key, char *val);
///    A call-back function provided by your application that processes incoming
///    CGI commands.  key and val are the incoming key=val CGI pairs.  file is
///    the file name.
///
/// int http_format_char(char* file, char id, char *str, int8 max_ret);
///    Given an escaped character in the HTML file, convert to
///    variable data.  id is the escaped character, *str is where to save the
///    result.  max_ret is the maximum amount of bytes you can save to *str.
///    Returns the number of bytes written to *str.  file is
///    the file name.
///
/// int1 http_check_authentication(char *fileName, char *user, char *pwd);
///   If someone has tried to access a password protected file, the http server
///   will call this function so the application can determine if the user has
///   access.  fileName is the requested file, user is the username the user
///   entered, and pwd is the password the user entered.  The function should
///   return TRUE if access is granted, FALSE if not.  This function is only
///   needed if HTTP_USE_AUTHENTICATION is defined as TRUE.
///
/// **** LIMITATIONS ****
///
/// When creating web pages with forms, keep your form names (keys) simple
/// because the HTTP stack does not format the escape characters.  For example,
/// when sending "Pass+Word" the HTTP client will parse it out as "Pass%2bWord".
/// The HTTP stack will correctly parse out the escape chars when retrieving
/// the value, but not the key.  Therefore keep your keys simple.
///
///
/// **** FILE SUPPORT ***
/// Two file systems are supported--FAT on an MMC and Microchip's MPFS on the
/// external eeprom chip.
/// 
/// Three files must be supplied on the MMC or MPFS image.  Error404.htm will
/// be called when the file requested in the URL does not exist.Error500.htm will
/// be called on an internal server error or timeout.  Internet Exploder requires
/// that custom error pages be greater than 512 bytes in length or the browser
/// will insert its own error page in its place.  Index.htm will be called
/// when no file is explicitly specified in the URL. Other files may be included
/// on the mmc or MPFS image.  File types that are supported are .htm, .html,
/// .xml, .txt, .jpg, .png, and .gif. Filenames should be in DOS 8.3 format. 
///
////////////////////////////////////////////////////////////////////////////////
///
/// * Author         Date           Comment
/// *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
///
/// * Darren Rook    Apr 12 2007    Added HTTP_USE_AUTHENTICATION.
///                                 If file system is missing, will display a
///                                 500 error file from memory.
///                                 If client gets root (/) and index.htm is
///                                 missing, show 404 page.
///                                 Fixed bug in TCPPutFileParseConst() where
///                                 it was checking for EOF after reading a 
///                                 char, it should check for EOF before reading
///                                 from stream.
///
/// * Nick LaBonte   Feb 22 2007    Added support for MPFS
///
/// * Nick LaBonte   Jan 2007       Added MMC file support, removed HTTP_USE_CHUNKS
///
/// * Darren Rook    Oct 05 2006    Bug fix involving POST
///
/// * Darren Rook    Summer 2006    Large parts of this rewritten to fix
///                                 many bugs.  The biggest bug is that
///                                 it can send pages and receive CGI that
///                                 is larger than 1 TCP packet.  Also
///                                 added the HTTP_USE_CHUNKS,
///                                 HTTP_USE_DOUBLE_ESCAPE and
///                                 HTTP_USE_CONTENT_TYPE parameters.
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

#ifndef debug_html
 #define debug_html_putc(c)
 #define debug_html(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z)
#else
 #define __DO_DEBUG_HTML
#endif

#ifndef debug_mpfs2
#define debug_mpfs2(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z)
#endif

#ifndef STACK_USE_MPFS
#error Must define a file system to use
#endif

#ifndef HTTP_ESCAPED_STR_SIZE
#define HTTP_ESCAPED_STR_SIZE 40
#endif

#ifndef HTTP_SEND_BYTES_PER_CHUNK
#define HTTP_SEND_BYTES_PER_CHUNK   128
#endif

#ifndef HTTP_INTERRUPT_TASKS
#define HTTP_INTERRUPT_TASKS()
#endif

#define HTTP_404_ERROR_FNAME "error404.htm"
#define HTTP_500_ERROR_FNAME "error500.htm"
#define HTML_INDEX_FNAME "index.htm"

#ifndef HTTP_SERVER_HTACCESS_FILE
#define HTTP_SERVER_HTACCESS_FILE "htaccess.txt"
#endif

//this will be displayed if the http_500_error[] file cannot be found on the
//file system.  useful if the file system has crashed.
#define HTML_500_FILE_CONTENTS "<html><body><h1>500 Error</h1><hr><p>Internal server error.</p></body></html>"

/*
Very similar to standard strncpy(), but it adds a null termination on n+1, and n
is the entire size of the string including null termination.
*/
void _strncpy(char *s1, char *s2, size_t n)
{
   strncpy(s1,s2,n-1);
   s1[n-1]=0;
}

//static int1 FTPWriteMMC = 0;

//key=val pair string, & delimited
void http_parse_cgi_str(char* file, char *cgistr);

unsigned int8 http_socket[HTTP_NUM_SOCKETS];

enum {
   HTTP_IGNORE = 0,
   HTTP_LISTEN_WAIT,
   HTTP_CONNECTED,
   HTTP_GET_HEADERS,
   HTTP_CHECK_AUTHENTICATION,
   HTTP_GET_POST,
   HTTP_GET_POST_CONTINUE,
   HTTP_SEND_RESPONSE,
   HTTP_SEND_RESPONSE_CONTINUE,
   HTTP_CLOSE,
   HTTP_CLOSE_WAITING,
   HTTP_CLOSED,
   HTTP_DISABLED = 0xFF,
} http_state[HTTP_NUM_SOCKETS];

unsigned int FileExists(char *file)
{
   unsigned int ret=FALSE;
   MPFS handle;
 
   handle=MPFSOpen(file);
   if (handle != MPFS_INVALID)
   {
      ret=TRUE;
      MPFSGetEnd(); 
      MPFSClose();
   }
 
   return(ret);
}

#if HTTP_USE_AUTHENTICATION
   char http_401_error[]="error401.htm";


/*
src holds a string in base64 (null terminated), this will convert that string 
to ascii and save to dest (null terminated).  if src is NULL, then it will use
dest for the source and save the result over source.
*/
void Base64ToString(char *dest, char *src)
{
   unsigned int32 j;
   unsigned int8 i,scr;
   
   if (!src)
      src=dest;
   
   while(*src)
   {
      j=0;
      for (i=0;i<4;i++)
      {
         scr=*src;
         //printf("'%c'->",scr);
         if (scr)
            src++;
         if ((scr>='A')&&(scr<='Z'))
            scr-='A';
         else if ((scr>='a')&&(scr<='z'))
            scr+=26-'a';
         else if ((scr>='0')&&(scr<='9'))
            scr+=52-'0';
         else if (scr==' ')
            scr=62;
         else if (scr=='/')
            scr=63;
         else
            scr=0;
            
         j *= (int32)64; //bit shift left 6 times
         j &= (int32)0xFFFFFFC0;
         j |= scr;
         //printf("%U [%LX]\r\n", scr,j);
      }
      dest[0]=make8(j,2);
      dest[1]=make8(j,1);
      dest[2]=make8(j,0);
      //printf("APPEND: '%c%c%c'\r\n", dest[0],dest[1],dest[2]);
      dest+=3;
   }
   *dest=0;
}

/*
Reads the htaccess file (already opened in fHandle), saving max chars to
*result.  If it reads a '|' then it returns FALSE, if it hits EOF then it 
returns TRUE.  If result is NULL then it won't save, it will just point the 
file to the next element.
*/
static unsigned int8 HTTPParseHtaccess(MPFS *pFHandle, char *result, unsigned int16 max)
{
   char c;
   unsigned int8 ret=FALSE;
   
   max--;   //save one for null termination
   
   do
   {
      if (MPFSIsEOF())
      {
         ret=TRUE;
         break;
      }
      c =  MPFSGet();
      if (result && max && (c!='|') && (c>=' '))
      {
         *result++ = c;
         max--;
      }
   } while(c!='|');
   
   if (result)
      *result = 0;
   
   return(ret);
}   

/*
Upon request of a file, this function should be called before serving the file
to the user.  It checks to see if the file requires authentication, and if it
does it sees if the user provided username/password combination passes.  *page
contains the requested page, *user contains the username/password combination
from the HTTP header (in base64).  If the user hasn't provided a 
username/password then user will be set to NULL.  This function will return 
TRUE if authentication fails, in which case the server will respond with 
Error 401.
If you are using MPFS, it must be free at this time and be able to open a file
else the results will be TRUE.  
If the htaccess format is not valid this will always return TRUE.
If it cannot find htaccess file it will assume that no file requires 
authentication.
*/
unsigned int8 HTTPRequiresAuthentication(char *page, char *user)
{
   static char htaccess[] = HTTP_SERVER_HTACCESS_FILE;
   static char token[]=":";
   char *pwd;
   MPFS fHandle;
   char userFromFile[30], pwdFromFile[30], fileToCheck[30];
   unsigned int8 eof,i;
   unsigned int8 ret=TRUE;


   //printf("\r\nCHECK FILE '%s'\r\n", page);
  
  //#if STACK_USE_MPFS
  #if 0
   if (MPFSIsInUse())
   {
      //printf("\r\nMPFSINUSE\r\n");
      return(TRUE);
   }
  #endif
   
   fHandle = MPFSOpen(htaccess);
   if (fHandle == MPFS_INVALID)
   {
      //printf("\r\nNOHTACCESS '%s'\r\n", htaccess);
      return(FALSE);
   }
   
   MPFSGetBegin(fHandle);
   
   if (HTTPParseHtaccess(&fHandle, userFromFile, sizeof(userFromFile)))
      goto __HTTPRequiresAuthentication_Cleanup;
   if (HTTPParseHtaccess(&fHandle, pwdFromFile, sizeof(pwdFromFile)))
      goto __HTTPRequiresAuthentication_Cleanup;
  
   for(;;)
   {
      //printf("\r\nFINDING FILE\r\n");
      eof = HTTPParseHtaccess(&fHandle, fileToCheck, sizeof(fileToCheck));
           
      strupr(fileToCheck);
      
      //strip any any whitespace chars at the end of the file
      i=strlen(fileToCheck);
      while(i--)
      {
         if (fileToCheck[i] <= ' ')
            fileToCheck[i]=0;
         else
            break;
      }

      //printf("\r\nFILE (%U) = '%s'\r\n", eof, fileToCheck);
      if (
            (fileToCheck[0] == '*') || //wildcard, match all files
            (strcmp(fileToCheck, page)==0) ||  //file is a perfect match
            (  //check for subdirectory
               (fileToCheck[i]=='/') &&   //if file ends in /, it is a directory
               (strstr(page, fileToCheck)==page)
            )
         )
      {
         //printf("\r\nCONVERTING 64: '%s'->", user);
         Base64ToString(user, NULL);         
         //printf("'%s'\r\n", user);
         user=strtok(user,token);
         pwd=strtok(0,token);
         return
            (
               !(
                  (
                     strlen(userFromFile) && 
                     strlen(pwdFromFile) && 
                     (stricmp(userFromFile,user)==0) &&
                     (stricmp(pwdFromFile,pwd)==0)
                  ) ||
                  http_check_authentication(page,user,pwd)
                )
            );
         //if (user && pwd && (strcmp(user,validUser)==0) && (strcmp(pwd,validPwd)==0))
         //   ret=FALSE;
         break;
      }
      
      if (eof)
      {
         ret=FALSE;
         break;
      }      
   }

__HTTPRequiresAuthentication_Cleanup:
   MPFSGetEnd();
   MPFSClose();
   return(ret);
}
#endif //HTTP_USE_AUTHENTICATION

//strips out any escape characters that the HTTP client may have inserted.
// (+ is replaced with space)
// (%xx is replaced with character representation of xx)
void http_escape_chars(char *str)
{
   char new[3];
   char c;
   char val;

   new[2]=0;

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
}

void http_parse_cgi_string(char* file, char *ptr)
{
   char *pKey, *pValue, c;

   pKey=ptr;

   for(;;)
   {
      c = *ptr;
      if ((c=='&') || (c==0))
      {
         *ptr=0;
         http_escape_chars(pKey);
         http_escape_chars(pValue);
         http_exec_cgi(file, pKey, pValue);
         pKey=ptr+1;
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

unsigned int8 g_HttpCurrSocket;
unsigned int8 g_HttpCurrConn;

#define tcp_http_tx_left()  TCPIsPutReady(g_HttpCurrSocket)

unsigned int tcp_http_putc(char c)
{
   //putc(c);
   return(TCPPut(g_HttpCurrSocket,c));
}

MPFS lastHTTPPutConstPos[HTTP_NUM_SOCKETS];
char * lastHTTPPutVarPos[HTTP_NUM_SOCKETS];

typedef enum
{
   MIME_TYPE_HTM,
   MIME_TYPE_HTML,
   MIME_TYPE_TXT,
   MIME_TYPE_XML,
   MIME_TYPE_GIF,
   MIME_TYPE_JPG,
   MIME_TYPE_PNG,
   MIME_TYPE_ICO
} MIME_T;

//static int1 is_image[HTTP_NUM_SOCKETS];
MIME_T g_HTTPMimeType[HTTP_NUM_SOCKETS];
#if HTTP_LAST_MODIFIED_CHECK
 int1 g_lastModifiedCheck[HTTP_NUM_SOCKETS];
#endif
#define IsImage(t)   (g_HTTPMimeType[t]>=MIME_TYPE_GIF)

#define HTTP_NUM_MIME_TYPES   8

ROM char gc_MimeTypes[HTTP_NUM_MIME_TYPES][5] =  //filename extensions
{
   "htm",
   "html",
   "txt",
   "xml",
   "gif",
   "jpg",
   "png",
   "ico"
};

ROM char gc_MimeTypesHeader[HTTP_NUM_MIME_TYPES][13] =
{
   "text/html",
   "text/html",
   "text/plain",
   "text/xml",
   "image/gif",
   "image/jpeg",
   "image/png",
   "image/x-icon"
};

MIME_T HTTPFindMimeType(char *fname)
{
   unsigned int8 i;
   char str[5];
   char extension[5];

   if(strlen(strchr(fname,'.'))<6)
   {
      strncpy (extension, (strchr(fname,  '.'))+1,  4);
   }
   else
      extension[0] = 0;


   for (i=0; i<HTTP_NUM_MIME_TYPES; i++)
   {
      //sprintf(str, "%s", gc_MimeTypes[i]);
      strcpypgm2ram(str, &gc_MimeTypes[i][0]);
      debug_html(debug_html_putc, "\r\nHTML Ext check %u '%s' '%s' vs '%s'(0x%LX) ", i, fname, extension, str, &gc_MimeTypes[i][0]);
      if (stricmp(str, extension) == 0)
         return(i);
   }
   
   return(MIME_TYPE_TXT);
}

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
//because of a compiler error this had to be a double pointer an int16, when
//it should be a char.

TCP_PUT_CONST_EC TCPPutFileVarChunk(unsigned int16 **retPtr)
{
   unsigned int16 txLeft, n;
   char *ptr, ec;

   ptr=*retPtr;

   n=strlen(ptr);
   
   if (!n){
      return(TCP_PUT_CONST_EC_FINISH);
   }

   txLeft = tcp_http_tx_left();
  
   if (n > txLeft)
      ec = TCP_PUT_CONST_EC_CONTINUE;   
   else
   {
      txLeft = n;
      ec = TCP_PUT_CONST_EC_FINISH;
   }

   //TCPPutFileChunkStart(txLeft);

   while (txLeft--)
      tcp_http_putc(*(ptr++));

   //TCPPutFileChunkStop();

   *retPtr=ptr;

   return(ec);
}


/*
   Allows negative seek offset.
*/
void myMPFSSeek(MPFS *handle, signed int16 offset)
{
    MPFSGetBegin(*handle);
    if(offset < 0){
      while(offset++!=0){
          _currentHandle--;
          _currentCount--;
       }
    }else if(offset >0){
      while(offset--!=0){
         _currentHandle++;
         _currentCount++;
      }
    }

   *handle = MPFSGetEnd();
}

/*********************************************************************
 * Function:        MPFS MPFSFileTell(void)
 *
 * PreCondition:    MPFSOpen() is already called.
 *
 * Input:           None
 *
 * Output:          beginning of current file
 *
 * Side Effects:    None.
 *
 * Overview:        None
 *
 * Note:            None.
 ********************************************************************/
#define MPFSFileTell()  (_currentFile)

//Now these are global--not initialized to 0
//save a couple hundred bytes of ROM this way
char HTTPbuffer[HTTP_NUM_SOCKETS][HTTP_GET_PARAM_MAX_SIZE];
MPFS http_page_req[HTTP_NUM_SOCKETS];

#if HTTP_USE_AUTHENTICATION
 char http_get_cache[HTTP_NUM_SOCKETS][HTTP_GET_PARAM_MAX_SIZE];
 char http_auth_user[HTTP_NUM_SOCKETS][HTTP_GET_PARAM_MAX_SIZE];
#endif


//////////////////////////////////////////////////////////////////////////////
//
// TCPPutFileParseConst(fstream, n, doSend)
//
// Reads file from mmc.  Stops when it reaches an escape sequence,
// n chars or an end of file
//
// fstream - file sream to read (will be sent as an http/1.1 chunk).  The stream
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
#if 0 //original slow
char TCPPutFileParseConst(MPFS *fstream, unsigned int16 *n, int8 doSend, int1 isPix)
{
   char stopC, checkC;
   unsigned int16 fileSize = 1, max;
   int1 premature = TRUE;
   max = *n;
   MPFSGetBegin(*fstream);
   while (TRUE)
   {
      if(MPFSIsEOF())//EOF
      {
         premature = FALSE;
         break;   
      }
      stopC= MPFSGet();
      if (stopC == '%'&&!isPix)
      {
         checkC= MPFSGet();
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
      else
      {
         if (MPFSIsEOF())
         {
            premature = FALSE;
            break;
         }
         if (((fileSize) < max))
         {
            //if (doSend&&!fateof(fstream))
            if (doSend)
            {
               tcp_http_putc(stopC);
            }
            fileSize++;
         }
         else
            break;
      }
      /*
      if(fateof(fstream))//EOF
      {
         premature = FALSE;
         break;   
      }
      */
   }
   
   *fstream = MPFSGetEnd();
   if (premature==TRUE){
      myMPFSSeek(fstream, -1);  //addy--;
   }
 
   *n = fileSize;
   *fstream = MPFSGetEnd();
   return(stopC);
}
#endif
//new fast
char TCPPutFileParseConst(MPFS *fstream, unsigned int16 max, int1 isPix)
{
   char c;
   unsigned int8 *p;
   unsigned int16 readCount;
   int1 escape = FALSE;
   
   debug_mpfs2(debug_putc, "\r\nTCPPutFileParseConst() c=%X max=%LX f=%LX p=%U ", g_HttpCurrConn, max, *fstream, isPix);
   
   /* 
      this will cause httpTask() to only process 128 bytes at
      a time and allow other processes to run while reading
      page from EE.
   */
   if (max > (unsigned int16)HTTP_SEND_BYTES_PER_CHUNK)
      max = HTTP_SEND_BYTES_PER_CHUNK;
   
   MPFSGetBegin(*fstream);

   while (max && !escape && !MPFSIsEOF())
   {
      p = &HTTPbuffer[g_HttpCurrConn][0];
   
      readCount = MIN(max, HTTP_GET_PARAM_MAX_SIZE);
   
      readCount = MPFSGetBytes(p, readCount);
      
      debug_mpfs2(debug_putc, "r=%LX ", readCount);
         
      while (readCount && !escape)
      {
         readCount--;
         c = *p++;
         if ((c == '%') && !isPix)
         {
            debug_mpfs2(debug_putc, "+%%=");
            if (readCount)
            {
               readCount--;
               c = *p++;
            }
            else
            {
               c = MPFSGet();
            }
            debug_mpfs2(debug_putc, "%X", c);
            if (c != '%')
            {
               escape = TRUE;
               debug_mpfs2(debug_putc, "e");
            }
            debug_mpfs2(debug_putc, " ");
         }
         if (!escape)
         {
            tcp_http_putc(c);
            max--;
         }
      }
      HTTP_INTERRUPT_TASKS();
   }
      
   *fstream = MPFSGetEnd();
   
   if (escape)
   {  
      debug_mpfs2(debug_putc, "f1=%LX ", *fstream);
      *fstream = _MpfsEofLoc;
      debug_mpfs2(debug_putc, "fe=%LX ", *fstream);
      c = '%';
      readCount++;
      myMPFSSeek(fstream, -readCount);  //addy--;
      debug_mpfs2(debug_putc, "r=%LX fr=%LX ", readCount, *fstream);
   }
   else
   {
      c = 0;
   }

   debug_mpfs2(debug_putc, "c=%X e=%U ", c, escape);
 
   return(c);
}

//////////////////////////////////////////////////////////////////////////////
//
// TCPPutFileConstChunk(*addy)
//
// send a chunked response from mmc
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
TCP_PUT_CONST_EC TCPPutFileConstChunk(MPFS *retAddy, int1 isPix)
{
   char stopC;
   unsigned int16 txLeft;
   TCP_PUT_CONST_EC ec;
   MPFSGetBegin(*retAddy);
   txLeft = tcp_http_tx_left();

   if (!txLeft)
   {
      debug_mpfs2(debug_putc, "\r\nTCPPutFileConstChunk() txleft=0 ");
      return(TCP_PUT_CONST_EC_CONTINUE);
   }
   
   stopC=TCPPutFileParseConst(retAddy, txLeft, isPix);
   
   if (stopC == '%'&&!isPix)
   {
      ec = TCP_PUT_CONST_EC_ESCAPE;
   }
   else
   {
      ec = TCP_PUT_CONST_EC_CONTINUE;
   }
   
   if(MPFSIsEOF())//EOF
   {
      ec = TCP_PUT_CONST_EC_FINISH;
   }
   
   debug_mpfs2(debug_putc, "\r\nTCPPutFileConstChunk() stop=%X isPix=%U ec=%X eof=%U ", stopC, isPix, ec, MPFSIsEOF());
   
   *retAddy = MPFSGetEnd();
   
   return(ec);
}


#if HTTP_USE_TRIPLE_ESCAPE
unsigned int16
#else
unsigned int8
#endif
TCPPutFileConstGetEscape(MPFS* fstream)
{
#if HTTP_USE_TRIPLE_ESCAPE
   char str[4];
   uint16_t ret;
   MPFSGetBegin(*fstream);
   str[0]=MPFSGet();
   str[1]=MPFSGet();
   str[2]=MPFSGet();
   str[3] = 0;
   ret = strtol(str, 0, 16);
#elif HTTP_USE_DOUBLE_ESCAPE
   char str[3];
   unsigned int ret;
   MPFSGetBegin(*fstream);
   str[0]=MPFSGet();
   str[1]=MPFSGet();
   //myfatseek(fstream, -2);

   str[2] = 0;
   ret = strtol(str, 0, 16);
#else
   char ret;
   //printf(UserPutc, "\r\nTCPPutFileConstGetEscape() st=%LX ", *fstream);
   MPFSGetBegin(*fstream);
   ret=MPFSGet();
   //MPFSGetEnd(fstream);
   //myfatseek(fstream, -1);//"replace" that char to the stream
#endif
   *fstream = MPFSGetEnd();
   //printf(UserPutc, "ret=%X end=%LX ", ret, *fstream);
   return(ret);
}

int1 tcp_http_put_file(unsigned int16 errorCode, MPFS* MMCfile, char* fname)
{
   static char str[HTTP_NUM_SOCKETS][HTTP_ESCAPED_STR_SIZE];
   char ec;
  #if HTTP_USE_TRIPLE_ESCAPE
   unsigned int16 escaped;
  #else
   unsigned int8 escaped;
  #endif

   MPFS position;   

   static enum
   {
      HTTP_PUT_FILE_INIT = 0,
      HTTP_PUT_FILE_CONTINUE,
      HTTP_PUT_FILE_CHUNK_END,
      HTTP_PUT_FILE_DONE
   } status[HTTP_NUM_SOCKETS];
   
   MPFSGetBegin(*MMCfile); 
     
   position = MPFSTell()-MPFSFileTell();

   debug_html(debug_html_putc, "\r\n** PUT FILE W%U/S%U '%s' EC=%LU MRK=%LX POS=%LX LASTVAR=%LX STATUS=%U ", g_HttpCurrConn, g_HttpCurrSocket, fname, errorCode, *MMCfile, position, lastHTTPPutVarPos[g_HttpCurrConn], status[g_HttpCurrConn]);
   if(position == 0)
   {
      lastHTTPPutVarPos[g_HttpCurrConn] = 0;
      lastHTTPPutConstPos[g_HttpCurrConn] = *MMCfile;
      status[g_HttpCurrConn] = HTTP_PUT_FILE_CONTINUE;

    #if HTTP_USE_CHUNKS
      printf(tcp_http_putc,"HTTP/1.1 %LU ", errorCode);
    #else
      printf(tcp_http_putc,"HTTP/1.1 %LU ", errorCode);
    #endif

      switch(errorCode)
      {
         case 200:
            printf(tcp_http_putc,"OK");
            break;
        #if HTTP_LAST_MODIFIED_CHECK
         case 304:
            printf(tcp_http_putc, "Not Modified");
            break;
        #endif
         case 401:
            printf(tcp_http_putc,"Authorization Required");
            break;
         case 404:
            printf(tcp_http_putc,"Not Found");
            break;
         case 500:
            printf(tcp_http_putc,"Server Error");
            break;
         default:
            break;
      }
      printf(tcp_http_putc, "\r\n");
      
     #if HTTP_USE_AUTHENTICATION
      if (errorCode==401)
         printf(tcp_http_putc, "WWW-Authenticate: Basic realm=\"Authorization Required\"\r\n");
     #endif

      printf(tcp_http_putc, "Content-Type: ");
      strcpypgm2ram(&str[g_HttpCurrConn][0], &gc_MimeTypesHeader[g_HTTPMimeType[g_HttpCurrConn]][0]);
      printf(tcp_http_putc, "%s\r\n", str[g_HttpCurrConn]);
      
      debug_html(debug_html_putc, " content='%s'(%u) ", str[g_HttpCurrConn], g_HTTPMimeType[g_HttpCurrConn]);
      
      if (IsImage(g_HttpCurrConn))
      {
         printf(tcp_http_putc, "Last-Modified: Tue, 15 Nov 1994 12:45:26 GMT\r\n");
      }
      else
      {
         printf(tcp_http_putc, "Cache-Control: no-cache\r\n");
      }

     #if !HTTP_USE_CHUNKS
      printf(tcp_http_putc, "Connection: close\r\n");
     #endif

      printf(tcp_http_putc, "\r\n");
   }
   
  #if HTTP_LAST_MODIFIED_CHECK
   if (errorCode == 304)
   {
      TCPFlush(socket);
      return(TRUE);
   }
  #endif
   
   if (errorCode==500)
   {
      sprintf(fname, "%s", HTTP_500_ERROR_FNAME);
      if(!FileExists(fname))
      {
         printf(tcp_http_putc, "%s", HTML_500_FILE_CONTENTS);
         TCPFlush(g_HttpCurrSocket);
         return(TRUE);
      }
   }

   debug_mpfs2(debug_putc, "\r\nVAR START ST=%X ", status[g_HttpCurrConn]);

   if (lastHTTPPutVarPos[g_HttpCurrConn]!=0)
   {
      TCPPutFileVarChunk(&lastHTTPPutVarPos[g_HttpCurrConn]);
      lastHTTPPutVarPos[g_HttpCurrConn] = 0;
   }

   debug_mpfs2(debug_putc, "\r\nPUT START ST=%X ", status[g_HttpCurrConn]);

   if (status[g_HttpCurrConn] == HTTP_PUT_FILE_CONTINUE)
   {
      for(;;)
      {
         //printf(UserPutc, "\r\nHTTP Put Const st=%LX ", lastHTTPPutConstPos[g_HttpCurrConn]);
         ec = TCPPutFileConstChunk(&lastHTTPPutConstPos[g_HttpCurrConn], IsImage(g_HttpCurrConn));
         //printf(UserPutc, "end=%LX\r\n", lastHTTPPutConstPos[g_HttpCurrConn]);
         if (ec == TCP_PUT_CONST_EC_ESCAPE)//&is_image
         {
            HTTP_INTERRUPT_TASKS();
            escaped = TCPPutFileConstGetEscape(&lastHTTPPutConstPos[g_HttpCurrConn]);////
            http_format_char(fname, escaped, &str[g_HttpCurrConn][0], (sizeof(str)/HTTP_NUM_SOCKETS)-1);
            lastHTTPPutVarPos[g_HttpCurrConn] = &str[g_HttpCurrConn][0];
            ec = TCPPutFileVarChunk(&lastHTTPPutVarPos[g_HttpCurrConn]);
            //printf(UserPutc, "\r\n** HTTP PUT VAR ec=%U escape=0x%LX str='%s' start=0x%LX end=0x%LX status=%U",
            debug_html(debug_html_putc, "\r\n** HTTP PUT VAR ec=%U escape=0x%LX str='%s' start=0x%LX end=0x%LX status=%U",
                  ec,
                  escaped,
                  str[g_HttpCurrConn],
                  &str[g_HttpCurrConn][0],
                  lastHTTPPutVarPos[g_HttpCurrConn],
                  status[g_HttpCurrConn]
               );
            if (ec == TCP_PUT_CONST_EC_FINISH)
               lastHTTPPutVarPos[g_HttpCurrConn] = 0;
            else
               break;
         }
         else
         {
            if (ec == TCP_PUT_CONST_EC_FINISH)
               status[g_HttpCurrConn] = HTTP_PUT_FILE_CHUNK_END;
            break;
         }
         //debug_printf(debug_putc, "\r\nHTTP INTR ");
         HTTP_INTERRUPT_TASKS();
         //debug_printf(debug_putc "DONE ");
         break;
      }
   }
   
   debug_mpfs2(debug_putc, "\r\nPUT END ST=%X ", status[g_HttpCurrConn]);

   if (status[g_HttpCurrConn] == HTTP_PUT_FILE_CHUNK_END)
   {
     #if HTTP_USE_CHUNKS
      if (tcp_http_tx_left() > 8)
      {
         TCPPutFileChunkStart(0);
         TCPPutFileChunkStop();
         status[which] = HTTP_PUT_FILE_DONE;
      }
     #else
      status[g_HttpCurrConn] = HTTP_PUT_FILE_DONE;
     #endif
   }

   *MMCfile = MPFSGetEnd();
   //printf("\r\nFLUSH W%u/S%u/T%u", which,socket,_httpPutcSocket);
   //printf(" RETURN=%U\r\n", ec);
   debug_html(debug_html_putc, "\r\nHTML Flush status=%U ", status[g_HttpCurrConn]);
   
   if (status[g_HttpCurrConn] == HTTP_PUT_FILE_DONE)
   {
      TCPFlush(g_HttpCurrSocket);
      return(TRUE);
   }
   else
   {
      return(FALSE);
   }
}

//initializes the HTTP state machine.  called automatically by the TCP/IP stack
void HTTPInit(void) {
   int8 i;
   //fprintf(USER,"\r\nHTTP OPENING");
   if (HTTP_PORT != 0)
   {
      for (i=0;i<HTTP_NUM_SOCKETS;i++)
      {
         http_state[i]=HTTP_DISABLED;
         
         http_socket[i]=TCPOpen(0, TCP_OPEN_SERVER, HTTP_PORT, TCP_PURPOSE_HTTP_SERVER);
         //fprintf(USER,"\r\nHTTP SOCKET=%X", http_socket[i]);
         if (http_socket[i]!=INVALID_SOCKET)
         {
            http_state[i]=HTTP_LISTEN_WAIT;
         }
      }
   }
   else
   {
      //fprintf(USER,"\r\nHTTP DISABLED");
      for (i=0;i<HTTP_NUM_SOCKETS;i++)
      {
            http_state[i]=HTTP_DISABLED;
      }
   }
}

#DEFINE HTTP_INDEX_PAGE_EC 0x01
#DEFINE HTTP_FILE_PAGE_EC    0x02
#DEFINE HTTP_404_PAGE_EC    0x00
#DEFINE HTTP_401_PAGE_EC    0xFE
#DEFINE HTTP_500_PAGE_EC    0xFF

void HTTPServer(void) {
   static char tokens_header[]=" ";
   static char tokens_get[]="?";
   static char http_get_str[]="GET";
   static char http_post_str[]="POST";
   static char http_len_str[]="Content-Length:";
   unsigned int8 j =0, l=0;
   
   char index[]="/";
   static char page[HTTP_NUM_SOCKETS][20];
   MPFS fstream;
  
  #if defined(__DO_DEBUG_HTML)
   static unsigned int8 debug;
  #endif

   //static char http_keepalive_str[]="keep-alive";
   //static char http_connection_str[]="Connection";



   static unsigned int8 i[HTTP_NUM_SOCKETS];
   static enum {HTTP_REQ_GET=1, HTTP_REQ_POST=2, HTTP_REQ_UNKOWN=0} http_cmd[HTTP_NUM_SOCKETS];
   
   static unsigned int16 http_error_code[HTTP_NUM_SOCKETS];
   static unsigned int16 http_post_len[HTTP_NUM_SOCKETS];
   static TICK http_timer[HTTP_NUM_SOCKETS];
 
 #if HTTP_USE_AUTHENTICATION
   static char http_auth_str[]="Authorization:";
 #endif

   int1 doneSend, postContinue;

   char c, *pKey, *pValue;
   //unsigned int8 hs, currSocket;

   for (g_HttpCurrConn=0; g_HttpCurrConn<HTTP_NUM_SOCKETS; g_HttpCurrConn++)
   {     
      if (http_state[g_HttpCurrConn]==HTTP_DISABLED)
         return;

      g_HttpCurrSocket = http_socket[g_HttpCurrConn];

      if (!TCPIsConnected(g_HttpCurrSocket))
         http_state[g_HttpCurrConn]=HTTP_LISTEN_WAIT;

      switch(http_state[g_HttpCurrConn])
      {
         case HTTP_LISTEN_WAIT:
            if (!TCPIsConnected(g_HttpCurrSocket))
               break;
//            fprintf(USER,"HTTP %U CONNECTED\r\n", hs);

         //wait until we get '\r\n\r\n', which marks the end of the HTTP request header
         case HTTP_CONNECTED:
//            fprintf(USER,"HTTP %U LISTENING\r\n", hs);
            /*
            printf("\r\nHTTP OPEN %U/%U ", hs, currSocket);
               ui_disp_ip_user(&TCB[currSocket].remote.IPAddr)
               printf(" MAC=");
               ui_disp_mac_user(&TCB[currSocket].remote.MACAddr);;
               printf("\r\n");
               */
               
            HTTPbuffer[g_HttpCurrConn][0]=0;
            i[g_HttpCurrConn]=0;
            http_state[g_HttpCurrConn]=HTTP_GET_HEADERS;
            http_timer[g_HttpCurrConn]=TickGet();
            http_page_req[g_HttpCurrConn]=0;
            http_post_len[g_HttpCurrConn]=0;
           #if HTTP_USE_AUTHENTICATION
            http_auth_user[g_HttpCurrConn][0]=0;
           #endif
           #if HTTP_LAST_MODIFIED_CHECK
            g_lastModifiedCheck[g_HttpCurrConn] = FALSE;
           #endif
           debug_html(debug_html_putc, "\r\nHTML Connected %u ", g_HttpCurrConn);
            //http_got_headers[hs]=FALSE;
            //http_isKeepAlive[hs]=FALSE;

         case HTTP_GET_HEADERS:
            if(mpfsFlags.bits.bNotAvailable)
               break;
            postContinue=FALSE;
            while (TCPIsGetReady(g_HttpCurrSocket) && TCPGet(g_HttpCurrSocket, &c))
            {
               //http_got_headers[hs]=TRUE;
               if ( (c >= 0x20) && (i[g_HttpCurrConn] < HTTP_GET_PARAM_MAX_SIZE - 2) )
               {
                  HTTPbuffer[g_HttpCurrConn][i[g_HttpCurrConn]++]=c;
               }
               if (c=='\n')
               {
                  HTTPbuffer[g_HttpCurrConn][i[g_HttpCurrConn]]=0;
                  if (
                       ( ( pKey = strtok(&HTTPbuffer[g_HttpCurrConn][0], tokens_header) ) !=0 ) &&
                       ( ( pValue = strtok(0, tokens_header) ) !=0 )
                     )
                  {
                     debug_html(debug_html_putc, "\r\nHTML Key/Pair '%s'/'%s' ", pKey, pValue);
                     if ( (strcmp(pKey, http_get_str)==0) || (strcmp(pKey, http_post_str)==0) )
                     {
                        if (strcmp(pKey, http_get_str)==0){
                           http_cmd[g_HttpCurrConn]=HTTP_REQ_GET;
                        }
                        else{
                           http_cmd[g_HttpCurrConn]=HTTP_REQ_POST;
                        }
                                          
                        pValue=strtok(pValue, tokens_get);  //chop the file after a ?
                        http_escape_chars(pValue);

                        if (stricmp(pValue,index)==0)
                        {
                           sprintf(pValue, "%s", HTML_INDEX_FNAME);
                           debug_html(debug_html_putc, "index='%s' ", pValue);                           
                        }
                        else
                        {
                           if (pValue[0] == '/')
                                                         pValue++;   //skip leading /
                           j=strlen(pValue);
                           l=j;
                           while(pValue[--j] == 47&& j!=0){//strip out trailing '/' chars
                              pValue[j] = 0;   //this may have to be changed if
                           }               //we want to process directories
                        }
                        
                        debug_html(debug_html_putc, "page='%s' ", pValue);
                        
                        //TODO: do i need the following 2 lines?
                        fstream = MPFSGetEnd();

                        MPFSClose();

                        if (FileExists(pValue))
                        {
                           _strncpy(&page[g_HttpCurrConn][0], pValue, sizeof(page)/HTTP_NUM_SOCKETS);
                           http_error_code[g_HttpCurrConn]=200;
                           debug_html(debug_html_putc, "FOUND ");
                        }
                        else
                        {
                           sprintf(&page[g_HttpCurrConn][0], "%s", HTTP_404_ERROR_FNAME);
                           http_error_code[g_HttpCurrConn]=404;
                           debug_html(debug_html_putc, "MISSING ");
                        }

//                      fprintf(USER,"HTTP %U PVALUE: %s FILE OPENED: %s, handle:%LX\r\n", hs, pValue, page, fstream);
                        pValue=strtok(0, tokens_get);
                       #if HTTP_USE_AUTHENTICATION
                       //we cant execute this until we authorize
                        _strncpy(&http_get_cache[g_HttpCurrConn][0],pValue,(sizeof(http_get_cache)/HTTP_NUM_SOCKETS));
                       #else
                        if (pValue && (http_error_code[g_HttpCurrConn]==200))
                        {
                           http_parse_cgi_string(&page[g_HttpCurrConn][0], pValue);
                        }
                       #endif
                     }
                     else if (http_cmd[g_HttpCurrConn] != HTTP_REQ_UNKOWN)   //we processed a GET or POST
                     {
                        //if you want to parse HTTP headers, do it here.
                        //pKey and pVal hold the individual headers.

                        //parse the Content-Length header.
                        if (strcmp(pKey, http_len_str)==0)
                           http_post_len[g_HttpCurrConn]=atol(pValue);
                      #if HTTP_LAST_MODIFIED_CHECK
                        if (strstr(pKey, "If-Modified-Since") != 0)
                           g_lastModifiedCheck[g_HttpCurrConn] = TRUE;
                      #endif
                      #if HTTP_USE_AUTHENTICATION                        
                        //parse the Authorization header.
                        if (strcmp(pKey, http_auth_str)==0)
                        {
                           _strncpy(http_auth_user, pValue+6,(sizeof(http_auth_user)/HTTP_NUM_SOCKETS));
                           //printf("\r\nAuth Attempt '%s'->'%s'\r\n", pValue, &http_auth_user[hs][0]);
                        }
                      #endif
                     }
                  }
                  else if (i[g_HttpCurrConn] == 0)
                  {
                     //got a double \r\n
                     //fprintf(USER,"HTTP %U GET HEADER DONE\r\n", hs);
                     if (http_cmd[g_HttpCurrConn] == HTTP_REQ_POST)
                     {
                      #if HTTP_USE_AUTHENTICATION
                        http_state[g_HttpCurrConn]=HTTP_CHECK_AUTHENTICATION;
                      #else
                        http_state[g_HttpCurrConn]=HTTP_GET_POST;
                      #endif
                        postContinue=TRUE;
                     }
                     else
                     {
                      #if HTTP_USE_AUTHENTICATION
                        http_state[g_HttpCurrConn]=HTTP_CHECK_AUTHENTICATION;
                      #else
                        http_state[g_HttpCurrConn]=HTTP_SEND_RESPONSE;
                      #endif
                        TCPDiscard(g_HttpCurrSocket);
                     }
                     break;   //break out of read from ethernet loop
                  }
                  i[g_HttpCurrConn]=0;
               }
            }
            if (TickGetDiff(TickGet(),http_timer[g_HttpCurrConn]) > TICKS_PER_SECOND*20)
            {
                  debug_html(debug_html_putc, "\r\nHTTP %U GET HEADER TIMEOUT ", g_HttpCurrConn);
                  sprintf(&page[g_HttpCurrConn][0], "%s", HTTP_500_ERROR_FNAME);
                  http_error_code[g_HttpCurrConn]=500;
                  http_state[g_HttpCurrConn]=HTTP_SEND_RESPONSE;
            }
            if (!postContinue)
               break;

      #if HTTP_USE_AUTHENTICATION
         case HTTP_CHECK_AUTHENTICATION:
            http_state[g_HttpCurrConn]=HTTP_SEND_RESPONSE;
            postContinue=FALSE;
            if (HTTPRequiresAuthentication(&page[g_HttpCurrConn][0], &http_auth_user[g_HttpCurrConn][0]))
            {
               //printf("\r\nAUTH REQUIRED\r\n");
               _strncpy(&page[g_HttpCurrConn][0], http_401_error, sizeof(page)/HTTP_NUM_SOCKETS);
               http_error_code[g_HttpCurrConn]=401;
            }
            else if (http_cmd[g_HttpCurrConn] == HTTP_REQ_POST)
            {
               http_state[g_HttpCurrConn]=HTTP_GET_POST;
               postContinue=TRUE;
            }
            else
            {
               debug_html(debug_html_putc, "\r\n!! AUTH OK !!\r\n");
               http_parse_cgi_string(&page[g_HttpCurrConn][0], &http_get_cache[g_HttpCurrConn][0]);
            }
            if (!postContinue)
               break;
      #endif

         case HTTP_GET_POST:
//            fprintf(USER,"HTTP %U GET POST %LU\r\n", hs, http_post_len[hs]);
            http_state[g_HttpCurrConn]=HTTP_GET_POST_CONTINUE;
            http_timer[g_HttpCurrConn]=TickGet();
            i[g_HttpCurrConn]=0;

         case HTTP_GET_POST_CONTINUE:
            while (
                     TCPIsGetReady(g_HttpCurrSocket) &&
                     TCPGet(g_HttpCurrSocket, &c) &&
                     (http_post_len[g_HttpCurrConn] != 0)
                  )
            {
               http_post_len[g_HttpCurrConn] -= 1;

               if (c!='&')
               {
                  HTTPbuffer[g_HttpCurrConn][i[g_HttpCurrConn]++]=c;
               }

               if ( (c=='&') || (http_post_len[g_HttpCurrConn] == 0) )
               {
                  HTTPbuffer[g_HttpCurrConn][i[g_HttpCurrConn]]=0;

                  //fprintf(USER,"%lu - %s\r\n", http_post_len[hs], &HTTPbuffer[hs][0]);

                  http_parse_cgi_string(&page[g_HttpCurrConn][0], &HTTPbuffer[g_HttpCurrConn][0]);
                  if (http_post_len[g_HttpCurrConn] == 0)
                  {
                     http_state[g_HttpCurrConn]=HTTP_SEND_RESPONSE;
                     TCPDiscard(g_HttpCurrSocket);
                     break;
                  }
                  else
                     i[g_HttpCurrConn]=0;
               }
            }
            if (TickGetDiff(TickGet(),http_timer[g_HttpCurrConn]) > TICKS_PER_SECOND*20)
            {
               debug_html(debug_html_putc, "\r\nHTTP %U GET POST TIMEOUT ", g_HttpCurrConn);
               sprintf(&page[g_HttpCurrConn][0], HTTP_500_ERROR_FNAME);
               http_error_code[g_HttpCurrConn]=500;
               http_state[g_HttpCurrConn]=HTTP_SEND_RESPONSE;
            }
            break;

         case HTTP_SEND_RESPONSE:
            //putc('.');
            if(mpfsFlags.bits.bNotAvailable)
               break;
//            fprintf(USER,"HTTP %U SEND RESPONSE\r\n", hs);
            //putc('*');
            g_HTTPMimeType[g_HttpCurrConn] = HTTPFindMimeType(&page[g_HttpCurrConn][0]);
           #if HTTP_LAST_MODIFIED_CHECK
            if (IsImage(g_HttpCurrConn) && g_lastModifiedCheck[g_HttpCurrConn])
            {
               http_error_code[g_HttpCurrConn] = 304;
            }
           #endif
            fstream = MPFSOpen(page);
            if (fstream == MPFS_INVALID)
            {
               sprintf(page, HTTP_500_ERROR_FNAME);
               http_error_code[g_HttpCurrConn]=500;
               fstream = MPFSOpen(page);
            }
            MPFSGetBegin(fstream);
            http_page_req[g_HttpCurrConn]=fstream;
            lastHTTPPutConstPos[g_HttpCurrConn]=0;
            http_state[g_HttpCurrConn]=HTTP_SEND_RESPONSE_CONTINUE;

         case HTTP_SEND_RESPONSE_CONTINUE:
            TCPDiscard(g_HttpCurrSocket);
            //putc('@');
             if (TCPIsPutReady(g_HttpCurrSocket))
            {
               //printf("\r\nPut Page Segment %U/%U EC=%LU '%s' %LX ", hs, currSocket, http_error_code[hs], page, http_page_req[hs]);
               /*
               ui_disp_mac_user(&TCB[currSocket].remote.MACAddr);
               printf(" MAC=");
               ui_disp_ip_user(&TCB[currSocket].remote.IPAddr);
               printf("\r\n");
               */
               http_timer[g_HttpCurrConn]=TickGet();
               
//               fprintf(USER,"\r\nPUTTING HTTP SEG\r\n");
               doneSend=tcp_http_put_file(http_error_code[g_HttpCurrConn], &http_page_req[g_HttpCurrConn], &page[g_HttpCurrConn][0]);
               if (doneSend!=0)
               {
                  debug_html(debug_html_putc, "\r\nHTML Done sending page ");
                  //if (http_isKeepAlive[hs])
                  //   http_state[hs]=HTTP_CONNECTED;
                  //else
                  //   http_state[hs]=HTTP_CLOSE;
                  http_state[g_HttpCurrConn] = HTTP_CLOSE;
                  
                  fstream = MPFSGetEnd(); 
                  MPFSClose();
//                  fprintf(USER,"HTTP %U RESPONSE SENT\r\n", hs);
               }
            }
            if ((TickGet() - http_timer[g_HttpCurrConn]) >= (TICK)15*TICKS_PER_SECOND)
            {
               http_state[g_HttpCurrConn] = HTTP_CLOSE;
            }
            break;

         case HTTP_CLOSE:
            //since we set connection: close in the header, the client
            //should automatically close.  but after so many seconds we
            //shall kill the connection
            /*
            printf("\r\nClosing HTTP %U/%U.... ", hs, currSocket);
               ui_disp_mac_user(&TCB[currSocket].remote.MACAddr);
               printf(" MAC=");
               ui_disp_ip_user(&TCB[currSocket].remote.IPAddr);
               printf("\r\n");
               */
            
            http_state[g_HttpCurrConn]=HTTP_CLOSE_WAITING;
            http_timer[g_HttpCurrConn]=TickGet();
            
         case HTTP_CLOSE_WAITING:
            TCPDiscard(g_HttpCurrSocket);
            if (  
                  (TCPGetTxFIFOFull(g_HttpCurrSocket) == 0) ||
                  (TickGetDiff(TickGet(),http_timer[g_HttpCurrConn]) > (TICKS_PER_SECOND*8))
               )
            {
               if (TCPGetTxFIFOFull(g_HttpCurrSocket) != 0)
               {
                  //socket is messed up.  just kill it by calling TCPDisconnect() twice.
                  TCPDisconnect(g_HttpCurrSocket);
               }
               TCPDisconnect(g_HttpCurrSocket);
               http_state[g_HttpCurrConn]=HTTP_CLOSED;
            }
            break;

         case HTTP_CLOSED: //do nothing until socket actually closes
         default:
            break;
      }
      
     #if defined(__DO_DEBUG_HTML)
      //HTTP_NUM_SOCKETS
      if (debug != http_state[g_HttpCurrConn])
      {
         debug_html(debug_html_putc, "\r\nHTML %U %X->%X ", g_HttpCurrConn, debug, http_state[g_HttpCurrConn]);
         debug = http_state[g_HttpCurrConn];
      }
     #endif
   }
}
