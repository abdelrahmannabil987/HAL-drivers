/************************************************/
/************************************************/
/*****************   A.NABIL   ******************/
/*****************   HAL       ******************/
/*****************   CLCD      ******************/
/************************************************/
/************************************************/


#include "STD_TYPES.h"
#include "util/delay.h"
#include "DIO_interface.h"
#include "CLCD_config.h"
#include "CLCD_interface.h"
#include "CLCD_private.h"


void CLCD_voidSendCommand(u8 Copy_u8Command)
{
	/*set RS pin to low ----> Command*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_LOW);
	/*set R/W pin to low TO write (instruction write operaion (write instruction code in IR)*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);
	/*set Command for data pins*/
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Command);
	/*set enable pulse*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
}

void CLCD_voidSendData(u8 Copy_u8Data)
{
	/*set RS pin to high ----> data*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_HIGH);
	/*set RW pin to low to write*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);
	/*set command for data pins*/
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Data);
	/*set enable pulse*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(200);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
}




void CLCD_voidsendstring(const char * copy_pcstring)//ascii so char
{
	u8 i=0 ;

	/*set command for data pins*/
	while(copy_pcstring[i] !='\0')
	{
		if (i==16)//to move to the second row
		{
			CLCD_voidGoToXY(1,0);
		}
		CLCD_voidSendData(copy_pcstring[i]);

		i++;
	}
}
/*
u8 CLCD_voidInit_4BitMode(void)
{
	u8 Local_u8ErrorState , Temp=Cursor ;
	//wait for more than 30 ms

	_delay_ms(40);
	//Function set command : 2 lines , 5*8 font size
	CLCD_voidSendCommand(0b00100000);
	CLCD_voidSendCommand(0b00100000);
	CLCD_voidSendCommand(0b10000000);
	//Display on off control : display enable , disable cursor , no blink cursor
	CLCD_voidSendCommand(0b00000000);
	if (Temp == 1 )
	{
		CLCD_voidSendCommand(0b11110000);
	}
	else if(Temp==0)
	{
		CLCD_voidSendCommand(0b11000000);
	}
	else
	{
		Local_u8ErrorState=1;
	}
	//Clear display
	CLCD_voidSendCommand(0b00000000);
	CLCD_voidSendCommand(0b00000001);

	return Local_u8ErrorState;
}

*/
u8 CLCD_voidInit_8BitMode(void)
{
	u8 Temp=Cursor , Local_u8ErrorState;
	/*Function set command : 2 lines , 5*8 font size*/
	CLCD_voidSendCommand(0b00111000);

	/*wait for more than 30 ms*/

	_delay_ms(40);
	/*Function set command : 2 lines , 5*8 font size*/
	CLCD_voidSendCommand(0b00111000);

	/*Display on off control : display enable , disable cursor , no blink cursor*/
	if (Temp == 1 )
	{
		CLCD_voidSendCommand(0b00001111);
	}
	else if(Temp==0)
	{
		CLCD_voidSendCommand(0b00001100);
	}
	else
	{
		Local_u8ErrorState=1;
	}
	/*Clear display*/
	CLCD_voidSendCommand(1);


	return Local_u8ErrorState;


}


void CLCD_voidGoToXY(u8 Copy_u8Xpos, u8 Copy_u8Ypos)
{
	u8 Local_u8adress;
	if(Copy_u8Xpos==0)
	{
		/*location for first line*/
		Local_u8adress=Copy_u8Ypos;
	}
	else if (Copy_u8Xpos==1)
	{
		/*location for second line*/
		Local_u8adress=Copy_u8Ypos+0x40;
	}
	CLCD_voidSendCommand(Local_u8adress+128);//to make the 8 bit = 1 in DDRAM Address Command data sheet page 16
}

void CLCD_voidWriteSpecialCharacter(u8 * copy_pu8pattern,u8 copy_u8patternNumber,u8 copy_u8XPos,u8 copy_u8YPos)
{

	/*calculate CGRAM address whose each block is 8 bytes*/
	u8 Local_u8CGRAMaddress , Local_u8Iterator;
	Local_u8CGRAMaddress=copy_u8patternNumber*8;
	/*send CGRAM address command to LCD,with setting set 6 , clearing bit 7 */
	CLCD_voidSendCommand(Local_u8CGRAMaddress+64);

	/*write the pattern into CGRAM*/
	for (Local_u8Iterator=0;Local_u8Iterator<8;Local_u8Iterator++)
	{

		CLCD_voidSendData(copy_pu8pattern[Local_u8Iterator]);
	}

	/*go back to the DDRAM to display the pattern*/
	CLCD_voidGoToXY(copy_u8XPos,copy_u8YPos);

	/*display  the pattern written in the CGRAM */
	CLCD_voidSendData(copy_u8patternNumber/*value from 0 to 7 will make DDRAM understand that she must get a value from CGRAM*/);
}


void CLCD_voidwriteNumber(u32 copy_u32Number)
{
	u8 arr[Array_Size],i,Local_u8Iterator;
	/*f32 Temp;
	Temp=copy_u32Number;
	while(1)
	{
		Temp/=10;
		Local_u8Size++;
		if(Temp<1)
		{
			break;
		}

	}*/
	i=Array_Size-1;
	//Local_u8Size=i= 8;
	for (Local_u8Iterator=0;Local_u8Iterator<Array_Size;Local_u8Iterator++)
	{
		arr[i]=copy_u32Number%10;
		copy_u32Number/=10;
		i--;
	}
	for (Local_u8Iterator=0;Local_u8Iterator<Array_Size;Local_u8Iterator++)
	{

		switch (arr[Local_u8Iterator])
		{
		case 0 : CLCD_voidSendData('0');break;
		case 1 : CLCD_voidSendData('1');break;
		case 2 : CLCD_voidSendData('2');break;
		case 3 : CLCD_voidSendData('3');break;
		case 4 : CLCD_voidSendData('4');break;
		case 5 : CLCD_voidSendData('5');break;
		case 6 : CLCD_voidSendData('6');break;
		case 7 : CLCD_voidSendData('7');break;
		case 8 : CLCD_voidSendData('8');break;
		case 9 : CLCD_voidSendData('9');break;
		}
	}


}









void CLCD_voidSaveSpecialCharacterToCGRAM(u8 * copy_pu8pattern,u8 copy_u8patternNumber)
{

	/*calculate CGRAM address whose each block is 8 bytes*/
	u8 Local_u8CGRAMaddress , Local_u8Iterator;
	Local_u8CGRAMaddress=copy_u8patternNumber*8;
	/*send CGRAM address command to LCD,with setting set 6 , clearing bit 7 */
	CLCD_voidSendCommand(Local_u8CGRAMaddress+64);

	/*write the pattern into CGRAM*/
	for (Local_u8Iterator=0;Local_u8Iterator<8;Local_u8Iterator++)
	{

		CLCD_voidSendData(copy_pu8pattern[Local_u8Iterator]);
	}
}


