#ifndef _PCB_H_
#define _PCB_H_
#include <iostream>
#include <list>

using namespace std;

class PCB {
public:
	PCB(int time, int priority);	//构造函数，time：运行需要的时间，priority：优先级
	~PCB();
	void disp();	//显示当前进程的信息



	bool run_this_by_priority();	//运行当前的进程(动态高优先级优先调度算法)
	bool run_this_by_number();	//运行当前的进程(先到先服务调度算法)
	bool run_this_by_time_needed();	//运行当前的进程(短作业优先调度算法)
	static int size;	//队列中的进程数量
	static list<PCB*> pcb_list;	//进程队列
	static void disp_list();	//显示所有队列的信息
	static bool compare_pcb_by_priority(const PCB* f, const PCB* s);	//比较两个进程的优先级f>s?
	static bool compare_pcb_by_number(const PCB* f, const PCB* s);	//比较两个进程的优先级f>s?
	static bool compare_pcb_by_time_needed(const PCB* f, const PCB* s);	//比较两个进程的优先级f>s?
	static void PSArun();	//运行当前进程队列(动态高优先级优先调度算法)
	static void FCFSrun();	//运行当前进程队列(先到先服务调度算法)
	static void SJFrun();	//运行当前进程队列(短作业优先调度算法)



private:
	int name;	//进程名称
	int number;	//进程顺序
	int priority_number;	//进程优先级
	int time_needed;	//进程需要运行的时间
	char state;	//进程的状态，R：就绪，E：结束
	
};

#endif // !_PCB_H_
