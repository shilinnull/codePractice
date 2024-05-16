#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <string>

using namespace std;


struct Point
{
	int _x;
	int _y;
};

//int main()
//{
//	int array1[] = { 1, 2, 3, 4, 5 };
//	int array2[5] = { 0 };
//	Point p = { 1, 2 };
//	return 0;
//}
//
//struct Point
//{
//	int _x;
//	int _y;
//};
//
//int main()
//{
//	int x1 = 1;
//	int x2{ 2 };
//	int array1[]{ 1, 2, 3, 4, 5 };
//	int array2[5]{ 0 };
//	Point p{ 1, 2 };
//
//	// C++11中列表初始化也可以适用于new表达式中
//	int* pa = new int[4]{ 0 };
//	return 0;
//}

class Date
{
public:
	Date(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Date(int year, int month, int day)" << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

//int main()
//{
//	Date d1(2022, 1, 1); 
//
//	// C++11支持的列表初始化，这里会调用构造函数初始化
//	Date d2{ 2022, 1, 2 };
//	Date d3 = { 2022, 1, 3 };
//	return 0;
//}


//int main()
//{
//	// the type of il is an initializer_list 
//	auto il = { 10, 20, 30 };
//	cout << typeid(il).name() << endl;
//	return 0;
//}

//int main()
//{
//	// 内置类型
//	int i = 0;
//	int j = { 0 };
//	int k{ 0 };
//	int array1[]{ 1, 2, 3, 4, 5 };
//	int array2[5]{ 0 };
//	
//	// 自定义类型
//	Point p{ 1, 2 };
//	Date d1(2023, 11, 25);
//
//	// 类型转换  构造+拷贝构造->优化直接构造
//	Date d2 = { 2024, 5, 15 };
//	Date d3{ 2024, 5, 15 };
//
//	string s1 = "xxxx";
//
//	const Date& d4 = { 2023, 11, 25 };
//
//	// new 表达式
//	Date* p1 = new Date[3]{ d1, d2, d3 };
//	Date* p2 = new Date[3]{ {2022, 11, 25}, {2022, 11, 26}, {2022, 11, 27} };
//
//	return 0;
//}



//int main()
//{
//	vector<int> v1 = { 1,2,3,4 };
//	vector<int> v2 = { 1,2,3,4,5,6};
//
//	v1 = { 10,20,30 };
//
//	list<int> lt = { 10,20,30 };
//
//	// 多参数构造类型转换  构造+拷贝构造->优化直接构造
//	// 跟对应构造函数参数个数匹配
//	Date d2 = { 2023, 11, 25 };
//
//	// the type of il is an initializer_list 
//	auto il1 = { 10, 20, 30, 40, 50 };
//	cout << typeid(il1).name() << endl;
//
//	initializer_list<int> il2 = { 10, 20, 30};
//
//	initializer_list<int>::iterator it2 = il2.begin();
//	while (it2 != il2.end())
//	{
//		cout << *it2 << " ";
//		++it2;
//	}
//	cout << endl;
//	
//	//for (int e : il2)
//	for (auto e : il2)
//	{
//		cout << e << " ";
//	}
//	cout<< endl;
//
//	pair<string, string> kv1("sort", "排序");
//	map<string, string> dict = {{"insert", "插入"}, {"get","获取"} };
//	for (auto& kv : dict)
//	{
//		cout << kv.first << ":" << kv.second << endl;
//	}
//
//	Date dd2 = { 2023, 11, 25 };
//	// Date dd3 = { 2023, 11, 25, 20}; // 报错
//
//	return 0;
//}

//
//namespace lsl
//{
//	template<class T>
//	class vector {
//	public:
//		typedef T* iterator;
//
//		vector(initializer_list<T> l)
//		{
//			_start = new T[l.size()];
//			_finish = _start + l.size();
//			_endofstorage = _start + l.size();
//			iterator vit = _start;
//			typename initializer_list<T>::iterator lit = l.begin();
//			while (lit != l.end())
//			{
//				*vit++ = *lit++;
//			}
//		}
//		vector<T>& operator=(initializer_list<T> l) {
//			vector<T> tmp(l);
//			std::swap(_start, tmp._start);
//			std::swap(_finish, tmp._finish);
//			std::swap(_endofstorage, tmp._endofstorage);
//			return *this;
//		}
//	private:
//		iterator _start;
//		iterator _finish;
//		iterator _endofstorage;
//	};
//}


//int main()
//{
//	int i = 1;
//	double d = 2.2;
//
//	// 类型以字符串形式获取到
//	cout << typeid(i).name() << endl;
//	cout << typeid(d).name() << endl;
//
//	// typeid(i).name() j;
//	auto j = i;
//
//	auto ret = i * d;
//	decltype(ret) x = ret;
//
//	// 用ret的类型去实例化vector
//	// decltype可以推导对象的类型。这个类型是可以用来模板实参，或者再定义对象
//	vector<decltype(ret)> v;
//	v.push_back(1);
//	v.push_back(1.1);
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	
//	return 0;
//}


//int main()
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//
//	for (auto e : v)
//	{
//		// 自动解引用，自动++
//		cout << e << " ";
//	}
//
//	cout << endl;
//
//	return 0;
//}

//int main()
//{
//	// 以下的p、b、c、*p都是左值
//	int* p = new int(0);
//	int b = 1;
//	const int c = 2;
//	// 以下几个是对上面左值的左值引用
//	int*& rp = p;
//	int& rb = b;
//	const int& rc = c;
//	int& pvalue = *p;
//	return 0;
//}

//int main()
//{
//	double x = 1.1, y = 2.2;
//	// 以下几个都是常见的右值
//	10;
//	x + y;
//	fmin(x, y);
//
//	// 以下几个都是对右值的右值引用
//	int&& rr1 = 10;
//	double&& rr2 = x + y;
//	double&& rr3 = fmin(x, y);
//	
//	// 这里编译会报错：error C2106: “=”: 左操作数必须为左值
//	10 = 1;
//	x + y = 1;
//	fmin(x, y) = 1;
//
//	return 0;
//}


//int main()
//{
//	double x = 1.1, y = 2.2;
//	int&& rr1 = 10;
//	const double&& rr2 = x + y;
//	rr1 = 20;
//	rr2 = 5.5;  // 报错
//	return 0;
//}

//int main()
//{
//	// 左值引用只能引用左值，不能引用右值。
//	int a = 10;
//	int& ra1 = a;
//
//	// ra为a的别名
//	int& ra2 = 10;   // 编译失败，因为10是右值
//	// const左值引用既可引用左值，也可引用右值。
//	const int& ra3 = 10;
//	const int& ra4 = a;
//	return 0;
//}


//int main()
//{
//	// 右值引用只能右值，不能引用左值。
//	int&& r1 = 10;
//
//
//	// error C2440: “初始化”: 无法从“int”转换为“int &&”
//	// message : 无法将左值绑定到右值引用
//	int a = 10;
//	int&& r2 = a;
//
//
//	// 右值引用可以引用move以后的左值
//	int&& r3 = std::move(a);
//	return 0;
//}

#include<assert.h>

namespace lsl
{
	class string
	{
	public:
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		string(const char* str = "")
			:_size(strlen(str))
			, _capacity(_size)
		{
			// cout << "string(char* str)" << endl;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		// s1.swap(s2)
		void swap(string& s)
		{
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}
		// 拷贝构造
		string(const string& s)
			:_str(nullptr)
		{
			cout << "string(const string& s) -- 深拷贝" << endl;
			string tmp(s._str);
			swap(tmp);
		}
		// 赋值重载
		string& operator=(const string& s)
		{
			cout << "string& operator=(string s) -- 深拷贝" << endl;
			string tmp(s);
			swap(tmp);
			return *this;
		}
		// 移动构造
		string(string&& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			cout << "string(string&& s) -- 移动语义" << endl;
			swap(s);
		}
		// 移动赋值
		string& operator=(string&& s)
		{
			cout << "string& operator=(string&& s) -- 移动语义" << endl;
			swap(s);
			return *this;
		}


		void push_back(string&& val)
		{

		}


		~string()
		{
			delete[] _str;
			_str = nullptr;
		}
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}
		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}


		void push_back(char ch)
		{
			if (_size >= _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newcapacity);
			}

			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}
		//string operator+=(char ch)
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}
		const char* c_str() const
		{
			return _str;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};

	lsl::string to_string(int x)
	{
		lsl::string ret;
		while (x)
		{
			int val = x % 10;
			x /= 10;
			ret += ('0' + val);
		}
		reverse(ret.begin(), ret.end());

		return ret;
	}
}



//
//int main()
//{
//	// 在bit::string to_string(int value)函数中可以看到，这里
//    // 只能使用传值返回，传值返回会导致至少1次拷贝构造(如果是一些旧一点的编译器可能是两次拷贝构造)。
//	lsl::string ret = lsl::to_string(1234);
//
//	return 0;
//}

//
//int main()
//{
//	lsl::string s1("hello world");
//	lsl::string s2 = s1;
//	lsl::string s3 = move(s1);
//
//	return 0;
//}


//void func1(lsl::string s)
//{}
//void func2(const lsl::string& s)
//{}
//int main()
//{
//	lsl::string s1("hello world");
//	// func1和func2的调用我们可以看到左值引用做参数减少了拷贝，提高效率的使用场景和价值
//	func1(s1);
//	func2(s1);
//
//	s1 += '!';
//	return 0;
//}

//int main()
//{
//	lsl::string s1("hello world");
//	// 这里s1是左值，调用的是拷贝构造
//	lsl::string s2(s1);
//
//	// 这里我们把s1 move处理以后, 会被当成右值，调用移动构造
//	// 但是这里要注意，一般是不要这样用的，因为我们会发现s1的
//	// 资源被转移给了s3，s1被置空了。
//	lsl::string s3(std::move(s1));
//	return 0;
//}

int main()
{
	list<lsl::string> lt;
	lsl::string s1("1111");
	
	// 这里调用的是拷贝构造
	lt.push_back(s1);

	// 下面调用都是移动构造
	lt.push_back("2222");
	lt.push_back(std::move(s1));
	return 0;
}


