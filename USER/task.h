#ifndef __TASK_H
#define __TASK_H

#include "stm32f10x.h"

typedef struct {
	u8 Run;			 		//Task run flag.
	u8 Foreground;			//Task Foreground flag.
	uint32_t Timer;			//Timer.
	uint32_t ItvTime;		//Task run interval.
	void (*TaskHook)(void); //The task process function.
}TASK_COMPONENTS;


void TaskRemarks(void);
void TaskProcess(void);

#endif

