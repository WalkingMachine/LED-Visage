
/*Begining of Auto generated code by Atmel studio */
//#include <Arduino.h>
#include <stdint.h>
/*End of auto generated code by Atmel studio */


#include "sara_face_led_driver.h"
//#include "sara_face_led_driver_define.h"

//Beginning of Auto generated function prototypes by Atmel Studio




//End of Auto generated function prototypes by Atmel Studio








 






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
  // put your main code here, to run repeatedly:
//set_brightness(1);
emo_content();
delay(1000);
//loadingFade();
while(1);
}
