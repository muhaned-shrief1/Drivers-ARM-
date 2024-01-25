/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/


#ifndef RTOS_INTERFACE_H_
#define RTOS_INTERFACE_H_

void RTOS_VidStart( void );

void RTOS_VidCreateTask( u8 Copy_u8Priority , u16 Copy_u16Periodicity , void (*Copy_pvTask)( void ) , u16 Copy_u16FirstDelay );

void RTOS_VidSuspendTask ( u8 Copy_u8TaskID );
void RTOS_VidResumeTask  ( u8 Copy_u8TaskID );
void RTOS_VidDeleteTask  ( u8 Copy_u8TaskID );

#endif /* RTOS_INTERFACE_H_ */
