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

//int main()
//{
//	list<lsl::string> lt;
//	lsl::string s1("1111");
//	
//	// 这里调用的是拷贝构造
//	lt.push_back(s1);
//
//	// 下面调用都是移动构造
//	lt.push_back("2222");
//	lt.push_back(std::move(s1));
//	return 0;
//}
//

//void Fun(int& x) { cout << "左值引用" << endl; }
//void Fun(const int& x) { cout << "const 左值引用" << endl; }
//
//void Fun(int&& x) { cout << "右值引用" << endl; }
//void Fun(const int&& x) { cout << "const 右值引用" << endl; }
//
//// 函数模板：万能引用
//template<typename T>
//void PerfectForward(T&& t)
//{
//	// 期望保持实参的属性！
//	// 完美转发
//	Fun(forward<T>(t));
//	// Fun(move(t));
//	// Fun(t);
//}
//
//int main()
//{
//	PerfectForward(10);           // 右值
//
//	int a;
//	PerfectForward(a);            // 左值
//	PerfectForward(std::move(a)); // 右值
//
//	const int b = 8;
//	PerfectForward(b);		      // const 左值
//	PerfectForward(std::move(b)); // const 右值
//
//	return 0;
//}


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
			cout << "string(char* str) -- 构造" << endl;
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

	//lsl::string to_string(int x)
	//{
	//	lsl::string ret;
	//	while (x)
	//	{
	//		int val = x % 10;
	//		x /= 10;
	//		ret += ('0' + val);
	//	}
	//	reverse(ret.begin(), ret.end());

	//	return ret;
	//}
}



template<class T>
struct ListNode
{
	ListNode* _next = nullptr;
	ListNode* _prev = nullptr;
	T _data;
};

template<class T>
class List
{
	typedef ListNode<T> Node;
public:
	List()
	{
		_head = new Node;
		_head->_next = _head;
		_head->_prev = _head;
	}
	void PushBack(T&& x)
	{
		//Insert(_head, x);
		Insert(_head, std::forward<T>(x));
	}
	void PushFront(T&& x)
	{
		//Insert(_head->_next, x);
		Insert(_head->_next, std::forward<T>(x));
	}
	void Insert(Node* pos, T&& x)
	{
		Node* prev = pos->_prev;
		Node* newnode = new Node;
		newnode->_data = std::forward<T>(x); // 关键位置
		// prev newnode pos
		prev->_next = newnode;
		newnode->_prev = prev;
		newnode->_next = pos;
		pos->_prev = newnode;
	}

	void Insert(Node* pos, const T& x)
	{
		Node* prev = pos->_prev;
		Node* newnode = new Node;
		newnode->_data = x;                 // 关键位置
		// prev newnode pos
		prev->_next = newnode;
		newnode->_prev = prev;
		newnode->_next = pos;
		pos->_prev = newnode;
	}
private:
	Node* _head;
};


//int main()
//{
//	List<lsl::string> lt;
//	lt.PushBack("1111");
//	lt.PushFront("2222");
//	return 0;
//}
// 以下代码在vs2013中不能体现，在vs2019下才能演示体现上面的特性。
//class Person
//{
//public:
//	Person(const char* name = "", int age = 0)
//		:_name(name)
//		, _age(age)
//	{}
//		Person(const Person& p)
//			:_name(p._name)
//			, _age(p._age)
//	{}
//
//		Person& operator=(const Person& p)
//		{
//			if(this != &p)
//			{
//				_name = p._name;
//				_age = p._age;
//			}
//			return *this;
//		}
//	
//		// 强制生成
//		// Person(Person&& p) = default;
//
//		// 禁止生成
//		Person(const Person& p) = delete;
//
//
//		//~Person()
//		//{}
//
//private:
//	lsl::string _name; 
//	int _age;
//};

//int main()
//{
//	Person s1;
//	Person s2 = s1;
//	Person s3 = std::move(s1);
//	Person s4;
//	s4 = std::move(s2);
//	return 0;
//}


//class Person
//{
//public:
//	Person(const char* name = "", int age = 0)
//		:_name(name)
//		, _age(age)
//	{}
//	Person(const Person& p) = delete;
//private:
//	lsl::string _name;
//	int _age;
//};

//int main()
//{
//	Person s1;
//	Person s2 = s1;
//	Person s3 = std::move(s1);
//
//	return 0;
//}


// Args是一个模板参数包，args是一个函数形参参数包
// 声明一个参数包Args...args，这个参数包中可以包含0到任意个模板参数。
//template <class ...Args>
//void ShowList(Args... args)
//{}

// 递归终止函数
//template <class T>
//void ShowList(const T& t)
//{
//	cout << t << endl;
//}
//// 展开函数
//template <class T, class ...Args>
//void ShowList(T value, Args... args)
//{
//	cout << value << " ";
//	ShowList(args...);
//}
//int main()
//{
//	ShowList(1);
//	ShowList(1, 'A');
//	ShowList(1, 'A', std::string("sort"));
//	return 0;
//}

//template <class T>
//void PrintArg(T t)
//{
//	cout << t << " ";
//}
////展开函数
//template <class ...Args>
//void ShowList(Args... args)
//{
//	// 要初始化arr，强行让解析参数包，参数包有一个参数，PrintArg就依次推演生成几个
//	int arr[] = { (PrintArg(args), 0)... };
//	cout << endl;
//}
//int main()
//{
//	ShowList(1);
//	ShowList(1, 'A');
//	ShowList(1, 'A', std::string("sort"));
//	return 0;
//}

//int main()
//{
//	std::list< std::pair<int, char> > mylist;
//
//	mylist.emplace_back(10, 'a');
//	mylist.emplace_back(20, 'b');
//	mylist.emplace_back(make_pair(30, 'c'));
//	mylist.push_back(make_pair(40, 'd'));
//	mylist.push_back({ 50, 'e' });
//	for (auto e : mylist)
//		cout << e.first << ":" << e.second << endl;
//	return 0;
//}


//int main()
//{
//	std::list< std::pair<int, lsl::string> > mylist;
//	mylist.emplace_back(10, "sort");
//	mylist.emplace_back(make_pair(20, "sort"));
//	mylist.push_back(make_pair(30, "sort"));
//	mylist.push_back({ 40, "sort" });
//	return 0;
//}



//int main()
//{
//	std::list<lsl::string> lt;
//	lsl::string s1("1111");
//	lt.push_back(s1);
//	lt.push_back(move(s1));
//
//	cout << endl;
//	lsl::string s2("1111");
//	lt.emplace_back(s2);
//	lt.emplace_back(move(s2));
//
//	cout << endl;
//	lt.push_back("xxxx");
//	lt.emplace_back("xxxx");
//
//	return 0;
//}


//int main()
//{
//	std::list<pair<lsl::string, int>> lt;
//	lt.push_back(make_pair("1111", 1));
//	
//	cout << endl;
//	lt.emplace_back("2222", 2);
//	lt.emplace_back(make_pair("1111", 1));
//
//	cout << endl;
//	pair<lsl::string, int> kv("1111", 1);
//	lt.emplace_back(kv);
//
//	return 0;
//}

#include<algorithm>

//int main()
//{
//	int array[] = { 4,1,8,5,3,7,0,9,2,6 };
//	// 默认按照小于比较，排出来结果是升序
//	std::sort(array, array + sizeof(array) / sizeof(array[0]));
//
//	// 如果需要降序，需要改变元素的比较规则
//	std::sort(array, array + sizeof(array) / sizeof(array[0]), greater<int>());
//	return 0;
//}


struct Goods
{
	string _name;  // 名字
	double _price; // 价格
	int _evaluate; // 评价
	Goods(const char* str, double price, int evaluate)
		:_name(str)
		, _price(price)
		, _evaluate(evaluate)
	{}
};

struct ComparePriceLess
{
	bool operator()(const Goods& gl, const Goods& gr)
	{
		return gl._price < gr._price;
	}
};

struct ComparePriceGreater
{
	bool operator()(const Goods& gl, const Goods& gr)
	{
		return gl._price > gr._price;
	}
};


//int main()
//{
//	vector<Goods> v = { { "苹果", 2.1, 5 }, { "香蕉", 3, 4 }, { "橙子", 2.2, 3 }, { "菠萝", 1.5, 4 } };
//
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2)->bool {g1._price < g2._price; });
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {g1._price > g2._price; });
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {g1._evaluate < g2._evaluate; });
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {g1._evaluate > g2._evaluate; });
//
//
//	// sort(v.begin(), v.end(), ComparePriceLess());
//	// sort(v.begin(), v.end(), ComparePriceGreater());
//}

//int main()
//{
//	auto f1 = [](int x) {cout << x << endl; return 0; };
//
//	cout << typeid(f1).name() << endl;
//
//	f1(1);
//	f1(2);
//
//	return 0;
//}


//int main()
//{
//	int x = 0, y = 1;
//	cout << x << ":" << y << endl;
//	
//	auto f1 = [](int& r1, int& r2) {
//		int tmp = r1;
//		r1 = r2;
//		r2 = tmp;
//	};
//	f1(x, y);
//	cout << x << ":" << y << endl;
//
//	// 这里是传值，默认用加了const，加mutable就没有const
//	auto f2 = [x, y]() mutable {
//		int tmp = x;
//		x = y;
//		y = tmp;
//	};
//	f2();
//	cout << x << ":" << y << endl;
//
//	
//	// 引用捕捉
//	auto f3 = [&x, &y]() mutable {
//		int tmp = x;
//		x = y;
//		y = tmp;
//	};
//	f3();
//	cout << x << ":" << y << endl;
//
//	// 可以不加mutable
//	auto f4 = [&x, &y]() {
//		int tmp = x;
//		x = y;
//		y = tmp;
//	};
//	f4();
//	cout << x << ":" << y << endl;
//
//
//	return 0;
//}


//int main()
//{
//	int x = 0, y = 1;
//	cout << x << " " << y << endl;
//
//	auto f1 = [](int& r1, int& r2) {
//		int tmp = r1;
//		r1 = r2;
//		r2 = tmp;
//	};
//
//	f1(x, y);
//	cout << x << " " << y << endl << endl;
//
//
//	cout << x << " " << y << endl;
//	cout << &x << ":" << &y << endl;
//
//	auto f2 = [x, y]() mutable {
//		cout << &x << ":" << &y << endl;
//
//		int tmp = x;
//		x = y;
//		y = tmp;
//	};
//
//	f2();
//	cout << x << " " << y << endl << endl;
//
//	cout << x << " " << y << endl;
//	cout << &x << ":" << &y << endl;
//	auto f3 = [&x, &y]() {
//		cout << &x << ":" << &y << endl;
//
//		int tmp = x;
//		x = y;
//		y = tmp;
//	};
//
//	f3();
//	cout << x << " " << y << endl << endl;
//	return 0;
//}

//
//class AA
//{
//public:
//	void func()
//	{
//		// 捕捉this
//		auto f1 = [this]() {
//			cout << a1 << endl;
//			cout << a2 << endl;
//		};
//
//		// 全部捕捉
//		auto f1 = [=]() {
//			cout << a1 << endl;
//			cout << a2 << endl;
//		};
//
//		f1();
//	}
//private:
//	int a1 = 1;
//	int a2 = 1;
//};
//
//
//int main()
//{
//	int x = 0, y = 1, z = 2;
//
//	// = 为全部捕捉，z为引用捕捉
//	auto f1 = [=, &z]() {
//		z++;
//
//		cout << x << endl;
//		cout << y << endl;
//		cout << z << endl;
//	};
//
//	f1();
//
//	return 0;
//}

#include<map>
#include<functional>
//
//void swap_func(int& r1, int& r2)
//{
//	int tmp = r1;
//	r1 = r2;
//	r2 = tmp;
//}
//
//struct Swap
//{
//	void operator()(int& r1, int& r2)
//	{
//		int tmp = r1;
//		r1 = r2;
//		r2 = tmp;
//	}
//};
//
//
//int main()
//{
//	int x = 0, y = 1;
//	cout << x << ":" << y << endl;
//
//	// lambda
//	auto swaplambda = [](int& r1, int& r2) {int tmp = r1; r1 = r2; r2 = tmp; };
//
//	// 函数指针
//	function<void(int&, int&)> f1 = swap_func;
//	f1(x, y);
//	cout << x << " " << y << endl << endl;
//	// 类[匿名对象]
//	function<void(int&, int&)> f2 = Swap();
//	f2(x, y);
//	cout << x << " " << y << endl << endl;
//	// lambda
//	function<void(int&, int&)> f3 = swaplambda;
//	f3(x, y);
//	cout << x << " " << y << endl << endl;
//
//	map<std::string, std::function<void(int&, int&)>> CmdOp{
//		{"函数指针", swap_func},
//		{"仿函数", Swap()},
//		{"lambda", swaplambda},
//
//		//{"函数指针", f1},
//		//{"仿函数", f2},
//		//{"lambda", f3},
//	};
//
//	// 使用
//	CmdOp["函数指针"](x, y);
//	cout << x << " " << y << endl << endl;
//
//	CmdOp["仿函数"](x, y);
//	cout << x << " " << y << endl << endl;
//
//	CmdOp["lambda"](x, y);
//	cout << x << " " << y << endl << endl;
//
//	return 0;
//}


//#include <functional>
//template<class F, class T>
//T useF(F f, T x)
//{
//	static int count = 0;
//	cout << "count:" << ++count << endl;
//	cout << "count:" << &count << endl;
//	return f(x);
//}
//double f(double i)
//{
//	return i / 2;
//}
//int main()
//{
//	struct Functor
//	{
//		double operator()(double d)
//		{
//			return d / 3;
//		}
//	};
//	// 函数名
//	std::function<double(double)> func1 = f;
//	cout << useF(func1, 11.11) << endl;
//	// 函数对象
//	std::function<double(double)> func2 = Functor();
//	cout << useF(func2, 11.11) << endl;
//	// lamber表达式
//	std::function<double(double)> func3 = [](double d)->double { return d / 4; };
//	cout << useF(func3, 11.11) << endl;
//	return 0;
//}

class Plus
{
public:
	static int plusi(int a, int b)
	{
		return a + b;
	}

	double plusd(double a, double b)
	{
		return a + b;
	}
};


int main()
{
	// 静态成员可以不加，但是建议加上&
	function<int(int, int)> f1 = Plus::plusi;
	cout << f1(1, 2) << endl;

	// 成员函数取地址，比较特殊，要加一个类域和&，还有一个this
	function<double(Plus*, double, double)> f2 = &Plus::plusd;
	Plus ps; 
	cout << f2(&ps, 1.1, 2.2) << endl;

	// 或者这样，也可以
	function<double(Plus, double, double)> f3 = &Plus::plusd;
	cout << f3(Plus(), 1.11, 2.22) << endl;

	// 但是上面太麻烦，每次写都需要写
	// 将参数固定bind，就可以省略不写
	function<double(double, double)> f4 = bind(&Plus::plusd, Plus(), placeholders::_1, placeholders::_2);
	cout << f4(1.11, 2.22) << endl;

	return 0;
}


//int Sub(int a, int b)
//{
//	return a - b;
//}
//
//int main()
//{
//	function<int(int, int)> f1 = Sub;
//	cout << f1(10, 5) << endl;
//
//	// 调整参数顺序
//	function<int(int, int)> f2 = bind(Sub, placeholders::_2, placeholders::_1);
//	cout << f2(10, 5) << endl;
//
//	// 调整参数个数，有些参数可以bind时写死
//	function<int(int)> f3 = bind(Sub, 20, placeholders::_1);
//	cout << f3(5) << endl;
//
//	return 0;
//}




