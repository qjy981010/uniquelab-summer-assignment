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
	enum color_type {BLACK = 0, RED}; // 定义颜色
	struct Node_base // 声明节点类
	{
		typedef Node_base* Base_ptr;
		color_type color = RED; // 初始设为RED
		Base_ptr left = nullptr;   //左孩子
		Base_ptr right = nullptr; // 右孩子
		T val; // 存储的值
	};
	typedef Node_base* Base_ptr;

private:
	Base_ptr root = nullptr;
	unsigned N = 0; // tree的大小，初始为0
	color_type isRed(Base_ptr h); // 判断是否为红色
	Base_ptr rotateLeft(Base_ptr h); // 左旋
	Base_ptr rotateRight(Base_ptr h); // 右旋
	Base_ptr moveRedLeft(Base_ptr h);
	Base_ptr moveRedRight(Base_ptr h);
	void flipColors(Base_ptr h); // 颜色颠倒
	void deltree(Base_ptr h); // 递归删除树
	Base_ptr fixUp(Base_ptr h); // 修复树
	Base_ptr eraseMin(Base_ptr h);
	Base_ptr delMin(Base_ptr h, Base_ptr head);
	Base_ptr put(Base_ptr h, T val);
	Base_ptr erase(Base_ptr h, const T& element);
};

#endif
