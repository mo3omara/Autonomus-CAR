/*
 * TIMER1_private.h
 *
 * Created: 11/16/2022 1:42:08 AM
 *  Author: Omar Wessam
 */ 


#ifndef TIMER1_PRIVATE_H_
#define TIMER1_PRIVATE_H_
#include "TIMER1_comfiguration.h"

void TIMER1_OVF_Intialize(TIMER1_OVF_Interrupt interrupt);
void TIMER1_OVF_Stop(void);
void TIMER1_OVF_delay_without_interrupt_empty_loop(void);
void TIMER1_OVF_Delay(uint32_t delay);
void TIMER1_EDGE_SELECT(TIMER1_OVF_EDGE edge);
double TIMER1_OVF_DISTANCE_BETWEEN_RISE_FALL(void);

#endif /* TIMER1_PRIVATE_H_ */