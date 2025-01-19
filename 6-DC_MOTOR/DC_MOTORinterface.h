/*****************************************************/
/*****************************************************/
/************** A.NABIL ******************************/
/************** HAL LAYER ****************************/
/************** INTERFACE_H_ *************************/
/*****************************************************/
/*****************************************************/


//preprocessor file guard
#ifndef INTERFACE_H_
#define INTERFACE_H_


/*
better not to use MCU pin to drive the motor and use a transistor 
* H bridge connection make your MCU pin safe to not get a hight current out of your MC 
* H bridge needs a 4 transistor connected togethr 
each two bases of 2 transistors are connected together to a MC pin 
and each of the two is connected to one of the rest transistors (emitter of the first to the collector of the second)
and connected to the gnd and vcc 
* let's say we have 2 pins : pin0 and pin1
pin0 output 1 and pin1 output 0 make the motor drives in some direction
pin0 output 0 and pin1 output 1 make the motor drives in the other direction
both pins output 1  or 0 ==> break no rotation 

*/



void DC_MOTOR_voidCW(); // this function to make the motor drives CW 


void DC_MOTOR_voidCCW();// this function to make the motor drives CCW 


void DC_MOTOR_voidSTOP();// this function to stop rotation 





#endif
