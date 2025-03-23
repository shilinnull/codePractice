#pragma once

#include "iterator.h"
namespace lsl
{
	template<class K,class T>
	class map
	{
	public:
		struct MapKetOFt
		{
			const K& operator()(const pair<K, T>& kv)
			{
				return kv.first;
			}
		};

		typedef typename lsl::RBTree<K, pair<const K, T>, MapKetOFt>::iterator iterator;
		typedef typename lsl::RBTree<K, pair<const K, T>, MapKetOFt>::const_iterator const_iterator;

		iterator begin()
		{
			return _t.Begin();
		}
		iterator end()
		{
			return _t.End();
		}
		pair<iterator, bool> insert(const pair<const K, T>& kv)
		{
			return _t.Insert(kv);
		}

		T& operator[](const K& key)
		{
			//1������insert���������ֵ��
			pair<iterator, bool> ret = insert(make_pair(key,T()));
			//2���ó���insert������ȡ���ĵ�����
			iterator it = ret.first;
			//3�����ظõ�����λ��Ԫ�ص�ֵvalue
			return it->second;
		}
		//���Һ���
		iterator find(const K& key)
		{
			return _t.Find(key);
		}
	private:
		RBTree<K, pair<const K, T>, MapKetOFt> _t;
	};
}