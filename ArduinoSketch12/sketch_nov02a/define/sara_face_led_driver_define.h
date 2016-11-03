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

#endif
#endif /* SARA_FACE_LED_DRIVER_DEFINE_H_ */