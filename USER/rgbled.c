#include "rgbled.h"
#include "ws2812b.h"
#include "flower.h"
#define COLORSTATENUM 3


u8 ColorState = 0;
RGB_Color_Struct myrgb1[LED_NUM]={0};

void SetLed2Red(u8 index){
	SetOneRgb(myrgb1, index, 0xff, 0, 0);
}
void SetLed2Green(u8 index){
	SetOneRgb(myrgb1, index, 0, 0xff, 0);
}
void SetLed2Blue(u8 index){
	SetOneRgb(myrgb1, index, 0, 0, 0xff);
}
void SetLed2White(u8 index){
	SetOneRgb(myrgb1, index, 0xff, 0xff, 0xff);
}

void RGBTask(void){
	if(ColorState < COLORSTATENUM-1){
		ColorState++;
	}else{
		ColorState = 0;
	}
	switch(ColorState){
		case RED	: 	SetLed2Red(0);
						break;
		case GREEN	:	SetLed2Green(0);
						break;
		case BLUE	:	SetLed2Blue(0);
						break;
		default		:	SetLed2White(0);
						break;
	}
	ReflashRGB(myrgb1);
}
