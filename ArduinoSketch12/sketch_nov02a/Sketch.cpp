
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

//End of Auto generated function prototypes by Atmel Studio




int delayval = 5; // delay for half a second
int luminosite = 1;
int mode = 1; // 0 = wait, 1 = start, 2 = loading, 3 = green, 4 = yellow, 5 = red, 6 = wait for answer
bool talking = false;



 






void emo_content()
{
  /*Émotion : Content**********************************************/
  clearPixels();
  eye(1,50,50,50);
  eye(2,50,50,50);
  //bouche_vide(); //Changer LED3 et LED45
  //smile(50,50,50);
  delay(1000);
}

 





  
void setup() {
  // put your setup code here, to run once:

	init_NeoPixels();
	#if defined(SOUND_WITH_AUDIO_IN)
		init_modeSoundWave_Adc();
	#endif
}
//#define TEST_MAIN_02
void loop() {
	#if defined( TEST_MAIN_01 )
		smile(50,50,0);
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
	
  // put your main code here, to run repeatedly:
  
//set_brightness(1);
// emo_content();
// delay(1000);
//loadingFade();
//while(1);

 process_mouth();
// delay(100);
}
