#include "page_manager.h"



page_manager::page_manager() {
	int i = 1;
	for (auto &frame:frames) {
		frame.id = i++;
	}
}


page_manager::~page_manager() {
}
