#pragma once
#include<iostream>

using namespace std;

template<class T>
struct RBTreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef RBTreeIterator<T> Self;

	RBTreeIterator(Node* pNode)
		: _pNode(pNode)
	{}

	// 让迭代器具有类似指针的行为
	T& operator*();
	T* operator->();

	// 然迭代器可以移动：前置/后置++  
	Self& operator++();
	Self operator++(int);
	// 然迭代器可以移动：前置/后置-- 
	Self& operator--();
	Self operator--(int);

	// 让迭代器可以比较
	bool operator!=(const Self& s)const;
	bool operator==(const Self& s)const;

private:
	void Increament();
	void DeIncreament();
	Node* _pNode;
};


// T: 可能是键值对<key,value>
//    可能是一个key
// 不论节点中存储的是<key, value> || key, 都是按照key来进行比较的
// KeyOfValue: 提取data中的Key
template<class T, class KeyOfValue>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	typedef RBTreeIterator<T> iterator;
public:
	RBTree()
		: _size(0)
	{
		_pHead = new Node;
		_pHead->_pLeft = _pHead;
		_pHead->_pRight = _pHead;
	}

	// 插入值为data的节点
	// 返回值含义：iterator代表新插入节点   bool：代表释放插入成功
	pair<iterator, bool> Insert(const T& data);

	// Begin和End迭代器
	iterator Begin();
	iterator End();

	// 红黑树是否为红，是返回true，否则返回false
	bool Empty()const;
	// 返回红黑树中有效节点的个数
	size_t Size()const;
	// 将红黑树中的有效节点删除，注意：删除的是有效节点，不删除头结点
	void Clear();
	// 在红黑树中查找data，存在赶回该节点对应的迭代器，否则返回End()
	iterator Find(const T& data);

private:
	Node* _LeftMost();
	Node* _RightMost();
	void _Destroy(Node*& pRoot);
	void RotateL(Node* pParent);
	void RotateR(Node* pParent);
private:
	Node* _pHead;
	size_t _size;
};