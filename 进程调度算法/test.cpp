#include "PCB.h"
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

int PCB::size = 0;
list<PCB*> PCB::pcb_list;


int main() {
	//进程个数
	int num = 3;
	int time, priority;
	//	cin >> num;
	PCB* pcb[3];


	while (num--) {
		//进程需要的时间
		cin >> time;
		//进程优先级
		cin >> priority;
		pcb[num] = new PCB(time, priority);
	}

	PCB::run();
	return 0;
}