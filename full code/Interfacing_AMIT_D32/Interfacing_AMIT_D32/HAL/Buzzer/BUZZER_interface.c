/*
 * BUZZER_interface.c
 *
 * Created: 10/2/2022 10:48:46 PM
 *  Author: Omar Wessam
 */ 

#include "BUZZER_private.h"

void BUZZER_intialize(void)
{
	DIO_SET_PinDirection(BUZZER_PORT,BUZZER_PIN,BUZZER_OUT);
}
void BUZZER_ON(void)
{
	
	DIO_SET_PinValue(BUZZER_PORT,BUZZER_PIN,BUZZER_HIGH);
}
void BUZZER_OFF(void)
{
	DIO_SET_PinValue(BUZZER_PORT,BUZZER_PIN,BUZZER_LOW);
}