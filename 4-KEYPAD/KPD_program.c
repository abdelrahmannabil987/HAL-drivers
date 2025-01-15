 /************************************/
/************************************/
/********    A.NABIL    *************/
/********    HAL Layer  *************/
/********    SWC:KEYPAD *************/
/************************************/
/************************************/

#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "KPD_config.h"
#include "KPD_interface.h"
#include "KPD_private.h"


u8 KPD_u8GetPressedKey(void)
{
	u8 Local_u8PressedKey=KPD_NO_PRESSED_KEY,Local_u8PinState;
	u8 Local_u8ColumnIndex,Local_u8RowIndex;
	static u8 Local_u8KPDArr[Row_NUM][Column_NUM]=KPD_ARR_VAL; //static for not saving in stack //save in .data in ram
    static u8 Local_u8KPDCoumnArr[Column_NUM]={KPD_Column0_PIN,KPD_Column1_PIN,KPD_Column2_PIN,KPD_Column3_PIN};
    static u8 Local_u8KPDRowArr[Row_NUM]={KPD_ROW0_PIN,KPD_ROW1_PIN,KPD_ROW2_PIN,KPD_ROW3_PIN};
	for(Local_u8ColumnIndex=0;Local_u8ColumnIndex<Column_NUM;Local_u8ColumnIndex++)
	{
		 /*Activate Current Column --->set pin value to low*/
		DIO_u8SetPinValue(KPD_PORT,Local_u8KPDCoumnArr[Local_u8ColumnIndex],DIO_u8PIN_LOW);
		for(Local_u8RowIndex=0;Local_u8RowIndex<Row_NUM;Local_u8RowIndex++)
		{
			/*read the current row*/
			DIO_u8GetPinValue(KPD_PORT,Local_u8KPDRowArr[Local_u8RowIndex],&Local_u8PinState);
			/*check if switch is pressed*/
			if(DIO_u8PIN_LOW==Local_u8PinState)
			{
				Local_u8PressedKey=Local_u8KPDArr[Local_u8RowIndex][Local_u8ColumnIndex];
				/*Polling or busy waiting until the key is pressed*/
				while(DIO_u8PIN_LOW==Local_u8PinState)//0==variable if more safe//debouncing
				{
					DIO_u8GetPinValue(KPD_PORT,Local_u8KPDRowArr[Local_u8RowIndex],&Local_u8PinState);
				}

				return Local_u8PressedKey;
			}
		}
		/*Deactivate the current column*/
		DIO_u8SetPinValue(KPD_PORT,Local_u8KPDCoumnArr[Local_u8ColumnIndex],DIO_u8PIN_HIGH);
	}

	return Local_u8PressedKey;
}
