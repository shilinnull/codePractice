#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


// �������ͺ��Զ�������֮��
// 1���Զ������� = �������� ->���캯��֧��
// 2���������� = �Զ������� ->operator �������� ֧��
//class A
//{
//public:
//	// ���캯������explicit�Ͳ�֧����ʽ����ת����
//	//explicit A(int a)
//	A(int a)
//		:_a1(a)
//		, _a2(a)
//	{}
//	A(int a1, int a2)
//		:_a1(a1)
//		, _a2(a2)
//	{}
//	// ����explicit�Ͳ�֧����ʽ����ת����
//	// explicit operator int()
//	operator int() const
//	{
//		return _a1 + _a2;
//	}
//private:
//	int _a1 = 1;
//	int _a2 = 1;
//};
//
//class B
//{
//public:
//	B(int b)
//		:_b1(b)
//	{}
//	// ֧��A���Ͷ���ת��ΪB���Ͷ���
//	B(const A& aa)
//		:_b1(aa)
//	{}
//private:
//	int _b1 = 1;
//};
//
//int main()
//{
//	// ��������ת��
//	string s1 = "1111111";
//	A aa1 = 1;
//	A aa2 = (A)1;
//	// �������ת��
//	A aa3 = { 2, 2 };
//	const A& aa4 = { 2,2 };
//	int z = aa1.operator int();
//	int x = aa1;
//	int y = (int)aa2;
//	cout << x << endl;
//	cout << y << endl;
//	cout << z << endl;
//	std::shared_ptr<int> foo;
//	std::shared_ptr<int> bar(new int(34));
//	//if (foo.operator bool())
//	if (foo)
//		std::cout << "foo points to " << *foo << '\n';
//	else
//		std::cout << "foo is null\n";
//
//	if (bar)
//		std::cout << "bar points to " << *bar << '\n';
//	else
//		std::cout << "bar is null\n";
//
//	// A���Ͷ�����ʽת��ΪB����
//	B bb1 = aa1;
//	B bb2(2);
//	bb2 = aa1;
//	const B& ref1 = aa1;
//	return 0;
//}


//int main()
//{
//	int x = 100;
//	double* p1 = (double*)&x;
//	// ����᱾���Ѿ�������Խ����ʣ�ֻ��Խ�粻һ���ܱ�������
//	cout << *p1 << endl;
//
//	return 0;
//}

//int main()
//{
//	volatile const int y = 0;
//	int* p2 = (int*)&y;
//	(*p2) = 1;
//	cout << *p2 << endl;
//	cout << y << endl;
//	return 0;
//}


//int main()
//{
//	// ��Ӧ��ʽ����ת�� -- ���ݵĽ�������û�иı�
//	double pi = 3.14;
//	int a = static_cast<int>(pi);
//	cout << a << endl;
//	int&& ref = static_cast<int&&>(a);
//
//	return 0;
//}

//int main()
//{
//	// ��Ӧ��ʽ����ת�� -- ���ݵĽ�������û�иı�
//	double pi = 3.14;
//	int a = static_cast<int>(pi);
//	cout << a << endl;
//
//	//int *p = static_cast<int*>(a);
//	int *p = reinterpret_cast<int*>(a);
//
//	return 0;
//}

//int main()
//{
//	// ��Ӧ��ʽ����ת�� -- ���ݵĽ�������û�иı�
//	double pi = 3.14;
//	int a = static_cast<int>(pi);
//	cout << a << endl;
//
//	//int *p = static_cast<int*>(a);
//	int *p = reinterpret_cast<int*>(a);
//
//	return 0;
//}


//#include<iostream>
//#include<string>
//#include<vector>
//#include<list>
//#include<typeinfo>
//using namespace std;
//
//int main()
//{
//	int a[10];
//	int* ptr = nullptr;
//	cout << typeid(10).name() << endl;
//	cout << typeid(a).name() << endl;
//	cout << typeid(ptr).name() << endl;
//	cout << typeid(string).name() << endl;
//	cout << typeid(string::iterator).name() << endl;
//	cout << typeid(vector<int>).name() << endl;
//	cout << typeid(vector<int>::iterator).name() << endl;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	virtual void func()
//	{}
//protected:
//	int _a1 = 1;
//};
//
//class B : public A
//{
//protected:
//	int _b1 = 2;
//};
//
//int main()
//{
//	try
//	{
//		B* pb = new B;
//		A* pa = (A*)pb;
//		if (typeid(*pb) == typeid(B))
//		{
//			cout << "typeid(*pb) == typeid(B)" << endl;
//		}
//		// ���A��B���Ǽ̳й�ϵ�������bad_typeid�쳣
//		if (typeid(*pa) == typeid(B))
//		{
//			cout << "typeid(*pa) == typeid(B)" << endl;
//		}
//		// ����pa��pb��A*��B*�����������Ͷ������ᱻ������������ֵ�ľ�̬��������
//		// ��������ʼ���ǲ���ȵ�
//		if (typeid(pa) == typeid(pb))
//		{
//			cout << "typeid(pa) == typeid(pb)" << endl;
//		}
//	}
//	catch (const std::exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	return 0;
//}
//

//#include<iostream>
//using namespace std;
//int main()
//{
//	cout << cin.good() << endl;
//	cout << cin.eof() << endl;
//	cout << cin.bad() << endl;
//	cout << cin.fail() << endl << endl;
//
//	int i = 0;
//	// ����һ���ַ������ַ���cin��ȡʧ�ܣ���״̬�����Ϊfailbit
//	cin >> i;
//	cout << i << endl;
//	cout << cin.good() << endl;
//	cout << cin.eof() << endl;
//	cout << cin.bad() << endl;
//	cout << cin.fail() << endl << endl;
//	if (cin.fail())
//	{
//		// clear���Իָ���״̬λgoodbit
//		cin.clear();
//		// ���ǻ�Ҫ�ѻ������еĶ���ַ�������������������ͣ������������ȥcin>>i���ǻ�ʧ��
//		char ch = cin.peek();
//		while (!(ch >= '0' && ch <= '9'))
//		{
//			ch = cin.get();
//			cout << ch;
//			ch = cin.peek();
//		}
//		cout << endl;
//	}
//	cout << cin.good() << endl;
//	cout << cin.eof() << endl;
//	cout << cin.bad() << endl;
//	cout << cin.fail() << endl << endl;
//	cin >> i;
//	cout << i << endl;
//	return 0;
//}


//#include<iostream>
//#include<fstream>
//using namespace std;
//void func(ostream& os)
//{
//	os << "hello world";
//	os << "hello bit";
//	// "hello world"��"hello bit"�Ƿ������ȷ��
//	system("pause");
//	// ����endl��"hello world"��"hello bit"һ��ˢ�»����������
//	// os << endl;
//	// os << flush;
//	int i;
//	//cin >> i;
//	os << "hello cat";
//	// "hello cat"�Ƿ������ȷ��
//	system("pause");
//}
//
//
//int main()
//{
//	ofstream ofs("test.txt");
//	// func(cout);
//	// unitbuf���ú�ofsÿ��д��ֱ��ˢ��
//	ofs << unitbuf;
//	// cin�󶨵�ofs��cin���ж�ʱ����ˢ��ofs�Ļ�����
//	cin.tie(&ofs);
//	func(ofs);
//	return 0;
//}


//int main()
//{
//	// ��io����Ƚϸߵĵط����粿�ִ�������ľ������У��������¼��д���������C++IOЧ��
//	// ���ҽ�����'\n'���endl����Ϊendl��ˢ�»�����
//	// �رձ�׼ C++ ���Ƿ����׼ C ����ÿ������/���������ͬ����
//	ios_base::sync_with_stdio(false);
//	// �ر�ͬ�������³������˳��Ϊb a c
//	// std::cout << "a\n";
//	// std::printf("b\n");
//	// std::cout << "c\n";
//	// ���cin��cout�����󶨵�������
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	return 0;
//}


//class Date
//{
//	friend ostream& operator << (ostream& out, const Date& d);
//	friend istream& operator >> (istream& in, Date& d);
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{}
//
//	operator bool() const
//	{
//		// ����������д�ģ���������_yearΪ0�������
//		if (_year == 0)
//			return false;
//		else
//			return true;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//istream& operator >> (istream& in, Date& d)
//{
//	in >> d._year >> d._month >> d._day;
//	return in;
//}
//
//ostream& operator << (ostream& out, const Date& d)
//{
//	out << d._year << " " << d._month << " " << d._day;
//	return out;
//}

// C++ IO����ʹ���������+��������صķ�ʽ
// �ܸ��õļ����Զ������ͣ������������ȡ
//int main()
//{
//	// �Զ�ʶ�����͵ı���--��������
//	// �������Ϳ���ֱ��ʹ��--��Ϊ������ostream�����Ѿ�ʵ����
//	int i = 1;
//	double j = 2.2;
//	cout << i << endl;
//	cout << j << endl;
//
//	// �Զ�����������Ҫ�����Լ�����<< �� >>
//	Date d(2022, 4, 10);
//	cout << d;
//	while (d)
//	{
//		cin >> d;
//		cout << d;
//	}
//	return 0;
//}


//#include<iostream>
//#include<fstream>
//#include<string>
//using namespace std;
//
//int main()
//{
//	int i = 0, j = 1;
//	
//
//	while (cin >> i >> j)
//	{
//		cout << i << ":" << j << endl;
//	}
//
//	cout << cin.good() << endl;
//	cout << cin.eof() << endl;
//	cout << cin.bad() << endl;
//	cout << cin.fail() << endl << endl;
//	// ��һ����������Ͳ��������ˣ���������һ������ʹ��
//	cin.clear();
//
//	string s;
//	while (cin >> s)
//	{
//		cout << s << endl;
//	}
//}



































































































































































