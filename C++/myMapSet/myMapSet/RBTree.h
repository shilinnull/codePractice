#pragma once
#include<iostream>

using namespace std;

//ö�ٶ��������ɫ
enum Colour
{
    RED,
    BLACK
};

//��������Ķ���
template<class T>
struct RBTreeNode
{
    //������
    RBTreeNode<T>* _left;
    RBTreeNode<T>* _right;
    RBTreeNode<T>* _parent;

    //�洢������
    T _data;

    //������ɫ
    Colour _col; //��/��

    //���캯��
    RBTreeNode(const T& data)
        :_left(nullptr)
        , _right(nullptr)
        , _parent(nullptr)
        , _data(data)
        , _col(RED)
    {}
};

//���������
template<class T, class Ref, class Ptr>
struct __TreeIterator
{

    typedef RBTreeNode<T> Node; //��������
    typedef __TreeIterator<T, Ref, Ptr> Self; //���������������

    Node* _node; //�������������װ����ָ��
    Node* _root; //���ڵ�

    //���캯��
    __TreeIterator(Node* node, Node* root)
        :_node(node) //�����������ָ�빹��һ�����������
        , _root(root)
    {}

    Ref operator*()
    {
        return _node->_data; //���ؽ�����ݵ�����
    }
    Ptr operator->()
    {
        return &_node->_data; //���ؽ�����ݵ�ָ��
    }
    //�ж���������������Ƿ�ͬ
    bool operator!=(const Self& s) const
    {
        return _node != s._node; //�ж������������������װ�Ľ���Ƿ���ͬһ��
    }
    //�ж���������������Ƿ���ͬ
    bool operator==(const Self& s) const
    {
        return _node == s._node; //�ж������������������װ�Ľ���Ƿ���ͬһ��
    }

    //ǰ��++
    /*
    1. itָ��Ľڵ㣬��������Ϊ�գ���һ��������������ڵ�
    2. itָ��Ľڵ㣬������Ϊ�գ�it�еĽڵ����ڵ������������ˣ������Һ����Ǹ�������Ǹ�����
    */
    Self& operator++()
    {
        if (_node->_right) //������������Ϊ��
        {
            //Ѱ�Ҹý�����������е�������
            Node* left = _node->_right;
            while (left->_left)
            {
                left = left->_left;
            }
            _node = left; //++���Ϊ�ý��
        }
        else //����������Ϊ��
        {
            //Ѱ�Һ��Ӳ��ڸ����ҵ�����
            Node* cur = _node;
            Node* parent = cur->_parent;
            while (parent && cur == parent->_right)
            {
                cur = parent;
                parent = parent->_parent;
            }
            _node = parent; //++���Ϊ�ý��
        }
        return *this;
    }

    //ǰ��--
    Self& operator--()
    {
        if (_node == nullptr) // end()
        {
            // --end()�����⴦���ߵ��������һ����㣬�����������ҽ��
            Node* rightMost = _root;
            while (rightMost && rightMost->_right)
            {
                rightMost = rightMost->_right;
            }
            _node = rightMost;
        }
        else if (_node->_left) //������������Ϊ��
        {
            //Ѱ�Ҹý�����������е����ҽ��
            Node* right = _node->_left;
            while (right->_right)
            {
                right = right->_right;
            }
            _node = right; //--���Ϊ�ý��
        }
        else //����������Ϊ��
        {
            //Ѱ�Һ��Ӳ��ڸ����������
            Node* cur = _node;
            Node* parent = cur->_parent;
            while (parent && cur == parent->_left)
            {
                cur = parent;
                parent = parent->_parent;
            }
            _node = parent; //--���Ϊ�ý��
        }
        return *this;
    }
};


//�������ʵ��
template<class K, class T, class KeyOfT>
class RBTree
{
    KeyOfT kot; // ���ڱȽ�
    typedef RBTreeNode<T> Node; //��������
public:
    typedef __TreeIterator<T, T&, T*> iterator;
    typedef __TreeIterator<T, const T&, const T*> const_iterator; //const������

    iterator begin()
    {
        //Ѱ��������
        Node* left = _root;
        while (left && left->_left)
        {
            left = left->_left;
        }
        //��������������������
        return iterator(left, _root);
    }

    iterator end()
    {
        //������nullptr����õ�����������������Ͻ���
        return iterator(nullptr, _root);
    }

    const_iterator begin()const
    {
        //Ѱ��������
        Node* left = _root;
        while (left && left->_left)
        {
            left = left->_left;
        }
        //��������������������
        return const_iterator(left, _root);
    }
    const_iterator end()const
    {
        //������nullptr����õ�����������������Ͻ���
        return const_iterator(nullptr, _root);
    }
    //���캯��
    RBTree()
        :_root(nullptr)
    {}

    //��������
    RBTree(const RBTree<K, T, KeyOfT>& t)
    {
        _root = _Copy(t._root, nullptr);
    }

    //��ֵ��������أ��ִ�д����
    RBTree<K, T, KeyOfT>& operator=(RBTree<K, T, KeyOfT> t)
    {
        swap(_root, t._root);
        return *this; //֧��������ֵ
    }

    //��������
    ~RBTree()
    {
        _Destroy(_root);
        _root = nullptr;
    }

    //���Һ���
    iterator Find(const K& key)
    {
        KeyOfT kot;
        Node* cur = _root;
        while (cur)
        {
            if (key < kot(cur->_data)) //keyֵС�ڸý���ֵ
            {
                cur = cur->_left; //�ڸý������������в���
            }
            else if (key > kot(cur->_data)) //keyֵ���ڸý���ֵ
            {
                cur = cur->_right; //�ڸý������������в���
            }
            else //�ҵ���Ŀ����
            {
                return iterator(cur); //���ظý��
            }
        }
        return end(); //����ʧ��
    }

    //���뺯��
    pair<iterator, bool> Insert(const T& data)
    {
        if (_root == nullptr) //�������Ϊ�������������ֱ����Ϊ�����
        {
            _root = new Node(data);
            _root->_col = BLACK; //���������Ǻ�ɫ

            return std::make_pair(iterator(_root, _root), true);
            //return { iterator(_root, _root), true }; //����ɹ�
        }
        //1���������������Ĳ��뷽�����ҵ�������λ��
        Node* cur = _root;
        Node* parent = nullptr;
        while (cur)
        {
            if (kot(data) < kot(cur->_data)) //���������keyֵС�ڵ�ǰ����keyֵ
            {
                //���ý�����������
                parent = cur;
                cur = cur->_left;
            }
            else if (kot(data) > kot(cur->_data)) //���������keyֵ���ڵ�ǰ����keyֵ
            {
                //���ý�����������
                parent = cur;
                cur = cur->_right;
            }
            else //���������keyֵ���ڵ�ǰ����keyֵ
            {
                return std::make_pair(iterator(cur, _root), false);
                //return { iterator(cur, _root), false }; //����ɹ�
            }
        }

        //2��������������뵽����
        cur = new Node(data); //��������ֵ����һ�����
        Node* newnode = cur; //��¼�²���Ľ�㣨���ں��򷵻أ�
        if (kot(data) < kot(parent->_data)) //�½���keyֵС��parent��keyֵ
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

        //3����������ĸ�����Ǻ�ɫ�ģ�����Ҫ�Ժ�������е���
        while (parent && parent->_col == RED)
        {
            Node* grandfather = parent->_parent; //parent�Ǻ�ɫ�����丸���һ������
            if (parent == grandfather->_left) //parent��grandfather������
            {
                Node* uncle = grandfather->_right; //uncle��grandfather���Һ���
                if (uncle && uncle->_col == RED) //���1��uncle������Ϊ��
                {
                    //��ɫ����
                    parent->_col = uncle->_col = BLACK;
                    grandfather->_col = RED;

                    //�������ϴ���
                    cur = grandfather;
                    parent = cur->_parent;
                }
                else //���2+���3��uncle������ + uncle������Ϊ��
                {
                    if (cur == parent->_left)
                    {
                        RotateR(grandfather); //�ҵ���

                        //��ɫ����
                        grandfather->_col = RED;
                        parent->_col = BLACK;
                    }
                    else //cur == parent->_right
                    {
                        RotateLR(grandfather); //����˫��

                        //��ɫ����
                        grandfather->_col = RED;
                        cur->_col = BLACK;
                    }
                    break; //������ת�󣬸������ĸ�����˺�ɫ������������Ͻ��д���
                }
            }
            else //parent��grandfather���Һ���
            {
                Node* uncle = grandfather->_left; //uncle��grandfather������
                if (uncle && uncle->_col == RED) //���1��uncle������Ϊ��
                {
                    //��ɫ����
                    uncle->_col = parent->_col = BLACK;
                    grandfather->_col = RED;

                    //�������ϴ���
                    cur = grandfather;
                    parent = cur->_parent;
                }
                else //���2+���3��uncle������ + uncle������Ϊ��
                {
                    if (cur == parent->_left)
                    {
                        RotateRL(grandfather); //����˫��

                        //��ɫ����
                        cur->_col = BLACK;
                        grandfather->_col = RED;
                    }
                    else //cur == parent->_right
                    {
                        RotateL(grandfather); //����

                        //��ɫ����
                        grandfather->_col = RED;
                        parent->_col = BLACK;
                    }
                    break; //������ת�󣬸������ĸ�����˺�ɫ������������Ͻ��д���
                }
            }
        }
        _root->_col = BLACK; //��������ɫΪ��ɫ�����ܱ����һ����˺�ɫ����Ҫ��غ�ɫ��

        return std::make_pair(iterator(newnode, _root), true); //����ɹ�
        //return { iterator(newnode, _root), true }; //����ɹ�
    }
private:
    //������
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

    //���������Ӻ���
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

    //����
    void RotateL(Node* parent)
    {
        Node* subR = parent->_right;
        Node* subRL = subR->_left;
        Node* parentParent = parent->_parent;

        //����subRL��parent֮�����ϵ
        parent->_right = subRL;
        if (subRL)
            subRL->_parent = parent;

        //����parent��subR֮�����ϵ
        subR->_left = parent;
        parent->_parent = subR;

        //����subR��parentParent֮�����ϵ
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

    //�ҵ���
    void RotateR(Node* parent)
    {
        Node* subL = parent->_left;
        Node* subLR = subL->_right;
        Node* parentParent = parent->_parent;

        //����subLR��parent֮�����ϵ
        parent->_left = subLR;
        if (subLR)
            subLR->_parent = parent;

        //����parent��subL֮�����ϵ
        subL->_right = parent;
        parent->_parent = subL;

        //����subL��parentParent֮�����ϵ
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

    //����˫��
    void RotateLR(Node* parent)
    {
        RotateL(parent->_left);
        RotateR(parent);
    }

    //����˫��
    void RotateRL(Node* parent)
    {
        RotateR(parent->_right);
        RotateL(parent);
    }

    Node* _root; //������ĸ����
};