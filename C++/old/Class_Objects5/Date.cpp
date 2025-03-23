#include <iostream>
#include <assert.h>
using namespace std;

class Date
{
public:
	// 构造函数
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;

		if (!CheckInvalid())
		{
			cout << "构造日期非法" << endl;
		}
	}
	// 判断等于
	bool operator==(const Date& d)
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}
	// 判断小于
	bool operator<(const Date& d)
	{
		if (_year < d._year)
		{
			return true;
		}
		else if (_year == d._year)
		{
			if (_month < d._month)
			{
				return true;
			}
			else if (_month == d._month)
			{
				if (_day < d._day)
				{
					return true;
				}
			}
		}
		return false;
	}
	// 判断小于等于
	bool operator<=(const Date& d)
	{
		return *this <= d || *this == d;
	}
	// 判断大于
	bool operator>(const Date& d)
	{
		return !(*this <= d);
	}
	// 判断大于等于
	bool operator>=(const Date& d)
	{
		return !(*this < d);
	}
	// 判断不等于
	bool operator!=(const Date& d)
	{
		return !(*this == d);
	}
	// 日期加等天数

	Date& operator+=(int day)
	{
		_day += day;
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			++_month;
			if (_month == 13)
			{
				++_year;
				_month = 1;
			}
		}
		return *this;
	}

	Date operator+(int day)
	{
		Date tmp(*this);
		//Date tmp = *this;
		tmp += day;
		return tmp;
	}


	// 日期加天数
	Date operator+(const Date& d)
	{
		Date tmp(*this);
		tmp._day += d._day;
		while (d._day > GetMonthDay(tmp._year, tmp._month))
		{
			tmp._day -= GetMonthDay(tmp._year, tmp._month);
			++tmp._month;
			if (tmp._month == 13)
			{
				++tmp._year;
				tmp._month = 1;
			}
		}
		return tmp;
	}
	//Date operator+(int day)
	//{
	//	Date tmp(*this);
	//	tmp._day += day;
	//	while (tmp._day > GetMonthDay(tmp._year, tmp._month))
	//	{
	//		tmp._day -= GetMonthDay(tmp._year, tmp._month);
	//		++tmp._month;
	//		if (tmp._month == 13)
	//		{
	//			++tmp._year;
	//			tmp._month = 1;
	//		}
	//	}
	//	return tmp;
	//}
	//// 日期+=天数
	//Date& operator+=(int day)
	//{
	//	*this = *this + day;
	//	return *this;
	//}

	// 日期-=天数
	Date& operator-=(int day)
	{
		_day -= day;
		while (_day <= 0)
		{
			--_month;
			if (_month == 0)
			{
				--_year;
				_month = 12;
			}
			_day += GetMonthDay(_year, _month);
		}
		return *this;
	}

	// 日期减天数
	Date operator-(int day)
	{
		Date tmp = *this;
		tmp -= day;

		return tmp;
	}

	// 前置++
	Date& operator++()
	{
		*this += 1;
		return *this;
	}

	// 后置++
	Date operator++(int)
	{
		Date tmp = *this;
		*this += 1;

		return tmp;
	}

	// 日期-日期
	int operator-(const Date& d)
	{
		int flag = 1;
		Date max = *this;
		Date min = d;

		if (*this < d)
		{
			int flag = -1;
			max = d;
			min = *this;
		}

		int n = 0;
		while (min != max)
		{
			++min;
			++n;
		}
		return n * flag;
	}


	// 获取月份天数[可以不写inline，类里默认就是]
	inline int GetMonthDay(int year, int month)
	{
		assert(month < 13 && month > 0);
		// 放到静态区
		static int MonthDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		// 先判断月份
		if (month == 2 && (((year % 100 == 0) && (year % 4 == 0)) || (year % 400 != 0)))
			return 29;
		return MonthDays[month];
	}

	// 拷贝构造
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);

	bool CheckInvalid()
	{
		if (_year <= 0
			|| _month < 1
			|| _month > 12
			|| _day < 1
			|| _day > GetMonthDay(_year,_month))
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	void Print()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}
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

istream& operator>>(istream& in, Date& d)
{
	while (1)
	{
		cout << "请依次输入年月日:>";
		in >> d._year >> d._month >> d._day;

		if (!d.CheckInvalid())
		{
			cout << "输入非法日期，请重新输入" << endl;
		}
		else
		{
			break;
		}
	}
	return in;
}

int main()
{
	//Date d1(2024,2,3);

	//d1 -= 1;
	//d1.Print();

	//++d1;
	//d1.Print();
	//d1++;
	//d1.Print();
	
	
	Date d1(2024, 1, 29);
	Date d2(2024, 8, 1);

	//cout << (d2 - d1) << endl;
	
	//作为成员函数重载，this指针占据第一个参数，Date必须是在操作数
	//d1.operator<<(cout);
	//d1 << cout;

	//cout << d1 << d2;
	cin >> d2 >> d1;

	cout << d2 << d1;
	return 0;
}




