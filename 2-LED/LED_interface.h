/********************************************************/
/********************************************************/
/************* Author : A.Nabil *************************/
/************* Layer: HAL       *************************/
/************* LED_INTERFACE_H_ *************************/
/********************************************************/
/********************************************************/


#ifndef LED_INTERFACE_H_ 
#define LED_INTERFACE_H_

#define LED_u8Source_Connection 1
#define LED_u8Sink_Connection 0

#define LED_u8PORTA 0
#define LED_u8PORTB 1
#define LED_u8PORTC 2
#define LED_u8PORTD 3
  
#define LED_u8PIN0 0
#define LED_u8PIN1 1
#define LED_u8PIN2 2
#define LED_u8PIN3 3
#define LED_u8PIN4 4
#define LED_u8PIN5 5
#define LED_u8PIN6 6
#define LED_u8PIN7 7

#define C_Anode 0
#define C_Cathode 1

typedef struct
{
	u8 Copy_u8Port;
	u8 Copy_u8Pin;
	u8 Copy_u8Src_Sink;
}LED_T;

typedef struct
{
	u8 Copy_u8Port;
	u8 Copy_u8Src_Sink;
}Blink8LEDS_T;

typedef struct
{
	u8 Copy_u8Port;
	u8 Copy_u8Pin;
	u8 Copy_u8Type;
}En_PIN;

u8 LED_EnPin(En_PIN * p_EnArguments);
u8 Blink_LED(LED_T * P_LEDArguments);
u8 Blink_8LED(Blink8LEDS_T * P_8LEDSArguments);

#endif
