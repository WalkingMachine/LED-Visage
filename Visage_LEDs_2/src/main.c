
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
#include "Timer.h"


/************************************/
/************ PROTOYPES *************/
/************************************/

/*Global Variables*/


/*******MAIN********/
int main( ){ /*Enlevé les arguments  "int arc, char **argv", ne servent pas dans l'application*/


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







