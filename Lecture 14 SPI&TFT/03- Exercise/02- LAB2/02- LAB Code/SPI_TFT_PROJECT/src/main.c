/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/

#include "TYPES.h"

#include "RCC_INTERFACE.h"
#include "GPIO_INTERFACE.h"
#include "SPI_INTERFACE.h"

#include "TFT_INTERFACE.h"

#include "Images.h"

int main ( void ){

	MRCC_VidInit();
	MRCC_VidEnablePeripheralClock( APB2_BUS , GPIOA_RCC );
	MRCC_VidEnablePeripheralClock( APB2_BUS , SPI1_RCC  );

	MGPIO_VidSetPinDirection( GPIOA , PIN7 , OUTPUT_SPEED_10MHZ_AFPP );//MOSI
	MGPIO_VidSetPinDirection( GPIOA , PIN5 , OUTPUT_SPEED_10MHZ_AFPP );//CLOCK

	MGPIO_VidSetPinDirection( GPIOA , PIN1 , OUTPUT_SPEED_10MHZ_PP   );//RST
	MGPIO_VidSetPinDirection( GPIOA , PIN2 , OUTPUT_SPEED_10MHZ_PP   );//A0(D/C)

	MSPI_VidInit();

	TFT_VidInit();

	/* Write IMT On TFT */
	TFT_VidFillColor( BLACK );

	u8 I[]     = {0x00, 0x82 , 0xFE , 0x82 , 0x00 } ;
	u8 M[]     = {0xFE, 0x40 , 0x20 , 0x40 , 0xFE } ;
	u8 T[]     = {0x80, 0x80 , 0xFE , 0x80 , 0x80 } ;
	u8 SPACE[] = {0x00, 0x00 , 0x00 , 0x00 , 0x00 } ;
	u8 S[]     = {0x70, 0x92 , 0x92 , 0x92 , 0x9E } ;
	u8 C[]     = {0x7C, 0x82 , 0x82 , 0x82 , 0x82 } ;
	u8 O[]     = {0x7C, 0x82 , 0x82 , 0x82 , 0x7C } ;
	u8 L[]     = {0xFE, 0x02 , 0x02 , 0x02 , 0x02 } ;

	TFT_VidWriteChar ( I     , 0  , 0 , MAGENTA   );
	TFT_VidWriteChar ( M     , 6  , 0 , GREEN     );
	TFT_VidWriteChar ( T     , 12 , 0 , RED       );
	TFT_VidWriteChar ( SPACE , 18 , 0 , WHITE     );
	TFT_VidWriteChar ( S     , 24 , 0 , BLUE      );
	TFT_VidWriteChar ( C     , 30 , 0 , LIME      );
	TFT_VidWriteChar ( O     , 36 , 0 , YELLOW    );
	TFT_VidWriteChar ( O     , 42 , 0 , MAGENTA   );
	TFT_VidWriteChar ( L     , 48 , 0 , GREEN     );


	while(1);

	return 0 ;
}