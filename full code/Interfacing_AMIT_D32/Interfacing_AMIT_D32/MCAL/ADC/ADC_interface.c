
/*
 * ADC_interface.c
 *
 * Created: 10/14/2022 3:06:59 PM
 *  Author: Omar Wessam
 */ 
#include "ADC_private.h"

void ADC_intialize(ADC_Vref  Vref,ADC_Prescaler prescaler)
{
	switch (Vref)
	{
		case AREF:
		CLR_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
		break;	
		
		case AVCC:
		SET_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
		break;
		
		case INTERNAL:
		SET_BIT(ADMUX,REFS0);
		SET_BIT(ADMUX,REFS1);
		break;
	}
	
	switch (prescaler)
	{
		case ADC_pre1:
		CLR_BIT(ADCSRA,ADPS0);
		CLR_BIT(ADCSRA,ADPS1);
		CLR_BIT(ADCSRA,ADPS2);
		break;
		
		case ADC_pre2:
		SET_BIT(ADCSRA,ADPS0);
		CLR_BIT(ADCSRA,ADPS1);
		CLR_BIT(ADCSRA,ADPS2);
		break;
		
		case ADC_pre4:
		CLR_BIT(ADCSRA,ADPS0);
		SET_BIT(ADCSRA,ADPS1);
		CLR_BIT(ADCSRA,ADPS2);
		break;
		
		case ADC_pre8:
		SET_BIT(ADCSRA,ADPS0);
		SET_BIT(ADCSRA,ADPS1);
		CLR_BIT(ADCSRA,ADPS2);
		break;
		
		case ADC_pre16:
		CLR_BIT(ADCSRA,ADPS0);
		CLR_BIT(ADCSRA,ADPS1);
		SET_BIT(ADCSRA,ADPS2);
		break;
		
		case ADC_pre32:
		SET_BIT(ADCSRA,ADPS0);
		CLR_BIT(ADCSRA,ADPS1);
		SET_BIT(ADCSRA,ADPS2);
		break;
		
		case ADC_pre64:
		CLR_BIT(ADCSRA,ADPS0);
		SET_BIT(ADCSRA,ADPS1);
		SET_BIT(ADCSRA,ADPS2);
		break;
		
		case ADC_pre128:
		SET_BIT(ADCSRA,ADPS0);
		SET_BIT(ADCSRA,ADPS1);
		SET_BIT(ADCSRA,ADPS2);
		break;
	}
	CLR_BIT(ADMUX,ADLAR);// right adjust
	SET_BIT(ADCSRA,ADEN); //enable adc
	SET_BIT(ADCSRA,ADATE); //auto trigger on
	CLR_BIT(ADCSRA,ADIE); //disable interrupt
	
}


uint16_t ADC_Read(ADC_Channel channel)
{
	uint16_t read=0;
	
	switch (channel)
	{
		case ADC_ch0:
		ADMUX|=0;
		break;
		
		case ADC_ch1:
		ADMUX|=1;
		break;
		
		case ADC_ch2:
		ADMUX|=2;
		break;
		
		case ADC_ch3:
		ADMUX|=3;
		break;
		
		case ADC_ch4:
		ADMUX|=4;
		break;
		
		case ADC_ch5:
		ADMUX|=5;
		break;
		
		case ADC_ch6:
		ADMUX|=6;
		break;
		
		case ADC_ch7:
		ADMUX|=7;
		break;
		
	}
	SET_BIT(ADCSRA,ADSC);
	while (GET_BIT(ADCSRA,ADIF)!= 1);
	
	read=ADC_data;
	return read;
}