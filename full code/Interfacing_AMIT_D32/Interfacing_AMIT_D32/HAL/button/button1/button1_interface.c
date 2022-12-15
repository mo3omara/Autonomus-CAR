/*
 * button0_interface.c
 *
 * Created: 9/30/2022 3:45:49 PM
 *  Author: Omar Wessam
 */ 
#include "button1_private.h"

void BTN1_intialize (void)
{
	DIO_SET_PinDirection(BTN1_PORT,BTN1_PIN,BTN1_INPUT);
}
Uint8_t BTN1_Read(void)
{
	Uint8_t reading =BTN1_OFF;
	_delay_ms(10);
	reading =DIO_Read_PinValue(BTN1_PORT,BTN1_PIN);
	if (reading == BTN1_ON)
	return BTN1_ON;
	

	else
	return BTN1_OFF;
}