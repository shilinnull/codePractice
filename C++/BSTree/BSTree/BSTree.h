#pragma once

#include <iostream>

using namespace std;

namespace key
{
	template <class K>
	struct BSTNode
	{
		K _key;
		BSTNode<K>* _left;
		BSTNode<K>* _right;

		BSTNode(const K& key)
			: _key(key)
			, _left(nullptr)
			, _right(nullptr)
		{
		}
	};


	template<class K>
	class BSTree
	{
		typedef BSTNode<K> Node;
	public:
		BSTree() = default; // Ĭ�Ϲ���

		~BSTree()
		{
			Destory(_root);
			_root = nullptr;
		}

		BSTree(const BSTree<K>& t)
		{
			_root = Copy(t._root);
		}

		Node* Copy(Node* root)
		{
			if (root == nullptr)
				return nullptr;

			Node* newRoot = new Node(_root->_key);
			newRoot->_left = Copy(root->_left);
			newRoot->_right = Copy(root->_right);

			return newRoot;
		}

		BSTree<K>& operator=(BSTree<K> k)
		{
			std::swap(_root, k._root);
			return *this;
		}

		bool Insert(const K& key)
		{
			if (_root == nullptr)
			{
				_root = new Node(key);
				return true;
			}

			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				// ��ǰ���游�ڵ�
				parent = cur;
				// �Ƚ�->1.��ǰλ�ñ�keyҪ��������
				//		 2. ��ǰλ�ñ�keyҪС������
				if (cur->_key < key)
					cur = cur->_right;
				else if (cur->_key > key)
					cur = cur->_left;
				else
					return false;
			}
			// �ҵ�λ����
			cur = new Node(key);
			if (parent->_key < key)
				parent->_right = cur;
			else
				parent->_left = cur;
			return true;
		}

		bool Erase(const K& key)
		{
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					// �ҵ��ˣ�����ɾ��
					if (cur->_left == nullptr)
					{
						if (cur == _root)
							_root = cur->_right;
						else
						{
							if (cur == parent->_left)
								parent->_left = cur->_right;
							else
								parent->_right = cur->_right;
						}
						delete cur;
					}
					else if (cur->_right == nullptr)
					{
						if (cur == _root)
							_root = cur->_left;
						else
						{
							if (cur == parent->_left)
								parent->_left = cur->_left;
							else
								parent->_right = cur->_left;
						}
						delete cur;
					}
					else
					{
						// ���Ҷ���Ϊ��
						// ��������������ڵ�
						Node* subParent = cur;
						Node* sub = cur->_right;
						while (sub->_left)
						{
							subParent = sub;
							sub = sub->_left;
						}

						std::swap(sub->_key, cur->_key);

						if (sub == subParent->_left)
							subParent->_left = sub->_right;
						else
							subParent->_right = sub->_right;

						delete sub;
					}
					return true;
				}
			}// while (cur)
			return false;
		}

		bool Find(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
					cur = cur->_right;
				else if (cur->_key > key)
					cur = cur->_left;
				else
					return true;
			}
			return false;
		}

		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}

		// ------------�ݹ�汾--------------

		void FindR(const K& val)
		{
			return _FindR(_root, val);
		}

		bool InsertR(const K& val)
		{
			return _InsertR(_root, val);
		}

		bool EraseR(const K& val)
		{
			return _EraseR(_root, val);
		}

	private:
		void _InOrder(Node* root)
		{
			if (root == nullptr)
				return;

			_InOrder(root->_left);
			std::cout << root->_key << " ";
			_InOrder(root->_right);
		}

		void Destory(Node*& root)
		{
			if (root == nullptr)
				return;
			Destory(root->_left);
			Destory(root->_right);
			delete root;
			root = nullptr;
		}
		
		bool _FindR(Node* root, const K& val)
		{
			if (root == nullptr)
				return false;
			if (root->_key < val)
				return _FindR(root->_right, val);
			else if (root->_key > val)
				return _FindR(root->_left, val);
			else
				return true;
		}

		// ����ע����ʹ�õ�����
		bool _InsertR(Node*& root, const K& val)
		{
			if (root == nullptr)
			{
				root = new Node(val);
				return true;
			}

			if (root->_key < val)
				return _InsertR(root->_right, val);
			else if (root->_key > val)
				return _InsertR(root->_left, val);
			else
				return false;
		}

		// ����ҲҪע����������
		bool _EraseR(Node*& root, const K& val)
		{
			if (root == nullptr)
				return false;

			if (root->_key < val)
				return _EraseR(root->_right, val);
			else if (root->_key > val)
				return _EraseR(root->_left, val);
			else
			{
				// ɾ��
				if (root->_left == nullptr)
				{
					Node* del = root;
					root = root->_right;
					delete del;

					return true;
				}
				else if (root->_right == nullptr)
				{
					Node* del = root;
					root = root->_left;
					delete del;

					return true;
				}
				else
				{
					// ������ڵ�
					Node* subLeft = root->_right;
					while (subLeft->_left)
					{
						subLeft = subLeft->_left;
					}

					std::swap(root->_key, subLeft->_key);

					// ת����������ȥ�ݹ�ɾ��
					return _EraseR(root->_right, val);
				}
			}
			return false;
		}
		Node* _root = nullptr;
	};
}

namespace key_value
{
	template <class K, class V>
	struct BSTNode
	{
		K _key;
		V _value;
		BSTNode<K, V>* _left;
		BSTNode<K, V>* _right;

		BSTNode(const K& key, const V& value)
			:_key(key)
			, _value(value)
			, _left(nullptr)
			, _right(nullptr)
		{
		}
	};


	template<class K, class V>
	class BSTree
	{
		typedef BSTNode<K, V> Node;
	public:
		BSTree() = default; // Ĭ�Ϲ���

		~BSTree()
		{
			Destory(_root);
			_root = nullptr;
		}

		void Destory(Node*& root)
		{
			if (root == nullptr)
				return;

			Destory(root->_left);
			Destory(root->_right);

			delete root;
			root = nullptr;
		}

		Node* Copy(Node* root)
		{
			if (root == nullptr)
				return nullptr;

			Node* newRoot = new Node(_root->_val, root->_value);
			newRoot->_left = Copy(root->_left);
			newRoot->_right = Copy(root->_right);

			return newRoot;
		}

		BSTree<K, V>& operator=(BSTree<K, V> k)
		{
			std::swap(_root, k._root);
			return *this;
		}

		bool Insert(const K& key, const V& value)
		{
			if (_root == nullptr)
			{
				_root = new Node(key, value);
				return true;
			}

			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				// ��ǰ���游�ڵ�
				parent = cur;
				// �Ƚ�->1. ��ǰλ�ñ�keyҪ��������
				//		 2. ��ǰλ�ñ�keyҪ��������
				if (cur->_key < key)
					cur = cur->_right;
				else if (cur->_key > key)
					cur = cur->_left;
				else
					return false;
			}
			// �ҵ�λ����
			cur = new Node(key, value);
			if (parent->_key < key)
				parent->_right = cur;
			else
				parent->_left = cur;
			return true;
		}

		bool Erase(const K& key)
		{
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					// �ҵ��ˣ�����ɾ��
					if (cur->_left == nullptr)
					{
						if (cur == _root)
							_root = cur->_right;
						else
						{
							if (cur == parent->_left)
								parent->_left = cur->_right;
							else
								parent->_right = cur->_right;
						}
						delete cur;
					}
					else if (cur->_right == nullptr)
					{
						if (cur == _root)
							_root = cur->_left;
						else
						{
							if (cur == parent->_left)
								parent->_left = cur->_left;
							else
								parent->_right = cur->_left;
						}
						delete cur;
					}
					else
					{
						// ���Ҷ���Ϊ��
						// ��������������ڵ�
						Node* subParent = cur;
						Node* sub = cur->_right;
						while (sub->_left)
						{
							subParent = sub;
							sub = sub->_left;
						}

						std::swap(sub->_key, cur->_key);
						std::swap(sub->_value, cur->_value);

						if (sub == subParent->_left)
							subParent->_left = sub->_right;
						else
							subParent->_right = sub->_right;

						delete sub;
					}
					return true;
				}
			}// while (cur)
			return false;
		}

		Node* Find(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
					cur = cur->_right;
				else if (cur->_key > key)
					cur = cur->_left;
				else
					return cur;
			}
			return nullptr;
		}

		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}

	private:
		void _InOrder(Node* root)
		{
			if (root == nullptr)
				return;
			_InOrder(root->_left);
			cout << root->_key << " " << root->_value << endl;
			_InOrder(root->_right);

		}
		Node* _root = nullptr;
	};
}

