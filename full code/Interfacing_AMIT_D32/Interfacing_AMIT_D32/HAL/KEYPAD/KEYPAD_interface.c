
/*
 * KEYPAD_interface.c
 *
 * Created: 10/11/2022 4:22:34 PM
 *  Author: Omar Wessam
 */ 

#include "KEYPAD_private.h"

const uint8_t saved[4][4] =
{
	{'1','2','3','A'},
	{'4','5','6','B'},
	{'7','8','9','C'},
	{'*','0','#','D'}
};

void KEYPAD_Intialize (void)
{
	//setting input pins
	DIO_SET_PinDirection(KEYPAD_PORT,KEYPAD_PIN_INP0,KEYPAD_INPUT);
	DIO_SET_PinDirection(KEYPAD_PORT,KEYPAD_PIN_INP1,KEYPAD_INPUT);
	DIO_SET_PinDirection(KEYPAD_PORT,KEYPAD_PIN_INP2,KEYPAD_INPUT);
	DIO_SET_PinDirection(KEYPAD_PORT,KEYPAD_PIN_INP3,KEYPAD_INPUT);
	//setting output pins
	DIO_SET_PinDirection(KEYPAD_PORT,KEYPAD_PIN_OUT0,KEYPAD_OUTPUT);
	DIO_SET_PinDirection(KEYPAD_PORT,KEYPAD_PIN_OUT1,KEYPAD_OUTPUT);
	DIO_SET_PinDirection(KEYPAD_PORT,KEYPAD_PIN_OUT2,KEYPAD_OUTPUT);
	DIO_SET_PinDirection(KEYPAD_PORT,KEYPAD_PIN_OUT3,KEYPAD_OUTPUT);
	//setting internal pull_up
	DIO_SET_PinPullUp(KEYPAD_PORT,KEYPAD_PIN_INP0);
	DIO_SET_PinPullUp(KEYPAD_PORT,KEYPAD_PIN_INP1);
	DIO_SET_PinPullUp(KEYPAD_PORT,KEYPAD_PIN_INP2);
	DIO_SET_PinPullUp(KEYPAD_PORT,KEYPAD_PIN_INP3);
	//setting all output to high
	DIO_SET_PinValue(KEYPAD_PORT,KEYPAD_PIN_OUT0,KEYPAD_HIGH);
	DIO_SET_PinValue(KEYPAD_PORT,KEYPAD_PIN_OUT1,KEYPAD_HIGH);
	DIO_SET_PinValue(KEYPAD_PORT,KEYPAD_PIN_OUT2,KEYPAD_HIGH);
	DIO_SET_PinValue(KEYPAD_PORT,KEYPAD_PIN_OUT3,KEYPAD_HIGH);
	
}
/*uint8_t KEYPAD_Read (void)
{
		
	uint8_t reading = 0;
	uint8_t btn=0;
	
	for (int i=0 ; i<4 ; i++)
	{
		DIO_SET_PinValue(KEYPAD_PORT,i+4,KEYPAD_LOW);
		for (int j=0;j<4;j++)
		{
			
			reading=DIO_Read_PinValue(KEYPAD_PORT,j);
			if (reading==0)
			{
				_delay_ms(10);
				reading=DIO_Read_PinValue(KEYPAD_PORT,j);
				if (reading==0)
				{
					btn=saved[i][j];
				}
			}
		}
		DIO_SET_PinValue(KEYPAD_PORT,i+4,KEYPAD_HIGH);
		
	}
	
	return btn;
	
	
}*/

uint8_t KEYPAD_Read (void)
{
	uint8_t val=0;
	uint8_t btn=0;
	uint8_t row_loc=0;
	uint8_t col_loc=0;
	
	for (col_loc =KEYPAD_COL_START;col_loc<=KEYPAD_COL_END;col_loc++)
	{
		DIO_SET_PinValue(KEYPAD_PORT,col_loc,KEYPAD_LOW);
		for (row_loc =KEYPAD_ROW_START;col_loc<=KEYPAD_ROW_END;row_loc++)
		{
			val=DIO_Read_PinValue(KEYPAD_PORT,row_loc);
			if (val==0)
			{
				btn=saved[row_loc -KEYPAD_ROW_START   ][col_loc -KEYPAD_COL_START   ];
				while (val==0)
				{
					val=DIO_Read_PinValue(KEYPAD_PORT,row_loc);
				}
				_delay_ms(10);
			}
		}
		DIO_SET_PinValue(KEYPAD_PORT,col_loc,KEYPAD_HIGH);
	}
	return btn;
}