/************************************************************/
/************************************************************/
/*****************  A.Nabil   *******************************/
/*****************  HAL_Layer *******************************/
/************************************************************/
/************************************************************/


#include "STD_TYPES.h"
#include "Stepper_config.h"
#include "Stepper_interface.h"
#include "Stepper_private.h"
#include "util/delay.h"


void Stepper_voidRotateCCW(Stepper * stepper_arguments)
{

	DIO_u8SetPinValue(stepper_arguments->Copy_u8Port,stepper_arguments->Copy_u8Pin0,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(stepper_arguments->Copy_u8Port,stepper_arguments->Copy_u8Pin1,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(stepper_arguments->Copy_u8Port,stepper_arguments->Copy_u8Pin2,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(stepper_arguments->Copy_u8Port,stepper_arguments->Copy_u8Pin3,DIO_u8PIN_HIGH);
	_delay_ms(2);

	DIO_u8SetPinValue(stepper_arguments->Copy_u8Port,stepper_arguments->Copy_u8Pin0,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(stepper_arguments->Copy_u8Port,stepper_arguments->Copy_u8Pin1,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(stepper_arguments->Copy_u8Port,stepper_arguments->Copy_u8Pin2,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(stepper_arguments->Copy_u8Port,stepper_arguments->Copy_u8Pin3,DIO_u8PIN_HIGH);
	_delay_ms(2);

	DIO_u8SetPinValue(stepper_arguments->Copy_u8Port,stepper_arguments->Copy_u8Pin0,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(stepper_arguments->Copy_u8Port,stepper_arguments->Copy_u8Pin1,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(stepper_arguments->Copy_u8Port,stepper_arguments->Copy_u8Pin2,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(stepper_arguments->Copy_u8Port,stepper_arguments->Copy_u8Pin3,DIO_u8PIN_HIGH);
	_delay_ms(2);

	DIO_u8SetPinValue(stepper_arguments->Copy_u8Port,stepper_arguments->Copy_u8Pin0,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(stepper_arguments->Copy_u8Port,stepper_arguments->Copy_u8Pin1,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(stepper_arguments->Copy_u8Port,stepper_arguments->Copy_u8Pin2,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(stepper_arguments->Copy_u8Port,stepper_arguments->Copy_u8Pin3,DIO_u8PIN_LOW);
	_delay_ms(2);
}





void Stepper_voidRotateCW(Stepper * stepper_arguments)
{
	DIO_u8SetPinValue(stepper_arguments->Copy_u8Port,stepper_arguments->Copy_u8Pin0,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(stepper_arguments->Copy_u8Port,stepper_arguments->Copy_u8Pin1,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(stepper_arguments->Copy_u8Port,stepper_arguments->Copy_u8Pin2,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(stepper_arguments->Copy_u8Port,stepper_arguments->Copy_u8Pin3,DIO_u8PIN_LOW);
	_delay_ms(2);

	DIO_u8SetPinValue(stepper_arguments->Copy_u8Port,stepper_arguments->Copy_u8Pin0,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(stepper_arguments->Copy_u8Port,stepper_arguments->Copy_u8Pin1,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(stepper_arguments->Copy_u8Port,stepper_arguments->Copy_u8Pin2,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(stepper_arguments->Copy_u8Port,stepper_arguments->Copy_u8Pin3,DIO_u8PIN_HIGH);
	_delay_ms(2);

	DIO_u8SetPinValue(stepper_arguments->Copy_u8Port,stepper_arguments->Copy_u8Pin0,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(stepper_arguments->Copy_u8Port,stepper_arguments->Copy_u8Pin1,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(stepper_arguments->Copy_u8Port,stepper_arguments->Copy_u8Pin2,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(stepper_arguments->Copy_u8Port,stepper_arguments->Copy_u8Pin3,DIO_u8PIN_HIGH);
	_delay_ms(2);

	DIO_u8SetPinValue(stepper_arguments->Copy_u8Port,stepper_arguments->Copy_u8Pin0,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(stepper_arguments->Copy_u8Port,stepper_arguments->Copy_u8Pin1,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(stepper_arguments->Copy_u8Port,stepper_arguments->Copy_u8Pin2,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(stepper_arguments->Copy_u8Port,stepper_arguments->Copy_u8Pin3,DIO_u8PIN_HIGH);
	_delay_ms(2);

}


void Stepper_voidStop(Stepper * stepper_arguments)
{
	DIO_u8SetPinValue(stepper_arguments->Copy_u8Port,stepper_arguments->Copy_u8Pin0,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(stepper_arguments->Copy_u8Port,stepper_arguments->Copy_u8Pin1,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(stepper_arguments->Copy_u8Port,stepper_arguments->Copy_u8Pin2,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(stepper_arguments->Copy_u8Port,stepper_arguments->Copy_u8Pin3,DIO_u8PIN_HIGH);
	_delay_ms(2);

	DIO_u8SetPinValue(stepper_arguments->Copy_u8Port,stepper_arguments->Copy_u8Pin0,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(stepper_arguments->Copy_u8Port,stepper_arguments->Copy_u8Pin1,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(stepper_arguments->Copy_u8Port,stepper_arguments->Copy_u8Pin2,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(stepper_arguments->Copy_u8Port,stepper_arguments->Copy_u8Pin3,DIO_u8PIN_HIGH);
	_delay_ms(2);

	DIO_u8SetPinValue(stepper_arguments->Copy_u8Port,stepper_arguments->Copy_u8Pin0,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(stepper_arguments->Copy_u8Port,stepper_arguments->Copy_u8Pin1,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(stepper_arguments->Copy_u8Port,stepper_arguments->Copy_u8Pin2,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(stepper_arguments->Copy_u8Port,stepper_arguments->Copy_u8Pin3,DIO_u8PIN_HIGH);
	_delay_ms(2);

	DIO_u8SetPinValue(stepper_arguments->Copy_u8Port,stepper_arguments->Copy_u8Pin0,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(stepper_arguments->Copy_u8Port,stepper_arguments->Copy_u8Pin1,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(stepper_arguments->Copy_u8Port,stepper_arguments->Copy_u8Pin2,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(stepper_arguments->Copy_u8Port,stepper_arguments->Copy_u8Pin3,DIO_u8PIN_HIGH);
	_delay_ms(2);
}
