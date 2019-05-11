#include "philosopher.h"
#include "Producer_Customer_1to1.h"
#include "Producer_Customer_NtoN.h"


void philosopher_init();
void producer_customer_1to1_init();
void producer_customer_NtoN_init();

int main() {
	//philosopher_init();
	//producer_customer_1to1_init();
	producer_customer_NtoN_init();
}


void philosopher_init() {

	//一个哲学家线程vector
	vector<std::thread> philosophers_thread;
	//一个哲学家对象数组
	vector<philosopher> philosophers;

	//初始化所以哲学家，并将所以哲学家放入到哲学家数组中
	for (int i = 0; i < philosopherNum - 1; i++) {
		philosopher philosopher_demo = philosopher(i + 1);
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
void producer_customer_1to1_init() {
	Producer_Customer_1to1 demo = Producer_Customer_1to1();
	std::thread producer(&Producer_Customer_1to1::producer_task, std::ref(demo));
	std::thread customer(&Producer_Customer_1to1::customer_task, std::ref(demo));
	producer.join();
	customer.join();
}
void producer_customer_NtoN_init() {
	Producer_Customer_NtoN demo = Producer_Customer_NtoN();
	std::thread producer1(&Producer_Customer_NtoN::producer_task, std::ref(demo));
	/*std::thread customer1(&Producer_Customer_NtoN::customer_task, std::ref(demo));
	std::thread producer2(&Producer_Customer_NtoN::producer_task, std::ref(demo));
	::thread customer2(&Producer_Customer_NtoN::customer_task, std::ref(demo));
	std::thread producer3(&Producer_Customer_NtoN::producer_task, std::ref(demo));
	std::thread customer3(&Producer_Customer_NtoN::customer_task, std::ref(demo));*/
	producer1.join();
	//customer1.join();
	//producer2.join();
	//customer2.join();
	//producer3.join();
	//customer3.join();
}
