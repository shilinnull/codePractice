#pragma once

#include <iostream>
#include <stdlib.h>
#include <assert.h>

using namespace std;

namespace lsl 
{
	template<class T>
	class vector {
		typedef T* iterator;
		typedef const T* const_iterator;
	public:
		iterator begin() {
			return _start;
		}
		iterator end() {
			return _finish;
		}
		const_iterator begin() const {
			return _start;
		}
		const_iterator end() const {
			return _finish;
		}

		vector()
			:_start(nullptr), _finish(nullptr), _end_of_storage(nullptr) 
		{}
		~vector()
		{
			delete[] _start;
			_start = _finish = _end_of_storage = nullptr;
		}

		size_t size() const {
			return _finish - _start;
		}
		size_t capacity() const {
			return _end_of_storage - _start;
		}

		void reserve(size_t n) 
		{
			if (_finish == _end_of_storage) {
				size_t oldSize = size(); // 保存旧的数据
				T* tmp = new T[n];
				memcpy(tmp, _start, sizeof(T) * oldSize);
				delete[] _start;

				_start = tmp;
				_finish = _start + oldSize;
				_end_of_storage = _start + n;
			}
		}
		void push_back(const T& x) {
			if (_finish == _end_of_storage)
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			*_finish++ = x;
		}

		T& operator[](size_t i) {
			assert(i < size());
			return _start[i];
		}



	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};




}






