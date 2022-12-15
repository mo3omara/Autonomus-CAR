/*
 * DIO_configuration.h
 *
 * Created: 10/2/2022 11:06:08 PM
 *  Author: Omar Wessam
 */ 


#ifndef DIO_CONFIGURATION_H_
#define DIO_CONFIGURATION_H_


#include "cpu_config.h"
typedef enum
{
	DIO_PORTA=0,
	DIO_PORTB=1,
	DIO_PORTC=2,
	DIO_PORTD=3
	
}DIO_PORT;

typedef enum
{
	DIO_PIN0=0,
	DIO_PIN1=1,
	DIO_PIN2=2,
	DIO_PIN3=3,
	DIO_PIN4=4,
	DIO_PIN5=5,
	DIO_PIN6=6,
	DIO_PIN7=7
	
}DIO_PIN;

typedef enum
{
	DIO_INPUT=0,
	DIO_OUTPUT=1
}DIO_State;

typedef enum
{
	DIO_LOW=0,
	DIO_HIGH=1
}DIO_Status;



#endif /* DIO_CONFIGURATION_H_ */