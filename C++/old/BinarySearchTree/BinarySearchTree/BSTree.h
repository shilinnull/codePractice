#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;

template<class K, class V>
struct BSTreeNode
{
	BSTreeNode<K, V>* _left;
	BSTreeNode<K, V>* _right;
	K _key;
	V _value;
	BSTreeNode(const K& val,const V& value)
		:_left(nullptr)
		, _right(nullptr)
		, _key(val)
		, _value(value)
	{}
};

template<class K, class V>
class BSTree
{
	typedef BSTreeNode<K, V> Node;
public:
	bool Insert(const K& key, const V& value)
	{
		if (_root == nullptr)
		{
			_root = new Node(key,value);
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			parent = cur;
			if (cur->_key < key)
				cur = cur->_left;
			else if (cur->_key > key)
				cur = cur->_right;
			else
				return false;
		}

		cur = new Node(key,value);
		if (parent->_key < key)
			parent->_left = cur;
		else
			parent->_right = cur;

		return true;
	}
	Node* Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
				cur = cur->_left;
			else if (cur->_key > key)
				cur = cur->_right;
			else
				return cur;
		}
		return nullptr;
	}
	bool Erase(const K& key)
	{
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			// 找val
			while (cur)
			{
				if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else
				{
					// 删除
					if (cur->_left == nullptr)
					{
						// 左为空
						if (cur == _root)
						{
							_root = cur->_right;
						}
						else
						{
							if (parent->_left == cur)
							{
								parent->_left = cur->_right;
							}
							else
							{
								parent->_right = cur->_right;
							}
						}
						delete cur;
					}
					else if (cur->_right == nullptr)
					{
						// 右为空
						if (cur == _root)
						{
							_root = cur->left;
						}
						else
						{
							if (cur == parent->_left)
							{
								parent->_left = cur->_left;
							}
							else
							{
								parent->_right = cur->_left;
							}
						}
						delete cur;
					}
					else
					{
						// 两边都不为空
						// 右树的最小节点(最左节点)
						Node* parent = cur;
						Node* rightMin = cur->_right;
						while (rightMin->_left)
						{
							parent = cur;
							rightMin = rightMin->_left;
						}

						std::swap(cur->_key, parent->_key);

						if (rightMin == parent->_left)
						{
							parent->_left = rightMin->_right;
						}
						else
						{
							parent->_right = rightMin->_right;
						}
						delete rightMin;
					}
					return true;
				}
			}
		}
		return false;
	}
	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;
		_InOrder(root->_left);
		cout << root->_key << " " << root->_value;
		_InOrder(root->_right);
	}
	void InOrder()
	{
		return _InOrder(_root);
		cout << endl;
	}
private:
	Node* _root = nullptr;
};

void BSTree1()
{
	BSTree<string, string> dict;
	dict.Insert("insert", "插入");
	dict.Insert("erase", "删除");
	dict.Insert("left", "左边");
	dict.Insert("string", "字符串");

	string str;
	while (cin >> str)
	{
		auto ret = dict.Find(str);
		if (ret)
		{
			cout << str << ":" << ret->_value << endl;
		}
		else
		{
			cout << "单词拼写错误" << endl;
		}
	}

	string strs[] = { "苹果", "西瓜", "苹果", "樱桃", "苹果", "樱桃", "苹果", "樱桃", "苹果" };
	// 统计水果出现的次
	BSTree<string, int> countTree;
	for (auto str : strs)
	{
		auto ret = countTree.Find(str);
		if (ret == NULL)
		{
			countTree.Insert(str, 1);
		}
		else
		{
			ret->_value++;
		}
	}
	countTree.InOrder();
}
