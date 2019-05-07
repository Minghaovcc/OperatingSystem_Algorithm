#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H
#include <mutex>
#include <chrono>


using namespace std;

int const philosopherNum = 5;
const int Thinking = 0;
const int Waiting = 1;
const int Eating = 2;
std::mutex chopsticks[philosopherNum];



class philosopher {
public:
	philosopher(int num);
	philosopher();
	void set_num(int num);
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






