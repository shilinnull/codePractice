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

namespace open_address
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
        std::pair<K, V> _kv; // ��ֵ��
        Status _state; // ״̬
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
        HashFun hf; // ����int��˵��ֱ����ֵ���Ƚϣ�����string����ʹ��BKDR�������Ƚ�
    public:
        HashTable(size_t size = __stl_next_prime(0))
            :_tables(size)
            , _n(0)
        {}

        // ���뷽��
        bool Insert(const std::pair<K, V>& kv)
        {
            // 1���鿴��ϣ�����Ƿ���ڸü�ֵ�ļ�ֵ��
            if (Find(kv.first))// ��ϣ�����Ѿ����ڸü�ֵ�ļ�ֵ�ԣ��������������ࣩ
                return false;

            //2���ж��Ƿ���Ҫ������ϣ��Ĵ�С
            if ((double)_n / (double)_tables.size() >= 0.7)// �������Ӵ���0.7��Ҫ����)
            {
                //a������һ���µĹ�ϣ���¹�ϣ��Ĵ�С����Ϊ����2��������
                HashTable<K, V, HashFun> newHT(__stl_next_prime(_tables.size() + 1));

                //b�������ɱ�,��ԭ��ϣ���е����ݲ��뵽�¹�ϣ��
                for (size_t i = 0; i < _tables.size(); i++)
                {
                    // ���_tables[i]��λ�������ݾͽ����ٴ�ӳ��
                    if (_tables[i]._state == EXIST) 
                    {
                        newHT.Insert(_tables[i]._kv);
                    }
                }
                // c����ɱ���н���
                _tables.swap(newHT._tables);
            }// ���� end...


            // 3������ֵ�Բ����ϣ��
            // a��ͨ����ϣ���������ϣ��ַ������̽��
            size_t hashi = hf(kv.first) % _tables.size(); // ����������capacity

            size_t index = hashi, i = 1;

            //b���ҵ�һ��״̬ΪEMPTY��DELETE��λ��
            while (_tables[hashi]._state == EXIST)
            {
                hashi = (index + i) % _tables.size();
                ++i;
            }

            //c�������ݲ����λ�ã�������λ�õ�״̬����ΪEXIST
            _tables[hashi]._kv = kv;
            _tables[hashi]._state = EXIST;

            //4����ϣ���е���ЧԪ�ظ���++
            ++_n;
            return true;
        }

        // ���ҷ���
        HashData<K, V>* Find(const K& key)
        {
            if (_tables.size() == 0)
                return nullptr;

            // ����λ��
            size_t hashi = hf(key) % _tables.size();
            size_t index = hashi, i = 1;

            // ��Ϊ�վ�һֱ��
            while (_tables[hashi]._state != EMPTY)
            {
                // ��keyƥ�䣬���Ҳ�����DELETE�����ҳɹ�
                if (_tables[hashi]._kv.first == key && _tables[hashi]._state != DELETE)
                    return &_tables[hashi];
                
                // ����̽��
                hashi = (index + i) % _tables.size();
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
                res->_state = DELETE;
                --_n; //3����ϣ���е���ЧԪ�ظ�����һ
                return true; // ɾ���ɹ�
            }
            return false;    // ɾ��ʧ��
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

        // ����
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
            // 1���鿴��ϣ�����Ƿ���ڸü�ֵ�ļ�ֵ��
            if (Find(kv.first))
                return false;

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
                        size_t hashi = hs(cur->_kv.first) % newTables.size(); // ͨ����ϣ�����������Ӧ�Ĺ�ϣͰ���index

                        cur->_next = newTables[hashi]; // �ڵ�ֱ���������ŵ���Ͱ��
                        newTables[hashi] = cur; // ���ý��ͷ�嵽�¹�ϣ���б��Ϊindex�Ĺ�ϣͰ��
                        cur = next; // ȡԭ��ϣ���и�Ͱ����һ�����
                    }
                    _tables[i] = nullptr;  // ��Ͱȡ��󽫸�Ͱ�ÿ�
                }
                _tables.swap(newTables);
            } // ����end...

            size_t hashi = hs(kv.first) % _tables.size();
            Node* newnode = new Node(kv);
            // ����ͷ��
            newnode->_next = _tables[hashi];
            _tables[hashi] = newnode;

            ++_n;
            return true;
        }


        Node* Find(const K& key)
        {
            if (_tables.size() == 0) // ��ϣ���СΪ0������ʧ��
                return nullptr;
            // ͨ����ϣ�����������Ӧ�Ĺ�ϣͰ���
            size_t hashi = hs(key) % _tables.size();
            Node* cur = _tables[hashi];
            // ������ϣͰ
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
            //1��ͨ����ϣ�����������Ӧ�Ĺ�ϣͰ���index������������capacity��
            size_t hashi = hs(key) % _tables.size();

            //2���ڱ��Ϊindex�Ĺ�ϣͰ��Ѱ�Ҵ�ɾ�����
            Node* cur = _tables[hashi];
            Node* prev = nullptr;
            while (cur)
            {
                //3�����ҵ��˴�ɾ����㣬��ɾ���ý��
                if (cur->_kv.first == key)
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


