
/*
 * ADC_private.h
 *
 * Created: 10/14/2022 3:06:45 PM
 *  Author: Omar Wessam
 */ 
#include "ADC_configuration.h"

void ADC_intialize(ADC_Vref  Vref,ADC_Prescaler prescaler);
uint16_t ADC_Read(ADC_Channel channel);
