#include "my_vector.h"
using namespace std;

void My_vector::insert_aux(const T& x) {
	size_type size_ = size();
	cout << '\n' << size_ << '\n';
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
