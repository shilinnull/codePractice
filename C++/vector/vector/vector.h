#pragma once

#include <iostream>
#include <stdlib.h>
#include <assert.h>

using namespace std;

namespace lsl
{
	template<class T>
	class vector {
		// vector 的迭代器是原生指针
		typedef T* iterator;
		typedef const T* const_iterator;
	public:
		/// <summary>
		/// 迭代器
		/// </summary>
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

		/// <summary>
		/// 构造与析构
		/// </summary>
		vector()
		{}
		vector(size_t n, const T& val = T()) {
			resize(n, val);
		}

		/*
		* 理论上提供了vector(size_t n, const T& value = T())之后
		* vector(int n, const T& value = T())就不需要提供了，但是对于：
		* vector<int> v(10, 5);
		* 编译器在编译时，认为T已经被实例化为int，而10和5编译器会默认其为int类型
		* 就不会走vector(size_t n, const T& value = T())这个构造方法，
		* 最终选择的是：vector(InputIterator first, InputIterator last)
		* 因为编译器觉得区间构造两个参数类型一致，因此编译器就会将InputIterator实例化为int
		* 但是10和5根本不是一个区间，编译时就报错了
		* 故需要增加该构造方法
		*/
		vector(int n, const T& val = T()) {
			resize(n, val);
		}

		template<class InputIterator>
		vector(InputIterator first, InputIterator last) {
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		vector(initializer_list<T> il) {
			reserve(il.size());
			for (auto& e : il)
				push_back(e);
		}

		vector(const vector<T>& v) {
			// 先开空间
			reserve(v.capacity());
			for (const auto& e : v)
				push_back(e);
		}
		
		void Swap(vector<T>& v) {
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_start, v._start);
		}

		vector<T>& operator=(const vector<T> v) {
			Swap(v);
			return *this;
		}

		~vector()
		{
			if (_start) {
				delete[] _start;
				_start = _finish = _end_of_storage = nullptr;
			}
		}

		/// <summary>
		/// 容量相关
		/// </summary>
		size_t size() const {
			return _finish - _start;
		}

		size_t capacity() const {
			return _end_of_storage - _start;
		}
		
		bool empty() const
		{
			return _start == _finish;
		}

		void reserve(size_t n)
		{
			// 检查容量是否满
			if (_finish == _end_of_storage) {

				size_t oldSize = size(); // 保存旧的数据
				T* tmp = new T[n];
				// 不能使用memcpy，会造成浅拷贝
				//if(_start)
				//	memcpy(tmp, _start, sizeof(T) * oldSize);
				
				if (_start)
					for (size_t i = 0; i < oldSize; i++)
						tmp[i] = _start[i]; // 内置类型直接赋值，自定义类型调用它的赋值重载

				// 释放原来的空间
				delete[] _start;

				// 改变指针
				_start = tmp;
				_finish = _start + oldSize;
				_end_of_storage = _start + n;
			}
		}
		
		void resize(size_t n, const T& val = T()) {
			// 如果比size()小直接改变_finish
			if (n < size())
				_finish = _start + n;
			else {
				// 扩容数据
				reserve(n);
				// 拷贝n个val
				while (_finish != _start + n)
					*_finish++ = val;
			}
		}

		/// <summary>
		/// 增删查改
		/// </summary>
		T& operator[](size_t i) {
			assert(i < size());
			return _start[i];
		}
		
		const T& operator[](size_t i) const {
			assert(i < size());
			return _start[i];
		}
		T& front()
		{
			return *_start;
		}

		const T& front()const
		{
			return *_start;
		}

		T& back()
		{
			return *(_finish - 1);
		}

		const T& back()const
		{
			return *(_finish - 1);
		}

		iterator insert(iterator pos, const T& x) {
			assert(pos >= _start);
			assert(pos <= _finish);

			// 发生了扩容,会导致迭代器失效,需要重新更新一下pos
			if (_finish == _end_of_storage) {
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : capacity() * 2);
				pos = _start + len;
			}

			iterator it = _finish - 1;
			while (it >= pos)
			{
				*(it + 1) = *it;
				--it;
			}

			*pos = x;
			++_finish;
			return pos;
		}

		// 返回删除数据的下一个数据，解决:一边遍历一边删除的迭代器失效问题
		iterator erase(iterator pos) {
			assert(pos >= _start);
			assert(pos < _finish);
			iterator it = pos + 1;
			while (it < _finish)
			{
				*(it - 1) = *it;
				++it;
			}
			--_finish;
			return pos;
		}

		void push_back(const T& x) {
			insert(end(), x);
		}
		//void push_back(const T& x) {
		//	if (_finish == _end_of_storage)
		//		reserve(capacity() == 0 ? 4 : capacity() * 2);
		//	*_finish++ = x;
		//}

		void pop_back() {
			erase(end() - 1);
		}

	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _end_of_storage = nullptr;
	};
}