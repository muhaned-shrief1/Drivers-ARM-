/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/

#include "TYPES.h"
#include "MACROS.h"

#include "AFIO_PRIVATE.h"
#include "AFIO_INTERFACE.h"

#include "GPIO_INTERFACE.h"

void AFIO_VidSetEXTIConfiguration( u8 LOC_u8EXTI_Line , u8 LOC_u8PortMap ){

	u8 LOC_u8RegIndex = 0;

	if( LOC_u8EXTI_Line <= 3 ){
		LOC_u8RegIndex = 0 ;
	}
	else if( LOC_u8EXTI_Line <= 7 ){
		LOC_u8RegIndex   = 1 ;
		LOC_u8EXTI_Line -= 4 ;
	}
	else if( LOC_u8EXTI_Line <= 11 ){
		LOC_u8RegIndex   = 2 ;
		LOC_u8EXTI_Line -= 8 ;
	}
	else if( LOC_u8EXTI_Line <= 15 ){
		LOC_u8RegIndex   = 3 ;
		LOC_u8EXTI_Line -= 12 ;
	}

	AFIO->EXTICRx[LOC_u8RegIndex] &= ~ ( ( 0b1111 )    << ( LOC_u8EXTI_Line * 4 ));// R M W
	AFIO->EXTICRx[LOC_u8RegIndex] |= ( LOC_u8PortMap ) << ( LOC_u8EXTI_Line * 4 );

}
