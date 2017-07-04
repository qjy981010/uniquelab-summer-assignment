#include "set.h"
#include "llrb.h"
#include "priority_queue.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {

	// TESTING CODE WILL BE PUT HERE
	srand((unsigned)time(NULL));
	Rb_tree my_tree;
	for (int i = 0; i < 100; i++) {
		my_tree.insert(rand()%10);
		cout << my_tree.size() << ' ';
	}
	cout << '\n';
	for (int i = 9; i >= 0; i--) {
		// my_tree.simpledisplay();
		cout << my_tree.size() << ' ';
		cout << my_tree.count(7) << ' ';
		my_tree.erase(i);
	}
	cout << my_tree.empty();
	cout << '\n';



/*	My_vector v;
	// T v[1000000];
	for (int i = 0; i < 1000000; i++) {
		v.push_back(rand()%1000); // *(v+i) = rand()%1000;
	}
	Priority_queue q(v.begin(), v.end()); //(v, v+1000000);
	cout << q;
	// vec;
	for (int i = 0; i < 1000000; i++) {
		// vec.push_back(q.top());
		cout << q.top() << ' ';
		q.pop();
	}
	// cout << vec;
	return 0;
*/
}
