#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<deque>
#include<queue>
#include<vector>
#include<functional>
using namespace std;


namespace lsl
{
	template<class T, class Container = deque<T>>
	class stack
	{
	public:
		stack() {}
		void push(const T& x) {
			_c.push_back(x);
		}
		void pop() {
			_c.pop_back();
		}
		T& top() {
			return _c.back();
		}
		const T& top()const {
			return _c.back();
		}
		size_t size()const {
			return _c.size();
		}
		bool empty()const {
			return _c.empty();
		}
	private:
		Container _c;
	};

	template<class T, class Container = deque<T>>
	class queue
	{
	public:
		void push(const T& x) {
			_c.push_back(x);
		}

		void pop() {
			_c.pop_front();
		}

		const T& front() {
			return _c.front();
		}

		const T& back() {
			return _c.back();
		}

		size_t size() {
			return _c.size();
		}

		bool empty() {
			return _c.empty();
		}

	private:
		Container _c;
	};


	// -----------------------------------------------------------------

	template<class T>
	struct less {
		bool operator()(const T& left, const T& right) {
			return left < right;
		}
	};

	template<class T>
	struct greater {
		bool operator()(const T& left, const T& right) {
			return left > right;
		}
	};


	template <class T, class Container = vector<T>, class Compare = less<T> >
	class priority_queue
	{
	public:
		priority_queue() {}
		template <class InputIterator>
		priority_queue(InputIterator first, InputIterator last)
			:c(first, last)
		{
			//将c中的元素调整为堆的结构，默认为大堆
			int count = c.size();
			int root = ((count - 2) >> 1);
			for (; root >= 0; root--)
				AdjustDown(root);
		}
		bool empty() const {
			return c.empty();
		}

		size_t size() const {
			return c.size();
		}

		const T& top() const {
			return c[0];
		}

		void push(const T& x) {
			c.push_back(x);
			adjust_up(c.size() - 1);
		}

		void pop() {
			std::swap(c[0], c[c.size() - 1]);
			c.pop_back();
			adjust_down(0);
		}

		void adjust_up(size_t child) {
			size_t parent = (child - 1) / 2;

			while (child > 0)
			{
				if (comp(c[parent], c[child])) {
					std::swap(c[parent], c[child]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else {
					break;
				}
			}
		}

		void adjust_down(size_t parent) {
			size_t child = parent * 2 + 1;

			while (child < c.size()) {
				if (child + 1 < c.size() && comp(c[child], c[child + 1]))
					child++;
				// 注意比较 父亲比孩子小就向下调整
				if (comp(c[parent], c[child])) {
					std::swap(c[child], c[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else {
					break;
				}
			}
		}
	private:
		Container c;
		Compare comp;
	};
	void test_priority_queue() {
		priority_queue<int, vector<int>, greater<int>> pq;
		pq.push(2);
		pq.push(1);
		pq.push(4);
		pq.push(3);
		pq.push(7);
		pq.push(8);
		while (!pq.empty())
		{
			cout << pq.top() << " ";
			pq.pop();
		}
		cout << endl;
	}
};