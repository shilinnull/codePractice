#pragma once
#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

template<class K, class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	pair<K, V> _kv;

	int _bf; // balance factor

	AVLTreeNode(const pair<K, V>& kv)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _kv(kv)
		, _bf(0)
	{}
};

template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	//bool Insert(const pair<K, V>& kv)
	//{
	//	if (_root == nullptr)
	//	{
	//		_root = new Node(kv);
	//		return true;
	//	}

	//	Node* parent = nullptr;
	//	Node* cur = _root;

	//	while (cur)
	//	{
	//		if (cur->_kv.first < kv.first)
	//		{
	//			parent = cur;
	//			cur = cur->_right;
	//		}
	//		else if (cur->_kv.first > kv.first)
	//		{
	//			parent = cur;
	//			cur = cur->_left;
	//		}
	//		else
	//		{
	//			return false;
	//		}
	//	}

	//	cur = new Node(kv);
	//	if (parent->_kv.first < kv.first)
	//	{
	//		parent->_right = cur;
	//		cur->_parent = parent;
	//	}
	//	else
	//	{
	//		parent->_left = cur;
	//		cur->_parent = parent;
	//	}

	//	while (parent)
	//	{
	//		if (cur == parent->_left)
	//		{
	//			parent->_bf--;
	//		}
	//		else
	//		{
	//			parent->_bf++;
	//		}

	//		if (parent->_bf == 0)
	//		{
	//			break;
	//		}
	//		else if (parent->_bf == 1 || parent->_bf == -1)
	//		{
	//			cur = parent;
	//			parent = parent->_parent;
	//		}
	//		else if (parent->_bf == 2 || parent->_bf == -2)
	//		{
	//			if (parent->_bf == 2 && cur->_bf == 1)
	//			{
	//				RotateL(parent);
	//			}
	//			else if (parent->_bf == -2 && cur->_bf == -1)
	//			{
	//				RotateR(parent);
	//			}
	//			else if (parent->_bf == 2 && cur->_bf == -1)
	//			{
	//				RotateRL(parent);
	//			}
	//			else if (parent->_bf == -2 && cur->_bf == 1)
	//			{
	//				RotateLR(parent);
	//			}
	//			break;
	//		}
	//		else
	//		{
	//			assert(false);
	//		}
	//	}

	//	return true;
	//}

	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		subR->_left = parent;

		Node* parentParent = parent->_parent;

		parent->_parent = subR;
		if (subRL)
			subRL->_parent = parent;

		if (_root == parent)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (parentParent->_left == parent)
			{
				parentParent->_left = subR;
			}
			else
			{
				parentParent->_right = subR;
			}

			subR->_parent = parentParent;
		}

		parent->_bf = subR->_bf = 0;
	}

	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		Node* parentParent = parent->_parent;

		subL->_right = parent;
		parent->_parent = subL;

		if (_root == parent)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			if (parentParent->_left == parent)
			{
				parentParent->_left = subL;
			}
			else
			{
				parentParent->_right = subL;
			}

			subL->_parent = parentParent;
		}

		subL->_bf = parent->_bf = 0;
	}

	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;

		RotateR(parent->_right);
		RotateL(parent);

		if (bf == 0)
		{
			// subRL�Լ���������
			parent->_bf = subR->_bf = subRL->_bf = 0;
		}
		else if (bf == -1)
		{
			// subRL������������
			parent->_bf = 0;
			subRL->_bf = 0;
			subR->_bf = 1;
		}
		else if (bf == 1)
		{
			// subRL������������
			parent->_bf = -1;
			subRL->_bf = 0;
			subR->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}

	void RotateLR(Node* parent)
	{

		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf; //subLR������Ϊnullptr����ΪsubL��ƽ��������1

		//1����subLΪ��ת���������
		RotateL(subL);

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

	//�޸ĺ���
	bool Modify(const K& key, const V& value)
	{
		Node* ret = Find(key);
		if (ret == nullptr) //δ�ҵ�ָ��keyֵ�Ľ��
		{
			return false;
		}
		ret->_kv.second = value; //�޸Ľ���value
		return true;
	}

	//���뺯��
	pair<Node*, bool> Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr) //��AVL��Ϊ�������������ֱ����Ϊ�����
		{
			_root = new Node(kv);
			return make_pair(_root, true); //����ɹ��������²������true
		}
		//1�����ն����������Ĳ��뷽�����ҵ�������λ��
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (kv.first < cur->_kv.first) //���������keyֵС�ڵ�ǰ����keyֵ
			{
				//���ý�����������
				parent = cur;
				cur = cur->_left;
			}
			else if (kv.first > cur->_kv.first) //���������keyֵ���ڵ�ǰ����keyֵ
			{
				//���ý�����������
				parent = cur;
				cur = cur->_right;
			}
			else //���������keyֵ���ڵ�ǰ����keyֵ
			{
				//����ʧ�ܣ�������keyֵ���ࣩ
				return make_pair(cur, false); //����ʧ�ܣ������Ѿ����ڵĽ���false
			}
		}

		//2��������������뵽����
		cur = new Node(kv); //��������ֵ����һ���½��
		Node* newnode = cur; //��¼�²���Ľ��
		if (kv.first < parent->_kv.first) //�½���keyֵС��parent��keyֵ
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

		//3������ƽ�����ӣ�������ֲ�ƽ�⣬����Ҫ������ת
		while (cur != _root) //�һ·���µ������
		{
			if (cur == parent->_left) //parent������������
			{
				parent->_bf--; //parent��ƽ������--
			}
			else if (cur == parent->_right) //parent������������
			{
				parent->_bf++; //parent��ƽ������++
			}
			//�ж��Ƿ���½�������Ҫ������ת
			if (parent->_bf == 0) //���½�������������parent��������������һ�������ˣ���ʱ���Ҹ߶�һ�£�
			{
				break; //parent���ĸ߶�û�з����仯������Ӱ���丸��㼰���Ͻ���ƽ������
			}
			else if (parent->_bf == -1 || parent->_bf == 1) //��Ҫ�������ϸ���ƽ������
			{
				//parent���ĸ߶ȱ仯����Ӱ���丸����ƽ�����ӣ���Ҫ�������ϸ���ƽ������
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == -2 || parent->_bf == 2) //��Ҫ������ת����ʱparent���Ѿ���ƽ���ˣ�
			{
				if (parent->_bf == -2)
				{
					if (cur->_bf == -1)
					{
						RotateR(parent); //�ҵ���
					}
					else //cur->_bf == 1
					{
						RotateLR(parent); //����˫��
					}
				}
				else //parent->_bf == 2
				{
					if (cur->_bf == -1)
					{
						RotateRL(parent); //����˫��
					}
					else //cur->_bf == 1
					{
						RotateL(parent); //����
					}
				}
				break; //��ת���һ��ƽ���ˣ�����������ϸ���ƽ������(��ת�����߶ȱ�Ϊ����֮ǰ��)
			}
			else
			{
				assert(false); //�ڲ���ǰ����ƽ�����Ӿ�������
			}
		}

		return make_pair(newnode, true); //����ɹ��������²������true
	}

	//operator[]����
	V& operator[](const K& key)
	{
		//���ò��뺯�������ֵ��
		pair<Node*, bool> ret = Insert(make_pair(key, V()));
		//�ó��Ӳ��뺯����ȡ���Ľ��
		Node* node = ret.first;
		//���ظý��value������
		return node->_kv.second;
	}

	//ɾ������
	bool Erase(const K& key)
	{
		//���ڱ���������
		Node* parent = nullptr;
		Node* cur = _root;
		//���ڱ��ʵ�ʵ�ɾ����㼰�丸���
		Node* delParentPos = nullptr;
		Node* delPos = nullptr;
		while (cur)
		{
			if (key < cur->_kv.first) //����keyֵС�ڵ�ǰ����keyֵ
			{
				//���ý�����������
				parent = cur;
				cur = cur->_left;
			}
			else if (key > cur->_kv.first) //����keyֵ���ڵ�ǰ����keyֵ
			{
				//���ý�����������
				parent = cur;
				cur = cur->_right;
			}
			else //�ҵ��˴�ɾ�����
			{
				if (cur->_left == nullptr) //��ɾ������������Ϊ��
				{
					if (cur == _root) //��ɾ������Ǹ����
					{
						_root = _root->_right; //�ø�������������Ϊ�µĸ����
						if (_root)
							_root->_parent = nullptr;
						delete cur; //ɾ��ԭ�����
						return true; //����������Ƚ�㣬�������ƽ�����ӵĸ��²���
					}
					else
					{
						delParentPos = parent; //���ʵ��ɾ�����ĸ����
						delPos = cur; //���ʵ��ɾ���Ľ��
					}
					break; //ɾ����������Ƚ�㣬�����ƽ������
				}
				else if (cur->_right == nullptr) //��ɾ������������Ϊ��
				{
					if (cur == _root) //��ɾ������Ǹ����
					{
						_root = _root->_left; //�ø�������������Ϊ�µĸ����
						if (_root)
							_root->_parent = nullptr;
						delete cur; //ɾ��ԭ�����
						return true; //����������Ƚ�㣬�������ƽ�����ӵĸ��²���
					}
					else
					{
						delParentPos = parent; //���ʵ��ɾ�����ĸ����
						delPos = cur; //���ʵ��ɾ���Ľ��
					}
					break; //ɾ����������Ƚ�㣬�����ƽ������
				}
				else //��ɾ������������������Ϊ��
				{
					//�滻��ɾ��
					//Ѱ�Ҵ�ɾ���������������keyֵ��С�Ľ����Ϊʵ��ɾ�����
					Node* minParent = cur;
					Node* minRight = cur->_right;
					while (minRight->_left)
					{
						minParent = minRight;
						minRight = minRight->_left;
					}
					cur->_kv.first = minRight->_kv.first; //����ɾ������key��ΪminRight��key
					cur->_kv.second = minRight->_kv.second; //����ɾ������value��ΪminRight��value
					delParentPos = minParent; //���ʵ��ɾ�����ĸ����
					delPos = minRight; //���ʵ��ɾ���Ľ��
					break; //ɾ����������Ƚ�㣬�����ƽ������
				}
			}
		}
		if (delParentPos == nullptr) //delParentPosû�б��޸Ĺ���˵��û���ҵ���ɾ�����
		{
			return false;
		}

		//��¼��ɾ����㼰�丸��㣨���ں���ʵ��ɾ����
		Node* del = delPos;
		Node* delP = delParentPos;

		//����ƽ������
		while (delPos != _root) //�һ·���µ������
		{
			if (delPos == delParentPos->_left) //delParentPos���������߶Ƚ���
			{
				delParentPos->_bf++; //delParentPos��ƽ������++
			}
			else if (delPos == delParentPos->_right) //delParentPos���������߶Ƚ���
			{
				delParentPos->_bf--; //delParentPos��ƽ������--
			}
			//�ж��Ƿ���½�������Ҫ������ת
			if (delParentPos->_bf == 0)//��Ҫ�������ϸ���ƽ������
			{
				//delParentPos���ĸ߶ȱ仯����Ӱ���丸����ƽ�����ӣ���Ҫ�������ϸ���ƽ������
				delPos = delParentPos;
				delParentPos = delParentPos->_parent;
			}
			else if (delParentPos->_bf == -1 || delParentPos->_bf == 1) //���½���
			{
				break; //delParent���ĸ߶�û�з����仯������Ӱ���丸��㼰���Ͻ���ƽ������
			}
			else if (delParentPos->_bf == -2 || delParentPos->_bf == 2) //��Ҫ������ת����ʱdelParentPos���Ѿ���ƽ���ˣ�
			{
				if (delParentPos->_bf == -2)
				{
					if (delParentPos->_left->_bf == -1)
					{
						Node* tmp = delParentPos->_left; //��¼delParentPos����ת���µĸ����
						RotateR(delParentPos); //�ҵ���
						delParentPos = tmp; //���¸����
					}
					else if (delParentPos->_left->_bf == 1)
					{
						Node* tmp = delParentPos->_left->_right; //��¼delParentPos������ת���µĸ����
						RotateLR(delParentPos); //����˫��
						delParentPos = tmp; //���¸����
					}
					else //delParentPos->_left->_bf == 0
					{
						Node* tmp = delParentPos->_left; //��¼delParentPos����ת���µĸ����
						RotateR(delParentPos); //�ҵ���
						delParentPos = tmp; //���¸����
						//ƽ�����ӵ���
						delParentPos->_bf = 1;
						delParentPos->_right->_bf = -1;
						break; //����
					}
				}
				else //delParentPos->_bf == 2
				{
					if (delParentPos->_right->_bf == -1)
					{
						Node* tmp = delParentPos->_right->_left; //��¼delParentPos������ת���µĸ����
						RotateRL(delParentPos); //����˫��
						delParentPos = tmp; //���¸����
					}
					else if (delParentPos->_right->_bf == 1)
					{
						Node* tmp = delParentPos->_right; //��¼delParentPos����ת���µĸ����
						RotateL(delParentPos); //����
						delParentPos = tmp; //���¸����
					}
					else //delParentPos->_right->_bf == 0
					{
						Node* tmp = delParentPos->_right; //��¼delParentPos����ת���µĸ����
						RotateL(delParentPos); //����
						delParentPos = tmp; //���¸����
						//ƽ�����ӵ���
						delParentPos->_bf = -1;
						delParentPos->_left->_bf = 1;
						break; //����
					}
				}
				//delParentPos���ĸ߶ȱ仯����Ӱ���丸����ƽ�����ӣ���Ҫ�������ϸ���ƽ������
				delPos = delParentPos;
				delParentPos = delParentPos->_parent;
				//break; //error
			}
			else
			{
				assert(false); //��ɾ��ǰ����ƽ�����Ӿ�������
			}
		}
		//����ʵ��ɾ��
		if (del->_left == nullptr) //ʵ��ɾ������������Ϊ��
		{
			if (del == delP->_left) //ʵ��ɾ��������丸��������
			{
				delP->_left = del->_right;
				if (del->_right)
					del->_right->_parent = delP;
			}
			else //ʵ��ɾ��������丸�����Һ���
			{
				delP->_right = del->_right;
				if (del->_right)
					del->_right->_parent = delP;
			}
		}
		else //ʵ��ɾ������������Ϊ��
		{
			if (del == delP->_left) //ʵ��ɾ��������丸��������
			{
				delP->_left = del->_left;
				if (del->_left)
					del->_left->_parent = delP;
			}
			else //ʵ��ɾ��������丸�����Һ���
			{
				delP->_right = del->_left;
				if (del->_left)
					del->_left->_parent = delP;
			}
		}
		delete del; //ʵ��ɾ�����
		return true;
	}


	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;

		_InOrder(root->_left);
		cout << root->_kv.first << " ";
		_InOrder(root->_right);
	}

	bool IsBalance()
	{
		return _IsBalance(_root);
	}

	int _Height(Node* root)
	{
		if (root == nullptr)
			return 0;

		int leftHeight = _Height(root->_left);
		int rightHeight = _Height(root->_right);

		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}

	bool _IsBalance(Node* root)
	{
		if (root == nullptr)
			return true;

		int leftHeight = _Height(root->_left);
		int rightHeight = _Height(root->_right);
		if (rightHeight - leftHeight != root->_bf)
		{
			cout << root->_kv.first << "ƽ�������쳣" << endl;
			return false;
		}

		return abs(rightHeight - leftHeight) < 2
			&& _IsBalance(root->_left)
			&& _IsBalance(root->_right);
	}

private:
	Node* _root = nullptr;
};



void TestAVLTree1()
{
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	AVLTree<int, int> t1;
	for (auto e : a)
	{
		t1.Insert({ e,e });
	}

	t1.InOrder();
}

void TestAVLTree2()
{

	// int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	AVLTree<int, int> t;
	for (auto e : a)
	{
		t.Insert(std::make_pair(e, e));
	}
	t.InOrder();
	std::cout << t.IsBalance() << std::endl;


	const int N = 30;
	std::vector<int> v;
	v.reserve(N);
	//srand(time(0));

	for (size_t i = 0; i < N; i++)
	{
		v.push_back(rand());
		std::cout << v.back() << std::endl;
	}

	for (auto e : v)
	{
		if (e == 14604)
		{
			int x = 0;
		}

		t.Insert(std::make_pair(e, e));
		std::cout << "Insert:" << e << "->" << t.IsBalance() << std::endl;
	}

	std::cout << t.IsBalance() << std::endl;

}



