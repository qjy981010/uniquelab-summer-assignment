#include "priority_queue.h"

#include <iostream>
#include <algorithm>

using std::cerr;

Priority_queue::Priority_queue() {
	v.push_back(0);
} // 首位储存其大小，初始设为0；实际数据从第二个开始

Priority_queue::Priority_queue(T* first, T* last) {
	v.push_back(0); // 首位储存其大小，初始设为0；实际数据从第二个开始
	for ( T* p = first; p != last; p++) {
		push(*p);
	}
}

bool Priority_queue::empty() const {
	return v.front() == 0;
}

unsigned Priority_queue::size() const {
	return v.front();
}

const T& Priority_queue::top() const {
	return v[1];
}

void Priority_queue::push(const T& val) { // 向堆中插入；
	v.push_back(val);
	int i = ++v.front();
	for (int j = i >> 1; j>0 && i!=1 && v[i]>v[j]; i = j, j = i >> 1) {
		std::swap(v[i], v[j]);
	}
}

void Priority_queue::pop() {
	if (empty()) {
		cerr << "ERROR: The Priority_queue is empty.\n";
		return;
	}
	unsigned size_ = --v.front();
	*( v.begin() + 1 ) = v.back(); // 把最后的元素赋值给堆顶
	v.pop_back(); // 删除最后的元素，相当于把最后的元素移至堆顶
	int i = 1;
	if ( size_ >= 3 ) {
		int j = v[2] > v[3] ? 2 : 3;
		while ( j<=size_ && i<size_ && v[j]>v[i]) { // 将其与两个子节点较大的交换
			std::swap(v[i], v[j]);
			i = j;
			j = v[i<<1] > v[(i<<1)+1] ? i<<1 : (i<<1)+1;
		}
	}
	else if (size_ == 2)
		if ( v[1] < v[2] )
			std::swap(v[1], v[2]);
}
