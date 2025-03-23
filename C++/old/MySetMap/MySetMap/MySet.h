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
		typedef typename RBTree<K, K, SetKeyOfT>::const_iterator iterator;
		typedef typename RBTree<K, K, SetKeyOfT>::const_iterator const_iterator;//const������

		iterator begin() const
		{
			return _t.begin();
		}

		iterator end() const
		{
			return _t.end();
		}

		//���뺯��
		pair<iterator, bool> insert(const K& key)
		{
			return _t.Insert(key);
		}
		//ɾ������
		void erase(const K& key)
		{
			_t.Erase(key);
		}
		//���Һ���
		iterator find(const K& key)
		{
			return _t.Find(key);
		}
	private:
		RBTree<K, K, SetKeyOfT> _t;
	};
}

