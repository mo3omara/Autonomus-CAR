/*
 * DC_interface.c
 *
 * Created: 10/27/2022 3:24:10 PM
 *  Author: Omar Wessam
 */ 
#include "DC_private.h"

void Motor_intialization(void)
{
	//intialize pins for motor 1
	DIO_SET_PinDirection(MOTOR_CNTRL_PRT,MOTOR1_EN,DIO_OUTPUT);
	DIO_SET_PinDirection(MOTOR_DRIVE_PRT,MOTOR1_COIL1,DIO_OUTPUT);
	DIO_SET_PinDirection(MOTOR_DRIVE_PRT,MOTOR1_COIL2,DIO_OUTPUT);
	//intialize pins for motor 2
	
	DIO_SET_PinDirection(MOTOR_CNTRL_PRT,MOTOR2_EN,DIO_OUTPUT);
	DIO_SET_PinDirection(MOTOR_DRIVE_PRT,MOTOR2_COIL1,DIO_OUTPUT);
	DIO_SET_PinDirection(MOTOR_DRIVE_PRT,MOTOR2_COIL2,DIO_OUTPUT);
}
void Motor_ON (Motor_No number,Motor_Direction direction)
{
	switch (number)
	{
		case Motor1:
		//enable motor 1
		DIO_SET_PinValue(MOTOR_CNTRL_PRT,MOTOR1_EN,MOTOR_HIGH);
		switch (direction)
		{
			case Motor_CW:
			DIO_SET_PinValue(MOTOR_DRIVE_PRT,MOTOR1_COIL1,MOTOR_LOW);
			DIO_SET_PinValue(MOTOR_DRIVE_PRT,MOTOR1_COIL2,MOTOR_HIGH);
			break;
			
			case Motor_CCW:
			DIO_SET_PinValue(MOTOR_DRIVE_PRT,MOTOR1_COIL2,MOTOR_LOW);
			DIO_SET_PinValue(MOTOR_DRIVE_PRT,MOTOR1_COIL1,MOTOR_HIGH);
			break;
		}
		break;
			
		case Motor2:
		//enable motor 2
		DIO_SET_PinValue(MOTOR_CNTRL_PRT,MOTOR2_EN,MOTOR_HIGH);
		switch (direction)
		{
			case Motor_CW:
			DIO_SET_PinValue(MOTOR_DRIVE_PRT,MOTOR2_COIL1,MOTOR_LOW);
			DIO_SET_PinValue(MOTOR_DRIVE_PRT,MOTOR2_COIL2,MOTOR_HIGH);
			break;
			
			case Motor_CCW:
			DIO_SET_PinValue(MOTOR_DRIVE_PRT,MOTOR2_COIL2,MOTOR_LOW);
			DIO_SET_PinValue(MOTOR_DRIVE_PRT,MOTOR2_COIL1,MOTOR_HIGH);
			break;
		}
		break;
	}
}
void Motor_OFF(Motor_No number)
{
	switch (number)
	{
		case Motor1:
		DIO_SET_PinValue(MOTOR_CNTRL_PRT,MOTOR1_EN,MOTOR_LOW);
		DIO_SET_PinValue(MOTOR_DRIVE_PRT,MOTOR1_COIL1,MOTOR_LOW);
		DIO_SET_PinValue(MOTOR_DRIVE_PRT,MOTOR1_COIL2,MOTOR_LOW);
		break;
		case Motor2:
		DIO_SET_PinValue(MOTOR_CNTRL_PRT,MOTOR2_EN,MOTOR_LOW);
		DIO_SET_PinValue(MOTOR_DRIVE_PRT,MOTOR2_COIL1,MOTOR_LOW);
		DIO_SET_PinValue(MOTOR_DRIVE_PRT,MOTOR2_COIL2,MOTOR_LOW);
		break;
	}
}