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

	// �õ�������������ָ�����Ϊ
	T& operator*();
	T* operator->();

	// Ȼ�����������ƶ���ǰ��/����++  
	Self& operator++();
	Self operator++(int);
	// Ȼ�����������ƶ���ǰ��/����-- 
	Self& operator--();
	Self operator--(int);

	// �õ��������ԱȽ�
	bool operator!=(const Self& s)const;
	bool operator==(const Self& s)const;

private:
	void Increament();
	void DeIncreament();
	Node* _pNode;
};


// T: �����Ǽ�ֵ��<key,value>
//    ������һ��key
// ���۽ڵ��д洢����<key, value> || key, ���ǰ���key�����бȽϵ�
// KeyOfValue: ��ȡdata�е�Key
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

	// ����ֵΪdata�Ľڵ�
	// ����ֵ���壺iterator�����²���ڵ�   bool�������ͷŲ���ɹ�
	pair<iterator, bool> Insert(const T& data);

	// Begin��End������
	iterator Begin();
	iterator End();

	// ������Ƿ�Ϊ�죬�Ƿ���true�����򷵻�false
	bool Empty()const;
	// ���غ��������Ч�ڵ�ĸ���
	size_t Size()const;
	// ��������е���Ч�ڵ�ɾ����ע�⣺ɾ��������Ч�ڵ㣬��ɾ��ͷ���
	void Clear();
	// �ں�����в���data�����ڸϻظýڵ��Ӧ�ĵ����������򷵻�End()
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