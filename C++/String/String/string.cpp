#define _CRT_SECURE_NO_WARNINGS 1

#include "my_string.h"
namespace lsl 
{
	string::iterator string::begin() {
		return _str;
	}
	string::const_iterator string::begin() const {
		return _str;
	}
	string::iterator string::end() {
		return _str + _size;
	}
	string::const_iterator string::end() const {
		return _str + _size;
	}

	string::string(const char* str)
		:_size(strlen(str))
	{
		_capacity = _size;
		_str = new char[_size + 1];
		strcpy(_str, str);
	}

	string::string(size_t n, char ch)
		:_str(new char[n + 1])
		, _size(n)
		,_capacity(n)
	{
		for (size_t i = 0; i < n; i++)
		{
			_str[i] = ch;
		}
		_str[_size] = '\0';
	}
	
	// 传统写法
	//string::string(const string& s) {
	//	_str = new char[s._capacity + 1];
	//	strcpy(_str, s._str);
	//	_capacity = s._capacity;
	//	_size = s._size;
	//}

	void string::swap(string& s) {
		std::swap(_str, s._str);
		std::swap(_size, s._size);
		std::swap(_capacity, s._capacity);
	}
	// 现代写法
	string::string(const string& s) {
		string tmp(s._str);
		swap(tmp);
	}

	// 传统写法1：
	//string& string::operator=(const string& s) {
	//	if (this != &s) {
	//		_str = new char[s._capacity + 1];
	//		strcpy(_str, s._str);
	//		_capacity = s._capacity;
	//		_size = s._size;
	//	}
	//	return *this;
	//}
	
	// 现代写法1：
	//string& string::operator=(const string& s) {
	//	if (this != &s) {
	//		string tmp(s);
	//		swap(tmp);
	//	}
	//}
	
	// 现代写法2：
	string& string::operator=(string s) {
		swap(s);
		return *this;
	}

	string::~string() {
		delete[] _str;
		_str = nullptr;
		_capacity = _size = 0;
	}

	void string::reserve(size_t n) {
		if (n > _capacity)
		{
			char* tmp = new char[n + 1];
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = n;
		}
	}

	void string::push_back(char ch) {
		if (_size + 1 > _capacity)
			reserve(_capacity == 0 ? 4 : _capacity * 2);
		_str[_size++] = ch;
		_str[_size] = '\0';
	}

	void string::append(const char* str) {
		assert(str);
		size_t len = strlen(str);
		if (_size + len > _capacity) { // 如果_str字符串的长度+str的长度大于容量就进行扩容
			// 扩容
			size_t newcapacity = 2 * _capacity;
			if (_size + len > 2 * _capacity) { // 如果这个str的字符串都比2倍大，那就要多少扩多少
				newcapacity = _size + len;
			}
			reserve(newcapacity);
		}
		strcpy(_str + _size, str);
		_size += len;
	}

	// s1+=s2
	string& string::operator+=(const char* s) {
		append(s);
		return *this;
	}

	string& string::operator+=(char ch) {
		push_back(ch);
		return *this;
	}

	void string::insert(size_t pos, size_t n, char ch) {
		assert(pos <= _size);
		assert(n > 0);
		if (_size + n > _capacity)
		{
			// 扩容
			size_t newcapacity = 2 * _capacity;
			if (_size + n > 2 * _capacity)
				newcapacity = _size + n;
			reserve(newcapacity);
		}
		// 挪动数据
		size_t end = _size + n;
		while (end > pos + n - 1)
		{
			_str[end] = _str[end - n];
			end--;
		}
		for (size_t i = 0; i < n; i++)
		{
			_str[pos + i] = ch;
		}
		_size += n;
	}

	void string::insert(size_t pos, const char* str) {
		assert(pos <= _size);
		size_t n = strlen(str);

		if (_size + n > _capacity)
		{
			// 扩容
			size_t newcapacity = 2 * _capacity;
			if (_size + n > 2 * _capacity)
				newcapacity = _size + n;
			reserve(newcapacity);
		}
		// 挪动数据
		size_t end = _size + n;
		while (end > pos + n - 1)
		{
			_str[end] = _str[end - n];
			end--;
		}
		// 覆盖数据
		for (size_t i = 0; i < n; i++)
		{
			_str[pos + i] = str[i];
		}
		_size += n;
	}

	void string::erase(size_t pos, size_t len) {
		if (len > pos + _size) {
			// 剩下的全部删完
			_str[pos] = '\0';
			_size = pos;
		}
		else {
			size_t end = pos + len;
			while (end <= _size)
			{
				_str[end - len] = _str[end];
				end++;
			}
			_size -= len;
		}
	}
	size_t string::find(char ch, size_t pos) {
		for (size_t i = pos; i < _size; i++)
		{
			if (_str[i] == ch)
				return i;
		}
		return npos;
	}
	string string::substr(size_t pos, size_t len) {
		size_t leftlen = _size - pos;
		if (len > leftlen)
			len = leftlen;
		string tmp;
		tmp.reserve(len);
		for (size_t i = 0; i < leftlen; i++)
		{
			tmp += _str[pos + i];
		}
		return tmp;
	}
	void string::clear() {
		_str[0] = '\0';
		_size = 0;
	}
	bool string::operator==(const string& s) const {
		return strcmp(_str, s._str) == 0;
	}
	bool string::operator!=(const string& s) const {
		return !(*this == s);
	}
	bool string::operator<(const string& s) const {
		return strcmp(_str, s._str) < 0;
	}
	bool string::operator<=(const string& s) const {
		return *this < s || *this == s;
	}
	bool string::operator>(const string& s) const {
		return !(*this <= s);
	}
	bool string::operator>=(const string& s) const {
		return !(*this < s);
	}
	ostream& operator<<(ostream& out, const string& s) {
		for (auto& e : s) {
			out << e;
		}
		return out;
	}
	istream& operator>>(istream& in, string& s) {
		s.clear();
		const int N = 1024;
		char buffer[N];
		int i = 0;
		char ch = in.get();
		while (ch != ' ' && ch != '\n')
		{
			buffer[i++] = ch;
			if (i == N - 1) {
				buffer[i] = '\0';
				s += buffer;
				i = 0;
			}
			ch = in.get();
		}
		if (i > 0) {
			buffer[i] = '\0';
			s += buffer;
		}
		return in;
	}

	istream& getline(istream& in, string& s, char delim) {
		s.clear();
		const int N = 1024;
		char buffer[N];
		int i = 0;
		int ch = in.get();
		while (ch != delim)
		{
			buffer[i++] = ch;
			if (i == N - 1) {
				buffer[i] = '\0';
				s += buffer;
				i = 0;
			}
			ch = in.get();
		}
		if (i > 0) {
			buffer[i] = '\0';
			s += buffer;
		}
		return in;
	}


	void test_string1() {
		string s1("hello world");
		cout << s1.c_str() << endl;

		string s2(5, 'a');
		cout << s2.c_str() << endl;

		string s3(s1);
		cout << s3.c_str() << endl;
		
		string s4 = s1;
		cout << s4.c_str() << endl;
	}
	void test_string2() {
		string s1("hello world");
		//s1.reserve(200);
		s1.push_back('x');
		s1.push_back('x');
		cout << s1.c_str() << endl;

		s1.append("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
		cout << s1.c_str() << endl;

		string s3("hello");
		s3 += " world";
		cout << s3.c_str() << endl;
	}
	void test_string3() {
		string s1("hello");
		s1.insert(5, 5, 'x');
		s1.insert(0,"world");
		cout << s1.c_str() << endl;

		//s1.erase(2);
		//cout << s1.c_str() << endl;

		s1.erase(2,5);
		cout << s1.c_str() << endl;
		cout << s1.find('x') << endl;
	}
	void test_string4() {
		string s1("hello world");
		string s2(s1);
		// cout << s1.substr(6).c_str() << endl;
		// cin >> s1;
		getline(cin,s1,'?');
		cout << s1 << endl;
	}
	void test_string5() {
		string s1("1111111111");
		string s2(s1);
		
		cout << s2 << endl;
	}

}

