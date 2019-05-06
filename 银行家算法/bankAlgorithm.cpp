
/**************************************************
@brief   : 银行家算法的实现
@author  : 渠继涵
@time    : 2019/05/06 19:15
**************************************************/

#include "bankAlgorithm.h"
#include <iostream>
using namespace std;


//构造函数
bankAlgorithm::bankAlgorithm() {
	int available[resourceNum] = { 3,3,2 };
	int max[processNum][resourceNum] = { {7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3} };
	int allocation[processNum][resourceNum] = { {0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2} };
	int need[processNum][resourceNum] = { {7,4,3},{1,2,2},{6,0,0},{0,1,1},{4,3,1} };
}

//资源申请函数
void bankAlgorithm::sendRequest() {
	cout << "输入需求(*第一个输入进程号，之后为需求值*)：   " ;
	cin >> request[0] >> request[1] >> request[2] >> request[3];
	//检查need数组
	if (need[request[0]][0] >= request[1] && need[request[0]][1] >= request[2] && need[request[0]][2] >= request[3]) {
		//检查availible数组
		if (request[0] <= available[0] && request[1] <= available[1] && request[2] <= available[2]) {
			cout << "安全性检查中..." << endl;
			int oldAvailable[resourceNum];
			int oldAllocation[processNum][resourceNum];
			int oldNeed[processNum][resourceNum];
			for (int i = 0; i < resourceNum; i++) {
				//将旧allocation存起来,并且分配资源
				oldAllocation[request[0]][i] = allocation[request[0]][i];
				allocation[request[0]][i] = allocation[request[0]][i] + request[i + 1];
				//将旧need存起来,并且分配资源
				oldNeed[request[0]][i] = need[request[0]][i];
				need[request[0]][i] = need[request[0]][i] - request[i + 1];
				//将旧available存起来,并且分配资源
				oldAvailable[i] = available[i];
				available[i] = available[i] - request[i + 1];
				}
			if(!safetyCheck()){
				cout << "系统处于不安全状态！" << endl;
				//复原
				for (int i = 0; i < resourceNum; i++) {
					allocation[request[0]][i] = oldAllocation[request[0]][i];
					need[request[0]][i] = oldNeed[request[0]][i];
					available[i] = oldAvailable[i];
				}
			} else {
				disp();
			}
		} else {
			cout << "系统中无足够的资源满足进程申请" << endl;
		}
	} else {
		cout << "进程所需要的资源数目超过它所宣布的最大值" << endl;
	}



}
//安全检查函数
bool bankAlgorithm::safetyCheck() {
	bool key;	//步骤跳转临时变量
	bool isFinial = false;	//是否完成变量
	int process = processNum-1;	//进程循环检查变量
	int finishedProcess = 0;
	//初始化完成数组
	for (int i = 0; i < processNum; i++) {finish[i] = false;}
	//初始化工作数组
	for (int i = 0; i < resourceNum; i++) { work[i] = available[i]; }

	while (process >= 0) {

		//第一步，找到一个未完成且need<work的进程
		if (!finish[process]) {
			for (int i = 0; i < resourceNum; i++) {
				if (work[i] < need[process][i]) {
					key = true;
				}
			}
		}


		//第二步，进程状态设置为true，且将进程的资源还给work
		if (key) {
			for (int i = 0; i < resourceNum; i++) {
				work[i] = work[i] + allocation[process][i];
				finish[i] = true;
			}
			process = processNum;
		}
		process--;
	}

	//第三步
	for (int i = 0; i < processNum; i++) {
		if (finish[i]) {
			finishedProcess++;
		}
	}
	if (finishedProcess = processNum) {
		isFinial = true;
	}

	
	return isFinial;
}
//显示函数
void bankAlgorithm::disp() {
	
}


int main() {
	cout << "hello";
}