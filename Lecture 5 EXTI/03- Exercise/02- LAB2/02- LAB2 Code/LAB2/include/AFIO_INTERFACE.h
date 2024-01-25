/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/

#ifndef AFIO_INTERFACE_H_
#define AFIO_INTERFACE_H_


//---------------------------------------------------------------------------------------------------------------------

#define EXTI0  0
#define EXTI1  1
#define EXTI2  2
#define EXTI3  3

#define EXTI4  4
#define EXTI5  5
#define EXTI6  6
#define EXTI7  7

#define EXTI8  8
#define EXTI9  9
#define EXTI10 10
#define EXTI11 11

#define EXTI12 12
#define EXTI13 13
#define EXTI14 14
#define EXTI15 15

void AFIO_VidSetEXTIConfiguration( u8 LOC_u8EXTI_Line , u8 LOC_u8PortMap );

#endif /* AFIO_INTERFACE_H_ */
