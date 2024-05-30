#pragma once
#include<iostream>

using namespace std;


namespace lsl {
	enum Colour
	{
		RED,
		BLACK
	};


	//红黑树结点的定义
	template<class T>
	struct RBTreeNode
	{
		//三叉链
		RBTreeNode<T>* _left;
		RBTreeNode<T>* _right;
		RBTreeNode<T>* _parent;

		T data;

		//结点的颜色
		Colour _col; //红/黑

		//构造函数
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

		// 让迭代器具有类似指针的行为
		Ref operator*()
		{
			return _pNode->data;
		}
		Ptr operator->()
		{
			return &_pNode->data;
		}
		// 然迭代器可以移动：前置/后置++  
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

		// 然迭代器可以移动：前置/后置-- 
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

		// 让迭代器可以比较
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
			// 1. it指向的节点，右子树不为空，下一个就是右子树的最左节点
			if (_pNode->_right)
			{
				// 找右子树的最左节点
				Node* left = _pNode->_right;
				while (left->_left)
				{
					left = left->_left;
				}
				_pNode->_left;
			}
			else // 2. it指向的节点，右子树为空，it中的节点所在的子树访问完了，往上找孩子是父亲的那个祖先
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
			if (_pNode->_left) //结点的左子树不为空
			{
				//寻找该结点左子树当中的最右结点
				Node* right = _pNode->_left;
				while (right->_right)
				{
					right = right->_right;
				}
				_pNode = right; //--后变为该结点
			}
			else //结点的左子树为空
			{
				//寻找孩子不在父亲左的祖先
				Node* cur = _pNode;
				Node* parent = cur->_parent;
				while (parent && cur == parent->_left)
				{
					cur = parent;
					parent = parent->_parent;
				}
				_pNode = parent; //--后变为该结点
			}
			return *this;
		}
		Node* _pNode;
	};


	// T: 可能是键值对<key,value>
	//    可能是一个key
	// 不论节点中存储的是<key, value> || key, 都是按照key来进行比较的
	// KeyOfValue: 提取data中的Key
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

		// 插入值为data的节点
		// 返回值含义：iterator代表新插入节点   bool：代表是否插入成功
		pair<iterator, bool> Insert(const T& data)
		{
			if (_pHead == nullptr) //若红黑树为空树，则插入结点直接作为根结点
			{
				_pHead = new Node(data);
				_pHead->_col = BLACK; //根结点必须是黑色
				++_size; // ++有效节点
				return make_pair(_pHead, true); //插入成功
			}
			//1、按二叉搜索树的插入方法，找到待插入位置
			KeyOfT kot;
			Node* cur = _pHead;
			Node* parent = nullptr;
			while (cur)
			{
				if (kot(data) < kot(cur->_data))
				{
					//往该结点的左子树走
					parent = cur;
					cur = cur->_left;
				}
				else if (kot(data) > kot(cur->_data))
				{
					//往该结点的右子树走
					parent = cur;
					cur = cur->_right;
				}
				else //待插入结点的key值等于当前结点的key值
				{
					return make_pair(cur, false); //插入失败
				}
			}

			//2、将待插入结点插入到树中
			cur = new Node(data); //根据所给值构造一个结点
			Node* newnode = cur; //记录新插入的结点（便于后序返回）
			if (kot(data) < kot(parent->_data)) //新结点的key值小于parent的key值
			{
				//插入到parent的左边
				parent->_left = cur;
				cur->_parent = parent;
			}
			else //新结点的key值大于parent的key值
			{
				//插入到parent的右边
				parent->_right = cur;
				cur->_parent = parent;
			}

			//3、若插入结点的父结点是红色的，则需要对红黑树进行调整，如果是黑色则不用调整
			while (parent && parent->_col == RED)
			{
				Node* grandfather = parent->_parent; //parent是红色，则其父结点一定存在
				if (parent == grandfather->_left) //parent是grandfather的左孩子
				{
					Node* uncle = grandfather->_right; //uncle是grandfather的右孩子
					if (uncle && uncle->_col == RED) //情况1：uncle存在且为红
					{
						//颜色调整
						parent->_col = uncle->_col = BLACK;
						grandfather->_col = RED;

						//继续往上处理
						cur = grandfather;
						parent = cur->_parent;
					}
					else //情况2+情况3：uncle不存在 + uncle存在且为黑
					{
						if (cur == parent->_left)
						{
							RotateR(grandfather); //右单旋

							//颜色调整
							grandfather->_col = RED;
							parent->_col = BLACK;
						}
						else //cur == parent->_right
						{

							RotateLR(grandfather); //左右双旋
							//颜色调整
							grandfather->_col = RED;
							cur->_col = BLACK;
						}
						break; //子树旋转后，该子树的根变成了黑色，无需继续往上进行处理
					}
				}
				else //parent是grandfather的右孩子
				{
					Node* uncle = grandfather->_left; //uncle是grandfather的左孩子
					if (uncle && uncle->_col == RED) //情况1：uncle存在且为红
					{
						//颜色调整
						uncle->_col = parent->_col = BLACK;
						grandfather->_col = RED;

						//继续往上处理
						cur = grandfather;
						parent = cur->_parent;
					}
					else //情况2+情况3：uncle不存在 + uncle存在且为黑
					{
						if (cur == parent->_left)
						{
							RotateRL(grandfather); //右左双旋

							//颜色调整
							cur->_col = BLACK;
							grandfather->_col = RED;
						}
						else //cur == parent->_right
						{
							RotateL(grandfather); //左单旋

							//颜色调整
							grandfather->_col = RED;
							parent->_col = BLACK;
						}
						break; //子树旋转后，该子树的根变成了黑色，无需继续往上进行处理
					}
				}
			}
			_pHead->_col = BLACK; //根结点的颜色为黑色（可能被情况一变成了红色，需要变回黑色）
			++_size; // ++有效节点
			return make_pair(newnode, true); //插入成功
		}

		// Begin和End迭代器
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

		// 红黑树是否为空，是返回true，否则返回false
		bool Empty()const
		{
			return _pHead == nullptr;
		}
		// 返回红黑树中有效节点的个数
		size_t Size() const
		{
			return _size;
		}
		// 将红黑树中的有效节点删除，注意：删除的是有效节点，不删除头结点
		void Clear()
		{
			_Destroy();
		}
		// 在红黑树中查找data，存在赶回该节点对应的迭代器，否则返回End()
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
			// 查找失败
			return End();
		}


		// 中序遍历
		void InOrder()
		{
			_InOrder(_pHead);
			cout << endl;
		}

		// 检查是否为红黑树
		bool IsBalance()
		{
			if (_pHead == nullptr)
				return true;

			if (_pHead->_col == RED)
				return false;

			//参考值
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

			//建立subRL与parent之间的联系
			parent->_right = subRL;
			if (subRL)
				subRL->_parent = parent;

			//建立parent与subR之间的联系
			subR->_left = parent;
			parent->_parent = subR;

			//建立subR与parentParent之间的联系
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

			//建立subLR与parent之间的联系
			parent->_left = subLR;
			if (subLR)
				subLR->_parent = parent;

			//建立parent与subL之间的联系
			subL->_right = parent;
			parent->_parent = subL;

			//建立subL与parentParent之间的联系
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

		//左右双旋
		void RotateLR(Node* parent)
		{
			RotateL(parent->_left);
			RotateR(parent);
		}

		//右左双旋
		void RotateRL(Node* parent)
		{
			RotateR(parent->_right);
			RotateL(parent);
		}

		public:

		// 根节点->当前节点这条路径的黑色节点的数量
		bool Check(Node* root, int blacknum, const int refVal)
		{
			if (root == nullptr)
			{
				//cout << balcknum << endl;
				if (blacknum != refVal)
				{
					cout << "存在黑色节点数量不相等的路径" << endl;
					return false;
				}

				return true;
			}

			if (root->_col == RED && root->_parent->_col == RED)
			{
				cout << "有连续的红色节点" << endl;

				return false;
			}

			if (root->_col == BLACK)
			{
				++blacknum;
			}

			return Check(root->_left, blacknum, refVal)
				&& Check(root->_right, blacknum, refVal);
		}

		// 中序遍历
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