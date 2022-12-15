/*
 * Ultrasonic_configuration.h
 *
 * Created: 12/11/2022 5:34:41 PM
 *  Author: Omar Wessam
 */ 


#ifndef ULTRASONIC_CONFIGURATION_H_
#define ULTRASONIC_CONFIGURATION_H_

#include "cpu_config.h"

#define PIN_ULTSONIC_trigger  DIO_PIN2
#define PORT_ULTSONIC_trigger DIO_PORTA

#define  Trigger_pin	PA0

#define OUT_ULTSONIC  DIO_OUTPUT
#define LOW_ULTSONIC  DIO_LOW
#define HIGH_ULTSONIC DIO_HIGH




#endif /* ULTRASONIC_CONFIGURATION_H_ */