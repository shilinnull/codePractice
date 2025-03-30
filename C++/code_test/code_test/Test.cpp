#define _CRT_SECURE_NO_WARNINGS 1

#include "Date.h"


//int main()
//{
//    int a[10] = { 1,2,3,4,5,6 };
//    for (auto& e : a) {
//        cout << e << " ";
//    }
//
//    return 0;
//}


//class Date {
//public:
//    Date(int year = 1, int month = 1, int day = 1) {
//        _year = year;
//        _month = month;
//        _day = day;
//    }   
//    void print()  {
//        cout << _year << " " << _month << " " << _day << endl;
//    }
//
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//int main()
//{
//    Date d1;
//    d1.print();
//
//    return 0;
//}


//class Date
//{
//public:
//    // 1.无参构造函数
//    Date()
//    {
//        _year = 1;
//        _month = 1;
//        _day = 1;
//    }
//    // 2.带参构造函数
//    Date(int year, int month , int day )
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//	void print() {
//		cout << _year << " " << _month << "" << _day << endl;
//	}
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//void TestDate()
//{
//    //Date d1; // 调用无参构造函数
//    //Date d2(2015, 1, 1); // 调用带参的构造函数
//    //Date d3();
//    //d3.print();
//}
//
//int main() {
//
//    TestDate();
//    return 0;
//}

//class AA {
//public:
//	void func() {
//		cout << "A::func()" << endl;
//	}
//};
//
//typedef void(AA::*PF)(); // 成员函数指针类型
//
//int main() {
//	// C++规定成员函数要加&才能取到函数指针
//	PF pf = &AA::func;
//	AA obj; // 定义obj类对象temp
//	(obj.*pf)(); // 对象调用成员函数指针时，使⽤.*运算符
//
//	return 0;
//}


int main()
{
	//Date d1(2024, 11, 16);
	//Date d2(2024, 11, 16);
	//Date d3(2024, 10, 17);

	//cout << (d1 > d2) << endl;
	//cout << (d1 >= d2) << endl;
	//cout << (d1 == d2) << endl;

	//cout << (d1 > d3) << endl;
	//cout << (d1 >= d3) << endl;
	//cout << (d1 == d3) << endl;

	//Date d1(2025, 3, 29);
	////d1 += 7;
	////d1 += 7;
	//Date d2 = d1;
	//Date d3,d4;
	//d4 = d3 = d2 = d1;
	//d1 = d1;
	//d4 += -100;
	////d2 -= 10;
	////cout << (d1 >= d2) << endl;
	////cout << d1 << endl;
	//cout << d4 << endl;


	Date d1(2005, 10, 9), d2(2025, 3, 30);
	cout << (d1 - d2) << endl;
	cin >> d2;
	cout << d2 << endl;

	return 0;
}




































































