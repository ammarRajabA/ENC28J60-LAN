/*
   Gratuitous Arp
   
   see ccs_gratarp.h for documentation
*/

#ifndef __CCS_GRATARP_C__
#define __CCS_GRATARP_C__

enum
{
   GRAT_ARP_SM_WAIT_FOR_LINK = 0,
   GRAT_ARP_SM_RUNNING
} g_GratArpSm;

TICK g_GratArpTick;
TICK g_GratArpDuration;

int1 g_GratArpEnabled = TRUE;
int1 g_GratArpForced = FALSE;

// reset the 120s timer so it will take a new 120s to send a gratuitous arp
void GratArpReset(void)
{
   if ((g_GratArpSm == GRAT_ARP_SM_RUNNING) && !g_GratArpForced)
   {
      g_GratArpDuration = 120 * TICKS_PER_SECOND;
      g_GratArpTick = TickGet();
   }
}

void GratArpInit(void)
{
   g_GratArpSm = GRAT_ARP_SM_WAIT_FOR_LINK;
}

void GratArpSetEnabled(int1 new)
{
   if (new && !g_GratArpEnabled)
   {
      g_GratArpSm = GRAT_ARP_SM_WAIT_FOR_LINK;
   }
   g_GratArpEnabled = new;
}

int1 GratAprIsEnabled(void)
{
   return(g_GratArpEnabled);
}

void GratArpSetForced(int1 new)
{
   g_GratArpForced = new;
}

int1 GratArpIsForced(void)
{
   return(g_GratArpForced);
}

static int1 GratArpSend(void)
{
   static unsigned int8 op_req;
   
   if (!WFisConnected() || !MACIsTxReady())
   {
      return(FALSE);
   }
   
   op_req = op_req == ARP_OPERATION_REQ ? ARP_OPERATION_RESP : ARP_OPERATION_REQ;
   
   return(ARPSendPkt(*(DWORD *)&AppConfig.MyIPAddr, *(DWORD *)&AppConfig.MyIPAddr, op_req ));
}

void GratArpTask(void)
{
   if (!g_GratArpEnabled)
      return;

   if (g_GratArpSm == GRAT_ARP_SM_WAIT_FOR_LINK)
   {
      if (IsLinked())
      {
         g_GratArpSm = GRAT_ARP_SM_RUNNING;
         g_GratArpDuration = 3 * TICKS_PER_SECOND;
         g_GratArpTick = TickGet();
      }
   }
   
   if (g_GratArpSm == GRAT_ARP_SM_RUNNING)
   {
      if (!IsLinked())
      {
         g_GratArpSm = GRAT_ARP_SM_WAIT_FOR_LINK;
      }
      else if 
      (
         ((TickGet() - g_GratArpTick) > g_GratArpDuration) &&
         (GratArpSend())
      )
      {
         g_GratArpDuration = 3 * TICKS_PER_SECOND;
         g_GratArpTick = TickGet();      
      }
   }
}


#endif
