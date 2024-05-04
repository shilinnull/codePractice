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
			// subRL自己就是新增
			parent->_bf = subR->_bf = subRL->_bf = 0;
		}
		else if (bf == -1)
		{
			// subRL的左子树新增
			parent->_bf = 0;
			subRL->_bf = 0;
			subR->_bf = 1;
		}
		else if (bf == 1)
		{
			// subRL的右子树新增
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
		int bf = subLR->_bf; //subLR不可能为nullptr，因为subL的平衡因子是1

		//1、以subL为旋转点进行左单旋
		RotateL(subL);

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

	//修改函数
	bool Modify(const K& key, const V& value)
	{
		Node* ret = Find(key);
		if (ret == nullptr) //未找到指定key值的结点
		{
			return false;
		}
		ret->_kv.second = value; //修改结点的value
		return true;
	}

	//插入函数
	pair<Node*, bool> Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr) //若AVL树为空树，则插入结点直接作为根结点
		{
			_root = new Node(kv);
			return make_pair(_root, true); //插入成功，返回新插入结点和true
		}
		//1、按照二叉搜索树的插入方法，找到待插入位置
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (kv.first < cur->_kv.first) //待插入结点的key值小于当前结点的key值
			{
				//往该结点的左子树走
				parent = cur;
				cur = cur->_left;
			}
			else if (kv.first > cur->_kv.first) //待插入结点的key值大于当前结点的key值
			{
				//往该结点的右子树走
				parent = cur;
				cur = cur->_right;
			}
			else //待插入结点的key值等于当前结点的key值
			{
				//插入失败（不允许key值冗余）
				return make_pair(cur, false); //插入失败，返回已经存在的结点和false
			}
		}

		//2、将待插入结点插入到树中
		cur = new Node(kv); //根据所给值构造一个新结点
		Node* newnode = cur; //记录新插入的结点
		if (kv.first < parent->_kv.first) //新结点的key值小于parent的key值
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

		//3、更新平衡因子，如果出现不平衡，则需要进行旋转
		while (cur != _root) //最坏一路更新到根结点
		{
			if (cur == parent->_left) //parent的左子树增高
			{
				parent->_bf--; //parent的平衡因子--
			}
			else if (cur == parent->_right) //parent的右子树增高
			{
				parent->_bf++; //parent的平衡因子++
			}
			//判断是否更新结束或需要进行旋转
			if (parent->_bf == 0) //更新结束（新增结点把parent左右子树矮的那一边增高了，此时左右高度一致）
			{
				break; //parent树的高度没有发生变化，不会影响其父结点及以上结点的平衡因子
			}
			else if (parent->_bf == -1 || parent->_bf == 1) //需要继续往上更新平衡因子
			{
				//parent树的高度变化，会影响其父结点的平衡因子，需要继续往上更新平衡因子
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == -2 || parent->_bf == 2) //需要进行旋转（此时parent树已经不平衡了）
			{
				if (parent->_bf == -2)
				{
					if (cur->_bf == -1)
					{
						RotateR(parent); //右单旋
					}
					else //cur->_bf == 1
					{
						RotateLR(parent); //左右双旋
					}
				}
				else //parent->_bf == 2
				{
					if (cur->_bf == -1)
					{
						RotateRL(parent); //右左双旋
					}
					else //cur->_bf == 1
					{
						RotateL(parent); //左单旋
					}
				}
				break; //旋转后就一定平衡了，无需继续往上更新平衡因子(旋转后树高度变为插入之前了)
			}
			else
			{
				assert(false); //在插入前树的平衡因子就有问题
			}
		}

		return make_pair(newnode, true); //插入成功，返回新插入结点和true
	}

	//operator[]重载
	V& operator[](const K& key)
	{
		//调用插入函数插入键值对
		pair<Node*, bool> ret = Insert(make_pair(key, V()));
		//拿出从插入函数获取到的结点
		Node* node = ret.first;
		//返回该结点value的引用
		return node->_kv.second;
	}

	//删除函数
	bool Erase(const K& key)
	{
		//用于遍历二叉树
		Node* parent = nullptr;
		Node* cur = _root;
		//用于标记实际的删除结点及其父结点
		Node* delParentPos = nullptr;
		Node* delPos = nullptr;
		while (cur)
		{
			if (key < cur->_kv.first) //所给key值小于当前结点的key值
			{
				//往该结点的左子树走
				parent = cur;
				cur = cur->_left;
			}
			else if (key > cur->_kv.first) //所给key值大于当前结点的key值
			{
				//往该结点的右子树走
				parent = cur;
				cur = cur->_right;
			}
			else //找到了待删除结点
			{
				if (cur->_left == nullptr) //待删除结点的左子树为空
				{
					if (cur == _root) //待删除结点是根结点
					{
						_root = _root->_right; //让根结点的右子树作为新的根结点
						if (_root)
							_root->_parent = nullptr;
						delete cur; //删除原根结点
						return true; //根结点无祖先结点，无需进行平衡因子的更新操作
					}
					else
					{
						delParentPos = parent; //标记实际删除结点的父结点
						delPos = cur; //标记实际删除的结点
					}
					break; //删除结点有祖先结点，需更新平衡因子
				}
				else if (cur->_right == nullptr) //待删除结点的右子树为空
				{
					if (cur == _root) //待删除结点是根结点
					{
						_root = _root->_left; //让根结点的左子树作为新的根结点
						if (_root)
							_root->_parent = nullptr;
						delete cur; //删除原根结点
						return true; //根结点无祖先结点，无需进行平衡因子的更新操作
					}
					else
					{
						delParentPos = parent; //标记实际删除结点的父结点
						delPos = cur; //标记实际删除的结点
					}
					break; //删除结点有祖先结点，需更新平衡因子
				}
				else //待删除结点的左右子树均不为空
				{
					//替换法删除
					//寻找待删除结点右子树当中key值最小的结点作为实际删除结点
					Node* minParent = cur;
					Node* minRight = cur->_right;
					while (minRight->_left)
					{
						minParent = minRight;
						minRight = minRight->_left;
					}
					cur->_kv.first = minRight->_kv.first; //将待删除结点的key改为minRight的key
					cur->_kv.second = minRight->_kv.second; //将待删除结点的value改为minRight的value
					delParentPos = minParent; //标记实际删除结点的父结点
					delPos = minRight; //标记实际删除的结点
					break; //删除结点有祖先结点，需更新平衡因子
				}
			}
		}
		if (delParentPos == nullptr) //delParentPos没有被修改过，说明没有找到待删除结点
		{
			return false;
		}

		//记录待删除结点及其父结点（用于后续实际删除）
		Node* del = delPos;
		Node* delP = delParentPos;

		//更新平衡因子
		while (delPos != _root) //最坏一路更新到根结点
		{
			if (delPos == delParentPos->_left) //delParentPos的左子树高度降低
			{
				delParentPos->_bf++; //delParentPos的平衡因子++
			}
			else if (delPos == delParentPos->_right) //delParentPos的右子树高度降低
			{
				delParentPos->_bf--; //delParentPos的平衡因子--
			}
			//判断是否更新结束或需要进行旋转
			if (delParentPos->_bf == 0)//需要继续往上更新平衡因子
			{
				//delParentPos树的高度变化，会影响其父结点的平衡因子，需要继续往上更新平衡因子
				delPos = delParentPos;
				delParentPos = delParentPos->_parent;
			}
			else if (delParentPos->_bf == -1 || delParentPos->_bf == 1) //更新结束
			{
				break; //delParent树的高度没有发生变化，不会影响其父结点及以上结点的平衡因子
			}
			else if (delParentPos->_bf == -2 || delParentPos->_bf == 2) //需要进行旋转（此时delParentPos树已经不平衡了）
			{
				if (delParentPos->_bf == -2)
				{
					if (delParentPos->_left->_bf == -1)
					{
						Node* tmp = delParentPos->_left; //记录delParentPos右旋转后新的根结点
						RotateR(delParentPos); //右单旋
						delParentPos = tmp; //更新根结点
					}
					else if (delParentPos->_left->_bf == 1)
					{
						Node* tmp = delParentPos->_left->_right; //记录delParentPos左右旋转后新的根结点
						RotateLR(delParentPos); //左右双旋
						delParentPos = tmp; //更新根结点
					}
					else //delParentPos->_left->_bf == 0
					{
						Node* tmp = delParentPos->_left; //记录delParentPos右旋转后新的根结点
						RotateR(delParentPos); //右单旋
						delParentPos = tmp; //更新根结点
						//平衡因子调整
						delParentPos->_bf = 1;
						delParentPos->_right->_bf = -1;
						break; //更正
					}
				}
				else //delParentPos->_bf == 2
				{
					if (delParentPos->_right->_bf == -1)
					{
						Node* tmp = delParentPos->_right->_left; //记录delParentPos右左旋转后新的根结点
						RotateRL(delParentPos); //右左双旋
						delParentPos = tmp; //更新根结点
					}
					else if (delParentPos->_right->_bf == 1)
					{
						Node* tmp = delParentPos->_right; //记录delParentPos左旋转后新的根结点
						RotateL(delParentPos); //左单旋
						delParentPos = tmp; //更新根结点
					}
					else //delParentPos->_right->_bf == 0
					{
						Node* tmp = delParentPos->_right; //记录delParentPos左旋转后新的根结点
						RotateL(delParentPos); //左单旋
						delParentPos = tmp; //更新根结点
						//平衡因子调整
						delParentPos->_bf = -1;
						delParentPos->_left->_bf = 1;
						break; //更正
					}
				}
				//delParentPos树的高度变化，会影响其父结点的平衡因子，需要继续往上更新平衡因子
				delPos = delParentPos;
				delParentPos = delParentPos->_parent;
				//break; //error
			}
			else
			{
				assert(false); //在删除前树的平衡因子就有问题
			}
		}
		//进行实际删除
		if (del->_left == nullptr) //实际删除结点的左子树为空
		{
			if (del == delP->_left) //实际删除结点是其父结点的左孩子
			{
				delP->_left = del->_right;
				if (del->_right)
					del->_right->_parent = delP;
			}
			else //实际删除结点是其父结点的右孩子
			{
				delP->_right = del->_right;
				if (del->_right)
					del->_right->_parent = delP;
			}
		}
		else //实际删除结点的右子树为空
		{
			if (del == delP->_left) //实际删除结点是其父结点的左孩子
			{
				delP->_left = del->_left;
				if (del->_left)
					del->_left->_parent = delP;
			}
			else //实际删除结点是其父结点的右孩子
			{
				delP->_right = del->_left;
				if (del->_left)
					del->_left->_parent = delP;
			}
		}
		delete del; //实际删除结点
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
			cout << root->_kv.first << "平衡因子异常" << endl;
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



