/*
 * DIO_private.h
 *
 * Created: 10/2/2022 11:06:26 PM
 *  Author: Omar Wessam
 */ 


#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

#include "cpu_config.h"
#include "DIO_configuration.h"

void DIO_SET_PinDirection(DIO_PORT port,DIO_PIN pin,DIO_State state);
void DIO_SET_PinValue(DIO_PORT port,DIO_PIN pin,DIO_Status status);
void DIO_TGL_PinValue(DIO_PORT port,DIO_PIN pin);
Uint8_t DIO_Read_PinValue(DIO_PORT port,DIO_PIN pin);
void DIO_SET_PinPullUp(DIO_PORT port,DIO_PIN pin);





#endif /* DIO_PRIVATE_H_ */