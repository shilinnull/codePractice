#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>

using namespace std;

// 使用素数
size_t GetNextPrime(size_t prime)
{
	const int PRIMECOUNT = 28;
	static const size_t primeList[PRIMECOUNT] =
	{
		53ul,         97ul,        193ul,       389ul,      769ul,
		1543ul,       3079ul,      6151ul,      12289ul,    24593ul,
		49157ul,      98317ul,     196613ul,    393241ul,   786433ul,
		1572869ul,    3145739ul,   6291469ul,   12582917ul, 25165843ul,
		50331653ul,   100663319ul, 201326611ul, 402653189ul,805306457ul,
		1610612741ul, 3221225473ul, 4294967291ul
	};
	size_t i = 0;
	for (; i < PRIMECOUNT; ++i)
	{
		if (primeList[i] > prime)
			return primeList[i];
	}
	return primeList[i];
}

template<class K>
struct Hash
{
	size_t operator()(const K& key)
	{
		return (size_t)key;
	}
};


// 特化
template<>
struct Hash<string>
{
	size_t operator()(const string& key)
	{
		size_t hash = 0;
		for (auto e : key)
		{
			hash *= 31; // BKDR
			hash += e;
		}
		cout << key << ":" << hash << endl;
		return hash;
	}
};


namespace lsl_open_address
{
	// 状态
	enum Status
	{
		EMPTY, // 空
		EXIST, // 存在
		DELETE // 删除
	};

	//哈希表每个位置存储的结构
	template<class K, class V>
	struct HashData
	{
		pair<K, V> _kv; // 键值对
		Status _status = EMPTY; // 状态
	};


	template<class K, class V, class HashFun = Hash<K>>
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
			// 1、查看哈希表中是否存在该键值的键值对
			if (Find(kv.first))// 哈希表中已经存在该键值的键值对（不允许数据冗余）
				return false;

			//2、判断是否需要调整哈希表的大小
			if (_tables.size() == 0)
				_tables.resize(10);
			else if (_n * 10 / _tables.size() == 7)// 负载因子大于0.7需要增容
			{
				// 2倍扩容
				size_t newSize = _tables.size() * 2;
				//a、创建一个新的哈希表，新哈希表的大小设置为原哈希表的2倍
				HashTable<K, V, HashFun> newHT;
				newHT._tables.resize(newSize);

				//b、遍历旧表,将原哈希表当中的数据插入到新哈希表
				for (size_t i = 0; i < _tables.size(); i++)
				{
					// 如果_tables[i]的位置有数据就进行再次映射
					if (_tables[i]._status == EXIST)
					{
						newHT.Insert(_tables[i]._kv);
					}
					// c、与旧表进行交换
					_tables.swap(newHT._tables);
				}
			}// 扩容 end...

			HashFun hf; // 对于int来说是直接用值来比较，对于string类型使用BKDR方法来比较

			// 3、将键值对插入哈希表
			// a、通过哈希函数计算哈希地址，线性探测
			size_t hashi = hf(kv.first) % _tables.size(); // 除数不能是capacity

			size_t index = hashi, i = 1;

			//b、找到一个状态为EMPTY或DELETE的位置
			while (_tables[hashi]._status == EXIST)
			{
				index = hashi + i;					// 线性探测
				index = hashi + i * i;				 // 二次探测
				hashi %= _tables.size();			 // 防止下标超出哈希表范围
				i++;
			}

			//c、将数据插入该位置，并将该位置的状态设置为EXIST
			_tables[hashi]._kv = kv;
			_tables[hashi]._status = EXIST;

			//4、哈希表中的有效元素个数++
			++_n;
			return true;
		}

		// 查找方法
		HashData<K, V>* Find(const K& key)
		{
			if (_tables.size() == 0)
				return nullptr;

			HashFun hf;

			// 计算位置
			size_t hashi = hf(key) % _tables.size();
			size_t index = hashi, i = 1;

			// 不为空就一直找
			while (_tables[hashi]._status != EMPTY)
			{
				//若该位置的状态为EXIST，并且key值匹配，则查找成功
				if (_tables[hashi]._status == EXIST
					&& _tables[hashi]._kv.first == key)
				{
					return &_tables[hashi];
				}
				index = hashi + i;			// 线性探测
				// index = hashi + i * i;	// 二次探测
				hashi %= _tables.size();    // //防止下标超出哈希表范围
				++i;
			}

			// 找不到的情况
			return nullptr;
		}

		// 伪删除法
		bool Erase(const K& key)
		{
			//1、查看哈希表中是否存在该键值的键值对
			HashData<K, V>* res = Find(key);
			if (res)
			{
				//2、若存在，则将该键值对所在位置的状态改为DELETE即可
				res->_status = DELETE;
				--_n; //3、哈希表中的有效元素个数减一
				return true; // 删除成功
			}
			return false;    // 删除失败
		}

		void Print()
		{
			for (size_t i = 0; i < _tables.size(); i++)
			{
				if (_tables[i]._status == EXIST)
				{
					// printf("[%d]->%d\n", i, _tables[i].first);
					cout << "[" << i << "]->" << _tables[i]._kv.first << ":" << _tables[i]._kv.second << endl;
				}
				else if (_tables[i]._status == EMPTY)
				{
					printf("[%d]->\n", i);
				}
				else
				{
					printf("[%d]->E\n", i);
				}
			}
			cout << endl;
		}

	private:
		vector<HashData<K, V>> _tables;
		size_t _n = 0;// 存储的关键字的个数
	};
}

namespace lsl_hash_bucket
{
	template<class T>
	struct HashNode
	{
		HashNode<T>* _next;
		T _data;

		// 构造
		HashNode(const T& data)
			:_data(data)
			, _next(nullptr)
		{}
	};
	// 前置声明
	template<class K, class T, class KeyOfT, class Hash>
	class HashTable;

	template<class K, class T, class Ref, class Ptr, class KeyOfT, class Hash>
	struct __HTIterator
	{
		typedef HashNode<T> Node;							 // 哈希节点的类型
		typedef __HTIterator<K, T, Ref, Ptr, KeyOfT, Hash> Self;	 // 迭代器的类型

		const HashTable<K, T, KeyOfT, Hash>* _pht;			 // 哈希表的地址
		Node* _node;									     // 节点指针

		size_t _hashi;


		// 构造
		__HTIterator(Node* node, HashTable<K, T, KeyOfT, Hash>* pht, size_t hashi)
			:_node(node)
			, _pht(pht)
			, _hashi(hashi)
		{}

		__HTIterator(Node* node, const HashTable<K, T, KeyOfT, Hash>* pht, size_t hashi)
			:_node(node)
			, _pht(pht)
			, _hashi(hashi)
		{}

		Ref operator*()
		{
			//返回哈希结点中数据的引用
			return _node->_data;
		}

		Ptr operator->()
		{
			//返回哈希结点中数据的地址
			return &_node->_data;
		}

		bool operator!=(const Self& s) const
		{
			return _node != s._node;
		}

		bool operator==(const Self& s) const
		{
			return _node == s._node;
		}

		//前置++
		Self& operator++()
		{
			if (_node->_next)
			{
				// 当前桶还有节点，走到下一个节点
				_node = _node->_next;
			}
			else
			{
				// 当前桶已经走完了，找下一个桶开始
				++_hashi;
				while (_hashi < _pht->_tables.size())
				{
					if (_pht->_tables[_hashi])
					{
						_node = _pht->_tables[_hashi];
						break;
					}

					++_hashi;
				}

				if (_hashi == _pht->_tables.size())
				{
					_node = nullptr;
				}
			}
			return *this;
		}
	};

	template<class K, class T, class KeyOfT, class Hash>
	class HashTable
	{
		typedef HashNode<T> Node;

		template<class K, class T, class Ref, class Ptr, class KeyOfT, class Hash>
		friend struct __HTIterator;

	public:
		typedef __HTIterator<K, T, T&, T*, KeyOfT, Hash> iterator;
		typedef __HTIterator<K, T, const T&, const T*, KeyOfT, Hash> const_iterator;

		iterator begin()
		{
			for (size_t i = 0; i < _tables.size(); i++)
			{
				if (_tables[i])
				{
					return iterator(_tables[i], this, i);
				}
			}
			return end();
		}

		iterator end()
		{
			return iterator(nullptr, this, -1);
		}

		const_iterator begin() const
		{
			for (size_t i = 0; i < _tables.size(); i++)
			{
				if (_tables[i])
				{
					return const_iterator(_tables[i], this, i);
				}
			}
			return end();
		}

		const_iterator end() const
		{
			return const_iterator(nullptr, this, -1);
		}

		HashTable()
		{
			_tables.resize(GetNextPrime(0));
		}

		~HashTable()
		{
			//将哈希表当中的结点一个个释放
			for (size_t i = 0; i < _tables.size(); i++)
			{
				if (_tables[i])
				{
					Node* cur = _tables[i];
					while (cur) //将该桶的结点取完为止
					{
						Node* next = cur->_next; //记录下一个结点
						delete cur;
						cur = next;
					}
					_tables[i] = nullptr;
				}
			}
		}


		//赋值运算符重载函数
		HashTable& operator=(HashTable ht)
		{
			//交换哈希表中两个成员变量的数据
			_tables.swap(ht._table);
			swap(_n, ht._n);

			return *this;
		}


		iterator Find(const K& key)
		{
			Hash hf;
			KeyOfT kot;

			size_t hashi = hf(key) % _tables.size();
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					return iterator(cur, this, hashi);
				}

				cur = cur->_next;
			}

			return end();
		}

		pair<iterator, bool> Insert(const T& data)
		{
			Hash hf;
			KeyOfT kot;

			iterator it = Find(kot(data));
			if (it != end())
				return make_pair(it, false);

			// 负载因子最大到1
			if (_n == _tables.size())
			{
				vector<Node*> newTables;
				newTables.resize(_tables.size() * 2, nullptr);
				// 遍历旧表
				for (size_t i = 0; i < _tables.size(); i++)
				{
					Node* cur = _tables[i];
					while (cur)
					{
						Node* next = cur->_next;

						// 挪动到映射的新表
						size_t hashi = hf(kot(cur->_data)) % newTables.size();
						cur->_next = newTables[hashi];
						newTables[hashi] = cur;

						cur = next;
					}

					_tables[i] = nullptr;
				}

				_tables.swap(newTables);
			}

			size_t hashi = hf(kot(data)) % _tables.size();
			Node* newnode = new Node(data);

			// 头插
			newnode->_next = _tables[hashi];
			_tables[hashi] = newnode;
			++_n;

			return make_pair(iterator(newnode, this, hashi), true);
		}
		bool Earse(const K& key)
		{
			Hash hf;
			KeyOfT kot;

			//1、通过哈希函数计算出对应的哈希桶编号index（除数不能是capacity）
			size_t hashi = hf(kot(key)) % _tables.size();

			//2、在编号为index的哈希桶中寻找待删除结点
			Node* prev = nullptr;
			Node* cur = _tables[hashi];
			while (cur)
			{
				//3、若找到了待删除结点，则删除该结点
				if (cur->_kv.first == key)
				{
					if (prev == nullptr) //待删除结点是哈希桶中的第一个结点
					{
						_tables[hashi] = cur->_next; // 将第一个结点从该哈希桶中移除
					}
					else // 待删除结点不是哈希桶的第一个结点
					{
						prev->_next = cur->_next; // 将该结点从哈希桶中移除
					}
					delete cur;

					--_n; // 4、删除结点后，将哈希表中的有效元素个数减一
					return true;
				}
				// 继续往后找
				prev = cur;
				cur = cur->_next;
			}
			return false;
		}
	private:
		vector<Node*> _tables;
		size_t _n = 0;
	};

}

