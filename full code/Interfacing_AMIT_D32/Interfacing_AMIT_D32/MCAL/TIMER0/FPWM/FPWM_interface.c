/*
 * FPWM_interface.c
 *
 * Created: 10/27/2022 10:59:45 AM
 *  Author: Omar Wessam
 */ 
#include "FPWM_private.h"

void F_PWM_Intialize(F_PWM_prescaler prescaler)
{
	//define direction of 0C0 pin direction as output "output pin that will have the required voltage"
	SET_BIT(DDRB,PB3);
	//choose timer mode as FPWM
	SET_BIT(TCCR0,WGM01);SET_BIT(TCCR0,WGM00);
	//choose mode
	
	//choose prescaler (not now)
	CLR_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);
	
	
	
	
}
void F_PWM_Stop(void)
{
	//clear prescalar
	CLR_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);
}
void F_PWM_SET_DutyCycle(uint8_t duty,F_PWM_InveringMode mode)
{
	//choose mode
	switch (mode)
	{
		case Disconnected_OC0:
		CLR_BIT(TCCR0,COM01);
		CLR_BIT(TCCR0,COM00);
		
		break;
		
		case Inverting:
		SET_BIT(TCCR0,COM01);
		SET_BIT(TCCR0,COM00);
		
		OCR0= (FPWM_BITS-1)-(((FPWM_BITS*duty) /100 ) -1)  ;
		break;
		
		case Non_inverting:
		SET_BIT(TCCR0,COM01);
		CLR_BIT(TCCR0,COM00);
		
		OCR0= ((FPWM_BITS*duty) /100 ) -1  ;
		break;
		
	}
	
}