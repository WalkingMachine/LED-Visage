
#ifndef TIMER_H
#define TIMER_H
#include "cmsis_device.h"
#include "stm32f4xx_hal_tim.h"
#include "stm32f4xx_hal_dma.h"


#define TIMING_ONE  75
#define TIMING_ZERO 29
#define PERIOD_RESET 0
#define PERIOD 105

#define LED_PER_HALF 4
#define NB_LEDS LED_PER_HALF*2
#define WS2812_DEADPERIOD 19



void SystemClock_Config(void);
void ws2812Init(uint32_t duty_cycle);
void Modify_PWM(uint32_t duty_cycle);
void HAL_MspInit(void);
void ws2812Send(uint8_t (*color)[3], int len);

//Timer Handler
void TIM4_IRQHandler(void);
//DMA Handler
void DMA1_Stream7_IRQHandler(void);
void ws2812DmaIsr(void);

#endif
