#ifndef _PRIORITY_QUEUE_H
#define _PRIORITY_QUEUE_H

#include <algorithm>
#include <iostream>
#include <vector>
#include "my_vector.h"

using T = double;

class Priority_queue {
public:
	Priority_queue() { v.push_back(0); }
	// Priority_queue(int max);
	// Priority_queue(Key[] a);
	bool empty() const { return *(v.begin()) == 0; }
	std::size_t size() const { return *(v.begin()); }
	const T& top() const { return *( v.begin() + 1 ); }
	void push(const T& val);
	void pop();
	void display() const { v.display(); }
private:
	My_vector v;
};

#endif
