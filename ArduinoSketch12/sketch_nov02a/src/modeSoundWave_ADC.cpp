/*
 * modeSoundWave_ADC.cpp
 *
 * Created: 2016-11-03 11:30:36
 *  Author: Salco
 */ 
#include <Arduino.h>
#include <avr/io.h>
#include "avr\interrupt.h"       // pour les interuptions
#include "sara_face_led_driver_define.h"
#include "modeSoundWave_ADC.h"
#include "sara_face_led_driver.h"


/// new code by salco below
//clipping indicator variables
bool clipping = 0;

//data storage variables
uint8_t newDataAdc01 = 0;
uint8_t prevDataAdc01 = 0;

//freq variables
unsigned int time = 0;//keeps time and sends vales to store in timer[] occasionally
int timer[10];//sstorage for timing of events
int slope[10];//storage for slope of events
unsigned int totalTimer;//used to calculate period
unsigned int period;
uint8_t index = 0;//current storage index
int frequency;
int maxSlope = 0;//used to calculate max slope as trigger point
int newSlope;//storage for incoming slope data

//variables for decided whether you have a match
uint8_t noMatch = 0;//counts how many non-matches you've received to reset variables if it's been too long
uint8_t slopeTol = 3;//slope tolerance- adjust this if you need
int timerTol = 10;//timer tolerance- adjust this if you need


//variables for amp detection
unsigned int ampTimer = 0;
uint8_t maxAmp = 0;
uint8_t checkMaxAmp;
uint8_t ampThreshold = 30;//raise if you have a very noisy signal

int incomingAudio;
volatile unsigned char sequence_mouth[6][11][4]={FRAME_MOUTH_01, FRAME_MOUTH_02, FRAME_MOUTH_03, FRAME_MOUTH_04, FRAME_MOUTH_05, FRAME_MOUTH_06 };
int currentFrame = 0;

float voltMax=0;
float past_voltCur=0;
float voltCur=0;
float voltMin=5;
#define CALCULATE_VOLT_MAX(newValue) {voltMax=/*((voltMax+*/newValue/*)/VOLT_MAX_MASK_BUFFER)*/;}
#define CALCULATE_VOLT_CUR(newValue) {past_voltCur=voltCur;voltCur=((voltCur+newValue)/VOLT_CUR_MASK_BUFFER);}
#define CALCULATE_VOLT_MIN(newValue) {voltMin=/*((voltMin*/+newValue/*)/VOLT_MIN_MASK_BUFFER)*/;}
#define WATCHDOG_TENTION_MAX 4
int watchdog_tension_ilde=0;


void init_modeSoundWave_Adc(void)
{
	cli();//diable interrupts
	//set up continuous sampling of analog pin 0 at 38.5kHz

	//clear ADCSRA and ADCSRB registers
	ADCSRA = 0;
	ADCSRB = 0;

	ADMUX |= (1 << REFS0); //set reference voltage
	ADMUX |= (1 << ADLAR); //left align the ADC value- so we can read highest 8 bits from ADCH register only

	ADCSRA |= (1 << ADPS2) | (1 << ADPS0); //set ADC clock with 32 prescaler- 16mHz/32=500kHz
	ADCSRA |= (1 << ADATE); //enabble auto trigger
	ADCSRA |= (1 << ADIE); //enable interrupts when measurement complete
	ADCSRA |= (1 << ADEN); //enable ADC
	ADCSRA |= (1 << ADSC); //start ADC measurements

	sei();//enable interrupts
}

ISR(ADC_vect) {//when new ADC value ready
	
	//PORTB &= B11101111;//set pin 12 low
	prevDataAdc01 = newDataAdc01;//store previous value
	newDataAdc01 = ADCH;//get value from A0
	//calcule amplitude
	CALCULATE_VOLT_CUR((newDataAdc01*5.0)/1024)
	if(voltCur >= voltMax)
	CALCULATE_VOLT_MAX(voltCur)
	if(voltCur <= voltMin )
	CALCULATE_VOLT_MIN(voltCur)
	
	//
	if (prevDataAdc01 < 127 && newDataAdc01 >=127){//if increasing and crossing midpoint
		newSlope = newDataAdc01 - prevDataAdc01;//calculate slope
		if (abs(newSlope-maxSlope)<slopeTol){//if slopes are ==
			//record new data and reset time
			slope[index] = newSlope;
			timer[index] = time;
			time = 0;
			if (index == 0){//new max slope just reset
				//PORTB |= B00010000;//set pin 12 high
				noMatch = 0;
				index++;//increment index
			}
			else if (abs(timer[0]-timer[index])<timerTol && abs(slope[0]-newSlope)<slopeTol){//if timer duration and slopes match
				//sum timer values
				totalTimer = 0;
				for (byte i=0;i<index;i++){
					totalTimer+=timer[i];
				}
				period = totalTimer;//set period
				//reset new zero index values to compare with
				timer[0] = timer[index];
				slope[0] = slope[index];
				index = 1;//set index to 1
				//PORTB |= B00010000;//set pin 12 high
				noMatch = 0;
				//clear max min and cur volt
				voltMax=0;
				voltMin=5;
				voltCur=0;
			}
			else{//crossing midpoint but not match
				index++;//increment index
				if (index > 9){
					reset();
				}
			}
		}
		else if (newSlope>maxSlope){//if new slope is much larger than max slope
			maxSlope = newSlope;
			time = 0;//reset clock
			noMatch = 0;
			index = 0;//reset index
		}
		else{//slope not steep enough
			noMatch++;//increment no match counter
			if (noMatch>9){
				reset();
			}
		}
	}
	
	if (newDataAdc01 == 0 || newDataAdc01 == 1023){//if clipping
		//PORTB |= B00100000;//set pin 13 high- turn on clipping indicator led
		clipping = 1;//currently clipping
	}
	
	time++;//increment timer at rate of 38.5kHz
	
	ampTimer++;//increment amplitude timer
	if (abs(127-ADCH)>maxAmp){
		maxAmp = abs(127-ADCH);
	}
	if (ampTimer==1000){
		ampTimer = 0;
		checkMaxAmp = maxAmp;
		maxAmp = 0;
	}
}

void reset(void)
{
	//clea out some variables
	index = 0;//reset index
	noMatch = 0;//reset match couner
	maxSlope = 0;//reset slope
}

void checkClipping(void)
{
	//manage clipping indicator LED
	if (clipping){//if currently clipping
		//PORTB &= B11011111;//turn off clipping indicator led
		clipping = 0;
	}
}

//Algo part
int get_led_number_col_1(int row)
{
	int result = DEFAULT_MOUTH_LED_NUMBER;
	switch (row)
	{
		case (1<<0):
		result = 23;
		break;
		case (1<<1):
		result = 22;
		break;
		case (1<<2):
		result = 1;
		break;
	}
	return result;
}
int get_led_number_col_2(int row)
{
	int result = DEFAULT_MOUTH_LED_NUMBER;
	switch (row)
	{
		case (1<<0):
		result = 24;
		break;
		case (1<<1):
		result = 21;
		break;
		case (1<<2):
		result = 2;
		break;
	}
	return result;
}
int get_led_number_col_3(int row)
{
	int result = DEFAULT_MOUTH_LED_NUMBER;
	switch (row)
	{
		case (1<<0):
		result = 43;
		break;
		case (1<<1):
		result = 25;
		break;
		case (1<<2):
		result = 26;
		break;
		case (1<<3):
		result = 20;
		break;
		case (1<<4):
		result = 3;
		break;
	}
	return result;
}
int get_led_number_col_4(int row)
{
	int result = DEFAULT_MOUTH_LED_NUMBER;
	switch (row)
	{
		case (1<<0):
		result = 44;
		break;
		case (1<<1):
		result = 42;
		break;
		case (1<<2):
		result = 27;
		break;
		case (1<<3):
		result = 19;
		break;
		case (1<<4):
		result = 4;
		break;
	}
	return result;
}
int get_led_number_col_5(int row)
{
	int result = DEFAULT_MOUTH_LED_NUMBER;
	switch (row)
	{
		case (1<<0):
		result = 52;
		break;
		case (1<<1):
		result = 45;
		break;
		case (1<<2):
		result = 46;
		break;
		case (1<<3):
		result = 41;
		break;
		case (1<<4):
		result = 28;
		break;
		case (1<<5):
		result = 29;
		break;
		case (1<<6):
		result = 18;
		break;
		case (1<<7):
		result = 5;
		break;
	}
	return result;
}
int get_led_number_col_6(int row)
{
	int result = DEFAULT_MOUTH_LED_NUMBER;
	switch (row)
	{
		case (1<<0):
		result = 51;
		break;
		case (1<<1):
		result = 47;
		break;
		case (1<<2):
		result = 30;
		break;
		case (1<<3):
		result = 17;
		break;
		case (1<<4):
		result = 6;
		break;
	}
	return result;
}
int get_led_number_col_7(int row)
{
	int result = DEFAULT_MOUTH_LED_NUMBER;
	switch (row)
	{
		case (1<<0):
		result = 53;
		break;
		case (1<<1):
		result = 50;
		break;
		case (1<<2):
		result = 48;
		break;
		case (1<<3):
		result = 40;
		break;
		case (1<<4):
		result = 31;
		break;
		case (1<<5):
		result = 32;
		break;
		case (1<<6):
		result = 16;
		break;
		case (1<<7):
		result = 7;
		break;
	}
	return result;
}
int get_led_number_col_8(int row)
{
	int result = DEFAULT_MOUTH_LED_NUMBER;
	switch (row)
	{
		case (1<<0):
		result = 49;
		break;
		case (1<<1):
		result = 39;
		break;
		case (1<<2):
		result = 33;
		break;
		case (1<<3):
		result = 15;
		break;
		case (1<<4):
		result = 8;
		break;
	}
	return result;
}
int get_led_number_col_9(int row)
{
	int result = DEFAULT_MOUTH_LED_NUMBER;
	switch (row)
	{
		case (1<<0):
		result = 38;
		break;
		case (1<<1):
		result = 35;
		break;
		case (1<<2):
		result = 34;
		break;
		case (1<<3):
		result = 14;
		break;
		case (1<<4):
		result = 9;
		break;
	}
	return result;
}
int get_led_number_col_10(int row)
{
	int result = DEFAULT_MOUTH_LED_NUMBER;
	switch (row)
	{
		case (1<<0):
		result = 36;
		break;
		case (1<<1):
		result = 13;
		break;
		case (1<<2):
		result = 10;
		break;
	}
	return result;
}
int get_led_number_col_11(int row)
{
	int result = DEFAULT_MOUTH_LED_NUMBER;
	switch (row)
	{
		case (1<<0):
		result = 37;
		break;
		case (1<<1):
		result = 12;
		break;
		case (1<<2):
		result = 11;
		break;
	}
	return result;
}

void set_mouth(int col, int row, uint8_t R,uint8_t G,uint8_t B)
{
	int ledNumber = DEFAULT_MOUTH_LED_NUMBER;
	switch(col)
	{
		case 0:
		ledNumber = get_led_number_col_1(row);
		break;
		case 1:
		ledNumber = get_led_number_col_2(row);
		break;
		case 2:
		ledNumber = get_led_number_col_3(row);
		break;
		case 3:
		ledNumber = get_led_number_col_4(row);
		break;
		case 4:
		ledNumber = get_led_number_col_5(row);
		break;
		case 5:
		ledNumber = get_led_number_col_6(row);
		break;
		case 6:
		ledNumber = get_led_number_col_7(row);
		break;
		case 7:
		ledNumber = get_led_number_col_8(row);
		break;
		case 8:
		ledNumber = get_led_number_col_9(row);
		break;
		case 9:
		ledNumber = get_led_number_col_10(row);
		break;
		case 10:
		ledNumber = get_led_number_col_11(row);
		break;
	}
	set_pixel_color(ledNumber,R,G,B);
}

void process_mouth(int amplitude, int frequency)
{
	clearPixels();
	
	currentFrame = (currentFrame + frequency) % MAX_FRAME;
	for (int i = 0, x = 0; i <= MAX_MOUTH_COL; x++)
	{
		int data = sequence_mouth[currentFrame][i][amplitude];
		if (data & (1<<x))
		{
			set_mouth(i, x, DEFAULT_RED_LED_MOUTH, DEFAULT_GREEN_LED_MOUTH, DEFAULT_BLUE_LED_MOUTH);
		}
		if ((1<<x) == mouthMaxColSize[i])
		{
			i++;
			x = 0;
		}
	}
	
	pixel_show();
}