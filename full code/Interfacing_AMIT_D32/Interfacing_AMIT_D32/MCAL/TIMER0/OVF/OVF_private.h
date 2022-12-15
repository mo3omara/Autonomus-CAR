
/*
 * OVF_private.h
 *
 * Created: 10/20/2022 3:54:44 PM
 *  Author: Omar Wessam
 */ 
#include "OVF_configuration.h"

/*void TIMER0_OVF_NoInterrupt_Intialize(void);
void TIMER0_OVF_NoInterrupt_start(void);
void TIMER0_OVF_NoInterrupt_Stop(void);
void TIMER0_OVF_NoInterrupt_SetDelay(uint32_t delay);

void TIMER0_OVF_Interrupt_Intialize(void);
void TIMER0_OVF_Interrupt_start(void);
void TIMER0_OVF_Interrupt_Stop(void);
void TIMER0_OVF_Interrupt_SetDelay(uint32_t delay);*/


void TIMER0_OVF_Intialize(TIMER0_OVF_Interrupt interrupt);
void TIMER0_OVF_Stop(void);
void TIMER0_OVF_delay_without_interrupt_empty_loop(void);
void TIMER0_OVF_Delay(uint32_t delay);
