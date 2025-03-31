#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;



class A
{
public:
	// ���캯��explicit�Ͳ���֧����ʽ����ת��
	// explicit A(int a1)
	A(int a1)
		:_a1(a1)
	{}

	A(const A& aa)
		:_a1(aa._a1)
		,_a2(aa._a2)
	{}

	// explicit A(int a1, int a2)
	A(int a1, int a2)
		:_a1(a1)
		, _a2(a2)
	{}

	void Print()
	{
		cout << _a1 << " " << _a2 << endl;
	}

	int Get() const
	{
		return _a1 + _a2;
	}

private:
	int _a1 = 1;
	int _a2 = 2;
};

class B
{
public:
	B(const A& a)
		:_b(a.Get())
	{}
private:
	int _b = 0;
};

class Stack
{
public:
	void Push(const A& aa)
	{}
};

int main()
{
	// ���������������Ĺ���+��������->�Ż�Ϊֱ�ӹ���
	A aa1(1);
	A aa2(1, 1);

	// ��ʱ������г��ԣ������const
	A aa3 = 1;
	const A& aa4 = 1; 

	// C++11֮���֧�ֶ����ת��
	A aa5 = { 2, 2 };
	const A& aa6 = { 2, 2 };

	// 7����ʽ����ת����A��������A�������й��캯�������ó�ʼ����7��Ȼ�󷵻�A����Push
	Stack st;
	st.Push(7);
	st.Push({8, 8});

	return 0;
}
