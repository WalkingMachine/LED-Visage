
#ifndef TIMER_H
#define TIMER_H
#include "cmsis_device.h"
#include "stm32f4xx_hal_tim.h"
#include "stm32f4xx_hal_dma.h"

//10 LEDs avec 24 bits pour chaque LEDDD
#define MAX_BITS 2
#define DUTYCYCLE_BIT_1 67
#define DUTYCYCLE_BIT_0 28
#define PERIOD_RESET 0
#define NB_LEDS 20
#define LED_PER_HALF 1



void SystemClock_Config(void);
void ws2812Init(uint32_t duty_cycle);
void Modify_PWM(uint32_t duty_cycle);
void HAL_MspInit(void);

//Timer Handler
void TIM4_IRQHandler(void);



#endif
