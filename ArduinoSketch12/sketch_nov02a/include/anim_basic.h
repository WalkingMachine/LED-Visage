/*
 * anim_basic.h
 *
 * Created: 2016-11-30 14:44:18
 *  Author: Salco
 */ 


#ifndef ANIM_BASIC_H_
#define ANIM_BASIC_H_

#include "anim.h"

void eye(uint8_t eyesNumber, uint8_t R,uint8_t G,uint8_t B);

#define MAX_FRAME_eye_roll_bar

void eye_roll_bar(eye_t eye_chose, uint8_t sequence _nbr, uint8_t R,uint8_t G,uint8_t B);

void eye_look_at(eye_t eye_chose, uint8_t eye_direction, uint8_t width, uint8_t R,uint8_t G,uint8_t B);

void smile(uint8_t R,uint8_t G,uint8_t B);
#if 0
void loadingFade();
void loadingRoll2();
#endif

#endif /* ANIM_BASIC_H_ */