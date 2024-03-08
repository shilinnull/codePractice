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
		const char* c_str() const{
			return _str;
		}
		size_t size() const {
			return _size;
		}
		size_t capacity()const {
			return _capacity;
		}
		string(const char* str = "")
			:_size(strlen(str)){
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		//string(const string& s) {
		//	_str = new char[s._capacity + 1];
		//	strcpy(_str, s._str);
		//	_size = s._size;
		//	_capacity = s._capacity;
		//}
		// 现代写法
		string(const string& s) {
			string tmp(s._str);
			swap(tmp);
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
		//string& operator=(const string& s) {
		//	char* tmp = new char[s._capacity + 1];
		//	strcpy(tmp, s._str);
		//	delete[] _str;
		//	_str = tmp;
		//	_size = s._size;
		//	_capacity = s._capacity;
		//	return *this;
		//}
		// 现代写法
		string& operator=(string tmp) {
			swap(tmp);
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
			//if (_size == _capacity) {
			//	reserve(_capacity == 0 ? 4 : 2 * _capacity);
			//}
			//_str[_size++] = ch;
			//_str[_size] = '\0';
			insert(_size, ch);
		}
		void append(const char* str) {
			//assert(str);
			//size_t len = strlen(str);
			//if (_size + len > _capacity) {
			//	reserve(_size + len);
			//}
			//strcpy(_size + _str, str);
			//_size += len;
			insert(_size, str);
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
		void insert(size_t pos, const char* str) {
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
		} 
		void erase(size_t pos = 0, size_t len = npos) {
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
		void swap(string& s) {
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
			std::swap(_str, s._str);
		}
		size_t find(char ch, size_t pos = 0) const {
			assert(pos < _size);
			for (size_t i = 0; i < _size; i++) {
				if (_str[i] == ch) {
					return i;
				}
			}
			return npos;
		}
		size_t find(const char* sub, size_t pos = 0) const {
			assert(pos < _size);
			const char* p = strstr(_str + pos, sub);
			if (p) {
				return p - _str;
			}
			else{
				return npos;
			}
		}
		string substr(size_t pos = 0, size_t len= npos) {
			assert(pos < _size); 
			string sub;
			size_t i = 0;
			if (len == npos || len >= _size - pos) {
				for (i = pos; i < _size; i++) {
					sub += _str[i];
				}
			}
			else {
				for (i = pos; i < pos + len; i++) {
					sub += _str[i];
				}
			}
			return sub;
		}
		void clear() {
			_size = 0;
			_str[_size] = '\0';
		}
		~string(){
			delete[] _str;
			_size = _capacity = 0;
		}
	private:
		char* _str = nullptr;
		size_t _size = 0;
		size_t _capacity = 0;
	public:
		static const int npos;
	};
	const int string::npos = -1;

	void swap(string& x, string& y) {
		x.swap(y);
	}
	bool operator==(const string& s1, const string& s2) {
		return strcmp(s1.c_str(), s2 .c_str()) == 0;
	}
	bool operator<(const string& s1, const string& s2) {
		return strcmp(s1.c_str(), s2.c_str()) < 0;
	}
	bool operator<=(const string& s1, const string& s2) {
		return s1 < s2 || s1 == s2;
	} 
	bool operator>(const string& s1, const string& s2) {
		return !(s1 <= s2);
	} 
	bool operator>=(const string& s1, const string& s2) {
		return !(s1 < s2);
	} 
	bool operator!=(const string& s1, const string& s2) {
		return !(s1 == s2);
	}

	ostream& operator<<(ostream& out, const string& s) {
		for (auto ch : s) {
			out << ch;
		}
		return out;
	}
	istream& operator>>(istream& in, string& s) {
		s.clear();
		char ch;
		size_t i = 0;
		char buff[128];
		ch = in.get();
		while (ch != ' ' && ch != '\n') {
			buff[i++] = ch;
			if (i == 127) {
				buff[127] = '\0';
				s += buff;
				i = 0;
			}
			ch = in.get();
		}
		if (i > 0) {
			buff[i] = '\0';
			s += buff;
		}
		return in;
	}
	istream& getline(istream& in, string& s) {
		s.clear();
		char ch;
		size_t i = 0;
		char buff[128];
		ch = in.get();
		while (ch != ' ') {
			buff[i++] = ch;
			if (i == 127) {
				buff[127] = '\0';
				s += buff;
				i = 0;
			}
			ch = in.get();
		}
		if (i > 0) {
			buff[i] = '\0';
			s += buff;
		}
		return in;
	}
}
