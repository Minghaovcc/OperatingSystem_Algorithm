#ifndef _PCB_H_
#define _PCB_H_
#include <iostream>
#include <list>

using namespace std;

class PCB {
public:
	PCB(int time, int priority);	//构造函数，time：运行需要的时间，priority：优先级
	~PCB();
	bool run_this();	//运行当前的进程
	void disp();	//显示当前进程的信息

	static int size;	//队列中的进程数量
	static void run();	//运行当前进程队列
	static list<PCB*> pcb_list;	//进程队列
	static void disp_list();	//显示所有队列的信息
	static bool compare_pcb(const PCB* f, const PCB* s);	//比较两个进程的优先级f>s?



private:
	int name;	//进程名称
	int priority_number;	//进程优先级
	int time_needed;	//进程需要运行的时间
	char state;	//进程的状态，R：就绪，E：结束
};

#endif // !_PCB_H_
