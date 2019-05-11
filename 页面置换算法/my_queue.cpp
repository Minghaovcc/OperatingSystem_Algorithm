#include "my_queue.h"


template<typename T>
my_queue<T>::my_queue() {
}

template<typename T>
my_queue<T>::~my_queue() {
}

template<typename T>
bool my_queue<T>::is_empty() const {
	return head->next_node==nullptr;
}

template<typename T>
T & my_queue<T>::get_head() const {
	if (is_empty) {
		throw "空队列！";
	} else {
		return head->next_node->date;
	}
}

template<typename T>
T & my_queue<T>::get_tail() const {
	if (is_empty) {
		throw "空队列！";
	} else {
		return tail->date;
	}
}

template<typename T>
my_queue<T>& my_queue<T>::enqueue(const T & node) {
	tail->next_node = new queue_node<T>;
	tail = tail->next_node;
	tail->next_node = nullptr;
	tail->date = node;
	return *this;


}


template<typename T>
my_queue<T>& my_queue<T>::dequeue() {
	if (is_empty) {
		return *this;
	}
	queue_node<T> *temp = head->next_node;
	head->next_node = temp->next_node;
	delete temp;
	return *this;
}

template<typename T>
my_queue<T>& my_queue<T>::dequeue(T & node) {
	if (is_empty) {
		return *this;
	}
	queue_node<T> *temp = head->next_node;
	head->next_node = temp->next_node;
	node = temp->date;
	delete temp;
	return *this;
}
}
