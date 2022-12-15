/*
 * SPI_private.h
 *
 * Created: 11/4/2022 5:24:03 PM
 *  Author: Omar Wessam
 */ 


#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#include "SPI_configuration.h"

void SPI_Master_Intialize(void);
void SPI_Slave_Intialize(void);
void SPI_Transmit(uint8_t data);
uint8_t SPI_Receive(void);
uint8_t SPI_TranCeive(uint8_t data);
uint8_t SPI_SlaveSelect (uint8_t slave);


#endif /* SPI_PRIVATE_H_ */