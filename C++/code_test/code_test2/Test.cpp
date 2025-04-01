#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;



//class A
//{
//public:
//	// ���캯��explicit�Ͳ���֧����ʽ����ת��
//	// explicit A(int a1)
//	A(int a1)
//		:_a1(a1)
//	{}
//
//	A(const A& aa)
//		:_a1(aa._a1)
//		,_a2(aa._a2)
//	{}
//
//	// explicit A(int a1, int a2)
//	A(int a1, int a2)
//		:_a1(a1)
//		, _a2(a2)
//	{}
//
//	void Print()
//	{
//		cout << _a1 << " " << _a2 << endl;
//	}
//
//	int Get() const
//	{
//		return _a1 + _a2;
//	}
//
//private:
//	int _a1 = 1;
//	int _a2 = 2;
//};
//
//class B
//{
//public:
//	B(const A& a)
//		:_b(a.Get())
//	{}
//private:
//	int _b = 0;
//};
//
//class Stack
//{
//public:
//	void Push(const A& aa)
//	{}
//};
//
//int main()
//{
//	// ���������������Ĺ���+��������->�Ż�Ϊֱ�ӹ���
//	A aa1(1);
//	A aa2(1, 1);
//
//	// ��ʱ������г��ԣ������const
//	A aa3 = 1;
//	const A& aa4 = 1; 
//
//	// C++11֮���֧�ֶ����ת��
//	A aa5 = { 2, 2 };
//	const A& aa6 = { 2, 2 };
//
//	// 7����ʽ����ת����A��������A�������й��캯�������ó�ʼ����7��Ȼ�󷵻�A����Push
//	Stack st;
//	st.Push(7);
//	st.Push({8, 8});
//
//	return 0;
//}

#include<iostream>
using namespace std;
class A
{
public:
	A(int a = 0)
		:_a1(a)
	{
		cout << "A(int a)" << endl;
	}
	A(const A& aa)
		:_a1(aa._a1)
	{
		cout << "A(const A& aa)" << endl;
	}
	A& operator=(const A& aa)
	{
		cout << "A& operator=(const A& aa)" << endl;
		if (this != &aa)
		{
			_a1 = aa._a1;
		}
		return *this;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a1 = 1;
};
void f1(A aa)
{
}
A f2()
{
	A aa;
	return aa;
}
int main()
{
	// ��ֵ����
	// ����+��������
	A aa1;
	f1(aa1);
	cout << endl;
	// ��ʽ���ͣ���������+��������->�Ż�Ϊֱ�ӹ���
	f1(1);
	// һ�����ʽ�У���������+��������->�Ż�Ϊһ������
	f1(A(2));
	cout << endl;
	cout << "***********************************************" << endl;
	// ��ֵ����
	// ���Ż�������´�ֵ���أ�������������һ���������ض������ʱ������Ϊ�������ñ��ʽ�ķ���ֵ
	// ���Ż� ��vs2019 debug��
	// һЩ���������Ż��ø�������������ľֲ�����Ϳ����������ʱ�����Ż�Ϊֱ�ӹ��죨vs2022 debug��
	f2();
	cout << endl;
	// ����ʱһ�����ʽ�У�������������+��������->�Ż�һ���������� ��vs2019 debug��
	// һЩ���������Ż��ø����������п��кϲ��Ż���������ľֲ�����aa�Ϳ�������ʱ����ͽ��շ���ֵ����aa2�Ż�Ϊһ��ֱ�ӹ��졣��vs2022 debug��
	A aa2 = f2();
	cout << endl;
	// һ�����ʽ�У���ʼ���죬�м俽������+��ֵ����->�޷��Ż���vs2019 debug��
	// һЩ���������Ż��ø����������п��кϲ��Ż���������ľֲ�����aa�Ϳ�����ʱ����ϲ�Ϊһ��ֱ�ӹ��죨vs2022 debug��
	aa1 = f2();
	cout << endl;
	return 0;
}


