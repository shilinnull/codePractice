#pragma once
#include<iostream>

using namespace std;

//枚举定义结点的颜色
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

    //存储的数据
    T _data;

    //结点的颜色
    Colour _col; //红/黑

    //构造函数
    RBTreeNode(const T& data)
        :_left(nullptr)
        , _right(nullptr)
        , _parent(nullptr)
        , _data(data)
        , _col(RED)
    {}
};

//正向迭代器
template<class T, class Ref, class Ptr>
struct __TreeIterator
{

    typedef RBTreeNode<T> Node; //结点的类型
    typedef __TreeIterator<T, Ref, Ptr> Self; //正向迭代器的类型

    Node* _node; //正向迭代器所封装结点的指针
    Node* _root; //根节点

    //构造函数
    __TreeIterator(Node* node, Node* root)
        :_node(node) //根据所给结点指针构造一个正向迭代器
        , _root(root)
    {}

    Ref operator*()
    {
        return _node->_data; //返回结点数据的引用
    }
    Ptr operator->()
    {
        return &_node->_data; //返回结点数据的指针
    }
    //判断两个正向迭代器是否不同
    bool operator!=(const Self& s) const
    {
        return _node != s._node; //判断两个正向迭代器所封装的结点是否是同一个
    }
    //判断两个正向迭代器是否相同
    bool operator==(const Self& s) const
    {
        return _node == s._node; //判断两个正向迭代器所封装的结点是否是同一个
    }

    //前置++
    /*
    1. it指向的节点，右子树不为空，下一个右子树的最左节点
    2. it指向的节点，右子树为空，it中的节点所在的子树访问完了，往上找孩子是父亲左的那个祖先
    */
    Self& operator++()
    {
        if (_node->_right) //结点的右子树不为空
        {
            //寻找该结点右子树当中的最左结点
            Node* left = _node->_right;
            while (left->_left)
            {
                left = left->_left;
            }
            _node = left; //++后变为该结点
        }
        else //结点的右子树为空
        {
            //寻找孩子不在父亲右的祖先
            Node* cur = _node;
            Node* parent = cur->_parent;
            while (parent && cur == parent->_right)
            {
                cur = parent;
                parent = parent->_parent;
            }
            _node = parent; //++后变为该结点
        }
        return *this;
    }

    //前置--
    Self& operator--()
    {
        if (_node == nullptr) // end()
        {
            // --end()，特殊处理，走到中序最后一个结点，整棵树的最右结点
            Node* rightMost = _root;
            while (rightMost && rightMost->_right)
            {
                rightMost = rightMost->_right;
            }
            _node = rightMost;
        }
        else if (_node->_left) //结点的左子树不为空
        {
            //寻找该结点左子树当中的最右结点
            Node* right = _node->_left;
            while (right->_right)
            {
                right = right->_right;
            }
            _node = right; //--后变为该结点
        }
        else //结点的左子树为空
        {
            //寻找孩子不在父亲左的祖先
            Node* cur = _node;
            Node* parent = cur->_parent;
            while (parent && cur == parent->_left)
            {
                cur = parent;
                parent = parent->_parent;
            }
            _node = parent; //--后变为该结点
        }
        return *this;
    }
};


//红黑树的实现
template<class K, class T, class KeyOfT>
class RBTree
{
    KeyOfT kot; // 用于比较
    typedef RBTreeNode<T> Node; //结点的类型
public:
    typedef __TreeIterator<T, T&, T*> iterator;
    typedef __TreeIterator<T, const T&, const T*> const_iterator; //const迭代器

    iterator begin()
    {
        //寻找最左结点
        Node* left = _root;
        while (left && left->_left)
        {
            left = left->_left;
        }
        //返回最左结点的正向迭代器
        return iterator(left, _root);
    }

    iterator end()
    {
        //返回由nullptr构造得到的正向迭代器（不严谨）
        return iterator(nullptr, _root);
    }

    const_iterator begin()const
    {
        //寻找最左结点
        Node* left = _root;
        while (left && left->_left)
        {
            left = left->_left;
        }
        //返回最左结点的正向迭代器
        return const_iterator(left, _root);
    }
    const_iterator end()const
    {
        //返回由nullptr构造得到的正向迭代器（不严谨）
        return const_iterator(nullptr, _root);
    }
    //构造函数
    RBTree()
        :_root(nullptr)
    {}

    //拷贝构造
    RBTree(const RBTree<K, T, KeyOfT>& t)
    {
        _root = _Copy(t._root, nullptr);
    }

    //赋值运算符重载（现代写法）
    RBTree<K, T, KeyOfT>& operator=(RBTree<K, T, KeyOfT> t)
    {
        swap(_root, t._root);
        return *this; //支持连续赋值
    }

    //析构函数
    ~RBTree()
    {
        _Destroy(_root);
        _root = nullptr;
    }

    //查找函数
    iterator Find(const K& key)
    {
        KeyOfT kot;
        Node* cur = _root;
        while (cur)
        {
            if (key < kot(cur->_data)) //key值小于该结点的值
            {
                cur = cur->_left; //在该结点的左子树当中查找
            }
            else if (key > kot(cur->_data)) //key值大于该结点的值
            {
                cur = cur->_right; //在该结点的右子树当中查找
            }
            else //找到了目标结点
            {
                return iterator(cur); //返回该结点
            }
        }
        return end(); //查找失败
    }

    //插入函数
    pair<iterator, bool> Insert(const T& data)
    {
        if (_root == nullptr) //若红黑树为空树，则插入结点直接作为根结点
        {
            _root = new Node(data);
            _root->_col = BLACK; //根结点必须是黑色

            return std::make_pair(iterator(_root, _root), true);
            //return { iterator(_root, _root), true }; //插入成功
        }
        //1、按二叉搜索树的插入方法，找到待插入位置
        Node* cur = _root;
        Node* parent = nullptr;
        while (cur)
        {
            if (kot(data) < kot(cur->_data)) //待插入结点的key值小于当前结点的key值
            {
                //往该结点的左子树走
                parent = cur;
                cur = cur->_left;
            }
            else if (kot(data) > kot(cur->_data)) //待插入结点的key值大于当前结点的key值
            {
                //往该结点的右子树走
                parent = cur;
                cur = cur->_right;
            }
            else //待插入结点的key值等于当前结点的key值
            {
                return std::make_pair(iterator(cur, _root), false);
                //return { iterator(cur, _root), false }; //插入成功
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

        //3、若插入结点的父结点是红色的，则需要对红黑树进行调整
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
        _root->_col = BLACK; //根结点的颜色为黑色（可能被情况一变成了红色，需要变回黑色）

        return std::make_pair(iterator(newnode, _root), true); //插入成功
        //return { iterator(newnode, _root), true }; //插入成功
    }
private:
    //拷贝树
    Node* _Copy(Node* root, Node* parent)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        Node* copyNode = new Node(root->_data);
        copyNode->_parent = parent;
        copyNode->_left = _Copy(root->_left, copyNode);
        copyNode->_right = _Copy(root->_right, copyNode);
        return copyNode;
    }

    //析构函数子函数
    void _Destroy(Node* root)
    {
        if (root == nullptr)
        {
            return;
        }
        _Destroy(root->_left);
        _Destroy(root->_right);
        delete root;
    }

    //左单旋
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
            _root = subR;
            _root->_parent = nullptr;
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

    //右单旋
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
            _root = subL;
            _root->_parent = nullptr;
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

    Node* _root; //红黑树的根结点
};