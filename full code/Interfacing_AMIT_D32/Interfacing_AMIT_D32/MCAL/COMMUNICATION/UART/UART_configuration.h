/*
 * UART_configuration.h
 *
 * Created: 11/15/2022 2:43:31 PM
 *  Author: Omar Wessam
 */ 


#ifndef UART_CONFIGURATION_H_
#define UART_CONFIGURATION_H_

#include "cpu_config.h"

#define BaudRate 96//9600 , 38400  , 115200
#define Frequency 160000 
typedef enum
{
	disabled=0,
	EVEN=1,
	ODD=2
}Parity_Mode;

typedef enum
{
	ONE_BIT=0,
	TWO_BIT=1
	
}Stop_Bit;

typedef enum
{
	BIT5=0,
	BIT6=1,
	BIT7=2,
	BIT8=3,
	BIT9=4
}DATA_BITs;

typedef enum
{
	TX_RISING=0,//RX_FALLING
	RX_RISING=1 //TX_FALLING
}CLk_Polarity;

typedef enum
{
	synchrounous=0,
	Asynchrounous=1
}UART_Mode;

//will not use this enum now to save time
//instead we will directly choose (disabled parity,8_bits,TX_RISING,Asynchrounous)

#endif /* UART_CONFIGURATION_H_ */