/*
   Implementation of HTCPCP
   
   See RFC 2324 for documentation
*/

#ifndef HTCPCP_C
#define HTCPCP_C

#include <stdint.h>

typedef struct
{
   uint16_t errorCode;
   const char* errorString;
} htcpcp_errors_t;

const htcpcp_errors_t g_HtcpcErrors[] =
{
   {406, "Not Acceptable"},	//The HTCPCP server is unable to brew coffee for some reason; the response should indicate a list of acceptable coffee types.
   {418, "I'm a teapot"}      //The HTCPCP server is a teapot; the resulting entity may be short and stout.
};

typedef enum
{
   HTCPCP_CMD_BREW = 0,
   HTCPCP_CMD_GET = 1,
   HTCPCP_CMD_PROPFIND = 2,
   HTCPCP_CMD_WHEN = 3
} htcpcp_cmd_idx_t;

const char* g_HtcpcCommands[] =
{
   "BREW",     //Causes the HTCPCP server to brew coffee.
   "GET",	   //Retrieves coffee from the HTCPCP server.
   "PROPFIND",	//Finds out metadata about the coffee.
   "WHEN"      //Says "when", causing the HTCPCP server to stop pouring milk into the coffee (if applicable).
};

#error finish

#endif
