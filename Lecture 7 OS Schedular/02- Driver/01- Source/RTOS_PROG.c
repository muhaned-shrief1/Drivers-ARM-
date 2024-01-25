/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/

#include "TYPES.h"

#include "SYSTICK_INTERFACE.h"

#include "RTOS_PRIVATE.h"
#include "RTOS_INTERFACE.h"
#include "RTOS_CONFIG.h"

#define NULL 0

static TASK_TCB SYS_TASKS[ TASK_NUMBERS ] = { { NULL } };

void RTOS_VidStart( void ){

	MSTK_VidSetCallBack( RTOS_VidSchedular );

	MSTK_VidInit();
	/* Tick time = 1 milliysecond */
	MSTK_VidStart( TICK_TIME );

}

void RTOS_VidCreateTask( u8 Copy_u8Priority , u16 Copy_u16Periodicity , void (*Copy_pvTask)( void ) , u16 Copy_u16FirstDelay ){

	if( SYS_TASKS[ Copy_u8Priority ].TaskHandler == NULL ){

		SYS_TASKS[ Copy_u8Priority ].Periodicity = Copy_u16Periodicity ;
		SYS_TASKS[ Copy_u8Priority ].TaskHandler = Copy_pvTask         ;
		SYS_TASKS[ Copy_u8Priority ].FirstDelay  = Copy_u16FirstDelay  ;
		SYS_TASKS[ Copy_u8Priority ].State       = TASK_READY          ;

	}
	else{

		/* Do No Thing */

	}

}

void RTOS_VidSuspendTask ( u8 Copy_u8TaskID ){

	SYS_TASKS[ Copy_u8TaskID ].State = TASK_SUSPEND ;

}

void RTOS_VidResumeTask  ( u8 Copy_u8TaskID ){

	SYS_TASKS[ Copy_u8TaskID ].State = TASK_READY   ;

}
void RTOS_VidDeleteTask  ( u8 Copy_u8TaskID ){

	SYS_TASKS[ Copy_u8TaskID ].TaskHandler = NULL ;

}


void RTOS_VidSchedular( void ){

	u8 LOC_u8TaskCounter      ;

	for( LOC_u8TaskCounter = 0 ; LOC_u8TaskCounter < TASK_NUMBERS ; LOC_u8TaskCounter++ ){

		if( ( SYS_TASKS[ LOC_u8TaskCounter ].TaskHandler != NULL ) && ( SYS_TASKS[ LOC_u8TaskCounter ].State == TASK_READY ) ){

			if( SYS_TASKS[ LOC_u8TaskCounter ].FirstDelay == 0 ){

				SYS_TASKS[ LOC_u8TaskCounter ].FirstDelay = SYS_TASKS[ LOC_u8TaskCounter ].Periodicity - 1 ;
				SYS_TASKS[ LOC_u8TaskCounter ].TaskHandler();

			}
			else{

				SYS_TASKS[ LOC_u8TaskCounter ].FirstDelay--;

			}

		}
		else{

			/* Do No Thing */

		}

	}

}


