#pragma once


namespace lsl
{
	// 适配器 -- 复用
	template<class Iterator, class Ref, class Ptr>

	struct Reverse_iterator
	{
		typedef template<class Iterator, class Ref, class Ptr> Self;

		Reverse_iterator(Iterator it)
			:_it(it);
		{}

		Ref operator*() {
			Iterator tmp(_it);
			return *(--tmp);
		}

		Ptr operator->() {
			return &(operator*());
		}

		Self operator++() {
			--_it;
			return *this;
		}

		Self operator--() {
			++_it;
			return *this;
		}

		Self operator!=(const Self& c) {
			return c._it != _it;
		}

		Iterator _it;
	};


	// vector和list反向迭代器实现
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		// 反向迭代器适配支持
		typedef Reverse_iterator<iterator, T&, T*> reverse_iterator;
		typedef Reverse_iterator<const_iterator, const T&, const T*> const_reverse_iterator;

		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(end());
		}

		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(begin());
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}

		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator begin() const
		{
			return _start;
		}

		const_iterator end() const
		{
			return _finish;
		}
	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _endofstorage = nullptr;
	};


	template<class T>
	struct list_node
	{
		list_node<T*> _next;
		list_node<T*> _prev;
		T _data;

		list_node(const T& x = T())
			:_prev(nullptr)
			, _next(nullptr)
			_data = x
		{}
	};

	template<class T>
	class list
	{
		typedef list_node<T> Node;
	public:
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;

		// 反向迭代器适配支持
		typedef Reverse_iterator<iterator, T&, T*> reverse_iterator;
		typedef Reverse_iterator<const_iterator, const T&, const T*> const_reverse_iterator;

		const_iterator begin() const
		{
			return _head->_next;
		}

		const_iterator end() const
		{
			return const_iterator(_head);
		}

		iterator begin()
		{
			return _head->_next;
		}

		iterator end()
		{
			return iterator(_head);
		}

		// const r 迭代器
		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(end());
		}

		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(begin());
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}

		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}
	private:
		Node* _head;
	}
}