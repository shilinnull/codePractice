#include<iostream>

using namespace std;



//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		this->_year = year;
//		this->_month = month;
//		this->_day = day;
//	}
//	void print()
//	{
//		//cout << this << endl;
//		cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
//		
//	}
//private:
//	int _year; 
//	int _month; 
//	int _day; 
//};
//int main()
//{
//	Date d1, d2;
//	
//
//	cout << "d1:" << &d1 << endl;
//	cout << "d2:" << &d2 << endl;
//
//
//	d1.Init(2024, 1, 26);
//	d2.Init(2022, 2, 27);
//
//	d1.print();
//	d2.print();
//	return 0;
//}


// this指针存在哪里？
// a、堆   b、栈   c、静态区   d、常量区  e、对象里面
//
//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		year = year;
//		month = month;
//		day = day;
//	}
//	void print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//		
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//int main()
//{
//	Date d1;
//	d1.Init(2024, 1, 27);
//
//	Date d2;
//	d2.Init(2024, 2, 28);
//
//	const int i = 0;
//	int j = 1;
//
//	cout << &i << endl;
//	cout << &j << endl;
//
//	const char* p = "xzxxxxxx";
//	cout << (void*)p << endl;
//	//cout << &p << endl;
//
//	return 0;
//}

// 1.下面程序编译运行结果是？ A、编译报错 B、运行崩溃 C、正常运行

//class A
//{
//public:
//	void PrintA()
//	{
//		cout << _a << endl;
//
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A* p = nullptr;
//	p->PrintA();
//
//
//	return 0;
//}


// 1.下面程序编译运行结果是？ A、编译报错 B、运行崩溃 C、正常运行
//class A
//{
//public:
//	void Print()
//	{
//		cout << "Print()" << endl;
//	}
//private:
//	int _a;
//};
//int main()
//{
//	A* p = nullptr;
//	p->Print();
//	return 0;
//}


//
//class A
//{
//public:
//	void PrintA()
//	{
//		cout << this->_a << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A* p = nullptr;
//
//	p->PrintA();
//	// 下面这个和上面那个p->PrintA一样
//	(*p).PrintA();
//
//	return 0;
//}





