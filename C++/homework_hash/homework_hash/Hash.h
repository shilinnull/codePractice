#include <iostream>
#include <vector>

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



#if 0
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


namespace OpenHash
{
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


	template<class T>
	class HashFunc
	{
	public:
		size_t operator()(const T& val)
		{
			return val;
		}
	};


	template<>
	class HashFunc<string>
	{
	public:
		size_t operator()(const string& s)
		{
			const char* str = s.c_str();
			unsigned int seed = 131; // 31 131 1313 13131 131313
			unsigned int hash = 0;
			while (*str)
			{
				hash = hash * seed + (*str++);
			}


			return hash;
		}
	};


	template<class V>
	struct HashBucketNode
	{
		HashBucketNode(const V& data)
			: _pNext(nullptr), _data(data)
		{}
		HashBucketNode<V>* _pNext;
		V _data;
	};


	// 本文所实现的哈希桶中key是唯一的
	template<class V, class HF = HashFunc<V>>
	class HashBucket
	{
		typedef HashBucketNode<V> Node;
		typedef Node* PNode;


		typedef HashBucket<V, HF> Self;


	public:
		HashBucket(size_t capacity)
			: _table(GetNextPrime(capacity))
			, _size(0)
		{}


		~HashBucket()
		{
			Clear();
		}


		// 哈希桶中的元素不能重复
		Node* Insert(const V& data)
		{
			CheckCapacity();


			// 计算位置
			size_t hashi = HashFunc(data) % _table.size();


			// 检测是否在其中
			if (Find(data))
				return nullptr;


			Node* cur = _table[hashi];
			// 插入节点
			cur = new Node(data);
			cur->_pNext = _table[hashi];
			// 让hashi的位置成为新的hashi
			_table[hashi] = cur;
			++_size;
			return cur;
		}


		// 删除哈希桶中为data的元素(data不会重复)
		bool Erase(const V& data)
		{
			size_t hashi = HashFunc(data) % _table.size();

			Node* cur = _table[hashi];
			Node* prev = nullptr;
			while (cur)
			{
				if (cur->_data == data)
				{
					// 删除的是第一个节点
					if (cur == _table[hashi])
					{
						_table[hashi] = cur->_pNext;
					}
					else // 删除的不是第一个节点
					{
						prev->_pNext = cur->_pNext;
					}
					delete cur;
					--size;
					return true;
				}
				prev = cur;
				cur = cur->_pNext;
			}
			return false;
		}


		Node* Find(const V& data)
		{
			size_t hashi = HashFunc(data) % _table.size();
			Node* cur = _table[i];
			while (cur)
			{
				if (data == cur->_data)
					return cur;
				cur = cur->_pNext;
			}
			return nullptr;
		}


		size_t Size()const
		{
			return _size;
		}


		bool Empty()const
		{
			return 0 == _size;
		}


		void Clear()
		{
			for (size_t i = 0; i < _table.capacity(); i++)
			{
				Node* cur = _table[i];


				while (cur)
				{
					_table[i] = cur->_pNext;
					delete cur;


					cur = _table[i];
				}
			}
			_size = 0;
		}


		size_t BucketCount()const
		{
			return _table.capacity();
		}


		void Swap(Self& ht)
		{
			_table.swap(ht._table);
			swap(_size, ht._size);
		}


	private:
		size_t HashFunc(const V& data)
		{
			return HF()(data) % _table.capacity();
		}


		void CheckCapacity()
		{
			if (_size == _table.capacity())
			{
				Self ht(GetNextPrime(_size));
				for (int i = 0; i < _table.capacity(); i++)
				{
					Node* cur = _table[i];

					while (cur)
					{
						// 将cur从旧表中删除
						// 先将旧表的下一个节点保存下来
						_table[i] = cur->_pNext;
						// 计算新的位置，将cur节点插入到新的链表
						size_t hashi = ht.HashFunc(cur->_data);
						// 头插
						cur->_pNext = ht._table[i];
						ht._table[hashi] = cur;
					}
				}
				this->Swap(ht);
			}
		}


	private:
		vector<Node*> _table;
		size_t _size;      // 哈希表中有效元素的个数
	};
}
#endif
