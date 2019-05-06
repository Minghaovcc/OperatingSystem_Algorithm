#include "PCB.h"
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

int PCB::size = 0;
list<PCB*> PCB::pcb_list;




int main() {
	//输入进程个数
	int num;
	cout << "输入进程个数：" << endl;
	cin >> num;
	init(num);
	cout << "=====高优先级优先调度算法=====" << endl;
	PCB::PSArun();
	cout << "=====高优先级优先调度算法=====" << endl;

	return 0;
}


void init(int num) {
	//进程个数
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
}