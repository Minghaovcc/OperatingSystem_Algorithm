#ifndef PRODUCER_CUSTOMER_NTON
#define PRODUCER_CUSTOMER_NTON


#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
static const int buffer_size_NtoN = 11;
static const int pruduce_plan_NtoN = 150;
static int buffer_NtoN[buffer_size_NtoN];
static int read_position_NtoN;
static int write_position_NtoN;
static int produced_counter;
static int consumed_counter;
static std::mutex buffermutex_NtoN;
static std::mutex iomutex_NtoN;
static std::mutex produced_counter_mutex_NtoN;
static std::mutex consumed_counter_mutex_NtoN;
static std::condition_variable repo_not_full_NtoN;
static std::condition_variable repo_not_empty_NtoN;

class Producer_Customer_NtoN {
public:
	Producer_Customer_NtoN();
	void producer_item(int i);
	int customer_item();
	void producer_task();
	void customer_task();
};




#endif // !PRODUCER_CUSTOMER_NTON

