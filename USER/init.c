#include "init.h"
#include "timer.h"
#include "blink.h"
#include "flower.h"

void TopInit(void){
	//Show my logo by led.	
	BlinkInit();					  
	
	//**********************************************************//
	FlowerInit();
	//**********************************************************//
	
	//ͨ�ö�ʱ��ʱ��72M����Ƶϵ��72������Ƶ��72M/72=1000Khz������100�Σ�0.1ms
	TIM3_init(TIM3_ARR,TIM3_PSC);	 
};

