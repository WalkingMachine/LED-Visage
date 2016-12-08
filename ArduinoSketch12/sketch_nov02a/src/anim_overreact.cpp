#include "sara_face_led_driver.h"
#include "anim_overreact.h"
#include "anim_basic.h"

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

void init_emotion(void)
{
 /* initialize random seed: */
  srand (4);
}
 
void mouth_surprise(uint8_t R,uint8_t G,uint8_t B)
{
 for(uint8_t i=1; i<=3;i++){
 set_mouth( 2, i, R, G, B);
 }
set_mouth( 3, 1, R, G, B);
set_mouth( 3, 3, R, G, B);
set_mouth( 4, 2, R, G, B);
set_mouth( 4, 6, R, G, B);
set_mouth( 5, 1, R, G, B);
set_mouth( 5, 3, R, G, B);
set_mouth( 6, 2, R, G, B);
set_mouth( 6, 6, R, G, B);
set_mouth( 7, 1, R, G, B);
set_mouth( 7, 3, R, G, B);
for(uint8_t i=1; i<=3;i++){
 set_mouth( 8, i, R, G, B);
 }
}

void emo_ciconspect()
{
	clearPixels();
	set_eye( eye_t::left, 255,20,147);
	set_eye( eye_t::right, 255,20,147);
	mouth_surprise(50,50,50);
	pixel_show();
}

void emo_party()
{
  #if 0
  /*Émotion : Party*********************************************/
  eye( eye_t::left, 255,20,147);
  eye( eye_t::right, 255,20,147);
  bouche_fermee(255,20,147);
  delay(100);
  bouche_vide();
  eye( eye_t::left, 0,245,255);
  eye( eye_t::right, 0,245,255);
  petite_bouche(0,245,255);
  delay(100);
  bouche_vide();
  eye( eye_t::left, 127,255,0);
  eye( eye_t::right, 127,255,0);
  grande_bouche(127,255,0);
  delay(100);
  bouche_vide();
  theaterChase(pixels.Color(127, 127, 127), 100); // White
  theaterChase(pixels.Color(127, 0, 0), 100); // Red
  theaterChase(pixels.Color(0, 0, 127), 100); // Blue
  #else
  //uint8_t LEhasard = rand() % 10 +1;
  uint8_t randomRed, randomGreen, randomBlue;
  randomRed=rand() % 150 ;
  randomGreen=rand() % 150 ;
  randomBlue=rand() % 20 ;
  #define ARRAY_LINEON 20
  #define TIMEDELAY 50
  #define CHANCE_CHOSE 3
  for(uint8_t i=0; i < ARRAY_LINEON; i++)
  {
	  set_pixel_color(rand() % NUMPIXELS,0,randomGreen ,randomBlue );
  }
  //set_pixel_color(rand() % NUMPIXELS,randomRed,randomGreen ,randomBlue );
  //delay(200);
  if(4 == rand()%8)
 {
  for(uint8_t i=0; i < ARRAY_LINEON*2; i++)
  {
	  set_pixel_color(rand() % NUMPIXELS,0 ,0 ,0 );
  }
 }
  
  if(6 == rand()%10)
  {
	  switch(rand()%4)
	  {
		  case 0:
			  /*Émotion : Triste*********************************************/
			  clearPixels();
			  //bouche_vide();
			  if(rand()%CHANCE_CHOSE==0)
			  set_eye(eye_t::left,50,0,0);
			  if(rand()%CHANCE_CHOSE==0)
			  set_eye(eye_t::right,50,0,0);
			  if(rand()%CHANCE_CHOSE==0)
			  smile(50,0,0);
			  pixel_show();
			break;
	      case 1:
			//break;
		  case 2:
		   clearPixels();
		   //bouche_vide();
		   if(rand()%CHANCE_CHOSE==0)
			set_eye(eye_t::left,50,0,0);
			if(rand()%CHANCE_CHOSE==0)
			set_eye(eye_t::right,50,0,0);
			if(rand()%CHANCE_CHOSE==0)
		sad(50,0,0);
		   pixel_show();
			break;
		  case 3:
		    clearPixels();
		    //bouche_vide();
		    if(rand()%CHANCE_CHOSE==0)
			set_eye(eye_t::left,50,0,0);
			if(rand()%CHANCE_CHOSE==0)
			set_eye(eye_t::right,50,0,0);
			if(rand()%CHANCE_CHOSE==0)
		    mouth_surprise(50,0,0);
		    pixel_show();
			break;
		  default:
		    break;
	  }
  }
  
  
  pixel_show();
  delay(rand() % TIMEDELAY);
  #endif
}

void emo_party_red()
{
	#if 0
	/*Émotion : Party*********************************************/
	eye( eye_t::left, 255,20,147);
	eye( eye_t::right, 255,20,147);
	bouche_fermee(255,20,147);
	delay(100);
	bouche_vide();
	eye( eye_t::left, 0,245,255);
	eye( eye_t::right, 0,245,255);
	petite_bouche(0,245,255);
	delay(100);
	bouche_vide();
	eye( eye_t::left, 127,255,0);
	eye( eye_t::right, 127,255,0);
	grande_bouche(127,255,0);
	delay(100);
	bouche_vide();
	theaterChase(pixels.Color(127, 127, 127), 100); // White
	theaterChase(pixels.Color(127, 0, 0), 100); // Red
	theaterChase(pixels.Color(0, 0, 127), 100); // Blue
	#else
	//uint8_t LEhasard = rand() % 10 +1;
	uint8_t randomRed, randomGreen, randomBlue;
	randomRed=rand() % 150 ;
	randomGreen=rand() % 150 ;
	randomBlue=rand() % 20 ;
	#define ARRAY_LINEON 10
	#define TIMEDELAY 50
	#define CHANCE_CHOSE 3
	for(uint8_t i=0; i < ARRAY_LINEON; i++)
	{
		set_pixel_color(rand() % NUMPIXELS,randomRed,0 ,/*randomBlue*/0 );
	}
	//set_pixel_color(rand() % NUMPIXELS,randomRed,randomGreen ,randomBlue );
	//delay(200);
	if(1 == rand()%4)
	{
		for(uint8_t i=0; i < ARRAY_LINEON*3; i++)
		{
			set_pixel_color(rand() % NUMPIXELS,0 ,0 ,0 );
		}
	}
	
	if(0 == rand()%4)
	{
		switch(rand()%4)
		{
			case 0:
			/*Émotion : Triste*********************************************/
			clearPixels();
			//bouche_vide();
			if(rand()%CHANCE_CHOSE==0)
			set_eye(eye_t::left,50,0,0);
			if(rand()%CHANCE_CHOSE==0)
			set_eye(eye_t::right,50,0,0);
			if(rand()%CHANCE_CHOSE==0)
			smile(50,0,0);
			pixel_show();
			break;
			case 1:
			//break;
			case 2:
			clearPixels();
			//bouche_vide();
			if(rand()%CHANCE_CHOSE==0)
			set_eye(eye_t::left,50,0,0);
			if(rand()%CHANCE_CHOSE==0)
			set_eye(eye_t::right,50,0,0);
			if(rand()%CHANCE_CHOSE==0)
			sad(50,0,0);
			pixel_show();
			break;
			case 3:
			clearPixels();
			//bouche_vide();
			if(rand()%CHANCE_CHOSE==0)
			set_eye(eye_t::left,50,0,0);
			if(rand()%CHANCE_CHOSE==0)
			set_eye(eye_t::right,50,0,0);
			if(rand()%CHANCE_CHOSE==0)
			mouth_surprise(50,0,0);
			pixel_show();
			break;
			default:
			break;
		}
	}
	
	
	pixel_show();
	delay(rand() % TIMEDELAY);
	#endif
}
#if 0
void petite_bouche(uint8_t R,uint8_t G,uint8_t B){
   pixels.setPixelColor(BASE_BOUCHE + 12, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 34, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 38, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 47, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 46, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 45, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 41, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 24, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 20, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 12, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 13, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 14, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 15, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 16, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 17, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 18, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 19, pixels.Color(R,G,B));
   pixels.setPixelColor(BASE_BOUCHE + 20, pixels.Color(R,G,B));
   pixels.show();
  }
#endif