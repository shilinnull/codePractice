#pragma once
#include <vector>
#include <iostream>

// ״̬
enum Status
{
    EMPTY, // ��
    EXIST, // ����
    DELETE // ɾ��
};

//��ϣ��ÿ��λ�ô洢�Ľṹ
template <class K, class V>
struct HashData
{
    std::pair<K, V> _kv;
    Status _state = EMPTY;
};


template <class K, class V>
class HashTable
{
public:
    HashTable()
        :_tables(11)
        ,_n(0)
    {}
    
    bool Insert(const std::pair<K, V>& kv)
    {
        if (_n / _tables.size() >= 0.7)
        {
            // ����
        }

        size_t hash0 = kv.first % _tables.size();
        size_t hashi = hash0;
        size_t i = 1;
        // ����̽��
        while (_tables[hashi]._state == EXIST)
        {
            hashi = (hash0 + i) % _tables.size();
            i++;
        }
        _tables[hashi]._kv = kv;
        _tables[hashi]._state = EXIST;
        ++_n;
        return true;
    }

    HashData<K, V>* Find(const K& key)
    {
        size_t hash0 = key % _tables.size();
        size_t hashi = hash0;
        size_t i = 1;
        // ����̽��
        while (_tables[hashi]._state != EMPTY)
        {
            // �����Ȳ���״̬��Ϊɾ��
            if (_tables[hashi]._kv.first == key && _tables[hashi]._state != DELETE)
                return &_tables[hashi];
            // ����������
            hashi = (hash0 + i) % _tables.size();
            i++;
        }
        return nullptr;
    }

    bool Erase(const K& key)
    {
        HashData<K, V>* ret = Find(key);
        if (ret) // ������ھ�αɾ��
        {
            ret->_state = DELETE;
            return true;
        }
        else
        {
            return false;
        }
    }


private:
    std::vector<HashData<K, V>> _tables;
    size_t _n = 0;
};






