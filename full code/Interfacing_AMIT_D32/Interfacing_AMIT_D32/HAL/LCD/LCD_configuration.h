/*
 * LCD_configuration.h
 *
 * Created: 10/6/2022 3:52:07 PM
 *  Author: Omar Wessam
 */ 


#ifndef LCD_CONFIGURATION_H_
#define LCD_CONFIGURATION_H_

#include "cpu_config.h"
//ports
#define LCD_cntrl_PORT DIO_PORTB
#define LCD_data_PORT DIO_PORTA
//data pins
#define LCD_D0 DIO_PIN4
#define LCD_D1 DIO_PIN5
#define LCD_D2 DIO_PIN6
#define LCD_D3 DIO_PIN7
//same data pins as we are using 4-bits system
#define LCD_D4 DIO_PIN4
#define LCD_D5 DIO_PIN5
#define LCD_D6 DIO_PIN6
#define LCD_D7 DIO_PIN7
//control pins
#define LCD_RS DIO_PIN1
#define LCD_RW DIO_PIN2
#define LCD_EN DIO_PIN3
//LCD conditions
#define LCD_OUT DIO_OUTPUT
#define LCD_LOW DIO_LOW
#define LCD_HIGH DIO_HIGH



#endif /* LCD_CONFIGURATION_H_ */