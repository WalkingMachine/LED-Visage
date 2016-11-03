/*
 * sara_face_led_driver_define.h
 *
 * Created: 2016-11-03 09:18:40
 *  Author: Salco
 */ 


#ifndef SARA_FACE_LED_DRIVER_DEFINE_H_
#define SARA_FACE_LED_DRIVER_DEFINE_H_

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS   81
#define EYEPIXELS   14
#define BASE_BOUCHE EYEPIXELS*2

#define DEFAULT_BRIGHTNESS 75


#if defined(SOUND_WITH_AUDIO_IN)
  #define VOLT_MAX_MASK_BUFFER 2
  #define VOLT_CUR_MASK_BUFFER 2
  #define VOLT_MIN_MASK_BUFFER 2
  
  #define MAX_FRAME 6
  #define MAX_MOUTH_COL 11
  #define MOUTH_MAX_COL_SIZE { (1<<2),(1<<2),(1<<4),(1<<4),(1<<7),(1<<4),(1<<7),(1<<4),(1<<4),(1<<2),(1<<2) }
  const unsigned char mouthMaxColSize[] = MOUTH_MAX_COL_SIZE;
  #define DEFAULT_RED_LED_MOUTH 0
  #define DEFAULT_GREEN_LED_MOUTH 0
  #define DEFAULT_BLUE_LED_MOUTH 50
#endif
#endif /* SARA_FACE_LED_DRIVER_DEFINE_H_ */