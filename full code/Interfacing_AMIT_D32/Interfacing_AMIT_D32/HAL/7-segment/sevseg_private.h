/*
 * _7_segment_private.h
 *
 * Created: 10/3/2022 11:26:00 PM
 *  Author: Omar Wessam
 */ 


#ifndef SEVSEG_PRIVATE_H_
#define SEVSEG_PRIVATE_H_

#include "SEVSEG_configuration.h"
void SEVSEG_intialize(void);

void SEVSEG_Enable1(void);
void SEVSEG_Enable2(void);

void SEVSEG_Disable1(void);
void SEVSEG_Disable2(void);

void SEVSEG_DIP_Enable(void);
void SEVSEG_DIP_Disable(void);

void SEVSEG_tenth(uint8_t number);

void SEVSEG_unit(uint8_t number);

void SEVSEG_Display(uint8_t number);

void SEVSEG_Display_99(void);



#endif /* 7-SEGMENT_PRIVATE_H_ */