#include "my_stack.h"



template<typename T>
my_stack<T>::my_stack(const int size, const int increase) {
	max = size;
	this->increase = size;
	this->top = -1;
	this->stack = new T[max];
}

template<typename T>
my_stack<T>::~my_stack() {
	delete[] stack;
}

template<typename T>
int my_stack<T>::size() const {
	return size;

}

template<typename T>
bool my_stack<T>::is_empty() const {
	return top==-1;
}

template<typename T>
bool my_stack<T>::is_full() const {
	return top == max;
}

template<typename T>
T & my_stack<T>::get_top() const {
	if (is_empty) {
		throw "ø’’ª£°";
	}

	return stack[top];
}

template<typename T>
T & my_stack<T>::get_button() const {
	if (is_empty) {
		throw "ø’’ª£°";
	}
	return stack[0];
}

template<typename T>
my_stack<T>& my_stack<T>::push(const T & node) {
	if (is_full) {
		auto_increase();
	}
	stack[++top] = node;
	return *this;
}

template<typename T>
my_stack<T>& my_stack<T>::pop() {
	if (!is_empty) {
		top--;
	}
	return *this;
}

template<typename T>
my_stack<T>& my_stack<T>::pop(T & node) {
	if (!is_empty) {
		node = stack[top];
	}
	return *this;
}

template<typename T>
my_stack<T>& my_stack<T>::clear() {
	top = -1;
	return *this;
}


template<typename T>
void my_stack<T>::auto_increase() {
	T *temp = new T[max + increase];
	memcpy(temp, stack, max*(sizeof(T)));
	delete[] stack;
	max += increase;
	stack = temp;
}
