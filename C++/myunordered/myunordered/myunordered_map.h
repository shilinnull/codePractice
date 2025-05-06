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

		// ʹ�����Ҳ����
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

	/////////////////����/////////////
	// const������
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
		s.insert({ "string", "�ַ���" });
		s.insert({ "left", "��" });

		unordered_map<std::string, std::string>::iterator it = s.begin();
		while (it != s.end())
		{
			std::cout << it->first << ":" << it->second << std::endl;
			++it;
		}

		print(s);

		s["sort"];
		s["left"] = "���+ʣ��";
		s["right"] = "�ұ�";

		// pair�е�first���ܱ��޸�
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
