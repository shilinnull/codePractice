#include<iostream>
using namespace std;

//int main()
//{
//	double d = 1.1;
//	int i = d; // ǿ������ת��
//	int& ri = d; // �޷����裬���Ͳ�ͬ
//	const int& ri = d; // ����const�Ϳ�����
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
//	Date d1; // �����޲ι��캯��
//	Date d2(2015, 1, 1); // ���ô��εĹ��캯��
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
//	// ������ȱʡֵ
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
//	// ����û���ʽ�����˹��캯��������������������
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
//// ��Date���й��캯�����κ󣬴������ͨ�����룬��Ϊ������������һ���޲ε�Ĭ�Ϲ��캯��
//// ��Date���й��캯���ſ����������ʧ�ܣ���Ϊһ����ʽ�����κι��캯��������������������
//// �޲ι��캯�����ſ��󱨴�error C2512: ��Date��: û�к��ʵ�Ĭ�Ϲ��캯������

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
//// ����ջʵ�ֶ���
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
//			perror("malloc����ռ�ʧ��!!!");
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
//	// ��������...
//	~Stack()
//	{
//		if (_array)
//		{
//			free(_array);
//			_array = nullptr;
//			_capacity = 0;
//			_size = 0;
//			// ��ӡһ�£���һ�µ���û��
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
	// ��������(��������)
	int _year = 1970;
	int _month = 1;
	int _day = 1;
	// �Զ�������
	Time _t;
};
int main()
{
	Date d;
	return 0;
}






