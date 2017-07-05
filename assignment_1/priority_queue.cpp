#include "priority_queue.h"

using namespace std;

Priority_queue::Priority_queue(T* first, T* last) {
	v.push_back(0); // 首位储存其大小，初始设为0
	for ( T* p = first; p < last; p++) {
		push(*p);
	}
}


void Priority_queue::push(const T& val) {
	v.push_back(val);
	int i = ++v.front();
	for (int j = i >> 1; j>0 && i!=1 && v[i]>v[j]; i = j, j = i >> 1) {
		swap(v[i], v[j]);
	}
}


void Priority_queue::pop() {

	size_t size_ = --v.front(); // 避免下面频繁调用front函数
	// if ( size_ < 0 ) {
	// 	v.front()++;
	// 	cerr << "ERROR: Nothing in the Priority queue!";
	// 	return;
	// }

	*( v.begin() + 1 ) = v.back();
	v.pop_back();
	int i = 1;
	if ( size_ >= 3 ) {
		int j = v[2] > v[3] ? 2 : 3;
		while ( j<=size_ && i<size_ && v[j]>v[i]) {
			swap(v[i], v[j]);
			i = j;
			j = v[i<<1] > v[(i<<1)+1] ? i<<1 : (i<<1)+1;
		}
	}
	else if (size_ == 2)
		if ( v[1] < v[2] )
			swap(v[1], v[2]);
}


ostream& operator << (ostream& out, const Priority_queue& q) {
	cout << q.v;
	return out;
}
