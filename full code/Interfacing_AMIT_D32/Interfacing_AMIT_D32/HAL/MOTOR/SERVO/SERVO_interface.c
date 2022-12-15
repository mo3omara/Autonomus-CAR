/*
 * SERVO_interface.c
 *
 * Created: 10/27/2022 11:15:27 PM
 *  Author: Omar Wessam
 */ 
#include "SERVO_private.h"
void Servo_intialize(void)
{
	//define direction of OC1A pin as output
	SET_BIT(DDRD,5);
	//choose FPWM mode where the ICR1 is the top value
	SET_BIT(TCCR1A,WGM11);CLR_BIT(TCCR1A,WGM10);SET_BIT(TCCR1B,WGM12);SET_BIT(TCCR1B,WGM13);
	//choose non inverting mode 
	SET_BIT(TCCR1A,COM1A1);CLR_BIT(TCCR1A,COM1A0);
	//choose prescalar 256	
	SET_BIT(TCCR1B,CS12);
	//set new top value
	ICR1=1250;
}
void Servo_Rotate(float angle)
{
	OCR1A = (  (ICR1*angle) /100  ) - 1;//output pin from mcu to the servo motor "if pulse is 1ms--0 degree"  "if pulse is 1.5ms--90 degree"
}