




// 注意：假如实现的哈希表中元素唯一，即key相同的元素不再进行插入
// 为了实现简单，此哈希表中我们将比较直接与元素绑定在一起
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

		// 插入
		bool Insert(const pair<K, V>& val);

		// 查找
		size_t Find(const K& key);

		// 删除
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
		size_t _totalSize;  // 哈希表中的所有元素：有效和已删除, 扩容时候要用到
	};
}