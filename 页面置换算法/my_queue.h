#ifndef MY_QUEUE_H
#define MY_QUEUE_H

template <typename T> 
struct queue_node {
	T date;
	queue_node<T> *next_node;
};

template<typename T> 
class my_queue {
public:
	my_queue();
	~my_queue();
	//判断是否是空的
	bool is_empty() const;
	//获得队列头节点
	T &get_head() const;
	//获得队列尾节点
	T &get_tail() const;
	//入队
	my_queue<T> &enqueue(const T &node);
	//出队
	my_queue<T> &dequeue();
	my_queue<T> &dequeue(T &node);

private:
	queue_node<T> *head;
	queue_node<T> *tail;

};




#endif // !MY_QUEUE_H







