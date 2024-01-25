/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/

#include "TYPES.h"
#include "MACROS.h"

#include "SYSTICK_INTERFACE.h"
#include "GPIO_INTERFACE.h"
#include "NVIC_INTERFACE.h"
#include "AFIO_INTERFACE.h"
#include "EXTI_INTERFACE.h"

#include "IR_INTERFACE.h"
#include "IR_CONFIG.h"

volatile u8  Start           =   0   ;
volatile u8  Counter         =   0   ;
volatile u32 CodeSample[100] = { 0 } ;
volatile u8  Data            =   0   ;
volatile u8  Iterator        =   0   ;

void Read_CodeCallBack ( void ){

	if ( Start == 0 ){

		MSTK_VidStart( TIMER_VALUE );
		Start = 1;

	}
	else if ( Start == 1 ){

		CodeSample[ Counter ] = MSTK_u32GetCounterValue();
		Counter++ ;
		MSTK_VidStart( TIMER_VALUE );

	}
	if( Counter == END_OF_CODE ){

		for( Iterator = 0 ; Iterator < END_OF_CODE ; Iterator++ ){

			CodeSample[ Iterator ] = TIMER_VALUE - CodeSample[ Iterator ];

		}

		for( Iterator = DATA_COMMEND_START_EDGE ; Iterator < DATA_COMMEND_END_EDGE ; Iterator++ ){

			if( CodeSample[ Iterator ] >= LOGIC1_RANGE ){

				SET_BIT( Data , ( Iterator - DATA_COMMEND_START_EDGE ) );

			}

		}

		MNVIC_VidDisablePeripheral( EXT0 );

		Start   = 2 ;

	}

}

void Timer_ResetCallBack ( void ){

	MSTK_VidStop();
	Start  = 0 ;
	Counter = 0 ;
	Data    = 0 ;

}

void IR_VidInit( void ){

	MGPIO_VidSetPinDirection    ( IR_PORT , IR_PIN , INPUT_FLOATING    );

	MNVIC_VidSetPriority        ( EXT0 ,  1 , NO_SUB_PRIORITY , GROUP3 );
	MNVIC_VidEnablePeripheral   ( EXT0 );

	AFIO_VidSetEXTIConfiguration( EXTI_LINE0 , IR_PORT                 );
	EXTI0_VidSetCallBack        ( Read_CodeCallBack                    );
	EXTI_VidInit                ( EXTI_LINE0 , FALLING_EDGE            );

	MSTK_VidSetCallBack         ( Timer_ResetCallBack                  );
	MSTK_VidInit                (                                      );

}

u8 IR_u8GetCode ( void ){

	u8 LOC_u8Data = 0 ;

	while( Start != 2 );

	LOC_u8Data = Data ;

	Start   = 0 ;
	Counter = 0 ;
	Data    = 0 ;

	MNVIC_VidEnablePeripheral   ( EXT0 );

	return LOC_u8Data ;
}

