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

		Ref* operator*() {
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
	class vector {
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		// 反向迭代器适配支持
		typedef Reverse_iterator<iterator, T&, T*> reverse_iterator;
		typedef Reverse_iterator<const_iterator, const T&, const T*> const_reverse_iterator;
	private:

		const_reverse_iterator rbegin() const {
			return const_reverse_iterator(end());
		}

		const_reverse_iterator rend() const {
			return const_reverse_iterator(begin());
		}

		reverse_iterator rbegin() {
			return reverse_iterator(end());
		}

		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}

	};

	template<class T>
	class list {

		typedef list_node<T> Node;
	public:
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;

		// 反向迭代器适配支持
		typedef Reverse_iterator<iterator, T&, T*> reverse_iterator;
		typedef Reverse_iterator<const_iterator, const T&, const T*> const_reverse_iterator;

	};

	reverse_iterator rbegin()
	{
		return reverse_iterator(end());
	}

	reverse_iterator rend()
	{
		return reverse_iterator(begin());
	}

}