#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>

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


namespace lsl_open_address
{
	// ״̬
	enum Status
	{
		EMPTY, // ��
		EXIST, // ����
		DELETE // ɾ��
	};

	//��ϣ��ÿ��λ�ô洢�Ľṹ
	template<class K, class V>
	struct HashData
	{
		pair<K, V> _kv; // ��ֵ��
		Status _status = EMPTY; // ״̬
	};


	template<class K, class V, class HashFun = Hash<K>>
	class HashTable
	{
	public:
		HashTable()
		{
			_tables.resize(10);
		}

		// ���뷽��
		bool Insert(const pair<K, V>& kv)
		{
			// 1���鿴��ϣ�����Ƿ���ڸü�ֵ�ļ�ֵ��
			if (Find(kv.first))// ��ϣ�����Ѿ����ڸü�ֵ�ļ�ֵ�ԣ��������������ࣩ
				return false;

			//2���ж��Ƿ���Ҫ������ϣ��Ĵ�С
			if (_tables.size() == 0)
				_tables.resize(10);
			else if (_n * 10 / _tables.size() == 7)// �������Ӵ���0.7��Ҫ����
			{
				// 2������
				size_t newSize = _tables.size() * 2;
				//a������һ���µĹ�ϣ���¹�ϣ��Ĵ�С����Ϊԭ��ϣ���2��
				HashTable<K, V, HashFun> newHT;
				newHT._tables.resize(newSize);

				//b�������ɱ�,��ԭ��ϣ���е����ݲ��뵽�¹�ϣ��
				for (size_t i = 0; i < _tables.size(); i++)
				{
					// ���_tables[i]��λ�������ݾͽ����ٴ�ӳ��
					if (_tables[i]._status == EXIST)
					{
						newHT.Insert(_tables[i]._kv);
					}
					// c����ɱ���н���
					_tables.swap(newHT._tables);
				}
			}// ���� end...

			HashFun hf; // ����int��˵��ֱ����ֵ���Ƚϣ�����string����ʹ��BKDR�������Ƚ�

			// 3������ֵ�Բ����ϣ��
			// a��ͨ����ϣ���������ϣ��ַ������̽��
			size_t hashi = hf(kv.first) % _tables.size(); // ����������capacity

			size_t index = hashi, i = 1;

			//b���ҵ�һ��״̬ΪEMPTY��DELETE��λ��
			while (_tables[hashi]._status == EXIST)
			{
				index = hashi + i;					// ����̽��
				index = hashi + i * i;				 // ����̽��
				hashi %= _tables.size();			 // ��ֹ�±곬����ϣ��Χ
				i++;
			}

			//c�������ݲ����λ�ã�������λ�õ�״̬����ΪEXIST
			_tables[hashi]._kv = kv;
			_tables[hashi]._status = EXIST;

			//4����ϣ���е���ЧԪ�ظ���++
			++_n;
			return true;
		}

		// ���ҷ���
		HashData<K, V>* Find(const K& key)
		{
			if (_tables.size() == 0)
				return nullptr;

			HashFun hf;

			// ����λ��
			size_t hashi = hf(key) % _tables.size();
			size_t index = hashi, i = 1;

			// ��Ϊ�վ�һֱ��
			while (_tables[hashi]._status != EMPTY)
			{
				//����λ�õ�״̬ΪEXIST������keyֵƥ�䣬����ҳɹ�
				if (_tables[hashi]._status == EXIST
					&& _tables[hashi]._kv.first == key)
				{
					return &_tables[hashi];
				}
				index = hashi + i;			// ����̽��
				// index = hashi + i * i;	// ����̽��
				hashi %= _tables.size();    // //��ֹ�±곬����ϣ��Χ
				++i;
			}

			// �Ҳ��������
			return nullptr;
		}

		// αɾ����
		bool Erase(const K& key)
		{
			//1���鿴��ϣ�����Ƿ���ڸü�ֵ�ļ�ֵ��
			HashData<K, V>* res = Find(key);
			if (res)
			{
				//2�������ڣ��򽫸ü�ֵ������λ�õ�״̬��ΪDELETE����
				res->_status = DELETE;
				--_n; //3����ϣ���е���ЧԪ�ظ�����һ
				return true; // ɾ���ɹ�
			}
			return false;    // ɾ��ʧ��
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
		size_t _n = 0;// �洢�Ĺؼ��ֵĸ���
	};
}

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

