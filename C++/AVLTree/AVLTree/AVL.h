#pragma once

#include <iostream>
#include <assert.h>
using namespace std;

template<class K, class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;

	int _bf; // 平衡因子

	std::pair<K, V> _kv;

	AVLTreeNode(const std::pair<K, V>& kv)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0)
		, _kv(kv)
	{}
};

template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	bool Insert(const std::pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}
		
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		// 到这里找到位置了，可以插入
		cur = new Node(kv);
		if (cur->_kv.first < parent->_kv.first)
			parent->_left = cur;
		else
			parent->_right = cur;
		// 更新
		cur->_parent = parent;

		// 更新平衡因子
		while (parent) // 一直更新到空为止
		{
			if (cur == parent->_left)
				parent->_bf--;
			else 
				parent->_bf++;
			// 如果正好平衡就结束
			if (parent->_bf == 0)
				break;
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				// 需要往上继续更新
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				if (parent->_bf == -2 && cur->_bf == -1) // 右单旋
					RotateR(parent);
				else if (parent->_bf == 2 && cur->_bf == 1) // 左单旋
					RotateL(parent);
				else if (parent->_bf == -2 && cur->_bf == 1) // 左右双旋
					RotateLR(parent);
				else if (parent->_bf == 2 && cur->_bf == -1) // 右左双旋
					RotateRL(parent);
				else
					throw "旋转错误！";
					//assert(false);
				break;
			}
			else
			{
				// 出现错误
				throw "平衡因子出现错误！";
			}
		}
		// 完成
		return true;
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	int Size()
	{
		return _Size(_root);
	} 

	int Height()
	{
		return _Height(_root);
	}
	bool IsBalanceTree()
	{
		return _IsBalanceTree(_root);
	}

	//查找函数
	Node* Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (key < cur->_kv.first) //key值小于该结点的值
			{
				cur = cur->_left; //在该结点的左子树当中查找
			}
			else if (key > cur->_kv.first) //key值大于该结点的值
			{
				cur = cur->_right; //在该结点的右子树当中查找
			}
			else //找到了目标结点
			{
				return cur; //返回该结点
			}
		}
		return nullptr; //查找失败
	}

private:
	///////////////////////// 旋转 /////////////////////////
	// 右单旋
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		//1、建立subL和parent之间的关系
		subL->_right = parent;
		parent->_left = subLR;

		//2、建立parent和subLR之间的关系
		if (subLR)
			subLR->_parent = parent;
		Node* parentParent = parent->_parent;
		parent->_parent = subL;

		//3、建立parentParent和subL之间的关系
		if (parentParent == nullptr)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			if (parentParent->_left == parent)
				parentParent->_left = subL;
			else
				parentParent->_right= subL;
			subL->_parent = parentParent;
		}
		//4、更新平衡因子
		subL->_bf = parent->_bf = 0;
	}


	//左单旋
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		// 1、建立subR和parent之间的关系
		parent->_right = subRL;
		subR->_left = parent;

		// 2、建立parent和subRL之间的关系
		if (subRL)
			subRL->_parent = parent;

		Node* parentParent = parent->_parent;
		parent->_parent = subR;

		// 3、建立parentParent和subR之间的关系
		if (parentParent == nullptr)
		{
			//subR的_parent指向需改变
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (parentParent->_left == parent)
				parentParent->_left = subR;
			else
				parentParent->_right = subR;
			subR->_parent = parentParent;
		}
		// 4、更新平衡因子
		subR->_bf = parent->_bf = 0;
	}

	//左右双旋
	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;

		//1、以subL为旋转点进行左单旋
		RotateL(parent->_left);
		//2、以parent为旋转点进行右单旋
		RotateR(parent);

		//3、更新平衡因子
		if (bf == 1)
		{
			subLR->_bf = 0;
			subL->_bf = -1;
			parent->_bf = 0;
		}
		else if (bf == -1)
		{
			subLR->_bf = 0;
			subL->_bf = 0;
			parent->_bf = 1;
		}
		else if (bf == 0)
		{
			subLR->_bf = 0;
			subL->_bf = 0;
			parent->_bf = 0;
		}
		else
		{
			assert(false); //在旋转前树的平衡因子就有问题
		}
	}

	//右左双旋
	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;

		//1、以subR为轴进行右单旋
		RotateR(subR);

		//2、以parent为轴进行左单旋
		RotateL(parent);

		//3、更新平衡因子
		if (bf == 1)
		{
			subRL->_bf = 0;
			parent->_bf = -1;
			subR->_bf = 0;
		}
		else if (bf == -1)
		{
			subRL->_bf = 0;
			parent->_bf = 0;
			subR->_bf = 1;
		}
		else if (bf == 0)
		{
			subRL->_bf = 0;
			parent->_bf = 0;
			subR->_bf = 0;
		}
		else
		{
			assert(false); //在旋转前树的平衡因子就有问题
		}
	}
	///////////////////////// 旋转end //////////////////////
	
	bool _IsBalanceTree(Node* root)
	{
		// 空树也是AVL树
		if (nullptr == root)
			return true;
		// 计算pRoot结点的平衡因子：即pRoot左右子树的高度差
		int leftHeight = _Height(root->_left);
		int rightHeight = _Height(root->_right);
		int diff = rightHeight - leftHeight;
		// 如果计算出的平衡因子与pRoot的平衡因子不相等，或者
		// pRoot平衡因子的绝对值超过1，则一定不是AVL树
		if (abs(diff) >= 2)
		{
			cout << root->_kv.first << "高度差异常" << endl;
			return false;
		}
		if (root->_bf != diff)
		{
			cout << root->_kv.first << "平衡因子异常" << endl;
			return false;
		}
		// pRoot的左和右如果都是AVL树，则该树一定是AVL树
		return _IsBalanceTree(root->_left) && _IsBalanceTree(root->_right);
	}

	int _Size(Node* root)
	{
		return root == nullptr ? 0 : _Size(root->_left) + _Size(root->_right) + 1;
	} 

	int _Height(Node* root)
	{
		if (root == nullptr)
			return 0;
		int leftHeight = _Height(root->_left);
		int rightHeight = _Height(root->_right);

		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;

		_InOrder(root->_left);
		cout << root->_kv.first << " ";
		_InOrder(root->_right);
	}

private:
	Node* _root = nullptr;
};




