#pragma once

#include "RBTree.h"

namespace lsl
{
	template<class K>
	class set
	{
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
	public:

		typedef typename RBTree<K, const K, SetKeyOfT>::const_iterator iterator;
		typedef typename RBTree<K, const K, SetKeyOfT>::const_iterator const_iterator;

		iterator begin() 
		{
			return _t.begin();
		}

		iterator end() 
		{
			return _t.end();
		} 

		const_iterator begin() const
		{
			return _t.begin();
		}

		const_iterator end() const
		{
			return _t.end();
		}

		pair<iterator, bool> insert(const K& key)
		{
			return _t.Insert(key);
		}
<<<<<<< HEAD
=======
		//É¾³ıº¯Êı
		void erase(const K& key)
		{
			_t.Erase(key);
		}
>>>>>>> 7482668f66368f1919d0498280638e4cd2642d3c
		//²éÕÒº¯Êı
		iterator find(const K& key)
		{
			return _t.Find(key);
		}

	private:
		RBTree<K, const K, SetKeyOfT> _t;
	};
}

