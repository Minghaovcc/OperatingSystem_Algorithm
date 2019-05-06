#include "pcb.h"
#include <iostream>
#include <list>

const int MIN = -32767;	//进程结束之后的优先级（int可以表示的最小数）

using namespace std;

//构造函数
PCB::PCB(int time, int priority) {
	name = ++size;
	time_needed = time;
	priority_number = priority;
	state = 'R';
	pcb_list.push_back(this);
}


//析构函数
PCB::~PCB() {
	size--;
}

//显示进程的信息
void PCB::disp() {
	cout << "Process" << name << "\t\t" << time_needed << "\t\t" << priority_number << "\t\t" << state << endl;
}

//比较两个进程的优先级f>s?
bool PCB::compare_pcb(const PCB* f, const PCB* s) {
	return f->priority_number > s->priority_number;
}


//运行当前的进程
bool PCB::run_this() {
	bool flag = false;
	if (this->time_needed <= 0 || this->state == 'E') {
		size--;
		this->priority_number = MIN;
		this->state = 'E';
		flag = false;
	} else {
		this->priority_number--;
		this->time_needed--;
		if (this->time_needed <= 0) this->state = 'E';
		flag = true;
	}

	return flag;
}

//显示所有队列的信息
void PCB::disp_list() {
	cout << "---------------------------------------------------" << endl;
	cout << "|Name\t\t" << "|Time_needed\t\t" << "|Priority_num\t\t" << "|State|" << endl;
	cout << "---------------------------------------------------" << endl;
	list <PCB*>::iterator plist;		//建立一个迭代器
	for (plist = pcb_list.begin(); plist != pcb_list.end(); plist++) {
		PCB* pcb;
		pcb = *plist;
		pcb->disp();
	}
	cout << endl;
}

//高优先权优先调度算法运行当前队列的进程
void PCB::PSArun() {
	disp_list();
	int i = 0;	//当前运行的进程数
	while (size > 0) {
		pcb_list.sort(compare_pcb);
		PCB* pcb;
		pcb = *pcb_list.begin();
		if (!pcb->run_this()) continue;
		cout << "Process_num:" << size << "\tRun:Process" << pcb->name << "\tStep:" << ++i << endl;
		disp_list();
	}
}


//高相应比优先算法
void PCB::HRRNrun() {

}

//短进程优先调度算法
void PCB::SJFrun(){

}

//先来先服务调度算法
void PCB::FCFSrun() {

}
