/*
 * 7_SEGMENT_PROGRAM.c
 *
 *  Created on: 26Aug.,2026
 *      Author: malak
 */

#include "../INCLUDE/LIB/BIT_MATH.h"
#include "../INCLUDE/LIB/STD_TYPES.h"
#include "../INCLUDE/MCAL/DIO/DIO_INTERFACE.h"
#include "../INCLUDE/HAL/7_SEGMENT/7_SEGMENT_INTERFACE.h"
#include "../INCLUDE/HAL/7_SEGMENT/7_SEGMENT_PRIVATE.h"
#include "../INCLUDE/HAL/7_SEGMENT/7_SEGMENT_CFG.h"

void SevenSegment_Init(void) {

    MDIO_voidSetPortDirection(SEVEN_SEGMENT_PORT, 0xFF);
}

void SevenSegment_DisplayNumber(u8 NumberOfScore) {
    if (NumberOfScore <= 99) {
        u8 Units = NumberOfScore % 10;
        u8 Tens  = NumberOfScore / 10;

        u8 Score_Count = (Tens << 4) | Units;

        MDIO_voidSetPortValue(SEVEN_SEGMENT_PORT, Score_Count);
    }
}

