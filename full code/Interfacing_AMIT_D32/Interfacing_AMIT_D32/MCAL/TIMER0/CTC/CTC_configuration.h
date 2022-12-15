
/*
 * CTC_configuration.h
 *
 * Created: 10/20/2022 3:55:39 PM
 *  Author: Omar Wessam
 */ 
#include "cpu_config.h"
#include "CTC_addresses.h"

#define CTC_BITS 256
#define CTC_prescalar 1024
#define CTC_frequency 16
#define CTC_MICRO_SEC 1000

/*typedef enum
{
	
}TIMER0_CTC_PRESCALAR;

typedef enum
{
	
}TIMER0_CTC_OCPin;*/
typedef enum
{
	With_interrupt_CTC=0,
	no_interrupt_CTC=1  
}TIMER0_CTC_Interrupt;
