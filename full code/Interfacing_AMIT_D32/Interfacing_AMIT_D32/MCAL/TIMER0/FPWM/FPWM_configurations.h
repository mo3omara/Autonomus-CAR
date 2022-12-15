/*
 * FPWM_configurations.h
 *
 * Created: 10/27/2022 10:58:52 AM
 *  Author: Omar Wessam
 */ 


#ifndef FPWM_CONFIGURATIONS_H_
#define FPWM_CONFIGURATIONS_H_
#include "FPWM_addresses.h"
#include "cpu_config.h"

#define FPWM_BITS 256
#define FPWM_prescalar 1024
#define FPWM_frequency 16
#define FPWM_MICRO_SEC 1000

typedef enum
{
	Disconnected_OC0=0,
	Non_inverting=1,
	Inverting=2
	
}F_PWM_InveringMode;

typedef enum
{
	disable=0,
	enable=1
	
}F_PWM_prescaler;


#endif /* FPWM_CONFIGURATIONS_H_ */