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
//// 1���������Ͳ�ͬ
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
//// 2������������ͬ
//void f()
//{
//	cout << "f()" << endl;
//}
//void f(int a)
//{
//	cout << "f(int a)" << endl;
//}
//// 3����������˳��ͬ
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
//	// �����ռ��п��Զ������/����/����
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
//	// �����ռ��п��Զ������/����/����
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
//	// �����Զ�ʶ�����������
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
//	Func(); // û�д���ʱ��ʹ�ò�����Ĭ��ֵ
//	Func(10); // ����ʱ��ʹ��ָ����ʵ��
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
//	// 1��ȷ��Ҫ����100������
//	StackInit(&st1, 100);  
//
//	// 2��ֻ����10������
//	struct Stack st2;
//	StackInit(&st2, 10);
//
//	// 3����֪��Ҫ������ٸ�
//	struct Stack st3;
//	StackInit(&st3);
//
//	return 0;
//}

// 1���������Ͳ�ͬ
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


// 2������������ͬ
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

// 3����������˳��ͬ
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
//	int& ra = a; // ������������&
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
//	// int& ra; // ����������ʱ�����,����Ҫ��ʼ��
//	int& ra = a;
//	int& rra = a;
//
//	printf("%p %p %p\n", &a, &ra, &rra);
//}

//void main()
//{
//	const int a = 10;
//	//int& ra = a; // ��������ʱ�����aΪ����
//
//	const int& ra = a;
//	// int& b = 10; // ��������ʱ�����bΪ����
//
//	const int& b = 10;
//	double d = 12.34;
//	//int& rd = d; // ��������ʱ��������Ͳ�ͬ
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
//	// ��ֵ��Ϊ��������
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//
//	// ��������Ϊ��������
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//
//	// �ֱ���������������н������ʱ��
//	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
//	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
//}
//#include <time.h>
//struct A { int a[10000]; };
//A a;
//// ֵ����
//A TestFunc1() { return a; }
//// ���÷���
//A& TestFunc2() { return a; }
//void main()
//{
//	// ��ֵ��Ϊ�����ķ���ֵ����
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc1();
//	size_t end1 = clock();
//	// ��������Ϊ�����ķ���ֵ����
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc2();
//	size_t end2 = clock();
//	// �������������������֮���ʱ��
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
//	// ��Ա����
//	int* a;
//	int size;
//	int capacity;
//
//	// ��Ա����
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
//		// ... ����
//		a[size++] = x;
//	}
//	// ��д���ر���
//	// ��ʱ�������г���
//	// ���Ա��뷵�����ã������м�û�в�����ʱ��������һ������
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
//	int& ra = a;  // �﷨�����ռ䣬
//	ra = 20;
//
//	int* pa = &a; // �﷨�Ͽ��ռ�
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




