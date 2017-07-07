#include <algorithm>
#include "llrb.h"
/*基本完全调用红黑树接口*/

using T = double;

class Set {
	public:
		void insert(const T& element); // 插入元素
		void erase(const T& element); // 删除元素
		void clear(); // 清空集合
		int count(const T& element) const; // 计算element个数
		bool empty(); // 判断是否为空
		unsigned size(); // 返回集合大小

	private:
		Rb_tree tree;
};

// TODO
