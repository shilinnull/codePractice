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

	int _bf; // ƽ������

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

		// �������ҵ�λ���ˣ����Բ���
		cur = new Node(kv);
		if (cur->_kv.first < parent->_kv.first)
			parent->_left = cur;
		else
			parent->_right = cur;
		// ����
		cur->_parent = parent;

		// ����ƽ������
		while (parent) // һֱ���µ���Ϊֹ
		{
			if (cur == parent->_left)
				parent->_bf--;
			else 
				parent->_bf++;
			// �������ƽ��ͽ���
			if (parent->_bf == 0)
				break;
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				// ��Ҫ���ϼ�������
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				if (parent->_bf == -2 && cur->_bf == -1) // �ҵ���
					RotateR(parent);
				else if (parent->_bf == 2 && cur->_bf == 1) // ����
					RotateL(parent);
				else if (parent->_bf == -2 && cur->_bf == 1) // ����˫��
					RotateLR(parent);
				else if (parent->_bf == 2 && cur->_bf == -1) // ����˫��
					RotateRL(parent);
				else
					throw "��ת����";
					//assert(false);
				break;
			}
			else
			{
				// ���ִ���
				throw "ƽ�����ӳ��ִ���";
			}
		}
		// ���
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

	//���Һ���
	Node* Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (key < cur->_kv.first) //keyֵС�ڸý���ֵ
			{
				cur = cur->_left; //�ڸý������������в���
			}
			else if (key > cur->_kv.first) //keyֵ���ڸý���ֵ
			{
				cur = cur->_right; //�ڸý������������в���
			}
			else //�ҵ���Ŀ����
			{
				return cur; //���ظý��
			}
		}
		return nullptr; //����ʧ��
	}

private:
	///////////////////////// ��ת /////////////////////////
	// �ҵ���
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		//1������subL��parent֮��Ĺ�ϵ
		subL->_right = parent;
		parent->_left = subLR;

		//2������parent��subLR֮��Ĺ�ϵ
		if (subLR)
			subLR->_parent = parent;
		Node* parentParent = parent->_parent;
		parent->_parent = subL;

		//3������parentParent��subL֮��Ĺ�ϵ
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
		//4������ƽ������
		subL->_bf = parent->_bf = 0;
	}


	//����
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		// 1������subR��parent֮��Ĺ�ϵ
		parent->_right = subRL;
		subR->_left = parent;

		// 2������parent��subRL֮��Ĺ�ϵ
		if (subRL)
			subRL->_parent = parent;

		Node* parentParent = parent->_parent;
		parent->_parent = subR;

		// 3������parentParent��subR֮��Ĺ�ϵ
		if (parentParent == nullptr)
		{
			//subR��_parentָ����ı�
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
		// 4������ƽ������
		subR->_bf = parent->_bf = 0;
	}

	//����˫��
	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;

		//1����subLΪ��ת���������
		RotateL(parent->_left);
		//2����parentΪ��ת������ҵ���
		RotateR(parent);

		//3������ƽ������
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
			assert(false); //����תǰ����ƽ�����Ӿ�������
		}
	}

	//����˫��
	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;

		//1����subRΪ������ҵ���
		RotateR(subR);

		//2����parentΪ���������
		RotateL(parent);

		//3������ƽ������
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
			assert(false); //����תǰ����ƽ�����Ӿ�������
		}
	}
	///////////////////////// ��תend //////////////////////
	
	bool _IsBalanceTree(Node* root)
	{
		// ����Ҳ��AVL��
		if (nullptr == root)
			return true;
		// ����pRoot����ƽ�����ӣ���pRoot���������ĸ߶Ȳ�
		int leftHeight = _Height(root->_left);
		int rightHeight = _Height(root->_right);
		int diff = rightHeight - leftHeight;
		// ����������ƽ��������pRoot��ƽ�����Ӳ���ȣ�����
		// pRootƽ�����ӵľ���ֵ����1����һ������AVL��
		if (abs(diff) >= 2)
		{
			cout << root->_kv.first << "�߶Ȳ��쳣" << endl;
			return false;
		}
		if (root->_bf != diff)
		{
			cout << root->_kv.first << "ƽ�������쳣" << endl;
			return false;
		}
		// pRoot��������������AVL���������һ����AVL��
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




