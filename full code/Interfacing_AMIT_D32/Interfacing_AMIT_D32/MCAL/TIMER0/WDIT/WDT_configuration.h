/*
 * WDT_configuration.h
 *
 * Created: 10/21/2022 3:47:45 PM
 *  Author: Omar Wessam
 */ 


#ifndef WDT_CONFIGURATION_H_
#define WDT_CONFIGURATION_H_

#include "cpu_config.h"

typedef enum
{
	WDT_5V=0,
	WDT_3V=1
}WDT_Volatage;

typedef enum
{
	WDT_pre16  =0,
	WDT_pre32  =1,
	WDT_pre64  =2,
	WDT_pre128 =3,
	WDT_pre256 =4,
	WDT_pre512 =5,
	WDT_pre1024=6,
	WDT_pre2048=7
	

}WDT_prescaler;

#endif /* WDT_CONFIGURATION_H_ */