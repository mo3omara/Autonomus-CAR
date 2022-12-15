/*
 * UART_private.h
 *
 * Created: 11/15/2022 2:43:56 PM
 *  Author: Omar Wessam
 */ 


#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

#include "UART_configuration.h"

void UART_intialize(UART_Mode mode,Parity_Mode parity,Stop_Bit bits ,CLk_Polarity polarity);
void UART_Transmit(Uint8_t data);
Uint8_t UART_Receive();



#endif /* UART_PRIVATE_H_ */