#pragma once

#include <iostream>
using namespace std;

class Date
{
public:
	// �ж�����
	bool is_year(int year) {
		return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
	}
	// ��ȡĳ��ĳ�µ�����
	int GetMonthDay(int year, int month) {
		static int a[13] = { -1,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (month == 2 && is_year(year)) {
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
		return *this;
	}
	// ��������
	~Date() {}

	// ����+=����
	Date& operator+=(int day) {
		if (day < 0)
			return *this -= (-day);
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
		if (day < 0)
			return *this += (-day);
		_day -= day;
		while (_day <= 0) {
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
	Date& operator++() {
		*this += 1;
		return *this;
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
		if (_year > d._year)
			return true;
		else if (_year == d._year && _month > d._month)
			return true;
		else if(_year == d._year && _month == d._month)
			return _day > d._day;
		return false;
	}

	// ==���������
	bool operator==(const Date& d) {
		return _year == d._year && _month == d._month && _day == d._day;
	}

	// >=���������
	bool operator>=(const Date& d) {
		return (*this > d || *this == d);
	}

	// <���������
	bool operator<(const Date& d) {
		return !(*this >= d);
	}

	// <=���������
	bool operator<=(const Date& d) {
		return !(*this > d);
	}

	// !=���������
	bool operator!=(const Date& d) {
		return !(*this == d);
	}
#if 0
	// ����-���� ��������
	int operator-(const Date& d) {
		// ����d1�ӹ�ԪԪ�꿪ʼ��������
		int d1 = 0;
		for (int year = 1; year < _year; ++year) {
			d1 += is_year(year) ? 366 : 365;
		}
		for (int month = 1; month < _month; ++month) {
			d1 += GetMonthDay(_year, month);
		}
		d1 += _day;

		// ����d2�ӹ�ԪԪ�꿪ʼ��������
		int d2 = 0;
		for (int year = 1; year < d._year; ++year) {
			d2 += is_year(year) ? 366 : 365;
		}
		for (int month = 1; month < d._month; ++month) {
			d2 += GetMonthDay(d._year, month);
		}
		d2 += d._day;

		// �����������ڵ�������
		int day = d1 - d2;
		if (day < 0) {
			day = -day;
		}

		return day;
	}
#endif

	// ����-���� ��������
	int operator-(const Date& d) {
		int flag = 1;
		Date max = *this,min = d;
		if (max < min) {
			max = d;
			min = *this;
			flag = -flag;
		}
		int n = 0;
		while (min != max)
		{
			++min;
			++n;
		}
		return n * flag;
	}


	bool CheckInvalid() {
		if (_year <= 0 || _month < 1 || _month > 12 || _day < 1 || _day > GetMonthDay(_year, _month))
			return false;
		else
			return true;
	}

	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& out, Date& d);


private:
	int _year;
	int _month;
	int _day;
};


ostream& operator<<(ostream& out,const Date& d) {
	out << d._year << "/" << d._month << "/" << d._day << endl;
	return out;
}

istream& operator>>(istream& in, Date& d) {
	in >> d._year >> d._month >> d._day;
	return in;
}