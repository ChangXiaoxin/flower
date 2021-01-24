#include "task.h"
#include "taskdo.h"
#include "blink.h"
#include "rgbled.h"
#include "touch.h"
#include "petals.h"
#include "flower.h"

void TaskLogoShow(void){
	BlinkTask();
}

void TaskRgbLed(void){
	//RGBTask();
}

void TaskFlower(void){
	FlowerTask();
}
