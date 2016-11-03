/*
 * sara_face_led_driver.h
 *
 * Created: 2016-11-03 09:17:18
 *  Author: Salco
 */ 


#ifndef SARA_FACE_LED_DRIVER_H_
#define SARA_FACE_LED_DRIVER_H_
#include <Arduino.h>
#include <stdint.h>
#include <Adafruit_NeoPixel.h>
//TODO: change that to make a class maybe
#include "sara_face_led_driver_define.h"

void init_NeoPixels(void);

void set_brightness(uint8_t value);

void clearPixels(void);

void eye(uint8_t eyesNumber, uint8_t R,uint8_t G,uint8_t B);

#if 0
void loadingFade();
void loadingRoll2();
#endif
#endif /* SARA_FACE_LED_DRIVER_H_ */