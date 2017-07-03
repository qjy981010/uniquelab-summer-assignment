#include "my_vector.h"

using namespace std;

My_vector::My_vector() {
	start = new T[16];
	finish = start;
	end_of_storage = start + 16;
}

void My_vector::insert_aux(const T& x) {
	size_type size_ = size();
	iterator newstart = new T[size_<<1];
	for (int i = 0 ; i < size_; i++) {
		*(newstart + i) = *(start + i);
	}
	delete []start;
	finish = newstart + size_;
	*(finish++) = x;
	start  = newstart;
	end_of_storage = start + ( size_ << 1 );
}


std::ostream& operator<<(std::ostream& out, const My_vector& v) {
	for (T* i = v.start; i < v.finish; i++)
		out << *i << ' ';
	out << '\n';
	return out;
}


void push_back(const T& x) {
	if (finish != end_of_storage) {
		*finish = x;
		finish++;
	}
	else
		insert_aux(x);
}


iterator erase(iterator position) {
	for (; position + 1 != finish; position++)
		*position = *( position + 1 );
	finish--;
	return position;
}

/*
int main() {
	My_vector v;
	for ( int i = 0; i < 400; i++) {
		v.push_back(i);
	}
	v.display();
	v.erase(v.begin());
	v.display();
	cout << v.size() << v.empty() << v[6];
}
*/
