#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <list>
using namespace std;

//
//void Print(const vector<int>& v)
//{
//	// 1. ��һ�����ֿ���ֱ��ʹ��
//	vector<int>::const_iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//}
//
//template<class T>
//void Print(const vector<T>& v)
//{
//	// 2. ���ֱ��ʹ�õĻ���û��ʵ����ʱ��֪�����const_iterator��ʲô����
//	//vector<T>::const_iterator it = v.begin();
//	
//	// ������ǰ����Ҫ����typename�����߱�����
//	typename vector<T>::const_iterator it = v.begin();
//	//auto it = v.begin(); // ���򵥵ķ�ʽ
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//}
//
//template<class Container>
//void Print(const Container& con)
//{
//	//typename Container::const_iterator it = con.begin();
//	auto it = con.begin();
//	while (it != con.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//}
//
//int main()
//{
//	vector<int> v1 = { 1,2,3,4,5 };
//	Print(v1);
//
//	vector<double> v2 = { 11.1,2.2,33.3 };
//	Print(v2);
//
//	list<double> lt1 = { 11.1,2.2,33.3 };
//	Print(lt1);
//
//	return 0;
//}
//

//class Person
//{
//public:
//    void Print()
//    {
//        cout << "name:" << _name << endl;
//        cout << "age:" << _age << endl;
//    }
//protected:
//    string _name = "peter"; // ����
//    int _age = 18; // ����
//};
//
//class Student : public Person
//{
//protected:
//    int _stuid; // ѧ��
//};
//
//
//class Teacher : public Person
//{
//protected:
//    int _jobid; // ����
//};
//
//int main()
//{
//    Student s;
//    Teacher t;
//    s.Print();
//    t.Print();
//    return 0;
//}

//class Person
//{
//public:
//	void Print()
//	{
//		cout << _name << endl;
//	}
//protected:
//	string _name; // ����
//private:
//	int _age; // ����
//};
////class Student : protected Person
////class Student : private Person
//class Student : public Person
//{
//protected:
//	int _stunum; // ѧ��
//};
//
//int main() 
//{
//	Student s;
//	s.Print();
//	return 0;
//}

//namespace lsl
//{
//	//template<class T>
//	//class vector
//	//{};
//	// stack��vector�Ĺ�ϵ���ȷ���is-a��Ҳ����has-a
//	template<class T>
//	class stack : public std::vector<T>
//	{
//	public:
//		void push(const T& x)
//		{
//			// ��������ģ��ʱ����Ҫָ��һ������
//			// ������뱨��:error C3861: ��push_back��: �Ҳ�����ʶ��
//			// ��Ϊstack<int>ʵ����ʱ��Ҳʵ����vector<int>��
//			// ����ģ���ǰ���ʵ������push_back�ȳ�Ա����δʵ�����������Ҳ���
//			//push_back(x);
//			vector<T>::push_back(x);
//		}
//		void pop()
//		{
//			vector<T>::pop_back();
//		}
//		const T& top()
//		{
//			return vector<T>::back();
//		}
//		bool empty()
//		{
//			return vector<T>::empty();
//		}
//	};
//}
//
//int main()
//{
//	lsl::stack<int> st;
//	st.push(1);
//	st.push(2);
//	st.push(3);
//	while (!st.empty())
//	{
//		cout << st.top() << " ";
//		st.pop();
//	}
//	return 0;
//}

//class Person
//{
//public:
//    void Print()
//    {
//        cout << "name:" << _name << endl;
//        cout << "age:" << _age << endl;
//    }
//protected:
//    string _name = "peter"; // ����
//    int _age = 18; // ����
//};
//
//class Student : public Person
//{
//protected:
//    int _stuid; // ѧ��
//    int _major; // רҵ
//};
//
//int main()
//{
//    Student s;
//    Person p = s; // ֻ�й��м̳вſ���
//
//    return 0;
//}

//class A
//{
//public:
//	void fun()
//	{
//		cout << "func()" << endl;
//	}
//};
//
//class B : public A
//{
//public:
//	void fun(int i)
//	{
//		cout << "func(int i)" << i << endl;
//	}
//};
//
//int main()
//{
//	B b;
//	b.fun(10);
//	b.A::fun();
//	return 0;
//}

//// C++11�ķ���
//class Base final
//{
//public:
//	void func5() { cout << "Base::func5" << endl; }
//protected:
//	int a = 1;
//private:
//	// C++98�ķ���
//	Base()
//	{}
//};
//
//class Derive :public Base
//{
//	void func4() { cout << "Derive::func4" << endl; }
//protected:
//	int b = 2;
//};
//int main()
//{
//	Base b;
//	Derive d;
//	return 0;
//}

//class Person
//{
//public:
//    string _name; // ����
//};
//
//class Student : virtual public Person
//{
//protected:
//    int _num; //ѧ��
//};
//
//class Teacher : virtual public Person
//{
//protected:
//    int _id; // ְ�����
//};
//
//class Assistant : public Student, public Teacher
//{
//protected:
//    string _majorCourse; // ���޿γ�
//};
//
//void main()
//{
//    Assistant a;
//    a._name = "peter";
//
//    a.Student::_name = "xxx";
//    a.Teacher::_name = "yyy";
//}




//class Base1
//{
//public:
//	int _b1;
//};
//
//class Base2 {
//public:
//	int _b2;
//};
//
//class Derive : public Base1, public Base2
//{
//public:
//	int _d;
//};
//
//int main()
//{
//	Derive d;
//	Base1* p1 = &d;
//	Base2* p2 = &d;
//	Derive* p3 = &d;
//	return 0;
//}

//class A
//{
//public:
//    int _a;
//};
//
//class B : public A
//{
//public:
//    int _b;
//    int _b1;
//    int _b2;
//};
//
//class C : public A
//{
//public:
//    int _c;
//};
//class D : public C, public B
//{
//public:
//    int _d;
//};
//
//
//int main() 
//{
//    D d;
//    d.B::_a = 1;
//    d.C::_a = 2;
//    return 0;
//}


class A
{
public:
    int _a;
};

class B : virtual public A
{
public:
    int _b;
    int _b1;
    int _b2;

};

class C : virtual public A
{
public:
    int _c;
};

class D : public C, public B
{
public:
    int _d;
};

int main()
{
    D d;
    d.B::_a = 1;
    d.C::_a = 2;
    d._a = 3;
    d._b = 4;
    d._c = 5;
    d._d = 6;
    return 0;
}
