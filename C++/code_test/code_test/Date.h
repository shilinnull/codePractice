#pragma once

#include <iostream>
using namespace std;

class Date
{
public:
	// ��ȡĳ��ĳ�µ�����
	int GetMonthDay(int year, int month) {
		static int a[13] = { -1,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (month == 2 && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)) {
			return 29;
		}
		return a[month];
	}

	// ȫȱʡ�Ĺ��캯��
	Date(int year = 1900, int month = 1, int day = 1) {
		_year = year;
		_month = month;
		_day = day;
		if (!CheckInvalid())
		{
			cout << "�������ڷǷ�" << endl;
			exit(-1);
		}
	}
	// �������캯��
	Date(const Date& d) {
		_year = d._year;
		_month = d._month;
		_day = d._day;
		if (!CheckInvalid())
		{
			cout << "�������ڷǷ�" << endl;
			exit(-1);
		}
	}

	// ��ֵ���������
	Date& operator=(const Date& d) {
		if (&d != this) {
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		if (!CheckInvalid())
		{
			cout << "�������ڷǷ�" << endl;
			exit(-1);
		}
		return *this;
	}
	// ��������
	~Date(){}

	// ����+=����
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
	// ����+����
	Date operator+(int day) {
		Date tmp(*this);
		tmp += day;
		return tmp;
	}

	// ����-����
	Date operator-(int day) {
		Date tmp(*this);
		tmp -= day;
		return tmp;
	}

	// ����-=����
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

	// ǰ��++
	// ++d1
	Date& operator++() {
		return *this += 1;
	}

	// ����++
	Date operator++(int) {
		Date tmp(*this);
		*this += 1;
		return tmp;
	}

	// ����--
	Date operator--(int) {
		Date tmp(*this);
		*this -= 1;
		return tmp;
	}

	// ǰ��--
	Date& operator--() {
		return *this -= 1;
	}

	// >���������
	bool operator>(const Date& d) {
		if (_year < d._year)
			return true;
		else if (_year == d._year && _month < d._month)
			return true;
		else
			return _day < d._day;
		return false;
	}

	// ==���������
	bool operator==(const Date& d) {
		return _year == d._year && _month == d._month && _day == d._day;
	}

	// >=���������
	bool operator>=(const Date& d) {
		return !(*this < d);
	}

	// <���������
	bool operator<(const Date& d) {
		if (_year > d._year)
			return true;
		else if (_year == d._year && _month > d._month)
			return true;
		else
			return _day > d._day;
		return false;
	}

	// <=���������
	bool operator<=(const Date& d) {
		return !(*this > d);
	}

	// !=���������
	bool operator!=(const Date& d) {
		return !(*this == d);
	}

	// ����-���� ��������
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
	out << d._year << "��" << d._month << "��" << d._day << "��" << endl;
	return out;
}
