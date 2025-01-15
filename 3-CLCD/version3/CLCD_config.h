/************************************************/
/************************************************/
/*****************   A.NABIL   ******************/
/*****************   HAL       ******************/
/*****************   CLCD      ******************/
/************************************************/
/************************************************/




#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_ 


#define CLCD_DATA_PORT  DIO_u8PORTA /*Choose Data Port*/
#define CLCD_CTRL_PORT  DIO_u8PORTB /*Choose Ctrl Port (RS-RW-E)*/



#define CLCD_RS_PIN    DIO_u8PIN0
#define CLCD_RW_PIN    DIO_u8PIN1
#define CLCD_E_PIN     DIO_u8PIN2

#define Array_Size 9  //number of digits in number in write number function


/* Choose
 * Cursor_ON for cursor and blink
 * OR
 * Cursor_OFF for no cursor nor blink
 * */

#define Cursor Cursor_OFF

#endif
