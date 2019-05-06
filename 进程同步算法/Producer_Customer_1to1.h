#ifndef PRODUCER_CUSTOMER_1TO1
#define PRODUCER_CUSTOMER_1TO1
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;


class Producer_Customer_1to1 {

public:

private:
	static const int buffer_size = 10;
	static const int pruduce_plan = 521;
	int buffer[buffer_size];	//产品缓冲区，配合read_position与write_position模拟环形队列
	int read_position;
	int write_position;
	mutex mutex;
	std::condition_variable rope_not_full;
	std::condition_variable rope_not_empty;

};
#endif // !PRODUCER_CUSTOMER_1TO1