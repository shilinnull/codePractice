#pragma once

#include <iostream>
#include <stdlib.h>
#include <assert.h>

using namespace std;

namespace lsl
{
	template<class T>
	class vector {
		// vector �ĵ�������ԭ��ָ��
		typedef T* iterator;
		typedef const T* const_iterator;
	public:
		/// <summary>
		/// ������
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
		/// ����������
		/// </summary>
		vector()
		{}
		vector(size_t n, const T& val = T()) {
			resize(n, val);
		}

		/*
		* �������ṩ��vector(size_t n, const T& value = T())֮��
		* vector(int n, const T& value = T())�Ͳ���Ҫ�ṩ�ˣ����Ƕ��ڣ�
		* vector<int> v(10, 5);
		* �������ڱ���ʱ����ΪT�Ѿ���ʵ����Ϊint����10��5��������Ĭ����Ϊint����
		* �Ͳ�����vector(size_t n, const T& value = T())������췽����
		* ����ѡ����ǣ�vector(InputIterator first, InputIterator last)
		* ��Ϊ�������������乹��������������һ�£���˱������ͻὫInputIteratorʵ����Ϊint
		* ����10��5��������һ�����䣬����ʱ�ͱ�����
		* ����Ҫ���Ӹù��췽��
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
			// �ȿ��ռ�
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
		/// �������
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
			// ��������Ƿ���
			if (_finish == _end_of_storage) {

				size_t oldSize = size(); // ����ɵ�����
				T* tmp = new T[n];
				// ����ʹ��memcpy�������ǳ����
				//if(_start)
				//	memcpy(tmp, _start, sizeof(T) * oldSize);
				
				if (_start)
					for (size_t i = 0; i < oldSize; i++)
						tmp[i] = _start[i]; // ��������ֱ�Ӹ�ֵ���Զ������͵������ĸ�ֵ����

				// �ͷ�ԭ���Ŀռ�
				delete[] _start;

				// �ı�ָ��
				_start = tmp;
				_finish = _start + oldSize;
				_end_of_storage = _start + n;
			}
		}
		
		void resize(size_t n, const T& val = T()) {
			// �����size()Сֱ�Ӹı�_finish
			if (n < size())
				_finish = _start + n;
			else {
				// ��������
				reserve(n);
				// ����n��val
				while (_finish != _start + n)
					*_finish++ = val;
			}
		}

		/// <summary>
		/// ��ɾ���
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

			// ����������,�ᵼ�µ�����ʧЧ,��Ҫ���¸���һ��pos
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

		// ����ɾ�����ݵ���һ�����ݣ����:һ�߱���һ��ɾ���ĵ�����ʧЧ����
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