
/*
 * CTC_private.h
 *
 * Created: 10/20/2022 3:55:55 PM
 *  Author: Omar Wessam
 */ 

#include "CTC_configuration.h"

void TIMER0_CTC_Intialize(TIMER0_CTC_Interrupt interupt);
void TIMER0_CTC_Stop(void);
void TIMER0_CTC_delay_without_interrupt_empty_loop(void);
void TIMER0_CTC_Delay(uint32_t delay,uint8_t OCR);