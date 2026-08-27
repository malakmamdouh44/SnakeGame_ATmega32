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

#include "../HAL/BUZZER/BUZZER_INTERFACE.h"
#include "../HAL/BUZZER/BUZZER_CFG.h"

#include <stdio.h>
#include <util/delay.h>
#include <stdlib.h>

#define BUTTON_PORT PORTA
#define SEGMENT_PORT PORTB

#define MAX_SNAKE_LENGTH     50
#define FOOD_CHAR            '*'
#define SNAKE_HEAD_CHAR      '$'
#define SNAKE_BODY_CHAR      's'


// Macros for reading button states
#define READ_UP()     (MDIO_pinValueGetPinValue(BUTTON_PORT, MOVE_UP))
#define READ_DOWN()   (MDIO_pinValueGetPinValue(BUTTON_PORT, MOVE_DOWN))
#define READ_LEFT()   (MDIO_pinValueGetPinValue(BUTTON_PORT, MOVE_LEFT))
#define READ_RIGHT()  (MDIO_pinValueGetPinValue(BUTTON_PORT, MOVE_RIGHT))
#define READ_RESET()  (MDIO_pinValueGetPinValue(BUTTON_PORT, RESET))

#define IS_PRESSED(current, previous) ((current == DIO_LOW) && (previous == DIO_HIGH))

typedef enum
{
    MOVE_UP=0,
    MOVE_DOWN,
    MOVE_RIGHT,
    MOVE_LEFT,
    RESET
} BUTTON_PINS;

typedef struct {
    u8 x;
    u8 y;
} Position;

typedef enum {
    DIR_UP = 0,
    DIR_DOWN,
    DIR_LEFT,
    DIR_RIGHT,
    DIR_NONE
} Direction;

typedef struct {
    Position body[MAX_SNAKE_LENGTH];
    u8 length;
    Direction nextDir;
    Direction currentDir;
    u8 isDead;
    u16 score;
} Snake;

void gameInit(void);
void snakeInit(void);
void gameReset(void);
void generateFood(void);
void snakeUpdate(void);
void snakeDraw(void);
void buttonInput(void);
u8 gameLoop(void);
u8 checkCollision(Position newHead);
u8 checkFoodPosition(u8 x, u8 y);
void score(void);
void gameOverScreen(void);
void startScreen(void);

#endif /* APP_INCLUDE_LIB_FUNCTION_H_ */
