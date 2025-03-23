#include<iostream>
using namespace std;



//class Time
//{
//public:
//	~Time()
//	{
//		cout << "~Time()" << endl;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//private:
//	// 基本类型(内置类型)
//	int _year = 1970;
//	int _month = 1;
//	int _day = 1;
//	// 自定义类型
//	Time _t;
//};
//int main()
//{
//	Date d;
//	return 0;
//}

//
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	Date(const Date& d) 
//	{
//		this->_year = d._year; 
//		this->_month = d._month;
//		this->_day = d._day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1(2024,2,1);
//	Date d2(d1);
//	return 0;
//}

//
//class Time
//{
//	p
//};

//class Date
//{
//public:
//
//	Date(int year = 2024, int month = 2, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//Date(const Date& d)
//	//{
//	//	this->_year = d._year;
//	//	this->_month = d._month;
//	//	this->_day = d._day;
//	//}
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
//	Date d1(2024, 2, 1);
//	Date d2(d1);
//	
//	d1.Print();
//	d2.Print();
//
//	return 0;
//}

//class Time
//{
//public:
//
//	// 强制让他生成
//	Time() = default;
//
//	Time(const Time& t)
//	{
//		_hour = t._hour;
//		_minute = t._minute;
//		_second = t._second;
//		cout << "Time::Time(const Time&)" << endl;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//
//class Date
//{
//public:
//	Date(int year = 2024, int month = 2, int day = 1)
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
//
//	// 自定义类型
//	Time _t;
//};
//int main()
//{
//	Date d1(2024,2,1);
//	Date d2(d1);
//	
//	d1.Print();
//	d2.Print();
//	return 0;
//}



//typedef int DataType;
//class Stack
//{
//public:
//	Stack(size_t capacity = 10)
//	{
//		_array = (DataType*)malloc(capacity * sizeof(DataType));
//		if (nullptr == _array)
//		{
//			perror("malloc申请空间失败");
//			return;
//		}
//		_size = 0;
//		_capacity = capacity;
//	}
//
//	Stack(const Stack& s)
//	{
//		// 深拷贝
//		DataType* tmp = (DataType*)malloc(s._capacity * sizeof(DataType));
//		if (nullptr == tmp)
//		{
//			perror("malloc fail\n");
//			exit(-1);
//		}
//		memcpy(tmp, s._array, sizeof(DataType) * s._size);
//		_array = tmp;
//		// 浅拷贝
//		_size = s._size;
//		_capacity = s._capacity;
//	}
//
//	void Push(const DataType& data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//	~Stack()
//	{
//		if (_array)
//		{
//			free(_array);
//			_array = nullptr;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//private:
//	DataType* _array;
//	size_t _size;
//	size_t _capacity;
//};
//int main()
//{
//	Stack s1;
//	s1.Push(1);
//	s1.Push(2);
//	s1.Push(3);
//	s1.Push(4);
//	Stack s2(s1);
//	return 0;
//}

class Date
{
public:
	Date(int year, int minute, int day)
	{
		cout << "Date(int,int,int):" << this << endl;
	}
	Date(const Date& d)
	{
		cout << "Date(const Date& d):" << this << endl;
	}
	~Date()
	{
		cout << "~Date():" << this << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
Date Test(Date d)
{
	Date temp(d);
	return temp;
}
int main()
{
	Date d1(2022, 1, 13);
	Test(d1);
	return 0;
}
