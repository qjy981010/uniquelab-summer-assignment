----------------
UniqueLab Summer Camp Assignment 0
---------------- 

**实现 C++ STL 中的 priority_queue 和 set. 无需实现template泛型，钦定类型为 T = double**
1. priorty_queue 需要实现 empty(), size(), top(), push(const T&), pop()方法
2. set 需要实现insert(const T&), erase(const T&), clear(), count(const T&), empty(), size(). 钦定数据结构内核为**左倾红黑树(LLRB)**

**所有接口以及功能参照 STL 文档**

其中priority_queue的底层用自己写的简单的vector实现
