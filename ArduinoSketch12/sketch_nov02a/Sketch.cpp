
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
}

void loop() {
	smile(50,50,0);
	while(1);
	process_mouth(0,0);
	while(1);
  // put your main code here, to run repeatedly:
//set_brightness(1);
emo_content();
delay(1000);
//loadingFade();
while(1);
}
