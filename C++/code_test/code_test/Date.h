#pragma once

#include <iostream>
using namespace std;

class Date
{
public:
	// 获取某年某月的天数
	int GetMonthDay(int year, int month) {
		static int a[13] = { -1,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (month == 2 && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)) {
			return 29;
		}
		return a[month];
	}

	// 全缺省的构造函数
	Date(int year = 1900, int month = 1, int day = 1) {
		_year = year;
		_month = month;
		_day = day;
		if (!CheckInvalid())
		{
			cout << "构造日期非法" << endl;
			exit(-1);
		}
	}
	// 拷贝构造函数
	Date(const Date& d) {
		_year = d._year;
		_month = d._month;
		_day = d._day;
		if (!CheckInvalid())
		{
			cout << "构造日期非法" << endl;
			exit(-1);
		}
	}

	// 赋值运算符重载
	Date& operator=(const Date& d) {
		if (&d != this) {
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		if (!CheckInvalid())
		{
			cout << "构造日期非法" << endl;
			exit(-1);
		}
		return *this;
	}
	// 析构函数
	~Date(){}

	// 日期+=天数
	Date& operator+=(int day) {
		_day += day;
		while (_day > GetMonthDay(_year, _month)) {
			_day -= GetMonthDay(_year, _month);
			_month++;
			if (_month == 13) {
				_year++;
				_month = 1;
			}
		}
		return *this;
	}
	// 日期+天数
	Date operator+(int day) {
		Date tmp(*this);
		tmp += day;
		return tmp;
	}

	// 日期-天数
	Date operator-(int day) {
		Date tmp(*this);
		tmp -= day;
		return tmp;
	}

	// 日期-=天数
	Date& operator-=(int day) {
		_day -= day;
		while (_day < 0) {
			--_month;
			if (_month == 0) {
				--_year;
				_month = 12;
			}
			_day += GetMonthDay(_year, _month);
		}
		return *this;
	}

	// 前置++
	// ++d1
	Date& operator++() {
		return *this += 1;
	}

	// 后置++
	Date operator++(int) {
		Date tmp(*this);
		*this += 1;
		return tmp;
	}

	// 后置--
	Date operator--(int) {
		Date tmp(*this);
		*this -= 1;
		return tmp;
	}

	// 前置--
	Date& operator--() {
		return *this -= 1;
	}

	// >运算符重载
	bool operator>(const Date& d) {
		if (_year < d._year)
			return true;
		else if (_year == d._year && _month < d._month)
			return true;
		else
			return _day < d._day;
		return false;
	}

	// ==运算符重载
	bool operator==(const Date& d) {
		return _year == d._year && _month == d._month && _day == d._day;
	}

	// >=运算符重载
	bool operator>=(const Date& d) {
		return !(*this < d);
	}

	// <运算符重载
	bool operator<(const Date& d) {
		if (_year > d._year)
			return true;
		else if (_year == d._year && _month > d._month)
			return true;
		else
			return _day > d._day;
		return false;
	}

	// <=运算符重载
	bool operator<=(const Date& d) {
		return !(*this > d);
	}

	// !=运算符重载
	bool operator!=(const Date& d) {
		return !(*this == d);
	}

	// 日期-日期 返回天数
	int operator-(const Date& d) {

	}
	bool CheckInvalid() {
		if (_year <= 0 || _month < 1 || _month > 12 || _day < 1 || _day > GetMonthDay(_year, _month))
			return false;
		else
			return true;
	}
	void Print()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}

	friend ostream& operator<<(ostream& out, const Date& d);
private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "年" << d._month << "月" << d._day << "日" << endl;
	return out;
}
