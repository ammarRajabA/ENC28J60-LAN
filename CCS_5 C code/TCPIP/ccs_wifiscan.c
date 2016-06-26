// ccs_wifiscan.c
//
// Extra state-machine code for handling AP scanning and getting RSSI of 
// current connection.
///////////////////////////////////////////////////////////////////////////
////        (C) Copyright 1996, 2013 Custom Computer Services          ////
//// This source code may only be used by licensed users of the CCS C  ////
//// compiler.  This source code may only be distributed to other      ////
//// licensed users of the CCS C compiler.  No other use, reproduction ////
//// or distribution is permitted without written permission.          ////
//// Derivative programs created using this software in object code    ////
//// form are not restricted in any way.                               ////
///////////////////////////////////////////////////////////////////////////

#ifndef __CCS_WIFISCAN_C__
#define __CCS_WIFISCAN_C__

#ifndef debug_scan_printf
   #define debug_scan_printf(a,b,c,d,e,f,g,h,i,j,k,l)
   #define debug_scan_putc(c)
#endif

#ifndef STACK_USE_CCS_SCAN_TASK_RSSI_PERIOD
#define STACK_USE_CCS_SCAN_TASK_RSSI_PERIOD  ((TICK)60 * TICKS_PER_SECOND)
#endif

tWFScanResult g_WifiScanScrResult;

UINT8 g_ScanConnectionProfile;

#if defined(CCS_WIFISCAN_EE_LOC)
static void _WifiScanResultsToEE(uint8_t num);
#endif

static void _WIFIScanResults(unsigned int8 num, int1 valid);

enum
{
   WIFI_SCAN_STATE_IDLE = 0,
   WIFI_SCAN_DOING_AP,
   WIFI_SCAN_DOING_RSSI,
  #if defined(CCS_WIFISCAN_EE_LOC) && !defined(CCS_WIFISCAN_IMMEDIATE_READ)
   WIFI_SCAN_SAVING_AP_TO_EE,
  #endif
  #if !defined(CCS_WIFISCAN_IMMEDIATE_READ)
   WIFI_SCAN_READ_RSSI
  #endif
} g_WifiScanState;

#if defined(CCS_WIFISCAN_EE_LOC)
unsigned int8 g_WifiScanToEE;
#define g_WifiScanRssiDisable FALSE
#else
unsigned int8 g_WifiScanApNum;   //0xFF is invalid
int1 g_WifiScanRssiDisable;
#endif

UINT8 g_WifiScanRssiValue; //0 is lowest value.  0xff is invalid
TICK g_WifiScanRssiTick;

int1 g_WifiScanApWhenReady;

void WIFIScanDiscard(void)
{
  #if defined(CCS_WIFISCAN_EE_LOC)
   unsigned int8 num = 0xFF;
   EEWriteBytes(CCS_WIFISCAN_EE_LOC, &num, 1);
  #else
   g_WifiScanApNum = 0xFF;
   
   g_WifiScanRssiDisable = FALSE;
  #endif
  
  #if defined(CCS_WIFISCAN_DONT_AUTO_CONNECT)
   WIFIConnectStart();
  #endif
}

static void _WIFIAPScanStart(void)
{
   UINT16 ret16 = WF_SUCCESS;
   UINT8 cp;
  #if defined(CCS_WIFISCAN_FIXED_TYPE)
   UINT8 WIFIConnectTask_Scratch[6];
  #endif

   WIFIConnectStop(); 
   
   debug_scan_printf(debug_scan_putc, "\r\n_WIFIAPScanStart() ");
   
   g_WifiScanApWhenReady = FALSE;
   
   g_WifiScanState = WIFI_SCAN_DOING_AP;
  
  #if defined(CCS_WIFISCAN_EE_LOC)
   _WifiScanResultsToEE(0xFF);
  #else
   g_WifiScanRssiDisable = TRUE;
   g_WifiScanApNum = 0xFF;   
  #endif
      
  #if !defined(CCS_WIFISCAN_FIXED_TYPE)
   cp = WF_SCAN_ALL;
  #else
   if (g_ScanConnectionProfile != 0xFF)
   {
      debug_scan_printf(debug_scan_putc, "\r\nDeleting scan profile %U", g_ScanConnectionProfile);
      WF_CPDelete(g_ScanConnectionProfile);
      g_ScanConnectionProfile = 0xFF;
   }
   
   debug_scan_printf(debug_scan_putc, "\r\nCreating scan profile");
   
   WF_CPCreate(&g_ScanConnectionProfile);
   
   if (g_ScanConnectionProfile == 0xFF)
   {
      debug_scan_printf(debug_scan_putc, "\r\nERR Scan Profile %LX\r\n", g_ScanConnectionProfile);
      ret16 = -1;
   }
   else
   {
      cp = g_ScanConnectionProfile;

      /*WF_CPSetSsid(g_ScanConnectionProfile, 
                 AppConfig.MySSID, 
                 AppConfig.SsidLength);*/
      
      memset(WIFIConnectTask_Scratch, 0xFF, 6);
      WF_CPSetBssid(g_ScanConnectionProfile, WIFIConnectTask_Scratch);

      WF_CPSetNetworkType(g_ScanConnectionProfile, CCS_WIFISCAN_FIXED_TYPE);
      
      //WF_CASetScanType(MY_DEFAULT_SCAN_TYPE);   // was WF_ACTIVE_SCAN

      //WF_CASetChannelList(WIFI_channelList, WIFI_numChannelsInList); //was AppConfig.channelList, AppConfig.numChannelsInList

      //WF_SetRegionalDomain(WIFI_region);  //was AppConfig.region   
   }
  #endif
   
   if (ret16 == WF_SUCCESS)
   {
      debug_scan_printf(debug_scan_putc, "\r\nStarting scan profile %U", cp);
      ret16 = WF_Scan(cp);
   }
   
   if (ret16 != WF_SUCCESS)  //error
   {
      debug_scan_printf(debug_scan_putc, "\r\nERR WF_Scan %U %LX\r\n", cp, ret16);
      _WIFIScanResults(0, FALSE);
   }
}

int1 WIFIRSSIIsValid(void)
{
   return((g_WifiScanRssiValue != 0xFF) && !g_WifiScanRssiDisable);
}

unsigned int8 WIFIRSSIGet(void)
{
   return(g_WifiScanRssiValue);
}

void WIFIScanStart(void)
{
   g_WifiScanApWhenReady = TRUE;
}

int1 WIFIScanIsBusy(void)
{
   return
   (  
      g_WifiScanApWhenReady
      || (g_WifiScanState == WIFI_SCAN_DOING_AP)
     #if defined(CCS_WIFISCAN_EE_LOC) && !defined(CCS_WIFISCAN_IMMEDIATE_READ)
      || (g_WifiScanState == WIFI_SCAN_SAVING_AP_TO_EE)
     #endif
   );
}

int1 WIFIScanIsValid(void)
{
  #if defined(CCS_WIFISCAN_EE_LOC)
   unsigned int8 ret;
   EEReadBytes(&ret, CCS_WIFISCAN_EE_LOC, 1);
   return(ret != 0xFF);
  #else
   return(g_WifiScanApNum != 0xFF);
  #endif
}

unsigned int8 WIFIScanGetNum(void)
{
  #if defined(CCS_WIFISCAN_EE_LOC)
   unsigned int8 ret;
   EEReadBytes(&ret, CCS_WIFISCAN_EE_LOC, 1);
   return(ret);
  #else
   return(g_WifiScanApNum);
  #endif
}

UINT8 _WIFIScanNormalizeRSSIValue(UINT8 rssi)
{
   //rssi is the value from tWFScanResult.
   //it doesn't have units.  also the range is different between the B and
   //G module.  this will normalize it to a set range for all modules where
   //0 is worst.
   
  #if defined(MRF24WG)
   #define __RSSI_MIN   43
   #define __RSSI_MAX   128
  #else
   #define __RSSI_MIN   106
   #define __RSSI_MAX   200
  #endif
  
  #if 1
   if (rssi < __RSSI_MIN)
      rssi = __RSSI_MIN;
   
   rssi -= __RSSI_MIN;
  #endif
   
   return(rssi);
}

unsigned int8 WIFIScanResultSecurityType(tWFScanResult *pResult)
{
   unsigned int8 ret, apConfig;
   
   apConfig = pResult->apConfig;
   
   ret = WF_SECURITY_OPEN;
   
   if (bit_test(apConfig, 4))
   {
      if (bit_test(apConfig, 6))
      {
         ret = WF_SECURITY_WPA_WITH_PASS_PHRASE;
      }
      else if (bit_test(apConfig, 7))
      {
         ret = WF_SECURITY_WPA2_WITH_PASS_PHRASE;
      }
      else
      {
         ret = WF_SECURITY_WEP_AUTO;
      }         
   }
   
   return(ret);
}

#if defined(CCS_WIFISCAN_EE_LOC)
#if (CCS_WIFISCAN_EE_SIZE < sizeof(tWFScanResult))
#error not allocating enough space in EEPROM for individual scan result
#endif
#endif

static void _WIFIScanNormalizeValues(void)
{  
   g_WifiScanScrResult.ssid[WF_MAX_SSID_LENGTH-1] = 0;   //WF_MAX_SSID_LENGTH and ssidLen
   if (g_WifiScanScrResult.ssidLen < WF_MAX_SSID_LENGTH)
   {
      g_WifiScanScrResult.ssid[g_WifiScanScrResult.ssidLen] = 0;
   }
   
   g_WifiScanScrResult.rssi = _WIFIScanNormalizeRSSIValue(g_WifiScanScrResult.rssi);
}

void WIFIScanGetResult(unsigned int8 index, tWFScanResult *pResult)
{
  #if defined(CCS_WIFISCAN_EE_LOC)
   EEPROM_ADDRESS loc;
  #endif
   
   memset(pResult, 0x00, sizeof(tWFScanResult));
   
   if (WIFIScanIsValid() && (index < WIFIScanGetNum()))
   {  
     #if defined(CCS_WIFISCAN_EE_LOC)
      loc = CCS_WIFISCAN_EE_LOC + 1;
      loc += (EEPROM_ADDRESS)index * CCS_WIFISCAN_EE_SIZE;
      EEReadBytes(pResult, loc, sizeof(tWFScanResult));
     #else
      WF_ScanGetResult(index, &g_WifiScanScrResult);
      
      _WIFIScanNormalizeValues();
      
      memcpy(pResult, &g_WifiScanScrResult, sizeof(g_WifiScanScrResult));
     #endif
   }
}
  
void WIFIScanInit(void)
{
   g_ScanConnectionProfile = 0xFF;
   
   g_WifiScanApWhenReady = FALSE;
   
   g_WifiScanState = WIFI_SCAN_STATE_IDLE;
     
   WIFIScanDiscard();

   g_WifiScanRssiValue = 0xFF;
}

#if defined(CCS_WIFISCAN_EE_LOC)
typedef struct
{
   UINT8 index;
   UINT8 rssi;
} rssi_qsort_t;


signed int8 _WifiRssiQsortCompare(void* a, void* b)
{
   UINT8 rssiA, rssiB;
   
   rssiA = ((rssi_qsort_t*)a)->rssi;
   rssiB = ((rssi_qsort_t*)b)->rssi;
   
   /*  //this is for sorting low to high
   if (rssiA < rssiB)   return -1;
   if (rssiA > rssiB)   return 1;
   return 0;   //rssiA == rssiB
   */
   
   // this is for sorting high to low
   if (rssiA < rssiB)   return 1;
   if (rssiA > rssiB)   return -1;
   return 0;   //rssiA == rssiB
}

void _WifiRssiQsortFunc(char * qdata, unsigned int qitems, unsigned int qsize) 
{
   unsigned int m,j,i,l;
   int1 done;
   unsigned int8 t[16];

   m = qitems/2;
   while( m > 0 ) {
     for(j=0; j<(qitems-m); ++j) {
        i = j;
        do
        {
           done=1;
           l = i+m;
           if(_WifiRssiQsortCompare(qdata+i*qsize, qdata+l*qsize) > 0 ) {
              memcpy(t, qdata+i*qsize, qsize);
              memcpy(qdata+i*qsize, qdata+l*qsize, qsize);
              memcpy(qdata+l*qsize, t, qsize);
              if(m <= i)
                i -= m;
                done = 0;
           }
        } while(!done);
     }
     m = m/2;
   }
}

#ifndef WIFI_SCAN_SORT_TABLE_SIZE
#define WIFI_SCAN_SORT_TABLE_SIZE   64
#endif

// pass 0xFF for num to clear/invalidate values in memory
// pass 0 for num for valid results of none found
// else num represents valid results of num number.
static void _WifiScanResultsToEE(uint8_t num)
{
   EEPROM_ADDRESS loc;
   UINT8 numSaved = 0;
   UINT8 listIndex;
   rssi_qsort_t sortTable[WIFI_SCAN_SORT_TABLE_SIZE];

   debug_scan_printf(debug_scan_putc, "\r\n_WifiScanResultsToEE %u ", num);

   if (num == 0xFF)
   {
      EEWriteBytes(CCS_WIFISCAN_EE_LOC, &num, 1);
   }
   else
   {   
      loc = CCS_WIFISCAN_EE_LOC + 1;
      
      listIndex = 0;
      
      memset(sortTable, 0x00, sizeof(sortTable));
      
      while ((listIndex < num) && (listIndex < WIFI_SCAN_SORT_TABLE_SIZE))
      {
         //debug_scan_printf(debug_scan_putc, "\r\nWF_ScanGetResult %u ... ", listIndex);
         
         WF_ScanGetResult(listIndex, &g_WifiScanScrResult);
         
         //debug_scan_printf(debug_scan_putc, "DONE! ");
         
         sortTable[listIndex].index = listIndex;
         sortTable[listIndex].rssi = g_WifiScanScrResult.rssi;
         
         listIndex++;
      }
      
      _WifiRssiQsortFunc(sortTable, listIndex, sizeof(rssi_qsort_t));
      
      listIndex = 0;
      
      while ((listIndex < num) && (numSaved < CCS_WIFISCAN_EE_NUM))
      {
         //debug_scan_printf(debug_scan_putc, "\r\nWF_ScanGetResult SORTED %u ... ", listIndex);
         
         WF_ScanGetResult(sortTable[listIndex].index, &g_WifiScanScrResult);
         
         //debug_scan_printf(debug_scan_putc, "DONE! ");

         if (g_WifiScanScrResult.ssidLen)
         {
            _WIFIScanNormalizeValues();   

            //debug_scan_printf(debug_scan_putc, "\r\nSaving %u (%u) '%s' ", listIndex, sortTable[listIndex].index, g_WifiScanScrResult.ssid);
           
            EEWriteBytes(loc, &g_WifiScanScrResult, sizeof(tWFScanResult));
            
            loc += CCS_WIFISCAN_EE_SIZE;
                        
            numSaved++;
         }
         
         listIndex++;
      }
      
      debug_scan_printf(debug_scan_putc, "\r\nDone, saved %u ", numSaved);
      
      EEWriteBytes(CCS_WIFISCAN_EE_LOC, &numSaved, 1);
   }
}
#endif

static int1 WIFIScanMACIsReady(void)
{
   int1 ret;
   unsigned int8 tcpSock = 0;
   
   ret = MACIsTxReady();
   
   while(ret && (tcpSock < TCP_CONFIGURATION))
   {
      if (TCPIsConnected(tcpSock) && !TCPIsPutReady(tcpSock))
      {
         ret = FALSE;
      }
      tcpSock++;
   }
   
   return(ret);
}

static void _WIFIScanResultHandleRSSI(void)
{
   WF_ScanGetResult(0, &g_WifiScanScrResult);
   _WIFIScanNormalizeValues();
   g_WifiScanRssiValue = g_WifiScanScrResult.rssi;
   
   g_WifiScanState = WIFI_SCAN_STATE_IDLE;
   
   g_WifiScanRssiTick = TickGet();
}

static void _WIFIScanResultHandleAP(void)
{
   _WifiScanResultsToEE(g_WifiScanToEE);
   
   g_WifiScanState = WIFI_SCAN_STATE_IDLE;
   
   WIFIConnectStart();
}

void WIFIScanTask(void)
{
  #if 0
   static UINT8 debug = 0xFF;
   
   if (g_WifiScanState != debug)
   {
      debug_scan_printf(debug_scan_putc, "\r\nWIFIScanTask %x -> %x ", debug, g_WifiScanState);
      debug = g_WifiScanState;
   }
  #endif
  
  #if defined(CCS_WIFISCAN_EE_LOC) && !defined(CCS_WIFISCAN_IMMEDIATE_READ)
   if (g_WifiScanState == WIFI_SCAN_SAVING_AP_TO_EE)
   {
      _WIFIScanResultHandleAP();
   }
  #endif
   
  #if !defined(CCS_WIFISCAN_IMMEDIATE_READ)
   if (g_WifiScanState == WIFI_SCAN_READ_RSSI)
   {
      _WIFIScanResultHandleRSSI();
   }
  #endif
   
   if (g_WifiScanState != WIFI_SCAN_STATE_IDLE)
   {
      return;
   }
   
   if (g_WifiScanApWhenReady && WIFIScanMACIsReady())
   {        
      _WIFIAPScanStart();
   }
   else if
   (
      !g_WifiScanRssiDisable &&
      (g_connectionProfileID != 0xFF) && 
     #if !defined(CCS_WIFISCAN_DURING_ADHOC)
      (AppConfig.networkType != WF_ADHOC) &&
     #endif
      MACIsLinked() &&
      WIFIScanMACIsReady() &&
      ((TickGet() - g_WifiScanRssiTick) >= STACK_USE_CCS_SCAN_TASK_RSSI_PERIOD)
   )
   {
      if (WF_Scan(g_connectionProfileID) == WF_SUCCESS)
      {
         g_WifiScanState = WIFI_SCAN_DOING_RSSI;
         debug_scan_printf(debug_scan_putc, "\r\nPeriodic scan start. ");
      }
      else
      {
         g_WifiScanRssiValue = 0xFF;
         debug_scan_printf(debug_scan_putc, "\r\nPeriodic scan fail. ");
      }
      
      g_WifiScanRssiTick = TickGet();
   }   
   else if
   (
      (g_connectionProfileID == 0xFF) ||
      !MACIsLinked()
   )
   {
      //cause an immediate scan once we connect
      g_WifiScanRssiTick = TickGet();
      g_WifiScanRssiTick -= STACK_USE_CCS_SCAN_TASK_RSSI_PERIOD;
   }
}

void WIFIScanIgnoreResults(void)
{  
/*
   if 
   (
     #if !defined(CCS_WIFISCAN_EE_LOC)
      (g_WifiScanApNum != 0xFF)
     #elif defined(CCS_WIFISCAN_EE_LOC) && !defined(CCS_WIFISCAN_IMMEDIATE_READ)
      (g_WifiScanState == WIFI_SCAN_SAVING_AP_TO_EE)
     #else
      FALSE
     #endif
     #if !defined(CCS_WIFISCAN_IMMEDIATE_READ)
      || (g_WifiScanState == WIFI_SCAN_READ_RSSI)
     #endif
   )
   {
      debug_scan_printf(debug_scan_putc, "\r\nWIFIIgnoreResults ");
      
      WIFIScanInit();
      
      WIFIConnectStart();
   }
   */
   
   // abort any pending results and ignore any incoming results.
   g_WifiScanState = WIFI_SCAN_STATE_IDLE;
}

static void _WIFIScanResults(unsigned int8 num, int1 valid)
{  
   if (g_WifiScanState == WIFI_SCAN_DOING_RSSI)
   {
      if ((num == 0) || !valid)
      {
         if (!valid)
         {
            g_WifiScanRssiValue = 0xFF;
         }
         
         g_WifiScanState = WIFI_SCAN_STATE_IDLE;
      }
      else
      {
        #if defined(CCS_WIFISCAN_IMMEDIATE_READ)
         _WIFIScanResultHandleRSSI();
        #else
         g_WifiScanState = WIFI_SCAN_READ_RSSI;
        #endif
      }
   }
   else if (g_WifiScanState == WIFI_SCAN_DOING_AP)
   {
      if (!valid)
      {
         num = 0xFF;
      }
      
     #if defined(CCS_WIFISCAN_EE_LOC) && defined(CCS_WIFISCAN_IMMEDIATE_READ)
      _WIFIScanResultHandleAP();
     #elif defined(CCS_WIFISCAN_EE_LOC)
      g_WifiScanState = WIFI_SCAN_SAVING_AP_TO_EE;
      g_WifiScanToEE = num;
     #else
      g_WifiScanState = WIFI_SCAN_STATE_IDLE;
      g_WifiScanApNum = num;
      #if !defined(CCS_WIFISCAN_DONT_AUTO_CONNECT)
      WIFIConnectStart();
      #endif
     #endif
   }
}

void WIFIScanResults(unsigned int8 num)
{
   _WIFIScanResults(num, TRUE);
}

#endif
