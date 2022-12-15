/*
 * FPWM_private.h
 *
 * Created: 10/27/2022 10:59:15 AM
 *  Author: Omar Wessam
 */ 


#ifndef FPWM_PRIVATE_H_
#define FPWM_PRIVATE_H_
#include "FPWM_configurations.h"
void F_PWM_Intialize(F_PWM_prescaler prescaler);
void F_PWM_Stop(void);
void F_PWM_SET_DutyCycle(uint8_t duty,F_PWM_InveringMode mode);


#endif /* FPWM_PRIVATE_H_ */