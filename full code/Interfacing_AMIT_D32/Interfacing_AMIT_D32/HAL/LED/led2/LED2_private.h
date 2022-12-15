/*
 * LED2_private.h
 *
 * Created: 9/30/2022 3:02:15 PM
 *  Author: Omar Wessam
 */ 


#ifndef LED2_PRIVATE_H_
#define LED2_PRIVATE_H_

#include "LED0_configuration.h"
#include "LED1_configuration.h"
#include "LED2_configuration.h"

void LED_intialize(int LED_NUM);
void LED_ON(int LED_NUM);
void LED_OFF(int LED_NUM);


void LED_TGL(int LED_NUM);

#endif /* LED2_PRIVATE_H_ */