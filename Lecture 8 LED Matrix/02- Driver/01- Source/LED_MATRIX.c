/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/


#include "TYPES.h"
#include "GPIO_INTERFACE.h"
#include "DELAY_INTERFACE.h"

#include "LED_MATRIX_INTERFACE.h"
#include "LED_MATRIX_CONFIG.h"

void LDM_VidEnable ( u8 * arr ){

	for( u8 i = 0 ; i < 8 ; i ++ ){

		MGPIO_VidSetPortValue( LDM_ROW_PORT , LDM_ROW_HIGH_LOW , arr[i] );
		MGPIO_VidSetPinValue ( LDM_COL_PORT , i+PIN8 , LOW );
		_delay_ms(2);
		MGPIO_VidSetPinValue ( GPIOB , i+PIN8 , HIGH );

	}

}
