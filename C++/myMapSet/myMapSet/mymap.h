#pragma once
#include"RBTree.h"

namespace lsl //��ֹ������ͻ
{
    template<class K, class V>
    class map
    {
    public:
        //�º���
        struct MapKeyOfT
        {
            const K& operator()(const pair<K, V>& kv) //���ؼ�ֵ�Ե��еļ�ֵKey
            {
                return kv.first;
            }
        };
        // ����ģ��ȡ��Ƕ���ͣ���typename���߱���������������
        typedef typename RBTree<K, pair<const K, V>, MapKeyOfT>::iterator iterator;
        typedef typename RBTree<K, pair<const K, V>, MapKeyOfT>::const_iterator const_iterator; // const������

        iterator begin()
        {
            return _t.begin();
        }
        iterator end()
        {
            return _t.end();
        } 

        const_iterator begin() const
        {
            return _t.begin();
        }
        const_iterator end() const
        {
            return _t.end();
        }


        //���뺯��
        pair<iterator, bool> insert(const pair<const K, V>& kv)
        {
            return _t.Insert(kv);
        }
        //[]��������غ���
        V& operator[](const K& key)
        {
            pair<iterator, bool> ret = insert(make_pair(key, V()));
            return ret.first->second;
        }
        //���Һ���
        iterator find(const K& key)
        {
            return _t.Find(key);
        }
    private:
        RBTree<K, pair<const K, V>, MapKeyOfT> _t;
    };
}