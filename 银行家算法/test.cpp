#include "bankAlgorithm.h"
#include <iostream>

using namespace std;

//³õÊ¼»¯º¯Êý

int main() {
	bankAlgorithm demo = bankAlgorithm();
	demo.disp();

	while (true) {
		demo.sendRequest();
		demo.disp();
	}
	

	return 0;
}
