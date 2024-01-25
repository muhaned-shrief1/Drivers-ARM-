/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/


#include "TYPES.h"
#include "MACROS.h"

#include "RCC_INTERFACE.h"
#include "GPIO_INTERFACE.h"
#include "GPIO_REG.h"

#include "RTOS_INTERFACE.h"

void LED1 ( void );
void LED2 ( void );
void LED3 ( void );

int main(void)
{

	MRCC_VidInit();
	MRCC_VidEnablePeripheralClock( APB2_BUS , GPIOA_RCC );

	MGPIO_VidSetPinDirection( GPIOA , PIN0 , OUTPUT_SPEED_2MHZ_PP );
	MGPIO_VidSetPinDirection( GPIOA , PIN1 , OUTPUT_SPEED_2MHZ_PP );
	MGPIO_VidSetPinDirection( GPIOA , PIN2 , OUTPUT_SPEED_2MHZ_PP );

	RTOS_VidCreateTask( 0 , 1000 , LED1 , 0 );
	RTOS_VidCreateTask( 1 , 2000 , LED2 , 0 );
	RTOS_VidCreateTask( 2 , 3000 , LED3 , 0 );

	RTOS_VidStart();

	while(1);

	return 0;
}



void LED1 ( void ){

	TOG_BIT( MGPIOA->ODR , PIN0 );

}

void LED2 ( void ){

	TOG_BIT( MGPIOA->ODR , PIN1 );

}

void LED3 ( void ){

	TOG_BIT( MGPIOA->ODR , PIN2 );

}
