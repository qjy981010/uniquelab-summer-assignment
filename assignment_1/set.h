#include <algorithm>
#include "llrb.h"

using T = double;

class Set {
public:
	void insert(const T& element) { tree.insert(element); }
	void erase(const T& element) { tree.erase(element); }
	void clear() { tree.clear(); }
	int count(const T& element) const { return tree.count(element); };
	bool empty() { return tree.empty(); }
	size_t size() { return tree.size(); }
private:
	Rb_tree tree;
};

// TODO
