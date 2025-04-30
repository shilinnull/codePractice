#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


// 内置类型和自定义类型之间
// 1、自定义类型 = 内置类型 ->构造函数支持
// 2、内置类型 = 自定义类型 ->operator 内置类型 支持
class A
{
public:
	// 构造函数加上explicit就不支持隐式类型转换了
	//explicit A(int a)
	A(int a)
		:_a1(a)
		, _a2(a)
	{}
	A(int a1, int a2)
		:_a1(a1)
		, _a2(a2)
	{}
	// 加上explicit就不支持隐式类型转换了
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
	// 支持A类型对象转换为B类型对象
	B(const A& aa)
		:_b1(aa)
	{}
private:
	int _b1 = 1;
};
int main()
{
	// 单参数的转换
	string s1 = "1111111";
	A aa1 = 1;
	A aa2 = (A)1;
	// 多参数的转换
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
	// A类型对象隐式转换为B类型
	B bb1 = aa1;
	B bb2(2);
	bb2 = aa1;
	const B& ref1 = aa1; 
	return 0;
}