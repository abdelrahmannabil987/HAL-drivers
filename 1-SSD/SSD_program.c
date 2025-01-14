/********************************************************/
/********************************************************/
/************* Author : A.Nabil *************************/
/************* Layer: HAL       *************************/
/************* PROGRAM_C        *************************/
/********************************************************/
/********************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SSD_interface.h"
#include "DIO_interface.h"

u8 SSD_EnPin(En_PIN * p_EnArguments)
{
	u8 Local_u8ErrorState = 0;
	if(p_EnArguments->Copy_u8Type ==C_Anode)
	{
		if (p_EnArguments->Copy_u8Pin<=7)
		{
		DIO_u8SetPinValue(p_EnArguments->Copy_u8Port,p_EnArguments->Copy_u8Pin,DIO_u8PIN_HIGH);
		}
		else
		{
			Local_u8ErrorState=1;
		}
	}
	else if(p_EnArguments->Copy_u8Type ==C_Cathode)
	{
		if (p_EnArguments->Copy_u8Pin<=7)
		{
			DIO_u8SetPinValue(p_EnArguments->Copy_u8Port,p_EnArguments->Copy_u8Pin,DIO_u8PIN_LOW);
		}
		else
		{
			Local_u8ErrorState=1;
		}
	}
	else
	{
		Local_u8ErrorState=1;
	}
	return Local_u8ErrorState;
}


u8 SSD_u8SetNumber (SSD_T * p_Arguments)
{
	u8 Local_u8ErrorState = 0;
	if(p_Arguments->Copy_u8Type==C_Anode)
	{
		p_Arguments->Copy_u8Number=~(p_Arguments->Copy_u8Number);
		DIO_u8SetPortValue(p_Arguments->Copy_u8Port,p_Arguments->Copy_u8Number);
	}

	else if(p_Arguments->Copy_u8Type==C_Cathode)
	{
		p_Arguments->Copy_u8Number=(p_Arguments->Copy_u8Number);
		DIO_u8SetPortValue(p_Arguments->Copy_u8Port,p_Arguments->Copy_u8Number);
	}
	else
	{
		Local_u8ErrorState = 1 ;
	}
	return Local_u8ErrorState;
}
