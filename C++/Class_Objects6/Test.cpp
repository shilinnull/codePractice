#include<iostream>

using namespace std;

//
//class Date
//{
//public:
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//void Print()
//	//{
//	//	cout << "Print()" << endl;
//	//	cout << "year:" << _year << endl;
//	//	cout << "month:" << _month << endl;
//	//	cout << "day:" << _day << endl << endl;
//	//}
//	void Print() const
//	{
//		cout << "Print()const" << endl;
//		cout << "year:" << _year << endl;
//		cout << "month:" << _month << endl;
//		cout << "day:" << _day << endl << endl;
//	}
//private:
//	int _year; // ��
//	int _month; // ��
//	int _day; // ��
//};
//
//
//
//int main()
//{
//	// ����ͱ��Ȩ�޵���С��
//	Date d1(2022, 1, 13);
//	d1.Print();
//	
//	const Date d2(2022, 1, 13);
//	// ����һ��Ȩ�޵ķŴ�
//	d2.Print();
//
//	return 0;
//}


//class Date
//{
//public:
//	Date* operator&()
//	{
//		return this;
//	}
//	const Date* operator&()const
//	{
//		return this;
//	}
//private:
//	int _year; // ��
//	int _month; // ��
//	int _day; // ��
//};
//

//class Date
//{
//public:
//	Date(int year, int month, int day)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//class A
//{
//public:
//	A(int a)
//		:_a(a)
//	{}
//private:
//	int _a;
//};
//class B
//{
//public:
//	B(int a, int ref)
//		:_aobj(a)
//		, _ref(ref)
//		, _n(10)
//	{}
//private:
//	A _aobj; // û��Ĭ�Ϲ��캯��
//	int& _ref; // ����
//	const int _n; // const
//};

//class Time
//{
//public:
//	Time(int hour = 0)
//		:_hour(hour)
//	{
//		cout << "Time()" << endl;
//	}
//private:
//	int _hour;
//};
//class Date
//{
//public:
//	Date(int day)
//	{}
//private:
//	int _day;
//	Time _t;
//};
//int main()
//{
//	Date d(1);
//}






//class A
//{
//public:
//	A(int a)
//		:_a1(a)
//		, _a2(_a1)
//	{}
//	void Print() {
//		cout << _a1 << " " << _a2 << endl;
//	}
//private:
//	int _a2;
//	int _a1;
//};
//int main() {
//	A aa(1);
//	aa.Print();
//} 
//A.���1 1
//B.�������
//C.���벻ͨ��
//D.���1 ���ֵ




//class Date
//{
//public:
//	// 1. ���ι��캯����û��ʹ��explicit���Σ���������ת������
//	// explicit���ι��캯������ֹ����ת��---explicitȥ��֮�󣬴������ͨ������
//	explicit Date(int year)
//		:_year(year)
//	{}
//	/*
//	// 2. ��Ȼ�ж�����������Ǵ�������ʱ�������������Բ����ݣ�û��ʹ��explicit���Σ���
//	������ת������
//	// explicit���ι��캯������ֹ����ת��
//	explicit Date(int year, int month = 1, int day = 1)
//	: _year(year)
//	, _month(month)
//	, _day(day)
//	{}
//	*/
//	Date& operator=(const Date& d)
//	{
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//		return *this;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//void Test()
//{
//	Date d1(2022);
//	// ��һ�����α������������Ͷ���ֵ
//	// ʵ�ʱ������������2023����һ������������������������d1������и�ֵ
//	d1 = 2023;
//	// ��1���ε���2�ſ�ʱ�����ʧ�ܣ���Ϊexplicit���ι��캯������ֹ�˵��ι��캯������ת��������
//}


//class A
//{
//public:
//	A() { 
//		++_scount; 
//	}
//	A(const A& t) {
//		++_scount; 
//	}
//	~A() {
//		--_scount; 
//	}
//	static int GetACount() { 
//		return _scount; 
//	}
//private:
//	static int _scount;
//};
//
//// ����������г�ʼ��
//int A::_scount = 0;
//
//void main()
//{
//	cout << A::GetACount() << endl;
//	A a1, a2;
//	A a3(a1);
//	cout << A::GetACount() << endl;
//}

//class Date
//{
//public:
//	Date(int year, int month, int day)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//	// d1 << cout; -> d1.operator<<(&d1, cout); �����ϳ������
//	// ��Ϊ��Ա������һ������һ�������ص�this������d1�������<<�����
//	ostream& operator<<(ostream& _cout)
//	{
//		_cout << _year << "-" << _month << "-" << _day << endl;
//		return _cout;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//class Date
//{
//	friend ostream& operator<<(ostream& _cout, const Date& d);
//	friend istream& operator>>(istream& _cin, Date& d);
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//ostream& operator<<(ostream& _cout, const Date& d)
//{
//	_cout << d._year << "-" << d._month << "-" << d._day;
//	return _cout;
//}
//istream& operator>>(istream& _cin, Date& d)
//{
//	_cin >> d._year;
//	_cin >> d._month;
//	_cin >> d._day;
//	return _cin;
//}
//int main()
//{
//	Date d;
//	cin >> d;
//	cout << d << endl;
//	return 0;
//}

//class A
//{
//private:
//	static int k;
//	int h;
//public:
//	class B // B��������A����Ԫ
//	{
//	public:
//		void foo(const A& a)
//		{
//			cout << k << endl;//OK
//			cout << a.h << endl;//OK
//		}
//	};
//};
//int A::k = 1;
//int main()
//{
//	A::B b;
//	b.foo(A());
//	return 0;
//}


//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a;
//};
//class Solution {
//public:
//	int Sum_Solution(int n) {
//		//...
//		return n;
//	}
//};
//int main()
//{
//	A aa1;
//	// ������ô���������Ϊ�������޷�ʶ��������һ���������������Ƕ�����
//	//A aa1();
//	// �������ǿ�����ô����������������������ص㲻��ȡ���֣�
//	// ����������������ֻ����һ�У����ǿ��Կ�����һ�����ͻ��Զ�������������
//	A();
//	A aa2(2);
//	// �������������������¾ͺܺ��ã���Ȼ����һЩ����ʹ�ó�������������Ժ���������˵
//	Solution().Sum_Solution(10);
//	return 0;
//}

#include <iostream>
using namespace std;
int main()
{
    int year, mon, day;
    int data[] = {0, 31,28,31,30,31,30,31,31,30,31,30,31 };
    while (cin >> year >> mon >> day)
    {
        int sum = 0;
        for (int i = 1; i <= mon; i++)
        {
            sum = sum + data[i];
        }
        if ((year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) && mon > 2)
            sum = sum + 1;
        else
            sum = sum + day;
        cout << sum << endl;

    }
    return 0;
}