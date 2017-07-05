#ifndef _LLRB_H
#define _LLRB_H

using T = double;

const bool RED = true;
const bool BLANK = false;

struct __rb_tree_node_base {
	typedef bool color_type;
	typedef __rb_tree_node_base* base_ptr;
	color_type color = RED;
	base_ptr left = 0;
	base_ptr right = 0;
	T val;
};

class Rb_tree {
public:
	typedef bool color_type;
	typedef unsigned size_type;
	typedef __rb_tree_node_base* base_ptr;
private:
	base_ptr root = 0;
	size_type N = 0;
	base_ptr rotateLeft(base_ptr h);
	base_ptr rotateRight(base_ptr h);
	base_ptr moveRedLeft(base_ptr h);
	base_ptr moveRedRight(base_ptr h);
	void flipColors(base_ptr h);
	color_type isRed(base_ptr h) {
		if ( h ) return h->color == RED;
		else return BLANK;
	};
	void deltree(base_ptr h);
	base_ptr fixUp(base_ptr h);
	base_ptr delMin(base_ptr h);
	base_ptr delMin(base_ptr h, base_ptr head);
	base_ptr put(base_ptr h, T val);
	base_ptr erase(base_ptr h, const T& element);
	void popRightMin(base_ptr h);
public:
	~Rb_tree();
	size_type size() const { return N; }
	bool empty() const { return N == 0; }
	void insert(const T& element);
	void eraseMin();
	void erase(const T& element);
	void clear();
	int count(const T& element) const;
};

#endif
