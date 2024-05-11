#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>

using namespace std;


template<class K>
struct HashFunc
{
	size_t operator()(const K& key)
	{
		return (size_t)key;
	}
};


// �ػ�
template<>
struct HashFunc<string>
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


	//struct HashFuncString
	//{
	//	size_t operator()(const string& key)
	//	{
	//		// BKDR
	//		size_t hash = 0;
	//		for (auto e : key)
	//		{
	//			hash *= 31;
	//			hash += e;
	//		}

	//		cout << key << ":" << hash << endl;
	//		return hash;
	//	}
	//};

	template<class K, class V, class HashFun = HashFunc<K>>
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


	void TestHT1()
	{
		HashTable<int, int> ht;
		int a[] = { 4,14,24,34,5,7,1 };
		for (auto e : a)
		{
			ht.Insert(make_pair(e, e));
		}

		ht.Insert(make_pair(3, 3));
		ht.Insert(make_pair(3, 3));
		ht.Insert(make_pair(-3, -3));
		ht.Print();

		ht.Erase(3);
		ht.Print();

		if (ht.Find(3))
		{
			cout << "3����" << endl;
		}
		else
		{
			cout << "3������" << endl;
		}

		ht.Insert(make_pair(3, 3));
		ht.Insert(make_pair(23, 3));
		ht.Print();
	}

	void TestHT2()
	{
		string arr[] = { "�㽶", "���","ƻ��", "����", "ƻ��", "����", "ƻ��", "ƻ��", "����", "ƻ��", "�㽶", "ƻ��", "�㽶" };
		HashTable<string, int, HashFunc<string>> ht;
		// HashTable<string, int> ht; // ʹ���ػ�
		for (auto& e : arr)
		{
			//auto ret = ht.Find(e);
			HashData<string, int>* ret = ht.Find(e);
			if (ret)
			{
				ret->_kv.second++;
			}
			else
			{
				ht.Insert(make_pair(e, 1));
			}
		}

		ht.Print();

		ht.Insert(make_pair("apple", 1));
		ht.Insert(make_pair("sort", 1));

		ht.Insert(make_pair("abc", 1));
		ht.Insert(make_pair("acb", 1));
		ht.Insert(make_pair("aad", 1));

		ht.Print();
	}
}


namespace lsl_hash_bucket
{
	template<class K,class V>
	struct HashData
	{
		HashData<K, V>* _next;
		pair<K, V> _kv;

		// ����
		HashData(const pair<K,V> &kv)
			:_kv(kv)
			,_next(nullptr)
		{}

	};


	template<class K, class V, class Hash = HashFunc<K>>
	class HashTable
	{
		typedef HashData<K, V> Node;
	public:
		HashTable()
		{
			_tables.resize(10);
		}
		~HashTable()
		{
			for (int i = 0; i < _tables.size(); i++)
			{
				Node* cur = _tables[i];
				while (cur)
				{
					Node* next = cur->_next;
					delete cur;
					cur = next;
				}
				_tables[i] = nullptr;
			}
		}


		Node* Find(const K& key)
		{
			Hash hf; // ͨ���º���

			if (_tables.size() == 0) // ��ϣ���СΪ0������ʧ��
				return nullptr;
			size_t hashi = hf(key) % _tables.size(); // ͨ����ϣ�����������Ӧ�Ĺ�ϣͰ���

			// ������ϣͰ
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (cur->_kv.first == key) 
					return cur;
				cur = cur->_next;
			}

			return nullptr;
		}

		bool Insert(const pair<K, V>& kv)
		{
			// 1���鿴��ϣ�����Ƿ���ڸü�ֵ�ļ�ֵ��
			if (Find(kv))
				return false;

			Hash hf;

			// 2���ж��Ƿ���Ҫ������ϣ��Ĵ�С
			if (_n == _tables.size())// ��ϣ��Ĵ�СΪ0���������ӳ���1
			{
				//����
				//a������һ���µĹ�ϣ���¹�ϣ��Ĵ�С����Ϊԭ��ϣ���2��������ϣ���СΪ0���򽫹�ϣ��ĳ�ʼ��С����Ϊ10��
				vector<Node*> newTables;
				size_t newsize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				newTables.resize(newsize, nullptr);
				// b����ԭ��ϣ���еĽ����뵽�¹�ϣ��
				for (size_t i = 0; i < _tables.size(); i++)
				{
					if (_tables[i])// Ͱ��Ϊ��
					{
						Node* cur = _tables[i];  //����Ͱ�Ľ��ȡ��Ϊֹ
						while (cur)
						{
							Node* next = cur->_next; //��¼cur����һ�����
							size_t index = hf(cur->_kv.first) % newTables.size(); // ͨ����ϣ�����������Ӧ�Ĺ�ϣͰ���index							cur->_next = newTables[index];
							newTables[index] = cur; // ���ý��ͷ�嵽�¹�ϣ���б��Ϊindex�Ĺ�ϣͰ��

							cur = next; // ȡԭ��ϣ���и�Ͱ����һ�����
						}	
						_tables[i] = nullptr; // ��Ͱȡ��󽫸�Ͱ�ÿ�
					}
				}

			}

			size_t hashi = hf(kv.first) % _tables.size();
			Node* newnode = new Node(kv);

			// ͷ��
			newnode->_next = _tables[hashi];
			_tables[hashi] = newnode;

			++_n;
			return true;
		}
		
		bool Earse(const K& key)
		{
			Hash hf;

			//1��ͨ����ϣ�����������Ӧ�Ĺ�ϣͰ���index������������capacity��
			size_t hashi = hf(key) % _tables.size();

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

