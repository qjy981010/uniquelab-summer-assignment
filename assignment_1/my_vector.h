#ifndef MY_VECTOR_H_
#define MY_VECTOR_H_

using T = double;

class My_vector
{
public:
	My_vector();
	~My_vector();
	T* begin() const; // 指向首节点的指针
	T* end() const; // 指向尾节点的指针
	T& front() const; // 首节点值
	T& back() const; // 尾节点值
	unsigned size() const; // 返回大小
	bool empty() const; // 判断是否为空
	void push_back(const T& x); // 在尾部添加元素
	void pop_back(); // 删除尾部元素
	T* erase(T* position); // 删除任意元素
	T& operator[](unsigned n) const {
		return *(begin() + n);
	}
protected:
	T* start;
	T* finish;
	T* end_of_storage;
	void insert_aux(const T& x);
};

#endif
