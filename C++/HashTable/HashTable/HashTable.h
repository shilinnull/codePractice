#pragma once
#include <vector>
#include <iostream>

// 状态
enum Status
{
    EMPTY, // 空
    EXIST, // 存在
    DELETE // 删除
};

//哈希表每个位置存储的结构
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
            // 扩容
        }

        size_t hash0 = kv.first % _tables.size();
        size_t hashi = hash0;
        size_t i = 1;
        // 线性探测
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
        // 线性探测
        while (_tables[hashi]._state != EMPTY)
        {
            // 如果相等并且状态不为删除
            if (_tables[hashi]._kv.first == key && _tables[hashi]._state != DELETE)
                return &_tables[hashi];
            // 继续往后找
            hashi = (hash0 + i) % _tables.size();
            i++;
        }
        return nullptr;
    }

    bool Erase(const K& key)
    {
        HashData<K, V>* ret = Find(key);
        if (ret) // 如果存在就伪删除
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






