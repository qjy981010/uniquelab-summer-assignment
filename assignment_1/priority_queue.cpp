#include "priority_queue.h"

using namespace std;

void Priority_queue::push(const T& val) {
	v.push_back(val);
	size_t size_ = ++v.front();
	int i = size_;
	for (int j = size_ >> 1; j>0 && i!=1 && v[i]>v[j]; i = j, j = i >> 1) {
		swap(v[i], v[j]);
	}
}

void Priority_queue::pop() {
	size_t size_ = --v.front();
	if ( size_ < 0 ) {
		v.front()++;
		cerr << "ERROR: Nothing in the Priority queue!";
	}
	*( v.begin() + 1 ) = v.back();
	v.pop_back();
	int i = 1;
	if ( size_ > 3 )
		for (int j = v[2] > v[3] ? 2 : 3; j<=size_ && i<size_ && v[j]<v[i]; i = j, j = v[i>>1] > v[(i>>1)+1] ? i>>1 : (i>>1)+1) {
			swap(v[i], v[j]);
		}
	else if (size_ == 2)
		if ( v[1] < v[2] )
			swap(v[1], v[2]);
}
