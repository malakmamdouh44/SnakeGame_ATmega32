/*
 * FUNCTION.h
 *
 *  Created on: Aug 24, 2026
 *      Author: Target
 */

#ifndef APP_INCLUDE_LIB_FUNCTION_H_
#define APP_INCLUDE_LIB_FUNCTION_H_

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "../MCAL/DIO/DIO_INTERFACE.h"
#include "../MCAL/DIO/DIO_PRIVATE.h"
#include "../MCAL/DIO/DIO_CFG.h"


#include "../HAL/LCD_LM044L/LCD_LM044L_INTERFACE.h"
#include "../HAL/LCD_LM044L/LCD_LM044L_PRIVATE.h"
#include "../HAL/LCD_LM044L/LCD_LM044L_CFG.h"

#include <stdio.h>
#include <util/delay.h>

#define BUTTON_PORT PORTA
#define SEGMENT_PORT PORTB

typedef enum
{
	MOVE_UP=0,
	MOVE_DOWN,
	MOVE_RIGHT,
	MOVE_LEFT,
	RESET
}BUTTON_PINS;

void gameInit(void);
void startScreen(void);

#endif /* APP_INCLUDE_LIB_FUNCTION_H_ */
