/*
 * LCD_private.h
 *
 * Created: 10/6/2022 3:52:23 PM
 *  Author: Omar Wessam
 */ 


#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_

#include "LCD_configuration.h"
#include "string.h"

void LCD_intialize(void);
void LCD_write_command(uint8_t command);
void LCD_write_character(uint8_t character);
void LCD_write_string(uint8_t *str);
void LCD_write_number(Uint32_t number);
void LCD_clear();

void LCD_cursor_column(Uint8_t position);
void LCD_MovingText(uint8_t *str);


#endif /* LCD_PRIVATE_H_ */