/********************************************************/
/************* Author : A.Nabil *************************/
/************* Layer: HAL       *************************/
/************* LED_PROGRAM_H_ *************************/
/********************************************************/
/********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "LED_interface.h"
#include "DIO_interface.h"


u8 LED_EnPin(En_PIN * p_EnArguments)
{
	u8 Local_u8ErrorState = 0;
	if(p_EnArguments->Copy_u8Type ==C_Anode)
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
	else if(p_EnArguments->Copy_u8Type ==C_Cathode)
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
	else
	{
		Local_u8ErrorState=1;
	}
	return Local_u8ErrorState;
}


/****************************************************************************************************************/


u8 Blink_LED(LED_T * P_LEDArguments)
{
	u8 Local_u8ErrorState=0;

	if (P_LEDArguments->Copy_u8Pin<=7)
	{
		if (P_LEDArguments->Copy_u8Src_Sink==LED_u8Source_Connection)
		{
			DIO_u8SetPinValue(P_LEDArguments->Copy_u8Port,P_LEDArguments->Copy_u8Pin,DIO_u8PIN_HIGH);
		}
		else if (P_LEDArguments->Copy_u8Src_Sink==LED_u8Sink_Connection)
		{
			DIO_u8SetPinValue(P_LEDArguments->Copy_u8Port,P_LEDArguments->Copy_u8Pin,DIO_u8PIN_LOW);
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


/****************************************************************************************************************/

u8 Blink_8LED(Blink8LEDS_T * P_8LEDSArguments)
{
	u8 Local_u8ErrorState=0;


		if (P_8LEDSArguments->Copy_u8Src_Sink==LED_u8Source_Connection)
		{
			DIO_u8SetPortValue(P_8LEDSArguments->Copy_u8Port,DIO_u8PORT_HIGH);
		}
		else if (P_8LEDSArguments->Copy_u8Src_Sink==LED_u8Sink_Connection)
		{
			DIO_u8SetPortValue(P_8LEDSArguments->Copy_u8Port,DIO_u8PORT_LOW);
		}
		else
		{
			Local_u8ErrorState=1;
		}

	return Local_u8ErrorState;
}



/****************************************************************************************************************/

































