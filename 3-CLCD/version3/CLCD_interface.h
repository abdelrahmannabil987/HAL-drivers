/************************************************/
/************************************************/
/*****************   A.NABIL   ******************/
/*****************   HAL       ******************/
/*****************   CLCD      ******************/
/************************************************/
/************************************************/



#ifndef CLCD_INTERFACE_H_ 
#define CLCD_INTERFACE_H_

#define Cursor_ON  1
#define Cursor_OFF  0



void CLCD_voidSendCommand(u8 Copy_u8Command);

void CLCD_voidSendData(u8 Copy_u8Data);

u8 CLCD_voidInit_8BitMode(void);

void CLCD_voidsendstring(const char * copy_pcstring);//ascii so char


void CLCD_voidGoToXY(u8 Copy_u8Xpos, u8 Copy_u8Ypos);

void CLCD_voidwritespecialcharacter(u8 * copy_pu8pattern,u8 copy_u8patternNumber,u8 copy_u8XPos,u8 copy_u8YPos);

void CLCD_voidwriteNumber(u32 copy_u32Number);

void CLCD_voidSaveSpecialCharacterToCGRAM(u8 * copy_pu8pattern,u8 copy_u8patternNumber);


#endif 
