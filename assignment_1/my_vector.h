#ifndef _MY_VECTOR_H
#define _MY_VECTOR_H

using T = double;

class My_vector {
public:
	typedef T value_type;
	typedef value_type* iterator;
	typedef value_type& reference;
	typedef unsigned size_type;
protected:
	iterator start;
	iterator finish;
	iterator end_of_storage;
	void insert_aux(const T& x);
public:
	iterator begin() const { return start; }
	iterator end() const { return finish; }
	size_type size() const { return size_type(end()-begin()); }
	bool empty() const {return begin() == end(); }
	reference operator[](size_type n) { return *(begin() + n); }
	My_vector();
	~My_vector() { delete []start; }
	reference front() { return *begin(); }
	reference back() { return *(end()-1); }
	void push_back(const T& x);
	void pop_back() { finish--; } // 直接将finish后移一位即可
	iterator erase(iterator position);
};

#endif
