#pragma once

#include <iostream>
#include <assert.h>
#include <string.h>

namespace lsl {
	template<class T>
	class vector {
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		
		iterator begin() {
			return _start;
		} 
		const_iterator begin() const {
			return _start;
		}

		iterator end() {
			return _finish;
		}
		const_iterator end() const {
			return _finish;
		}
		
		size_t capacity() const {
			return _endofstorage - _finish;
		}
		size_t size() const {
			return _finish - _start;
		}

		T& operator[](size_t pos) {
			assert(pos < size());
			return _start[pos];
		}

		const T& operator[](size_t pos) const {
			assert(pos < size());
			return _start[pos];
		}

		vector(const vector<T>& v) {
			reserve(v.capacity());
			for (auto& e : v) {
				push_back(e);
			}
		}

		vector(){}
		
		void reserve(size_t n) {
			if (n > capacity()) {
				// size要提前保存一下
				size_t old_size = size();
				T* tmp = new T[n];
				
				// 拷贝数据+释放原空间
				memcpy(tmp, _start, size() * sizeof(T));
				delete[] _start;

				// 进行替换
				_start = tmp;
				// _finish = tmp +size(); // 错
				_finish = tmp + old_size;
				_endofstorage = tmp + n;
			}
		}

		void resize(size_t n,const T& val = T()) {
			if (n > size()) {
				reserve(n);
				while (_finish < _start + n) {
					*_finish = val;
					++_finish;
				}
			}else{
				// 更新有效个数
				_finish = _start + n;
			}
		}

		void push_back(const T& val) {
			// 检查
			//if (_finish == _endofstorage) {
			//	// 扩容
			//	reserve(capacity() == 0 ? 4 : 2 * capacity());
			//}
			//*_finish = val;
			//++_finish;
			insert(end(), val);
		}
		
		bool empty() const {
			return _start == _finish;
		}
		
		void pop_back() {
			//assert(!empty());
			//--_finish;
			earse(--end());
		}
		
		void insert(iterator pos, const T& val) {
			assert(pos >= _start && pos <= _finish);
			if (_finish == _endofstorage) {
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : 2 * capacity());
				pos = _start + len;
			}

			iterator it = _finish - 1;
			while (it >= pos) {
				*(it + 1) = *it;
				--it;
			}
			*pos = val;
			++_finish;
		}
		
		void erase(iterator pos) {
			assert(pos >= _start && pos <= _finish);
			iterator it = pos + 1;
			while (it < _finish) {
				*(it - 1) = *it;
				++it;
			}
			--_finish;
		}

		//~vector() {
		//	delete[] _start;
		//	_start = _finish = _endofstorage = nullptr;
		//}

	private:
		// 开始元素的位置
		iterator _start = nullptr;
		// 最后元素的位置
		iterator _finish = nullptr;
		// 容量
		iterator _endofstorage = nullptr;
	};

	template<class T>
	void print_vector(const vector<T>& v) {
	/*	for (size_t i = 0; i < v.size(); i++){
			std::cout << v[i] << " ";
		}
		std::cout << std::endl;*/
		//typename vector<T>::const_iterator it = v.begin();
		// auto it = v.begin();
		//while (it != v.end()) {
		//	std::cout << *it << " ";
		//	++it;
		//}
		//std::cout << std::endl;

		for (auto e : v) {
			std::cout << e << " ";
		}
		std::cout << std::endl;
	}
}
