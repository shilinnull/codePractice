#include"Stack.h"




//void Stack::Init(int n)
//{
//	a = (int*)malloc(sizeof(int) * n);
//	if (nullptr == a)
//	{
//		perror("malloc…Í«Îø’º‰ ß∞‹");
//		return;
//	}
//
//	capacity = n;
//	top = 0;
//}
//
//void Stack::Push(int x)
//{
//	//...
//	a[top++] = x;
//}



//class Date
//{
//
//private:
//	int _year;
//	int _month;
//	int _day;
//
//	void print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//
//public:
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//};



// ≥…‘±∫Ø ˝
void Stack::Init(size_t capacity)
{
	_array = (DataType*)malloc(sizeof(DataType) * capacity);
	if (nullptr == _array)
	{
		perror("malloc…Í«Îø’º‰ ß∞‹");
		return;
	}
	_capacity = capacity;
	_size = 0;
}
void Stack::Push(const DataType& data)
{
	// ¿©»›
	_array[_size] = data;
	++_size;
}
DataType Stack::Top()
{
	return _array[_size - 1];
}
void Stack::Destroy()
{
	if (_array)
	{
		free(_array);
		_array = nullptr;
		_capacity = 0;
		_size = 0;
	}
}
