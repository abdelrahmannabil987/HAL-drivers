/********************************************************/
/********************************************************/
/************* Author : A.Nabil *************************/
/************* Layer: HAL       *************************/
/************* SSD_INTERFACE_H_ *************************/
/********************************************************/
/********************************************************/


#ifndef SSD_INTERFACE_H_ 
#define SSD_INTERFACE_H_

#define DIO_u8PORTA 0
#define DIO_u8PORTB 1
#define DIO_u8PORTC 2
#define DIO_u8PORTD 3

#define C_Anode 0
#define C_Cathode 1

#define SS_0    0b00111111
#define SS_1    0b00000110
#define SS_2    0b01011011
#define SS_3    0b01001111
#define SS_4    0b01100110
#define SS_5    0b01101101
#define SS_6    0b01111101
#define SS_7    0b00000111
#define SS_8    0b01111111
#define SS_9    0b01101111


typedef struct
{
	u8 Copy_u8Port;
	u8 Copy_u8Type;
	u8 Copy_u8Number;
}SSD_T;

typedef struct
{
	u8 Copy_u8Port;
	u8 Copy_u8Pin;
	u8 Copy_u8Type;
}En_PIN;


u8 SSD_EnPin(En_PIN * p_EnArguments);

u8 SSD_u8SetNumber (SSD_T * p_Arguments);




#endif 
