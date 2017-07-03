#include "llrb.h"

using namespace std;

void Rb_tree::init() {
	header = new __rb_tree_node_base;
	header->parent = 0;
	// header->left = header;
	// header->right = header;
}

void Rb_tree::deltree(base_ptr root) {
	if (root) {
		deltree(root->left);
		deltree(root->right);
		delete root;
	}
}

Rb_tree::~Rb_tree() {
 	deltree(root());
 	delete header;
}

base_ptr Rb_tree::rotateLeft(base_ptr h) {
	base_ptr x = h->right;
	h->right = x->left;
	if (x->left) x->left->parent = h;
	x->left = h;
	x->parent = h->parent;
	h->parent = x;
	// if (x.parent.left == h) x.parent.left = x;
	// else x.parent.right = x;
	return x;
}

base_ptr Rb_tree::rotateRight(base_ptr h) {
	base_ptr x = h->left;
	h->left = x->right;
	if (x->right) x->right->parent = h;
	x->right = h;
	x->parent = h->parent;
	h->parent = x;
	return x;
}

void Rb_tree::flipColors(base_ptr h) {
	h->color = RED;
	h->right->color = h->left->color = BLANK;
}

void Rb_tree::insert(const T& element) {
	header->parent = put(header, root(), element);
	root()->color = BLANK;
}

base_ptr Rb_tree::put(base_ptr parent_h, base_ptr h, T val) {
	if ( h == 0 ) {
		N++;
		base_ptr node_t = new __rb_tree_node_base;
		node_t->val = val;
		node_t->parent = parent_h;
		return node_t;
	}
	if (val > h->val) h->right = put(h, h->right, val);
	else if (val < h->val) h->left = put(h, h->left, val);
	else return h;
	if ( !isRed(h->left) && isRed(h->right) )
		h = rotateLeft(h);
	if ( isRed(h->left) && isRed(h->left->left) )
		h = rotateRight(h);
	if ( isRed(h->left) && isRed(h->right) )
		flipColors(h);
	return h;
}

void Rb_tree::clear() {
	deltree(root());
	init();
}
