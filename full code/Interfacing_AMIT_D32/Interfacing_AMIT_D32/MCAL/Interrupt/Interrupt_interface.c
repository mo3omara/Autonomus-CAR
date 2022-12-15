
/*
 * Interrupt_interface.c
 *
 * Created: 10/13/2022 3:00:55 PM
 *  Author: Omar Wessam
 */ 
#include "Interrupt_private.h"

void ExternalInterrupt_intialize(interrupts inter,interrupt_sense intsense)
{
	//disable Global interrupt
	CLR_BIT(SREG,7);
	
	switch (inter)
	{
		case EXT_INT0:
		switch (intsense)
		{
			
			case LOW:
			CLR_BIT(MCUCR,ISC00);
			CLR_BIT(MCUCR,ISC01);
			break;
			
			case HIGH:
			SET_BIT(MCUCR,ISC00);
			CLR_BIT(MCUCR,ISC01);
			break;
			
			case RISING:
			SET_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;
			
			case FALLING:
			CLR_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;
			
			
			
		}
		SET_BIT(GICR,INT0); 
		break;
		
		case EXT_INT1:
		switch (intsense)
		{
			case LOW:
			CLR_BIT(MCUCR,ISC10);
			CLR_BIT(MCUCR,ISC11);
			break;
			
			case HIGH:
			SET_BIT(MCUCR,ISC10);
			CLR_BIT(MCUCR,ISC11);
			break;
			
			case RISING:
			SET_BIT(MCUCR,ISC11);
			SET_BIT(MCUCR,ISC10);
			break;
			
			case FALLING:
			CLR_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
			break;
			
			
			
		}
		SET_BIT(GICR,INT1);
		break;
		
		case EXT_INT2:
		break;
		
	}
	
	//enable Global interrupt
	SET_BIT(SREG,7);
	
	
	
}