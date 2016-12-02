#include "sara_face_led_driver.h"
#include "anim_overreact.h"

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