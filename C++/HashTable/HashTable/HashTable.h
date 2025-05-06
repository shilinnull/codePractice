#pragma once
#include <vector>
#include <iostream>

static const int __stl_num_primes = 28;
static const unsigned long __stl_prime_list[__stl_num_primes] =
{
    53,         97,         193,       389,       769,
    1543,       3079,       6151,      12289,     24593,
    49157,      98317,      196613,    393241,    786433,
    1572869,    3145739,    6291469,   12582917,  25165843,
    50331653,   100663319,  201326611, 402653189, 805306457,
    1610612741, 3221225473, 4294967291
};

inline unsigned long __stl_next_prime(unsigned long n)
{
    const unsigned long* first = __stl_prime_list;
    const unsigned long* last = __stl_prime_list + __stl_num_primes;
    const unsigned long* pos = std::lower_bound(first, last, n);
    return pos == last ? *(last - 1) : *pos;
}


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
struct HashFunc<std::string>
{
    size_t operator()(const std::string& key)
    {
        size_t hashi = 0;
        for (auto& e : key)
        {
            hashi *= 131;
            hashi += e;
        }
        return hashi;
    }
};

namespace open_address
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
        std::pair<K, V> _kv; // 键值对
        Status _state; // 状态
    };

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
    struct HashFunc<std::string>
    {
        size_t operator()(const std::string& key)
        {
            size_t hash = 0;
            for (auto& e : key)
            {
                hash *= 131; // BKDR
                hash += e;
            }
            return hash;
        }
    };

    template <class K, class V, class HashFun = HashFunc<K>>
    class HashTable
    {
        HashFun hf; // 对于int来说是直接用值来比较，对于string类型使用BKDR方法来比较
    public:
        HashTable(size_t size = __stl_next_prime(0))
            :_tables(size)
            , _n(0)
        {}

        // 插入方法
        bool Insert(const std::pair<K, V>& kv)
        {
            // 1、查看哈希表中是否存在该键值的键值对
            if (Find(kv.first))// 哈希表中已经存在该键值的键值对（不允许数据冗余）
                return false;

            //2、判断是否需要调整哈希表的大小
            if ((double)_n / (double)_tables.size() >= 0.7)// 负载因子大于0.7需要增容)
            {
                //a、创建一个新的哈希表，新哈希表的大小设置为近似2倍的质数
                HashTable<K, V, HashFun> newHT(__stl_next_prime(_tables.size() + 1));

                //b、遍历旧表,将原哈希表当中的数据插入到新哈希表
                for (size_t i = 0; i < _tables.size(); i++)
                {
                    // 如果_tables[i]的位置有数据就进行再次映射
                    if (_tables[i]._state == EXIST) 
                    {
                        newHT.Insert(_tables[i]._kv);
                    }
                }
                // c、与旧表进行交换
                _tables.swap(newHT._tables);
            }// 扩容 end...


            // 3、将键值对插入哈希表
            // a、通过哈希函数计算哈希地址，线性探测
            size_t hashi = hf(kv.first) % _tables.size(); // 除数不能是capacity

            size_t index = hashi, i = 1;

            //b、找到一个状态为EMPTY或DELETE的位置
            while (_tables[hashi]._state == EXIST)
            {
                hashi = (index + i) % _tables.size();
                ++i;
            }

            //c、将数据插入该位置，并将该位置的状态设置为EXIST
            _tables[hashi]._kv = kv;
            _tables[hashi]._state = EXIST;

            //4、哈希表中的有效元素个数++
            ++_n;
            return true;
        }

        // 查找方法
        HashData<K, V>* Find(const K& key)
        {
            if (_tables.size() == 0)
                return nullptr;

            // 计算位置
            size_t hashi = hf(key) % _tables.size();
            size_t index = hashi, i = 1;

            // 不为空就一直找
            while (_tables[hashi]._state != EMPTY)
            {
                // 若key匹配，并且不等于DELETE，查找成功
                if (_tables[hashi]._kv.first == key && _tables[hashi]._state != DELETE)
                    return &_tables[hashi];
                
                // 继续探测
                hashi = (index + i) % _tables.size();
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
                res->_state = DELETE;
                --_n; //3、哈希表中的有效元素个数减一
                return true; // 删除成功
            }
            return false;    // 删除失败
        }

    private:
        std::vector<HashData<K, V>> _tables;
        size_t _n = 0;
    };
}

namespace hash_bucket
{
    template<class K, class V>
    struct HashNode
    {
        std::pair<K, V> _kv;
        HashNode<K, V>* _next;

        // 构造
        HashNode(const std::pair<K, V>& kv)
            :_kv(kv)
            ,_next(nullptr)
        {}
    };

    template<class K, class V, class Hash = HashFunc<K>>
    class HashTable
    {
        Hash hs;
        typedef HashNode<K, V> Node;
    public:
        HashTable(size_t size = __stl_next_prime(0))
            : _tables(size, nullptr)
            , _n(0)
        {}

        ~HashTable()
        {
            for (size_t i = 0; i < _tables.size(); i++)
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

        bool Insert(const std::pair<K, V>& kv)
        {
            // 1、查看哈希表中是否存在该键值的键值对
            if (Find(kv.first))
                return false;

            // 2、判断是否需要调整哈希表的大小
            if (_n == _tables.size())
            {
                // a. 建立新表
                std::vector<Node*> newTables(__stl_next_prime(_tables.size() + 1));
                
                // b、将原哈希表当中的结点插入到新哈希表
                for (size_t i = 0; i < _tables.size(); i++)
                {
                    Node* cur = _tables[i];
                    while (cur)
                    {
                        // 旧表的节点挪动下来插入到映射的新表位置
                        Node* next = cur->_next;   //记录cur的下一个结点
                        size_t hashi = hs(cur->_kv.first) % newTables.size(); // 通过哈希函数计算出对应的哈希桶编号index

                        cur->_next = newTables[hashi]; // 节点直接拿下来放到新桶中
                        newTables[hashi] = cur; // 将该结点头插到新哈希表中编号为index的哈希桶中
                        cur = next; // 取原哈希表中该桶的下一个结点
                    }
                    _tables[i] = nullptr;  // 该桶取完后将该桶置空
                }
                _tables.swap(newTables);
            } // 扩容end...

            size_t hashi = hs(kv.first) % _tables.size();
            Node* newnode = new Node(kv);
            // 进行头插
            newnode->_next = _tables[hashi];
            _tables[hashi] = newnode;

            ++_n;
            return true;
        }


        Node* Find(const K& key)
        {
            if (_tables.size() == 0) // 哈希表大小为0，查找失败
                return nullptr;
            // 通过哈希函数计算出对应的哈希桶编号
            size_t hashi = hs(key) % _tables.size();
            Node* cur = _tables[hashi];
            // 遍历哈希桶
            while (cur)
            {
                if (cur->_kv.first == key)
                    return cur;
                cur = cur->_next;
            }
            return nullptr;
        }

        bool Erase(const K& key)
        {
            //1、通过哈希函数计算出对应的哈希桶编号index（除数不能是capacity）
            size_t hashi = hs(key) % _tables.size();

            //2、在编号为index的哈希桶中寻找待删除结点
            Node* cur = _tables[hashi];
            Node* prev = nullptr;
            while (cur)
            {
                //3、若找到了待删除结点，则删除该结点
                if (cur->_kv.first == key)
                {
                    //待删除结点是哈希桶中的第一个结点
                    if (prev == nullptr)
                        _tables[hashi] = cur->_next;// 将第一个结点从该哈希桶中移除
                    else// 待删除结点不是哈希桶的第一个结点
                        prev->_next = cur->_next; // 前一个节点的next指向cur的next
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
        std::vector<Node*> _tables;
        size_t _n;
    };
}


