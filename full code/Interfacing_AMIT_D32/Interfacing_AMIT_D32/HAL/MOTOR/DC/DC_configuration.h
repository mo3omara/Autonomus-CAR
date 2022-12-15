/*
 * DC_configuration.h
 *
 * Created: 10/27/2022 3:22:35 PM
 *  Author: Omar Wessam
 */ 


#ifndef DC_CONFIGURATION_H_
#define DC_CONFIGURATION_H_
#include "cpu_config.h"

#define MOTOR_CNTRL_PRT DIO_PORTD
#define MOTOR_DRIVE_PRT DIO_PORTC
//motor 1
#define MOTOR1_EN DIO_PIN4
#define MOTOR1_COIL1 DIO_PIN3
#define MOTOR1_COIL2 DIO_PIN4
//motor 2
#define MOTOR2_EN DIO_PIN5
#define MOTOR2_COIL1 DIO_PIN5
#define MOTOR2_COIL2 DIO_PIN6

#define MOTOR_LOW DIO_LOW
#define MOTOR_HIGH DIO_HIGH

typedef enum
{
	Motor1=0,
	Motor2=1
}Motor_No;

typedef enum
{
	Motor_CW=0,
	Motor_CCW=1
	
}Motor_Direction;


#endif /* DC_CONFIGURATION_H_ */