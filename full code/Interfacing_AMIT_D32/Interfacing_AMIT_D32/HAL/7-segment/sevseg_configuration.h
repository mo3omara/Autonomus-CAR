/*
 * _7_segment_configuration.h
 *
 * Created: 10/3/2022 11:25:40 PM
 *  Author: Omar Wessam
 */ 


#ifndef SEVSEG_CONFIGURATION_H_
#define SEVSEG_CONFIGURATION_H_

#include "cpu_config.h"

#define SEVSEG_DATA_PORT DIO_PORTA
#define SEVSEG_CNTRL_PORT DIO_PORTB

//DATA PINS
#define SEVSEG_A DIO_PIN4
#define SEVSEG_B DIO_PIN5
#define SEVSEG_C DIO_PIN6
#define SEVSEG_D DIO_PIN7
//CONTROL PINS
#define SEVSEG_EN1_PIN DIO_PIN1
#define SEVSEG_EN2_PIN DIO_PIN2
#define SEVSEG_DIP_PIN DIO_PIN3
//STATE
#define SEVSEG_OUT DIO_OUTPUT
//STATUS
#define SEVSEG_LOW DIO_LOW
#define SEVSEG_HIGH DIO_HIGH

//uint8_t numbers[][]=
//{0001},{0010},{0011},{0100},{}
	



#endif /* 7-SEGMENT_CONFIGURATION_H_ */