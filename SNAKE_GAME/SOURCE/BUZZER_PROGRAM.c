/*
 * BUZZER_PROGRAM.c
 */

#include <util/delay.h>

#include "../INCLUDE/LIB/STD_TYPES.h"
#include "../INCLUDE/MCAL/DIO/DIO_INTERFACE.h"

#include "../INCLUDE/HAL/BUZZER/BUZZER_INTERFACE.h"
#include "../INCLUDE/HAL/BUZZER/BUZZER_CFG.h"


void HBuzzer_voidInit(void)
{
	MDIO_voidSetPinDirection(
            BUZZER_PORT,
            BUZZER_PIN,
            DIO_OUTPUT);

    HBuzzer_voidOff();
}


void HBuzzer_voidOn(void)
{
    MDIO_voidSetPinValue(
            BUZZER_PORT,
            BUZZER_PIN,
            DIO_HIGH);
}


void HBuzzer_voidOff(void)
{
    MDIO_voidSetPinValue(
            BUZZER_PORT,
            BUZZER_PIN,
            DIO_LOW);
}


void HBuzzer_voidBeep(void)
{
    HBuzzer_voidOn();

    _delay_ms(100);

    HBuzzer_voidOff();
}
