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

template<class T, class Ref, class Ptr>
class __TreeIterator
{
public:
    typedef RBTreeNode<T> Node;
    typedef __TreeIterator<T, Ref, Ptr> Self;

    Node* _node;
    Node* _root;

    __TreeIterator(Node* node, Node* root)
        :_node(node)
        ,_root(root)
    {}

    Ref operator*()
    {
        return _node->_data;
    }

    Ptr operator->()
    {
        return &_node->_data;
    }

    bool operator!=(const Self& s) const
    {
        return _node != s._node;
    }
    bool operator==(const Self& s) const
    {
        return !(_node != s._node);
    }

    Self& operator++()
    {
        if (_node->_right)
        {
            _node = _node->_right;
            while (_node->_left)
                _node = _node->_left;
        }
        else
        {
            //Ѱ�Һ��Ӳ��ڸ����ҵ�����
            Node* cur = _node;
            Node* parent = cur->_parent;
            while (parent && parent->_right == cur)
            {
                cur = parent;
                parent = parent->_parent;
            }
            _node = parent;
        }
        return *this;
    }

    Self& operator--()
    {
        if (_node == nullptr) // end()
        {
            // --end()�����⴦���ߵ��������һ����㣬�����������ҽ��
            Node* right = _root;
            while (right && right->_right)
                right = right->_right;
            _node = right;
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
    typedef RBTreeNode<T> Node;
public:
    typedef __TreeIterator<T, T&, T*> iterator;
    typedef __TreeIterator<T, const T&, const T*> const_iterator;

    iterator begin()
    {
        Node* cur = _root;
        while (cur && cur->_left)
            cur = cur->_left;
        return iterator(cur, _root);
    }
    
    iterator end()
    {
        return iterator(nullptr, _root);
    } 

    const_iterator begin() const
    {
        Node* cur = _root;
        while (cur && cur->_left)
            cur = cur->_left;
        return const_iterator(cur, _root);
    }
    
    const_iterator end() const 
    {
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
        std::swap(_root, t._root);
        return *this;
    }

    //��������
    ~RBTree()
    {
        _Destroy(_root);
        _root = nullptr;
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
    
    // �������
    void InOrder()
    {
        _InOrder(_root);
        cout << endl;
    }

    // ����Ƿ�Ϊ�����
    bool IsBalance()
    {
        if (_root == nullptr)
            return true;

        if (_root->_col == RED)
            return false;

        //�ο�ֵ
        int refVal = 0;
        Node* cur = _root;
        while (cur)
        {
            if (cur->_col == BLACK)
            {
                ++refVal;
            }

            cur = cur->_left;
        }

        int blacknum = 0;
        return Check(_root, blacknum, refVal);
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

    // ���ڵ�->��ǰ�ڵ�����·���ĺ�ɫ�ڵ������
    bool Check(Node* root, int blacknum, const int refVal)
    {
        if (root == nullptr)
        {
            //cout << balcknum << endl;
            if (blacknum != refVal)
            {
                cout << "���ں�ɫ�ڵ���������ȵ�·��" << endl;
                return false;
            }

            return true;
        }

        if (root->_col == RED && root->_parent && root->_parent->_col == RED)
        {
            cout << "�������ĺ�ɫ�ڵ�" << endl;

            return false;
        }

        if (root->_col == BLACK)
        {
            ++blacknum;
        }

        return Check(root->_left, blacknum, refVal)
            && Check(root->_right, blacknum, refVal);
    }

    // �������
    void _InOrder(Node* root)
    {
        if (root == nullptr)
            return;

        _InOrder(root->_left);
        cout << root->_kv.first << " ";
        _InOrder(root->_right);
    }

    Node* _root; //������ĸ����
};