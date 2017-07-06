#ifndef _HASHTABLE_H
#define _HASHTABLE_H

#include <vector>
#include <iostream>
#include <string>

using T = double;
using KT = std::string;

class Hash_node {
	Hash_node* next = nullptr;
	KT key;
	T val;
	friend class Hashtable;
public:
	Hash_node(KT _key, T _val) { key = _key; val = _val; };
};

class Hashtable {
public:
	typedef std::size_t size_type;
	typedef Hash_node* base_ptr;
	T search(KT key);
	void insert(KT key, T val);
	void erase(KT key);
	Hashtable() {
		for (char i = 0; i != 37; i++) buckets.push_back((base_ptr) 0);
	}
private:
	size_type size = 37;
	std::vector<base_ptr> buckets;
	int hash_func(KT key);
	char size_index = -1;
	void resize();
	const unsigned long size_list[8] = {53, 97, 193, 389, 769, 1543,
		3079, 6151, };
};

#endif
