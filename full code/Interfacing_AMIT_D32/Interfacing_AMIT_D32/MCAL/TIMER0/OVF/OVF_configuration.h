
/*
 * OVF_configuration.h
 *
 * Created: 10/20/2022 3:54:28 PM
 *  Author: Omar Wessam
 */ 
#include "cpu_config.h"
#include "OVF_adresses.h"

#define OVF_BITS 256
#define OVF_prescalar 1024
#define OVF_frequency 16
#define OVF_MICRO_SEC 1000

/*typedef enum
{
	
	No_CLK_SRC     =0,//CLOCK is off
	No_Prescaling  =1, // working with no Prescaling 'same CPU frequency'
	prescaling_8   =2,
	prescaling_64  =3,
	prescaling_256 =4,
	prescaling_1024=5,
	prescaling_EXE_FALL =6,
	prescaling_EXE_RISE =7
	
}TIMER0_OVF_PRESCALAR;*/

/*typedef enum
{
	
}TIMER0_OVF_OCPin;*/

typedef enum
{
	With_interrupt=0,
	no_interrupt=1
}TIMER0_OVF_Interrupt;
