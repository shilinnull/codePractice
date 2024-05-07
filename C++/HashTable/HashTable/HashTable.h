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
		EMPTY, // ��
		EXIST, // ����
		DELETE // ɾ��
	};

	template<class K, class V>
	struct HashData
	{
		pair<K, V> _kv;
		Status _status; // ״̬
	};


	template<class K, class V>
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
			// ��������0.7������
			if (_n * 10 / _tables.size() == 7)
			{
				// 2������
				size_t newSize = _tables.size() * 2;
				HashTable<K, V> newHT;
				newHT._tables.resize(newSize);

				// �����ɱ�
				for (size_t i = 0; i < _tables.size(); i++)
				{
					// ���_tables[i]��λ�������ݾͽ����ٴ�ӳ��
					if (_tables[i]._status == EXIST)
					{
						newHT.Insert(_tables[i]._kv);
					}
					// ��ɱ���н���
					_tables.swap(newHT._tables);
				}
			}// ���� end...

			// ����ֵ�Բ����ϣ��
			// ͨ����ϣ���������ϣ��ַ
			size_t hashi = kv.first % _tables.size(); // ����������capacity
			while (_tables[hashi]._status == EXIST)
			{
				hashi++; // ����̽��
				hashi %= _tables.size(); // ��ֹ�±곬����ϣ��Χ

				++_n;
				return true;
			}
		}
	private:
		vector<HashTable> _tables;
		size_t _n = 0;// �洢�Ĺؼ��ֵĸ���
	};

}

