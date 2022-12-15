/*
 * cpu_config.h
 *
 * Created: 9/29/2022 11:30:51 PM
 *  Author: Omar Wessam
 */ 


#ifndef CPU_CONFIG_H_
#define CPU_CONFIG_H_

#undef F_CPU
#define F_CPU 16000000

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>
#include <string.h>

#include "BIT_MATH.h"
#include "Standard_Types.h"
#include "DIO_private.h"
/*#include "Interrupt_private.h"
#include "ADC_private.h"
#include "OVF_private.h"*/



#endif /* CPU_CONFIG_H_ */