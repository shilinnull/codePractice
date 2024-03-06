#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <iostream>
#include <string.h>
#include <assert.h>

using namespace std;

namespace lsl {
	class string {
	public:
		typedef char* iterator;
		typedef const char* const_iterator;
		iterator begin() {
			return _str;
		}
		iterator end() {
			return _str + _size;
		}
		const_iterator begin() const {
			return _str;
		}
		const_iterator end() const {
			return _str + _size;
		}
		const char* c_str() {
			return _str;
		}
		size_t size() const {
			return _size;
		}
		size_t capacity()const {
			return _capacity;
		}
		string(const char* str = "")
			:_size(strlen(str))
		{
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		string(const string& s) {
			_str = new char[s._capacity + 1];
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;
		}
		char& operator[](size_t pos) {
			assert(pos < _size);
			return _str[pos];
		}
		const char& operator[](size_t pos) const {
			assert(pos < _size);
			return _str[pos];
		}
		string& operator+=(char ch) {
			push_back(ch);
			return *this;
		}
		string& operator+=(const char* str) {
			append(str);
			return *this;
		}
		string& operator=(const string& s) {
			char* tmp = new char[s._capacity + 1];
			strcpy(tmp, s._str);
			delete[] _str;
			_str = tmp;
			_size = s._size;
			_capacity = s._capacity;
			return *this;
		}
		void reserve(size_t n) {
			if (n > _capacity) {
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}
		void push_back(char ch) {
			if (_size == _capacity) {
				reserve(_capacity == 0 ? 4 : 2 * _capacity);
			}
			_str[_size++] = ch;
			_str[_size] = '\0';
		}
		void append(const char* str) {
			assert(str);
			size_t len = strlen(str);
			if (_size + len > _capacity) {
				reserve(_size + len);
			}
			strcpy(_size + _str, str);
			_size += len;
		}
		void insert(size_t pos, char ch) {
			assert(pos <= _size);
			if (_size == _capacity) {
				reserve(_capacity == 0 ? 4 : 2 * _capacity);
			}
			size_t end = _size + 1;
			while (end > pos) {
				_str[end--] = _str[end - 1];
			}
			_str[pos] = ch;
			_size++;
		}
		string& insert(size_t pos, const char* str) {
			assert(pos <= _size);
			size_t len = strlen(str);
			if (_size + len > _capacity) {
				reserve(_size + len);
			}
			size_t end = _size + len;
			while (end > pos + len - 1) {
				_str[end--] = _str[end - len];
			}
			strncpy(_str + pos, str, len);
			_size += len;
			return *this;
		}
		string& erase(size_t pos = 0, size_t len = npos) {
			assert(pos < _size);
			if (len == npos || len >= _size - pos) {
				_str[0] = '\0';
				_size = pos;
			}
			else {
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}
		}
		void resize(size_t n, char ch = '\0') {
			if (n <= _size) {
				_str[n] = '\0';
				_size = n;
			}
			else {
				reserve(n);
				for (size_t i = _size; i < n; i++){
					_str[i] = ch;
				}
				_str[n] = '\0';
				_size = n;
			}
		}
		~string(){
			delete[] _str;
			_size = _capacity = 0;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	public:
		static const int npos;
	};
	const int string::npos = -1;
}
