#include "PCB.h"
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

void init();

int main() {
	init();
	cout << "=====动态高优先级优先调度算法=====" << endl;
	PCB::PSArun();
	return 0;
}


void init() {

	PCB *pcb[3];
	for (int i = 0; i < 3; i++) {
		pcb[i] = new PCB(i+4, i+5);
	}
	
}