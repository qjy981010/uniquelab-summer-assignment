#ifndef _PRIORITY_QUEUE_H
#define _PRIORITY_QUEUE_H

#include <algorithm>
#include "my_vector.h" // 自己实现的简单的vector

using T = double;

class Priority_queue {
public:
	Priority_queue() { v.push_back(0); } // 首位储存其大小，初始设为0；实际数据从第二个开始
	Priority_queue(T* first, T* last);
	bool empty() const { return *( v.begin() ) == 0; }
	unsigned size() const { return *( v.begin() ); }
	const T& top() const { return *( v.begin() + 1 ); }
	void push(const T& val);
	void pop();
private:
	My_vector v; // vector实现大顶堆；
};

#endif
