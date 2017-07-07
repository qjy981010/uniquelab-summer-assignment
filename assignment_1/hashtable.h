#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <vector>
#include <iostream>
#include <string>

using T = double;
using KT = std::string;


class Hash_node
{
	public:
		Hash_node(KT _key, T _val);
	private:
		Hash_node* next = nullptr;
		KT key;
		T val;
		friend class Hashtable;
};

class Hashtable
{
	public:
		typedef Hash_node* base_ptr;
		T search(KT key);
		void insert(KT key, T val);
		void erase(KT key);
		Hashtable();
	private:
		unsigned size = 37;
		std::vector<base_ptr> buckets;
		int hash_func(KT key);
		char size_index = -1;
		void resize();
		const unsigned size_list[8] = {53, 97, 193, 389, 769, 1543,
			3079, 6151, };
};

#endif
