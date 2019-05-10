
/**************************************************
@brief   : 生产者消费者问题（一个生产者对一个消费者）
@author  : 渠继涵
@time    : 2019/05/05 11:23
**************************************************/



#ifndef PRODUCER_CUSTOMER_1TO1
#define PRODUCER_CUSTOMER_1TO1
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

static const int buffer_size = 10;
static const int pruduce_plan = 521;
static std::mutex buffermutex;
static std::mutex iomutex;
static std::condition_variable rope_not_full;
static std::condition_variable rope_not_empty;
static int buffer[buffer_size] = { 0 };
static int read_position;
static int write_position;

class Producer_Customer_1to1 {
public:
	Producer_Customer_1to1();
	void producer_item(int i);
	int customer_item();
	void producer_task();
	void customer_task();

private:
	//int buffer[buffer_size];	//产品缓冲区，配合read_position与write_position模拟环形队列
	

};
#endif // !PRODUCER_CUSTOMER_1TO1