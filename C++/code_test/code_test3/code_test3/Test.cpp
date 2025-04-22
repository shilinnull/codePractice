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


//class A
//{
//public:
//    int _a;
//};
//
//class B : virtual public A
//{
//public:
//    int _b;
//    int _b1;
//    int _b2;
//
//};
//
//class C : virtual public A
//{
//public:
//    int _c;
//};
//
//class D : public C, public B
//{
//public:
//    int _d;
//};
//
//int main()
//{
//    D d;
//    d.B::_a = 1;
//    d.C::_a = 2;
//    d._a = 3;
//    d._b = 4;
//    d._c = 5;
//    d._d = 6;
//    return 0;
//}
//
//class Person {
//public:
//    virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
//};
//
//class Student : public Person {
//public:
//    void BuyTicket() { cout << "��Ʊ-���" << endl; }
//};
//
//void Func(Person& p)
//{
//    p.BuyTicket();
//}
//
//int main()
//{
//    Person ps;
//    Student st;
//    Func(ps);
//    Func(st);
//    return 0;
//}

//class A
//{
//public:
//	virtual void func(int val = 1) { std::cout << "A->" << val << std::endl; }
//	virtual void test() { func(); }
//};
//
//class B : public A
//{
//public:
//	void func(int val = 0) { std::cout << "B->" << val << std::endl; }
//};
//
//int main(int argc, char* argv[])
//{
//	B* p = new B;
//	p->test();
//	return 0;
//}
//


//class Person {
//public:
//	virtual Person* BuyTicket()
//	{
//		cout << "��Ʊ-ȫ��" << endl;
//		return nullptr;
//	}
//};
//
//class Student : public Person {
//public:
//	virtual Person* BuyTicket()
//	{
//		cout << "��Ʊ-����" << endl;
//		return nullptr;
//	}
//};
//
//void Func(Person* ptr)
//{
//	ptr->BuyTicket();
//}
//
//int main()
//{
//	Person ps;
//	Student st;
//	Func(&ps);
//	Func(&st);
//	return 0;
//}
//
//class A
//{
//public:
//    virtual ~A()
//    {
//        cout << "~A()" << endl;
//    }
//};
//class B : public A {
//public:
//    ~B()
//    {
//        cout << "~B()->delete:" << _p << endl;
//        delete _p;
//    }
//protected:
//    int* _p = new int[10];
//};
//
//int main()
//{
//    A* p1 = new A;
//    A* p2 = new B;
//    // ֻ��������B������������д��A�����������������delete�����������������
//    // ���ܹ��ɶ�̬�����ܱ�֤p1��p2ָ��Ķ�����ȷ�ĵ�������������
//    delete p1;
//    delete p2;
//    return 0;
//}

//class Car
//{
//public:
//    virtual void Drive() final {}
//};
//class Benz :public Car
//{
//public:
//    virtual void Drive() { cout << "Benz-����" << endl; }
//};

//class Car {
//public:
//    virtual void Drive() {}
//};
//class Benz :public Car {
//public:
//    virtual void Drive() override { cout << "Benz-����" << endl; }
//};


////�����ࣨ�ӿ��ࣩ
//class Car
//{
//public:
//    //���麯��
//    virtual void Drive() = 0;
//};
////������
//class Benz : public Car
//{
//public:
//    //��д���麯��
//    virtual void Drive()
//    {
//        cout << "Benz-����" << endl;
//    }
//};
////������
//class BMW : public Car
//{
//public:
//    //��д���麯��
//    virtual void Drive()
//    {
//        cout << "BMW-�ٿ�" << endl;
//    }
//};
//
//int main()
//{
//    // ���뱨��error C2259: ��Car��: �޷�ʵ����������
//    // Car car;
//
//    Car* pBenz = new Benz;
//    pBenz->Drive();
//
//    Car* pBMW = new BMW;
//    pBMW->Drive();
//
//    return 0;
//}

//class Base
//{
//public:
//    virtual void Func1()
//    {
//        cout << "Func1()" << endl;
//    }
//private:
//    int _b = 1;
//};
//
//int main()
//{
//    Base b;
//    cout << sizeof(b) << endl;
//
//    return 0;
//}


//class Base
//{
//public:
//    virtual void Func1()
//    {
//        cout << "Base::Func1()" << endl;
//    }
//    virtual void Func2()
//    {
//        cout << "Base::Func2()" << endl;
//    }
//    void Func3()
//    {
//        cout << "Base::Func3()" << endl;
//    }
//private:
//    int _b = 1;
//};
//
//class Derive : public Base
//{
//public:
//    virtual void Func1()
//    {
//        cout << "Derive::Func1()" << endl;
//    }
//private:
//    int _d = 2;
//};
//
//int main()
//{
//    Base b;
//    Derive d;
//
//    return 0;
//}


//
//class Base {
//public:
//    virtual void func1() { cout << "Base::func1" << endl; }
//    virtual void func2() { cout << "Base::func2" << endl; }
//private:
//    int a;
//};
//
//void func()
//{
//    cout << "void func()" << endl;
//}
//
//int main()
//{
//    Base b1;
//    Base b2;
//
//    static int a = 0;
//    int b = 0;
//    int* p1 = new int;
//    const char* p2 = "hello world";
//
//    printf("��̬��:%p\n", &a);
//    printf("ջ:%p\n", &b);
//    printf("��:%p\n", p1);
//    printf("�����:%p\n", p2);
//    printf("���:%p\n", *((int*)&b1));
//    printf("�麯����ַ:%p\n", &Base::func1);
//    printf("��ͨ������ַ:%p\n", func);
//
//    return 0;
//}
//
// 

//
//class Person {
//public:
//    virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
//};
//
//class Student : public Person {
//public:
//    virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }
//};
//
//void Func(Person* p)
//{
//    p->BuyTicket();
//}
//
//int main()
//{
//    Person Mike;
//    Func(&Mike);
//
//    Mike.BuyTicket();
//    return 0;
//}

//
//class Base {
//public:
//    virtual void func1() { cout << "Base::func1" << endl; }
//private:
//    int a;
//};
//
//int main()
//{
//    Base a;
//    Base b;
//
//    return 0;
//}


//class Base {
//public:
//    virtual void func1() { cout << "Base::func1" << endl; }
//    virtual void func2() { cout << "Base::func2" << endl; }
//private:
//    int a;
//};
//class Derive :public Base {
//public:
//    virtual void func1() { cout << "Derive::func1" << endl; }
//    virtual void func3() { cout << "Derive::func3" << endl; }
//    virtual void func4() { cout << "Derive::func4" << endl; }
//private:
//    int b;
//};
//
//// ��ӡ���
//typedef void(*VFPTR) ();
//void PrintVTable(VFPTR vTable[])
//{
//    // ����ȡ����е��麯��ָ���ӡ�����á����þͿ��Կ���������ĸ�����
//    cout << " ����ַ>" << vTable << endl;
//    for (int i = 0; vTable[i] != nullptr; ++i)
//    {
//        printf(" ��%d���麯����ַ :0X%x,->", i, vTable[i]);
//        VFPTR f = vTable[i];
//        f();
//    }
//    cout << endl;
//}
//
//int main()
//{
//    Base b;
//    Derive d;
//
//    VFPTR* vTableb = (VFPTR*)(*(int*)&b);
//    PrintVTable(vTableb);
//    VFPTR* vTabled = (VFPTR*)(*(int*)&d);
//    PrintVTable(vTabled);
//
//    return 0;
//}


//class Base1 {
//public:
//    virtual void func1() { cout << "Base1::func1" << endl; }
//    virtual void func2() { cout << "Base1::func2" << endl; }
//private:
//    int b1;
//};
//class Base2 {
//public:
//    virtual void func1() { cout << "Base2::func1" << endl; }
//    virtual void func2() { cout << "Base2::func2" << endl; }
//private:
//    int b2;
//};
//class Derive : public Base1, public Base2 {
//public:
//    virtual void func1() { cout << "Derive::func1" << endl; }
//    virtual void func3() { cout << "Derive::func3" << endl; }
//private:
//    int d1;
//};
//
//typedef void(*VFPTR) ();
//void PrintVTable(VFPTR vTable[])
//{
//    cout << " ����ַ>" << vTable << endl;
//    for (int i = 0; vTable[i] != nullptr; ++i)
//    {
//        printf(" ��%d���麯����ַ :0X%x,->", i, vTable[i]);
//        VFPTR f = vTable[i];
//        f();
//    }
//    cout << endl;
//}
//
//int main()
//{
//    Derive d;
//    VFPTR* vTableb1 = (VFPTR*)(*(int*)&d);
//    PrintVTable(vTableb1);
//    VFPTR* vTableb2 = (VFPTR*)(*(int*)((char*)&d + sizeof(Base1)));
//    PrintVTable(vTableb2);
//    // ����Ҳ���ԣ�������Ƭ
//    Base2* ptr = &d;
//    PrintVTable(((VFPTR*)*(int*)ptr));
//    return 0;
//}
#include <set>
#include <map>

void test_set1()
{
    // ȥ��+��������
    set<int> s1;
    // ȥ��+�������򣨸�һ�����ڵķº�����
    // set<int, greater<int>> s;

    s1.insert(1);
    s1.insert(11);
    s1.insert(3);
    s1.insert(1);
    s1.insert(4);
    s1.insert(2);

    set<int>::iterator it = s1.begin();
    while (it != s1.end())
    {
        // *it = 1; // ��֧���޸�
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    vector<int> v = { 3,2,8,1,10,2 };
    set<int> s2(v.begin(), v.end());
    for (auto e : s2)
    {
        cout << e << " ";
    }
    cout << endl;

    // ����һ��initializer_list�б�ֵ���Ѿ����ڵ�ֵ����ʧ��
    set<int> s3;
    s3.insert({ 3,2,8,1,10,2 });
    for (auto e : s3)
    {
        cout << e << " ";
    }
    cout << endl;

    // ɾ��
    s3.erase(8);
    s3.erase(18);
    for (auto e : s3)
    {
        cout << e << " ";
    }
    cout << endl;

    auto pos = s3.find(10);
    if (pos != s3.end())
    {
        cout << *pos << endl;
        s3.erase(pos);
    }
    else
    {
        cout << "�Ҳ���" << endl;
    }

    for (auto e : s3)
    {
        cout << e << " ";
    }
    cout << endl;

    set<string> strset = { "sort", "insert", "add" };
    // ����string�Ƚ�ascll���С˳�������
    for (auto& e : strset)
    {
        cout << e << " ";
    }
    cout << endl;
}

void test_set2()
{
    set<int> s = { 4,2,7,2,8,5,9 };
    for (auto e : s)
    {
        cout << e << " ";
    }
    cout << endl;

    int x;
    cin >> x;
    // �㷨��Ĳ��� O(N)
    auto pos1 = find(s.begin(), s.end(), x);
    // set����ʵ�ֵĲ��� O(logN)
    auto pos2 = s.find(x);

    // ����count���ʵ�ֿ��ٲ���
    cin >> x;
    if (s.count(x))
    {
        cout << x << "�ڣ�" << endl;
    }
    else
    {
        cout << x << "�����ڣ�" << endl;
    }

    std::set<int> myset;
    for (int i = 1; i < 10; i++)
        myset.insert(i * 10); // 10 20 30 40 50 60 70 80 90

    for (auto e : myset)
    {
        cout << e << " ";
    }
    cout << endl;

    // [25,60)
    auto itlow = myset.lower_bound(25);      // >=val	
    auto itup = myset.upper_bound(60);       // >val

    myset.erase(itlow, itup);
    for (auto e : myset)
    {
        cout << e << " ";
    }
    cout << endl;

    auto ret = myset.equal_range(35);
    std::cout << *ret.first << std::endl; // >=val
    std::cout << *ret.second << std::endl; // >val
}

void test_map1()
{
    map<string, string> dict;
    dict.insert(pair<string, string>("sort", "����"));
    dict.insert(pair<string, string>("inster", "����"));
    dict.insert(pair<const char*, const char*>("left", "��"));
    // �Ƽ�
    dict.insert(make_pair("right", "��"));
    // ����������֧�� ��ʽ����ת��
    dict.insert({ "left", "��" });

    string s1("xxx"), s2("yyy");
    dict.insert(make_pair(s1, s2));

    for (auto& e : dict)
    {
        cout << e.first << " " << e.second << endl;
    }
    cout << endl;
}

void test_map4()
{
    map<string, string> dict;
    dict.insert(pair<string, string>("sort", "����"));
    dict.insert(pair<string, string>("inster", "����"));
    dict.insert(pair<const char*, const char*>("left", "��"));

    dict.insert(make_pair("right", "��"));

    string s1("xxx"), s2("yyy");
    dict.insert(make_pair(s1, s2));

    dict["erase"];  // ����
    cout << dict["erase"] << endl; // ����
    dict["erase"] = "ɾ��"; // �޸�
    dict["test"] = "����";  // ����+�޸�
    dict["left"] = "��ߡ�ʣ��"; // �޸�

    map<string, string>::iterator it = dict.begin();
    while (it != dict.end())
    {
        //cout << (*it).first << " " << (*it).second << endl;
        cout << it->first << " " << it->second << endl;
        ++it;
    }
}

int main()
{
    // test_set1();
    // test_set2();
    //test_map1();
    test_map4();
    return 0;
}

 













 















 















 















 















 















 















 















 















 















 















 















 















 















 















 















 















 















 















 















 















 















 















 















 















 















 















 















 















 















 















 
















