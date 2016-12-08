/*
 * anim_basic.cpp
 *
 * Created: 2016-12-01 10:29:34
 *  Author: Salco
 */ 
#include "sara_face_led_driver.h"
#include "anim_basic.h"

#define MAX_EYE_LED_NBR(eye_chose) ((eye_chose==eye_t::left ? BASE_LEFT_EYE : BASE_RIGHT_EYE) + EYEPIXELS)
#define MIN_EYE_LED_NBR(eye_chose) (eye_chose==eye_t::left ? BASE_LEFT_EYE : BASE_RIGHT_EYE)

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
	//pixel_show();
}

void sad(uint8_t R,uint8_t G,uint8_t B){
	set_pixel_color(BASE_BOUCHE + 12, R,G,B);
	set_pixel_color(BASE_BOUCHE + 13, R,G,B);
	set_pixel_color(BASE_BOUCHE + 14, R,G,B);
	set_pixel_color(BASE_BOUCHE + 15, R,G,B);
	set_pixel_color(BASE_BOUCHE + 16, R,G,B);
	set_pixel_color(BASE_BOUCHE + 17, R,G,B);
	set_pixel_color(BASE_BOUCHE + 18, R,G,B);
	set_pixel_color(BASE_BOUCHE + 19, R,G,B);
	set_pixel_color(BASE_BOUCHE + 20, R,G,B);
	//pixels.show();
}


void emo_content()
{
  /*Émotion : Content**********************************************/
  clearPixels();
  eye(eye_t::left,50,50,50);
  eye(eye_t::right,50,50,50);
  //bouche_vide(); //Changer LED3 et LED45
  smile(50,50,50);
  //delay(1000);
  pixel_show();
}
void emo_triste()
{
	/*Émotion : Triste*********************************************/
	clearPixels();
	//bouche_vide();
	eye(eye_t::left,50,50,50);
	eye(eye_t::right,50,50,50);
	sad(0,0,50);
	pixel_show();
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

void eye(eye_t eye_chose, uint8_t R,uint8_t G,uint8_t B){
	
	for(int i=(eye_chose==eye_t::left ? BASE_LEFT_EYE : BASE_RIGHT_EYE), j= i+EYEPIXELS; i<j; i++) {
		// pixels->Color takes RGB values, from 0,0,0 up to 255,255,255
		set_pixel_color(i, R,G,B);
		//pixel_show();
	}
}

void eye_roll_bar(eye_t eye_chose, uint8_t sequence_nbr, uint8_t R,uint8_t G,uint8_t B)
{
 sequence_nbr %= MAX_FRAME_eye_roll_bar;

uint8_t led_position = (eye_chose==eye_t::left ? BASE_LEFT_EYE : BASE_RIGHT_EYE);
	eye(eye_chose,0,0,0);

led_position = (led_position + sequence_nbr)% MAX_EYE_LED_NBR(eye_chose);

set_pixel_color(led_position,R, G,B);

led_position = (led_position + (EYEPIXELS/2))% MAX_EYE_LED_NBR(eye_chose);
set_pixel_color(led_position,R, G,B);
}

void eye_look_at(eye_t eye_chose, uint8_t eye_direction, uint8_t width, uint8_t R,uint8_t G,uint8_t B)
{
	width %= EYEPIXELS; //limit the size
	eye_direction %= (EYEPIXELS); //limit the size
	
	eye_direction+=MIN_EYE_LED_NBR(eye_chose);//adjust to the right eye

	 uint8_t finish = ( eye_direction==0? EYEPIXELS_MINUS_ONE : eye_direction-1); //-1 to ofset else it will re-toggle le first led
	 
	
	uint8_t led_toggle_from =  eye_direction; // equivalent du i , i= start_at
	uint8_t led_position = MIN_EYE_LED_NBR(eye_chose); // equivalent du j , j=counter_to_know_we_dont_pass_EYEPIXELS
	
	uint8_t width_high_limit = MIN_EYE_LED_NBR(eye_chose)+(width/2);
	uint8_t width_low_limit  = MAX_EYE_LED_NBR(eye_chose)-(width/2);
	do 
	{
		if((led_position <= width_high_limit) || (led_position >= width_low_limit))
			set_pixel_color(led_toggle_from,0, 0, 0);
		else
			set_pixel_color(led_toggle_from,R, G, B);
			
		pixel_show();//only for debug purpose
			
		led_position++;
		
		if (led_toggle_from+1 < MAX_EYE_LED_NBR(eye_chose))
		{
			led_toggle_from++;
		} 
		else
		{
			led_toggle_from = MIN_EYE_LED_NBR(eye_chose);
		}
	} while (led_position != MAX_EYE_LED_NBR(eye_chose));//(led_toggle_from != finish eye_direction); 
	
	
}