
/*
 * ADC_configuration.h
 *
 * Created: 10/14/2022 3:06:28 PM
 *  Author: Omar Wessam
 */ 
#include "cpu_config.h"
#include "ADC_adresses.h"

typedef enum
{
	AREF=0,
	AVCC=1,
	INTERNAL=2
}ADC_Vref;



typedef enum
{
	ADC_ch0=0,
	ADC_ch1=1,
	ADC_ch2=2,
	ADC_ch3=3,
	ADC_ch4=4,
	ADC_ch5=5,
	ADC_ch6=6,
	ADC_ch7=7
	
}ADC_Channel;

typedef enum
{
	
	ADC_pre1=0,
	ADC_pre2=1,
	ADC_pre4=2,
	ADC_pre8=3,
	ADC_pre16=4,
	ADC_pre32=5,
	ADC_pre64=6,
	ADC_pre128=7
	
}ADC_Prescaler;