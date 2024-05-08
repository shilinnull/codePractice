#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>

using namespace std;

namespace hash_addres
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
			HashFun hf;

			// ����λ��
			size_t hashi = hf(key) % _tables.size();

			while (_tables[hashi]._status != EMPTY)
			{
				//����λ�õ�״̬ΪEXIST������keyֵƥ�䣬����ҳɹ�
				if (_tables[hashi]._status == EXIST
					&& _tables[hashi]._kv.first == key)
				{
					return &_tables[hashi];
				}
				++hashi;
				hashi %= _tables.size();
			}
			// �Ҳ���
			return nullptr;
		}

		// αɾ����
		bool Erase(const K& key)
		{
			HashData<K, V>* res = Find(key);
			if (res)
			{
				res->_status = DELETE;
				--_n;
				return true;
			}
			else
			{
				return false;
			}
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

