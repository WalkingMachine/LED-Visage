
// ----------------------------------------------------------------------------

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>


#include "diag/Trace.h"


/* HAL Drivers Includes ------------------------------------------------------*/
#include "stm32f4xx.h"
#include "stm32f4xx_hal_rcc.h"
#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx_hal_tim.h"
#include "system_stm32f4xx.h"

/*MX Cube*/
#include "stm32f4xx_it.h"

/* Personal Includes ---------------------------------------------------------*/
/*#include "FreeRTOS.h"
#include "semphr.h"
#include "task.h"*/

#include "Timer.h"


/************************************/
/************ PROTOYPES *************/
/************************************/

/*Global Variables*/

/*******MAIN********/
int main( ){
	uint8_t WHITE[] = {0xff, 0xff, 0xff};

	HAL_DMA_StateTypeDef i;
	uint32_t j,k = 0;
	/*Initialize the system*/
	SystemInit() ;

	SystemClock_Config();
	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	HAL_MspInit();

	ws2812Init(TIMING_ZERO);



	while(1){
	  i = DMA1->HISR;
	  j = DMA1_Stream7->NDTR;
	  k = NVIC_GetActive(TIM4_IRQn);
	  ws2812Send(&WHITE, NB_LEDS);
	}

	return EXIT_SUCCESS;
}

/*
void vApplicationTickHook(void){

}
void vApplicationStackOverflowHook(TaskHandle_t pxTask, char *pcTaskName){

}
void vApplicationMallocFailedHook(void){

}
void vApplicationIdleHook(void){

}

*/

