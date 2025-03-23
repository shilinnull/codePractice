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


// 特化
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
			cout << "3存在" << endl;
		}
		else
		{
			cout << "3不存在" << endl;
		}

		ht.Insert(make_pair(3, 3));
		ht.Insert(make_pair(23, 3));
		ht.Print();
	}

	void TestHT2()
	{
		string arr[] = { "香蕉", "甜瓜","苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉" };
		HashTable<string, int, HashFunc<string>> ht;
		// HashTable<string, int> ht; // 使用特化
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

		// 构造
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
			Hash hf; // 通过仿函数

			if (_tables.size() == 0) // 哈希表大小为0，查找失败
				return nullptr;
			size_t hashi = hf(key) % _tables.size(); // 通过哈希函数计算出对应的哈希桶编号

			// 遍历哈希桶
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
			// 1、查看哈希表中是否存在该键值的键值对
			if (Find(kv))
				return false;

			Hash hf;

			// 2、判断是否需要调整哈希表的大小
			if (_n == _tables.size())// 哈希表的大小为0，或负载因子超过1
			{
				//增容
				//a、创建一个新的哈希表，新哈希表的大小设置为原哈希表的2倍（若哈希表大小为0，则将哈希表的初始大小设置为10）
				vector<Node*> newTables;
				size_t newsize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				newTables.resize(newsize, nullptr);
				// b、将原哈希表当中的结点插入到新哈希表
				for (size_t i = 0; i < _tables.size(); i++)
				{
					if (_tables[i])// 桶不为空
					{
						Node* cur = _tables[i];  //将该桶的结点取完为止
						while (cur)
						{
							Node* next = cur->_next; //记录cur的下一个结点
							size_t index = hf(cur->_kv.first) % newTables.size(); // 通过哈希函数计算出对应的哈希桶编号index							cur->_next = newTables[index];
							newTables[index] = cur; // 将该结点头插到新哈希表中编号为index的哈希桶中

							cur = next; // 取原哈希表中该桶的下一个结点
						}	
						_tables[i] = nullptr; // 该桶取完后将该桶置空
					}
				}

			}

			size_t hashi = hf(kv.first) % _tables.size();
			Node* newnode = new Node(kv);

			// 头插
			newnode->_next = _tables[hashi];
			_tables[hashi] = newnode;

			++_n;
			return true;
		}
		
		bool Earse(const K& key)
		{
			Hash hf;

			//1、通过哈希函数计算出对应的哈希桶编号index（除数不能是capacity）
			size_t hashi = hf(key) % _tables.size();

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

