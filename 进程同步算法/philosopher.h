#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H
#include <mutex>
#include <vector>

using namespace std;

int const philosopherNum = 5;
const int Thinking = 0;
const int Waiting = 1;
const int Eating = 2;

static std::mutex chopsticks[philosopherNum];
static std::mutex io_mutex;

class philosopher {
public:
	philosopher(int num);
	philosopher();
	//开始吃饭
	void start_eat();
	//吃完饭放下筷子开始思考
	void start_think();
	void start();


private:
	int num;
	int statue;
};

#endif // !PHILOSOPHER_H






