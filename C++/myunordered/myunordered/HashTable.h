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

// �ػ�
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

        // ����
        HashNode(const T& data)
            :_data(data)
            ,_next(nullptr)
        {}
    };

    // ��Ҫǰ������һ��HashTable
    template<class K, class T, class KeyOfT, class Hash>
    class HashTable;

    template<class K, class T, class Ref, class Ptr, class KeyOfT, class Hash = HashFunc<T>>
    struct __HTIterator
    {

        typedef HashNode<T> Node; //��ϣ��������
        typedef HashTable<K, T, KeyOfT, Hash> HT; // ��ϣ�������
        typedef __HTIterator<K, T, Ref, Ptr, KeyOfT, Hash> Self; //���������������

        Node* _node; //���ָ��
        const HT* _ht; //��ϣ��ĵ�ַ // ��Ҫ��const

        // ����
        __HTIterator(Node* node, const HT* ht) // ע�����
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
                // ��ǰͰ���нڵ㣬�ߵ���һ���ڵ�
                _node = _node->_next;
            }
            else
            {
                // ��ǰͰ�Ѿ������ˣ�����һ��Ͱ��ʼ
                KeyOfT kot;
                Hash hs;
                size_t hashi = hs(kot(_node->_data)) % _ht->_tables.size();
                ++hashi;
                while (hashi < _ht->_tables.size())
                {
                    if (_ht->_tables[hashi]) // ���Ͱ����
                    {
                        // �ҵ���
                        _node = _ht->_tables[hashi];
                        break;
                    }
                    else
                    {
                        // ����������
                        ++hashi;
                    }
                }

                // ������
                if (hashi == _ht->_tables.size())
                    _node = nullptr;
            }
            return *this;
        }
    };


    // �º�������������дȱʡ����������Ҫ����һ���
    template<class K, class T, class KeyOfT, class Hash>
    class HashTable
    {
        KeyOfT kot; // ����ȡֵ
        Hash hs;    // ���ڼ���
        typedef HashNode<T> Node;
        ////////////////////////
        // ��Ҫ������Ԫ����__HTIterator�е�_tables���ܷ��ʣ���������������ȱʡ����
        template<class K, class T, class Ref, class Ptr, class KeyOfT, class Hash>
        friend struct __HTIterator;
        ///////////////////////////
    public:
        typedef __HTIterator<K, T, T&, T*, KeyOfT, Hash> Iterator;
        typedef __HTIterator<K, T, const T&, const T*, KeyOfT, Hash> ConstIterator;
        ////////////////////////////////////////////////////
        // ������
        Iterator Begin()
        {
            // �ҵ�һ����Ϊ�յ�Ͱ����ĵ�һ���ڵ�
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
            // �ҵ�һ����Ϊ�յ�Ͱ����ĵ�һ���ڵ�
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
            // 1���鿴��ϣ�����Ƿ���ڸü�ֵ�ļ�ֵ��
            Iterator it = Find(kot(data));
            if (it != End())
                return { it , false };

            // 2���ж��Ƿ���Ҫ������ϣ��Ĵ�С
            if (_n == _tables.size())
            {
                // a. �����±�
                std::vector<Node*> newTables(__stl_next_prime(_tables.size() + 1));

                // b����ԭ��ϣ���еĽ����뵽�¹�ϣ��
                for (size_t i = 0; i < _tables.size(); i++)
                {
                    Node* cur = _tables[i];
                    while (cur)
                    {
                        // �ɱ�Ľڵ�Ų���������뵽ӳ����±�λ��
                        Node* next = cur->_next;   //��¼cur����һ�����
                        size_t hashi = hs(kot(cur->_data)) % newTables.size(); // ͨ����ϣ�����������Ӧ�Ĺ�ϣͰ���index

                        cur->_next = newTables[hashi]; // �ڵ�ֱ���������ŵ���Ͱ��
                        newTables[hashi] = cur; // ���ý��ͷ�嵽�¹�ϣ���б��Ϊindex�Ĺ�ϣͰ��
                        cur = next; // ȡԭ��ϣ���и�Ͱ����һ�����
                    }
                    _tables[i] = nullptr;  // ��Ͱȡ��󽫸�Ͱ�ÿ�
                }
                _tables.swap(newTables);
            } // ����end...

            size_t hashi = hs(kot(data)) % _tables.size();
            Node* newnode = new Node(data);
            // ����ͷ��
            newnode->_next = _tables[hashi];
            _tables[hashi] = newnode;

            ++_n;
            return { {newnode, this}, true };
        }


        Iterator Find(const K& key)
        {
            if (_tables.size() == 0) // ��ϣ���СΪ0������ʧ��
                return End();
            // ͨ����ϣ�����������Ӧ�Ĺ�ϣͰ���
            size_t hashi = hs(key) % _tables.size();
            Node* cur = _tables[hashi];
            // ������ϣͰ
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
            //1��ͨ����ϣ�����������Ӧ�Ĺ�ϣͰ���index������������capacity��
            size_t hashi = hs(kot(key)) % _tables.size();

            //2���ڱ��Ϊindex�Ĺ�ϣͰ��Ѱ�Ҵ�ɾ�����
            Node* cur = _tables[hashi];
            Node* prev = nullptr;
            while (cur)
            {
                //3�����ҵ��˴�ɾ����㣬��ɾ���ý��
                if (kot(cur->_data) == key)
                {
                    //��ɾ������ǹ�ϣͰ�еĵ�һ�����
                    if (prev == nullptr)
                        _tables[hashi] = cur->_next;// ����һ�����Ӹù�ϣͰ���Ƴ�
                    else// ��ɾ����㲻�ǹ�ϣͰ�ĵ�һ�����
                        prev->_next = cur->_next; // ǰһ���ڵ��nextָ��cur��next
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
        std::vector<Node*> _tables;
        size_t _n;
    };
}
