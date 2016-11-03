/*
 * CPPFile1.cpp
 *
 * Created: 2016-11-03 09:16:34
 *  Author: Salco
 */ 
#include "sara_face_led_driver.h"

Adafruit_NeoPixel *pixels; //= Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void init_NeoPixels(void)
{
	pixels = new Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
	pixels->begin(); // This initializes the NeoPixel library.
    pixels->setBrightness(DEFAULT_BRIGHTNESS);
	clearPixels();
	pixels->show();
}

void clearPixels(void)
{
	for(int i=0; i < NUMPIXELS; i++)
	{
		pixels->setPixelColor(i,pixels->Color(0,0,0));
	}
}

void pixel_show(void)
{
	pixels->show();
}

void set_brightness(const /*std_msgs::UInt8*/uint8_t& value)
{
	pixels->setBrightness(value);
	pixels->show();
	
}

void eye(uint8_t eyesNumber, uint8_t R,uint8_t G,uint8_t B){
	
	for(int i=(eyesNumber=1?0:EYEPIXELS), j=(eyesNumber=1?EYEPIXELS:EYEPIXELS*2); i<j; i++) {
		// pixels->Color takes RGB values, from 0,0,0 up to 255,255,255
		pixels->setPixelColor(i, pixels->Color(R,G,B));
		pixels->show();
	}
}



#if 0
void smile(uint8_t R,uint8_t G,uint8_t B){
	pixels->setPixelColor(BASE_BOUCHE + 11, pixels->Color(R,G,B));
	pixels->setPixelColor(BASE_BOUCHE + 12, pixels->Color(R,G,B));
	pixels->setPixelColor(BASE_BOUCHE + 34, pixels->Color(R,G,B));
	pixels->setPixelColor(BASE_BOUCHE + 38, pixels->Color(R,G,B));
	pixels->setPixelColor(BASE_BOUCHE + 47, pixels->Color(R,G,B));
	pixels->setPixelColor(BASE_BOUCHE + 46, pixels->Color(R,G,B));
	pixels->setPixelColor(BASE_BOUCHE + 45, pixels->Color(R,G,B));
	pixels->setPixelColor(BASE_BOUCHE + 41, pixels->Color(R,G,B));
	pixels->setPixelColor(BASE_BOUCHE + 24, pixels->Color(R,G,B));
	pixels->setPixelColor(BASE_BOUCHE + 20, pixels->Color(R,G,B));
	pixels->setPixelColor(BASE_BOUCHE + 35, pixels->Color(R,G,B)); 
	pixels->setPixelColor(BASE_BOUCHE + 37, pixels->Color(R,G,B));
	pixels->setPixelColor(BASE_BOUCHE + 48, pixels->Color(R,G,B));
	pixels->setPixelColor(BASE_BOUCHE + 49, pixels->Color(R,G,B));
	pixels->setPixelColor(BASE_BOUCHE + 50, pixels->Color(R,G,B));
	pixels->setPixelColor(BASE_BOUCHE + 44, pixels->Color(R,G,B));
	pixels->setPixelColor(BASE_BOUCHE + 43, pixels->Color(R,G,B));
	pixels->setPixelColor(BASE_BOUCHE + 42, pixels->Color(R,G,B));
	pixels->setPixelColor(BASE_BOUCHE + 23, pixels->Color(R,G,B));
	pixels->setPixelColor(BASE_BOUCHE + 21, pixels->Color(R,G,B));
	pixels->setPixelColor(BASE_BOUCHE + 23, pixels->Color(R,G,B));
	pixels->show();
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
			 pixels->setPixelColor(i, pixels->Color(j,j,j));
		 }
		 for(int i=OEIL_2; i<(OEIL_2+14); i++)
		 {
			 pixels->setPixelColor(i, pixels->Color(j,j,j));
		 }
		 pixels->show();
		 delay(wait);
	 }
	 for(int j = 150; j >= 0; j--)
	 {
		 for(int i=OEIL_1; i<(OEIL_1+14); i++)
		 {
			 pixels->setPixelColor(i, pixels->Color(j,j,j));
		 }
		 for(int i=OEIL_2; i<(OEIL_2+14); i++)
		 {
			 pixels->setPixelColor(i, pixels->Color(j,j,j));
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
			 pixels->setPixelColor((i+PositionCercle)%14, pixels->Color(i*5,i*5,75));
		 }
		 // Oeil gauche
		 for(int i = 0; i < 14; i++)
		 {
			 int pos = (i+PositionCercle)%14;
			 
			 if(pos >= 7)
			 {
				 pixels->setPixelColor(pos + 7, pixels->Color(i*5,i*5,75));
			 }
			 else
			 {
				 pixels->setPixelColor(pos + 21, pixels->Color(i*5,i*5,75));
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
			 pixels.setPixelColor(oeil, pixels.Color(i,i,i));
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
			 pixels.setPixelColor(i, pixels.Color(j,j,j));
		 }
		 for(int i=OEIL_2; i<(OEIL_2+14); i++)
		 {
			 pixels.setPixelColor(i, pixels.Color(j,j,j));
		 }
		 pixels.show();
		 delay(wait);
	 }
	 for(int j = 150; j >= 0; j--)
	 {
		 for(int i=OEIL_1; i<(OEIL_1+14); i++)
		 {
			 pixels.setPixelColor(i, pixels.Color(j,j,j));
		 }
		 for(int i=OEIL_2; i<(OEIL_2+14); i++)
		 {
			 pixels.setPixelColor(i, pixels.Color(j,j,j));
		 }
		 pixels.show();
		 delay(wait);
	 }
 }
#endif
void set_pixel_color(uint8_t neoPixel_nbr, uint8_t R, uint8_t G,uint8_t B)
{
	pixels->setPixelColor(neoPixel_nbr, pixels->Color(R,G,B));
}