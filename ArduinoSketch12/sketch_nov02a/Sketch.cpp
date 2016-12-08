
/*Begining of Auto generated code by Atmel studio */
//#include <Arduino.h>
#include <stdint.h>
/*End of auto generated code by Atmel studio */

//
#include <avr/io.h>

#include "avr\interrupt.h"       // pour les interuptions
#include <util/delay.h>          // pour les delay
//	

#if defined(SOUND_WITH_AUDIO_IN)
#include "modeSoundWave_ADC.h"
#endif

#include "sara_face_led_driver.h"

//#include "sara_face_led_driver_define.h"

//Beginning of Auto generated function prototypes by Atmel Studio

#define TEST_COLONNE 5
#define TEST_ROW 5

//test some emotion
//#define TEST_FACE_01
//#define TEST_FACE_02 test eye_roll_bar
#define TEST_FACE_03 test 0
#include "anim_basic.h"
#include "anim_overreact.h"
//#define TEST_ROS

#if defined( TEST_ROS )
	#include "ros_interface.h"
#endif
//End of Auto generated function prototypes by Atmel Studio




int delayval = 5; // delay for half a second
int luminosite = 1;
int mode = 1; // 0 = wait, 1 = start, 2 = loading, 3 = green, 4 = yellow, 5 = red, 6 = wait for answer
bool talking = false;

uint8_t m_mode=7;

 







/*void emo_party()
{
	clearPixels();
	mouth_surprise(50,50,50);
	pixel_show();
}*/


  
void setup() {
  // put your setup code here, to run once:

	init_NeoPixels();
	#if defined(SOUND_WITH_AUDIO_IN)
		init_modeSoundWave_Adc();
	#endif
	
	#if defined( TEST_ROS )
		init_ros_interface();
	#endif
	emo_content();
	init_emotion();
	//emo_triste();//emo_content();
}
//#define TEST_MAIN_02
//#define TEST_MAIN_01
void state_machine_face(void)
{
	switch (m_mode)
	{
		 case 7:
			emo_party();
			delay(200);
			break;
	}
}
void loop() {
	#if defined( TEST_MAIN_01 )
		clearPixels();
		eye(1,50,50,50);
		eye(2,50,50,50);
		smile(50,50,50);
		while(1);
	#endif

	#if defined( TEST_MAIN_02 )
		for(int col=0; col <= (MAX_MOUTH_COL-1); col++)
		{
			for(int row=0; row< mouthMaxRow[col]; row++)
			{
				set_mouth(col,row,50,50,50);
				pixel_show();
				//delay(400);
				clearPixels();
			}
			
		}
		clearPixels();
		pixel_show();
	
		while(1);
	#endif	
	
	#if defined( TEST_FACE_01 )
	
		emo_content();
		//emo_triste();
		while(1);
	#endif
	
	#if defined( TEST_FACE_02 )
		do 
		{

			for(uint8_t i=0; i != MAX_FRAME_eye_roll_bar; i++)
			{
			 eye_roll_bar(eye_t::left,i,DEFAULT_RED_EYE, DEFAULT_GREEN_LED_EYE, DEFAULT_BLUE_LED_EYE);
			 eye_roll_bar(eye_t::right,i,DEFAULT_RED_EYE, DEFAULT_GREEN_LED_EYE, DEFAULT_BLUE_LED_EYE);
			 pixel_show();
			 delay(500);
			}
			delay(1000);
		}
		while(1);
	#endif
	#if defined( TEST_FACE_03 )
	#define EYE_WIDTH 4
	do
	{
		
		for(uint8_t i=0; i != MAX_FRAME_eye_look_at; i++)
		{
			eye_look_at(eye_t::left,i,EYE_WIDTH, DEFAULT_RED_EYE, DEFAULT_GREEN_LED_EYE, DEFAULT_BLUE_LED_EYE);
			pixel_show();
			eye_look_at(eye_t::right,i,EYE_WIDTH,DEFAULT_RED_EYE, DEFAULT_GREEN_LED_EYE, DEFAULT_BLUE_LED_EYE);
			pixel_show();
			delay(500);
		}

	}
	while(1);
	#endif
  // put your main code here, to run repeatedly:
  
//set_brightness(1);
// emo_content();
// delay(1000);
//loadingFade();
//while(1);
#if defined(SOUND_WITH_AUDIO_IN)
 process_mouth();
 #endif
 state_machine_face();
 #if defined( TEST_ROS )
	 ros_spinOnce();
 #endif
// delay(100);
}

#if defined( TEST_ROS )
void control_emo(const std_msgs::UInt8& emo)
{
	m_mode = emo.data;
	switch (emo.data)
	{
		case 1:
		emo_content();
		break;
		case 2:
		emo_triste();
		break;
		case 3:
		emo_ciconspect();
		break;
		/*case 4:
		emo_fache();
		break;
		case 5:
		emo_surpris();
		break;
		case 6:
		emo_coquin();
		break;*/
		case 7:
		emo_party();
		break;
		default:
		m_mode = 1;
		emo_content();
	}
	
//	pixel_show();
}
#endif