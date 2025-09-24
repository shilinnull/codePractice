#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string.h>
using namespace std;

//int main()
//{
//	for (int i = 0; i < 50; i++)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	int* const p1 = &i;		// 顶层const
//	
//	const int ci = 111;		// 顶层const
//	const int* p2 = &ci;	// 底层const
//	const int& r = ci;		// 底层const
//	return 0;
//}


//int size()
//{
//	int n = 10;
//	return n;
//}
//
//int main()
//{
//	const int a = 1;		// a是常量表达式
//	const int b = a + 1;	// b是常量表达式
//	int c = 1;				// c不是常量表达式
//	const int d = c;		// d不是常量表达式
//	const int e = size();	// e不是常量表达式
//	
//	// 常量表达式可以做数组大小，vs不支持变长数组，所以这里数组大小必须是编译时确认的
//	int arr[a];
//	constexpr int aa = 1;
//	constexpr int bb = aa + 1;
//
//	//constexpr int cc = c;				// 报错
//	//constexpr int cc = size();		// 报错
//	//constexpr int* p1 = &d;			// 报错，权限放大了，constexpr修饰的是p1本身
//
//	const int* p2 = &d;
//	constexpr const int* p3 = &d;		// constexpr修饰的是p1本身，const修饰*p3
//	return 0;
//}

//constexpr int size()
//{
//	return 10;
//}
//constexpr int func(int x)
//{
//	return 10 + x;
//}
//constexpr int factorial(int n)
//{
//	return n <= 1 ? 1 : n * factorial(n - 1);
//}
//constexpr int fxx(int x)
//{
//	int i = x;
//	i++;
//	cout << i << endl;
//	return 10 + x;
//}
//
//int main()
//{
//	// 编译时，N会被直接替换为10，constexpr函数默认就是inline
//	constexpr int N1 = size();
//	int arr1[N1];
//	// func传10时，func函数返回值是常量表达式，所以N2是常量表达式
//	constexpr int N2 = func(10);
//	int arr2[N2];
//	
//	int i = 10;
//	constexpr int N3 = func(i); // 报错func返回的不是常量表达式
//	int N4 = func(i); // 不报错constexpr函数返回的不一是常量表达式
//
//	constexpr int fact5 = factorial(5); // 编译时计算
//	
//	// constexpr修饰的函数可以有一些其他语句，但是这些语句运行时可以不执行任何操作就可以
//	// 如类型别名、空语句、using声明等
//	constexpr int N5 = fxx(10); // 报错
//
//	return 0;
//}

//class Date
//{
//public:
//	constexpr Date(int year, int month, int day)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{
//		//cout << "constexpr Date(int year, int month, int day)" << endl;
//	}
//	constexpr int GetYear() const
//	{
//		return _year;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//template<typename T>
//constexpr T Func(T t)
//{
//	return t;
//}
//
//int main()
//{
//	int x = 2025;
//	// constexpr Date d0(x, 9, 8); // 报错 必须使用常量进行初始化
//	constexpr Date d1(2000, 1, 1);
//	constexpr int y = d1.GetYear();
//
//	Date d2(2000, 1, 1);
//	int z = d2.GetYear();
//	string ret1 = Func("111111"); // 普通函数
//	constexpr int ret2 = Func(10);
//	return 0;
//}

