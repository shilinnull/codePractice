#pragma once

#include "RBTree.h"
namespace lsl //防止命名冲突
{
    template<class K>
    class set
    {
    public:
        //仿函数
        struct SetKeyOfT
        {
            const K& operator()(const K& key) //返回键值Key
            {
                return key;
            }
        };
        // 对类模板取内嵌类型，加typename告诉编译器这里是类型
        typedef typename RBTree<K, const K, SetKeyOfT>::const_iterator iterator;
        typedef typename RBTree<K, const K, SetKeyOfT>::const_iterator const_iterator;//const迭代器

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

        //插入函数
        pair<iterator, bool> insert(const K& key)
        {
            return _t.Insert(key);
        }
        //查找函数
        iterator find(const K& key)
        {
            return _t.Find(key);
        }
    private:
        RBTree<K, const K, SetKeyOfT> _t;
    };
}