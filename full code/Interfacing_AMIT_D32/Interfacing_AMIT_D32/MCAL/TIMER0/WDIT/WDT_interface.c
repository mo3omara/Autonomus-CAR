
/*
 * WDT_interface.c
 *
 * Created: 10/21/2022 3:47:07 PM
 *  Author: Omar Wessam
 */ 
#include "WDT_private.h"

void WDT_intialize(WDT_prescaler prescalar)
{
	//WD timer turn-off Enable
	SET_BIT(WDTCR,WDTOE);
	//WD timer Enable
	SET_BIT(WDTCR,WDE);
	
	switch (prescalar)
	{
		case WDT_pre16:
		break;
		
		case WDT_pre32:
		break;
		
		case WDT_pre64:
		break;
		
		case WDT_pre128:
		break;
		
		case WDT_pre256:
		break;
		
		case WDT_pre512:
		break;
		
		case WDT_pre1024:
		break;
		
		case WDT_pre2048:
		SET_BIT(WDTCR,WDP2);
		SET_BIT(WDTCR,WDP1);
		SET_BIT(WDTCR,WDP0);
		break;
		
	}	
}
void WDT_refresh(void)
{
	//refresh by the powerful instruction of the WDR
	asm("WDR");
	
}