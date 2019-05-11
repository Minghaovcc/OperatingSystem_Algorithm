#include "Producer_Customer_NtoN.h"
#include <iostream>
#include <Windows.h>

using namespace std;

Producer_Customer_NtoN::Producer_Customer_NtoN() {
	int read_position = 0;
	int write_position = 0;
	int produced_counter = 0;
	int consumed_counter = 0;
}

void Producer_Customer_NtoN::producer_item(int i) {
	int item = i;
	//上锁
	std::unique_lock < std::mutex> lock(buffermutex_NtoN);
	//生产者等待“缓冲区不满”这个条件的发生
	while ((write_position_NtoN+1) % buffer_size_NtoN == read_position_NtoN) {
		iomutex_NtoN.lock();
		cout << ".......生产者：在等待仓库有空余地方......." << endl;
		iomutex_NtoN.unlock();
		repo_not_full_NtoN.wait(lock);
	}
	//生产者生产产品
	buffer_NtoN[write_position_NtoN] = item;
	write_position_NtoN++;


	if (write_position_NtoN == buffer_size_NtoN) write_position_NtoN = 0;	//如果到了最后一个，就回到第一个，实现循环
	//通知消费者“缓冲区不空”
	repo_not_empty_NtoN.notify_all();
	//解锁
	lock.unlock();
}

int Producer_Customer_NtoN::customer_item() {
	int item;
	//上锁
	std::unique_lock<std::mutex> lock(buffermutex_NtoN);
	//消费者等待“缓冲区不空”这个条件的发生
	while (write_position_NtoN == read_position_NtoN) {
		iomutex_NtoN.lock();
		cout << ".......消费者：在等待仓库有产品......." << endl;
		iomutex_NtoN.unlock();
		repo_not_empty_NtoN.wait(lock);
	}
	//消费者消费产品
	item = buffer_NtoN[read_position_NtoN];
	read_position_NtoN++;
	if (read_position_NtoN == buffer_size_NtoN) read_position_NtoN = 0;
	//通知生产者“缓冲区不满”
	repo_not_full_NtoN.notify_all();
	//解锁
	lock.unlock();

	return item;
}

void Producer_Customer_NtoN::producer_task() {
	bool exit = false;
	while (true) {
		
		//加锁
		std::unique_lock<std::mutex> lock(produced_counter_mutex_NtoN);
		iomutex_NtoN.lock();
		cout << "\tNo." << std::this_thread::get_id() << "\t生产者，来了！" << endl;
		iomutex_NtoN.unlock();
		//判断生产
		if (produced_counter <pruduce_plan_NtoN) {
			++produced_counter;
			producer_item(produced_counter);
			iomutex_NtoN.lock();
			cout << "No." << std::this_thread::get_id() << "\t生产者，生产了第" << produced_counter << "件商品！" << endl;
			iomutex_NtoN.unlock();
		} else {
			exit = true;
		}
		//解锁
		lock.unlock();
		Sleep(600);
		iomutex_NtoN.lock();
		cout << "No." << std::this_thread::get_id() << "\t生产者，离开了！" << endl;
		iomutex_NtoN.unlock();
		//生产结束，退出
		if (exit) break;
	}
}

void Producer_Customer_NtoN::customer_task() {
	bool exit = false;
	while (true) {
		Sleep(3000);
		//加锁
		std::unique_lock<std::mutex> lock(consumed_counter_mutex_NtoN);
		iomutex_NtoN.lock();
		cout << "\tNo." << std::this_thread::get_id() << "\t消费者，来了！" << endl;
		iomutex_NtoN.unlock();
		//判断生产
		if (consumed_counter < pruduce_plan_NtoN) {
			int item = customer_item();
			iomutex_NtoN.lock();
			cout << "\tNo." << std::this_thread::get_id() << "\t消费者，消费了第" << item << "件商品！" << endl;
			iomutex_NtoN.unlock();
		} else {
			exit = true;
		}
		//解锁
		lock.unlock();
		//Sleep(3000);
		iomutex_NtoN.lock();
		cout << "\tNo." << std::this_thread::get_id() << "\t消费者，离开了！" << endl;
		iomutex_NtoN.unlock();
		//生产结束，退出
		if (exit) break;
	}
}
