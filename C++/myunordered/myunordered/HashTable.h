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

namespace hash_bucket
{
    template<class T>
    struct HashNode
    {
        T _data;
        HashNode<T>* _next;

        // 构造
        HashNode(const T& data)
            :_data(data)
            ,_next(nullptr)
        {}
    };

    // 需要前置声明一下HashTable
    template<class K, class T, class KeyOfT, class Hash>
    class HashTable;

    template<class K, class T, class Ref, class Ptr, class KeyOfT, class Hash = HashFunc<T>>
    struct __HTIterator
    {

        typedef HashNode<T> Node; //哈希结点的类型
        typedef HashTable<K, T, KeyOfT, Hash> HT; // 哈希表的类型
        typedef __HTIterator<K, T, Ref, Ptr, KeyOfT, Hash> Self; //正向迭代器的类型

        Node* _node; //结点指针
        const HT* _ht; //哈希表的地址 // 需要是const

        // 构造
        __HTIterator(Node* node, const HT* ht) // 注意参数
            :_node(node)
            ,_ht(ht)
        {}

        Ref operator*()
        {
            return _node->_data;
        }

        Ptr operator->()
        {
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

        Self& operator++()
        {
            if (_node->_next)
            {
                // 当前桶还有节点，走到下一个节点
                _node = _node->_next;
            }
            else
            {
                // 当前桶已经走完了，找下一个桶开始
                KeyOfT kot;
                Hash hs;
                size_t hashi = hs(kot(_node->_data)) % _ht->_tables.size();
                ++hashi;
                while (hashi < _ht->_tables.size())
                {
                    if (_ht->_tables[hashi]) // 如果桶存在
                    {
                        // 找到了
                        _node = _ht->_tables[hashi];
                        break;
                    }
                    else
                    {
                        // 继续往后找
                        ++hashi;
                    }
                }

                // 走完了
                if (hashi == _ht->_tables.size())
                    _node = nullptr;
            }
            return *this;
        }
    };


    // 仿函数不能在这里写缺省参数，必须要在上一层加
    template<class K, class T, class KeyOfT, class Hash>
    class HashTable
    {
        KeyOfT kot; // 用于取值
        Hash hs;    // 用于计算
        typedef HashNode<T> Node;
        ////////////////////////
        // 须要进行友元声明__HTIterator中的_tables才能访问，并且声明不能有缺省参数
        template<class K, class T, class Ref, class Ptr, class KeyOfT, class Hash>
        friend struct __HTIterator;
        ///////////////////////////
    public:
        typedef __HTIterator<K, T, T&, T*, KeyOfT, Hash> Iterator;
        typedef __HTIterator<K, T, const T&, const T*, KeyOfT, Hash> ConstIterator;
        ////////////////////////////////////////////////////
        // 迭代器
        Iterator Begin()
        {
            // 找第一个不为空的桶里面的第一个节点
            for (size_t i = 0; i < _tables.size(); i++)
            {
                if (_tables[i])
                    return Iterator(_tables[i], this);
            }
            return End();
        }

        Iterator End()
        {
            return Iterator(nullptr, this);
        } 

        ConstIterator Begin() const
        {
            // 找第一个不为空的桶里面的第一个节点
            for (size_t i = 0; i < _tables.size(); i++)
            {
                if (_tables[i])
                    return ConstIterator(_tables[i], this);
            }
            return End();
        }

        ConstIterator End() const 
        {
            return ConstIterator(nullptr, this);
        }

        ////////////////////////////////////////////////////
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

        std::pair<Iterator, bool>Insert(const T& data)
        {
            // 1、查看哈希表中是否存在该键值的键值对
            Iterator it = Find(kot(data));
            if (it != End())
                return { it , false };

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
                        size_t hashi = hs(kot(cur->_data)) % newTables.size(); // 通过哈希函数计算出对应的哈希桶编号index

                        cur->_next = newTables[hashi]; // 节点直接拿下来放到新桶中
                        newTables[hashi] = cur; // 将该结点头插到新哈希表中编号为index的哈希桶中
                        cur = next; // 取原哈希表中该桶的下一个结点
                    }
                    _tables[i] = nullptr;  // 该桶取完后将该桶置空
                }
                _tables.swap(newTables);
            } // 扩容end...

            size_t hashi = hs(kot(data)) % _tables.size();
            Node* newnode = new Node(data);
            // 进行头插
            newnode->_next = _tables[hashi];
            _tables[hashi] = newnode;

            ++_n;
            return { {newnode, this}, true };
        }


        Iterator Find(const K& key)
        {
            if (_tables.size() == 0) // 哈希表大小为0，查找失败
                return End();
            // 通过哈希函数计算出对应的哈希桶编号
            size_t hashi = hs(key) % _tables.size();
            Node* cur = _tables[hashi];
            // 遍历哈希桶
            while (cur)
            {
                if (kot(cur->_data) == key)
                    return Iterator(cur, nullptr);
                cur = cur->_next;
            }
            return End();
        }

        bool Erase(const K& key)
        {
            //1、通过哈希函数计算出对应的哈希桶编号index（除数不能是capacity）
            size_t hashi = hs(kot(key)) % _tables.size();

            //2、在编号为index的哈希桶中寻找待删除结点
            Node* cur = _tables[hashi];
            Node* prev = nullptr;
            while (cur)
            {
                //3、若找到了待删除结点，则删除该结点
                if (kot(cur->_data) == key)
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
