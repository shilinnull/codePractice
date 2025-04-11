#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

namespace lsl
{
	template<class T>
	struct ListNode
	{
		T _val;
		struct ListNode<T>* _next;
		struct ListNode<T>* _prev;
		ListNode(const T& x = T())
			:_val(x)
			, _next(nullptr)
			, _prev(nullptr)
		{
		}
	};

	/// <summary>
	/// 迭代器
	/// </summary>
	template<class T,class Ref,class Ptr>
	struct list_iterator
	{
		typedef ListNode<T> Node;
		typedef list_iterator<T, Ref, Ptr> Self;
		Node* _node;

		list_iterator(Node* node)
			:_node(node)
		{
		}

		Ref operator*()
		{
			return _node->_val;
		}

		Ptr operator->()
		{
			return &_node->_val;
		}

		Self operator++()
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

		bool operator!=(const Self& it) const 
		{
			return _node != it._node;
		}

		bool operator==(const Self& it) const
		{
			return _node == it._node;
		}
	};

	template<class T>
	class list
	{
		typedef ListNode<T> Node;
	public:
		typedef list_iterator<T, T&, T*> iterator;
		typedef list_iterator<T, const T&, const T*> const_iterator;
		
		iterator begin() 
		{
			return iterator(_head->_next);
		}
		
		iterator end()
		{
			return iterator(_head);
		}
		
		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}
		
		const_iterator end() const 
		{
			return const_iterator(_head);
		}

		/// <summary>
		/// 构造与析构
		/// </summary>
		void empty_init(const T& val = T()) {
			_head = new Node(val);
			_head->_next = _head;
			_head->_prev = _head;

			_size = 0;
		}
		
		list()
		{
			empty_init();
		}

		list(const T& val)
		{
			empty_init(val);
		}
		
		list(size_t n, const T& val)
		{
			empty_init();
			for (size_t i = 0; i < n; i++)
			{
				push_back(val);
			}
		}

		list(const list<T>& lt) 
		 {
			empty_init();
			for (auto& e : lt)
				push_back(e);
		}

		void swap(list<T>& lt) {
			std::swap(_head, lt._head);
			std::swap(_size, lt._size);
		}

		list<T>& operator=(list<T> lt) {
			swap(lt);
			return *this;
		}

		list(initializer_list<T> lt) {
			empty_init();
			for (auto& e : lt) {
				push_back(e);
			}
		}

		void clear() {
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}

		size_t size() const {
			return _size;
		}

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		/// <summary>
		/// 增删查改
		/// </summary>

		void insert(iterator pos, const T& val) {
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* newnode = new Node(val);
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;

			++_size;
		}

		iterator erase(iterator pos) {
			assert(pos != end());
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;
			prev->_next = next;
			next->_prev = prev;

			delete cur;
			cur = nullptr;

			--_size;
			return iterator(next);
		}

		void push_back(const T& val) {
			insert(end(), val);
		}
		
		void push_front(const T& val) {
			insert(begin(), val);
		}

		void pop_back() {
			erase(--end());
		}
		
		void pop_front() {
			erase(begin());
		}

	private:
		Node* _head;
		size_t _size;
	};
}