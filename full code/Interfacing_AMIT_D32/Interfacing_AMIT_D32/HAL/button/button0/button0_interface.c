/*
 * button0_interface.c
 *
 * Created: 9/30/2022 3:45:49 PM
 *  Author: Omar Wessam
 */ 
#include "button0_private.h"

void BTN0_intialize (void)
{
	DIO_SET_PinDirection(BTN0_PORT,BTN0_PIN,DIO_INPUT);
	DIO_SET_PinPullUp(BTN0_PORT,BTN0_PIN);
}
Uint8_t BTN0_Read(void)
{
	Uint8_t reading =BTN0_OFF;
	_delay_ms(10);
	reading =DIO_Read_PinValue(BTN0_PORT,BTN0_PIN);
	if (reading == BTN0_ON)
		return BTN0_ON;
	

	else 
		return BTN0_OFF;
	
	
	
}