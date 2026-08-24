/*
 * LCD_LM044L_PRIVATE.h
 *
 *  Created on: Aug 23, 2026
 *      Author: Target
 */
#include "../../LIB/BIT_MATH.h"

#ifndef INCLUDE_HAL_LCD_LM044L_LCD_LM044L_PRIVATE_H_
#define INCLUDE_HAL_LCD_LM044L_LCD_LM044L_PRIVATE_H_


#define FUNCTION_SET 	    	CONC_BIT(0,0,1,LCD_DL,LCD_NO_OF_LINES,LCD_CHAR_FONT,0,0)
#define DISPLAY_ON_OFF_CONTROL 	CONC_BIT(0,0,0,0,1,DISPLAY_ON,CURSOR_DISPLAY,CURSOR_BLINK)
#define DISPLAY_CLEAR    		0x01
#define ENTRY_MODE_SET 			CONC_BIT(0,0,0,0,0,1,LCD_DATA_DIRECTION,LCD_SHIFT)

// LM044L 4x20 DDRAM addresses
// Line 1: 0x00 - 0x13 (20 characters)
// Line 2: 0x40 - 0x53 (20 characters)
// Line 3: 0x14 - 0x27 (20 characters)
// Line 4: 0x54 - 0x67 (20 characters)
#define LCD_ROW1_ADDRESS 0x80  // 0x00 + 0x80
#define LCD_ROW2_ADDRESS 0xC0  // 0x40 + 0x80
#define LCD_ROW3_ADDRESS 0x94  // 0x14 + 0x80
#define LCD_ROW4_ADDRESS 0xD4  // 0x54 + 0x80

// Number of lines and columns for LM044L
#define LCD_MAX_LINES 4
#define LCD_MAX_COLS 20

#endif /* INCLUDE_HAL_LCD_LM044L_LCD_LM044L_PRIVATE_H_ */
