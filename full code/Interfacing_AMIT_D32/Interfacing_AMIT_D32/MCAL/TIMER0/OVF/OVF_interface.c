
/*
 * OVF_interface.c
 *
 * Created: 10/20/2022 3:54:14 PM
 *  Author: Omar Wessam
 */ 
#include "OVF_private.h"

/*void TIMER0_OVF_NoInterrupt_Intialize(void)
{
	//choose OVF mode
	CLR_BIT(TCCR0,WGM01);CLR_BIT(TCCR0,WGM00);
	//disconnect pins "normal port operation ,no toggle, no set ,no clear"
	CLR_BIT(TCCR0,COM01);CLR_BIT(TCCR0,COM00);
	//disable interrupt 
	CLR_BIT(TIMSK,TOIE0);
}
void TIMER0_OVF_NoInterrupt_start(void)
{
	//we should switch case on prescaler for ease now we 
	//will choose 1024 prescaler directly
	SET_BIT(TCCR0,CS02);
	CLR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS00);
}
void TIMER0_OVF_NoInterrupt_Stop(void)
{
	//prescaler =zero
	CLR_BIT(TCCR0,CS02);
	CLR_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS00);
}
void TIMER0_OVF_NoInterrupt_SetDelay(uint32_t delay)
{
	uint32_t counter= 0;
	uint8_t  Tick   = (OVF_prescalar / OVF_frequency);// time taken by each CPU pulse
	uint32_t count  =((delay * OVF_MICRO_SEC) / Tick);// number of pulses "ticks" to complete the delay time needed
	uint32_t OVF_NO = (count / OVF_BITS); //we keep doing (tick-tick-tick-tick....for 256 times"from 0 to 255" which is 1 over flow 
	                                    //no. of over flows is the number of times we need to clear the byte and start tick tick... again
										// 1 over flow = 256 ticks , 1 tick time depend on the prescalar.
	uint8_t intial_value = OVF_BITS - (count % OVF_BITS);
	TCNT0= intial_value;
	if (intial_value !=0) //we add 1 to OVF if there is a reminder  
		OVF_NO++;
		
	while(counter != OVF_NO)
	{
		while ( GET_BIT (TIFR,TOV0)  == 0 );
		SET_BIT(TIFR,TOV0);
		counter++;	 
		
	}
}

uint8_t intial_value_interrupt=0;
uint32_t OVF_NO_interrupt =0;

void TIMER0_OVF_Interrupt_Intialize(void)
{
	//choose OVF mode
	CLR_BIT(TCCR0,WGM01);CLR_BIT(TCCR0,WGM00);
	//disconnect pins "normal port operation ,no toggle, no set ,no clear"
	CLR_BIT(TCCR0,COM01);CLR_BIT(TCCR0,COM00);
	//enable interrupt
	SET_BIT(TIMSK,TOIE0);
	//enable global interrupt
	SET_BIT(SREG,7);
}
void TIMER0_OVF_Interrupt_start(void)
{
	//we should switch case on prescaler what for ease now we
	//will choose 1024 prescaler directly
	SET_BIT(TCCR0,CS02);
	CLR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS00);
}
void TIMER0_OVF_Interrupt_Stop(void)
{
	//prescaler =zero
	CLR_BIT(TCCR0,CS02);
	CLR_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS00);
}
void TIMER0_OVF_Interrupt_SetDelay(uint32_t delay)
{
	uint8_t  Tick   = OVF_prescalar /OVF_frequency;// time taken by each CPU pulse
	uint32_t count  =(delay * OVF_MICRO_SEC) / Tick;// number of pulses "ticks" to complete the delay time needed
    OVF_NO_interrupt = count / OVF_BITS;            we keep doing (tick-tick-tick-tick....for 256 times"from 0 to 255" which is 1 over flow
	                                   	            no. of over flows is the number of times we need to clear the byte and start tick tick... again
		                                            1 over flow = 256 ticks , 1 tick time depend on the prescalar.
																		
	 intial_value_interrupt =OVF_BITS - (count % OVF_BITS);
	 if (intial_value_interrupt !=0) //we add 1 to OVF if there is a reminder
	 OVF_NO_interrupt++;
	 
	 TCNT0= intial_value_interrupt;
										
}
*/


uint8_t intial_value=0;
uint32_t OVF_NO =0;

void TIMER0_OVF_Intialize(TIMER0_OVF_Interrupt interrupt)
{
	//choose OVF mode
	CLR_BIT(TCCR0,WGM01);CLR_BIT(TCCR0,WGM00);
	//disconnect pins "normal port operation ,no toggle, no set ,no clear"
	CLR_BIT(TCCR0,COM01);CLR_BIT(TCCR0,COM00);
	
	//switch case on prescaler will use 1024 for now
	SET_BIT(TCCR0,CS02);
	CLR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS00);
	
	
	switch(interrupt)
	{
		case no_interrupt:
		//disable interrupt
		CLR_BIT(TIMSK,TOIE0);
		break;
		
		case With_interrupt:
		//enable interrupt
		SET_BIT(TIMSK,TOIE0);
		//enable global interrupt
		SET_BIT(SREG,7);  //sei();  //cli();
		break;
	}
}
void TIMER0_OVF_Stop(void)
{
	//prescaler =zero
	CLR_BIT(TCCR0,CS02);
	CLR_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS00);
}
void TIMER0_OVF_delay_without_interrupt_empty_loop(void)
{
	int counter=0;
	while(counter != OVF_NO)
	{
		while ( GET_BIT (TIFR,TOV0)  == 0 );
		SET_BIT(TIFR,TOV0);
		counter++;
	}
}
void TIMER0_OVF_Delay(uint32_t delay)
{
	uint8_t  Tick   = (OVF_prescalar / OVF_frequency );
	uint32_t count  = ((delay * OVF_MICRO_SEC) / Tick);
	
	OVF_NO = (count / OVF_BITS); 
	intial_value = OVF_BITS - (count % OVF_BITS);
	
	TCNT0= intial_value;
	if (intial_value !=0)
	OVF_NO++;
	
	if (GET_BIT(TIMSK,TOIE0)==0)//if interrupt is off (pooling)
	{
		TIMER0_OVF_delay_without_interrupt_empty_loop();
	}
	
}




