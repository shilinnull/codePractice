#include <iostream>
#include <vector>

using namespace std;


// ʹ������
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


// �ػ�
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

		// ����
		HashNode(const T& data)
			:_data(data)
			, _next(nullptr)
		{}
	};
	// ǰ������
	template<class K, class T, class KeyOfT, class Hash>
	class HashTable;

	template<class K, class T, class Ref, class Ptr, class KeyOfT, class Hash>
	struct __HTIterator
	{
		typedef HashNode<T> Node;							 // ��ϣ�ڵ������
		typedef __HTIterator<K, T, Ref, Ptr, KeyOfT, Hash> Self;	 // ������������

		const HashTable<K, T, KeyOfT, Hash>* _pht;			 // ��ϣ��ĵ�ַ
		Node* _node;									     // �ڵ�ָ��

		size_t _hashi;

		// ����
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
			//���ع�ϣ��������ݵ�����
			return _node->_data;
		}

		Ptr operator->()
		{
			//���ع�ϣ��������ݵĵ�ַ
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

		//ǰ��++
		Self& operator++()
		{
			if (_node->_next)
			{
				// ��ǰͰ���нڵ㣬�ߵ���һ���ڵ�
				_node = _node->_next;
			}
			else
			{
				// ��ǰͰ�Ѿ������ˣ�����һ��Ͱ��ʼ
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
			//����ϣ���еĽ��һ�����ͷ�
			for (size_t i = 0; i < _tables.size(); i++)
			{
				if (_tables[i])
				{
					Node* cur = _tables[i];
					while (cur) //����Ͱ�Ľ��ȡ��Ϊֹ
					{
						Node* next = cur->_next; //��¼��һ�����
						delete cur;
						cur = next;
					}
					_tables[i] = nullptr;
				}
			}
		}


		//��ֵ��������غ���
		HashTable& operator=(HashTable ht)
		{
			//������ϣ����������Ա����������
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

			// �����������1
			if (_n == _tables.size())
			{
				vector<Node*> newTables;
				newTables.resize(_tables.size() * 2, nullptr);
				// �����ɱ�
				for (size_t i = 0; i < _tables.size(); i++)
				{
					Node* cur = _tables[i];
					while (cur)
					{
						Node* next = cur->_next;

						// Ų����ӳ����±�
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

			// ͷ��
			newnode->_next = _tables[hashi];
			_tables[hashi] = newnode;
			++_n;

			return make_pair(iterator(newnode, this, hashi), true);
		}
		bool Earse(const K& key)
		{
			Hash hf;
			KeyOfT kot;

			//1��ͨ����ϣ�����������Ӧ�Ĺ�ϣͰ���index������������capacity��
			size_t hashi = hf(kot(key)) % _tables.size();

			//2���ڱ��Ϊindex�Ĺ�ϣͰ��Ѱ�Ҵ�ɾ�����
			Node* prev = nullptr;
			Node* cur = _tables[hashi];
			while (cur)
			{
				//3�����ҵ��˴�ɾ����㣬��ɾ���ý��
				if (cur->_kv.first == key)
				{
					if (prev == nullptr) //��ɾ������ǹ�ϣͰ�еĵ�һ�����
					{
						_tables[hashi] = cur->_next; // ����һ�����Ӹù�ϣͰ���Ƴ�
					}
					else // ��ɾ����㲻�ǹ�ϣͰ�ĵ�һ�����
					{
						prev->_next = cur->_next; // ���ý��ӹ�ϣͰ���Ƴ�
					}
					delete cur;

					--_n; // 4��ɾ�����󣬽���ϣ���е���ЧԪ�ظ�����һ
					return true;
				}
				// ����������
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
// ע�⣺����ʵ�ֵĹ�ϣ����Ԫ��Ψһ����key��ͬ��Ԫ�ز��ٽ��в���
// Ϊ��ʵ�ּ򵥣��˹�ϣ�������ǽ��Ƚ�ֱ����Ԫ�ذ���һ��
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

		// ����
		bool Insert(const pair<K, V>& val)
		{
			if (Find(val.first))
				return false;

			// �ж��Ƿ���Ҫ������ϣ��Ĵ�С
			if (_ht.size() == 0)
			{
				_ht.resize(10);
			}
			
			if (_n * 10 >= _ht.capacity()) // ע������
			{
				// �����µĹ�ϣ��
				HashTable<K, V> newHT;
				// 2������
				newHT._ht.resize(_ht.size() * 2);
				// ����
				for (size_t i = 0; i < _ht.size(); i++)
				{
					if (_ht[i]._state == EXIST)
					{
						newHT.Insert(_ht[i]._val);
					}
				}
				// ����
				_ht.swap(newHT._ht);
			}
			size_t hashi = val.first % _ht.size();
			while (_ht[hashi]._state == EXIST)
			{
				++hashi;
				hashi %= _ht.size();
			}

			// �����ݲ����λ�ã�������λ�õ�״̬����ΪEXIST
			_ht[hashi]._val = val;
			_ht[hashi]._state = EXIST;

			++_n;
			return true;
		}

		// ����
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

		// ɾ��
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
	// ʹ������
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


	// ������ʵ�ֵĹ�ϣͰ��key��Ψһ��
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


		// ��ϣͰ�е�Ԫ�ز����ظ�
		Node* Insert(const V& data)
		{
			CheckCapacity();


			// ����λ��
			size_t hashi = HashFunc(data) % _table.size();


			// ����Ƿ�������
			if (Find(data))
				return nullptr;


			Node* cur = _table[hashi];
			// ����ڵ�
			cur = new Node(data);
			cur->_pNext = _table[hashi];
			// ��hashi��λ�ó�Ϊ�µ�hashi
			_table[hashi] = cur;
			++_size;
			return cur;
		}


		// ɾ����ϣͰ��Ϊdata��Ԫ��(data�����ظ�)
		bool Erase(const V& data)
		{
			size_t hashi = HashFunc(data) % _table.size();

			Node* cur = _table[hashi];
			Node* prev = nullptr;
			while (cur)
			{
				if (cur->_data == data)
				{
					// ɾ�����ǵ�һ���ڵ�
					if (cur == _table[hashi])
					{
						_table[hashi] = cur->_pNext;
					}
					else // ɾ���Ĳ��ǵ�һ���ڵ�
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
						// ��cur�Ӿɱ���ɾ��
						// �Ƚ��ɱ����һ���ڵ㱣������
						_table[i] = cur->_pNext;
						// �����µ�λ�ã���cur�ڵ���뵽�µ�����
						size_t hashi = ht.HashFunc(cur->_data);
						// ͷ��
						cur->_pNext = ht._table[i];
						ht._table[hashi] = cur;
					}
				}
				this->Swap(ht);
			}
		}


	private:
		vector<Node*> _table;
		size_t _size;      // ��ϣ������ЧԪ�صĸ���
	};
}
#endif
