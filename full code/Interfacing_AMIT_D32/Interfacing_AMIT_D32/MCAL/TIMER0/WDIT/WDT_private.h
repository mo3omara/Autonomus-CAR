/*
 * WDT_private.h
 *
 * Created: 10/21/2022 3:47:23 PM
 *  Author: Omar Wessam
 */ 


#ifndef WDT_PRIVATE_H_
#define WDT_PRIVATE_H_

#include "WDT_configuration.h"

void WDT_intialize(WDT_prescaler prescalar);
void WDT_refresh(void);

#endif /* WDT_PRIVATE_H_ */