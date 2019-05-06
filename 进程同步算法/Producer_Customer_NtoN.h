#ifndef PRODUCER_CUSTOMER_NTON
#define PRODUCER_CUSTOMER_NTON
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>


class Producer_Customer_NtoN {
public:


private:
	static const int buffer_size = 10;
	static const int pruduce_plan = 10;
	int bufffer[buffer_size];
	int read_position;
	int wirte_position;
	int produced_counter;
	int consumed_counter;
	std::mutex mutex;
	std::mutex produced_counter_mutex;
	std::mutex consumed_counter_mutex;
	std::condition_variable repo_not_full;
	std::condition_variable repo_not_empty;
};


#endif // !PRODUCER_CUSTOMER_NTON

