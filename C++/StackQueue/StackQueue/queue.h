#pragma once
#include <list>
#include <iostream>

namespace lsl
{
	template<class T,class Con = deque<T>>
	class queue
	{
	public:
		void push(const T& x) {
			_con.push_back(x);
		}

		void pop() {
			_con.pop_front();
		}

		const T& front() {
			return _con.front();
		}

		const T& back() {
			return _con.back();
		}

		size_t size() const {
			return _con.size();
		}
		
		bool empty() const {
			return _con.empty();
		}
	private:
		Con _con;
	};
}
