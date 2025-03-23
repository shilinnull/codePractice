#pragma once

#include "RBTree.h"
namespace lsl //·ÀÖ¹ÃüÃû³åÍ»
{
	template<class K>
	class set
	{
	public:
		//·Âº¯Êı
		struct SetKeyOfT
		{
			const K& operator()(const K& key) //·µ»Ø¼üÖµKey
			{
				return key;
			}
		};
		typedef typename RBTree<K, K, SetKeyOfT>::const_iterator iterator;
		typedef typename RBTree<K, K, SetKeyOfT>::const_iterator const_iterator;//constµü´úÆ÷

		iterator begin() const
		{
			return _t.begin();
		}

		iterator end() const
		{
			return _t.end();
		}

		//²åÈëº¯Êı
		pair<iterator, bool> insert(const K& key)
		{
			return _t.Insert(key);
		}
		//É¾³ıº¯Êı
		void erase(const K& key)
		{
			_t.Erase(key);
		}
		//²éÕÒº¯Êı
		iterator find(const K& key)
		{
			return _t.Find(key);
		}
	private:
		RBTree<K, K, SetKeyOfT> _t;
	};
}

