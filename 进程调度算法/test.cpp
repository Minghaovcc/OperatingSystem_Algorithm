#include "PCB.h"
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

void init(int num);

int main() {
	//输入进程个数
	int num;
	cout << "输入进程个数：" << endl;
	cin >> num;
	init(num);
	PCB::disp_list();


	cout << "========短作业优先调度算法========" << endl;
	PCB::SJFrun();
	cout << "=====动态高优先级优先调度算法=====" << endl;
	PCB::PSArun();

	cout << "========先到先服务调度算法========" << endl;
	PCB::FCFSrun();
	


	return 0;
}


void init(int num) {
	//进程个数
	int time, priority;
	PCB *pcb[3];
	while (num--) {
		//进程需要的时间
		cin >> time;
		//进程优先级
		cin >> priority;
		pcb[num] = new PCB(time, priority);
	}
}