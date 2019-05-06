#ifndef RW_PROBLEM_H
#define RW_PROBLEM_H



#include <iostream>



using namespace std;

class RW_problem {

public:
	RW_problem();
	~RW_problem();




private:
	typedef struct {
		int id;
		int delay;	//进程持续多长时间后开始
		int last;	//进程持续多长时间
	} Role;
};

#endif // !RW_PROBLEM_H





