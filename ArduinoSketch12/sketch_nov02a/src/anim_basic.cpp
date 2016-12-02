/*
 * anim_basic.cpp
 *
 * Created: 2016-12-01 10:29:34
 *  Author: Salco
 */ 
#include "sara_face_led_driver.h"
#include "anim_basic.h"

	void smile(uint8_t R,uint8_t G,uint8_t B)
{
set_pixel_color(BASE_BOUCHE + 11,R,G,B);
	set_pixel_color(BASE_BOUCHE + 12,R,G,B);
	set_pixel_color(BASE_BOUCHE + 34,R,G,B);
	set_pixel_color(BASE_BOUCHE + 38,R,G,B);
	set_pixel_color(BASE_BOUCHE + 47,R,G,B);
	set_pixel_color(BASE_BOUCHE + 46,R,G,B);
	set_pixel_color(BASE_BOUCHE + 45,R,G,B);
	set_pixel_color(BASE_BOUCHE + 41,R,G,B);
	set_pixel_color(BASE_BOUCHE + 24,R,G,B);
	set_pixel_color(BASE_BOUCHE + 20, R,G,B);
	set_pixel_color(BASE_BOUCHE + 35, R,G,B);
	set_pixel_color(BASE_BOUCHE + 37, R,G,B);
	set_pixel_color(BASE_BOUCHE + 48, R,G,B);
	set_pixel_color(BASE_BOUCHE + 49, R,G,B);
	set_pixel_color(BASE_BOUCHE + 50, R,G,B);
	set_pixel_color(BASE_BOUCHE + 44, R,G,B);
	set_pixel_color(BASE_BOUCHE + 43, R,G,B);
	set_pixel_color(BASE_BOUCHE + 42, R,G,B);
	set_pixel_color(BASE_BOUCHE + 23, R,G,B);
	set_pixel_color(BASE_BOUCHE + 21, R,G,B);
	set_pixel_color(BASE_BOUCHE + 23, R,G,B);
	pixels->show();
}

#if 0


 void loadingFade()
 {
	 int OEIL_1 = 0;
	 int OEIL_2 = 14;
	 int wait = 5;
	 for(int j = 0; j <= 150; j++)
	 {
		 for(int i=OEIL_1; i<(OEIL_1+14); i++)
		 {
			 set_pixel_color(i, j,j,j);
		 }
		 for(int i=OEIL_2; i<(OEIL_2+14); i++)
		 {
			 set_pixel_color(i, j,j,j);
		 }
		 pixels->show();
		 delay(wait);
	 }

	 for(int j = 150; j >= 0; j--)
	 {
		 for(int i=OEIL_1; i<(OEIL_1+14); i++)
		 {
			 set_pixel_color(i, j,j,j);
		 }
		 for(int i=OEIL_2; i<(OEIL_2+14); i++)
		 {
			 set_pixel_color(i, j,j,j);
		 }
		 pixels->show();
		 delay(wait);
	 }
 }


 void loadingRoll2()
 {
	 int OEIL_1 = 0;
	 int OEIL_2 = 14+7;
	 int wait = 100;
	 
	 for(int PositionCercle = 14; PositionCercle > 0; PositionCercle--)
	 {
		 // Oeil droit
		 for(int i = 0; i < 14; i++)
		 {
			 set_pixel_color((i+PositionCercle)%14, i*5,i*5,75);
		 }
		 // Oeil gauche
		 for(int i = 0; i < 14; i++)
		 {
			 int pos = (i+PositionCercle)%14;
			 
			 if(pos >= 7)
			 {
				 set_pixel_color(pos + 7, i*5,i*5,75);
			 }
			 else
			 {
				 set_pixel_color(pos + 21, i*5,i*5,75);
			 }
		 }
		 
		 pixels->show();
		 delay(wait);
	 }
 }

 void openFade()
 {
	 for(int i = 0; i < 60; i++)
	 {
		 for(int oeil = 0; oeil < EYEPIXELS*2; oeil++)
		 {
			 set_pixel_color(oeil, i,i,i);
		 }
		 pixels.show();
		 delay(20);
		 smile(i,i,i);
		 pixels.show();
	 }
	 delay(1000);
 }

 void loadingFade()

 {
	 int OEIL_1 = 0;
	 int OEIL_2 = 14;
	 int wait = 5;
	 for(int j = 0; j <= 150; j++)
	 {
		 for(int i=OEIL_1; i<(OEIL_1+14); i++)
		 {
			 set_pixel_color(i, j,j,j);
		 }
		 for(int i=OEIL_2; i<(OEIL_2+14); i++)
		 {
			 set_pixel_color(i, j,j,j);
		 }
		 pixels.show();
		 delay(wait);
	 }
	 for(int j = 150; j >= 0; j--)
	 {
		 for(int i=OEIL_1; i<(OEIL_1+14); i++)
		 {
			 set_pixel_color(i, j,j,j);
		 }
		 for(int i=OEIL_2; i<(OEIL_2+14); i++)
		 {
			 set_pixel_color(i, j,j,j);
		 }
		 pixels.show();
		 delay(wait);
	 }
 }
#endif

void eye(uint8_t eyesNumber, uint8_t R,uint8_t G,uint8_t B){
	
	for(int i=(eyesNumber==1?0:EYEPIXELS), j=(eyesNumber==1?EYEPIXELS:EYEPIXELS*2); i<j; i++) {
		// pixels->Color takes RGB values, from 0,0,0 up to 255,255,255
		set_pixel_color(i, R,G,B);
		pixel_show();
	}
}

void eye_roll_bar(eye_t eye_chose, uint8_t sequence _nbr, uint8_t R,uint8_t G,uint8_t B)
{
 sequence_nbr %= MAX_FRAME_eye_roll_bar;

uint_t led_position = (eye_chose==eye_t::left ? BASE_LEFT_EYE : BASE_RIGHT_EYE);
led_position = (led_position + sequence_nbr)% EYEPIXELS;

set_pixel_color(led_position,R, G,B);

}

void eye_look_at(eye_t eye_chose, uint8_t eye_direction, uint8_t width, uint8_t R,uint8_t G,uint8_t B)
{

width %= EYEPIXELS;

uint_t led_position = (eye_chose==eye_t::left ? BASE_LEFT_EYE : BASE_RIGHT_EYE);

led_position = (led_position + eye_direction)% EYEPIXELS;

uint8_t led_position_start_at = (led_position + (width/2))% EYEPIXELS;

uint8_t led_position_stop_at = (led_position - (width/2))% EYEPIXELS;


for( uint8_t position = led_position_start_at;
 position == led_position_stop_at; position=(position-1)% EYEPIXELS)
{

set_pixel_color(position,R, G,B);

}
set_pixel_color(led_position_stop_at,R, G,B);
}