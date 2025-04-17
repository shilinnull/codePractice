#pragma once

namespace lsl
{
	template<class Iterator, class Ref, class Ptr>
	struct ReverseIterator
	{
		typedef ReverseIterator<Iterator, Ref, Ptr> Self;

		ReverseIterator(Iterator it)
			:_it(it)
		{
		}

		Ref operator*()
		{
			Iterator tmp = _it;
			return *--tmp;
		}

		Ptr operator->()
		{
			return &(operator*());
		}

		Self& operator++()
		{
			--_it;
			return *this;
		}

		Self operator++(int)
		{
			Self temp(*this);
			--_it;
			return temp;
		}

		Self& operator--()
		{
			++_it;
			return *this;
		}

		Self operator--(int)
		{
			Self temp(*this);
			++_it;
			return temp;
		}

		bool operator!=(const Self& s)
		{
			return _it != s._it;
		}

		bool operator==(const Self& s)
		{
			return _it == s._it;
		}

		Iterator _it;
	};
}
