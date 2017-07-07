#include "set.h"

void Set::insert(const T& element) {
	tree.insert(element);
}

void Set::erase(const T& element) {
	tree.erase(element);
}

void Set::clear() {
	tree.clear();
}

int Set::count(const T& element) const {
	return tree.count(element);
}

bool Set::empty() {
	return tree.empty();
}

unsigned Set::size() {
	return tree.size();
}
