#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

namespace lsl 
{
	// 节点
	template<class T>
	struct ListNode 
	{
		ListNode<T>* _next;
		ListNode<T>* _prev;
		T _val;

		ListNode(const T& x = T())
			:_next(nullptr)
			, _prev(nullptr)
			, _val(x)
		{}
	};

	// 迭代器
	template<class T,class Ref,class Ptr>
	class ListIterator
	{
	public:
		typedef ListNode<T> Node;
		typedef ListIterator<T, Ref, Ptr> Self;

		// 哨兵位的头节点
		Node* _node;

		ListIterator(Node* node)
			:_node(node)
		{}

		Ref operator*()
		{
			// 直接返回值
			return _node->_val;
		}

		Ptr operator->()
		{
			return &_node->_val;
		}

		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		Self operator++(int)
		{
			Self tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		Self operator--(int)
		{
			Self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}
		
		bool operator!=(const Self& it)
		{
			// 比较的是节点的指针
			return _node != it._node;
		}

		bool operator==(const Self& it)
		{
			return _node == it._node;
		}
	};

	// const迭代器初代版本
	/*
	template<class T>
	class ListConstIterator
	{
	public:
		typedef ListNode<T> Node;
		typedef ListConstIterator<T> Self;
		// 哨兵位的头节点
		Node* _node;

		// 构造
		ListConstIterator(Node* node)
			:_node(node)
		{}

		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		Self operator++(int)
		{
			Self tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		Self operator--(int)
		{
			Self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}

		// 返回的是const别名
		const T& operator*()
		{
			return _node->_val;
		}

		const T* operator->()
		{
			return &_node->_val;
		}

		bool operator!=(const Self& it)
		{
			// 比较的是节点的指针
			return _node != it._node;
		}

		bool operator==(const Self& it)
		{
			return _node == it._node;
		}
	};
	*/

	template<class T>
	class list {
		typedef ListNode<T> Node;
	public:
		//typedef ListIterator<T> iterator;
		//typedef ListConstIterator<T> const_iterator;

		typedef ListIterator<T, T&, T*> iterator;
		typedef ListIterator<T, const T&, const T*> const_iterator;

		void empty_init()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
			_size = 0;
		}

		list()
		{
			empty_init();
		}
		
		list(const list<T>& lt)
		{
			empty_init();
			for (auto e : lt)
			{
				push_back(e);
			}
		}

		void swap(list<T>& lt)
		{
			std::swap(_head, lt._head);
			std::swap(_size, lt._size);
		}

		list<T>& operator=(list<T> lt)
		{
			swap(lt);
			return *this;
		}

		iterator begin()
		{
			return iterator(_head->_next);
			// return _head->_next;
		}

		iterator end()
		{
			// return iterator(_head);
			return _head;
		}

		// const迭代器
		const_iterator begin() const
		{
			return _head->_next;
		}

		const_iterator end() const
		{
			return _head;
		}

		void push_back(const T& x) 
		{
			//Node* newnode = new Node(x);
			//Node* tail = _head->_prev;

			//// 连接
			//tail->_next = newnode;
			//newnode->_prev = tail;
			//newnode->_next = _head;
			//_head->_prev = newnode;
			insert(end(), x);
		}

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void pop_back()
		{
			// end是最后一个的下一个位置，所以就需要先--
			erase(--end());
		}

		void pop_front()
		{
			erase(begin());
		}

		void insert(iterator pos, const T& val)
		{
			Node* cur = pos._node;
			Node* newnode = new Node(val);
			Node* prev = cur->_prev;

			// 链接 prev newnode cur
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
			++_size;
		}

		iterator erase(iterator pos)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;

			// 删除 prev cur next
			prev->_next = next;
			next->_prev = prev;
			delete cur;
			--_size;
			// 返回下一个位置的迭代器
			return iterator(next);
		}

		size_t size() const
		{
			return _size;
		}

		bool empty()
		{
			return _size == 0;
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}
	private:
		Node* _head;
		size_t _size;
	};

	void test_list1() {
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);


		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		lt.push_back(10);
		lt.push_back(20);
		lt.push_back(30);
		lt.push_back(40);
		lt.push_front(100);
		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		lt.pop_back();
		lt.pop_back();
		lt.pop_front();
		lt.pop_front();

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;
	}
	
	struct A
	{
		int _a1;
		int _a2;

		A(int a1 = 0, int a2 = 0)
			:_a1(a1)
			,_a2(a2)
		{}
	};


	void test_list2() {
		list<A> lt;
		A aa1(1, 1);
		A aa2 = { 3,4 };
		lt.push_back(aa1);
		lt.push_back(aa2);
		lt.push_back(A(2, 3));
		lt.push_back({ 3,3 });
		lt.push_back({ 4,4 });
		A* ptr = &aa1;

		list<A>::iterator it = lt.begin();
		while (it != lt.end())
		{
			// cout << (*it)._a1 << ":" << (*it)._a2 << "\n";
			cout << it->_a1 << ":" << it->_a2 << endl;
			++it;
		}
		cout << endl;
	}

	void printList(const list<int>& clt)
	{
		list<int>::const_iterator it = clt.begin();
		while (it != clt.end())
		{
			// *it += 10;
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

	void test_list3() 
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_back(5);
		printList(lt);
		list<int> lt1(lt);
		printList(lt);
		list<int> lt2;

		lt2 = lt;
		printList(lt);


	}
}