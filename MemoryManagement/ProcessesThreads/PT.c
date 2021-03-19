#include "stdio.h"
#include "ntk_5.4.h"
#include "PT.h"
unsigned __stdcall taskCode(void* arg);
void main() {
	task* t1 = (task*)malloc(sizeof(task));
	int par;
	startNTK();
	create_task(t1, taskCode, &par, sizeof(int), 0);
	//wait for 2 secs
	sleep(2000);
}

unsigned __stdcall taskCode(void* arg) {
	task* t = (task*)arg;
	//TypeA is the type of the parameter (int, string etc.).
	char* a = (char*)getArgument_task(t);
	while (!isTerminated_task(t)) {
		//...
		//	a->...
		//	...
		//	//Do work for 5 seconds
		//	....
	}
	//...
}