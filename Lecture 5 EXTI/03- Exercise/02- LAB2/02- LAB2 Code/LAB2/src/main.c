/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/


#include "TYPES.h"

#include "RCC_INTERFACE.h"
#include "GPIO_INTERFACE.h"
#include "NVIC_INTERFACE.h"
#include "AFIO_INTERFACE.h"
#include "EXTI_INTERFACE.h"


void EXT0_CALLBACK( void ){

	MGPIO_VidSetPinValue( GPIOA , PIN3 , HIGH );
	MGPIO_VidSetPinValue( GPIOA , PIN4 , LOW  );
	MGPIO_VidSetPinValue( GPIOA , PIN5 , LOW  );

}

void EXT1_CALLBACK( void ){

	MGPIO_VidSetPinValue( GPIOA , PIN3 , LOW  );
	MGPIO_VidSetPinValue( GPIOA , PIN4 , HIGH );
	MGPIO_VidSetPinValue( GPIOA , PIN5 , LOW  );
}

void EXT2_CALLBACK( void ){

	MGPIO_VidSetPinValue( GPIOA , PIN3 , LOW  );
	MGPIO_VidSetPinValue( GPIOA , PIN4 , LOW  );
	MGPIO_VidSetPinValue( GPIOA , PIN5 , HIGH );
}

int main(void)
{

	MRCC_VidInit();
	MRCC_VidEnablePeripheralClock( APB2_BUS , GPIOA_RCC );
	MRCC_VidEnablePeripheralClock( APB2_BUS , GPIOB_RCC );
	MRCC_VidEnablePeripheralClock( APB2_BUS , AFIO_RCC  );

	MGPIO_VidSetPinDirection( GPIOA , PIN0 , INPUT_PULLUP_PULLDOWN );
	MGPIO_VidSetPinDirection( GPIOB , PIN1 , INPUT_PULLUP_PULLDOWN );
	MGPIO_VidSetPinDirection( GPIOA , PIN2 , INPUT_PULLUP_PULLDOWN );

	MGPIO_VidSetPinValue( GPIOA , PIN0 , HIGH );
	MGPIO_VidSetPinValue( GPIOB , PIN1 , HIGH );
	MGPIO_VidSetPinValue( GPIOA , PIN2 , HIGH );

	MGPIO_VidSetPinDirection( GPIOA , PIN3 , OUTPUT_SPEED_2MHZ_PP );
	MGPIO_VidSetPinDirection( GPIOA , PIN4 , OUTPUT_SPEED_2MHZ_PP );
	MGPIO_VidSetPinDirection( GPIOA , PIN5 , OUTPUT_SPEED_2MHZ_PP );

	MNVIC_VidSetPriority( EXT0 , 1 , NO_SUB_PRIORITY , GROUP3 );
	MNVIC_VidSetPriority( EXT1 , 2 , NO_SUB_PRIORITY , GROUP3 );
	MNVIC_VidSetPriority( EXT2 , 3 , NO_SUB_PRIORITY , GROUP3 );

	MNVIC_VidEnablePeripheral( EXT0 );
	MNVIC_VidEnablePeripheral( EXT1 );
	MNVIC_VidEnablePeripheral( EXT2 );

	AFIO_VidSetEXTIConfiguration( EXTI_LINE0 , GPIOA );
	AFIO_VidSetEXTIConfiguration( EXTI_LINE1 , GPIOB );
	AFIO_VidSetEXTIConfiguration( EXTI_LINE2 , GPIOA );

	EXTI0_VidSetCallBack( EXT0_CALLBACK );
	EXTI1_VidSetCallBack( EXT1_CALLBACK );
	EXTI2_VidSetCallBack( EXT2_CALLBACK );

	EXTI_VidInit( EXTI_LINE0 , FALLING_EDGE );
	EXTI_VidInit( EXTI_LINE1 , FALLING_EDGE );
	EXTI_VidInit( EXTI_LINE2 , FALLING_EDGE );

	while(1);

	return 0;
}







