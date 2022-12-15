/*
 * LEDD_interface.c
 *
 * Created: 10/2/2022 10:44:43 PM
 *  Author: Omar Wessam
 */ 
#include "LED0_private.h"
#include "LED1_private.h"
#include "LED2_private.h"


void LED_intialize(int LED_NUM)
{
	if (LED_NUM==0)
	{
		DIO_SET_PinDirection(PORT_LED0,PIN_LED0,OUT_LED0);
	}
	else if (LED_NUM==1)
	{
		DIO_SET_PinDirection(PORT_LED1,PIN_LED1,OUT_LED1);
	}
	else if (LED_NUM==2)
	{
		DIO_SET_PinDirection(PORT_LED2,PIN_LED2,OUT_LED2);
	}
	
}

void LED_ON(int LED_NUM)
{
	if (LED_NUM==0)
	{
		DIO_SET_PinValue(PORT_LED0,PIN_LED0,HIGH_LED0);
	}
	else if (LED_NUM==1)
	{
		DIO_SET_PinValue(PORT_LED1,PIN_LED1,HIGH_LED1);
	}
	else if (LED_NUM==2)
	{
		DIO_SET_PinValue(PORT_LED2,PIN_LED2,HIGH_LED2);
	}
}

void LED_OFF(int LED_NUM)
{
	if (LED_NUM==0)
	{
		DIO_SET_PinValue(PORT_LED0,PIN_LED0,LOW_LED0);
	}
	else if (LED_NUM==1)
	{
		DIO_SET_PinValue(PORT_LED1,PIN_LED1,LOW_LED1);
	}
	else if (LED_NUM==2)
	{
		DIO_SET_PinValue(PORT_LED2,PIN_LED2,LOW_LED2);
	}
}

void LED_TGL(int LED_NUM)
{
	if (LED_NUM==0)
	{
		DIO_TGL_PinValue(PORT_LED0,PIN_LED0);
	}
	else if (LED_NUM==1)
	{
		DIO_TGL_PinValue(PORT_LED1,PIN_LED1);
	}
	else if (LED_NUM==2)
	{
		DIO_TGL_PinValue(PORT_LED2,PIN_LED2);
	}
}