#pragma once

#include"Hash.h"

namespace lsl
{
	template<class K, class Hash = Hash<K>>
	class unordered_set
	{
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};

	public:
		//现在没有实例化，没办法到HashTable里面找iterator，所以typename就是告诉编译器这里是一个类型，实例化以后再去取
		typedef typename lsl_hash_bucket::HashTable<K, K, SetKeyOfT, Hash>::const_iterator iterator;
		typedef typename lsl_hash_bucket::HashTable<K, K, SetKeyOfT, Hash>::const_iterator const_iterator;

		const_iterator begin() const
		{
			return _ht.begin();
		}

		const_iterator end() const
		{
			return _ht.end();
		}

		iterator find(const K& key)
		{
			return _ht.Find(key);
		}

		bool erase(const K& key)
		{
			return _ht.Erase(key);
		}

		pair<const_iterator, bool> insert(const K& key)
		{
			auto ret = _ht.Insert(key);
			return pair<const_iterator, bool>(const_iterator(ret.first._node, ret.first._pht, ret.first._hashi), ret.second);
		}

	private:
		lsl_hash_bucket::HashTable<K, K, SetKeyOfT, Hash> _ht;
	};
}
