/*
 * button2_interface.c
 *
 * Created: 10/8/2022 2:00:52 PM
 *  Author: Omar Wessam
 */ 
#include "button2_private.h"

void BTN2_intialize (void)
{
	DIO_SET_PinDirection(BTN2_PORT,BTN2_PIN,BTN2_INPUT);
}
Uint8_t BTN2_Read(void)
{
	Uint8_t reading =BTN2_OFF;
	_delay_ms(10);
	reading =DIO_Read_PinValue(BTN2_PORT,BTN2_PIN);
	if (reading == BTN2_ON)
		return BTN2_ON;
	
	else
		return BTN2_OFF;
	
	
	
}