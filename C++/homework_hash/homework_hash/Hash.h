
#include <iostream>
#include <vector>

using namespace std;

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