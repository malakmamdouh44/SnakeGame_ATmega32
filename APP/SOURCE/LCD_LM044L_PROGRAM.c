/*
 * LCD_LM044L_PROGRAM.c
 *
 *  Created on: Aug 23, 2026
 *      Author: Target
 */



#include <util/delay.h>
#include "../INCLUDE/LIB/STD_TYPES.h"
#include "../INCLUDE/LIB/BIT_MATH.h"
#include "../INCLUDE/MCAL/DIO/DIO_INTERFACE.h"

#include "../INCLUDE/HAL/LCD_LM044L/LCD_LM044L_INTERFACE.h"
#include "../INCLUDE/HAL/LCD_LM044L/LCD_LM044L_PRIVATE.h"
#include "../INCLUDE/HAL/LCD_LM044L/LCD_LM044L_CFG.h"


void HLCD_voidInit(void)
{
    MDIO_voidSetPortDirection(LCD_DATA_PORT, 0xFF);
    MDIO_voidSetPortValue(LCD_DATA_PORT, 0x00);

    MDIO_voidSetPortDirection(LCD_CONTROL_PORT, 0xFF);
    MDIO_voidSetPortValue(LCD_CONTROL_PORT, 0x00);

    // Wait for more than 30ms
    _delay_ms(32);

    // Function Set Command
    HLCD_voidSendCommand(FUNCTION_SET);
    // Wait for more than 39 us
    _delay_ms(1);

    // Display on/off control
    HLCD_voidSendCommand(DISPLAY_ON_OFF_CONTROL);
    // Wait for more than 39 us
    _delay_ms(1);

    // Display Clear
    HLCD_voidSendCommand(DISPLAY_CLEAR);
    // Wait for more than 1.53 ms
    _delay_ms(2);

    // Entry Mode Set
    HLCD_voidSendCommand(ENTRY_MODE_SET);
}

void HLCD_voidSendCommand(u8 A_u8Command)
{
    // RS --> 0, RW --> 0
    MDIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_LOW);
    MDIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_LOW);

    // Set data port with the command
    MDIO_voidSetPortValue(LCD_DATA_PORT, A_u8Command);

    // Set pulse on E pin with 2ms delay
    MDIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_HIGH);
    _delay_ms(2);
    MDIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_LOW);
}

void HLCD_voidSendData(u8 A_u8Data)
{
    // RS --> 1, RW --> 0
    MDIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, DIO_HIGH);
    MDIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RW_PIN, DIO_LOW);

    // Set data port with the data
    MDIO_voidSetPortValue(LCD_DATA_PORT, A_u8Data);

    // Set pulse on E pin with 2ms delay
    MDIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_HIGH);
    _delay_ms(2);
    MDIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, DIO_LOW);
}

void HLCD_voidSendString(u8 *A_Pu8String)
{
    while(*A_Pu8String > 0)
    {
        HLCD_voidSendData(*A_Pu8String++);
    }
}

void HLCD_voidSendStringLine(u8 *A_Pu8String, LCD_ROWS row)
{
    // Go to the specified row, column 1
    HLCD_voidGoToPos(row, col1);

    u8 len = 0;
    u8 *ptr = A_Pu8String;

    // Count characters
    while(*ptr++ > 0) len++;

    // Send string (limit to 20 characters for LM044L)
    for(u8 i = 0; i < len && i < LCD_MAX_COLS; i++)
    {
        HLCD_voidSendData(A_Pu8String[i]);
    }
}

void HLCD_voidClearDisplay(void)
{
    // Display Clear
    HLCD_voidSendCommand(DISPLAY_CLEAR);
    // Wait for more than 1.53 ms
    _delay_ms(2);
}

void HLCD_voidGoToPos(LCD_ROWS A_LcdRowNo, LCD_COLS A_LcdColNo)
{
    // Convert column number to 0-based index
    u8 colIndex = A_LcdColNo - 1;

    switch(A_LcdRowNo)
    {
        case ROW1:
            HLCD_voidSendCommand(LCD_ROW1_ADDRESS + colIndex);
            break;
        case ROW2:
            HLCD_voidSendCommand(LCD_ROW2_ADDRESS + colIndex);
            break;
        case ROW3:
            HLCD_voidSendCommand(LCD_ROW3_ADDRESS + colIndex);
            break;
        case ROW4:
            HLCD_voidSendCommand(LCD_ROW4_ADDRESS + colIndex);
            break;
        default:
            break;
    }
    _delay_ms(1);
}

void HLCD_voidDisplayNumberUnsigned(u32 A_u32Number)
{
    u32 local_u32Number = 0;

    if(A_u32Number == 0)
    {
        HLCD_voidSendData('0');
        return;
    }

    // Convert number to string
    u8 buffer[12];
    u8 index = 0;

    while(A_u32Number > 0)
    {
        buffer[index++] = (A_u32Number % 10) + '0';
        A_u32Number /= 10;
    }

    // Display in reverse order
    while(index > 0)
    {
        HLCD_voidSendData(buffer[--index]);
    }
}

void HLCD_voidDisplayNumberSigned(s32 A_s32Number)
{
    if(A_s32Number < 0)
    {
        HLCD_voidSendData('-');
        A_s32Number = -A_s32Number;
    }
    HLCD_voidDisplayNumberUnsigned((u32)A_s32Number);
}

void HLCD_voidSendSpecialCharacter(u8 *A_pu8PatternArr, u8 A_u8PatternNumber, LCD_ROWS A_LcdRowNo, LCD_COLS A_LcdColNo)
{
    u8 local_u8CGRamAddress;

    // Calculate CGRAM Address = Pattern No. * 8
    local_u8CGRamAddress = A_u8PatternNumber * 8;

    // Data sheet says that bit 6 must be high
    SET_BIT(local_u8CGRamAddress, 6);

    // Send CGRAM Write Command
    HLCD_voidSendCommand(local_u8CGRamAddress);

    for(u8 i = 0; i < 8; i++)
    {
        HLCD_voidSendData(A_pu8PatternArr[i]);
    }

    // Send go to position Command to the DDRAM
    HLCD_voidGoToPos(A_LcdRowNo, A_LcdColNo);

    // Display pattern
    HLCD_voidSendData(A_u8PatternNumber);
}
