/************************************************************/
/************************************************************/
/*****************  A.Nabil   *******************************/
/*****************  HAL_Layer *******************************/
/************************************************************/
/************************************************************/


#ifndef STEPPER_INTERFACE_H_
#define STEPPER_INTERFACE_H_


typedef struct
{
	u8 Copy_u8Port;
	u8 Copy_u8Pin0;
	u8 Copy_u8Pin1;
	u8 Copy_u8Pin2;
	u8 Copy_u8Pin3;
}Stepper;

/*                  CONNECTION                        */
//connection is MC to the darligton pair then darligton pair to the stepper motor


#define DIO_u8PIN_LOW 0
#define DIO_u8PIN_HIGH 1


void Stepper_voidRotateCW(Stepper * stepper_arguments);
void Stepper_voidRotateCCW(Stepper * stepper_arguments);
void Stepper_voidStop(Stepper * stepper_arguments);


#endif
