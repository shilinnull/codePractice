#pragma once

#include "HashTable.h"

namespace lsl
{
	template<class K, class Hash = HashFunc<K>>
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
		// �õ�һ��Ҳ����
		//typedef typename hash_bucket::HashTable<K, const K, SetKeyOfT, Hash>::ConstIterator iterator;

		typedef typename hash_bucket::HashTable<K, const K, SetKeyOfT, Hash>::Iterator iterator;
		typedef typename hash_bucket::HashTable<K, const K, SetKeyOfT, Hash>::ConstIterator const_iterator;

		// ʹ�����Ҳ����
		/*
		using iterator = typename hash_bucket::HashTable<K, const K, SetKeyOfT, Hash>::Iterator;
		using const_iterator = typename hash_bucket::HashTable<K, const K, SetKeyOfT, Hash>::ConstIterator;
		*/

		iterator begin()
		{
			return _ht.Begin();
		}

		iterator end()
		{
			return _ht.End();
		} 

		const_iterator begin() const
		{
			return _ht.Begin();
		}

		const_iterator end() const
		{
			return _ht.End();
		}

		std::pair<iterator, bool> insert(const K& key)
		{
			return _ht.Insert(key);
		}

	private:
		hash_bucket::HashTable<K, const K, SetKeyOfT, Hash> _ht;
	};

	/////////////////����/////////////
	// const������
	void print(const unordered_set<int>& s)
	{
		unordered_set<int>::const_iterator it = s.begin();
		while (it != s.end())
		{
			//*it = 1;
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
	}

	void unordered_set_Test()
	{
		unordered_set<int> s;
		s.insert(1);
		s.insert(5);
		s.insert(10);
		s.insert(508);
		s.insert(333);
		s.insert(82);

		for (auto& e : s)
		{
			std::cout << e << " ";
		}
		std::cout << std::endl;

		print(s);

		// set�������޸�
		unordered_set<int>::iterator it = s.begin();
		while (it != s.end())
		{
			//*it = 1;
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
	}
}
