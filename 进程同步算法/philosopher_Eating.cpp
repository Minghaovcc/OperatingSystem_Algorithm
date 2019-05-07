#include "philosopher.h"
#include <iostream>
#include <vector>

using namespace std;

void philosopher_init() {

	//一个哲学家线程vector
	vector<std::thread> philosophers_thread(philosopherNum);
	//一个哲学家对象数组
	vector<philosopher> philosophers(philosopherNum);

	//初始化所以哲学家，并将所以哲学家放入到哲学家数组中
	for (int i = 0; i < philosopherNum-1; i++) {
		philosopher philosopher_demo = philosopher(i);
		philosophers.push_back(philosopher_demo);
	}

	//初始化所以哲学家进程，并将所有的哲学家进程放在哲学家进程数组里面
	for (int i = 0; i < philosophers.size; i++) {
		//std::thread philosopher_thread(&philosopher::start, &philosophers[i]);
		philosophers_thread.push_back(thread(&philosopher::start, &philosophers[i]));
	}

	for (auto iter = philosophers_thread.begin(); iter != philosophers_thread.end(); ++iter) {
	}
}