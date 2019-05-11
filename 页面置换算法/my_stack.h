#ifndef MY_STACK_H
#define MY_STACK_H
#include <cstring>
template <typename T>
class my_stack {
public:
	my_stack(const int size, const int increase);
	~my_stack();
	int size() const;
	bool is_empty() const;
	bool is_full() const;
	T &get_top() const;
	T &get_button() const;
	my_stack<T> &push(const T &node);
	my_stack<T> &pop();
	my_stack<T> &pop(T &node);
	my_stack<T> &clear();

private:
	T *stack;
	int top;
	int max;
	int increase;
	void auto_increase();
};

#endif // !MY_STACK_H







