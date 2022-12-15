/*
 * TIMER1_interface.c
 *
 * Created: 11/16/2022 1:42:26 AM
 *  Author: Omar Wessam
 */ 
#include "TIMER1_private.h"

uint8_t intial_value1=0;
uint32_t OVF1_NO =0;
extern int TimerOverflow;
void TIMER1_OVF_Intialize(TIMER1_OVF_Interrupt interrupt)
{
	//choose OVF mode
	//CLR_BIT(TCCR0,WGM01);CLR_BIT(TCCR0,WGM00);
	//disconnect pins "normal port operation ,no toggle, no set ,no clear"
	//CLR_BIT(TCCR0,COM01);CLR_BIT(TCCR0,COM00);
	
	//switch case on prescaler no prescalar for now"
	CLR_BIT(TCCR1B,CS12);
	CLR_BIT(TCCR1B,CS11);
	SET_BIT(TCCR1B,CS10);
	
	
	switch(interrupt)
	{
		case no_interrupt1:
		//disable interrupt
		CLR_BIT(TIMSK,TOIE1);
		break;
		
		case With_interrupt1:
		//enable interrupt
		SET_BIT(TIMSK,TOIE1);
		//enable global interrupt
		SET_BIT(SREG,7);  //sei();  //cli();
		TIFR = 1<<ICF1;//clear ICF flag "input capture flag
		TIFR = 1<<TOV1;//clear timer ovf flag
		break;
	}
	
}

void TIMER1_EDGE_SELECT(TIMER1_OVF_EDGE edge)
{
	
	switch (edge)
	{
		case falling:
		CLR_BIT(TCCR1B,ICES1);
		break;
		case rising :
		SET_BIT(TCCR1B,ICES1);
		break;
	}
}

void TIMER1_OVF_Stop(void)
{
	//prescaler =zero
	CLR_BIT(TCCR0,CS02);
	CLR_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS00);
}
void TIMER1_OVF_delay_without_interrupt_empty_loop(void)
{
	int counter=0;
	while(counter != OVF1_NO)
	{
		while ( GET_BIT (TIFR,TOV0)  == 0 );
		SET_BIT(TIFR,TOV0);
		counter++;
	}
}
void TIMER1_OVF_Delay(uint32_t delay)
{
	uint8_t  Tick   = (OVF1_prescalar / OVF1_frequency );
	uint32_t count  = ((delay * OVF1_MICRO_SEC) / Tick);
	
	OVF1_NO = (count / OVF1_BITS);
	intial_value1 = OVF1_BITS - (count % OVF1_BITS);
	
	TCNT1= intial_value1;
	if (intial_value1 !=0)
	OVF1_NO++;
	
	if (GET_BIT(TIMSK,TOIE0)==0)//if interrupt is off (pooling)
	{
		TIMER1_OVF_delay_without_interrupt_empty_loop();
	}
	
}
double TIMER1_OVF_DISTANCE_BETWEEN_RISE_FALL(void)
{
	
	TIFR = 1<<ICF1;
	TIFR = 1<<TOV1;
	TIMER1_EDGE_SELECT(rising);
	while ((TIFR & (1 << ICF1)) == 0);/* Wait for rising edge */
	TCNT1 = 0;	/* Clear Timer counter */
	TIMER1_EDGE_SELECT(falling);
	TIFR = 1<<ICF1;	/* Clear Input Capture flag */
	TIFR = 1<<TOV1;	/* Clear Timer Overflow flag */
	TimerOverflow = 0;/* Clear Timer overflow count */
	while ((TIFR & (1 << ICF1)) == 0);/* Wait for falling edge */
	long count= ICR1 + (65535 * TimerOverflow);
	double distance= (double)count / 932.9446  ;
	
	return distance;
}