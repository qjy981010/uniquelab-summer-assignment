#include "llrb.h"

Rb_tree::color_type Rb_tree::isRed(Base_ptr h) {
	if ( h ) return color_type(h->color == RED);
	else return BLACK; // 叶节点为黑
};

void Rb_tree::deltree(Base_ptr h) { // 递归删除树h
	if (!h) return;
	deltree(h->left);
	deltree(h->right);
	delete h;
}

Rb_tree::~Rb_tree() {
 	deltree(root);
}

unsigned Rb_tree::size() const {
	return N;
}

bool Rb_tree::empty() const {
	return N == 0;
}

Rb_tree::Base_ptr Rb_tree::rotateLeft(Base_ptr h) {
	Base_ptr x = h->right;
	h->right = x->left;
	x->left = h;
	x->color = h->color;
	h->color = RED; // 旋转时x的颜色一定是红的，下同
	return x;
}

Rb_tree::Base_ptr Rb_tree::rotateRight(Base_ptr h) {
	Base_ptr x = h->left;
	h->left = x->right;
	x->right = h;
	x->color = h->color;
	h->color = RED;
	return x;
}

void Rb_tree::flipColors(Base_ptr h) { // 颠倒颜色
	if (h->right) h->right->color = (color_type) !h->right->color;
	if (h->left) h->left->color = (color_type) !h->left->color;
	h->color = (color_type) !h->color;
}

void Rb_tree::insert(const T& element) {
	root = put(root, element);
	root->color = BLACK;
}

Rb_tree::Base_ptr Rb_tree::put(Base_ptr h, T val) {
	if ( h == nullptr ) {
		N++;
		Base_ptr node_temp = new Node_base;
		node_temp->val = val;
		return node_temp;
	}
	if (val > h->val) h->right = put(h->right, val);
	else if (val < h->val) h->left = put(h->left, val);
	else return h; // 因为是为了实现集合，相等时不插入
	if ( !isRed(h->left) && isRed(h->right) ) // 返回时修复
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
	root = nullptr;
	N = 0;
}

Rb_tree::Base_ptr Rb_tree::fixUp(Base_ptr h) {
	if (isRed(h->right)) h = rotateLeft(h);
	if (isRed(h->left) && isRed(h->left->left)) h = rotateRight(h);
	if (isRed(h->left) && isRed(h->right)) flipColors(h);
	return h;
}

Rb_tree::Base_ptr Rb_tree::moveRedLeft(Base_ptr h) {
	flipColors(h);
	if (h->right && isRed(h->right->left)) {
		h->right = rotateRight(h->right);
		h = rotateLeft(h);
		// flipColors(h);         //这行代码有没有都行，有的话就是在向下递归时flipColors
		//没有的话在向上递归时会fixUp回去，下个函数也是一样；
	}
	return h;
}

Rb_tree::Base_ptr Rb_tree::moveRedRight(Base_ptr h) {
	flipColors(h);
	if (h->left && isRed(h->left->left)) {
		h = rotateRight(h);
		// flipColors(h);
	}
	return h;
}

Rb_tree::Base_ptr Rb_tree::eraseMin(Base_ptr h) { // 递归下降，返回时调整
	if (!h->left) {
		delete h;
		return nullptr;
	}
	if (!isRed(h->left) && !isRed(h->left->left)) {
		h = moveRedLeft(h);
	}
	h->left = eraseMin(h->left);
	return fixUp(h);
}

void Rb_tree::eraseMin() {
	if ( !isRed(root->right) && !isRed(root->left) ) // 先把root置红
		root->color = RED;
	root = eraseMin(root);
	if (root) root->color = BLACK; // 把root颜色改回来，下同
	N--;
}

Rb_tree::Base_ptr Rb_tree::erase(Base_ptr h, const T& element) {
	if (!h) return nullptr;
	if (element < h->val) {
		if (!isRed(h->left) && h->left && !isRed(h->left->left))
			h = moveRedLeft(h);
		h->left = erase(h->left, element);
	}
	else { // 此为大于或等于的情况
		if (isRed(h->left)) h = rotateRight(h); // 大于或者等于时都需先执行此行
		// 如果右边有红节点，则右旋，把等于转为大于继续递归
		if (h->val == element && h->right==nullptr) { // 右边为空时左边必为空
			N--;
			delete h;
			return nullptr;
		}
		if (!isRed(h->right) && h->right && !isRed(h->right->left))
			h = moveRedRight(h);
		if (element > h->val) {
			h->right = erase(h->right, element);
		}
		else {
			N--;
			h->right = delMin(h->right, h); // 左右不为空时，将右子树的最小值换上来
		}
	}
	return fixUp(h);
}

void Rb_tree::erase(const T& element) {
	if (!isRed(root->right) && !isRed(root->left))
		root->color = RED;
	root = erase(root, element);
	if (root) root->color = BLACK;
}

int Rb_tree::count(const T& element) const{ // 结果只有1和0
	Base_ptr h = root;
	while (h) {
		if (element < h->val) h = h->left;
		else if (element > h->val) h = h->right;
		else return 1;
	}
	return 0;
}

Rb_tree::Base_ptr Rb_tree::delMin(Base_ptr h, Base_ptr p) {
	if (!h->left) {
		p->val = h->val;
		delete h;
		return nullptr;
	}
	if (!isRed(h->left) && !isRed(h->left->left))
		h = moveRedLeft(h);
	h->left = delMin(h->left, p);
	return fixUp(h);
}

/* 技巧笔记：
1.可以在每个节点加入parent指针，然后定义header节点，
header与root互为父节点，header的左指针指向树的最小节点，
右指针指向树的最大节点，可以方便找到最小最大节点；
2.还可以在每个节点加入sub_tree_size，
在需要实现基于范围的查询时很有用；
*/
