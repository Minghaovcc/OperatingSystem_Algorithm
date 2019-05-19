#include "PCB.h"
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

void init();

int main() {
	init();
	/*cout << "========先到先服务调度算法========" << endl;
	PCB::FCFSrun();
	cout << "========短作业优先调度算法========" << endl;
	PCB::SJFrun();*/
	cout << "=====动态高优先级优先调度算法=====" << endl;
	PCB::PSArun();
	return 0;
}


void init() {
	//进程个数
	//int time, priority, num;
	//cout << "输入进程个数：" << endl;
	//cin >> num;
	PCB *pcb[3];
	for (int i = 0; i < 3; i++) {
		//cin >> time;
		//进程优先级
		//cin >> priority;
		pcb[i] = new PCB(i+4, i+5);
	}
	
}