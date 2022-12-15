/*
 * LCD_interface.c
 *
 * Created: 10/6/2022 3:51:52 PM
 *  Author: Omar Wessam
 */ 
#include "LCD_private.h"


void LCD_intialize(void)
{
	//control pins
	DIO_SET_PinDirection(LCD_cntrl_PORT,LCD_EN,LCD_OUT);
	DIO_SET_PinDirection(LCD_cntrl_PORT,LCD_RW,LCD_OUT);
	DIO_SET_PinDirection(LCD_cntrl_PORT,LCD_RS,LCD_OUT);
	//data pins
	DIO_SET_PinDirection(LCD_data_PORT,LCD_D0,LCD_OUT);
	DIO_SET_PinDirection(LCD_data_PORT,LCD_D1,LCD_OUT);
	DIO_SET_PinDirection(LCD_data_PORT,LCD_D2,LCD_OUT);
	DIO_SET_PinDirection(LCD_data_PORT,LCD_D3,LCD_OUT);
	//initialization command from the data sheet 
	LCD_write_command(0X33);
	LCD_write_command(0X32);
	LCD_write_command(0X28);
	
    LCD_write_command(0X01);//clear display
	LCD_write_command(0X02);//clear display
	LCD_write_command(0X06);//shift cursor to the right
	LCD_write_command(0X0C);//display on ,cursor off
	
	
	

}
void LCD_write_command(uint8_t command)
{
	//select the COMMAND register
	DIO_SET_PinValue(LCD_cntrl_PORT,LCD_RS,LCD_LOW);
	//select write on screen
	DIO_SET_PinValue(LCD_cntrl_PORT,LCD_RW,LCD_LOW);
	//insure enable is low"default is low ,just insuring"
	DIO_SET_PinValue(LCD_cntrl_PORT,LCD_EN,LCD_LOW);
	//set the high nibble
	PORTA=(command & 0XF0);
	DIO_SET_PinValue(LCD_cntrl_PORT,LCD_EN,LCD_HIGH);
	_delay_ms(1);
	DIO_SET_PinValue(LCD_cntrl_PORT,LCD_EN,LCD_LOW);
	
	//set the LOW nibble 
	PORTA=(command & 0X0F)<<4;
	DIO_SET_PinValue(LCD_cntrl_PORT,LCD_EN,LCD_HIGH);
	_delay_ms(1);
	DIO_SET_PinValue(LCD_cntrl_PORT,LCD_EN,LCD_LOW);
	_delay_ms(1);
}
void LCD_write_character(uint8_t character)
{
	//select the DATA register
	DIO_SET_PinValue(LCD_cntrl_PORT,LCD_RS,LCD_HIGH);
	//select write on screen
	DIO_SET_PinValue(LCD_cntrl_PORT,LCD_RW,LCD_LOW);
	//insure enable is low"default is low ,just insuring"
	DIO_SET_PinValue(LCD_cntrl_PORT,LCD_EN,LCD_LOW);
	//set the high nibble
	PORTA=(character & 0XF0);
	DIO_SET_PinValue(LCD_cntrl_PORT,LCD_EN,LCD_HIGH);
	_delay_ms(1);
	DIO_SET_PinValue(LCD_cntrl_PORT,LCD_EN,LCD_LOW);
	
	//set the LOW nibble
	PORTA=((character & 0X0F)<<4);
	DIO_SET_PinValue(LCD_cntrl_PORT,LCD_EN,LCD_HIGH);
	_delay_ms(1);
	DIO_SET_PinValue(LCD_cntrl_PORT,LCD_EN,LCD_LOW);
	_delay_ms(5);
}
void LCD_write_string(uint8_t *str)
{
	for (int i=0;str[i]!='\0';i++)
	{
		LCD_write_character(str[i]);
		_delay_ms(1);
	}
}
void LCD_write_number(uint32_t number)
{
	Uint8_t num[16];
	ltoa(number,(uint8_t*)num,10);
	LCD_write_string(num);
}

void LCD_clear()
{
	LCD_write_command(0X01);
	_delay_ms(2);
	//LCD_write_command(0X80);
}

void LCD_cursor_column(Uint8_t position)
{
	for (int i=0;i<position;i++)
	{
		LCD_write_command(0X14);
	}
}

void LCD_MovingText(uint8_t *str)
{
	LCD_clear();
	for (int i=0;i<16;i++)
	{
		LCD_write_string(str);
		
		if (strlen(str)>(16-i))
		{
			uint8_t *str2 = &str[16-i];
			LCD_write_command(0X80);
			LCD_write_string(str2);
		}
	
		 _delay_ms(500);
		LCD_clear();
		LCD_cursor_column(i+1);
	}
	
}