/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/


#include "TYPES.h"

#include "RCC_INTERFACE.h"
#include "GPIO_INTERFACE.h"
#include "NVIC_INTERFACE.h"

#include "DELAY_INTERFACE.h"

void EXTI0_IRQHandler(void){

	MGPIO_VidSetPinValue( GPIOA , PIN0 , HIGH );

}

void EXTI1_IRQHandler(void){

	MGPIO_VidSetPinValue( GPIOA , PIN0 , LOW );

}

int main(void)
{

	MRCC_VidInit();
	MRCC_VidEnablePeripheralClock( APB2_BUS , GPIOA_RCC );

	MGPIO_VidSetPinDirection( GPIOA , PIN0 , OUTPUT_SPEED_2MHZ_PP );

	MNVIC_VidSetPriority( EXT0 , 1 , NO_SUB_PRIORITY , GROUP3 );
	MNVIC_VidSetPriority( EXT1 , 2 , NO_SUB_PRIORITY , GROUP3 );

	MNVIC_VidEnablePeripheral( EXT0 );
	MNVIC_VidEnablePeripheral( EXT1 );

	while(1){

		MNVIC_VidSetPending( EXT0 );
		_delay_ms( 1000 );
		MNVIC_VidSetPending( EXT1 );
		_delay_ms( 1000 );

	}

	return 0;
}







