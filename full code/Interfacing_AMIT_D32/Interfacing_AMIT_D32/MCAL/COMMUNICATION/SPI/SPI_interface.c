/*
 * SPI_interface.c
 *
 * Created: 11/4/2022 5:24:22 PM
 *  Author: Omar Wessam
 */ 
#include "SPI_private.h"

void SPI_Master_Intialize(void)
{
	SET_BIT(PORTB,MOSI);
	CLR_BIT(PORTB,MISO);
	SET_BIT(PORTB,SS);
	SET_BIT(PORTB,SCK);
	
	SPCR=0X01010011;//55  
	
}
void SPI_Slave_Intialize(void)
{
	CLR_BIT(PORTB,MOSI);
	SET_BIT(PORTB,MISO);
	CLR_BIT(PORTB,SS);
	CLR_BIT(PORTB,SCK);
	
	SPCR=0X01000011;//43
	        
}
void SPI_Transmit(uint8_t data)
{
	SPDR =data;// data register
	while ( GET_BIT(SPSR,SPIF) !=1); //while the flag in the SPI interrupt flag is still not raised ,keep transmitting data
}
uint8_t SPI_Receive(void)
{
	while (GET_BIT(SPSR,SPIF)!=1);
	return SPDR;
}
uint8_t SPI_TxRx(uint8_t data)//transmit and receive data switching between master and slave
{
	SPDR =data;// data register
	while (GET_BIT(SPSR,SPIF)!=1);
	return SPDR;
}
uint8_t SPI_SlaveSelect (Slave slave_num)
{
	CLR_BIT(PORTB,slave_num);  //logic zero to the required slave s
}
