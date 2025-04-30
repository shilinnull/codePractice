#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


// 内置类型和自定义类型之间
// 1、自定义类型 = 内置类型 ->构造函数支持
// 2、内置类型 = 自定义类型 ->operator 内置类型 支持
//class A
//{
//public:
//	// 构造函数加上explicit就不支持隐式类型转换了
//	//explicit A(int a)
//	A(int a)
//		:_a1(a)
//		, _a2(a)
//	{}
//	A(int a1, int a2)
//		:_a1(a1)
//		, _a2(a2)
//	{}
//	// 加上explicit就不支持隐式类型转换了
//	// explicit operator int()
//	operator int() const
//	{
//		return _a1 + _a2;
//	}
//private:
//	int _a1 = 1;
//	int _a2 = 1;
//};
//
//class B
//{
//public:
//	B(int b)
//		:_b1(b)
//	{}
//	// 支持A类型对象转换为B类型对象
//	B(const A& aa)
//		:_b1(aa)
//	{}
//private:
//	int _b1 = 1;
//};
//
//int main()
//{
//	// 单参数的转换
//	string s1 = "1111111";
//	A aa1 = 1;
//	A aa2 = (A)1;
//	// 多参数的转换
//	A aa3 = { 2, 2 };
//	const A& aa4 = { 2,2 };
//	int z = aa1.operator int();
//	int x = aa1;
//	int y = (int)aa2;
//	cout << x << endl;
//	cout << y << endl;
//	cout << z << endl;
//	std::shared_ptr<int> foo;
//	std::shared_ptr<int> bar(new int(34));
//	//if (foo.operator bool())
//	if (foo)
//		std::cout << "foo points to " << *foo << '\n';
//	else
//		std::cout << "foo is null\n";
//
//	if (bar)
//		std::cout << "bar points to " << *bar << '\n';
//	else
//		std::cout << "bar is null\n";
//
//	// A类型对象隐式转换为B类型
//	B bb1 = aa1;
//	B bb2(2);
//	bb2 = aa1;
//	const B& ref1 = aa1;
//	return 0;
//}


//int main()
//{
//	int x = 100;
//	double* p1 = (double*)&x;
//	// 这里会本质已经出现了越界访问，只是越界不一定能被检查出来
//	cout << *p1 << endl;
//
//	return 0;
//}

//int main()
//{
//	volatile const int y = 0;
//	int* p2 = (int*)&y;
//	(*p2) = 1;
//	cout << *p2 << endl;
//	cout << y << endl;
//	return 0;
//}


//int main()
//{
//	// 对应隐式类型转换 -- 数据的解释意义没有改变
//	double pi = 3.14;
//	int a = static_cast<int>(pi);
//	cout << a << endl;
//	int&& ref = static_cast<int&&>(a);
//
//	return 0;
//}

//int main()
//{
//	// 对应隐式类型转换 -- 数据的解释意义没有改变
//	double pi = 3.14;
//	int a = static_cast<int>(pi);
//	cout << a << endl;
//
//	//int *p = static_cast<int*>(a);
//	int *p = reinterpret_cast<int*>(a);
//
//	return 0;
//}

//int main()
//{
//	// 对应隐式类型转换 -- 数据的解释意义没有改变
//	double pi = 3.14;
//	int a = static_cast<int>(pi);
//	cout << a << endl;
//
//	//int *p = static_cast<int*>(a);
//	int *p = reinterpret_cast<int*>(a);
//
//	return 0;
//}


//#include<iostream>
//#include<string>
//#include<vector>
//#include<list>
//#include<typeinfo>
//using namespace std;
//
//int main()
//{
//	int a[10];
//	int* ptr = nullptr;
//	cout << typeid(10).name() << endl;
//	cout << typeid(a).name() << endl;
//	cout << typeid(ptr).name() << endl;
//	cout << typeid(string).name() << endl;
//	cout << typeid(string::iterator).name() << endl;
//	cout << typeid(vector<int>).name() << endl;
//	cout << typeid(vector<int>::iterator).name() << endl;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	virtual void func()
//	{}
//protected:
//	int _a1 = 1;
//};
//
//class B : public A
//{
//protected:
//	int _b1 = 2;
//};
//
//int main()
//{
//	try
//	{
//		B* pb = new B;
//		A* pa = (A*)pb;
//		if (typeid(*pb) == typeid(B))
//		{
//			cout << "typeid(*pb) == typeid(B)" << endl;
//		}
//		// 如果A和B不是继承关系，则会抛bad_typeid异常
//		if (typeid(*pa) == typeid(B))
//		{
//			cout << "typeid(*pa) == typeid(B)" << endl;
//		}
//		// 这里pa和pb是A*和B*，不是类类型对象，他会被当做编译是求值的静态类型运算
//		// 所以这里始终是不相等的
//		if (typeid(pa) == typeid(pb))
//		{
//			cout << "typeid(pa) == typeid(pb)" << endl;
//		}
//	}
//	catch (const std::exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	return 0;
//}
//

//#include<iostream>
//using namespace std;
//int main()
//{
//	cout << cin.good() << endl;
//	cout << cin.eof() << endl;
//	cout << cin.bad() << endl;
//	cout << cin.fail() << endl << endl;
//
//	int i = 0;
//	// 输入一个字符或多个字符，cin读取失败，流状态被标记为failbit
//	cin >> i;
//	cout << i << endl;
//	cout << cin.good() << endl;
//	cout << cin.eof() << endl;
//	cout << cin.bad() << endl;
//	cout << cin.fail() << endl << endl;
//	if (cin.fail())
//	{
//		// clear可以恢复流状态位goodbit
//		cin.clear();
//		// 我们还要把缓冲区中的多个字符都读出来，读到数字停下来，否则再去cin>>i还是会失败
//		char ch = cin.peek();
//		while (!(ch >= '0' && ch <= '9'))
//		{
//			ch = cin.get();
//			cout << ch;
//			ch = cin.peek();
//		}
//		cout << endl;
//	}
//	cout << cin.good() << endl;
//	cout << cin.eof() << endl;
//	cout << cin.bad() << endl;
//	cout << cin.fail() << endl << endl;
//	cin >> i;
//	cout << i << endl;
//	return 0;
//}


//#include<iostream>
//#include<fstream>
//using namespace std;
//void func(ostream& os)
//{
//	os << "hello world";
//	os << "hello bit";
//	// "hello world"和"hello bit"是否输出不确定
//	system("pause");
//	// 遇到endl，"hello world"和"hello bit"一定刷新缓冲区输出了
//	// os << endl;
//	// os << flush;
//	int i;
//	//cin >> i;
//	os << "hello cat";
//	// "hello cat"是否输出不确定
//	system("pause");
//}
//
//
//int main()
//{
//	ofstream ofs("test.txt");
//	// func(cout);
//	// unitbuf设置后，ofs每次写都直接刷新
//	ofs << unitbuf;
//	// cin绑定到ofs，cin进行读时，会刷新ofs的缓冲区
//	cin.tie(&ofs);
//	func(ofs);
//	return 0;
//}


//int main()
//{
//	// 在io需求比较高的地方，如部分大量输入的竞赛题中，加上以下几行代码可以提高C++IO效率
//	// 并且建议用'\n'替代endl，因为endl会刷新缓冲区
//	// 关闭标准 C++ 流是否与标准 C 流在每次输入/输出操作后同步。
//	ios_base::sync_with_stdio(false);
//	// 关闭同步后，以下程序可能顺序为b a c
//	// std::cout << "a\n";
//	// std::printf("b\n");
//	// std::cout << "c\n";
//	// 解绑cin和cout关联绑定的其他流
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	return 0;
//}


//class Date
//{
//	friend ostream& operator << (ostream& out, const Date& d);
//	friend istream& operator >> (istream& in, Date& d);
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{}
//
//	operator bool() const
//	{
//		// 这里是随意写的，假设输入_year为0，则结束
//		if (_year == 0)
//			return false;
//		else
//			return true;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//istream& operator >> (istream& in, Date& d)
//{
//	in >> d._year >> d._month >> d._day;
//	return in;
//}
//
//ostream& operator << (ostream& out, const Date& d)
//{
//	out << d._year << " " << d._month << " " << d._day;
//	return out;
//}

// C++ IO流，使用面向对象+运算符重载的方式
// 能更好的兼容自定义类型，流插入和流提取
//int main()
//{
//	// 自动识别类型的本质--函数重载
//	// 内置类型可以直接使用--因为库里面ostream类型已经实现了
//	int i = 1;
//	double j = 2.2;
//	cout << i << endl;
//	cout << j << endl;
//
//	// 自定义类型则需要我们自己重载<< 和 >>
//	Date d(2022, 4, 10);
//	cout << d;
//	while (d)
//	{
//		cin >> d;
//		cout << d;
//	}
//	return 0;
//}


//#include<iostream>
//#include<fstream>
//#include<string>
//using namespace std;
//
//int main()
//{
//	int i = 0, j = 1;
//	
//
//	while (cin >> i >> j)
//	{
//		cout << i << ":" << j << endl;
//	}
//
//	cout << cin.good() << endl;
//	cout << cin.eof() << endl;
//	cout << cin.bad() << endl;
//	cout << cin.fail() << endl << endl;
//	// 流一旦发生错误就不能再用了，清理重置一下再能使用
//	cin.clear();
//
//	string s;
//	while (cin >> s)
//	{
//		cout << s << endl;
//	}
//}



































































































































































