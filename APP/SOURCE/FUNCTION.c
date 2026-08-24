/*
 * FUNCTION.c
 *
 *  Created on: Aug 24, 2026
 *      Author: Target
 */

#include "../INCLUDE/LIB/FUNCTION.h"

void gameInit()
{
    HLCD_voidInit();

    MDIO_voidSetPinValue(BUTTON_PORT,MOVE_UP,DIO_HIGH);
    MDIO_voidSetPinValue(BUTTON_PORT,MOVE_DOWN,DIO_HIGH);
    MDIO_voidSetPinValue(BUTTON_PORT,MOVE_RIGHT,DIO_HIGH);
    MDIO_voidSetPinValue(BUTTON_PORT,MOVE_LEFT,DIO_HIGH);
    MDIO_voidSetPinValue(BUTTON_PORT,RESET,DIO_HIGH);


    MDIO_voidSetPinDirection(BUTTON_PORT,MOVE_UP,DIO_INPUT);
    MDIO_voidSetPinDirection(BUTTON_PORT,MOVE_DOWN,DIO_INPUT);
    MDIO_voidSetPinDirection(BUTTON_PORT,MOVE_RIGHT,DIO_INPUT);
    MDIO_voidSetPinDirection(BUTTON_PORT,MOVE_LEFT,DIO_INPUT);
    MDIO_voidSetPinDirection(BUTTON_PORT,RESET,DIO_INPUT);


    MDIO_voidSetPortValue(SEGMENT_PORT,DIO_LOW);
    MDIO_voidSetPortDirection(SEGMENT_PORT,DIO_OUTPUT);

}

void startScreen()
{

    HLCD_voidSendStringLine("+      +      +    +", ROW1);
    HLCD_voidSendStringLine("  +   SNAKE GAME  + ", ROW2);
    HLCD_voidSendStringLine("   +  START(UP)?   +", ROW3);
    HLCD_voidSendStringLine(" +    +    +    +   ", ROW4);

    while(MDIO_pinValueGetPinValue(BUTTON_PORT,MOVE_UP)==DIO_HIGH){};
    HLCD_voidClearDisplay();

}

