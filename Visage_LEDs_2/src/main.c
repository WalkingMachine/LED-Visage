
// ----------------------------------------------------------------------------

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
<<<<<<< HEAD


=======
>>>>>>> parent of 16f6231... DMA mis en place, mauvaise valeur transférée dans TIM4_CCR3
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
int main( ){ /*Enlev� les arguments  "int arc, char **argv", ne servent pas dans l'application*/


	uint32_t j,i,k = 0;
	/*Initialize the system*/
	SystemInit() ;

	SystemClock_Config();
	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	HAL_MspInit();

	ws2812Init(DUTYCYCLE_BIT_1);



	while(1){
	  i = NVIC_GetPendingIRQ(TIM4_IRQn);
	  k = NVIC_GetActive(TIM4_IRQn);
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

