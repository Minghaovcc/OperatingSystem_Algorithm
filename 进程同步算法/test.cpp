#include "philosopher.h"
#include <vector>


using namespace std;

//哲学家就餐进程初始化
void philosopher_init();





int main() {
	philosopher_init();
}


void philosopher_init() {

	//一个哲学家线程vector
	vector<std::thread> philosophers_thread;
	//一个哲学家对象数组
	vector<philosopher> philosophers;

	//初始化所以哲学家，并将所以哲学家放入到哲学家数组中
	for (int i = 0; i < philosopherNum - 1; i++) {
		philosopher philosopher_demo = philosopher(i+1);
		philosophers.push_back(philosopher_demo);
	}

	//初始化所以哲学家进程，并将所有的哲学家进程放在哲学家进程数组里面
	for (unsigned int i = 0; i < philosophers.size(); i++) {
		philosophers_thread.push_back(thread(&philosopher::start, &philosophers[i]));
	}

	//所有哲学家进程开始运行
	for (unsigned int i = 0; i < philosophers.size(); i++) {
		philosophers_thread[i].join();
	}
}