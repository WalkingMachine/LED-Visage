/*
 * Timer.c
 *
 *  Created on: 2015-09-12
 *      Author: Samuel Otis
 */

#include "Timer.h"

#define PERIOD 105



static int CycleCount = 0;
static int ResetFlag = 0;
static int ResetCount =0;


void TM_TIMER_PWM_Init(uint32_t duty_cycle){

	//TIM_HandleTypeDef htim4;
	//TIM_OC_InitTypeDef PWMConfig;


	__TIM4_CLK_ENABLE();

	htim4.Init.Prescaler = 0;  /*The counter will use 84 MHz clock*/
	htim4.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim4.Instance = TIM4;
	htim4.Init.Period = PERIOD - 1; /*The counter will operate at 800 kHZ*/
	htim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim4.Init.RepetitionCounter = 0;

	HAL_TIM_PWM_Init(&htim4);

	PWMConfig.OCMode = TIM_OCMODE_PWM1;
	PWMConfig.OCIdleState = TIM_OCIDLESTATE_RESET;
	PWMConfig.Pulse = (duty_cycle -1); /* 68% duty cycle */
	PWMConfig.OCPolarity = TIM_OCPOLARITY_HIGH;
	PWMConfig.OCNPolarity = TIM_OCNPOLARITY_HIGH;
	PWMConfig.OCNIdleState = TIM_OCNIDLESTATE_RESET;
	PWMConfig.OCFastMode = TIM_OCFAST_DISABLE;
	HAL_TIM_PWM_ConfigChannel(&htim4, &PWMConfig, TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_3);


	TIM4->CR1 |= TIM_CR1_ARPE | TIM_CR1_CEN;
	TIM4->EGR = 1;
	TIM4->DIER |= (TIM_DIER_UIE | TIM_DIER_CC3IE) ; // enable update interrupt and capture/compare 3


}

void Ini_Interrupt_TIM4(void){

	HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_0);
	HAL_NVIC_SetPriority(TIM4_IRQn,0,0);
	NVIC_EnableIRQ(TIM4_IRQn);
	//NVIC_ClearPendingIRQ(TIM4_IRQn);
}

void TM_LEDS_Init(void){

	GPIO_InitTypeDef GPIO_InitStruct;

	__GPIOD_CLK_ENABLE();

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


}

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

void Modify_PWM(uint32_t duty_cycle){
	TIM4->CCR3 = (duty_cycle -1); /* 68% duty cycle */
}

void TIM4_IRQHandler(void)
{

	NVIC_ClearPendingIRQ(TIM4_IRQn);
	HAL_TIM_IRQHandler(&htim4);
	/* USER CODE BEGIN TIM4_IRQn 0 */

	int i = 0;
	int k = 0;

	//i = NVIC_GetPendingIRQ(TIM4_IRQn);
	//k = NVIC_GetActive(TIM4_IRQn);

	//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET); //Orange LED



		if(CycleCount == MAX_BITS)
		{
			//HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);//Green LED Pour des tests
			CycleCount = 0;
			ResetFlag = 1;
		}

		if(ResetFlag){
			ResetCount++;
			if(ResetCount == 50){
				ResetFlag = 0;
				ResetCount = 0;
			}
			Modify_PWM(PERIOD_RESET);

		} else {
			Modify_PWM(DUTYCYCLE_BIT_1);
			CycleCount++;
		}
	/* USER CODE END TIM4_IRQn 0 */
}



