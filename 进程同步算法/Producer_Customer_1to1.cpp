
/**************************************************
@brief   : 生产者消费者问题（一个生产者对一个消费者）
@author  : 渠继涵
@time    : 2019/05/05 11:23
**************************************************/

#include "Producer_Customer_1to1.h"
#include <iostream>
#include <Windows.h>

Producer_Customer_1to1::Producer_Customer_1to1() {
	int read_position = 0;
	int write_position = 0;
}

void Producer_Customer_1to1::producer_item(int i) {
	int item = i;
	//上锁
	std::unique_lock < std::mutex> lock(buffermutex);
	//生产者等待“缓冲区不满”这个条件的发生
	while ((write_position + 1) % buffer_size == read_position) {
		iomutex.lock();
		cout << "生产者：在等待仓库有空余地方...." << endl;
		iomutex.unlock();
		rope_not_full.wait(lock);
	}
	//生产者生产产品
	buffer[write_position] = item;
	write_position++;	
	if (write_position == buffer_size) write_position = 0;	//如果到了最后一个，就回到第一个，实现循环
	//通知消费者“缓冲区不空”
	rope_not_empty.notify_all();
	//解锁
	lock.unlock();
}

int Producer_Customer_1to1::customer_item() {
	int item;
	//上锁
	std::unique_lock<std::mutex> lock(buffermutex);
	//消费者等待“缓冲区不空”这个条件的发生
	while (write_position==read_position) {
		iomutex.lock();
		cout << "消费者：在等待仓库有产品...." << endl;
		iomutex.unlock();
		rope_not_empty.wait(lock);	
	}
	//消费者消费产品
	item = buffer[read_position];
	read_position++;
	if (read_position == buffer_size) read_position = 0;
	//通知生产者“缓冲区不满”
	rope_not_full.notify_all();
	//解锁
	lock.unlock();

	return item;
}

void Producer_Customer_1to1::producer_task() {
	//生产者根据定义的producer_plan循环生产产品
	for (int i = 0; i < pruduce_plan; i++) {
		Sleep(1000);
		producer_item(i);
		iomutex.lock();
		cout << "第" << i << "个产品已经生产出来啦！" << endl;
		iomutex.unlock();
	}
}

void Producer_Customer_1to1::customer_task() {
	//消费者消费产品，等消费数量达到producer_plan时退出
	while (true) {
		Sleep(5000);
		int item = customer_item();
		iomutex.lock();
		cout << "第" << item << "个产品已经被消费啦！" << endl;
		iomutex.unlock();
	}
}

