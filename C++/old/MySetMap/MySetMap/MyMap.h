#pragma once
#include"RBTree.h"

namespace lsl //防止命名冲突
{
	template<class K, class V>
	class map
	{
	public:
		//仿函数
		struct MapKeyOfT
		{
			const K& operator()(const pair<K, V>& kv) //返回键值对当中的键值Key
			{
				return kv.first;
			}
		};

		typedef typename RBTree<K, pair<const K, V>, MapKeyOfT>::iterator iterator;
		typedef typename RBTree<K, pair<const K, V>, MapKeyOfT>::const_iterator const_iterator; // const迭代器

		iterator begin()		
		{
			return _t.begin();
		}
		iterator end()
		{
			return _t.end();
		} 
		//插入函数
		pair<iterator, bool> insert(const pair<const K, V>& kv)
		{
			return _t.Insert(kv);
		}
		//[]运算符重载函数
		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = insert(make_pair(key, V()));
			return ret.first->second;
		}
		//删除函数
		void erase(const K& key)
		{
			_t.Erase(key);
		}
		//查找函数
		iterator find(const K& key)
		{
			return _t.Find(key);
		}
	private:
		RBTree<K, pair<const K, V>, MapKeyOfT> _t;
	};
}

