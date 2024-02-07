#include <iostream>
#include <assert.h>
using namespace std;

class Date
{
public:
	// ���캯��
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;

		if (!CheckInvalid())
		{
			cout << "�������ڷǷ�" << endl;
		}
	}
	// �жϵ���
	bool operator==(const Date& d)
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}
	// �ж�С��
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
	// �ж�С�ڵ���
	bool operator<=(const Date& d)
	{
		return *this <= d || *this == d;
	}
	// �жϴ���
	bool operator>(const Date& d)
	{
		return !(*this <= d);
	}
	// �жϴ��ڵ���
	bool operator>=(const Date& d)
	{
		return !(*this < d);
	}
	// �жϲ�����
	bool operator!=(const Date& d)
	{
		return !(*this == d);
	}
	// ���ڼӵ�����

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


	// ���ڼ�����
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
	//// ����+=����
	//Date& operator+=(int day)
	//{
	//	*this = *this + day;
	//	return *this;
	//}

	// ����-=����
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

	// ���ڼ�����
	Date operator-(int day)
	{
		Date tmp = *this;
		tmp -= day;

		return tmp;
	}

	// ǰ��++
	Date& operator++()
	{
		*this += 1;
		return *this;
	}

	// ����++
	Date operator++(int)
	{
		Date tmp = *this;
		*this += 1;

		return tmp;
	}

	// ����-����
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


	// ��ȡ�·�����[���Բ�дinline������Ĭ�Ͼ���]
	inline int GetMonthDay(int year, int month)
	{
		assert(month < 13 && month > 0);
		// �ŵ���̬��
		static int MonthDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		// ���ж��·�
		if (month == 2 && (((year % 100 == 0) && (year % 4 == 0)) || (year % 400 != 0)))
			return 29;
		return MonthDays[month];
	}

	// ��������
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
	out << d._year << "��" << d._month << "��" << d._day << "��" << endl;
	return out;
}

istream& operator>>(istream& in, Date& d)
{
	while (1)
	{
		cout << "����������������:>";
		in >> d._year >> d._month >> d._day;

		if (!d.CheckInvalid())
		{
			cout << "����Ƿ����ڣ�����������" << endl;
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
	
	//��Ϊ��Ա�������أ�thisָ��ռ�ݵ�һ��������Date�������ڲ�����
	//d1.operator<<(cout);
	//d1 << cout;

	//cout << d1 << d2;
	cin >> d2 >> d1;

	cout << d2 << d1;
	return 0;
}




