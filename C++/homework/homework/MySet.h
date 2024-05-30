#pragma once
#include "iterator.h"


namespace lsl
{
	template<class K>
	class set
	{
	public:
		struct SetKetOFt
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};

		typedef typename RBTree<K, K, SetKetOFt>::const_iterator iterator;
		typedef typename RBTree<K, K, SetKetOFt>::const_iterator const_iterator;
		iterator begin() const
		{
			return _t.Begin();
		}

		iterator end() const
		{
			return _t.End();
		}
		//插入函数
		pair<iterator, bool> insert(const K& key)
		{
			return _t.Insert(key);
		}

		//查找函数
		iterator find(const K& key)
		{
			return _t.Find(key);
		}
		RBTree<K, K, SetKetOFt> _t;
	};
}