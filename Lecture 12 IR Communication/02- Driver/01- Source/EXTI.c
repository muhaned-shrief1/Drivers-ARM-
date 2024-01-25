/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/



#include"TYPES.h"
#include"MACROS.h"

#include"EXTI_PRIVATE.h"
#include"EXTI_INTERFACE.h"

#include"AFIO_INTERFACE.h"

void (*EXTI0_CallBack) (void);

void EXTI_VidInit( u8 Copy_EXTILine , u8 Copy_u8EXTIMode ){

	switch(Copy_u8EXTIMode){

	case RISING_EDGE:

		SET_BIT( EXTI->RTSR , Copy_EXTILine );

		break;


	case FALLING_EDGE:

		SET_BIT( EXTI->FTSR , Copy_EXTILine );

		break;


	case ON_CHANGE:

		SET_BIT( EXTI->RTSR , Copy_EXTILine );
		SET_BIT( EXTI->FTSR , Copy_EXTILine );

		break;
	}

	SET_BIT( EXTI->IMR , Copy_EXTILine );

}

void EXTI_VidEnableEXTI( u8 LOC_u8EXTILine){

	SET_BIT( EXTI->IMR , LOC_u8EXTILine );

}

void EXTI_VidDisableEXTI( u8 LOC_u8EXTILine){

	CLR_BIT( EXTI->IMR , LOC_u8EXTILine );

}

void EXTI_VidSoftWareTrigger( u8 LOC_u8EXTILine){

	SET_BIT( EXTI->SWIER , LOC_u8EXTILine );

}

//////////////////////////////////////////////////// ISR 0 ///////////////////////////////////////////////////////////
void EXTI0_VidSetCallBack( void (*ptr) (void) ){

	EXTI0_CallBack = ptr;

}
void EXTI0_IRQHandler(void){

	EXTI0_CallBack();
	SET_BIT( EXTI->PR , 0 );

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
