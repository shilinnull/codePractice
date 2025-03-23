#pragma once
#include<iostream>

namespace key
{
	// ���Ľڵ�
	template<class K>
	struct BSTreeNode
	{
		BSTreeNode<K>* _left;
		BSTreeNode<K>* _right;
		K _val;

		BSTreeNode(const K& val)
			:_left(nullptr)
			, _right(nullptr)
			, _val(val)
		{}
	};

	template<class K>
	class BSTree
	{
		typedef BSTreeNode<K> Node;
	public:
		bool Insert(const K& val)
		{
			if (_root == nullptr) {
				_root = new Node(val);
				return true;
			}

			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				// ��ǰ����cur��λ��
				parent = cur;
				// �ȵ�ǰλ�ô������ߣ��ȵ�ǰλ��С������
				if (cur->_val < val)
					cur = cur->_left;
				else if (cur->_val > val)
					cur = cur->_right;
				else
					return false;
			}
			// �ߵ�����˵���ҵ����ʵ�λ����
			cur = new Node(val);
			if (parent->_val < val)
				parent->_left = cur;
			else
				parent->_right = cur;

			return true;
		}

		bool Find(const K& val)
		{
			Node* cur = _root;
			while (cur) {
				if (cur->_val < val)
					cur = cur->_left;
				else if (cur->_val > val)
					cur = cur->_right;
				else if (cur->_val == val)
					return true;
			}
			return false;
		}

		bool Erase(const K& key)
		{
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				// ��val
				if (cur->_val < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_val > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					// ׼��ɾ��
					if (cur->_left == nullptr)
					{//��Ϊ��
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
					{//��Ϊ��
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
					{//���Ҷ���Ϊ��
						// ��������С�ڵ�(����ڵ�)
						Node* parent = cur;
						Node* subLeft = cur->_right;
						while (subLeft->_left)
						{
							parent = subLeft;
							subLeft = subLeft->_left;
						}

						std::swap(cur->_val, subLeft->_val);

						if (subLeft == parent->_left)
							parent->_left = subLeft->_right;
						else
							parent->_right = subLeft->_right;

						delete subLeft;
					}
					return true;
				}
			}// (cur)end...
			return false;
		}

		void InOrder()
		{
			_InOrder(_root);
			std::cout << std::endl;
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

		~BSTree()
		{
			Destory(_root);
		}

		BSTree() = default;

		BSTree(const BSTree<K>& t)
		{
			_root = Copy(t._root);
		}

		BSTree<K>& operator=(BSTree<K> t)
		{
			swap(_root, t._root);

			return *this;
		}

	private:

		Node* Copy(Node* root)
		{
			if (root == nullptr)
				return nullptr;

			Node* newRoot = new Node(_root->_val);
			newRoot->_left = Copy(root->_left);
			newRoot->_right = Copy(root->_right);

			return newRoot;
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

		// ����ҲҪע����������
		bool _EraseR(Node*& root, const K& val)
		{
			if (root == nullptr)
				return false;

			if (root->_val < val)
				return _EraseR(root->_right, val);
			else if (root->_val > val)
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

					std::swap(root->_val, subLeft->_val);

					// ת����������ȥ�ݹ�ɾ��
					return _EraseR(root->_right, val);
				}
			}
			return false;
		}

		bool _FindR(Node* root, const K& val)
		{
			if (root == nullptr)
				return false;
			if (root->_val < val)
				return _FindR(root->_right, val);
			else if (root->_val > val)
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

			if (root->_val < val)
				return _InsertR(root->_right, val);
			else if (root->_val > val)
				return _InsertR(root->_left, val);
			else
				return false;
		}

		void _InOrder(Node* root)
		{
			if (root == nullptr)
				return;

			_InOrder(root->_right);
			std::cout << root->_val << " ";
			_InOrder(root->_left);
		}

		Node* _root = nullptr;
	};
}


namespace key_value
{
	// ���Ľڵ�
	template<class K, class V>
	struct BSTreeNode
	{
		BSTreeNode<K, V>* _left;
		BSTreeNode<K, V>* _right;
		K _val;
		V _value;

		BSTreeNode(const K& val, const V& value)
			:_left(nullptr)
			, _right(nullptr)
			, _val(val)
			, _value(value)
		{}
	};

	template<class K, class V>
	class BSTree
	{
		typedef BSTreeNode<K, V> Node;
	public:
		bool Insert(const K& val, const V& value)
		{
			if (_root == nullptr) {
				_root = new Node(val, value);
				return true;
			}

			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				// ��ǰ����cur��λ��
				parent = cur;
				// �ȵ�ǰλ�ô������ߣ��ȵ�ǰλ��С������
				if (cur->_val < val)
					cur = cur->_left;
				else if (cur->_val > val)
					cur = cur->_right;
				else
					return false;
			}
			// �ߵ�����˵���ҵ����ʵ�λ����
			cur = new Node(val, value);
			if (parent->_val < val)
				parent->_left = cur;
			else
				parent->_right = cur;

			return true;
		}

		Node* Find(const K& val)
		{
			Node* cur = _root;
			while (cur) {
				if (cur->_val < val)
					cur = cur->_left;
				else if (cur->_val > val)
					cur = cur->_right;
				else if (cur->_val == val)
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
				// ��val
				if (cur->_val < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_val > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					// ׼��ɾ��
					if (cur->_left == nullptr)
					{//��Ϊ��
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
					{//��Ϊ��
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
					{//���Ҷ���Ϊ��
						// ��������С�ڵ�(����ڵ�)
						Node* parent = cur;
						Node* subLeft = cur->_right;
						while (subLeft->_left)
						{
							parent = subLeft;
							subLeft = subLeft->_left;
						}

						std::swap(cur->_val, subLeft->_val);

						if (subLeft == parent->_left)
							parent->_left = subLeft->_right;
						else
							parent->_right = subLeft->_right;

						delete subLeft;
					}
					return true;
				}
			}// (cur)end...
			return false;
		}

		void InOrder()
		{
			_InOrder(_root);
			std::cout << std::endl;
		}
	private:
		void _InOrder(Node* root)
		{
			if (root == nullptr)
				return;

			_InOrder(root->_right);
			std::cout << root->_val << ":" << root->_value << std::endl;
			_InOrder(root->_left);
		}

		Node* _root = nullptr;
	};
}
