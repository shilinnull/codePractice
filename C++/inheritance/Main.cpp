#include<iostream>
#include<string>

using namespace std;

//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
//	string _name = "peter"; // 姓名
//	int _age = 18; // 年龄
//};
//
//class Student : public Person
//{
//protected:
//	int _stuid; // 学号
//	int _major; // 专业
//};
//
//
//class Teacher : public Person
//{
//protected:
//	int _jobid; // 工号
//};

// 基类A的定义
//class A 
//{
//public:
//	int a_public_Num;
//protected:
//	int a_protect_Num;
//private:
//	int a_private_Num;
//};
//
//// 类pubB 使用public的方式继承A
//class pubB : public A
//{
//public:
//	pubB()
//	{
//		a_public_Num = 1;
//		a_protect_Num = 2; // 类内可以访问
//		// a_private_Num = 3 // 不能访问
//	}
//}; 
//
//// 类proB 使用protect的方式继承A
//class proB : protected A
//{
//public:
//	proB()
//	{
//		a_public_Num = 4;
//		a_protect_Num = 5; // 类内可以访问
//		// a_private_Num = 6 // 不能访问
//	}
//}; 
//
//// 类proB 使用private的方式继承A
//class prvB : private A
//{
//public:
//	prvB()
//	{
//		a_public_Num = 7;
//		a_protect_Num = 8; // 类内可以访问
//		// a_private_Num = 9 // 不能访问
//	}
//};
//
//int main()
//{
//	pubB b1;
//	cout << b1.a_public_Num << endl; // 可以访问
//
//	proB b2;
//	// cout << b2.a_public_Num << endl;  // 不可访问
//	
//	prvB b3;
//	// cout << b3.a_public_Num << endl; // 不可访问
//	
//	
//	return 0;
//}

//
//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
//	string _name = "peter"; // 姓名
//	int _age = 18; // 年龄
//};
//
//class Student : public Person
//{
//protected:
//	int _stuid; // 学号
//	int _major; // 专业
//};
//
//class Teacher : public Person
//{
//protected:
//	int _jobid; // 工号
//};
//
//int main()
//{
//	Student s;
//	Person p = s; // 只有公有继承才可以
//
//	return 0;
//}


//class Person
//{
//protected:
//	string _name; // 姓名
//	string _sex; // 性别
//	int _age; // 年龄
//};
//
//class Student : public Person
//{
//public:
//	int _No; // 学号
//};
//
//void main()
//{
//	Student sobj;
//	// 1.子类对象可以赋值给父类对象/指针/引用
//	Person pobj = sobj;
//	Person* pp = &sobj;
//	Person& rp = sobj;
//	
//	//2.基类对象不能赋值给派生类对象
//	//sobj = pobj;
//
//	// 3.基类的指针可以通过强制类型转换赋值给派生类的指针
//	pp = &sobj;
//	Student* ps1 = (Student*)pp; // 这种情况转换时可以的。
//	ps1->_No = 10;
//	pp = &pobj;
//
//	Student* ps2 = (Student*)pp; // 这种情况转换时虽然可以，但是会存在越界访问的问题
//	ps2->_No = 10;
//}


// Student的_num和Person的_num构成隐藏关系，可以看出这样代码虽然能跑，但是非常容易混淆
//class Person
//{
//protected:
//	string _name = "小李子"; // 姓名
//	int _num = 111; // 身份证号
//};
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << "姓名:" << _name << endl;
//		cout << "身份证号:" << Person::_num << endl;
//		cout << "学号:" << _num << endl;
//	}
//protected:
//	int _num = 999; // 学号
//};
//
//class A
//{
//public:
//	void fun()
//	{
//		cout << "func()" << endl;
//	}
//};
//class B : public A
//{
//public:
//	void fun(int i)
//	{
//		A::fun();
//		cout << "func(int i)->" << i << endl;
//	}
//};
//
//int main()
//{
//	B b;
//	// b.fun(10);
//
//	b.A::fun();
//
//	//Student s1;
//	//s1.Print();
//
//	return 0;
//};

class Person
{
public:
	Person(const char* name = "peter")
		: _name(name)
	{
		cout << "Person()" << endl;
	}

	Person(const Person& p)
		: _name(p._name)
	{
		cout << "Person(const Person& p)" << endl;
	}

	Person& operator=(const Person& p)
	{
		cout << "Person operator=(const Person& p)" << endl;
		if (this != &p)
			_name = p._name;
		return *this;
	}

	~Person()
	{
		cout << "~Person()" << endl;
	}
protected:
	string _name; 
};

class Student : public Person
{
public:
	Student(const char* name, int num)
		: Person(name)
		, _num(num)
	{
		cout << "Student()" << endl;
	}

	Student(const Student& s)
		: Person(s)
		, _num(s._num)
	{
		cout << "Student(const Student& s)" << endl;
	}

	Student& operator=(const Student& s)
	{
		cout << "Student& operator= (const Student& s)" << endl;
		if (this != &s)
		{
			// 指定作用域显示调用
			Person::operator=(s);
			_num = s._num;
		}
		return *this;
	}

	~Student()
	{
		cout << "~Student()" << endl;
	}
protected:
	int _num;
	string _str;
};

int main()
{
	Student s1("jack", 18);
	Student s2(s1);
	Student s3("rose", 17);
	s1 = s3;

	return 0;
}

