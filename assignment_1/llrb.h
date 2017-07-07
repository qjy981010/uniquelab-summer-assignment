#ifndef LLRB_H_
#define LLRB_H_

using T = double;

class Rb_tree
{
	public:
		~Rb_tree();
		unsigned size() const;
		bool empty() const; // 是否为空
		void insert(const T& element); // 插入节点
		int count(const T& element) const; // 计算val为element的个数
		void eraseMin(); // 删除最小节点
		void erase(const T& element); // 删除任意节点
		void clear(); // 清空

	private:
		enum color_type {BLANK, RED}; // 定义颜色

	public:
		class __rb_tree_node_base // 声明节点类
		{
			typedef __rb_tree_node_base* base_ptr;
			color_type color = RED; // 初始设为RED
			base_ptr left = nullptr;   //左孩子
			base_ptr right = nullptr; // 右孩子
			T val; // 存储的值
			friend class Rb_tree;
		};
		typedef __rb_tree_node_base* base_ptr;

	private:
		base_ptr root = nullptr;
		unsigned N = 0; // tree的大小，初始为0
		color_type isRed(base_ptr h); // 判断是否为红色
		base_ptr rotateLeft(base_ptr h); // 左旋
		base_ptr rotateRight(base_ptr h); // 右旋
		base_ptr moveRedLeft(base_ptr h);
		base_ptr moveRedRight(base_ptr h);
		void flipColors(base_ptr h); // 颜色颠倒
		void deltree(base_ptr h); // 递归删除树
		base_ptr fixUp(base_ptr h); // 修复树
		base_ptr eraseMin(base_ptr h);
		base_ptr delMin(base_ptr h, base_ptr head);
		base_ptr put(base_ptr h, T val);
		base_ptr erase(base_ptr h, const T& element);
};

#endif
