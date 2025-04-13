#pragma once
#include <iostream>
#include <deque>
#include <vector>
using namespace std;


namespace lsl 
{
	template<class T>
	struct Less {
		bool operator()(const T& x, const T& y)
		{
			return x < y;
		}
	};

	template<class T>
	struct Greater {
		bool operator()(const T& x, const T& y)
		{
			return x > y;
		}
	};
	
	template<class T,class Container = std::vector<T>, class Compare = Less<T>>
	class priority_queue
	{
	public:
		priority_queue() = default;

		template<class Iterator>
		priority_queue(Iterator first, Iterator last)
			: _con(first, last)
		{
			// 将_con中的元素调整成堆的结构
			int count = _con.size();
			int root = ((count - 2) >> 1);
			for (; root >= 0; root--)
				AdjustDown(root);
		}

		void push(const T& x) {
			_con.push_back(x);
			AsjustUp(_con.size() - 1);
		}

		void pop() {
			if (empty())
				return;

			std::swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			AdjustDown(0);
		}

		const T& top() const {
			return _con.front();
		}

		size_t size() const {
			return _con.size();
		}

		bool empty() const {
			return _con.empty();
		}

	private:
		void AsjustUp(size_t child) {
			Compare com;
			size_t parent = (child - 1) / 2;

			while (child > 0)
			{
				if (com(_con[parent], _con[child]))
				{
					std::swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
					break;
			}
		}

		void AdjustDown(size_t parent) {
			Compare com;
			size_t child = parent * 2 + 1;

			while (child < _con.size())
			{
				if (child + 1 < _con.size() && com(_con[child], _con[child + 1]))
					++child;
				if (com(_con[parent], _con[child]))
				{
					std::swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else break;
			}
		}

		Container _con;
	};
}