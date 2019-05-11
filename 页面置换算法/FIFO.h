#ifndef FIFO_H
#define FIFO_H
#include "page_manager.h"
#include "my_queue.h"




class FIFO:public page_manager{
public:
	FIFO();
	~FIFO();
	missing require_frame(const int page_id, int &frame_id, const bool alter = false);

private:
	my_queue<page> pages;
};


#endif // !FIFO_H
