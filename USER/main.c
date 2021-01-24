#include "task.h"
#include "timer.h"
#include "init.h"

int main(void){
	//Initialize on-chip resources and peripherals.
	TopInit(); 
	while(1){
		//Run the task process.
		TaskProcess();
	}
}



