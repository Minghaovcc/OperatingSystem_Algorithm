
/**************************************************
@brief   : 银行家算法的头文件
@author  : 渠继涵
@time    : 2019/05/06 19:15
**************************************************/
#ifndef BANKALGORITHM_H
#define BANKALGORITHM_H

int const processNum = 5;
int const resourceNum = 3;

class bankAlgorithm {
public:
	bankAlgorithm();//构造函数
	void sendRequest();	//资源申请函数
	bool safetyCheck();	//安全检查函数
	void disp();
private:

	int available[resourceNum] = {3,3,2};	//可利用资源向量
	int max[processNum][resourceNum] = { {7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3} };	//最大需求矩阵
	int allocation[processNum][resourceNum] = { {0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2} };	//分配矩阵
	int need[processNum][resourceNum] = { {7,4,3},{1,2,2},{6,0,0},{0,1,1},{4,3,1} };	//需求矩阵
	int request[resourceNum+1] = {0};	//请求向量
	int work[resourceNum] = { 0 };	//工作向量
	bool finish[processNum] = {false};	//是否完成布尔向量
	int show[resourceNum * 4] = { 0 };	//	将结果保存下来

};
#endif // !BANKALGORITHM_H







