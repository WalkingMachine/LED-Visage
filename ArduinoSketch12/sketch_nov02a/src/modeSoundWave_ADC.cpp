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
#include "anim_basic.h"

#ifdef __AVR__
  #include <avr/power.h>
#endif
#define TEST_ONLY_ALGO

#define TEST_SALCO_02 //Patch just to see how manage the equalizer

#if defined( TEST_SALCO_02 )
	#define TEST_SALCO_02_WATCHDOG 4000
	uint16_t TEST_SALCO_02_WATCHDOG_Var = TEST_SALCO_02_WATCHDOG;
	uint16_t test_salco_02_watchdog_counter=0;
#endif
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
int mfrequency=0;
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
static unsigned char sequence_mouth[6][11][4]={FRAME_MOUTH_01, FRAME_MOUTH_02, FRAME_MOUTH_03, FRAME_MOUTH_04, FRAME_MOUTH_05, FRAME_MOUTH_06 };
int currentFrame = 0;
bool is_adc2_received;
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
	//init value
	is_adc2_received=false;
	
	wave_mouth(0,0);
	
#if defined(TEST_ONLY_ALGO)
	cli();//diable interrupts
	//set up continuous sampling of analog pin 0 at 38.5kHz

	//clear ADCSRA and ADCSRB registers
	ADCSRA = 0;
	ADCSRB = 0;
	
	//ADMUX = MUX2
	ADMUX |= (1 << REFS0); //set reference voltage
	ADMUX |= (1 << ADLAR); //left align the ADC value- so we can read highest 8 bits from ADCH register only
	ADMUX |= /*(1 <<*/ MUX2/*)*/; //

	ADCSRA |= (1 << ADPS2) | (1 << ADPS0); //set ADC clock with 32 prescaler- 16mHz/32=500kHz
	ADCSRA |= (1 << ADATE); //enabble auto trigger
	ADCSRA |= (1 << ADIE); //enable interrupts when measurement complete
	ADCSRA |= (1 << ADEN); //enable ADC
	ADCSRA |= (1 << ADSC); //start ADC measurements

	sei();//enable interrupts
#endif
}
void process_ADC2(uint8_t adcRead)
{
	//calcule amplitude
	CALCULATE_VOLT_CUR((newDataAdc01*5.0)/1024)
	if(voltCur >= voltMax)
	CALCULATE_VOLT_MAX(voltCur)
	if(voltCur <= voltMin )
	CALCULATE_VOLT_MIN(voltCur)
	
	
}
#if defined(TEST_ONLY_ALGO)
ISR(ADC_vect) {//when new ADC value ready
	//Get ADCH and toggle a bool to know it's change
	
	//PORTB &= B11101111;//set pin 12 low
	prevDataAdc01 = newDataAdc01;//store previous value
	newDataAdc01 = ADCH;//get value from A0
	
	//
	
	if (prevDataAdc01 < 127 && newDataAdc01 >=127){//if increasing and crossing midpoint
		newSlope = newDataAdc01 - prevDataAdc01;//calculate slope
		
		//calcule amplitude
		CALCULATE_VOLT_CUR((newDataAdc01*5.0)/1024)
		if(voltCur >= voltMax)
		CALCULATE_VOLT_MAX(voltCur)
		if(voltCur <= voltMin )
		CALCULATE_VOLT_MIN(voltCur)
		
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
	if (abs(127-ADCH)>maxAmp)
	{
		maxAmp = abs(127-ADCH);
	}
	if (ampTimer==1000){
		ampTimer = 0;
		checkMaxAmp = maxAmp;
		maxAmp = 0;
	}
	
	is_adc2_received = true;
}
#endif

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

//for(int row=0; row< mouthMaxRow[col]; row++)



void wave_mouth(int amplitude, int frequency)
{
	clearPixels();
	
	currentFrame = (currentFrame + frequency) % MAX_FRAME;

	for (int i = 0, x = 0; i < MAX_MOUTH_COL; x++)
	{
		int data = sequence_mouth[currentFrame][i][amplitude];
		if (data & (1<<x))
		{
			set_mouth(i, x, DEFAULT_RED_LED_MOUTH, DEFAULT_GREEN_LED_MOUTH, DEFAULT_BLUE_LED_MOUTH);
		}
		if (((1<<x) == mouthMaxColSize[i])|| (x>=8))
		{
			i++;
			x = 0;
		}
	}
	
	pixel_show();
}

#define TEST_SALCO_01
void process_mouth(void)
	{
		#if 0
		//process ADC
		if(is_adc2_received)
		{
			process_ADC2(newDataAdc01);
		}
		#endif
		#if defined(TEST_SALCO_02)
			test_salco_02_watchdog_counter++;
			if(test_salco_02_watchdog_counter > TEST_SALCO_02_WATCHDOG_Var)
			{
				test_salco_02_watchdog_counter=0;
			
		#endif
		
		static int deltaAmplitude;
		static int deltaFrequency;
	
	//aquireAudio();
	checkClipping();//pas vraiment utile
	if (checkMaxAmp>ampThreshold)
	{//amplitude threshold
    mfrequency = 38462/float(period);//calculate frequency timer rate/period
  
    //print results
    //Serial.print(frequency);
    //Serial.print(" hz, ");
 
  
  //print results
  //
  
  if((mfrequency >= -1) && (mfrequency<100))
  {
    deltaFrequency=0;
  }
  if((mfrequency >= 100) && (mfrequency<180))
  {
    deltaFrequency=1;
  }
  if((mfrequency >= 180) && (mfrequency<220))
  {
    deltaFrequency=2;
  }
  if((mfrequency >= 220) )
  {
    deltaFrequency=3;
  }
  const int past_frequency= mfrequency;
   if(mfrequency == past_frequency) 
  {
    //Serial.println("same as before");
    watchdog_tension_ilde++;
  }
 if(int(watchdog_tension_ilde*100) >= int(WATCHDOG_TENTION_MAX*100))
 {
  watchdog_tension_ilde=0;
  period=38462;
  voltMax=0;
  voltCur=0;
  voltMin=5;
  deltaFrequency=0;
  deltaAmplitude=0;
 }
 /*Serial.print(watchdog_tension_ilde);
 Serial.print(" watchdog_tension_ilde, ");
  //
  Serial.print(frequency);


  Serial.print(" hz, ");
  Serial.println(result);*/

 
 /*if(watchdog_tension_ilde >= WATCHDOG_TENTION_MAX)
 {
  watchdog_tension_ilde=0;
  //period=38462;
  voltMax=0;
  voltCur=0;
  voltMin=5;
 }*/
 
  /*Serial.print(" voltMax: ");
  Serial.print(voltMax);

  Serial.print(" voltCur: ");
  Serial.print(voltCur);
  Serial.print(" past_voltCur: ");
  Serial.print(past_voltCur);

  Serial.print(" voltMin: ");
  Serial.println(voltMin);*/

  float amplitudeV= voltMax-voltMin;
  amplitudeV*=100;

  //Serial.print(" amplitudeV: ");
  //Serial.println(amplitudeV);  
  
  if((amplitudeV >= 0) && (amplitudeV<10))
  {
    deltaAmplitude=0;
  }
  if((amplitudeV >= 10) && (amplitudeV<30))
  {
    deltaAmplitude=1;
  }
  if((amplitudeV >= 30) && (amplitudeV<60))
  {
    deltaAmplitude=2;
  }
  if((amplitudeV >= 60) && (amplitudeV<70))
  {
    deltaAmplitude=3;
  }
  if((amplitudeV >= 70) )
  {
    deltaAmplitude=4;
  }
  //Serial.print(" stugff: ");
  //Serial.println(result);  
  //delay(100);
  #if defined(TEST_SALCO_01)
	wave_mouth(deltaAmplitude,deltaFrequency);
  #else
	wave_mouth(deltaAmplitude,deltaFrequency);
	#endif
   }
   
  #if defined(TEST_SALCO_02)
	} //if(test_salco_02_watchdog_counter > TEST_SALCO_02_WATCHDOG)
  #endif
   
	}