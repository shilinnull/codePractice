#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;



//class A
//{
//public:
//	// 构造函数explicit就不再支持隐式类型转换
//	// explicit A(int a1)
//	A(int a1)
//		:_a1(a1)
//	{}
//
//	A(const A& aa)
//		:_a1(aa._a1)
//		,_a2(aa._a2)
//	{}
//
//	// explicit A(int a1, int a2)
//	A(int a1, int a2)
//		:_a1(a1)
//		, _a2(a2)
//	{}
//
//	void Print()
//	{
//		cout << _a1 << " " << _a2 << endl;
//	}
//
//	int Get() const
//	{
//		return _a1 + _a2;
//	}
//
//private:
//	int _a1 = 1;
//	int _a2 = 2;
//};
//
//class B
//{
//public:
//	B(const A& a)
//		:_b(a.Get())
//	{}
//private:
//	int _b = 0;
//};
//
//class Stack
//{
//public:
//	void Push(const A& aa)
//	{}
//};
//
//int main()
//{
//	// 编译器遇到连续的构造+拷贝构造->优化为直接构造
//	A aa1(1);
//	A aa2(1, 1);
//
//	// 临时对象具有常性，必须加const
//	A aa3 = 1;
//	const A& aa4 = 1; 
//
//	// C++11之后才支持多参数转化
//	A aa5 = { 2, 2 };
//	const A& aa6 = { 2, 2 };
//
//	// 7先隐式类型转换成A对象，由于A对象中有构造函数，调用初始化成7，然后返回A对象Push
//	Stack st;
//	st.Push(7);
//	st.Push({8, 8});
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	A(int a = 0)
//		:_a1(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//	A(const A& aa)
//		:_a1(aa._a1)
//	{
//		cout << "A(const A& aa)" << endl;
//	}
//	A& operator=(const A& aa)
//	{
//		cout << "A& operator=(const A& aa)" << endl;
//		if (this != &aa)
//		{
//			_a1 = aa._a1;
//		}
//		return *this;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a1 = 1;
//};
//void f1(A aa)
//{
//}
//A f2()
//{
//	A aa;
//	return aa;
//}
//int main()
//{
//	// 传值传参
//	// 构造+拷贝构造
//	A aa1;
//	f1(aa1);
//	cout << endl;
//	// 隐式类型，连续构造+拷贝构造->优化为直接构造
//	f1(1);
//	// 一个表达式中，连续构造+拷贝构造->优化为一个构造
//	f1(A(2));
//	cout << endl;
//	cout << "***********************************************" << endl;
//	// 传值返回
//	// 不优化的情况下传值返回，编译器会生成一个拷贝返回对象的临时对象作为函数调用表达式的返回值
//	// 无优化 （vs2019 debug）
//	// 一些编译器会优化得更厉害，将构造的局部对象和拷贝构造的临时对象优化为直接构造（vs2022 debug）
//	f2();
//	cout << endl;
//	// 返回时一个表达式中，连续拷贝构造+拷贝构造->优化一个拷贝构造 （vs2019 debug）
//	// 一些编译器会优化得更厉害，进行跨行合并优化，将构造的局部对象aa和拷贝的临时对象和接收返回值对象aa2优化为一个直接构造。（vs2022 debug）
//	A aa2 = f2();
//	cout << endl;
//	// 一个表达式中，开始构造，中间拷贝构造+赋值重载->无法优化（vs2019 debug）
//	// 一些编译器会优化得更厉害，进行跨行合并优化，将构造的局部对象aa和拷贝临时对象合并为一个直接构造（vs2022 debug）
//	aa1 = f2();
//	cout << endl;
//	return 0;
//}


//class A
//{
//public:
//    A(int a = 0)
//        : _a(a)
//    {
//        cout << "A():" << this << endl;
//    }
//    ~A()
//    {
//        cout << "~A():" << this << endl;
//    }
//private:
//    int _a;
//};
//
//// 定位new/replacement new
//int main()
//{
//    // p1现在指向的只不过是与A对象相同大小的一段空间，还不能算是一个对象，因为构造函数没有执行
//    A* p1 = (A*)malloc(sizeof(A));
//    new(p1)A; // 注意：如果A类的构造函数有参数时，此处需要传参
//    p1->~A();
//    free(p1);
//    A* p2 = (A*)operator new(sizeof(A));
//    new(p2)A(10);
//    p2->~A();
//    operator delete(p2);
//    return 0;
//}
//
//



template<typename T>
T Swap(T x,T y) {
	return x + y;
}














