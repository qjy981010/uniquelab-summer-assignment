#ifndef _LLRB_H
#define _LLRB_H

using T = double;

const bool RED = true;
const bool BLANK = false;

struct __rb_tree_node_base {
	typedef bool color_type;
	typedef __rb_tree_node_base* base_ptr;
	color_type color = RED;
	base_ptr parent;
	base_ptr left = 0;
	base_ptr right = 0;
	T val;
};

typedef __rb_tree_node_base* base_ptr;

class Rb_tree {
public:
	typedef bool color_type;
	typedef unsigned size_type;
	typedef T* pointer;
	typedef T& reference;
private:
	base_ptr header;
	size_type N = 0;
	base_ptr rotateLeft(base_ptr h);
	base_ptr rotateRight(base_ptr h);
	void flipColors(base_ptr h);
	color_type isRed(base_ptr h) {
		if ( h ) return h->color == RED;
		else return 0;
	};
	base_ptr root() const { return header->parent; }
	// base_ptr leftmost() const { return header->left; }
	// base_ptr rightmost() const { return header->right; }
	void init();
	void deltree(base_ptr root);
	base_ptr put(base_ptr parent_h, base_ptr h, T val);
public:
	Rb_tree() { init(); }
	~Rb_tree();
	size_type size() const { return N; }
	bool empty() const { return N == 0; }
	void insert(const T& element);
	void erase(const T& element);
	void clear();
	int count(const T& element) const;
};

#endif
