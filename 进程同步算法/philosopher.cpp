
/**************************************************
@brief   : 哲学家就餐的实现文件（使用两种方法解决死锁问题：1、使用And型信号量机制）2、最多只有N-1个人同时就餐
@author  : 渠继涵
@time    : 2019/05/07 8:12
**************************************************/

#include "philosopher.h"
#include <iostream>
#include <Windows.h>
using namespace std;

philosopher::philosopher(int num) {
	this->num = num;
	this->statue = Thinking;
}

philosopher::philosopher() {
	this->statue = Thinking;
}

//吃饭的过程
void philosopher::start_eat() {
	std::lock(chopsticks[num], chopsticks[(num + 1) % philosopherNum]);	//使用and型信号量解决死锁问题
	io_mutex.lock();
	cout << "第" << num << "个哲学家拿起了筷子，开始吃饭了！" << endl;
	io_mutex.unlock();
	this->statue = Eating;
}

//吃完饭放下筷子开始思考
void philosopher::start_think() {

	chopsticks[num].unlock();
	chopsticks[(num + 1) % philosopherNum].unlock();
	io_mutex.lock();
	cout << "\t第" << num << "个哲学家吃完了饭，放下了筷子！开始思考" << endl;
	io_mutex.unlock();
	this->statue = Thinking;
}


void philosopher::start() {
	int loop_num = 7 ;
	for (int i = 0; i < loop_num; i++) {
		start_eat();
		Sleep(300);
		start_think();
		Sleep(300);
	}

}



