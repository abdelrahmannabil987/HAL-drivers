/***********************************/
/***** Author : A.Nabil ************/
/***** Date   : 13 Mar 2025  *******/
/***** Version: V01 ****************/
/***********************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STICK_interface.h"

#include "LEDMTRX_interface.h"
#include "LEDMTRX_private.h"
#include "LEDMTRX_config.h"

void HLEDMTRX_voidInit(void)
{
	MGPIO_voidSetPinDirection(LEDMTRX_ROW0_PIN,0b0010);
	MGPIO_voidSetPinDirection(LEDMTRX_ROW1_PIN,0b0010);
	MGPIO_voidSetPinDirection(LEDMTRX_ROW2_PIN,0b0010);
	MGPIO_voidSetPinDirection(LEDMTRX_ROW3_PIN,0b0010);
	MGPIO_voidSetPinDirection(LEDMTRX_ROW4_PIN,0b0010);
	MGPIO_voidSetPinDirection(LEDMTRX_ROW5_PIN,0b0010);
	MGPIO_voidSetPinDirection(LEDMTRX_ROW6_PIN,0b0010);
	MGPIO_voidSetPinDirection(LEDMTRX_ROW7_PIN,0b0010);
	
	
	MGPIO_voidSetPinDirection(LEDMTRX_COL0_PIN,0b0010);
	MGPIO_voidSetPinDirection(LEDMTRX_COL1_PIN,0b0010);
	MGPIO_voidSetPinDirection(LEDMTRX_COL2_PIN,0b0010);
	MGPIO_voidSetPinDirection(LEDMTRX_COL3_PIN,0b0010);
	MGPIO_voidSetPinDirection(LEDMTRX_COL4_PIN,0b0010);
	MGPIO_voidSetPinDirection(LEDMTRX_COL5_PIN,0b0010);
	MGPIO_voidSetPinDirection(LEDMTRX_COL6_PIN,0b0010);
	MGPIO_voidSetPinDirection(LEDMTRX_COL7_PIN,0b0010);
}

void HLEDMTRX_voidDisplay(u8 *Copy_u8Data)
{
	while(1)
	{
	/*Column 0*/
	DisableAllColumns();
	MGPIO_voidSetPinValue(LEDMTRX_COL0_PIN,GPIO_HIGH);
	SetRowValues(Copy_u8Data[0]);
	MSTICK_voidSetBusyWait(2500);//2.5 MSEC
	
	/*Column 1*/
	DisableAllColumns();
	MGPIO_voidSetPinValue(LEDMTRX_COL1_PIN,GPIO_LOW);
	SetRowValues(Copy_u8Data[1]);
	MSTICK_voidSetBusyWait(2500);//2.5 MSEC
	
	/*Column 2*/
	DisableAllColumns();
	MGPIO_voidSetPinValue(LEDMTRX_COL2_PIN,GPIO_LOW);
	SetRowValues(Copy_u8Data[2]);
	MSTICK_voidSetBusyWait(2500);//2.5 MSEC
	
	/*Column 3*/
	DisableAllColumns();
	MGPIO_voidSetPinValue(LEDMTRX_COL3_PIN,GPIO_LOW);
	SetRowValues(Copy_u8Data[3]);
	MSTICK_voidSetBusyWait(2500);//2.5 MSEC
	
	/*Column 4*/
	DisableAllColumns();
	MGPIO_voidSetPinValue(LEDMTRX_COL4_PIN,GPIO_LOW);
	SetRowValues(Copy_u8Data[4]);
	MSTICK_voidSetBusyWait(2500);//2.5 MSEC
	
	/*Column 5*/
	DisableAllColumns();
	MGPIO_voidSetPinValue(LEDMTRX_COL5_PIN,GPIO_LOW);
	SetRowValues(Copy_u8Data[5]);
	MSTICK_voidSetBusyWait(2500);//2.5 MSEC
	
	/*Column 6*/
	DisableAllColumns();
	MGPIO_voidSetPinValue(LEDMTRX_COL6_PIN,GPIO_LOW);
	SetRowValues(Copy_u8Data[6]);
	MSTICK_voidSetBusyWait(2500);//2.5 MSEC
	
	/*Column 7*/
	DisableAllColumns();
	MGPIO_voidSetPinValue(LEDMTRX_COL7_PIN,GPIO_LOW);
	SetRowValues(Copy_u8Data[7]);
	MSTICK_voidSetBusyWait(2500);//2.5 MSEC
	}
}



static void DisableAllColumns(void)
{
	MGPIO_voidSetPinValue(LEDMTRX_COL0_PIN,GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMTRX_COL1_PIN,GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMTRX_COL2_PIN,GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMTRX_COL3_PIN,GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMTRX_COL4_PIN,GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMTRX_COL5_PIN,GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMTRX_COL6_PIN,GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMTRX_COL7_PIN,GPIO_HIGH);
}

static void SetRowValues(u8 Copy_u8Vlaue)
{
	u8 Local_u8BIT;
	Local_u8BIT=GET_BIT(Copy_u8Vlaue,0);
	MGPIO_voidSetPinValue(LEDMTRX_ROW0_PIN,Local_u8BIT);
	
	Local_u8BIT=GET_BIT(Copy_u8Vlaue,1);
	MGPIO_voidSetPinValue(LEDMTRX_ROW1_PIN,Local_u8BIT);
	
	Local_u8BIT=GET_BIT(Copy_u8Vlaue,2);
	MGPIO_voidSetPinValue(LEDMTRX_ROW2_PIN,Local_u8BIT);
	
	Local_u8BIT=GET_BIT(Copy_u8Vlaue,3);
	MGPIO_voidSetPinValue(LEDMTRX_ROW3_PIN,Local_u8BIT);
	
	Local_u8BIT=GET_BIT(Copy_u8Vlaue,4);
	MGPIO_voidSetPinValue(LEDMTRX_ROW4_PIN,Local_u8BIT);
	
	Local_u8BIT=GET_BIT(Copy_u8Vlaue,5);
	MGPIO_voidSetPinValue(LEDMTRX_ROW5_PIN,Local_u8BIT);
	
	Local_u8BIT=GET_BIT(Copy_u8Vlaue,6);
	MGPIO_voidSetPinValue(LEDMTRX_ROW6_PIN,Local_u8BIT);
	
	Local_u8BIT=GET_BIT(Copy_u8Vlaue,7);
	MGPIO_voidSetPinValue(LEDMTRX_ROW7_PIN,Local_u8BIT);
}
