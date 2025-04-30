#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


// �������ͺ��Զ�������֮��
// 1���Զ������� = �������� ->���캯��֧��
// 2���������� = �Զ������� ->operator �������� ֧��
class A
{
public:
	// ���캯������explicit�Ͳ�֧����ʽ����ת����
	//explicit A(int a)
	A(int a)
		:_a1(a)
		, _a2(a)
	{}
	A(int a1, int a2)
		:_a1(a1)
		, _a2(a2)
	{}
	// ����explicit�Ͳ�֧����ʽ����ת����
	// explicit operator int()
	operator int() const
	{
		return _a1 + _a2;
	}
private:
	int _a1 = 1;
	int _a2 = 1;
};

class B
{
public:
	B(int b)
		:_b1(b)
	{}
	// ֧��A���Ͷ���ת��ΪB���Ͷ���
	B(const A& aa)
		:_b1(aa)
	{}
private:
	int _b1 = 1;
};
int main()
{
	// ��������ת��
	string s1 = "1111111";
	A aa1 = 1;
	A aa2 = (A)1;
	// �������ת��
	A aa3 = { 2,2 };
	const A& aa4 = { 2,2 };
	int z = aa1.operator int();
	int x = aa1;
	int y = (int)aa2;
	cout << x << endl;
	cout << y << endl;
	cout << z << endl;
	std::shared_ptr<int> foo;
	std::shared_ptr<int> bar(new int(34));
	//if (foo.operator bool())
	if (foo)
		std::cout << "foo points to " << *foo << '\n';
	else
		std::cout << "foo is null\n";
	if (bar)
		std::cout << "bar points to " << *bar << '\n';
	else
		std::cout << "bar is null\n";
	// A���Ͷ�����ʽת��ΪB����
	B bb1 = aa1;
	B bb2(2);
	bb2 = aa1;
	const B& ref1 = aa1; 
	return 0;
}