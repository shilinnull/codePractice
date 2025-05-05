#pragma once

#include "RBTree.h"
namespace lsl //��ֹ������ͻ
{
    template<class K>
    class set
    {
    public:
        //�º���
        struct SetKeyOfT
        {
            const K& operator()(const K& key) //���ؼ�ֵKey
            {
                return key;
            }
        };
        // ����ģ��ȡ��Ƕ���ͣ���typename���߱���������������
        typedef typename RBTree<K, const K, SetKeyOfT>::const_iterator iterator;
        typedef typename RBTree<K, const K, SetKeyOfT>::const_iterator const_iterator;//const������

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
        pair<iterator, bool> insert(const K& key)
        {
            return _t.Insert(key);
        }
        //���Һ���
        iterator find(const K& key)
        {
            return _t.Find(key);
        }
    private:
        RBTree<K, const K, SetKeyOfT> _t;
    };
}