/*
 * BIT_MATH.h
 *
 * Created: 9/29/2022 10:53:06 PM
 *  Author: Omar Wessam
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_


//bit Math
#define SET_BIT(REG,BIT) REG|=(1<<BIT)
#define CLR_BIT(REG,BIT) REG&=~(1<<BIT)
#define TGL_BIT(REG,BIT) REG^=(1<<BIT)
#define GET_BIT(REG,BIT) ((REG>>BIT)&1)


#endif /* BIT_MATH_H_ */