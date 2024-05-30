
#include <iostream>
#include <vector>

using namespace std;

// 注意：假如实现的哈希表中元素唯一，即key相同的元素不再进行插入
// 为了实现简单，此哈希表中我们将比较直接与元素绑定在一起
namespace Close_Hash
{
	enum State { EMPTY, EXIST, DELETE };

	template<class K, class V>
	class HashTable
	{
	public:
		struct Elem
		{
			pair<K, V> _val;
			State _state = EMPTY;
		};

	public:
		HashTable()
		{
			_ht.resize(3);
		}

		// 插入
		bool Insert(const pair<K, V>& val)
		{
			if (Find(val.first))
				return false;

			// 判断是否需要调整哈希表的大小
			if (_ht.size() == 0)
			{
				_ht.resize(10);
			}
			
			if (_n * 10 >= _ht.capacity()) // 注意这里
			{
				// 创建新的哈希表
				HashTable<K, V> newHT;
				// 2倍扩容
				newHT._ht.resize(_ht.size() * 2);
				// 插入
				for (size_t i = 0; i < _ht.size(); i++)
				{
					if (_ht[i]._state == EXIST)
					{
						newHT.Insert(_ht[i]._val);
					}
				}
				// 交换
				_ht.swap(newHT._ht);
			}
			size_t hashi = val.first % _ht.size();
			while (_ht[hashi]._state == EXIST)
			{
				++hashi;
				hashi %= _ht.size();
			}

			// 将数据插入该位置，并将该位置的状态设置为EXIST
			_ht[hashi]._val = val;
			_ht[hashi]._state = EXIST;

			++_n;
			return true;
		}

		// 查找
		Elem* Find(const K& key)
		{
			size_t hashi = key % _ht.size();
			while (_ht[hashi]._state != EMPTY)
			{
				if (_ht[hashi]._state == EXIST && _ht[hashi]._val.first == key)
				{
					return &_ht[hashi];
				}
				++hashi;
				hashi %= _ht.size();
			}
			return nullptr;
		}

		// 删除
		bool Erase(const K& key)
		{
			Elem* ret = Find(key);
			if (ret == nullptr)
				return false;
			else
			{
				ret->_state = DELETE;
				--_n;

				return true;
			}
		}

		size_t Size()const
		{
			return _n;
		}

		bool Empty() const
		{
			return _n == 0;
		}

		void Swap(HashTable<K, V>& ht)
		{
			swap(_n, ht._n);
			_ht.swap(ht._ht);
		}

	private:
		size_t HashFunc(const K& key)
		{
			return key % _ht.capacity();
		}
	private:
		vector<Elem> _ht;
		size_t _n = 0;
	};
}