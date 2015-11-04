/*
 * Timer.c

 *
 *  Created on: 2015-09-12
 *      Author: Samuel Otis
 */

<<<<<<< HEAD
<<<<<<< HEAD
#include <string.h>
#include "Timer.h"

/*#include "FreeRTOS.h"
#include "semphr.h"*/



//static xSemaphoreHandle allLedDone = NULL;
=======
=======
>>>>>>> parent of 16f6231... DMA mis en place, mauvaise valeur transférée dans TIM4_CCR3
#include "Timer.h"

#define PERIOD 105
#define TIMING_ONE  75
#define TIMING_ZERO 29


static int CycleCount = 0;
static int ResetFlag = 0;
static int ResetCount =0;
static int All_LEDs_Done;
<<<<<<< HEAD
>>>>>>> parent of 16f6231... DMA mis en place, mauvaise valeur transférée dans TIM4_CCR3
=======
>>>>>>> parent of 16f6231... DMA mis en place, mauvaise valeur transférée dans TIM4_CCR3

/*D�claration des variables de configuration*/
static GPIO_InitTypeDef GPIO_InitStruct;
static TIM_HandleTypeDef htim4;
static TIM_OC_InitTypeDef PWMConfig;
static DMA_HandleTypeDef hdma1;
static int IN_IRQ = 0;

static union {
	uint8_t buffer[2*LED_PER_HALF*24];
	struct {
		uint8_t begin[LED_PER_HALF*24];
		uint8_t end[LED_PER_HALF*24];
	} __attribute__((packed));
} led_dma;

void ws2812Init(uint32_t duty_cycle){

	__GPIOD_CLK_ENABLE();
	/* GPIOD Configuration: TIM4 Channel 1-2-3-4 as alternate function push-pull */
	GPIO_InitStruct.Pin = GPIO_PIN_14|GPIO_PIN_15;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
	GPIO_InitStruct.Alternate = GPIO_AF2_TIM4;
	HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_13;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
	HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

	__TIM4_CLK_ENABLE();
	/* Time base configuration */
	htim4.Init.Prescaler = 0;  /*The counter will use 84 MHz clock*/
	htim4.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim4.Instance = TIM4;
	htim4.Init.Period = PERIOD - 1; /*The counter will operate at 800 kHZ*/
	htim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim4.Init.RepetitionCounter = 0;

	HAL_TIM_PWM_Init(&htim4);
	/* PWM1 Mode configuration: Channel3 */
	PWMConfig.OCMode = TIM_OCMODE_PWM1;
	PWMConfig.OCIdleState = TIM_OCIDLESTATE_RESET;
	PWMConfig.Pulse = (duty_cycle -1); /* 68% duty cycle */
	PWMConfig.OCPolarity = TIM_OCPOLARITY_HIGH;
	PWMConfig.OCNPolarity = TIM_OCNPOLARITY_HIGH;
	PWMConfig.OCNIdleState = TIM_OCNIDLESTATE_RESET;
	PWMConfig.OCFastMode = TIM_OCFAST_DISABLE;
	HAL_TIM_PWM_Init(&htim4);
	HAL_TIM_PWM_ConfigChannel(&htim4, &PWMConfig, TIM_CHANNEL_3);

	/* configure DMA */
	/* DMA clock enable */
	__DMA1_CLK_ENABLE();

	hdma1.Instance = DMA1_Stream7;
	hdma1.Init.Channel = DMA_CHANNEL_2;
	hdma1.Init.Direction = DMA_MEMORY_TO_PERIPH;
	hdma1.Init.PeriphInc = DMA_PINC_DISABLE;
	hdma1.Init.MemInc = DMA_MINC_ENABLE;
	hdma1.Init.PeriphDataAlignment = DMA_PDATAALIGN_HALFWORD;
	hdma1.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
	hdma1.Init.Mode = DMA_CIRCULAR;
	hdma1.Init.Priority = DMA_PRIORITY_HIGH;
	hdma1.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
	htim4.hdma[TIM_DMA_ID_CC3]=&hdma1;
	HAL_DMA_Init(&hdma1);
	HAL_TIM_PWM_Start_DMA(&htim4,TIM_CHANNEL_3,(uint32_t)led_dma.buffer,sizeof(led_dma.buffer));
	DMA1_Stream7->PAR = (uint32_t)&TIM4->CCR3;
	DMA1_Stream7->M0AR = (uint32_t)led_dma.buffer;

	HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_0);
	HAL_NVIC_SetPriority(DMA1_Stream7_IRQn,0,0);
	NVIC_EnableIRQ(DMA1_Stream7_IRQn);

	//vSemaphoreCreateBinary(allLedDone);
}

static void fillLed(uint16_t *buffer, uint8_t *color)
{
    int i;

    for(i=0; i<8; i++) // GREEN data
	{
	    buffer[i] = ((color[1]<<i) & 0x0080) ? TIMING_ONE:TIMING_ZERO;
	}
	for(i=0; i<8; i++) // RED
	{
	    buffer[8+i] = ((color[0]<<i) & 0x0080) ? TIMING_ONE:TIMING_ZERO;
	}
	for(i=0; i<8; i++) // BLUE
	{
	    buffer[16+i] = ((color[2]<<i) & 0x0080) ? TIMING_ONE:TIMING_ZERO;
	}
}

static int current_led = 0;
static int total_led = 0;
static uint8_t (*color_led)[3] = NULL;

void SystemClock_Config(void)
{

	RCC_OscInitTypeDef RCC_OscInitStruct;
	RCC_ClkInitTypeDef RCC_ClkInitStruct;

	__PWR_CLK_ENABLE();

	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.HSICalibrationValue = 16;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
	RCC_OscInitStruct.PLL.PLLM = 16;
	RCC_OscInitStruct.PLL.PLLN = 336;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
	RCC_OscInitStruct.PLL.PLLQ = 4;
	HAL_RCC_OscConfig(&RCC_OscInitStruct);

	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_SYSCLK|RCC_CLOCKTYPE_PCLK1;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
	HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2);

	HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

	HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

}

<<<<<<< HEAD
<<<<<<< HEAD
void ws2812Send(uint8_t (*color)[3], int len)
{
    int i;
	if(len<1) return;

	//Wait for previous transfer to be finished
	//xSemaphoreTake(allLedDone, portMAX_DELAY);

	// Set interrupt context ...
	current_led = 0;
	total_led = len;
	color_led = color;

    for(i=0; (i<LED_PER_HALF) && (current_led<total_led+2); i++, current_led++) {
        if (current_led<total_led)
            fillLed(led_dma.begin+(24*i), color_led[current_led]);
        else
            bzero(led_dma.begin+(24*i), 24);
    }

    for(i=0; (i<LED_PER_HALF) && (current_led<total_led+2); i++, current_led++) {
        if (current_led<total_led)
            fillLed(led_dma.end+(24*i), color_led[current_led]);
        else
            bzero(led_dma.end+(24*i), 24);
    }
		HAL_TIM_PWM_Start_DMA(&htim4,TIM_CHANNEL_3,(uint32_t)led_dma.buffer,sizeof(led_dma.buffer));// enable DMA channel 3
		__TIM4_CLK_ENABLE();                      // Go!!!
}

void ws2812DmaIsr(void){
	//portBASE_TYPE xHigherPriorityTaskWoken;
	static  uint8_t DMA_finished = 0;
	uint16_t * buffer;
	int i;



	    if (total_led == 0)
	    {
	    	__TIM4_CLK_DISABLE();
	    	DMA1_Stream7->CR &=  ~DMA_SxCR_EN; //DMA1 Stream7 Disabled
	    }

	    if (DMA1->HISR & DMA_FLAG_HTIF3_7)
	    {
	    	DMA1->HIFCR = DMA1->HIFCR | DMA_FLAG_HTIF3_7;//(DMA1->HIFCR = DMA_FLAG_HTIF3_7;)
	    	buffer = led_dma.begin;
	    }

	    if (DMA1->HISR & DMA_FLAG_TCIF3_7)
	    {
	    	DMA1->HIFCR = DMA1->HIFCR | DMA_FLAG_TCIF3_7;//DMA1->HIFCR = DMA_FLAG_TCIF3_7;
	    	buffer = led_dma.end;
	    }

	    for(i=0; (i<LED_PER_HALF) && (current_led<total_led+2); i++, current_led++) {
	      if (current_led<total_led)
	          fillLed(buffer+(24*i), color_led[current_led]);
	      else
	          bzero(buffer+(24*i), sizeof(led_dma.end));
	    }

		if (current_led >= total_led+2) {
		//	xSemaphoreGiveFromISR(allLedDone, &xHigherPriorityTaskWoken);
			__TIM4_CLK_DISABLE();
			DMA1_Stream7->CR &=  ~DMA_SxCR_EN; //DMA1 Stream7 Disabled
			total_led = 0;
		}







=======
void Modify_PWM(uint32_t duty_cycle){
	TIM4->CCR3 = (duty_cycle -1); /* 68% duty cycle */
}

void ws2812DmaIsr(void){
=======
void Modify_PWM(uint32_t duty_cycle){
	TIM4->CCR3 = (duty_cycle -1); /* 68% duty cycle */
}

void ws2812DmaIsr(void){
>>>>>>> parent of 16f6231... DMA mis en place, mauvaise valeur transférée dans TIM4_CCR3
	NVIC_ClearPendingIRQ(DMA1_Stream7_IRQn);
	DMA1->HIFCR = 0;
	DMA1->LIFCR = 0;
	DMA1->HISR = 0;
	DMA1->LISR = 0;
	fillLed(&(led_dma.buffer),&color_led);
<<<<<<< HEAD
>>>>>>> parent of 16f6231... DMA mis en place, mauvaise valeur transférée dans TIM4_CCR3
=======
>>>>>>> parent of 16f6231... DMA mis en place, mauvaise valeur transférée dans TIM4_CCR3
}

void DMA1_Stream7_IRQHandler(void)
{
	ws2812DmaIsr();
	IN_IRQ = 1;
}



