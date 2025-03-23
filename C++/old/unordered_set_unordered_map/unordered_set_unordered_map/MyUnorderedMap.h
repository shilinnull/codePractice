#pragma once

#include"HashTable.h"


namespace lsl
{
	template<class K, class V, class Hash = Hash<K>>
	class unordered_map
	{
		struct MapKeyOfT
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};
	public:
		typedef typename lsl_hash_bucket::HashTable<K, pair<const K, V>, MapKeyOfT, Hash>::iterator iterator;

		iterator begin()
		{
			return _ht.begin();
		}

		iterator end()
		{
			return _ht.end();
		}

		pair<iterator, bool> insert(const pair<K, V>& kv)
		{
			return _ht.Insert(kv);
		}

		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = _ht.Insert(make_pair(key, V()));
			return ret.first->second;
		}

		const V& operator[](const K& key) const
		{
			pair<iterator, bool> ret = _ht.Insert(make_pair(key, V()));
			return ret.first->second;
		}

		iterator find(const K& key)
		{
			return _ht.Find(key);
		}

		bool erase(const K& key)
		{
			return _ht.Erase(key);
		}

	private:
		lsl_hash_bucket::HashTable<K, pair<const K, V>, MapKeyOfT, Hash> _ht;
	};

	void test_map()
	{
		unordered_map<string, string> dict;
		dict.insert(make_pair("sort", "排序"));
		dict.insert(make_pair("string", "字符串"));
		dict.insert(make_pair("insert", "插入"));

		for (auto& kv : dict)
		{
			//kv.first += 'x';
			kv.second += 'x';

			cout << kv.first << ":" << kv.second << endl;
		}
		cout << endl;

		string arr[] = { "香蕉", "甜瓜","苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉" };
		unordered_map<string, int> count_map;
		for (auto& e : arr)
		{
			count_map[e]++;
		}

		for (auto& kv : count_map)
		{
			cout << kv.first << ":" << kv.second << endl;
		}
		cout << endl;
	}
}
