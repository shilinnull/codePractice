#pragma once

#include "HashTable.h"

namespace lsl
{
	template<class K, class V, class Hash = HashFunc<K>>
	class unordered_map
	{
		struct MapKeyOfT
		{
			const K& operator()(const std::pair<K, V>& kv)
			{
				return kv.first;
			}
		};
	public:
		typedef typename hash_bucket::HashTable<K, std::pair<const K, V>, MapKeyOfT, Hash>::Iterator iterator;
		typedef typename hash_bucket::HashTable<K, std::pair<const K, V>, MapKeyOfT, Hash>::ConstIterator const_iterator;

		// 使用这个也可以
		/*
		using iterator = typename hash_bucket::HashTable<K, std::pair<const K, V>, MapKeyOfT, Hash>::Iterator;
		using const_iterator = typename hash_bucket::HashTable<K, std::pair<const K, V>, MapKeyOfT, Hash>::ConstIterator;
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

		std::pair<iterator, bool> insert(const std::pair<K, V>& kv)
		{
			return _ht.Insert(kv);
		}

		V& operator[](const K& key)
		{
			std::pair<iterator, bool> ret = _ht.Insert({ key, V() });
			return ret.first->second;
		}

	private:
		hash_bucket::HashTable<K, std::pair<const K, V>, MapKeyOfT, Hash> _ht;
	};

	/////////////////测试/////////////
	// const迭代器
	void print(const unordered_map<std::string, std::string>& s)
	{
		unordered_map<std::string, std::string>::const_iterator it = s.begin();
		while (it != s.end())
		{
			//*it = 1;
			std::cout << it->first << " " << it->second << std::endl;
			++it;
		}
		std::cout << std::endl;
	}

	void unordered_map_Test()
	{
		unordered_map<std::string, std::string> s;
		s.insert({ "string", "字符串" });
		s.insert({ "left", "左" });

		unordered_map<std::string, std::string>::iterator it = s.begin();
		while (it != s.end())
		{
			std::cout << it->first << ":" << it->second << std::endl;
			++it;
		}

		print(s);

		s["sort"];
		s["left"] = "左边+剩余";
		s["right"] = "右边";

		// pair中的first不能被修改
		unordered_map<std::string, std::string>::iterator it2 = s.begin();
		while (it2 != s.end())
		{
			//it2->first += 'x';
			//it2->second += 'x';
			std::cout << it2->first << ":" << it2->second << std::endl;
			++it2;
		}
	}
}
