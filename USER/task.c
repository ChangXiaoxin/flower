#include "stm32f10x.h"
#include "task.h"
#include "taskdo.h"

#define TASK_NUM sizeof(TaskComps)/sizeof(TASK_COMPONENTS)		//Task number.

/**
  *@breif List of tasks.
  *--Initial run state 0: Stop 1: Run. 
  *--Initial foreground state 0: foreground 1: background.  
  *--Initial task time. 
  *--Overload task time.  *0.1ms
  *--Task function.
  */
static TASK_COMPONENTS TaskComps[]={		
	//show my logo using led.
	{0, 1, 1000, 1000, TaskLogoShow},
	//deal with rgb led.
	{0, 1, 10000, 10000, TaskRgbLed},
	{0, 1,  150,  150, TaskFlower}
};	

void TaskRemarks(void){			
	//Process the status of the task run.
	u8 i;
	for(i = 0; i < TASK_NUM; i++){
		if(TaskComps[i].Timer&&TaskComps[i].Foreground){		
			//Task time count.
			TaskComps[i].Timer--;
			if(TaskComps[i].Timer == 0){	
				//Count time overloads.
				TaskComps[i].Timer = TaskComps[i].ItvTime;
				//Run flag set 1, task run.
				TaskComps[i].Run = 1;		
			}
		}
	}
}

//Task processing.
void TaskProcess(void){			
	u8 i;
	for(i = 0; i < TASK_NUM; i++){
		if(TaskComps[i].Run){
			//Call the task function.
			TaskComps[i].TaskHook();	
			//Reset task Run flag.
			TaskComps[i].Run = 0;		
		}
	}
}


