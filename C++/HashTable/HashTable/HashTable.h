#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>

using namespace std;

namespace lsl
{
	enum Status
	{
		EMPTY, // 空
		EXIST, // 存在
		DELETE // 删除
	};

	template<class K, class V>
	struct HashData
	{
		pair<K, V> _kv;
		Status _status; // 状态
	};


	template<class K, class V>
	class HashTable
	{
	public:
		HashTable()
		{
			_tables.resize(10); 
		}
		
		// 插入方法
		bool Insert(const pair<K, V>& kv)
		{
			// 负载因子0.7就扩容
			if (_n * 10 / _tables.size() == 7)
			{
				// 2倍扩容
				size_t newSize = _tables.size() * 2;
				HashTable<K, V> newHT;
				newHT._tables.resize(newSize);

				// 遍历旧表
				for (size_t i = 0; i < _tables.size(); i++)
				{
					// 如果_tables[i]的位置有数据就进行再次映射
					if (_tables[i]._status == EXIST)
					{
						newHT.Insert(_tables[i]._kv);
					}
					// 与旧表进行交换
					_tables.swap(newHT._tables);
				}
			}// 扩容 end...

			// 将键值对插入哈希表
			// 通过哈希函数计算哈希地址
			size_t hashi = kv.first % _tables.size(); // 除数不能是capacity
			while (_tables[hashi]._status == EXIST)
			{
				hashi++; // 线性探测
				hashi %= _tables.size(); // 防止下标超出哈希表范围

				++_n;
				return true;
			}
		}
	private:
		vector<HashTable> _tables;
		size_t _n = 0;// 存储的关键字的个数
	};

}

