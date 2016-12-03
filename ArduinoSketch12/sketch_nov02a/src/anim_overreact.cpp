#include "sara_face_led_driver.h"
#include "anim_overreact.h"
#include "anim_basic.h"

void mouth_surprise(uint8_t R,uint8_t G,uint8_t B)
{
 for(uint8_t i=2; i<=4;I++){
 set_mouth( 3, i, R, G, B)
 }
set_mouth( 4, 2, R, G, B);
set_mouth( 4, 4, R, G, B);
set_mouth( 5, 2, R, G, B);
set_mouth( 5, 6, R, G, B);
set_mouth( 6, 2, R, G, B);
set_mouth( 6, 4, R, G, B);
set_mouth( 7, 2, R, G, B);
set_mouth( 7, 6, R, G, B);
set_mouth( 8, 2, R, G, B);
set_mouth( 8, 4, R, G, B);
for(uint8_t i=2; i<=4;I++){
 set_mouth( 9, i, R, G, B)
 }
}

#if 0
void emo_party()
{
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
}

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