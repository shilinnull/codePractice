#pragma once
#include<iostream>

using namespace std;


namespace lsl {
	enum Colour
	{
		RED,
		BLACK
	};


	//��������Ķ���
	template<class T>
	struct RBTreeNode
	{
		//������
		RBTreeNode<T>* _left;
		RBTreeNode<T>* _right;
		RBTreeNode<T>* _parent;

		T data;

		//������ɫ
		Colour _col; //��/��

		//���캯��
		RBTreeNode(const T& data)
			:_left(nullptr)
			, _right(nullptr)
			, _parent(nullptr)
			, _col(RED)
		{}
	};


	template<class T, class Ref, class Ptr>
	struct RBTreeIterator
	{
		typedef RBTreeNode<T> Node;
		typedef RBTreeIterator<T, Ref, Ptr> Self;

		RBTreeIterator(Node* pNode)
			: _pNode(pNode)
		{}

		// �õ�������������ָ�����Ϊ
		Ref operator*()
		{
			return _pNode->data;
		}
		Ptr operator->()
		{
			return &_pNode->data;
		}
		// Ȼ�����������ƶ���ǰ��/����++  
		Self& operator++()
		{
			Increament();
			return *this;
		}
		Self operator++(int)
		{
			Self temp(*this);
			Increament();
			return temp;
		}

		// Ȼ�����������ƶ���ǰ��/����-- 
		Self& operator--()
		{
			DeIncreament();
			return *this;
		}
		Self operator--(int)
		{
			Self temp(*this);
			DeIncreament();
			return temp;
		}

		// �õ��������ԱȽ�
		bool operator!=(const Self& s)const
		{
			return s._pNode != _pNode;
		}
		bool operator==(const Self& s)const
		{
			return s._pNode == _pNode;
		}

	private:
		void Increament()
		{
			// 1. itָ��Ľڵ㣬��������Ϊ�գ���һ������������������ڵ�
			if (_pNode->_right)
			{
				// ��������������ڵ�
				Node* left = _pNode->_right;
				while (left->_left)
				{
					left = left->_left;
				}
				_pNode->_left;
			}
			else // 2. itָ��Ľڵ㣬������Ϊ�գ�it�еĽڵ����ڵ������������ˣ������Һ����Ǹ��׵��Ǹ�����
			{
				Node* cur = _pNode;
				Node* parent = cur->_parent;
				while (parent && cur == parent->_right)
				{
					cur = parent;
					parent = parent->_parent;
				}
				_pNode = parent;
			}
			return *this;
		}
		void DeIncreament()
		{
			if (_pNode->_left) //������������Ϊ��
			{
				//Ѱ�Ҹý�����������е����ҽ��
				Node* right = _pNode->_left;
				while (right->_right)
				{
					right = right->_right;
				}
				_pNode = right; //--���Ϊ�ý��
			}
			else //����������Ϊ��
			{
				//Ѱ�Һ��Ӳ��ڸ����������
				Node* cur = _pNode;
				Node* parent = cur->_parent;
				while (parent && cur == parent->_left)
				{
					cur = parent;
					parent = parent->_parent;
				}
				_pNode = parent; //--���Ϊ�ý��
			}
			return *this;
		}
		Node* _pNode;
	};


	// T: �����Ǽ�ֵ��<key,value>
	//    ������һ��key
	// ���۽ڵ��д洢����<key, value> || key, ���ǰ���key�����бȽϵ�
	// KeyOfValue: ��ȡdata�е�Key
	template<class K, class T, class KeyOfT>
	class RBTree
	{
		typedef RBTreeNode<T> Node;
	public:
		typedef RBTreeIterator<T, T&, T*> iterator;
	public:
		RBTree()
			: _size(0)
		{
			_pHead = new Node;
			_pHead->_left = _pHead;
			_pHead->_right = _pHead;
		}

		// ����ֵΪdata�Ľڵ�
		// ����ֵ���壺iterator�����²���ڵ�   bool�������Ƿ����ɹ�
		pair<iterator, bool> Insert(const T& data)
		{
			if (_pHead == nullptr) //�������Ϊ�������������ֱ����Ϊ�����
			{
				_pHead = new Node(data);
				_pHead->_col = BLACK; //���������Ǻ�ɫ
				++_size; // ++��Ч�ڵ�
				return make_pair(_pHead, true); //����ɹ�
			}
			//1���������������Ĳ��뷽�����ҵ�������λ��
			KeyOfT kot;
			Node* cur = _pHead;
			Node* parent = nullptr;
			while (cur)
			{
				if (kot(data) < kot(cur->_data))
				{
					//���ý�����������
					parent = cur;
					cur = cur->_left;
				}
				else if (kot(data) > kot(cur->_data))
				{
					//���ý�����������
					parent = cur;
					cur = cur->_right;
				}
				else //���������keyֵ���ڵ�ǰ����keyֵ
				{
					return make_pair(cur, false); //����ʧ��
				}
			}

			//2��������������뵽����
			cur = new Node(data); //��������ֵ����һ�����
			Node* newnode = cur; //��¼�²���Ľ�㣨���ں��򷵻أ�
			if (kot(data) < kot(parent->_data)) //�½���keyֵС��parent��keyֵ
			{
				//���뵽parent�����
				parent->_left = cur;
				cur->_parent = parent;
			}
			else //�½���keyֵ����parent��keyֵ
			{
				//���뵽parent���ұ�
				parent->_right = cur;
				cur->_parent = parent;
			}

			//3����������ĸ�����Ǻ�ɫ�ģ�����Ҫ�Ժ�������е���������Ǻ�ɫ���õ���
			while (parent && parent->_col == RED)
			{
				Node* grandfather = parent->_parent; //parent�Ǻ�ɫ�����丸���һ������
				if (parent == grandfather->_left) //parent��grandfather������
				{
					Node* uncle = grandfather->_right; //uncle��grandfather���Һ���
					if (uncle && uncle->_col == RED) //���1��uncle������Ϊ��
					{
						//��ɫ����
						parent->_col = uncle->_col = BLACK;
						grandfather->_col = RED;

						//�������ϴ���
						cur = grandfather;
						parent = cur->_parent;
					}
					else //���2+���3��uncle������ + uncle������Ϊ��
					{
						if (cur == parent->_left)
						{
							RotateR(grandfather); //�ҵ���

							//��ɫ����
							grandfather->_col = RED;
							parent->_col = BLACK;
						}
						else //cur == parent->_right
						{

							RotateLR(grandfather); //����˫��
							//��ɫ����
							grandfather->_col = RED;
							cur->_col = BLACK;
						}
						break; //������ת�󣬸������ĸ�����˺�ɫ������������Ͻ��д���
					}
				}
				else //parent��grandfather���Һ���
				{
					Node* uncle = grandfather->_left; //uncle��grandfather������
					if (uncle && uncle->_col == RED) //���1��uncle������Ϊ��
					{
						//��ɫ����
						uncle->_col = parent->_col = BLACK;
						grandfather->_col = RED;

						//�������ϴ���
						cur = grandfather;
						parent = cur->_parent;
					}
					else //���2+���3��uncle������ + uncle������Ϊ��
					{
						if (cur == parent->_left)
						{
							RotateRL(grandfather); //����˫��

							//��ɫ����
							cur->_col = BLACK;
							grandfather->_col = RED;
						}
						else //cur == parent->_right
						{
							RotateL(grandfather); //����

							//��ɫ����
							grandfather->_col = RED;
							parent->_col = BLACK;
						}
						break; //������ת�󣬸������ĸ�����˺�ɫ������������Ͻ��д���
					}
				}
			}
			_pHead->_col = BLACK; //��������ɫΪ��ɫ�����ܱ����һ����˺�ɫ����Ҫ��غ�ɫ��
			++_size; // ++��Ч�ڵ�
			return make_pair(newnode, true); //����ɹ�
		}

		// Begin��End������
		iterator Begin()
		{
			Node* left = _pHead;
			while (left)
			{
				left = left->_left;
			}
			return iterator(left);
		}
		iterator End()
		{
			return iterator(nullptr);
		}

		// ������Ƿ�Ϊ�գ��Ƿ���true�����򷵻�false
		bool Empty()const
		{
			return _pHead == nullptr;
		}
		// ���غ��������Ч�ڵ�ĸ���
		size_t Size() const
		{
			return _size;
		}
		// ��������е���Ч�ڵ�ɾ����ע�⣺ɾ��������Ч�ڵ㣬��ɾ��ͷ���
		void Clear()
		{
			_Destroy();
		}
		// �ں�����в���data�����ڸϻظýڵ��Ӧ�ĵ����������򷵻�End()
		iterator Find(const T& data)
		{
			KeyOfT kot;
			Node* cur = _pHead;
			while (cur)
			{
				if (data < kot(cur->data))
				{
					cur = cur->_left;
				}
				else if (data > kot(cur->data))
				{
					cur = cur->_right;
				}
				else
				{
					return iterator(nullptr);
				}
			}
			// ����ʧ��
			return End();
		}


		// �������
		void InOrder()
		{
			_InOrder(_pHead);
			cout << endl;
		}

		// ����Ƿ�Ϊ�����
		bool IsBalance()
		{
			if (_pHead == nullptr)
				return true;

			if (_pHead->_col == RED)
				return false;

			//�ο�ֵ
			int refVal = 0;
			Node* cur = _pHead;
			while (cur)
			{
				if (cur->_col == BLACK)
				{
					++refVal;
				}

				cur = cur->_left;
			}

			int blacknum = 0;
			return Check(_pHead, blacknum, refVal);
		}

	private:
		Node* _LeftMost()
		{
			Node* left = _pHead;
			while (left)
			{
				left = left->_left;
			}
			return left;
		}
		Node* _RightMost()
		{
			Node* right = _pHead;
			while (right)
			{
				right = right->_left;
			}
			return right;
		}
		void _Destroy(Node*& pRoot)
		{
			if (pRoot == nullptr)
				return;
			_Destroy(pRoot->_left);
			_Destroy(pRoot->_right);
			delete pRoot;
		}
		void RotateL(Node* parent)
		{
			Node* subR = parent->_right;
			Node* subRL = subR->_left;
			Node* parentParent = parent->_parent;

			//����subRL��parent֮�����ϵ
			parent->_right = subRL;
			if (subRL)
				subRL->_parent = parent;

			//����parent��subR֮�����ϵ
			subR->_left = parent;
			parent->_parent = subR;

			//����subR��parentParent֮�����ϵ
			if (parentParent == nullptr)
			{
				_pHead = subR;
				_pHead->_parent = nullptr;
			}
			else
			{
				if (parent == parentParent->_left)
				{
					parentParent->_left = subR;
				}
				else
				{
					parentParent->_right = subR;
				}
				subR->_parent = parentParent;
			}

		}
		void RotateR(Node* parent)
		{
			Node* subL = parent->_left;
			Node* subLR = subL->_right;
			Node* parentParent = parent->_parent;

			//����subLR��parent֮�����ϵ
			parent->_left = subLR;
			if (subLR)
				subLR->_parent = parent;

			//����parent��subL֮�����ϵ
			subL->_right = parent;
			parent->_parent = subL;

			//����subL��parentParent֮�����ϵ
			if (parentParent == nullptr)
			{
				_pHead = subL;
				_pHead->_parent = nullptr;
			}
			else
			{
				if (parent == parentParent->_left)
				{
					parentParent->_left = subL;
				}
				else
				{
					parentParent->_right = subL;
				}
				subL->_parent = parentParent;
			}
		}

		//����˫��
		void RotateLR(Node* parent)
		{
			RotateL(parent->_left);
			RotateR(parent);
		}

		//����˫��
		void RotateRL(Node* parent)
		{
			RotateR(parent->_right);
			RotateL(parent);
		}

		public:

		// ���ڵ�->��ǰ�ڵ�����·���ĺ�ɫ�ڵ������
		bool Check(Node* root, int blacknum, const int refVal)
		{
			if (root == nullptr)
			{
				//cout << balcknum << endl;
				if (blacknum != refVal)
				{
					cout << "���ں�ɫ�ڵ���������ȵ�·��" << endl;
					return false;
				}

				return true;
			}

			if (root->_col == RED && root->_parent->_col == RED)
			{
				cout << "�������ĺ�ɫ�ڵ�" << endl;

				return false;
			}

			if (root->_col == BLACK)
			{
				++blacknum;
			}

			return Check(root->_left, blacknum, refVal)
				&& Check(root->_right, blacknum, refVal);
		}

		// �������
		void _InOrder(Node* root)
		{
			if (root == nullptr)
				return;

			_InOrder(root->_left);
			cout << root->_kv.first << " ";
			_InOrder(root->_right);
		}
	private:
		Node* _pHead;
		size_t _size;
	};
}