#include "my_vector.h"

My_vector::My_vector() {
	start = new T[16]; // 初始空间设为16
	My_vector::finish = start;
	end_of_storage = start + 16;
}

void My_vector::insert_aux(const T& x) { // 分配新空间，转移并delete原空间
	size_type size_ = size();
	My_vector::iterator newstart = new T[size_<<1];
	for (int i = 0 ; i != size_; i++) {
		*(newstart + i) = *(start + i);
	}
	delete []start;
	finish = newstart + size_;
	*(finish++) = x;
	start  = newstart;
	end_of_storage = start + ( size_ << 1 );
}

void My_vector::push_back(const T& x) {
	if (finish != end_of_storage) { // vector 未满
		*finish = x;
		finish++;
	}
	else // vector容量已满，重建数组；
		insert_aux(x);
}

 // 删除某节点并将后面节点前移
My_vector::iterator My_vector::erase(iterator position) {
	for (; position + 1 != finish; position++)
		*position = *( position + 1 );
	finish--;
	return position;
}
