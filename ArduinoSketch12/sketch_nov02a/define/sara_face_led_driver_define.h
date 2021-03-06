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
  #define MAX_MOUTH_ROW_1 3
  #define MAX_MOUTH_ROW_2 3
  #define MAX_MOUTH_ROW_3 5
  #define MAX_MOUTH_ROW_4 5
  #define MAX_MOUTH_ROW_5 8
  #define MAX_MOUTH_ROW_6 5
  #define MAX_MOUTH_ROW_7 8
  #define MAX_MOUTH_ROW_8 5
  #define MAX_MOUTH_ROW_9 5
  #define MAX_MOUTH_ROW_10 3
  #define MAX_MOUTH_ROW_11 3
  #define MOUTH_MAX_ROW { MAX_MOUTH_ROW_1,MAX_MOUTH_ROW_2,MAX_MOUTH_ROW_3,MAX_MOUTH_ROW_4,MAX_MOUTH_ROW_5,MAX_MOUTH_ROW_6,\
						  MAX_MOUTH_ROW_7,MAX_MOUTH_ROW_8,MAX_MOUTH_ROW_9,MAX_MOUTH_ROW_10,MAX_MOUTH_ROW_11 }
  static const unsigned char mouthMaxRow[MAX_MOUTH_COL] = MOUTH_MAX_ROW;
  
  #define MOUTH_MAX_COL_SIZE { (1<<2),(1<<2),(1<<4),(1<<4),(1<<7),(1<<4),(1<<7),(1<<4),(1<<4),(1<<2),(1<<2) }
  static const unsigned char mouthMaxColSize[] = MOUTH_MAX_COL_SIZE;
  #define DEFAULT_RED_LED_MOUTH 0
  #define DEFAULT_GREEN_LED_MOUTH 0
  #define DEFAULT_BLUE_LED_MOUTH 50
#endif

/*

				[3,5]
	[1,3] [2,3]  [3,4]
	[1,2]  [2,2] [3,3]
	[1,1] [2,1]  [3,2]
				[3,1]


*/
//base 28

//organisation des led de la bouche
#define BOARD_LED_MOUTH_001 ((BASE_BOUCHE+0)+(MAX_MOUTH_COL*0))
#define BOARD_LED_MOUTH_002 ((BASE_BOUCHE+1)+(MAX_MOUTH_COL*0))
#define BOARD_LED_MOUTH_003 ((BASE_BOUCHE+2)+(MAX_MOUTH_COL*0))
#define BOARD_LED_MOUTH_004 ((BASE_BOUCHE+3)+(MAX_MOUTH_COL*0))
#define BOARD_LED_MOUTH_005 ((BASE_BOUCHE+4)+(MAX_MOUTH_COL*0))
#define BOARD_LED_MOUTH_006 ((BASE_BOUCHE+5)+(MAX_MOUTH_COL*0))
#define BOARD_LED_MOUTH_007 ((BASE_BOUCHE+6)+(MAX_MOUTH_COL*0))
#define BOARD_LED_MOUTH_008 ((BASE_BOUCHE+7)+(MAX_MOUTH_COL*0))
#define BOARD_LED_MOUTH_009 ((BASE_BOUCHE+8)+(MAX_MOUTH_COL*0))
#define BOARD_LED_MOUTH_010 ((BASE_BOUCHE+9)+(MAX_MOUTH_COL*0))
#define BOARD_LED_MOUTH_011 ((BASE_BOUCHE+10)+(MAX_MOUTH_COL*0))
#define BOARD_LED_MOUTH_012 ((BASE_BOUCHE+0)+(MAX_MOUTH_COL*1))
#define BOARD_LED_MOUTH_013 ((BASE_BOUCHE+1)+(MAX_MOUTH_COL*1))
#define BOARD_LED_MOUTH_014 ((BASE_BOUCHE+2)+(MAX_MOUTH_COL*1))
#define BOARD_LED_MOUTH_015 ((BASE_BOUCHE+3)+(MAX_MOUTH_COL*1))
#define BOARD_LED_MOUTH_016 ((BASE_BOUCHE+4)+(MAX_MOUTH_COL*1))
#define BOARD_LED_MOUTH_017 ((BASE_BOUCHE+5)+(MAX_MOUTH_COL*1))
#define BOARD_LED_MOUTH_018 ((BASE_BOUCHE+6)+(MAX_MOUTH_COL*1))
#define BOARD_LED_MOUTH_019 ((BASE_BOUCHE+7)+(MAX_MOUTH_COL*1))
#define BOARD_LED_MOUTH_020 ((BASE_BOUCHE+8)+(MAX_MOUTH_COL*1))
#define BOARD_LED_MOUTH_021 ((BASE_BOUCHE+9)+(MAX_MOUTH_COL*1))
#define BOARD_LED_MOUTH_022 ((BASE_BOUCHE+10)+(MAX_MOUTH_COL*1))
#define BOARD_LED_MOUTH_023 ((BASE_BOUCHE+0)+(MAX_MOUTH_COL*2))
#define BOARD_LED_MOUTH_024 ((BASE_BOUCHE+1)+(MAX_MOUTH_COL*2))
#define BOARD_LED_MOUTH_025 ((BASE_BOUCHE+2)+(MAX_MOUTH_COL*2))
#define BOARD_LED_MOUTH_026 ((BASE_BOUCHE+3)+(MAX_MOUTH_COL*2))
#define BOARD_LED_MOUTH_027 ((BASE_BOUCHE+4)+(MAX_MOUTH_COL*2))
#define BOARD_LED_MOUTH_028 ((BASE_BOUCHE+5)+(MAX_MOUTH_COL*2))
#define BOARD_LED_MOUTH_029 ((BASE_BOUCHE+6)+(MAX_MOUTH_COL*2))
#define BOARD_LED_MOUTH_030 ((BASE_BOUCHE+7)+(MAX_MOUTH_COL*2))
#define BOARD_LED_MOUTH_031 ((BASE_BOUCHE+8)+(MAX_MOUTH_COL*2))
#define BOARD_LED_MOUTH_032 ((BASE_BOUCHE+9)+(MAX_MOUTH_COL*2))
#define BOARD_LED_MOUTH_033 ((BASE_BOUCHE+10)+(MAX_MOUTH_COL*2))
#define BOARD_LED_MOUTH_034 ((BASE_BOUCHE+0)+(MAX_MOUTH_COL*3))
#define BOARD_LED_MOUTH_035 ((BASE_BOUCHE+1)+(MAX_MOUTH_COL*3))
#define BOARD_LED_MOUTH_036 ((BASE_BOUCHE+2)+(MAX_MOUTH_COL*3))
#define BOARD_LED_MOUTH_037 ((BASE_BOUCHE+3)+(MAX_MOUTH_COL*3))
#define BOARD_LED_MOUTH_038 ((BASE_BOUCHE+4)+(MAX_MOUTH_COL*3))
#define BOARD_LED_MOUTH_039 ((BASE_BOUCHE+5)+(MAX_MOUTH_COL*3))
#define BOARD_LED_MOUTH_040 ((BASE_BOUCHE+6)+(MAX_MOUTH_COL*3))
#define BOARD_LED_MOUTH_041 ((BASE_BOUCHE+7)+(MAX_MOUTH_COL*3))
#define BOARD_LED_MOUTH_042 ((BASE_BOUCHE+8)+(MAX_MOUTH_COL*3))
#define BOARD_LED_MOUTH_043 ((BASE_BOUCHE+9)+(MAX_MOUTH_COL*3))
#define BOARD_LED_MOUTH_044 ((BASE_BOUCHE+10)+(MAX_MOUTH_COL*3))
#define BOARD_LED_MOUTH_045 ((BASE_BOUCHE+0)+(MAX_MOUTH_COL*4))
#define BOARD_LED_MOUTH_046 ((BASE_BOUCHE+1)+(MAX_MOUTH_COL*4))
#define BOARD_LED_MOUTH_047 ((BASE_BOUCHE+2)+(MAX_MOUTH_COL*4))
#define BOARD_LED_MOUTH_048 ((BASE_BOUCHE+3)+(MAX_MOUTH_COL*4))
#define BOARD_LED_MOUTH_049 ((BASE_BOUCHE+4)+(MAX_MOUTH_COL*4))
#define BOARD_LED_MOUTH_050 ((BASE_BOUCHE+5)+(MAX_MOUTH_COL*4))
#define BOARD_LED_MOUTH_051 ((BASE_BOUCHE+6)+(MAX_MOUTH_COL*4))
#define BOARD_LED_MOUTH_052 ((BASE_BOUCHE+7)+(MAX_MOUTH_COL*4))
#define BOARD_LED_MOUTH_053 ((BASE_BOUCHE+8)+(MAX_MOUTH_COL*4))




#define LED_MOUTH_COL_1_ROW_1 BOARD_LED_MOUTH_023
#define LED_MOUTH_COL_1_ROW_2 BOARD_LED_MOUTH_022
#define LED_MOUTH_COL_1_ROW_3 BOARD_LED_MOUTH_001
static const unsigned char mouthLedNbr_Col_1[] = {LED_MOUTH_COL_1_ROW_1,LED_MOUTH_COL_1_ROW_2,LED_MOUTH_COL_1_ROW_3};

#define LED_MOUTH_COL_2_ROW_1 BOARD_LED_MOUTH_024
#define LED_MOUTH_COL_2_ROW_2 BOARD_LED_MOUTH_021
#define LED_MOUTH_COL_2_ROW_3 BOARD_LED_MOUTH_002
static const unsigned char mouthLedNbr_Col_2[] = {LED_MOUTH_COL_2_ROW_1,LED_MOUTH_COL_2_ROW_2,LED_MOUTH_COL_2_ROW_3};

#define LED_MOUTH_COL_3_ROW_1 BOARD_LED_MOUTH_043
#define LED_MOUTH_COL_3_ROW_2 BOARD_LED_MOUTH_025
#define LED_MOUTH_COL_3_ROW_3 BOARD_LED_MOUTH_026
#define LED_MOUTH_COL_3_ROW_4 BOARD_LED_MOUTH_020
#define LED_MOUTH_COL_3_ROW_5 BOARD_LED_MOUTH_003
static const unsigned char mouthLedNbr_Col_3[] = {LED_MOUTH_COL_3_ROW_1,LED_MOUTH_COL_3_ROW_2,LED_MOUTH_COL_3_ROW_3,LED_MOUTH_COL_3_ROW_4,LED_MOUTH_COL_3_ROW_5};

#define LED_MOUTH_COL_4_ROW_1 BOARD_LED_MOUTH_044
#define LED_MOUTH_COL_4_ROW_2 BOARD_LED_MOUTH_042
#define LED_MOUTH_COL_4_ROW_3 BOARD_LED_MOUTH_027
#define LED_MOUTH_COL_4_ROW_4 BOARD_LED_MOUTH_019
#define LED_MOUTH_COL_4_ROW_5 BOARD_LED_MOUTH_004
static const unsigned char mouthLedNbr_Col_4[] = {LED_MOUTH_COL_4_ROW_1,LED_MOUTH_COL_4_ROW_2,LED_MOUTH_COL_4_ROW_3,LED_MOUTH_COL_4_ROW_4,LED_MOUTH_COL_4_ROW_5};


#define LED_MOUTH_COL_5_ROW_1 BOARD_LED_MOUTH_052
#define LED_MOUTH_COL_5_ROW_2 BOARD_LED_MOUTH_045
#define LED_MOUTH_COL_5_ROW_3 BOARD_LED_MOUTH_046
#define LED_MOUTH_COL_5_ROW_4 BOARD_LED_MOUTH_041
#define LED_MOUTH_COL_5_ROW_5 BOARD_LED_MOUTH_028
#define LED_MOUTH_COL_5_ROW_6 BOARD_LED_MOUTH_029
#define LED_MOUTH_COL_5_ROW_7 BOARD_LED_MOUTH_018
#define LED_MOUTH_COL_5_ROW_8 BOARD_LED_MOUTH_005
static const unsigned char mouthLedNbr_Col_5[] = {LED_MOUTH_COL_5_ROW_1,LED_MOUTH_COL_5_ROW_2,LED_MOUTH_COL_5_ROW_3,LED_MOUTH_COL_5_ROW_4,LED_MOUTH_COL_5_ROW_5,
										   LED_MOUTH_COL_5_ROW_6,LED_MOUTH_COL_5_ROW_7,LED_MOUTH_COL_5_ROW_8};

#define LED_MOUTH_COL_6_ROW_1 BOARD_LED_MOUTH_051
#define LED_MOUTH_COL_6_ROW_2 BOARD_LED_MOUTH_047
#define LED_MOUTH_COL_6_ROW_3 BOARD_LED_MOUTH_030
#define LED_MOUTH_COL_6_ROW_4 BOARD_LED_MOUTH_017
#define LED_MOUTH_COL_6_ROW_5 BOARD_LED_MOUTH_006
static const unsigned char mouthLedNbr_Col_6[] = {LED_MOUTH_COL_6_ROW_1,LED_MOUTH_COL_6_ROW_2,LED_MOUTH_COL_6_ROW_3,LED_MOUTH_COL_6_ROW_4,LED_MOUTH_COL_6_ROW_5};


#define LED_MOUTH_COL_7_ROW_1 BOARD_LED_MOUTH_053
#define LED_MOUTH_COL_7_ROW_2 BOARD_LED_MOUTH_050
#define LED_MOUTH_COL_7_ROW_3 BOARD_LED_MOUTH_048
#define LED_MOUTH_COL_7_ROW_4 BOARD_LED_MOUTH_040
#define LED_MOUTH_COL_7_ROW_5 BOARD_LED_MOUTH_031
#define LED_MOUTH_COL_7_ROW_6 BOARD_LED_MOUTH_032
#define LED_MOUTH_COL_7_ROW_7 BOARD_LED_MOUTH_016
#define LED_MOUTH_COL_7_ROW_8 BOARD_LED_MOUTH_007
static const unsigned char mouthLedNbr_Col_7[] = {LED_MOUTH_COL_7_ROW_1,LED_MOUTH_COL_7_ROW_2,LED_MOUTH_COL_7_ROW_3,LED_MOUTH_COL_7_ROW_4,LED_MOUTH_COL_7_ROW_5,
										   LED_MOUTH_COL_7_ROW_6,LED_MOUTH_COL_7_ROW_7,LED_MOUTH_COL_7_ROW_8};

#define LED_MOUTH_COL_8_ROW_1 BOARD_LED_MOUTH_049
#define LED_MOUTH_COL_8_ROW_2 BOARD_LED_MOUTH_039
#define LED_MOUTH_COL_8_ROW_3 BOARD_LED_MOUTH_033
#define LED_MOUTH_COL_8_ROW_4 BOARD_LED_MOUTH_015
#define LED_MOUTH_COL_8_ROW_5 BOARD_LED_MOUTH_008
static const unsigned char mouthLedNbr_Col_8[] = {LED_MOUTH_COL_8_ROW_1,LED_MOUTH_COL_8_ROW_2,LED_MOUTH_COL_8_ROW_3,LED_MOUTH_COL_8_ROW_4,LED_MOUTH_COL_8_ROW_5};

#define LED_MOUTH_COL_9_ROW_1 BOARD_LED_MOUTH_038
#define LED_MOUTH_COL_9_ROW_2 BOARD_LED_MOUTH_035
#define LED_MOUTH_COL_9_ROW_3 BOARD_LED_MOUTH_034
#define LED_MOUTH_COL_9_ROW_4 BOARD_LED_MOUTH_014
#define LED_MOUTH_COL_9_ROW_5 BOARD_LED_MOUTH_009
static const unsigned char mouthLedNbr_Col_9[] = {LED_MOUTH_COL_9_ROW_1,LED_MOUTH_COL_9_ROW_2,LED_MOUTH_COL_9_ROW_3,LED_MOUTH_COL_9_ROW_4,LED_MOUTH_COL_9_ROW_5};

#define LED_MOUTH_COL_10_ROW_1 BOARD_LED_MOUTH_036
#define LED_MOUTH_COL_10_ROW_2 BOARD_LED_MOUTH_013
#define LED_MOUTH_COL_10_ROW_3 BOARD_LED_MOUTH_010
static const unsigned char mouthLedNbr_Col_10[] = {LED_MOUTH_COL_10_ROW_1,LED_MOUTH_COL_10_ROW_2,LED_MOUTH_COL_10_ROW_3};

#define LED_MOUTH_COL_11_ROW_1 BOARD_LED_MOUTH_037
#define LED_MOUTH_COL_11_ROW_2 BOARD_LED_MOUTH_012
#define LED_MOUTH_COL_11_ROW_3 BOARD_LED_MOUTH_011

static const unsigned char mouthLedNbr_Col_11[] = {LED_MOUTH_COL_11_ROW_1,LED_MOUTH_COL_11_ROW_2,LED_MOUTH_COL_11_ROW_3};


static const unsigned char* mouthLedNbr[] = {mouthLedNbr_Col_1,mouthLedNbr_Col_2,mouthLedNbr_Col_3,mouthLedNbr_Col_4,mouthLedNbr_Col_5,mouthLedNbr_Col_6,
									 mouthLedNbr_Col_7,mouthLedNbr_Col_8,mouthLedNbr_Col_9,mouthLedNbr_Col_10,mouthLedNbr_Col_11};

#endif /* SARA_FACE_LED_DRIVER_DEFINE_H_ */
