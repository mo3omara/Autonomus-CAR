/*
 * DIO_interface.c
 *
 * Created: 10/2/2022 11:06:59 PM
 *  Author: Omar Wessam
 */ 
#include "DIO_private.h"

void DIO_SET_PinDirection(DIO_PORT port,DIO_PIN pin,DIO_State state)
{
	if (state==DIO_INPUT)
	{
		switch (port)
		{
			case DIO_PORTA:
			CLR_BIT(DDRA,pin);
			break;
			
			case DIO_PORTB:
			CLR_BIT(DDRB,pin);
			break;
			
			case DIO_PORTC:
			CLR_BIT(DDRC,pin);
			break;
			
			case DIO_PORTD:
			CLR_BIT(DDRD,pin);
			break;
			
		}
		
	}
	
	else
	{
		switch (port)
		{
			case DIO_PORTA:
			SET_BIT(DDRA,pin);
			break;
			
			case DIO_PORTB:
			SET_BIT(DDRB,pin);
			break;
			
			case DIO_PORTC:
			SET_BIT(DDRC,pin);
			break;
			
			case DIO_PORTD:
			SET_BIT(DDRD,pin);
			break;
			
		}
		
	}
}

void DIO_SET_PinValue(DIO_PORT port,DIO_PIN pin,DIO_Status status)
{
	if (status==DIO_LOW)
	{
		switch (port)
		{
			case DIO_PORTA:
			CLR_BIT(PORTA,pin);
			break;
			
			case DIO_PORTB:
			CLR_BIT(PORTB,pin);
			break;
			
			case DIO_PORTC:
			CLR_BIT(PORTC,pin);
			break;
			
			case DIO_PORTD:
			CLR_BIT(PORTD,pin);
			break;
			
		}
		
	}
	
	else
	{
		switch (port)
		{
			case DIO_PORTA:
			SET_BIT(PORTA,pin);
			break;
			
			case DIO_PORTB:
			SET_BIT(PORTB,pin);
			break;
			
			case DIO_PORTC:
			SET_BIT(PORTC,pin);
			break;
			
			case DIO_PORTD:
			SET_BIT(PORTD,pin);
			break;
			
		}
		
	}
	
}

void DIO_TGL_PinValue(DIO_PORT port,DIO_PIN pin)
{
	switch (port)
	{
		case DIO_PORTA:
		TGL_BIT(PORTA,pin);
		break;
		
		case DIO_PORTB:
		TGL_BIT(PORTB,pin);
		break;
		
		case DIO_PORTC:
		TGL_BIT(PORTC,pin);
		break;
		
		case DIO_PORTD:
		TGL_BIT(PORTD,pin);
		break;
		
	}
}
Uint8_t DIO_Read_PinValue(DIO_PORT port,DIO_PIN pin)
{
	Uint8_t x=0;
	switch (port)
	{
		case DIO_PORTA:
		x=GET_BIT(PINA,pin);
		break;
		
		case DIO_PORTB:
		x=GET_BIT(PINB,pin);
		break;
		
		case DIO_PORTC:
		x=GET_BIT(PINC,pin);
		break;
		
		case DIO_PORTD:
		x=GET_BIT(PIND,pin);
		break;
		
	}
	return x;
}

void DIO_SET_PinPullUp(DIO_PORT port,DIO_PIN pin)
//activate the pullup circuit by setting the pin by 1 
//in case of using output register "port" 
{
	switch (port)
	{
		case DIO_PORTA:
		SET_BIT(PORTA,pin);
		break;
		
		case DIO_PORTB:
		SET_BIT(PORTB,pin);
		break;
		
		case DIO_PORTC:
		SET_BIT(PORTC,pin);
		break;
		
		case DIO_PORTD:
		SET_BIT(PORTD,pin);
		break;
		
	}
	
}