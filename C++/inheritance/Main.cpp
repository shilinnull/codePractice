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
//	string _name = "peter"; // ����
//	int _age = 18; // ����
//};
//
//class Student : public Person
//{
//protected:
//	int _stuid; // ѧ��
//	int _major; // רҵ
//};
//
//
//class Teacher : public Person
//{
//protected:
//	int _jobid; // ����
//};

// ����A�Ķ���
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
//// ��pubB ʹ��public�ķ�ʽ�̳�A
//class pubB : public A
//{
//public:
//	pubB()
//	{
//		a_public_Num = 1;
//		a_protect_Num = 2; // ���ڿ��Է���
//		// a_private_Num = 3 // ���ܷ���
//	}
//}; 
//
//// ��proB ʹ��protect�ķ�ʽ�̳�A
//class proB : protected A
//{
//public:
//	proB()
//	{
//		a_public_Num = 4;
//		a_protect_Num = 5; // ���ڿ��Է���
//		// a_private_Num = 6 // ���ܷ���
//	}
//}; 
//
//// ��proB ʹ��private�ķ�ʽ�̳�A
//class prvB : private A
//{
//public:
//	prvB()
//	{
//		a_public_Num = 7;
//		a_protect_Num = 8; // ���ڿ��Է���
//		// a_private_Num = 9 // ���ܷ���
//	}
//};
//
//int main()
//{
//	pubB b1;
//	cout << b1.a_public_Num << endl; // ���Է���
//
//	proB b2;
//	// cout << b2.a_public_Num << endl;  // ���ɷ���
//	
//	prvB b3;
//	// cout << b3.a_public_Num << endl; // ���ɷ���
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
//	string _name = "peter"; // ����
//	int _age = 18; // ����
//};
//
//class Student : public Person
//{
//protected:
//	int _stuid; // ѧ��
//	int _major; // רҵ
//};
//
//class Teacher : public Person
//{
//protected:
//	int _jobid; // ����
//};
//
//int main()
//{
//	Student s;
//	Person p = s; // ֻ�й��м̳вſ���
//
//	return 0;
//}


//class Person
//{
//protected:
//	string _name; // ����
//	string _sex; // �Ա�
//	int _age; // ����
//};
//
//class Student : public Person
//{
//public:
//	int _No; // ѧ��
//};
//
//void main()
//{
//	Student sobj;
//	// 1.���������Ը�ֵ���������/ָ��/����
//	Person pobj = sobj;
//	Person* pp = &sobj;
//	Person& rp = sobj;
//	
//	//2.��������ܸ�ֵ�����������
//	//sobj = pobj;
//
//	// 3.�����ָ�����ͨ��ǿ������ת����ֵ���������ָ��
//	pp = &sobj;
//	Student* ps1 = (Student*)pp; // �������ת��ʱ���Եġ�
//	ps1->_No = 10;
//	pp = &pobj;
//
//	Student* ps2 = (Student*)pp; // �������ת��ʱ��Ȼ���ԣ����ǻ����Խ����ʵ�����
//	ps2->_No = 10;
//}


// Student��_num��Person��_num�������ع�ϵ�����Կ�������������Ȼ���ܣ����Ƿǳ����׻���
//class Person
//{
//protected:
//	string _name = "С����"; // ����
//	int _num = 111; // ���֤��
//};
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << "����:" << _name << endl;
//		cout << "���֤��:" << Person::_num << endl;
//		cout << "ѧ��:" << _num << endl;
//	}
//protected:
//	int _num = 999; // ѧ��
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
			// ָ����������ʾ����
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

