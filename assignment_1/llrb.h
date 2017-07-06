#ifndef _LLRB_H
#define _LLRB_H

using T = double;

const bool RED = true;
const bool BLANK = false;

class __rb_tree_node_base {
	typedef bool color_type;
	typedef __rb_tree_node_base* base_ptr;
	color_type color = RED;
	base_ptr left = 0;
	base_ptr right = 0;
	T val;
	friend class Rb_tree;
};

class Rb_tree {
public:
	typedef bool color_type;
	typedef unsigned size_type;
	typedef __rb_tree_node_base* base_ptr;
private:
	friend class __rb_tree_node_base;
	base_ptr root = 0;
	size_type N = 0;
	base_ptr tail = new __rb_tree_node_base;
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
	base_ptr eraseMin(base_ptr h);
	base_ptr delMin(base_ptr h, base_ptr head);
	base_ptr put(base_ptr h, T val);
	base_ptr erase(base_ptr h, const T& element);
public:
	~Rb_tree();
	size_type size() const { return N; }
	bool empty() const { return N == 0; } // 是否为空
	void insert(const T& element);
	void eraseMin(); // 删除最小节点
	void erase(const T& element); // 删除任意节点
	void clear(); // 清空
	int count(const T& element) const;
};

/* 技巧笔记：
1.可以在每个节点加入parent指针，然后定义header节点，
header与root互为父节点，header的左指针指向树的最小节点，
右指针指向树的最大节点，可以方便找到最小最大节点；
2.还可以在每个节点加入sub_tree_size，
在需要实现数出某个范围内节点个数时很有用；
*/

#endif
