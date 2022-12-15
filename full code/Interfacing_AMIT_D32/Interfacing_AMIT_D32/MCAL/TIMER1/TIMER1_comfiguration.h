/*
 * TIMER1_comfiguration.h
 *
 * Created: 11/16/2022 1:41:51 AM
 *  Author: Omar Wessam
 */ 


#ifndef TIMER1_COMFIGURATION_H_
#define TIMER1_COMFIGURATION_H_

#include "cpu_config.h"

#define OVF1_BITS 65535
#define OVF1_prescalar 1
#define OVF1_frequency 16
#define OVF1_MICRO_SEC 1000



typedef enum
{
	With_interrupt1=0,
	no_interrupt1=1
}TIMER1_OVF_Interrupt;


typedef enum
{
	rising=0,
	falling=1
}TIMER1_OVF_EDGE;
#endif /* TIMER1_COMFIGURATION_H_ */