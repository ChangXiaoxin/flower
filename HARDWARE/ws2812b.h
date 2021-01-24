#ifndef __WS2812B_H__
#define __WS2812B_H__
#include "stm32f10x.h"
#include "sys.h"

#define WSLED PBout(11)

typedef struct RGB_Color_Struct{
	u8 green;
	u8 red;
	u8 blue;	
}RGB_Color_Struct;

void Ws2812bInit(void);			//WS2812B GPIO pin initial.
								//(Note: Don't forget change the pin in func Ws2812bInit() before use it.)


//********************SetOneColor*****************************
//name: SetOneColor.
//disc: Set one led color data in the array color[].
//input: - *color: The array which save the led color data.
//		 -  index: The index of the led you want to change.
//		 -      r: The led red data.
//		 -      g: The led green data.
//		 -      b: The led blue data.
//*************************************************************/
void SetOneRgb(RGB_Color_Struct* color, u8 index, u8 r, u8 g ,u8 b);
void SetOneColor(RGB_Color_Struct* color, u8 index, RGB_Color_Struct color0);
void SetAllColor(RGB_Color_Struct* color, RGB_Color_Struct color0);

//********************ReflashRGB*****************************
//name: ReflashRGB.
//disc: Change all RGB led color with color[].
//input: - *color: The array which save the led color data.
//*************************************************************/
void ReflashRGB(RGB_Color_Struct* color);

#endif

