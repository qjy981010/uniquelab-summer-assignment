#ifndef _MY_VECTOR_H
#define _MY_VECTOR_H

#include <iostream>

using T = double;

class My_vector {
public:
	typedef T value_type;
	typedef value_type* iterator;
	typedef value_type& reference;
	typedef std::size_t size_type;
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
	void push_back(const T& x)
	void pop_back() { finish--; }
	iterator erase(iterator position);
	friend std::ostream& operator << (std::ostream& out, const My_vector& v);  // for test
};

#endif
