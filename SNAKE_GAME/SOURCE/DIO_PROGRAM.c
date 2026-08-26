/*
 * DIO_PROGRAM.c
 *
 *  Created on: 26Aug.,2026
 *      Author: malak
 */

#include "../INCLUDE/LIB/BIT_MATH.h"
#include "../INCLUDE/LIB/STD_TYPES.h"

#include "../INCLUDE/MCAL/DIO/DIO_INTERFACE.h"
#include "../INCLUDE/MCAL/DIO/DIO_PRIVATE.h"
#include "../INCLUDE/MCAL/DIO/DIO_CFG.h"

void MDIO_voidInit()
{
	DDRA_REG= CONC_BIT(PORTA_PIN7_DIRECTION,
			PORTA_PIN6_DIRECTION,
			PORTA_PIN5_DIRECTION,
			PORTA_PIN4_DIRECTION,
			PORTA_PIN3_DIRECTION,
			PORTA_PIN2_DIRECTION,
			PORTA_PIN1_DIRECTION,
			PORTA_PIN0_DIRECTION);

	DDRB_REG= CONC_BIT(PORTB_PIN7_DIRECTION,
				PORTB_PIN6_DIRECTION,
				PORTB_PIN5_DIRECTION,
				PORTB_PIN4_DIRECTION,
				PORTB_PIN3_DIRECTION,
				PORTB_PIN2_DIRECTION,
				PORTB_PIN1_DIRECTION,
				PORTB_PIN0_DIRECTION);

	DDRC_REG= CONC_BIT(PORTC_PIN7_DIRECTION,
				PORTC_PIN6_DIRECTION,
				PORTC_PIN5_DIRECTION,
				PORTC_PIN4_DIRECTION,
				PORTC_PIN3_DIRECTION,
				PORTC_PIN2_DIRECTION,
				PORTC_PIN1_DIRECTION,
				PORTC_PIN0_DIRECTION);

	DDRD_REG= CONC_BIT(PORTD_PIN7_DIRECTION,
				PORTD_PIN6_DIRECTION,
				PORTD_PIN5_DIRECTION,
				PORTD_PIN4_DIRECTION,
				PORTD_PIN3_DIRECTION,
				PORTD_PIN2_DIRECTION,
				PORTD_PIN1_DIRECTION,
				PORTD_PIN0_DIRECTION);

	PORTA_REG= CONC_BIT(PORTA_PIN7_VALUE,
				PORTA_PIN6_VALUE,
				PORTA_PIN5_VALUE,
				PORTA_PIN4_VALUE,
				PORTA_PIN3_VALUE,
				PORTA_PIN2_VALUE,
				PORTA_PIN1_VALUE,
				PORTA_PIN0_VALUE);

	PORTB_REG= CONC_BIT(PORTB_PIN7_VALUE,
					PORTB_PIN6_VALUE,
					PORTB_PIN5_VALUE,
					PORTB_PIN4_VALUE,
					PORTB_PIN3_VALUE,
					PORTB_PIN2_VALUE,
					PORTB_PIN1_VALUE,
					PORTB_PIN0_VALUE);

	PORTC_REG= CONC_BIT(PORTC_PIN7_VALUE,
					PORTC_PIN6_VALUE,
					PORTC_PIN5_VALUE,
					PORTC_PIN4_VALUE,
					PORTC_PIN3_VALUE,
					PORTC_PIN2_VALUE,
					PORTC_PIN1_VALUE,
					PORTC_PIN0_VALUE);

	PORTD_REG= CONC_BIT(PORTD_PIN7_VALUE,
					PORTD_PIN6_VALUE,
					PORTD_PIN5_VALUE,
					PORTD_PIN4_VALUE,
					PORTD_PIN3_VALUE,
					PORTD_PIN2_VALUE,
					PORTD_PIN1_VALUE,
					PORTD_PIN0_VALUE);
}

void MDIO_voidSetPinDirection(DIO_PORTS A_DIOPORT,DIO_PINS A_DIOPIN,PIN_DIRECTION A_PINDIRECTION)
{
	if((A_DIOPORT<= PORTD) && (A_DIOPIN<=PIN7 )&& (A_PINDIRECTION <= DIO_OUTPUT ))
	{
		switch(A_DIOPORT)
		{
		case PORTA:
			switch(A_PINDIRECTION)
			{
			case DIO_OUTPUT: SET_BIT(DDRA_REG,A_DIOPIN);break;
			case DIO_INPUT: CLEAR_BIT(DDRA_REG,A_DIOPIN);break;

			}
			break;
		case PORTB:
			switch(A_PINDIRECTION)
						{
						case DIO_OUTPUT: SET_BIT(DDRB_REG,A_DIOPIN);break;
						case DIO_INPUT: CLEAR_BIT(DDRB_REG,A_DIOPIN);break;

						}
			break;
		case PORTC:
			switch(A_PINDIRECTION)
						{
						case DIO_OUTPUT: SET_BIT(DDRC_REG,A_DIOPIN);break;
						case DIO_INPUT: CLEAR_BIT(DDRC_REG,A_DIOPIN);break;

						}
			break;
		case PORTD:
			switch(A_PINDIRECTION)
						{
						case DIO_OUTPUT: SET_BIT(DDRD_REG,A_DIOPIN);break;
						case DIO_INPUT: CLEAR_BIT(DDRD_REG,A_DIOPIN);break;

						}
			break;
			default:break;

		}
	}
}


void MDIO_voidSetPinValue(DIO_PORTS A_DIOPORT,DIO_PINS A_DIOPIN,PIN_VALUE  A_PINVALUE)
{
	if((A_DIOPORT<= PORTD) && (A_DIOPIN<=PIN7 )&& (A_PINVALUE <= DIO_HIGH ))
	{
		switch(A_DIOPORT)
		{
		case PORTA:
			switch(A_PINVALUE)
			{
			case DIO_HIGH: SET_BIT(PORTA_REG,A_DIOPIN);break;
			case DIO_LOW: CLEAR_BIT(PORTA_REG,A_DIOPIN);break;

			}
			break;
		case PORTB:
			switch(A_PINVALUE)
						{
			case DIO_HIGH:SET_BIT(PORTB_REG,A_DIOPIN);break;
			case DIO_LOW: CLEAR_BIT(PORTB_REG,A_DIOPIN);break;

						}
			break;
		case PORTC:
			switch(A_PINVALUE)
						{
			case DIO_HIGH: SET_BIT(PORTC_REG,A_DIOPIN);break;
			case DIO_LOW: CLEAR_BIT(PORTC_REG,A_DIOPIN);break;

						}
			break;
		case PORTD:
			switch(A_PINVALUE)
						{
			case DIO_HIGH: SET_BIT(PORTD_REG,A_DIOPIN);break;
			case DIO_LOW: CLEAR_BIT(PORTD_REG,A_DIOPIN);break;

						}
			break;
			default:break;
		}
	}
}

void MDIO_voidTogglePinValue (DIO_PORTS A_DIOPORT,DIO_PINS A_DIOPIN)
{

	if((A_DIOPORT<= PORTD) && (A_DIOPIN<=PIN7 ))
	{
		switch(A_DIOPORT)
		{

		case PORTA:
			TOGGLE_BIT(PORTA_REG,A_DIOPIN);
			break;

		case PORTB:
			TOGGLE_BIT(PORTB_REG,A_DIOPIN);
			break;

		case PORTC:
			TOGGLE_BIT(PORTC_REG,A_DIOPIN);
			break;

		case PORTD:
			TOGGLE_BIT(PORTD_REG,A_DIOPIN);
			break;
		default:break;
		}
	}
}

void MDIO_voidTogglePinDirection (DIO_PORTS A_DIOPORT,DIO_PINS A_DIOPIN)
{

	if((A_DIOPORT<= PORTD) && (A_DIOPIN<=PIN7 ))
	{
		switch(A_DIOPORT)
		{
		case PORTA:
			TOGGLE_BIT(DDRA_REG,A_DIOPIN);
			break;
		case PORTB:
			TOGGLE_BIT(DDRB_REG,A_DIOPIN);

			break;
		case PORTC:
			TOGGLE_BIT(DDRC_REG,A_DIOPIN);

			break;
		case PORTD:
			TOGGLE_BIT(DDRD_REG,A_DIOPIN);

			break;
		default:break;

		}
	}
}

void MDIO_voidSetPortValue (DIO_PORTS A_DIOPORT,u8 a_u8PORTVALUE)
{
	if((A_DIOPORT<= PORTD))
		{
			switch(A_DIOPORT)
			{
			case PORTA:
				SET_BYTE(PORTA_REG,a_u8PORTVALUE);
				break;
			case PORTB:
				SET_BYTE(PORTB_REG,a_u8PORTVALUE);

				break;
			case PORTC:
				SET_BYTE(PORTC_REG,a_u8PORTVALUE);

				break;
			case PORTD:
				SET_BYTE(PORTD_REG,a_u8PORTVALUE);

				break;
			}
		}
}
void MDIO_voidSetPortDirection (DIO_PORTS A_DIOPORT,u8 a_u8PORTDIRECTION)
{
	if((A_DIOPORT<= PORTD))
			{
				switch(A_DIOPORT)
				{
				case PORTA:
					SET_BYTE(DDRA_REG,a_u8PORTDIRECTION);
					break;
				case PORTB:
					SET_BYTE(DDRB_REG,a_u8PORTDIRECTION);

					break;
				case PORTC:
					SET_BYTE(DDRC_REG,a_u8PORTDIRECTION);

					break;
				case PORTD:
					SET_BYTE(DDRD_REG,a_u8PORTDIRECTION);

					break;
				}
			}
}

PIN_VALUE MDIO_pinValueGetPinValue(DIO_PORTS A_DIOPORT, DIO_PINS A_DIOPIN)
{
	PIN_VALUE VALUE;
	if((A_DIOPORT<= PORTD) && (A_DIOPIN<=PIN7 ))
		{
			switch(A_DIOPORT)
			{

			case PORTA:
				VALUE=GET_BIT(PINA_REG,A_DIOPIN);
				break;

			case PORTB:
				VALUE=GET_BIT(PINB_REG,A_DIOPIN);
				break;

			case PORTC:
				VALUE=GET_BIT(PINC_REG,A_DIOPIN);
				break;

			case PORTD:
				VALUE=GET_BIT(PIND_REG,A_DIOPIN);
				break;
			default:break;
			}
		}
	return VALUE;

}

