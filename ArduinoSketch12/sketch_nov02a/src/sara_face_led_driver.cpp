/*
 * sara_face_led_driver.cpp
 *
 * Created: 2016-11-03 09:16:34
 *  Author: Salco
 */ 
#include "sara_face_led_driver.h"

Adafruit_NeoPixel *pixels; //= Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void init_NeoPixels(void)
{
  if(pixels = voidptr)
    {
	     pixels = new Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
    }
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

void set_pixel_color(uint8_t neoPixel_nbr, uint8_t R, uint8_t G,uint8_t B)
{
	pixels->setPixelColor(neoPixel_nbr, pixels->Color(R,G,B));
}

void set_mouth(int col, int row, uint8_t R,uint8_t G,uint8_t B)
{
	int ledNumber= get_led_number_col(col,row);
	if( ledNumber != -1)
	{
		set_pixel_color(ledNumber,R,G,B);
	}
}

int get_led_number_col(int col, int row)
{
	int result = -1;
	if((col < MAX_MOUTH_COL)&&(row < mouthMaxRow[col]))
	{
		result = mouthLedNbr[col][row];
	}
	
	
	return result;
}
