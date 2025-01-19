/*****************************************************/
/*****************************************************/
/************** A.NABIL ******************************/
/************** HAL LAYER ****************************/
/************** PROGRAM_C_   *************************/
/*****************************************************/
/*****************************************************/

#include "STD_TYPES.h"
#include "DC_MOTORconfig.h"
#include "DC_MOTORinterface.h"
#include "DC_MOTORprivate.h"
#include "DIO_interface.h"

void DC_MOTOR_voidCW()
{
	DIO_u8SetPinValue(DC_MOTOR_PORT,DC_MOTOR_PIN0,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DC_MOTOR_PORT,DC_MOTOR_PIN1,DIO_u8PIN_LOW);
}

void DC_MOTOR_voidCCW()
{
	DIO_u8SetPinValue(DC_MOTOR_PORT,DC_MOTOR_PIN0,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DC_MOTOR_PORT,DC_MOTOR_PIN1,DIO_u8PIN_HIGH);
}

void DC_MOTOR_voidSTOP()
{
	DIO_u8SetPinValue(DC_MOTOR_PORT,DC_MOTOR_PIN0,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DC_MOTOR_PORT,DC_MOTOR_PIN1,DIO_u8PIN_LOW);
}
