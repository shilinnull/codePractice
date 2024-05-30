




// ע�⣺����ʵ�ֵĹ�ϣ����Ԫ��Ψһ����key��ͬ��Ԫ�ز��ٽ��в���
// Ϊ��ʵ�ּ򵥣��˹�ϣ�������ǽ��Ƚ�ֱ����Ԫ�ذ���һ��
namespace Close_Hash
{
	enum State { EMPTY, EXIST, DELETE };

	template<class K, class V>
	class HashTable
	{
		struct Elem
		{
			pair<K, V> _val;
			State _state;
		};

	public:
		HashTable(size_t capacity = 3)
			: _ht(capacity), _size(0), _totalSize(0)
		{
			for (size_t i = 0; i < capacity; ++i)
				_ht[i]._state = EMPTY;
		}

		// ����
		bool Insert(const pair<K, V>& val);

		// ����
		size_t Find(const K& key);

		// ɾ��
		bool Erase(const K& key);

		size_t Size()const
		{
			return _size;
		}

		bool Empty() const
		{
			return _size == 0;
		}

		void Swap(HashTable<K, V>& ht)
		{
			swap(_size, ht._size);
			swap(_totalSize, ht._totalSize);
			_ht.swap(ht._ht);
		}

	private:
		size_t HashFunc(const K& key)
		{
			return key % _ht.capacity();
		}

		void CheckCapacity();
	private:
		vector<Elem> _ht;
		size_t _size;
		size_t _totalSize;  // ��ϣ���е�����Ԫ�أ���Ч����ɾ��, ����ʱ��Ҫ�õ�
	};
}