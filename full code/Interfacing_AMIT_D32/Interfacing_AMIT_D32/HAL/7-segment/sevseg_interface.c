/*
 * _7_segment_interface.c
 *
 * Created: 10/3/2022 11:26:19 PM
 *  Author: Omar Wessam
 */ 
#include "SEVSEG_private.h"

void SEVSEG_intialize(void)
{
	//control ports
	DIO_SET_PinDirection(SEVSEG_CNTRL_PORT,SEVSEG_EN1_PIN,SEVSEG_OUT);
	DIO_SET_PinDirection(SEVSEG_CNTRL_PORT,SEVSEG_EN2_PIN,SEVSEG_OUT);
	DIO_SET_PinDirection(SEVSEG_CNTRL_PORT,SEVSEG_DIP_PIN,SEVSEG_OUT);
	//data ports
	DIO_SET_PinDirection(SEVSEG_DATA_PORT,SEVSEG_A,SEVSEG_OUT);
	DIO_SET_PinDirection(SEVSEG_DATA_PORT,SEVSEG_B,SEVSEG_OUT);
	DIO_SET_PinDirection(SEVSEG_DATA_PORT,SEVSEG_C,SEVSEG_OUT);
	DIO_SET_PinDirection(SEVSEG_DATA_PORT,SEVSEG_D,SEVSEG_OUT);
}

void SEVSEG_Enable1(void)
{
	DIO_SET_PinValue(SEVSEG_CNTRL_PORT,SEVSEG_EN1_PIN,SEVSEG_HIGH);
}
void SEVSEG_Enable2(void)
{
	DIO_SET_PinValue(SEVSEG_CNTRL_PORT,SEVSEG_EN2_PIN,SEVSEG_HIGH);
}

void SEVSEG_Disable1(void)
{
	DIO_SET_PinValue(SEVSEG_CNTRL_PORT,SEVSEG_EN1_PIN,SEVSEG_LOW);
}
void SEVSEG_Disable2(void)
{
	DIO_SET_PinValue(SEVSEG_CNTRL_PORT,SEVSEG_EN2_PIN,SEVSEG_LOW);
}

void SEVSEG_DIP_Enable(void)
{
	DIO_SET_PinValue(SEVSEG_CNTRL_PORT,SEVSEG_DIP_PIN,SEVSEG_HIGH);
}
void SEVSEG_DIP_Disable(void)
{
	DIO_SET_PinValue(SEVSEG_CNTRL_PORT,SEVSEG_DIP_PIN,SEVSEG_LOW);
}

void SEVSEG_unit(uint8_t number)
{
	uint8_t units=number%10;
	PORTA=(units<<4);
	SEVSEG_Enable1();
	SEVSEG_Disable2();
	_delay_ms(1);
}

void SEVSEG_tenth(uint8_t number)
{
	uint8_t tenths=number/10;
	PORTA=(tenths<<4);
	SEVSEG_Enable2();
	SEVSEG_Disable1();
	_delay_ms(1);
}


void SEVSEG_Display(uint8_t number)
{
	SEVSEG_unit(number);
	SEVSEG_tenth(number);
}
void SEVSEG_Display_99(void)
{
    Uint8_t i=0;
	
	for (;i<100;i++)
	{
		for (int j=0;j<500;j++)
		{
			SEVSEG_Display(i);
			_delay_ms(1);
		}
	}
	
	
}