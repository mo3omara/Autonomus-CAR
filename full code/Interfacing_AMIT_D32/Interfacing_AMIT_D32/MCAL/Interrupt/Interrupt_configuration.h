
/*
 * Interrupt_configuration.h
 *
 * Created: 10/13/2022 3:00:26 PM
 *  Author: Omar Wessam
 */ 
#include "cpu_config.h"
#include "Interrupt_adresses.h"
typedef enum
{
	LOW     =0,
	HIGH    =1,
	FALLING =2,
	RISING  =3
}interrupt_sense;

typedef enum
{
	LOW1     =0,
	HIGH1    =1,
	FALLING1 =2,
	RISING1  =3
}interrupt1_sense;

typedef enum
{
	EXT_INT0 =0,
	EXT_INT1 =1,
	EXT_INT2 =2
}interrupts;