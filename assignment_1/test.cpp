#include "set.h"
#include "priority_queue.h"

using namespace std;

int main() {
	// TESTING CODE WILL BE PUT HERE
	Priority_queue q;
	for (int i = 0; i < 10; i++) {
		q.push(i);
	}
	q.display();
	return 0;
}
