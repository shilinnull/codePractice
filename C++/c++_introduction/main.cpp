//#include<iostream>


//using namespace std;

//
//int main()
//{
//	int i = 0;
//	//cout << "hello " "world" << i << endl;
//	double a = 1.11111111;
//	//cin >> i;
//	//cout << i << endl;
//	cout.precision(5);
//	cout << a << endl;
//	return 0;
//}
//


//#include<iostream>
//using namespace std;
//// 1、参数类型不同
//int Add(int left, int right)
//{
//	cout << "int Add(int left, int right)" << endl;
//	return left + right;
//}
//double Add(double left, double right)
//{
//	cout << "double Add(double left, double right)" << endl;
//	return left + right;
//}
//// 2、参数个数不同
//void f()
//{
//	cout << "f()" << endl;
//}
//void f(int a)
//{
//	cout << "f(int a)" << endl;
//}
//// 3、参数类型顺序不同
//void f(int a, char b)
//{
//	cout << "f(int a,char b)" << endl;
//}
//void f(char b, int a)
//{
//	cout << "f(char b, int a)" << endl;
//}
//int main()
//{
//	Add(10, 20);
//	Add(10.1, 20.2);
//	f();
//	f(10);
//	f(10, 'a');
//	f('a', 10);
//	return 0;
//}

//void Func(int a = 10, int b = 20, int c = 30, int d = 40)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//	cout << "d = " << d << endl << endl;
//
//}
//
//int main()
//{
//	Func(1,2,3,4);
//	Func(2,3,4);
//	Func(3,4);
//	Func(4);
//
//	return 0;
//}





//
//int main()
//{
//	int a = 0;
//	int& b = a;
//	
//	cout << &a << endl;
//	cout << &b << endl;
//
//	return 0;
//}

//
//int& fun()
//{
//	int a = 2;
//	return a;
//}
//
//int main()
//{
//	int& ret = fun();
//	
//	cout << ret << endl;
//
//	return 0;
//}

//
//inline int Add(int x, int y)
//{
//	return x + y;
//}
//
//
//int main()
//{
//	int ret = 0;
//	auto i = 0;
//	NULL;
//	nullptr;
//	ret = Add(1, 2);
//	return 0;
//}
//
//class A2
//{
//public:
//	void f2()
//	{}
//};
//
//int main()
//{
//	cout << sizeof(A2) << endl;
//}


//#include <stdio.h>
//#include <stdlib.h>
//int rand = 10;
//
//int main()
//{
//	printf("%d\n", rand);
//	return 0;
//}

//#include <stdlib.h>

//namespace lsl 
//{
//	// 命名空间中可以定义变量/函数/类型
//	int rand = 10;
//	
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//
//	struct Node
//	{
//		struct Node* next;
//		int val;
//	};
//}


//namespace N1
//{
//	int a;
//	int b;
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//	namespace N2
//	{
//		int c;
//		int d;
//		int Sub(int left, int right)
//		{
//			return left - right;
//		}
//	}
//}

#include "test.h"

//namespace lsl
//{
//	// 命名空间中可以定义变量/函数/类型
//	int a = 0;
//	int b = 1;
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//	struct Node
//	{
//		struct Node* next;
//		int val;
//	};
//}
//
//using namespace lsl;
//
//int main()
//{
//	printf("%d\n", lsl::a);
//
//	printf("%d\n", b);
//
//	return 0;
//}
//
//using lsl::b;

//int main()
//{
//	printf("%d\n", lsl::a);
//	return 0;
//}


//int main()
//{
//	printf("%d\n", a);
//	return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//
//
//int main()
//{
//	cout << "hello world" << endl;
//
//	return 0;
//}


//#include <iostream>
//using namespace std;
//int main()
//{
//	int a;
//	double b;
//	char c;
//	// 可以自动识别变量的类型
//	cin >> a;
//	cin >> b >> c;
//	cout << a << endl;
//	cout << b << " " << c << endl;
//	return 0;
//}

//void Func(int a = 0)
//{
//	cout << a << endl;
//}
//int main()
//{
//	Func(); // 没有传参时，使用参数的默认值
//	Func(10); // 传参时，使用指定的实参
//	return 0;
//}

//void Func(int a = 10, int b = 20, int c = 30)
//{
//	cout << "a = "<< a <<endl;
//	cout << "b = "<< b <<endl;
//	cout << "c = " << c << endl << endl;
//}
//
//
//
//int main()
//{
//	Func(1,2,3);
//	Func(2,3);
//	Func(1);
//	Func();
//	return 0;
//}

#include "test.h"

//int main()
//{
//	struct Stack st1;
//
//	// 1、确定要插入100个数据
//	StackInit(&st1, 100);  
//
//	// 2、只插入10个数据
//	struct Stack st2;
//	StackInit(&st2, 10);
//
//	// 3、不知道要插入多少个
//	struct Stack st3;
//	StackInit(&st3);
//
//	return 0;
//}

// 1、参数类型不同
//int Add(int left, int right)
//{
//	cout << "int Add(int left, int right)" << endl;
//	return left + right;
//}
//double Add(double left, double right)
//{
//	cout << "double Add(double left, double right)" << endl;
//	return left + right;
//}


// 2、参数个数不同
//void f()
//{
//	cout << "f()" << endl;
//}
//
//void f(int a)
//{
//	cout << "f(int a)" << endl;
//}
// 

// 3、参数类型顺序不同
//void f(int a, char b)
//{
//	cout << "f(int a,char b)" << endl;
//}
//
//void f(char b, int a)
//{
//	cout << "f(char b, int a)" << endl;
//}



//int main()
//{
//	f(10, 'a');
//	f('a', 10);
//
//
//	//f();
//	//f(10);
//
//	//Add(10, 20);
//	//Add(10.1, 20.2);
//
//	return 0;
//}

//double compare(int, int)
//{}
//
//
//
////int compare(double, double)
////{}
//double compare(double, double)
//{}
//double compare(double, int)
//{}
////int compare(int, int)
////{}
//
//int main()
//{
//	return 0;
//}


//int main()
//{
//	int a = 10;
//	int& ra = a; // 定义引用类型&
//
//	ra++;
//	a++;
//	printf("%d\n", a);
//	printf("%d\n", ra);
//
//	//printf("%p\n", &a);
//	//printf("%p\n", &ra);
//	return 0;
//}



//void main()
//{
//	int a = 10;
//	// int& ra; // 该条语句编译时会出错,必须要初始化
//	int& ra = a;
//	int& rra = a;
//
//	printf("%p %p %p\n", &a, &ra, &rra);
//}

//void main()
//{
//	const int a = 10;
//	//int& ra = a; // 该语句编译时会出错，a为常量
//
//	const int& ra = a;
//	// int& b = 10; // 该语句编译时会出错，b为常量
//
//	const int& b = 10;
//	double d = 12.34;
//	//int& rd = d; // 该语句编译时会出错，类型不同
//
//	const int& rd = d;
//}
//void Swap(int* a, int* b)
//{
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//
//
//
//void Swap(int& a, int& b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//
//
//int main()
//{
//	int x = 0, y = 1;
//
//	Swap(x, y);
//
//
//
//	Swap(&x, &y);
//	return 0;
//}

//void PushBack(struct Node*& phead, int x)
//{
//	phead = nullptr;
//}
//
//int main()
//{
//	struct Node* plist = NULL;
//
//	return 0;
//}


//#include <time.h>
//
//struct A { int a[10000]; };
//void TestFunc1(A a) {}
//void TestFunc2(A& a) {}
//
//void main()
//{
//	A a;
//	// 以值作为函数参数
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//
//	// 以引用作为函数参数
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//
//	// 分别计算两个函数运行结束后的时间
//	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
//	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
//}
//#include <time.h>
//struct A { int a[10000]; };
//A a;
//// 值返回
//A TestFunc1() { return a; }
//// 引用返回
//A& TestFunc2() { return a; }
//void main()
//{
//	// 以值作为函数的返回值类型
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc1();
//	size_t end1 = clock();
//	// 以引用作为函数的返回值类型
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc2();
//	size_t end2 = clock();
//	// 计算两个函数运算完成之后的时间
//	cout << "TestFunc1 time:" << end1 - begin1 << endl;
//	cout << "TestFunc2 time:" << end2 - begin2 << endl;
//}



//
//int& func()
//{
//	int a = 0;
//	return a;
//}
//
//int main()
//{
//	int ret = func();
//	cout << ret << endl;
//
//	return 0;
//}
//

//
//int& func()
//{
//	int a = 0;
//	return a;
//}
//
//int& fx()
//{
//	int b = 1;
//	return b;
//}
//
//int main()
//{
//	int& ret = func();
//	cout << ret << endl;
//
//	fx();
//	cout << ret << endl;
//
//	return 0;
//}
//#include<assert.h>
//
//struct SeqList
//{
//	// 成员变量
//	int* a;
//	int size;
//	int capacity;
//
//	// 成员函数
//	void Init()
//	{
//		a = (int*)malloc(sizeof(int) * 4);
//		// ...
//		size = 0;
//		capacity = 4;
//	}
//
//	void PushBack(int x)
//	{
//		// ... 扩容
//		a[size++] = x;
//	}
//	// 读写返回变量
//	// 临时变量具有常性
//	// 所以必须返回引用，引用中间没有产生临时变量，是一个别名
//	int& Get(int pos)
//	{
//		assert(pos >= 0);
//		assert(pos < size);
//
//		return a[pos];
//	}
//
//
//};
//
//int main()
//{
//	SeqList s;
//	s.Init();
//	s.PushBack(1);
//	s.PushBack(2);
//	s.PushBack(3);
//	s.PushBack(4);
//
//	for (int i = 0; i < s.size; i++)
//	{
//		cout << s.Get(i) << " ";
//	}
//	cout << endl;
//
//	for (int i = 0; i < s.size; i++)
//	{
//		if (s.Get(i) % 2 == 0)
//		{
//			s.Get(i) *= 2;
//		}
//	}
//	cout << endl;
//
//	for (int i = 0; i < s.size; i++)
//	{
//		cout << s.Get(i) << " ";
//	}
//	cout << endl;
//
//	return 0;
//}


//
//int main()
//{
//	int a = 10;
//	int& ra = a;  // 语法不开空间，
//	ra = 20;
//
//	int* pa = &a; // 语法上开空间
//	*pa = 20;
//
//	return 0;
//}

//inline int Add(int a, int b)
//{
//	return a + b;
//}
//
//int main()
//{
//	int ret1 = Add(1, 2) * 3;
//
//	int x = 1, y = 2;
//	int ret2 = Add(x | y, x & y);
//
//	return 0;
//}




