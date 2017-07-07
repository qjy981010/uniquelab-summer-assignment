#ifndef PRIORITY_QUEUE_H_
#define PRIORITY_QUEUE_H_

#include <algorithm>

#include "my_vector.h" // 自己实现的简单的vector

using T = double;

class Priority_queue
{
	public:
		Priority_queue();
		Priority_queue(T* first, T* last);
		bool empty() const; // 判断是否为空
		unsigned size() const; // 返回其大小
		const T& top() const; // 返回根节点值（最大值）
		void push(const T& val); // 插入元素
		void pop(); // 删除最大元素
	private:
		My_vector v; // vector实现大顶堆；
};

#endif
