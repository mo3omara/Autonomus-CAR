/*
 * DC_private.h
 *
 * Created: 10/27/2022 3:22:48 PM
 *  Author: Omar Wessam
 */ 


#ifndef DC_PRIVATE_H_
#define DC_PRIVATE_H_
#include "DC_configuration.h"

void Motor_intialization(void);
void Motor_ON (Motor_No number,Motor_Direction direction);
void Motor_OFF(Motor_No number);


#endif /* DC_PRIVATE_H_ */