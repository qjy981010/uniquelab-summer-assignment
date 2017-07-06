/*简单的可以重整的哈希表*/
#include "hashtable.h"

using namespace std;

int Hashtable::hash_func(KT key) { // 简单的哈希函数，能处理std::string
   int b     = 378551;
   int a     = 63689;
   long hash = 0;
   for(int i = 0; i < key.length(); i++)
   {
      hash = hash * a + key[i];
      a    = a * b;
   }
   return hash % size;
}

T Hashtable::search(KT key) {
	base_ptr h = buckets[hash_func(key)];
	for (; h && h->key != key; h = h->next);
	if (h) return h->val;
	else cerr << "Key Error" << endl;
}

void Hashtable::insert(KT key, T val) {
	int index = hash_func(key);
	base_ptr h = buckets[index];
	if (!h) {
		buckets[index] = new Hash_node(key, val);
		return;
	}
	for (int i = 1; ; h = h->next, i++) {
		if (h->key == key) {
			h->val = val;
			return;
		}
		if (!h->next) {
			base_ptr newone = new Hash_node(key, val);
			// newone->key = key;
			// newone->val =
			h->next = newone;
			if (i >= size) resize(); // 当有一个bucket的长度大于vector的长度时，重整vector；
			return;
		}
	}
}

void Hashtable::resize() {
	size_type oldsize = size;
	size = size_list[++size_index];
	vector<base_ptr> tmp(size, (base_ptr) 0); // 新的vector
	for (size_type bucket = 0; bucket < oldsize; ++bucket) {
		base_ptr first = buckets[bucket];
		while (first) { //重整vector时，每次将原节点插入新vector对应的bucket的最前端，避免了对bucket的遍历
			int new_bucket = hash_func(first->key);
			buckets[bucket] = first->next;
			first->next = tmp[new_bucket];
			tmp[new_bucket] = first;
			first = buckets[bucket];
		}
	}
	buckets.swap(tmp); // 交换新旧vector
}

void Hashtable::erase(KT key) {
	int index = hash_func(key);
	base_ptr h = buckets[index];
	if (!h) {
		cerr << "Key Error" << endl;
		return;
	}
	if (h->key == key && !h->next) {
		delete buckets[index];
		buckets[index] = 0;
		return;
	}
	for (; h->next && h->next->key != key; h = h->next);
	if (h->next) {
		if (h->next->next) {
			base_ptr p = h->next;
			for (; p->next->next; p = p->next);
			h->next->key = p->next->key;
			h->next->val = p->next->val;
			delete p->next;
			p->next = 0;
		}
		else {
			delete h->next;
			h->next = 0;
			return;
		}
	}
	else cerr << "Key Error" << endl;

}
