
/*
 * CTC_interface.c
 *
 * Created: 10/20/2022 3:55:23 PM
 *  Author: Omar Wessam
 */ 
#include "CTC_private.h"

uint8_t intial_value_CTC=0;
uint32_t CTC_NO =0;

void TIMER0_CTC_Intialize(TIMER0_CTC_Interrupt interupt)
{
	//choose CTC mode
	SET_BIT(TCCR0,WGM01);CLR_BIT(TCCR0,WGM00);
	//disconnect pins "normal port operation ,no toggle, no set ,no clear"
	CLR_BIT(TCCR0,COM01);CLR_BIT(TCCR0,COM00);
	
	//switch case on prescaler will use 1024 for now
	SET_BIT(TCCR0,CS02);
	CLR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS00);
	
	
	switch(interupt)
	{
		case no_interrupt_CTC:
		//disable interrupt
		CLR_BIT(TIMSK,OCIE0);//bit of output compare with initial pre-determined value is (OCIE0)
		break;
		
		case With_interrupt_CTC:
		//enable interrupt
		SET_BIT(TIMSK,OCIE0);
		//enable global interrupt
		SET_BIT(SREG,7);
		break;
	}
}
void TIMER0_CTC_Stop(void)
{
	//prescaler =zero
	CLR_BIT(TCCR0,CS02);
	CLR_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS00);
}
void TIMER0_CTC_delay_without_interrupt_empty_loop(void)
{
	int counter=0;
	while(counter != CTC_NO)
	{
		while ( GET_BIT (TIFR,OCF0)  == 0 );
		SET_BIT(TIFR,OCF0);
		counter++;
	}
}
void TIMER0_CTC_Delay(uint32_t delay,uint8_t OCR)
{
	uint8_t  Tick   = (CTC_prescalar / CTC_frequency);
	uint32_t count  =((delay * CTC_MICRO_SEC) / Tick);
	
	OCR0=OCR;//any number from 0-256
	CTC_NO =(count / OCR0) ;//(count / CTC_BITS) for OVF but for ctc we divide by predetermined OCR value
	intial_value_CTC = CTC_BITS - (count % CTC_BITS);
	
	TCNT0= intial_value_CTC;
	if (intial_value_CTC !=0)
	CTC_NO++;
	
	if (GET_BIT(TIMSK,OCIE0)==0)//if interrupt is off (pooling)
	{
		TIMER0_CTC_delay_without_interrupt_empty_loop();
	}
}