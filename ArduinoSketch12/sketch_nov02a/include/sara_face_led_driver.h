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

void set_pixel_color(uint8_t neoPixel_nbr, uint8_t R, uint8_t G,uint8_t B);

void set_mouth(int col, int row, uint8_t R,uint8_t G,uint8_t B);

void pixel_show(void);

/**
 * Fonction utiliser afin d'avoir la valeur numerique reel selon la position dans la matrice virtuel.
 * @param col colomn atitre
 * @param row row atitre
 * @return Renvois la valeur numerique de la led en question, si impossible renvois -1.
 */
int get_led_number_col(int col, int row);

#endif /* SARA_FACE_LED_DRIVER_H_ */