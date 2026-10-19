
#include "mqx.h"
#include "bsp.h"
#include "bsp_prv.h"
#include "enet.h"
#include "enetprv.h"
#include "phy_ksz8081.h"

static bool phy_ksz8081_discover_addr(ENET_CONTEXT_STRUCT_PTR enet_ptr);
static bool phy_ksz8081_init(ENET_CONTEXT_STRUCT_PTR enet_ptr);
static uint32_t phy_ksz8081_get_speed(ENET_CONTEXT_STRUCT_PTR enet_ptr);
static bool phy_ksz8081_get_link_status(ENET_CONTEXT_STRUCT_PTR enet_ptr);

const ENET_PHY_IF_STRUCT phy_ksz8081_IF = {
  phy_ksz8081_discover_addr,
  phy_ksz8081_init,
  phy_ksz8081_get_speed,
  phy_ksz8081_get_link_status
};
  
volatile uint32_t errorCount = 0;
  

/*FUNCTION*-------------------------------------------------------------
*
*  Function Name  : phy_ksz8041_discover_addr
*  Returned Value : none
*  Comments       :
*    Scan possible PHY addresses looking for a valid device
*
*END*-----------------------------------------------------------------*/

static bool phy_ksz8081_discover_addr(ENET_CONTEXT_STRUCT_PTR enet_ptr)
{ 
   uint32_t  i;
   uint32_t  id;

   for (i = 0; i < 32; i++)
   {
      id = 0;
      enet_ptr->PHY_ADDRESS = i;
      if ((*enet_ptr->PARAM_PTR->ENET_IF->MAC_IF->PHY_READ)(enet_ptr, PHY_MII_REG_PHYIR1, &id, MII_TIMEOUT)) 
      {
          if ((id != 0) && (id != 0xffff)) 
          {
                return TRUE;
          }
      } 
   } 
   
   return FALSE; 
} 


/*FUNCTION*-------------------------------------------------------------
*
*  Function Name  : phy_ksz8081_init
*  Returned Value : boolean
*  Comments       :
*    Wait for PHY to automatically negotiate its configuration
*
*END*-----------------------------------------------------------------*/

static bool phy_ksz8081_init(ENET_CONTEXT_STRUCT_PTR enet_ptr)
{ 
   uint32_t              phy_status=0;

   // tell the phy that we're using 50MHz clocks.
   if ((*enet_ptr->PARAM_PTR->ENET_IF->MAC_IF->PHY_READ)(enet_ptr, PHY_MII_REG_PHYC2, &phy_status, MII_TIMEOUT))
   {
      phy_status |= PHY_MII_REG_PHY2_RMII_REFERENCE_CLOCK_SELECT;
      (*enet_ptr->PARAM_PTR->ENET_IF->MAC_IF->PHY_WRITE)(enet_ptr, PHY_MII_REG_PHYC2, phy_status, MII_TIMEOUT);
   }

   if (enet_ptr->PARAM_PTR->OPTIONS & ENET_OPTION_PHY_LOOPBACK)
   {
      if ((*enet_ptr->PARAM_PTR->ENET_IF->MAC_IF->PHY_READ)(enet_ptr, PHY_MII_REG_CR, &phy_status, MII_TIMEOUT))
      {
         phy_status |= PHY_MII_REG_CR_LOOP;
         (*enet_ptr->PARAM_PTR->ENET_IF->MAC_IF->PHY_WRITE)(enet_ptr, PHY_MII_REG_CR, phy_status, MII_TIMEOUT);
         return TRUE;
      }
   }
   else
   {
      if ((*enet_ptr->PARAM_PTR->ENET_IF->MAC_IF->PHY_READ)(enet_ptr, PHY_MII_REG_SR, &phy_status, MII_TIMEOUT))
      {
         if (phy_status & PHY_MII_REG_SR_AN_ABLE)
         { 
            // Has auto-negotiate ability
            int i;
            for (i = 0; i < 3 * BSP_ALARM_FREQUENCY; i++)
            {
               if ((*enet_ptr->PARAM_PTR->ENET_IF->MAC_IF->PHY_READ)(enet_ptr, PHY_MII_REG_SR, &phy_status, MII_TIMEOUT))
               {
                  if ((phy_status & PHY_MII_REG_SR_AN_COMPLETE) != 0)
                  {
                     return TRUE;
                  }
               }
               _time_delay(BSP_ALARM_RESOLUTION);
            }  
         }
         return TRUE;
      }  
   }  
   return FALSE;
}  


/*FUNCTION*-------------------------------------------------------------
*
*  Function Name  : phy_ksz8081_get_speed
*  Returned Value : uint_32 - connection speed
*  Comments       :
*    Determine if connection speed is 10 or 100 Mbit
*
*END*-----------------------------------------------------------------*/

static uint32_t phy_ksz8081_get_speed(ENET_CONTEXT_STRUCT_PTR enet_ptr)
{ 
   uint32_t speed_status;

   if ((*enet_ptr->PARAM_PTR->ENET_IF->MAC_IF->PHY_READ)(enet_ptr, PHY_MII_REG_PHYC1, &speed_status, MII_TIMEOUT))
   {
      speed_status &= PHY_MII_REG_PHYC1_OP_MODE_MASK;
  
      if ((PHY_MII_REG_PHYC1_OP_MODE_10_HD == speed_status) ||
          (PHY_MII_REG_PHYC1_OP_MODE_10_FD == speed_status))
      {
         return 10;
      }
      else if ((PHY_MII_REG_PHYC1_OP_MODE_100_HD == speed_status) ||
               (PHY_MII_REG_PHYC1_OP_MODE_100_FD == speed_status))
      {
         return 100;
      }
   }
   return 0;
} 

  
/*FUNCTION*-------------------------------------------------------------
*
*  Function Name  : phy_ksz8081_get_link_status
*  Returned Value : TRUE if link active, FALSE otherwise
*  Comments       : 
*    Get actual link status.
*
*END*-----------------------------------------------------------------*/

static bool phy_ksz8081_get_link_status(ENET_CONTEXT_STRUCT_PTR enet_ptr)
{ 
   uint32_t data;
   bool res = FALSE;
   
   if ((*enet_ptr->PARAM_PTR->ENET_IF->MAC_IF->PHY_READ)(enet_ptr, PHY_MII_REG_CR, &data, MII_TIMEOUT))
   {
       /* After power up, when PHY does not fully initial PHY_MII_REG_SR_LINK_STATUS bit 
        * is '1'. So if we get link status in this case, the return result is always "Connected" 
        * even when we haven't plug the cable in yet. 
        * Check if PHY in normal operation -> ready to get link status */
       if ((data & PHY_MII_REG_CR_RESET) == 0 )
       {
           /* Some PHY (e.g.DP8340) returns "unconnected" and than "connected" state
           *  just to show that was transition event from one state to another.
           *  As we need only curent state,  read 2 times and return 
           *  the current/latest state. */
           if ((*enet_ptr->PARAM_PTR->ENET_IF->MAC_IF->PHY_READ)(enet_ptr, PHY_MII_REG_SR, &data, MII_TIMEOUT))
           {
              if ((*enet_ptr->PARAM_PTR->ENET_IF->MAC_IF->PHY_READ)(enet_ptr, PHY_MII_REG_SR, &data, MII_TIMEOUT))
              {
                 res = ((data & PHY_MII_REG_SR_LINK_STATUS) != 0) ? TRUE : FALSE;
              }
           }
       }
   }

  return res;
}
