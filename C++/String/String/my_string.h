#pragma once

#include <iostream>
#include <string.h>
#include <assert.h>

using namespace std;

namespace lsl 
{
	class string {
		const static size_t npos = -1;
	public:
		typedef char* iterator;
		typedef const char* const_iterator;
		iterator begin();
		const_iterator begin() const;
		iterator end();
		const_iterator end() const;

		// 字符串构造
		string(const char* = "");
		// 构造n个字符
		string(size_t n, char ch);
		// 拷贝构造
		string(const string& s);
		~string();
		
		char* c_str() {
			return _str;
		}
		
		//string& operator=(const string& s);
		string& operator=(string s);
		void reserve(size_t n);
		void push_back(char ch);
		void append(const char* str);
		string& operator+=(const char* s);
		string& operator+=(char ch);
		void insert(size_t pos, size_t n, char ch);
		void insert(size_t pos, const char* str);
		void erase(size_t pos,size_t len = npos);
		size_t find(char ch,size_t pos = 0);
		string substr(size_t pos, size_t len = npos);
		bool operator==(const string& s) const;
		bool operator!=(const string& s) const;
		bool operator<(const string& s) const;
		bool operator<=(const string& s) const;
		bool operator>(const string& s) const;
		bool operator>=(const string& s) const;
		void clear();
		void swap(string& s);

	private:
		char* _str = nullptr;
		size_t _size = 0;
		size_t _capacity = 0;
	};
	ostream& operator<<(ostream& out, const string& s);
	istream& operator>>(istream& in, string& s);
	istream& getline(istream& in, string& s, char delim = '\n');

	void test_string1();
	void test_string2();
	void test_string3();
	void test_string4();
	void test_string5();
}