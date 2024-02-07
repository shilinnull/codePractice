#include<iostream>
using namespace std;

//int main()
//{
//	double d = 1.1;
//	int i = d; // 强制类型转换
//	int& ri = d; // 无法赋予，类型不同
//	const int& ri = d; // 加上const就可以了
//
//	return 0;
//}
// 


//
//class Date
//{
//public:
//	Date(int y = 1, int m = 1, int r = 1)
//	{
//		_y = y;
//		_m = m;
//		_r = r;
//	}
//
//
//	Date& operator = (const Date & d)
//	{
//		if (this != &d)
//		{
//			_y = d._r;
//			_m = d._m;
//			_r = d._r;
//		}
//		return *this;
//	}
//private:
//	int _y;
//	int _m;
//	int _r;
//};
//
//int main()
//{
//	Date d1(2022, 1, 1);
//	Date d2(2022, 2, 2);
//	
//	d1 = d2;
//}


//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1;
//	d1.Init(2022, 7, 5);
//	d1.Print();
//	Date d2;
//	d2.Init(2022, 7, 6);
//	d2.Print();
//	return 0;
//}


//class Date
//{
//public:
//
//	Date()
//	{
//		_year = 1;
//		_month = 1;
//		_day = 1;
//	}
//
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void print()
//	{
//		cout <<  _year << "/" << _month << "/" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1; // 调用无参构造函数
//	Date d2(2015, 1, 1); // 调用带参的构造函数
//
//	d1.print();
//	d2.print();
//
//	//Date d3();
//	return 0;
//}

//class A
//{
//public:
//	A()
//	{
//		cout << "A()" << endl;
//		_a = 0;
//	}
//private:
//	int _a;
//};
//class Date
//{
//public:
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//private:
//	// 声明给缺省值
//	int _year = 1;
//	int _month = 1;
//	int _day = 1;
//
//	A _aa;
//};
//int main()
//{
//	Date d1;
//	d1.Print();
//	return 0;
//}

//class Date
//{
//public:
//	
//	Date()
//	{}
//	// 如果用户显式定义了构造函数，编译器将不再生成
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1;
//	d1.Print();
//	return 0;
//}
//
//// 将Date类中构造函数屏蔽后，代码可以通过编译，因为编译器生成了一个无参的默认构造函数
//// 将Date类中构造函数放开，代码编译失败，因为一旦显式定义任何构造函数，编译器将不再生成
//// 无参构造函数，放开后报错：error C2512: “Date”: 没有合适的默认构造函数可用

//class Stack
//{
//public:
//	Stack()
//	{
//		//....
//		cout << "Stack()" << endl;
//	}
//};
//
//
//// 两个栈实现队列
//class MyQueue
//{
//private:
//	Stack st1;
//	Stack st2;
//};
//
//int main()
//{
//	MyQueue q;
//	return 0;
//}

//typedef int DataType;
//class Stack
//{
//public:
//	Stack(size_t capacity = 4)
//	{
//		_array = (DataType*)malloc(sizeof(DataType) * capacity);
//		if (nullptr == _array)
//		{
//			perror("malloc申请空间失败!!!");
//			return;
//		}
//		_capacity = capacity;
//		_size = 0;
//	}
//	void Push(DataType data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//	// 其他方法...
//	~Stack()
//	{
//		if (_array)
//		{
//			free(_array);
//			_array = nullptr;
//			_capacity = 0;
//			_size = 0;
//			// 打印一下，看一下调用没有
//			cout << "~Stack" << endl;
//		}
//	}
//	void print()
//	{
//		while (_size)
//		{
//			cout << _array[_size - 1] << endl;
//			_size--;
//		}
//	}
//
//private:
//	DataType* _array;
//	int _capacity;
//	int _size;
//};
//void main()
//{
//	Stack s;
//	s.Push(1);
//	s.Push(2);
//	s.print();
//
//	Stack s1;
//	s1.Push(3);
//	s1.Push(4);
// 	s1.print();
//	cout << "he";
//
//}


class Time
{
public:
	~Time()
	{
		cout << "~Time()" << endl;
	}
private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
private:
	// 基本类型(内置类型)
	int _year = 1970;
	int _month = 1;
	int _day = 1;
	// 自定义类型
	Time _t;
};
int main()
{
	Date d;
	return 0;
}






