/*
 * SPI_configuration.h
 *
 * Created: 11/4/2022 5:23:44 PM
 *  Author: Omar Wessam
 */ 


#ifndef SPI_CONFIGURATION_H_
#define SPI_CONFIGURATION_H_

#include "cpu_config.h"
#define SPI_PORT DIO_PORTB

#define SS   DIO_PIN4
#define MOSI DIO_PIN5
#define MISO DIO_PIN6
#define SCK  DIO_PIN7

typedef enum
{
	slave0= SS      ,
	slave1= DIO_PIN3,
	slave2= DIO_PIN2,
	slave3= DIO_PIN1,
	slave4= DIO_PIN0
}Slave;




#endif /* SPI_CONFIGURATION_H_ */