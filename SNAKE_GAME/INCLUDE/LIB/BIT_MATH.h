/*
 * BIT_MATH.h
 *
 *  Created on: 26Aug.,2026
 *      Author: malak
 */

#ifndef INCLUDE_LIB_BIT_MATH_H_
#define INCLUDE_LIB_BIT_MATH_H_

#define SET_BIT(reg,bitNum)  (reg |=(1<<bitNum))
#define CLEAR_BIT(reg,bitNum)  (reg &=~(1<<bitNum))
#define TOGGLE_BIT(reg,bitNum)  (reg ^=(1<<bitNum))
#define GET_BIT(reg,bitNum)   (0x01 & (reg>>bitNum))

#define SET_BYTE(reg,value)  reg = value

#define CONC_BIT(b7,b6,b5,b4,b3,b2,b1,b0) Conc_help(b7,b6,b5,b4,b3,b2,b1,b0)
#define Conc_help(b7,b6,b5,b4,b3,b2,b1,b0) 0b##b7##b6##b5##b4##b3##b2##b1##b0


#endif /* INCLUDE_LIB_BIT_MATH_H_ */
