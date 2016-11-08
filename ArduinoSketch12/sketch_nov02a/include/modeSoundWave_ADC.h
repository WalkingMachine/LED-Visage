/*
 * modeSoundWave_ADC.h
 *
 * Created: 2016-11-03 11:30:52
 *  Author: wn
 */ 


#ifndef MODESOUNDWAVE_ADC_H_
#define MODESOUNDWAVE_ADC_H_

#include <stdint.h>

//define default value
#define FRAME_MOUTH_IDLE_COLUMN_PATCH_1 (1<<1)
#define FRAME_MOUTH_IDLE_COLUMN_0 (1<<1)
#define FRAME_MOUTH_IDLE_COLUMN_1 (1<<2)
#define FRAME_MOUTH_IDLE_COLUMN_2 (1<<2)
#define FRAME_MOUTH_IDLE_COLUMN_3 (1<<4)
#define FRAME_MOUTH_IDLE_COLUMN_4 (1<<2)
#define FRAME_MOUTH_IDLE_COLUMN_5 (1<<4)
#define FRAME_MOUTH_IDLE_COLUMN_6 (1<<2)
#define FRAME_MOUTH_IDLE_COLUMN_7 (1<<2)
#define FRAME_MOUTH_IDLE_COLUMN_8 (1<<1)
#define FRAME_MOUTH_IDLE_COLUMN_PATCH_2 (1<<1)

//Todo: verifier si cest vraiment utile
#define DEFAULT_MOUTH_LED_NUMBER BASE_BOUCHE 


#define FRAME_MOUTH_01_COLUMN_0_SEQ_PATCH_1 FRAME_MOUTH_IDLE_COLUMN_PATCH_1
//----//
#define FRAME_MOUTH_01_COLUMN_0_SEQ_0 FRAME_MOUTH_IDLE_COLUMN_0
//----//
#define FRAME_MOUTH_01_COLUMN_1_SEQ_0 FRAME_MOUTH_IDLE_COLUMN_1
#define FRAME_MOUTH_01_COLUMN_1_SEQ_1 (FRAME_MOUTH_IDLE_COLUMN_1<<1)
//----//
#define FRAME_MOUTH_01_COLUMN_2_SEQ_0 FRAME_MOUTH_IDLE_COLUMN_2
#define FRAME_MOUTH_01_COLUMN_2_SEQ_1 ((FRAME_MOUTH_IDLE_COLUMN_2>>1)+FRAME_MOUTH_IDLE_COLUMN_2)
//----//
#define FRAME_MOUTH_01_COLUMN_3_SEQ_0 FRAME_MOUTH_IDLE_COLUMN_3
#define FRAME_MOUTH_01_COLUMN_3_SEQ_1 (FRAME_MOUTH_IDLE_COLUMN_3>>1)
#define FRAME_MOUTH_01_COLUMN_3_SEQ_2 ((FRAME_MOUTH_IDLE_COLUMN_3>>2)+(FRAME_MOUTH_IDLE_COLUMN_3>>1))
#define FRAME_MOUTH_01_COLUMN_3_SEQ_3 (FRAME_MOUTH_IDLE_COLUMN_3>>2)
//----//
#define FRAME_MOUTH_01_COLUMN_4_SEQ_0 FRAME_MOUTH_IDLE_COLUMN_4
#define FRAME_MOUTH_01_COLUMN_4_SEQ_1 ((FRAME_MOUTH_IDLE_COLUMN_4>>1)+FRAME_MOUTH_IDLE_COLUMN_4)
//----//
#define FRAME_MOUTH_01_COLUMN_5_SEQ_0 FRAME_MOUTH_IDLE_COLUMN_5
#define FRAME_MOUTH_01_COLUMN_5_SEQ_1 (FRAME_MOUTH_IDLE_COLUMN_5<<1)
#define FRAME_MOUTH_01_COLUMN_5_SEQ_2 ((FRAME_MOUTH_IDLE_COLUMN_5<<2)+(FRAME_MOUTH_IDLE_COLUMN_5<<1))
//----//
#define FRAME_MOUTH_01_COLUMN_6_SEQ_0 FRAME_MOUTH_IDLE_COLUMN_6
#define FRAME_MOUTH_01_COLUMN_6_SEQ_1 ((FRAME_MOUTH_IDLE_COLUMN_6>>1)+FRAME_MOUTH_IDLE_COLUMN_6)
//----//
#define FRAME_MOUTH_01_COLUMN_7_SEQ_0 FRAME_MOUTH_IDLE_COLUMN_7
#define FRAME_MOUTH_01_COLUMN_7_SEQ_1 (FRAME_MOUTH_IDLE_COLUMN_7>>1)
//----//
#define FRAME_MOUTH_01_COLUMN_8_SEQ_0 FRAME_MOUTH_IDLE_COLUMN_8
//----//
#define FRAME_MOUTH_01_COLUMN_0_SEQ_PATCH_2 FRAME_MOUTH_IDLE_COLUMN_PATCH_2
//----//

#define FRAME_MOUTH_01 { { FRAME_MOUTH_01_COLUMN_0_SEQ_PATCH_1, FRAME_MOUTH_01_COLUMN_0_SEQ_PATCH_1, FRAME_MOUTH_01_COLUMN_0_SEQ_PATCH_1, FRAME_MOUTH_01_COLUMN_0_SEQ_PATCH_1 }, \
{ FRAME_MOUTH_01_COLUMN_0_SEQ_0, FRAME_MOUTH_01_COLUMN_0_SEQ_0, FRAME_MOUTH_01_COLUMN_0_SEQ_0, FRAME_MOUTH_01_COLUMN_0_SEQ_0 }, \
{ FRAME_MOUTH_01_COLUMN_1_SEQ_0, FRAME_MOUTH_01_COLUMN_1_SEQ_1, FRAME_MOUTH_01_COLUMN_1_SEQ_1, FRAME_MOUTH_01_COLUMN_1_SEQ_1 }, \
{ FRAME_MOUTH_01_COLUMN_2_SEQ_0, FRAME_MOUTH_01_COLUMN_2_SEQ_1, FRAME_MOUTH_01_COLUMN_2_SEQ_1, FRAME_MOUTH_01_COLUMN_2_SEQ_1 }, \
{ FRAME_MOUTH_01_COLUMN_3_SEQ_0, FRAME_MOUTH_01_COLUMN_3_SEQ_1, FRAME_MOUTH_01_COLUMN_3_SEQ_2, FRAME_MOUTH_01_COLUMN_3_SEQ_3 }, \
{ FRAME_MOUTH_01_COLUMN_4_SEQ_0, FRAME_MOUTH_01_COLUMN_4_SEQ_1, FRAME_MOUTH_01_COLUMN_4_SEQ_1, FRAME_MOUTH_01_COLUMN_4_SEQ_1 }, \
{ FRAME_MOUTH_01_COLUMN_5_SEQ_0, FRAME_MOUTH_01_COLUMN_5_SEQ_1, FRAME_MOUTH_01_COLUMN_5_SEQ_2, FRAME_MOUTH_01_COLUMN_5_SEQ_2 }, \
{ FRAME_MOUTH_01_COLUMN_6_SEQ_0, FRAME_MOUTH_01_COLUMN_6_SEQ_1, FRAME_MOUTH_01_COLUMN_6_SEQ_1, FRAME_MOUTH_01_COLUMN_6_SEQ_1 }, \
{ FRAME_MOUTH_01_COLUMN_7_SEQ_0, FRAME_MOUTH_01_COLUMN_7_SEQ_1, FRAME_MOUTH_01_COLUMN_7_SEQ_1, FRAME_MOUTH_01_COLUMN_7_SEQ_1 }, \
{ FRAME_MOUTH_01_COLUMN_8_SEQ_0, FRAME_MOUTH_01_COLUMN_8_SEQ_0, FRAME_MOUTH_01_COLUMN_8_SEQ_0, FRAME_MOUTH_01_COLUMN_8_SEQ_0 }, \
{ FRAME_MOUTH_01_COLUMN_0_SEQ_PATCH_2, FRAME_MOUTH_01_COLUMN_0_SEQ_PATCH_2, FRAME_MOUTH_01_COLUMN_0_SEQ_PATCH_2, FRAME_MOUTH_01_COLUMN_0_SEQ_PATCH_2 } \
}
///------------------///
#define FRAME_MOUTH_02_COLUMN_0_SEQ_PATCH_1 FRAME_MOUTH_IDLE_COLUMN_PATCH_1
//----//
#define FRAME_MOUTH_02_COLUMN_0_SEQ_0 FRAME_MOUTH_IDLE_COLUMN_0
//----//
#define FRAME_MOUTH_02_COLUMN_1_SEQ_0 FRAME_MOUTH_IDLE_COLUMN_1
#define FRAME_MOUTH_02_COLUMN_1_SEQ_1 (FRAME_MOUTH_IDLE_COLUMN_1<<1)
#define FRAME_MOUTH_02_COLUMN_1_SEQ_2 ((FRAME_MOUTH_IDLE_COLUMN_1<<1)+FRAME_MOUTH_IDLE_COLUMN_1)
//----//
#define FRAME_MOUTH_02_COLUMN_2_SEQ_0 FRAME_MOUTH_IDLE_COLUMN_2
#define FRAME_MOUTH_02_COLUMN_2_SEQ_1 (FRAME_MOUTH_IDLE_COLUMN_2<<1)
#define FRAME_MOUTH_02_COLUMN_2_SEQ_2 ((FRAME_MOUTH_IDLE_COLUMN_2<<2)+(FRAME_MOUTH_IDLE_COLUMN_2<<1))
//----//
#define FRAME_MOUTH_02_COLUMN_3_SEQ_0 FRAME_MOUTH_IDLE_COLUMN_3
#define FRAME_MOUTH_02_COLUMN_3_SEQ_1 ((FRAME_MOUTH_IDLE_COLUMN_3>>1)+FRAME_MOUTH_IDLE_COLUMN_3)
//----//
#define FRAME_MOUTH_02_COLUMN_4_SEQ_0 FRAME_MOUTH_IDLE_COLUMN_4
#define FRAME_MOUTH_02_COLUMN_4_SEQ_1 (FRAME_MOUTH_IDLE_COLUMN_4>>1)
#define FRAME_MOUTH_02_COLUMN_4_SEQ_2 ((FRAME_MOUTH_IDLE_COLUMN_4>>1)+(FRAME_MOUTH_IDLE_COLUMN_4>>2))
#define FRAME_MOUTH_02_COLUMN_4_SEQ_3 ((FRAME_MOUTH_IDLE_COLUMN_4>>2)+(FRAME_MOUTH_IDLE_COLUMN_4>>3))
//----//
#define FRAME_MOUTH_02_COLUMN_5_SEQ_0 FRAME_MOUTH_IDLE_COLUMN_5
#define FRAME_MOUTH_02_COLUMN_5_SEQ_1 ((FRAME_MOUTH_IDLE_COLUMN_5<<1)+(FRAME_MOUTH_IDLE_COLUMN_5))
//----//
#define FRAME_MOUTH_02_COLUMN_6_SEQ_0 FRAME_MOUTH_IDLE_COLUMN_6
#define FRAME_MOUTH_02_COLUMN_6_SEQ_1 (FRAME_MOUTH_IDLE_COLUMN_6<<1)
#define FRAME_MOUTH_02_COLUMN_6_SEQ_2 ((FRAME_MOUTH_IDLE_COLUMN_6<<1)+(FRAME_MOUTH_IDLE_COLUMN_6<<2))
//----//
#define FRAME_MOUTH_02_COLUMN_7_SEQ_0 FRAME_MOUTH_IDLE_COLUMN_7
#define FRAME_MOUTH_02_COLUMN_7_SEQ_1 ((FRAME_MOUTH_IDLE_COLUMN_7>>1)+FRAME_MOUTH_IDLE_COLUMN_7)
//----//
#define FRAME_MOUTH_02_COLUMN_8_SEQ_0 FRAME_MOUTH_IDLE_COLUMN_8
#define FRAME_MOUTH_02_COLUMN_8_SEQ_1 (FRAME_MOUTH_IDLE_COLUMN_8<<1)
//----//
#define FRAME_MOUTH_02_COLUMN_0_SEQ_PATCH_2 FRAME_MOUTH_IDLE_COLUMN_PATCH_2
//----//

#define FRAME_MOUTH_02 { { FRAME_MOUTH_02_COLUMN_0_SEQ_PATCH_1, FRAME_MOUTH_02_COLUMN_0_SEQ_PATCH_1, FRAME_MOUTH_02_COLUMN_0_SEQ_PATCH_1, FRAME_MOUTH_02_COLUMN_0_SEQ_PATCH_1 }, \
{ FRAME_MOUTH_02_COLUMN_0_SEQ_0, FRAME_MOUTH_02_COLUMN_0_SEQ_0, FRAME_MOUTH_02_COLUMN_0_SEQ_0, FRAME_MOUTH_02_COLUMN_0_SEQ_0 }, \
{ FRAME_MOUTH_02_COLUMN_1_SEQ_0, FRAME_MOUTH_02_COLUMN_1_SEQ_1, FRAME_MOUTH_02_COLUMN_1_SEQ_2, FRAME_MOUTH_02_COLUMN_1_SEQ_2 }, \
{ FRAME_MOUTH_02_COLUMN_2_SEQ_0, FRAME_MOUTH_02_COLUMN_2_SEQ_1, FRAME_MOUTH_02_COLUMN_2_SEQ_2, FRAME_MOUTH_02_COLUMN_2_SEQ_2 }, \
{ FRAME_MOUTH_02_COLUMN_3_SEQ_0, FRAME_MOUTH_02_COLUMN_3_SEQ_1, FRAME_MOUTH_02_COLUMN_3_SEQ_1, FRAME_MOUTH_02_COLUMN_3_SEQ_1 }, \
{ FRAME_MOUTH_02_COLUMN_4_SEQ_0, FRAME_MOUTH_02_COLUMN_4_SEQ_1, FRAME_MOUTH_02_COLUMN_4_SEQ_2, FRAME_MOUTH_02_COLUMN_4_SEQ_3 }, \
{ FRAME_MOUTH_02_COLUMN_5_SEQ_0, FRAME_MOUTH_02_COLUMN_5_SEQ_1, FRAME_MOUTH_02_COLUMN_5_SEQ_1, FRAME_MOUTH_02_COLUMN_5_SEQ_1 }, \
{ FRAME_MOUTH_02_COLUMN_6_SEQ_0, FRAME_MOUTH_02_COLUMN_6_SEQ_1, FRAME_MOUTH_02_COLUMN_6_SEQ_2, FRAME_MOUTH_02_COLUMN_6_SEQ_2 }, \
{ FRAME_MOUTH_02_COLUMN_7_SEQ_0, FRAME_MOUTH_02_COLUMN_7_SEQ_1, FRAME_MOUTH_02_COLUMN_7_SEQ_1, FRAME_MOUTH_02_COLUMN_7_SEQ_1 }, \
{ FRAME_MOUTH_02_COLUMN_8_SEQ_0, FRAME_MOUTH_02_COLUMN_8_SEQ_1, FRAME_MOUTH_02_COLUMN_8_SEQ_1, FRAME_MOUTH_02_COLUMN_8_SEQ_1 }, \
{ FRAME_MOUTH_02_COLUMN_0_SEQ_PATCH_2, FRAME_MOUTH_02_COLUMN_0_SEQ_PATCH_2, FRAME_MOUTH_02_COLUMN_0_SEQ_PATCH_2, FRAME_MOUTH_02_COLUMN_0_SEQ_PATCH_2 }  \
}
///------------------///
#define FRAME_MOUTH_03_COLUMN_0_SEQ_PATCH_1 FRAME_MOUTH_IDLE_COLUMN_PATCH_1
//----//
#define FRAME_MOUTH_03_COLUMN_0_SEQ_0 FRAME_MOUTH_IDLE_COLUMN_0
#define FRAME_MOUTH_03_COLUMN_0_SEQ_1 (FRAME_MOUTH_IDLE_COLUMN_0>>1)
//----//
#define FRAME_MOUTH_03_COLUMN_1_SEQ_0 FRAME_MOUTH_IDLE_COLUMN_1
//----//
#define FRAME_MOUTH_03_COLUMN_2_SEQ_0 FRAME_MOUTH_IDLE_COLUMN_2
#define FRAME_MOUTH_03_COLUMN_2_SEQ_1 (FRAME_MOUTH_IDLE_COLUMN_2<<1)
#define FRAME_MOUTH_03_COLUMN_2_SEQ_2 ((FRAME_MOUTH_IDLE_COLUMN_2<<1)+FRAME_MOUTH_IDLE_COLUMN_2)
//----//
#define FRAME_MOUTH_03_COLUMN_3_SEQ_0 FRAME_MOUTH_IDLE_COLUMN_3
#define FRAME_MOUTH_03_COLUMN_3_SEQ_1 (FRAME_MOUTH_IDLE_COLUMN_3<<1)
#define FRAME_MOUTH_03_COLUMN_3_SEQ_2 ((FRAME_MOUTH_IDLE_COLUMN_3<<1)+(FRAME_MOUTH_IDLE_COLUMN_3<<2))
//----//
#define FRAME_MOUTH_03_COLUMN_4_SEQ_0 FRAME_MOUTH_IDLE_COLUMN_4
#define FRAME_MOUTH_03_COLUMN_4_SEQ_1 ((FRAME_MOUTH_IDLE_COLUMN_4>>1)+FRAME_MOUTH_IDLE_COLUMN_4)
//----//
#define FRAME_MOUTH_03_COLUMN_5_SEQ_0 FRAME_MOUTH_IDLE_COLUMN_5
#define FRAME_MOUTH_03_COLUMN_5_SEQ_1 (FRAME_MOUTH_IDLE_COLUMN_5>>1)
#define FRAME_MOUTH_03_COLUMN_5_SEQ_2 ((FRAME_MOUTH_IDLE_COLUMN_5>>1)+(FRAME_MOUTH_IDLE_COLUMN_5>>2))
#define FRAME_MOUTH_03_COLUMN_5_SEQ_3 ((FRAME_MOUTH_IDLE_COLUMN_5>>2)+(FRAME_MOUTH_IDLE_COLUMN_5>>3))
//----//
#define FRAME_MOUTH_03_COLUMN_6_SEQ_0 FRAME_MOUTH_IDLE_COLUMN_6
#define FRAME_MOUTH_03_COLUMN_6_SEQ_1 (FRAME_MOUTH_IDLE_COLUMN_6>>1)
#define FRAME_MOUTH_03_COLUMN_6_SEQ_2 ((FRAME_MOUTH_IDLE_COLUMN_6>>1)+FRAME_MOUTH_IDLE_COLUMN_6)
//----//
#define FRAME_MOUTH_03_COLUMN_7_SEQ_0 FRAME_MOUTH_IDLE_COLUMN_7
#define FRAME_MOUTH_03_COLUMN_7_SEQ_1 ((FRAME_MOUTH_IDLE_COLUMN_7<<1)+(FRAME_MOUTH_IDLE_COLUMN_7<<2))
//----//
#define FRAME_MOUTH_03_COLUMN_8_SEQ_0 FRAME_MOUTH_IDLE_COLUMN_8
#define FRAME_MOUTH_03_COLUMN_8_SEQ_1 ((FRAME_MOUTH_IDLE_COLUMN_8>>1)+FRAME_MOUTH_IDLE_COLUMN_8)
//----//
#define FRAME_MOUTH_03_COLUMN_0_SEQ_PATCH_2 FRAME_MOUTH_IDLE_COLUMN_PATCH_2
//----//

#define FRAME_MOUTH_03 { { FRAME_MOUTH_03_COLUMN_0_SEQ_PATCH_1, FRAME_MOUTH_03_COLUMN_0_SEQ_PATCH_1, FRAME_MOUTH_03_COLUMN_0_SEQ_PATCH_1, FRAME_MOUTH_03_COLUMN_0_SEQ_PATCH_1 }, \
{ FRAME_MOUTH_03_COLUMN_0_SEQ_0, FRAME_MOUTH_03_COLUMN_0_SEQ_1, FRAME_MOUTH_03_COLUMN_0_SEQ_1, FRAME_MOUTH_03_COLUMN_0_SEQ_1 }, \
{ FRAME_MOUTH_03_COLUMN_1_SEQ_0, FRAME_MOUTH_03_COLUMN_1_SEQ_0, FRAME_MOUTH_03_COLUMN_1_SEQ_0, FRAME_MOUTH_03_COLUMN_1_SEQ_0 }, \
{ FRAME_MOUTH_03_COLUMN_2_SEQ_0, FRAME_MOUTH_03_COLUMN_2_SEQ_1, FRAME_MOUTH_03_COLUMN_2_SEQ_2, FRAME_MOUTH_03_COLUMN_2_SEQ_2 }, \
{ FRAME_MOUTH_03_COLUMN_3_SEQ_0, FRAME_MOUTH_03_COLUMN_3_SEQ_1, FRAME_MOUTH_03_COLUMN_3_SEQ_2, FRAME_MOUTH_03_COLUMN_3_SEQ_2 }, \
{ FRAME_MOUTH_03_COLUMN_4_SEQ_0, FRAME_MOUTH_03_COLUMN_4_SEQ_1, FRAME_MOUTH_03_COLUMN_4_SEQ_1, FRAME_MOUTH_03_COLUMN_4_SEQ_1 }, \
{ FRAME_MOUTH_03_COLUMN_5_SEQ_0, FRAME_MOUTH_03_COLUMN_5_SEQ_1, FRAME_MOUTH_03_COLUMN_5_SEQ_2, FRAME_MOUTH_03_COLUMN_5_SEQ_3 }, \
{ FRAME_MOUTH_03_COLUMN_6_SEQ_0, FRAME_MOUTH_03_COLUMN_6_SEQ_1, FRAME_MOUTH_03_COLUMN_6_SEQ_2, FRAME_MOUTH_03_COLUMN_6_SEQ_2 }, \
{ FRAME_MOUTH_03_COLUMN_7_SEQ_0, FRAME_MOUTH_03_COLUMN_7_SEQ_1, FRAME_MOUTH_03_COLUMN_7_SEQ_1, FRAME_MOUTH_03_COLUMN_7_SEQ_1 }, \
{ FRAME_MOUTH_03_COLUMN_8_SEQ_0, FRAME_MOUTH_03_COLUMN_8_SEQ_1, FRAME_MOUTH_03_COLUMN_8_SEQ_1, FRAME_MOUTH_03_COLUMN_8_SEQ_1 }, \
{ FRAME_MOUTH_03_COLUMN_0_SEQ_PATCH_2, FRAME_MOUTH_03_COLUMN_0_SEQ_PATCH_2, FRAME_MOUTH_03_COLUMN_0_SEQ_PATCH_2, FRAME_MOUTH_03_COLUMN_0_SEQ_PATCH_2 }  \
}
///------------------///
#define FRAME_MOUTH_04_COLUMN_0_SEQ_PATCH_1 FRAME_MOUTH_IDLE_COLUMN_PATCH_1
//----//
#define FRAME_MOUTH_04_COLUMN_0_SEQ_0 FRAME_MOUTH_IDLE_COLUMN_0
//----//
#define FRAME_MOUTH_04_COLUMN_1_SEQ_0 FRAME_MOUTH_IDLE_COLUMN_1
#define FRAME_MOUTH_04_COLUMN_1_SEQ_1 (FRAME_MOUTH_IDLE_COLUMN_1>>1)
//----//
#define FRAME_MOUTH_04_COLUMN_2_SEQ_0 FRAME_MOUTH_IDLE_COLUMN_2
#define FRAME_MOUTH_04_COLUMN_2_SEQ_1 ((FRAME_MOUTH_IDLE_COLUMN_2<<1)+FRAME_MOUTH_IDLE_COLUMN_2)
//----//
#define FRAME_MOUTH_04_COLUMN_3_SEQ_0 FRAME_MOUTH_IDLE_COLUMN_3
#define FRAME_MOUTH_04_COLUMN_3_SEQ_1 (FRAME_MOUTH_IDLE_COLUMN_3<<1)
#define FRAME_MOUTH_04_COLUMN_3_SEQ_2 ((FRAME_MOUTH_IDLE_COLUMN_3<<1)+(FRAME_MOUTH_IDLE_COLUMN_3<<2))
#define FRAME_MOUTH_04_COLUMN_3_SEQ_3 ((FRAME_MOUTH_IDLE_COLUMN_3<<2)+(FRAME_MOUTH_IDLE_COLUMN_3<<3))
//----//
#define FRAME_MOUTH_04_COLUMN_4_SEQ_0 FRAME_MOUTH_IDLE_COLUMN_4
#define FRAME_MOUTH_04_COLUMN_4_SEQ_1 ((FRAME_MOUTH_IDLE_COLUMN_4<<1)+FRAME_MOUTH_IDLE_COLUMN_4)
//----//
#define FRAME_MOUTH_04_COLUMN_5_SEQ_0 FRAME_MOUTH_IDLE_COLUMN_5
#define FRAME_MOUTH_04_COLUMN_5_SEQ_1 (FRAME_MOUTH_IDLE_COLUMN_5>>1)
#define FRAME_MOUTH_04_COLUMN_5_SEQ_2 ((FRAME_MOUTH_IDLE_COLUMN_5>>1)+(FRAME_MOUTH_IDLE_COLUMN_5>>2))
//----//
#define FRAME_MOUTH_04_COLUMN_6_SEQ_0 FRAME_MOUTH_IDLE_COLUMN_6
#define FRAME_MOUTH_04_COLUMN_6_SEQ_1 ((FRAME_MOUTH_IDLE_COLUMN_6>>1)+FRAME_MOUTH_IDLE_COLUMN_6)
//----//
#define FRAME_MOUTH_04_COLUMN_7_SEQ_0 FRAME_MOUTH_IDLE_COLUMN_7
#define FRAME_MOUTH_04_COLUMN_7_SEQ_1 (FRAME_MOUTH_IDLE_COLUMN_7<<1)
//----//
#define FRAME_MOUTH_04_COLUMN_8_SEQ_0 FRAME_MOUTH_IDLE_COLUMN_8
//----//
#define FRAME_MOUTH_04_COLUMN_0_SEQ_PATCH_2 FRAME_MOUTH_IDLE_COLUMN_PATCH_2
//----//

#define FRAME_MOUTH_04 { { FRAME_MOUTH_04_COLUMN_0_SEQ_PATCH_1, FRAME_MOUTH_04_COLUMN_0_SEQ_PATCH_1, FRAME_MOUTH_04_COLUMN_0_SEQ_PATCH_1, FRAME_MOUTH_04_COLUMN_0_SEQ_PATCH_1 }, \
{ FRAME_MOUTH_04_COLUMN_0_SEQ_0, FRAME_MOUTH_04_COLUMN_0_SEQ_0, FRAME_MOUTH_04_COLUMN_0_SEQ_0, FRAME_MOUTH_04_COLUMN_0_SEQ_0 }, \
{ FRAME_MOUTH_04_COLUMN_1_SEQ_0, FRAME_MOUTH_04_COLUMN_1_SEQ_1, FRAME_MOUTH_04_COLUMN_1_SEQ_1, FRAME_MOUTH_04_COLUMN_1_SEQ_1 }, \
{ FRAME_MOUTH_04_COLUMN_2_SEQ_0, FRAME_MOUTH_04_COLUMN_2_SEQ_1, FRAME_MOUTH_04_COLUMN_2_SEQ_1, FRAME_MOUTH_04_COLUMN_2_SEQ_1 }, \
{ FRAME_MOUTH_04_COLUMN_3_SEQ_0, FRAME_MOUTH_04_COLUMN_3_SEQ_1, FRAME_MOUTH_04_COLUMN_3_SEQ_2, FRAME_MOUTH_04_COLUMN_3_SEQ_3 }, \
{ FRAME_MOUTH_04_COLUMN_4_SEQ_0, FRAME_MOUTH_04_COLUMN_4_SEQ_1, FRAME_MOUTH_04_COLUMN_4_SEQ_1, FRAME_MOUTH_04_COLUMN_4_SEQ_1 }, \
{ FRAME_MOUTH_04_COLUMN_5_SEQ_0, FRAME_MOUTH_04_COLUMN_5_SEQ_1, FRAME_MOUTH_04_COLUMN_5_SEQ_2, FRAME_MOUTH_04_COLUMN_5_SEQ_2 }, \
{ FRAME_MOUTH_04_COLUMN_6_SEQ_0, FRAME_MOUTH_04_COLUMN_6_SEQ_1, FRAME_MOUTH_04_COLUMN_6_SEQ_1, FRAME_MOUTH_04_COLUMN_6_SEQ_1 }, \
{ FRAME_MOUTH_04_COLUMN_7_SEQ_0, FRAME_MOUTH_04_COLUMN_7_SEQ_1, FRAME_MOUTH_04_COLUMN_7_SEQ_1, FRAME_MOUTH_04_COLUMN_7_SEQ_1 }, \
{ FRAME_MOUTH_04_COLUMN_8_SEQ_0, FRAME_MOUTH_04_COLUMN_8_SEQ_0, FRAME_MOUTH_04_COLUMN_8_SEQ_0, FRAME_MOUTH_04_COLUMN_8_SEQ_0 }, \
{ FRAME_MOUTH_04_COLUMN_0_SEQ_PATCH_2, FRAME_MOUTH_04_COLUMN_0_SEQ_PATCH_2, FRAME_MOUTH_04_COLUMN_0_SEQ_PATCH_2, FRAME_MOUTH_04_COLUMN_0_SEQ_PATCH_2 }  \
}
///------------------///
#define FRAME_MOUTH_05_COLUMN_0_SEQ_PATCH_1 FRAME_MOUTH_IDLE_COLUMN_PATCH_1
//----//
#define FRAME_MOUTH_05_COLUMN_0_SEQ_0 FRAME_MOUTH_IDLE_COLUMN_0
//----//
#define FRAME_MOUTH_05_COLUMN_1_SEQ_0 FRAME_MOUTH_IDLE_COLUMN_1
#define FRAME_MOUTH_05_COLUMN_1_SEQ_1 (FRAME_MOUTH_IDLE_COLUMN_1>>1)
#define FRAME_MOUTH_05_COLUMN_1_SEQ_2 ((FRAME_MOUTH_IDLE_COLUMN_1>>1)+FRAME_MOUTH_IDLE_COLUMN_1)
//----//
#define FRAME_MOUTH_05_COLUMN_2_SEQ_0 FRAME_MOUTH_IDLE_COLUMN_2
#define FRAME_MOUTH_05_COLUMN_2_SEQ_1 (FRAME_MOUTH_IDLE_COLUMN_2>>1)
#define FRAME_MOUTH_05_COLUMN_2_SEQ_2 ((FRAME_MOUTH_IDLE_COLUMN_2>>1)+(FRAME_MOUTH_IDLE_COLUMN_2>>2))
//----//
#define FRAME_MOUTH_05_COLUMN_3_SEQ_0 FRAME_MOUTH_IDLE_COLUMN_3
#define FRAME_MOUTH_05_COLUMN_3_SEQ_1 ((FRAME_MOUTH_IDLE_COLUMN_3<<1)+FRAME_MOUTH_IDLE_COLUMN_3)
//----//
#define FRAME_MOUTH_05_COLUMN_4_SEQ_0 FRAME_MOUTH_IDLE_COLUMN_4
#define FRAME_MOUTH_05_COLUMN_4_SEQ_1 (FRAME_MOUTH_IDLE_COLUMN_4<<1)
#define FRAME_MOUTH_05_COLUMN_4_SEQ_2 ((FRAME_MOUTH_IDLE_COLUMN_4<<1)+(FRAME_MOUTH_IDLE_COLUMN_4<<2))
#define FRAME_MOUTH_05_COLUMN_4_SEQ_3 ((FRAME_MOUTH_IDLE_COLUMN_4<<2)+(FRAME_MOUTH_IDLE_COLUMN_4<<3))
//----//
#define FRAME_MOUTH_05_COLUMN_5_SEQ_0 FRAME_MOUTH_IDLE_COLUMN_5
#define FRAME_MOUTH_05_COLUMN_5_SEQ_1 ((FRAME_MOUTH_IDLE_COLUMN_5<<1)+FRAME_MOUTH_IDLE_COLUMN_5)
//----//
#define FRAME_MOUTH_05_COLUMN_6_SEQ_0 FRAME_MOUTH_IDLE_COLUMN_6
#define FRAME_MOUTH_05_COLUMN_6_SEQ_1 (FRAME_MOUTH_IDLE_COLUMN_6>>1)
#define FRAME_MOUTH_05_COLUMN_6_SEQ_2 ((FRAME_MOUTH_IDLE_COLUMN_6>>1)+(FRAME_MOUTH_IDLE_COLUMN_6>>2))
//----//
#define FRAME_MOUTH_05_COLUMN_7_SEQ_0 FRAME_MOUTH_IDLE_COLUMN_7
#define FRAME_MOUTH_05_COLUMN_7_SEQ_1 ((FRAME_MOUTH_IDLE_COLUMN_7<<1)+FRAME_MOUTH_IDLE_COLUMN_7)
//----//
#define FRAME_MOUTH_05_COLUMN_8_SEQ_0 FRAME_MOUTH_IDLE_COLUMN_8
#define FRAME_MOUTH_05_COLUMN_8_SEQ_1 (FRAME_MOUTH_IDLE_COLUMN_8<<1)
//----//
#define FRAME_MOUTH_05_COLUMN_0_SEQ_PATCH_2 FRAME_MOUTH_IDLE_COLUMN_PATCH_2
//----//

#define FRAME_MOUTH_05 { { FRAME_MOUTH_05_COLUMN_0_SEQ_PATCH_1, FRAME_MOUTH_05_COLUMN_0_SEQ_PATCH_1, FRAME_MOUTH_05_COLUMN_0_SEQ_PATCH_1, FRAME_MOUTH_05_COLUMN_0_SEQ_PATCH_1 }, \
{ FRAME_MOUTH_05_COLUMN_0_SEQ_0, FRAME_MOUTH_05_COLUMN_0_SEQ_0, FRAME_MOUTH_05_COLUMN_0_SEQ_0, FRAME_MOUTH_05_COLUMN_0_SEQ_0 }, \
{ FRAME_MOUTH_05_COLUMN_1_SEQ_0, FRAME_MOUTH_05_COLUMN_1_SEQ_1, FRAME_MOUTH_05_COLUMN_1_SEQ_2, FRAME_MOUTH_05_COLUMN_1_SEQ_2 }, \
{ FRAME_MOUTH_05_COLUMN_2_SEQ_0, FRAME_MOUTH_05_COLUMN_2_SEQ_1, FRAME_MOUTH_05_COLUMN_2_SEQ_2, FRAME_MOUTH_05_COLUMN_2_SEQ_2 }, \
{ FRAME_MOUTH_05_COLUMN_3_SEQ_0, FRAME_MOUTH_05_COLUMN_3_SEQ_1, FRAME_MOUTH_05_COLUMN_3_SEQ_1, FRAME_MOUTH_05_COLUMN_3_SEQ_1 }, \
{ FRAME_MOUTH_05_COLUMN_4_SEQ_0, FRAME_MOUTH_05_COLUMN_4_SEQ_1, FRAME_MOUTH_05_COLUMN_4_SEQ_2, FRAME_MOUTH_05_COLUMN_4_SEQ_3 }, \
{ FRAME_MOUTH_05_COLUMN_5_SEQ_0, FRAME_MOUTH_05_COLUMN_5_SEQ_1, FRAME_MOUTH_05_COLUMN_5_SEQ_1, FRAME_MOUTH_05_COLUMN_5_SEQ_1 }, \
{ FRAME_MOUTH_05_COLUMN_6_SEQ_0, FRAME_MOUTH_05_COLUMN_6_SEQ_1, FRAME_MOUTH_05_COLUMN_6_SEQ_2, FRAME_MOUTH_05_COLUMN_6_SEQ_2 }, \
{ FRAME_MOUTH_05_COLUMN_7_SEQ_0, FRAME_MOUTH_05_COLUMN_7_SEQ_1, FRAME_MOUTH_05_COLUMN_7_SEQ_1, FRAME_MOUTH_05_COLUMN_7_SEQ_1 }, \
{ FRAME_MOUTH_05_COLUMN_8_SEQ_0, FRAME_MOUTH_05_COLUMN_8_SEQ_1, FRAME_MOUTH_05_COLUMN_8_SEQ_1, FRAME_MOUTH_05_COLUMN_8_SEQ_1 }, \
{ FRAME_MOUTH_05_COLUMN_0_SEQ_PATCH_2, FRAME_MOUTH_05_COLUMN_0_SEQ_PATCH_2, FRAME_MOUTH_05_COLUMN_0_SEQ_PATCH_2, FRAME_MOUTH_05_COLUMN_0_SEQ_PATCH_2 }  \
}
///------------------///
#define FRAME_MOUTH_06_COLUMN_0_SEQ_PATCH_1 FRAME_MOUTH_IDLE_COLUMN_PATCH_1
//----//
#define FRAME_MOUTH_06_COLUMN_0_SEQ_0 FRAME_MOUTH_IDLE_COLUMN_0
#define FRAME_MOUTH_06_COLUMN_0_SEQ_1 (FRAME_MOUTH_IDLE_COLUMN_0<<1)
//----//
#define FRAME_MOUTH_06_COLUMN_1_SEQ_0 FRAME_MOUTH_IDLE_COLUMN_1
//----//
#define FRAME_MOUTH_06_COLUMN_2_SEQ_0 FRAME_MOUTH_IDLE_COLUMN_2
#define FRAME_MOUTH_06_COLUMN_2_SEQ_1 (FRAME_MOUTH_IDLE_COLUMN_2>>1)
#define FRAME_MOUTH_06_COLUMN_2_SEQ_2 ((FRAME_MOUTH_IDLE_COLUMN_2>>1)+FRAME_MOUTH_IDLE_COLUMN_2)
//----//
#define FRAME_MOUTH_06_COLUMN_3_SEQ_0 FRAME_MOUTH_IDLE_COLUMN_3
#define FRAME_MOUTH_06_COLUMN_3_SEQ_1 (FRAME_MOUTH_IDLE_COLUMN_3>>1)
#define FRAME_MOUTH_06_COLUMN_3_SEQ_2 ((FRAME_MOUTH_IDLE_COLUMN_3>>1)+(FRAME_MOUTH_IDLE_COLUMN_3>>2))
//----//
#define FRAME_MOUTH_06_COLUMN_4_SEQ_0 FRAME_MOUTH_IDLE_COLUMN_4
#define FRAME_MOUTH_06_COLUMN_4_SEQ_1 ((FRAME_MOUTH_IDLE_COLUMN_4<<1)+FRAME_MOUTH_IDLE_COLUMN_4)
//----//
#define FRAME_MOUTH_06_COLUMN_5_SEQ_0 FRAME_MOUTH_IDLE_COLUMN_5
#define FRAME_MOUTH_06_COLUMN_5_SEQ_1 (FRAME_MOUTH_IDLE_COLUMN_5<<1)
#define FRAME_MOUTH_06_COLUMN_5_SEQ_2 ((FRAME_MOUTH_IDLE_COLUMN_5<<1)+(FRAME_MOUTH_IDLE_COLUMN_5<<2))
#define FRAME_MOUTH_06_COLUMN_5_SEQ_3 ((FRAME_MOUTH_IDLE_COLUMN_5<<1)+(FRAME_MOUTH_IDLE_COLUMN_5<<3))
//----//
#define FRAME_MOUTH_06_COLUMN_6_SEQ_0 FRAME_MOUTH_IDLE_COLUMN_6
#define FRAME_MOUTH_06_COLUMN_6_SEQ_1 (FRAME_MOUTH_IDLE_COLUMN_6<<1)
#define FRAME_MOUTH_06_COLUMN_6_SEQ_2 ((FRAME_MOUTH_IDLE_COLUMN_6<<1)+FRAME_MOUTH_IDLE_COLUMN_6)
//----//
#define FRAME_MOUTH_06_COLUMN_7_SEQ_0 FRAME_MOUTH_IDLE_COLUMN_7
#define FRAME_MOUTH_06_COLUMN_7_SEQ_1 ((FRAME_MOUTH_IDLE_COLUMN_7>>1)+(FRAME_MOUTH_IDLE_COLUMN_7>>2))
//----//
#define FRAME_MOUTH_06_COLUMN_8_SEQ_0 FRAME_MOUTH_IDLE_COLUMN_8
#define FRAME_MOUTH_06_COLUMN_8_SEQ_1 ((FRAME_MOUTH_IDLE_COLUMN_8<<1)+FRAME_MOUTH_IDLE_COLUMN_8)
//----//
#define FRAME_MOUTH_06_COLUMN_0_SEQ_PATCH_2 FRAME_MOUTH_IDLE_COLUMN_PATCH_2
//----//

#define FRAME_MOUTH_06 { { FRAME_MOUTH_06_COLUMN_0_SEQ_PATCH_1, FRAME_MOUTH_06_COLUMN_0_SEQ_PATCH_1, FRAME_MOUTH_06_COLUMN_0_SEQ_PATCH_1, FRAME_MOUTH_06_COLUMN_0_SEQ_PATCH_1 }, \
{ FRAME_MOUTH_06_COLUMN_0_SEQ_0, FRAME_MOUTH_06_COLUMN_0_SEQ_1, FRAME_MOUTH_06_COLUMN_0_SEQ_1, FRAME_MOUTH_06_COLUMN_0_SEQ_1 }, \
{ FRAME_MOUTH_06_COLUMN_1_SEQ_0, FRAME_MOUTH_06_COLUMN_1_SEQ_0, FRAME_MOUTH_06_COLUMN_1_SEQ_0, FRAME_MOUTH_06_COLUMN_1_SEQ_0 }, \
{ FRAME_MOUTH_06_COLUMN_2_SEQ_0, FRAME_MOUTH_06_COLUMN_2_SEQ_1, FRAME_MOUTH_06_COLUMN_2_SEQ_2, FRAME_MOUTH_06_COLUMN_2_SEQ_2 }, \
{ FRAME_MOUTH_06_COLUMN_3_SEQ_0, FRAME_MOUTH_06_COLUMN_3_SEQ_1, FRAME_MOUTH_06_COLUMN_3_SEQ_2, FRAME_MOUTH_06_COLUMN_3_SEQ_2 }, \
{ FRAME_MOUTH_06_COLUMN_4_SEQ_0, FRAME_MOUTH_06_COLUMN_4_SEQ_1, FRAME_MOUTH_06_COLUMN_4_SEQ_1, FRAME_MOUTH_06_COLUMN_4_SEQ_1 }, \
{ FRAME_MOUTH_06_COLUMN_5_SEQ_0, FRAME_MOUTH_06_COLUMN_5_SEQ_1, FRAME_MOUTH_06_COLUMN_5_SEQ_2, FRAME_MOUTH_06_COLUMN_5_SEQ_3 }, \
{ FRAME_MOUTH_06_COLUMN_6_SEQ_0, FRAME_MOUTH_06_COLUMN_6_SEQ_1, FRAME_MOUTH_06_COLUMN_6_SEQ_2, FRAME_MOUTH_06_COLUMN_6_SEQ_2 }, \
{ FRAME_MOUTH_06_COLUMN_7_SEQ_0, FRAME_MOUTH_06_COLUMN_7_SEQ_1, FRAME_MOUTH_06_COLUMN_7_SEQ_1, FRAME_MOUTH_06_COLUMN_7_SEQ_1 }, \
{ FRAME_MOUTH_06_COLUMN_8_SEQ_0, FRAME_MOUTH_06_COLUMN_8_SEQ_1, FRAME_MOUTH_06_COLUMN_8_SEQ_1, FRAME_MOUTH_06_COLUMN_8_SEQ_1 }, \
{ FRAME_MOUTH_06_COLUMN_0_SEQ_PATCH_2, FRAME_MOUTH_06_COLUMN_0_SEQ_PATCH_2, FRAME_MOUTH_06_COLUMN_0_SEQ_PATCH_2, FRAME_MOUTH_06_COLUMN_0_SEQ_PATCH_2 }  \
}



void init_modeSoundWave_Adc(void);
void reset(void);
void checkClipping(void);

int get_led_number_col_1(int row);
int get_led_number_col_2(int row);
int get_led_number_col_3(int row);
int get_led_number_col_4(int row);
int get_led_number_col_5(int row);
int get_led_number_col_6(int row);
int get_led_number_col_7(int row);
int get_led_number_col_8(int row);
int get_led_number_col_9(int row);
int get_led_number_col_10(int row);
int get_led_number_col_11(int row);
void set_mouth(int col, int row, uint8_t R,uint8_t G,uint8_t B);
void process_mouth(int amplitude, int frequency);


#endif /* MODESOUNDWAVE_ADC_H_ */
