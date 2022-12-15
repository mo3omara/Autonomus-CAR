
/*
 * KEYPAD_configuration.h
 *
 * Created: 10/11/2022 4:21:53 PM
 *  Author: Omar Wessam
 */ 


#include "cpu_config.h"

#define KEYPAD_PORT PORTD

#define KEYPAD_PIN_INP0 DIO_PIN0
#define KEYPAD_PIN_INP1 DIO_PIN1
#define KEYPAD_PIN_INP2 DIO_PIN2
#define KEYPAD_PIN_INP3 DIO_PIN3

#define KEYPAD_PIN_OUT0 DIO_PIN4
#define KEYPAD_PIN_OUT1 DIO_PIN5
#define KEYPAD_PIN_OUT2 DIO_PIN6
#define KEYPAD_PIN_OUT3 DIO_PIN7

#define KEYPAD_INPUT  DIO_INPUT
#define KEYPAD_OUTPUT DIO_OUTPUT

#define KEYPAD_LOW  DIO_LOW
#define KEYPAD_HIGH DIO_HIGH

#define KEYPAD_COL_START 0
#define KEYPAD_COL_END   3

#define KEYPAD_ROW_START 4
#define KEYPAD_ROW_END   7