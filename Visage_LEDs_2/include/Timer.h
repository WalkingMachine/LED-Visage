
#ifndef TIMER_H
#define TIMER_H
#include "cmsis_device.h"
#include "stm32f4xx_hal_tim.h"

TIM_HandleTypeDef htim4;
TIM_OC_InitTypeDef PWMConfig;

//10 LEDs avec 24 bits pour chaque LED
#define MAX_BITS 6
#define DUTYCYCLE_BIT_1 67
#define DUTYCYCLE_BIT_0 28
#define PERIOD_RESET 0
#define NB_LEDS 20



void SystemClock_Config(void);
void TM_TIMER_PWM_Init(uint32_t duty_cycle);
void TM_LEDS_Init(void);
void Ini_Interrupt_TIM4(void);
void Modify_PWM(uint32_t duty_cycle);
void HAL_MspInit(void);

//Timer Handler
void TIM4_IRQHandler(void);



#endif
