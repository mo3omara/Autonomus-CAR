/*
 * UART_interface.c
 *
 * Created: 11/15/2022 2:44:15 PM
 *  Author: Omar Wessam
 */ 

#include "UART_private.h"

void UART_intialize(UART_Mode mode,Parity_Mode parity,Stop_Bit bits ,CLk_Polarity polarity)
{
	UCSRB|= 0X00011000;
	UCSRC|= 0X10000110;
	
	SET_BIT(DDRD,PD1);//DDRD |=0X02;
	CLR_BIT(DDRD,PD0);
	
	uint16_t UBRR=(Frequency/(16*BaudRate))-1;
	//SET_BIT(UBRRH,URSEL);
	UBRRL=UBRR;
	UBRRH=UBRR>>8;
	
	
}
void UART_Transmit(Uint8_t data)
{
	UDR=data;
	while (GET_BIT(UCSRA,TXC)!=1);
}
Uint8_t UART_Receive(void)
{
	uint8_t data=0;
	while (GET_BIT(UCSRA,RXC)!=1);
	data=UDR;
	return data;
}