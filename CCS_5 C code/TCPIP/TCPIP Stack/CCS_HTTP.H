///////////////////////////////////////////////////////////////////////////
///                                                                     ///
///                              HTTP.H                                 ///
///                                                                     ///
/// Simple webserver for the Microchip TCP/IP stack.                    ///
/// NOTE: THIS IS A DIFFERENT HTTP.H THAN WHAT MICROCHIP PROVIDES       ///
///                                                                     ///
/// See HTTP.C for documenation                                         ///
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


#ifndef HTTP_USE_CHUNKS
#define HTTP_USE_CHUNKS   FALSE
#endif

#ifndef HTTP_USE_DOUBLE_ESCAPE
#define HTTP_USE_DOUBLE_ESCAPE   FALSE
#endif

#ifndef HTTP_USE_CONTENT_TYPE
#define HTTP_USE_CONTENT_TYPE   FALSE
#endif

#ifndef HTTP_PORT
#define HTTP_PORT             80
#endif

#ifndef HTTP_NUM_SOCKETS
#define HTTP_NUM_SOCKETS      1
#endif

#ifndef HTTP_GET_PARAM_MAX_SIZE
#define HTTP_GET_PARAM_MAX_SIZE  254
#endif

void HTTPInit(void);
void HTTPServer(void);

//**** CALLBACKS START ******///

/// the following three functions are callbacks and
/// must be written in your main application!!!  see the documentation above
/// for more help.

#if HTTP_USE_CONTENT_TYPE
 void http_get_page(char *file_str, unsigned int32 *retAddress, char *retStr);
#else
 unsigned int32 http_get_page(char *file_str);
#endif

unsigned int8 http_format_char(unsigned int32 file, char id, char *str, unsigned int8 max_ret);
void http_exec_cgi(unsigned int32 file, char *key, char *val);

//**** CALLBACKS END ******///
