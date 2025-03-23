#pragma once

#include "iterator.h"
namespace lsl
{
	template<class K,class T>
	class map
	{
	public:
		struct MapKetOFt
		{
			const K& operator()(const pair<K, T>& kv)
			{
				return kv.first;
			}
		};

		typedef typename lsl::RBTree<K, pair<const K, T>, MapKetOFt>::iterator iterator;
		typedef typename lsl::RBTree<K, pair<const K, T>, MapKetOFt>::const_iterator const_iterator;

		iterator begin()
		{
			return _t.Begin();
		}
		iterator end()
		{
			return _t.End();
		}
		pair<iterator, bool> insert(const pair<const K, T>& kv)
		{
			return _t.Insert(kv);
		}

		T& operator[](const K& key)
		{
			//1、调用insert函数插入键值对
			pair<iterator, bool> ret = insert(make_pair(key,T()));
			//2、拿出从insert函数获取到的迭代器
			iterator it = ret.first;
			//3、返回该迭代器位置元素的值value
			return it->second;
		}
		//查找函数
		iterator find(const K& key)
		{
			return _t.Find(key);
		}
	private:
		RBTree<K, pair<const K, T>, MapKetOFt> _t;
	};
}