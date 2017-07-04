#include "llrb.h"

using namespace std;

void Rb_tree::deltree(base_ptr h) {
	if (!h) return;
	deltree(h->left);
	deltree(h->right);
	delete h;
}

Rb_tree::~Rb_tree() {
 	deltree(root);
}

Rb_tree::base_ptr Rb_tree::rotateLeft(base_ptr h) {
	base_ptr x = h->right;
	h->right = x->left;
	x->left = h;
	x->color = h->color;
	h->color = RED;
	return x;
}

Rb_tree::base_ptr Rb_tree::rotateRight(base_ptr h) {
	base_ptr x = h->left;
	h->left = x->right;
	x->right = h;
	x->color = h->color;
	h->color = RED;
	return x;
}

void Rb_tree::flipColors(base_ptr h) {
	h->color = !h->color;
	h->right->color = !h->right->color;
	h->left->color = !h->left->color;
}

void Rb_tree::insert(const T& element) {
	root = put(root, element);
	root->color = BLANK;
}

Rb_tree::base_ptr Rb_tree::put(base_ptr h, T val) {
	if ( h == 0 ) {
		N++;
		base_ptr node_t = new __rb_tree_node_base;
		node_t->val = val;
		return node_t;
	}
	if (val > h->val) h->right = put(h->right, val);
	else if (val < h->val) h->left = put(h->left, val);
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
	if (!root) return;
	deltree(root->left);
	deltree(root->right);
	root = 0;
}

Rb_tree::base_ptr Rb_tree::fixUp(base_ptr h) {
	if (isRed(h->right)) h = rotateLeft(h);
	if (isRed(h->left) && isRed(h->left->left)) h = rotateRight(h);
	if (isRed(h->left) && isRed(h->right)) flipColors(h);
	return h;
}

Rb_tree::base_ptr Rb_tree::moveRedLeft(base_ptr h) {
	flipColors(h);
	if (isRed(h->right->left)) {
		h->right = rotateRight(h->right);
		h = rotateLeft(h);
		flipColors(h);
	}
	return h;
}

Rb_tree::base_ptr Rb_tree::moveRedRight(base_ptr h) {
	flipColors(h);
	if (isRed(h->left->left)) {
		h = rotateRight(h);
		flipColors(h);
	}
	return h;
}

Rb_tree::base_ptr Rb_tree::delMin(base_ptr h) {
	if (!h->left) {
		delete h;
		return nullptr;
	}
	if (!isRed(h->left) && !isRed(h->left->left)) {
		h = moveRedLeft(h);
	}
	h->left = delMin(h->left);
	return fixUp(h);
}

void Rb_tree::eraseMin() {
	if ( !isRed(root->right) && !isRed(root->left) )
		root->color = RED;
	root = delMin(root);
	if (root) root->color = BLANK;
	N--;
}

Rb_tree::base_ptr Rb_tree::erase(base_ptr h, const T& element) {
	if (element < h->val) {
		if (!isRed(h->left) && !isRed(h->left->left))
			h = moveRedLeft(h);
		h->left = erase(h->left, element);
	}
	else {
		if (isRed(h->left)) h = rotateRight(h);
		if (element > h->val) {
			if (!isRed(h->right) && !isRed(h->right->left))
				h = moveRedRight(h);
			h->right = erase(h->right, element);
		}
		else {
			if (h->right==nullptr) {
				delete h;
				return nullptr;
			}
			else {
				popRightMin(h);
			}
		}
	}
	return fixUp(h);
}

void Rb_tree::erase(const T& element) {
	if (!isRed(root->right) && !isRed(root->left))
		root->color = RED;
	root = erase(root, element);
	if (root) root->color = BLANK;
	N--;
}

int Rb_tree::count(const T& element) const{
	base_ptr h = root;
	while (h) {
		if (element < h->val) h = h->left;
		else if (element > h->val) h = h->right;
		else return 1;
	}
	return 0;
}

void Rb_tree::popRightMin(base_ptr h) {
	base_ptr its_right = h->right;
	color_type its_color = h->color;
	if ( !isRed(its_right->right) && !isRed(its_right->left) )
		its_right->color = RED;
	h->right = delMin(its_right, h);
	if (h->right) h->right->color = its_color;
}

Rb_tree::base_ptr Rb_tree::delMin(base_ptr h, base_ptr head) {
	if (!h->left) {
		head->val = h->val;
		delete h;
		return nullptr;
	}
	if (!isRed(h->left) && !isRed(h->left->left))
		h = moveRedLeft(h);
	h->left = delMin(h->left, head);
	return fixUp(h);
}

/*
void Rb_tree::popLeftMax(base_ptr h) {
	base_ptr its_left = h->left;
	color_type its_color = h->color;
	if ( !isRed(its_left->right) && !isRed(its_left->left) )
		its_color = RED;
	its_left = delMax(its_left, h);
	if (its_left) its_left->color = its_color;
}

Rb_tree::base_ptr Rb_tree::delMax(base_ptr h, base_ptr head) {
	if (isRed(h->left)) h = rotateRight(h);
	if (!h->right) {
		head->val = h->val;
		delete h;
		return nullptr;
	}
	if (!isRed(h->right) && !isRed(h->right->left))
		h = moveRedRight(h);
	h->right = delMax(h->right, head);
	return fixUp(h);
}
*/
