#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string.h>
using namespace std;

//int main()
//{
//	for (int i = 0; i < 50; i++)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	int* const p1 = &i;		// ����const
//	
//	const int ci = 111;		// ����const
//	const int* p2 = &ci;	// �ײ�const
//	const int& r = ci;		// �ײ�const
//	return 0;
//}


//int size()
//{
//	int n = 10;
//	return n;
//}
//
//int main()
//{
//	const int a = 1;		// a�ǳ������ʽ
//	const int b = a + 1;	// b�ǳ������ʽ
//	int c = 1;				// c���ǳ������ʽ
//	const int d = c;		// d���ǳ������ʽ
//	const int e = size();	// e���ǳ������ʽ
//	
//	// �������ʽ�����������С��vs��֧�ֱ䳤���飬�������������С�����Ǳ���ʱȷ�ϵ�
//	int arr[a];
//	constexpr int aa = 1;
//	constexpr int bb = aa + 1;
//
//	//constexpr int cc = c;				// ����
//	//constexpr int cc = size();		// ����
//	//constexpr int* p1 = &d;			// ����Ȩ�޷Ŵ��ˣ�constexpr���ε���p1����
//
//	const int* p2 = &d;
//	constexpr const int* p3 = &d;		// constexpr���ε���p1����const����*p3
//	return 0;
//}

//constexpr int size()
//{
//	return 10;
//}
//constexpr int func(int x)
//{
//	return 10 + x;
//}
//constexpr int factorial(int n)
//{
//	return n <= 1 ? 1 : n * factorial(n - 1);
//}
//constexpr int fxx(int x)
//{
//	int i = x;
//	i++;
//	cout << i << endl;
//	return 10 + x;
//}
//
//int main()
//{
//	// ����ʱ��N�ᱻֱ���滻Ϊ10��constexpr����Ĭ�Ͼ���inline
//	constexpr int N1 = size();
//	int arr1[N1];
//	// func��10ʱ��func��������ֵ�ǳ������ʽ������N2�ǳ������ʽ
//	constexpr int N2 = func(10);
//	int arr2[N2];
//	
//	int i = 10;
//	constexpr int N3 = func(i); // ����func���صĲ��ǳ������ʽ
//	int N4 = func(i); // ������constexpr�������صĲ�һ�ǳ������ʽ
//
//	constexpr int fact5 = factorial(5); // ����ʱ����
//	
//	// constexpr���εĺ���������һЩ������䣬������Щ�������ʱ���Բ�ִ���κβ����Ϳ���
//	// �����ͱ���������䡢using������
//	constexpr int N5 = fxx(10); // ����
//
//	return 0;
//}

//class Date
//{
//public:
//	constexpr Date(int year, int month, int day)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{
//		//cout << "constexpr Date(int year, int month, int day)" << endl;
//	}
//	constexpr int GetYear() const
//	{
//		return _year;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//template<typename T>
//constexpr T Func(T t)
//{
//	return t;
//}
//
//int main()
//{
//	int x = 2025;
//	// constexpr Date d0(x, 9, 8); // ���� ����ʹ�ó������г�ʼ��
//	constexpr Date d1(2000, 1, 1);
//	constexpr int y = d1.GetYear();
//
//	Date d2(2000, 1, 1);
//	int z = d2.GetYear();
//	string ret1 = Func("111111"); // ��ͨ����
//	constexpr int ret2 = Func(10);
//	return 0;
//}

