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
//
//int main()
//{
//    // test_set1();
//    // test_set2();
//    //test_map1();
//    test_map4();
//    return 0;
//}
//
// 

//#include<iostream>
//#include<vector>
//using namespace std;
//struct Point
//{
//    int _x;
//    int _y;
//};
//class Date
//{
//public:
//    Date(int year = 1, int month = 1, int day = 1)
//        :_year(year)
//        , _month(month)
//        , _day(day)
//    {
//        cout << "Date(int year, int month, int day)" << endl;
//    }
//    Date(const Date& d)
//        :_year(d._year)
//        , _month(d._month)
//        , _day(d._day)
//    {
//        cout << "Date(const Date& d)" << endl;
//    }
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//// һ�нԿ����б��ʼ�����ҿ��Բ���=
//int main()
//{
//    //////////// C++98֧�ֵ� //////////////
//    int a1[] = { 1, 2, 3, 4, 5 };
//    int a2[5] = { 0 };
//    Point p = { 1, 2 };
//
//    /////////// C++11֧�ֵ� ///////////////
//    
//    // ��������֧��
//    int x1 = { 2 };
//
//    // �Զ�������֧��
//    // ���ﱾ������{ 2025, 1, 1}����һ��Date��ʱ����
//    // ��ʱ������ȥ��������d1���������Ż���϶�Ϊһ���{ 2025, 1, 1}ֱ�ӹ����ʼ��d1
//    // ����һ�£����ǿ�����֤��������ۣ�������û���ÿ��������
//    Date d1 = { 2025, 1, 1 };
//
//    // ����d2���õ���{ 2024, 7, 25 }�������ʱ����
//    const Date& d2 = { 2024, 7, 25 };
//    
//    // ��Ҫע�����C++98֧�ֵ�����ʱ����ת����Ҳ���Բ���{}
//    Date d3 = { 2025 };
//    Date d4 = 2025;
//    
//    // ����ʡ�Ե�=
//    Point p1{ 1, 2 };
//    int x2{ 2 };
//    Date d6{ 2024, 7, 25 };
//    const Date& d7{ 2024, 7, 25 };
//    
//    // ��֧�����������ֻ��{}��ʼ��������ʡ��=
//    // Date d8 2025;
//    vector<Date> v;
//    v.push_back(d1);
//    v.push_back(Date(2025, 1, 1));
//
//    // ��������������������󴫲Σ�����{}�����Լ۱�
//    v.push_back({ 2025, 1, 1 });
//    
//    return 0;
//}


//int main()
//{
//    std::initializer_list<int> mylist;
//    mylist = { 10, 20, 30 };
//    cout << sizeof(mylist) << endl;
//    
//    // ����begin��end���ص�ֵinitializer_list�����д������ָ��
//    // ������ָ���ֵ��i�ĵ�ַ���ӽ���˵���������ջ��
//    int i = 0;
//    cout << mylist.begin() << endl;
//    cout << mylist.end() << endl;
//    cout << &i << endl;
//    
//    // {}�б��п�����������ֵ
//    // ������д�������ϻ����в��ģ���һ��v1��ֱ�ӹ��죬
//    // �ڶ���v2�ǹ�����ʱ����+��ʱ���󿽱�v2+�Ż�Ϊֱ�ӹ���
//    vector<int> v1({ 1,2,3,4,5 });
//    vector<int> v2 = { 1,2,3,4,5 };
//    const vector<int>& v3 = { 1,2,3,4,5 };
//    // ������pair�����{}��ʼ����map��initializer_list�����ϵ�һ������
//    map<string, string> dict = { {"sort", "����"}, {"string", "�ַ���"} };
//    // initializer_list�汾�ĸ�ֵ֧��
//    v1 = { 10,20,30,40,50 };
//    return 0;
//}




//int main()
//{
//    vector<int> v1 = { 1,2,3,4 };
//    vector<int> v2 = { 1,2,3,4,5,6 };
//
//    v1 = { 10,20,30 };
//
//    list<int> lt = { 10,20,30 };
//
//    // �������������ת��  ����+��������->�Ż�ֱ�ӹ���
//    // ����Ӧ���캯����������ƥ��
//    Date d2 = { 2023, 11, 25 };
//
//    // the type of il is an initializer_list 
//    auto il1 = { 10, 20, 30, 40, 50 };
//    cout << typeid(il1).name() << endl;
//
//    initializer_list<int> il2 = { 10, 20, 30 };
//
//    initializer_list<int>::iterator it2 = il2.begin();
//    while (it2 != il2.end())
//    {
//        cout << *it2 << " ";
//        ++it2;
//    }
//    cout << endl;
//
//    //for (int e : il2)
//    for (auto e : il2)
//    {
//        cout << e << " ";
//    }
//    cout << endl;
//
//    pair<string, string> kv1("sort", "����");
//    map<string, string> dict = { {"insert", "����"}, {"get","��ȡ"} };
//    for (auto& kv : dict)
//    {
//        cout << kv.first << ":" << kv.second << endl;
//    }
//
//    Date dd2 = { 2023, 11, 25 };
//    // Date dd3 = { 2023, 11, 25, 20}; // ����
//
//    return 0;
//}

//int main()
//{
//    // ��ֵ����ֻ��������ֵ������������ֵ��
//    int a = 10;
//    int& ra1 = a;
//
//    // raΪa�ı���
//    int& ra2 = 10;   // ����ʧ�ܣ���Ϊ10����ֵ
//    // const��ֵ���üȿ�������ֵ��Ҳ��������ֵ��
//    const int& ra3 = 10;
//    const int& ra4 = a;
//    return 0;
//}
 

//int main()
//{
//    // ��ֵ����ֻ����ֵ������������ֵ��
//    int&& r1 = 10;
//
//    // error C2440: ����ʼ����: �޷��ӡ�int��ת��Ϊ��int &&��
//    // message : �޷�����ֵ�󶨵���ֵ����
//    int a = 10;
//    int&& r2 = a;
//
//    // ��ֵ���ÿ�������move�Ժ����ֵ
//    int&& r3 = std::move(a);
//    return 0;
//}



#include<assert.h>

namespace lsl
{
    class string
    {
    public:
        typedef char* iterator;
        typedef const char* const_iterator;
        iterator begin()
        {
            return _str;
        }
        iterator end()
        {
            return _str + _size;
        }
        const_iterator begin() const
        {
            return _str;
        }
        const_iterator end() const
        {
            return _str + _size;
        }
        string(const char* str = "")
            :_size(strlen(str))
            , _capacity(_size)
        {
            cout << "string(char* str)-����" << endl;
            _str = new char[_capacity + 1];
            strcpy(_str, str);
        }
        void swap(string& s)
        {
            ::swap(_str, s._str);
            ::swap(_size, s._size);
            ::swap(_capacity, s._capacity);
        }
        string(const string& s)
            :_str(nullptr)
        {
            cout << "string(const string& s) -- ��������" << endl;
            reserve(s._capacity);
            for (auto ch : s)
            {
                push_back(ch);
            }
        }
        // �ƶ�����
        string(string&& s)
        {
            cout << "string(string&& s) -- �ƶ�����" << endl;
            swap(s);
        }
        string& operator=(const string& s)
        {
            cout << "string& operator=(const string& s) -- ������ֵ" <<
                endl;
            if (this != &s)
            {
                _str[0] = '\0';
                _size = 0;
                reserve(s._capacity);
                for (auto ch : s)
                {
                    push_back(ch);
                }
            }
            return *this;
        }
        // �ƶ���ֵ
        string& operator=(string&& s)
        {
            cout << "string& operator=(string&& s) -- �ƶ���ֵ" << endl;
            swap(s);
            return *this;
        }
        ~string()
        {
            cout << "~string() -- ����" << endl;
            delete[] _str;
            _str = nullptr;
        }

        char& operator[](size_t pos)
        {
            assert(pos < _size);
            return _str[pos];
        }
        void reserve(size_t n)
        {
            if (n > _capacity)
            {
                char* tmp = new char[n + 1];
                if (_str)
                {
                    strcpy(tmp, _str);
                    delete[] _str;
                }
                _str = tmp;
                _capacity = n;
            }
        }
        void push_back(char ch)
        {
            if (_size >= _capacity)
            {
                size_t newcapacity = _capacity == 0 ? 4 : _capacity *
                    2;
                reserve(newcapacity);
            }
            _str[_size] = ch;
            ++_size;
            _str[_size] = '\0';
        }
        string& operator+=(char ch)
        {
            push_back(ch);
            return *this;
        }
        const char* c_str() const
        {
            return _str;
        }
        size_t size() const
        {
            return _size;
        }
    private:
        char* _str = nullptr;
        size_t _size = 0;
        size_t _capacity = 0;
    };
}

namespace lsl {
    string addStrings(string num1, string num2)
    {
        string str;
        int end1 = num1.size() - 1, end2 = num2.size() - 1;
        int next = 0;
        while (end1 >= 0 || end2 >= 0)
        {
            int val1 = end1 >= 0 ? num1[end1--] - '0' : 0;
            int val2 = end2 >= 0 ? num2[end2--] - '0' : 0;
            int ret = val1 + val2 + next;
            next = ret / 10;
            ret = ret % 10;
            str += ('0' + ret);
        }
        if (next == 1)
            str += '1';
        reverse(str.begin(), str.end());

        cout << "******************************" << endl;
        return str;
    }
}

//int main()
//{
//    lsl::string ret = lsl::addStrings("11111", "2222");
//    cout << &ret << endl;
//    cout << ret.c_str() << endl;
//    return 0;
//}


//int main()
//{
//    lsl::string ret;
//    ret = lsl::addStrings("11111", "2222");
//    cout << ret.c_str() << endl;
//    return 0;
//}

//int main()
//{
//    lsl::string s1("xxxxx");
//    // ��������
//    lsl::string s2 = s1;
//    // ����+�ƶ����죬�Ż���ֱ�ӹ���
//    lsl::string s3 = lsl::string("yyyyy");
//    // �ƶ�����
//    lsl::string s4 = move(s1);
//    return 0;
//}

//lsl::string to_string(int x)
//{
//    lsl::string ret;
//    while (x)
//    {
//        int val = x % 10;
//        x /= 10;
//        ret += ('0' + val);
//    }
//    reverse(ret.begin(), ret.end());
//
//    return ret;
//}
//
//int main()
//{
//    lsl::string ret = lsl::to_string(1234);
//    return 0;
//}

//void func1(lsl::string s)
//{
//}
//void func2(const lsl::string& s)
//{
//}
//int main()
//{
//    lsl::string s1("hello world");
//    // func1��func2�ĵ������ǿ��Կ�����ֵ���������������˿��������Ч�ʵ�ʹ�ó����ͼ�ֵ
//    func1(s1);
//    func2(s1);
//
//    s1 += '!';
//    return 0;
//}



//int main()
//{
//    // ��ֵ������ȡ��ַ
//    // ���µ�p��b��c��*p��s��s[0]���ǳ�������ֵ
//    int* p = new int(0);
//    int b = 1;
//    const int c = b;
//    *p = 10;
//    string s("111111");
//    s[0] = 'x';
//    double x = 1.1, y = 2.2;
//
//    // ��ֵ���ø���ֵȡ����
//    int& r1 = b;
//    int*& r2 = p;
//    int& r3 = *p;
//    string& r4 = s;
//    char& r5 = s[0];
// 
//    // ��ֵ���ø���ֵȡ����
//    int&& rr1 = 10;
//    double&& rr2 = x + y;
//    double&& rr3 = fmin(x, y);
//    string&& rr4 = string("11111");
//
//    // ��ֵ���ò���ֱ��������ֵ������const��ֵ���ÿ���������ֵ
//    const int& rx1 = 10;
//    const double& rx2 = x + y;
//    const double& rx3 = fmin(x, y);
//    const string& rx4 = string("11111");
//
//    // ��ֵ���ò���ֱ��������ֵ��������ֵ���ÿ�������move(��ֵ)
//    int&& rrx1 = move(b);
//    int*&& rrx2 = move(p);
//    int&& rrx3 = move(*p);
//    string&& rrx4 = move(s);
//    string&& rrx5 = (string&&)s;
//
//    // b��r1��rr1���Ǳ������ʽ��������ֵ
//    cout << &b << endl;
//    cout << &r1 << endl;
//    cout << &rr1 << endl;
//
//    // ����Ҫע����ǣ�rr1����������ֵ�����Բ����ٱ���ֵ���ð󶨣�����moveһ��
//    int& r6 = r1;
//    // int&& rrx6 = rr1;
//    int&& rrx6 = move(rr1);
//    return 0;
//}


//int main()
//{
//    std::string s1 = "Test";
//    // std::string&& r1 = s1; // ���󣺲��ܰ󶨵���ֵ
//
//    const std::string& r2 = s1 + s1; // OK���� const ����ֵ�����ӳ�������
//    
//    // r2 += "Test"; // ���󣺲���ͨ���� const �������޸�
//    std::string&& r3 = s1 + s1; // OK����ֵ�����ӳ�������
//    r3 += "Test"; // OK����ͨ������ const �������޸�
//    
//    std::cout << r3 << '\n';
//    return 0;
//}


//void f(int& x)
//{
//    std::cout << "��ֵ�������� f(" << x << ")\n";
//}
//void f(const int& x)
//{
//    std::cout << "�� const ����ֵ�������� f(" << x << ")\n";
//}
//void f(int&& x)
//{
//    std::cout << "��ֵ�������� f(" << x << ")\n";
//}
//
//int main()
//{
//    int i = 1;
//    const int ci = 2;
//    f(i); // ���� f(int&)
//    f(ci); // ���� f(const int&)
//
//    f(3); // ���� f(int&&)�����û�� f(int&&) ���������� f(const int&)
//    f(std::move(i)); // ���� f(int&&)
//
//    // ��ֵ���ñ��������ڱ��ʽʱ����ֵ(ע��)
//    int&& x = 1;
//    f(x); // ���� f(int& x)
//    f(std::move(x)); // ���� f(int&& x)
//    return 0;
//}


#include"list.h"
//int main()
//{
// 
//    lsl::list<lsl::string> lt;
//    cout << "*************************" << endl;
//    lsl::string s1("111111111111111111111");
//    lt.push_back(s1);
//    cout << "*************************" << endl;
//    lt.push_back(lsl::string("22222222222222222222222222222"));
//    cout << "*************************" << endl;
//    lt.push_back("3333333333333333333333333333");
//    cout << "*************************" << endl;
//    lt.push_back(move(s1));
//    cout << "*************************" << endl;
//    return 0;
//}

//template<class ...Args>
//void Print(Args... args)
//{
//    cout << sizeof...(args) << endl;
//}
//
//int main()
//{
//    double x = 2.2;
//    Print(); // ������0������
//    Print(1); // ������1������
//    Print(1, string("xxxxx")); // ������2������
//    Print(1.1, string("xxxxx"), x); // ������3������
//    return 0;
//}

//template <class ...Args>
//void Print(Args... args)
//{
//	// �ɱ����ģ�����ʱ����
//	// ���������л�ȡ�ͽ��������Բ�֧��������
//	cout << sizeof...(args) << endl;
//	for (size_t i = 0; i < sizeof...(args); i++)
//	{
//		cout << args[i] << " ";
//	}
//	cout << endl;
//}

//void ShowList()
//{
//    // ������ʱ�ݹ����ֹ��������������0��ʱ��ֱ��ƥ���������
//    cout << endl;
//}
//template <class T, class ...Args>
//void ShowList(T x, Args... args)
//{
//    cout << x << " ";
//    // args��N�������Ĳ�����
//    // ����ShowList���������ĵ�һ������x��ʣ��N-1�����ڶ���������
//    ShowList(args...);
//}
//// ����ʱ�ݹ��Ƶ���������
//template <class ...Args>
//void Print(Args... args)
//{
//    ShowList(args...);
//}
//int main()
//{
//    Print();
//    Print(1);
//    Print(1, string("xxxxx"));
//    Print(1, string("xxxxx"), 2.2);
//    return 0;
//}

//template <class T>
//const T& GetArg(const T& x)
//{
//    cout << x << " ";
//    return x;
//}
//
//template <class ...Args>
//void Arguments(Args... args)
//{
//}
//
//template <class ...Args>
//void Print(Args... args)
//{
//    // ע��GetArg���뷵�ػ��ߵ��Ķ�������������ɲ�������Arguments
//    Arguments(GetArg(args)...);
//}
//// ���ʿ������Ϊ����������ʱ��������չģʽ
//// ������ĺ���ģ����չʵ����Ϊ����ĺ���
//// �ǲ��Ǻܳ���C++11�Ժ�ֻ��˵ίԱ��Ĵ�������﷨˼ά��Ծ��̫����
////void Print(int x, string y, double z)
////{
//// Arguments(GetArg(x), GetArg(y), GetArg(z));
////}
//
//int main()
//{
//    Print(1, string("xxxxx"), 2.2);
//    return 0;
//}

//int main()
//{
//    lsl::list<lsl::string> lt;
//    // ����ֵ����push_backһ�����߿�������
//    lsl::string s1("111111111111");
//    lt.emplace_back(s1);
//    cout << "*********************************" << endl;
//
//    // ��ֵ����push_backһ�������ƶ�����
//    lt.emplace_back(move(s1));
//    cout << "*********************************" << endl;
//
//    // ֱ�Ӱѹ���string���������´���ֱ����string����������string
//    // ����ﵽ��Ч����push_back��������
//    lt.emplace_back("111111111111");
//    cout << "*********************************" << endl;
//
//    lsl::list<pair<lsl::string, int>> lt1;
//    // ��push_backһ��
//    // ����pair + ����/�ƶ�����pair��list�Ľڵ���data��
//    pair<lsl::string, int> kv("ƻ��", 1);
//    lt1.emplace_back(kv);
//    cout << "*********************************" << endl;
//
//    // ��push_backһ��
//    lt1.emplace_back(move(kv));
//    cout << "*********************************" << endl;
//
//    ////////////////////////////////////////////////////////////////////
//    // ֱ�Ӱѹ���pair���������´���ֱ����pair����������pair
//    // ����ﵽ��Ч����push_back��������
//    lt1.emplace_back("ƻ��", 1);
//    cout << "*********************************" << endl;
//
//    return 0;
//}



#include<functional>
//
//void swap_func(int& r1, int& r2)
//{
//    int tmp = r1;
//    r1 = r2;
//    r2 = tmp;
//}
//
//struct Swap
//{
//    void operator()(int& r1, int& r2)
//    {
//        int tmp = r1;
//        r1 = r2;
//        r2 = tmp;
//    }
//};
//
//
//int main()
//{
//    int x = 0, y = 1;
//    cout << x << ":" << y << endl;
//
//    // lambda
//    auto swaplambda = [](int& r1, int& r2) {int tmp = r1; r1 = r2; r2 = tmp; };
//
//    // ����ָ��
//    function<void(int&, int&)> f1 = swap_func;
//    f1(x, y);
//    cout << x << " " << y << endl << endl;
//    // ��[��������]
//    function<void(int&, int&)> f2 = Swap();
//    f2(x, y);
//    cout << x << " " << y << endl << endl;
//    // lambda
//    function<void(int&, int&)> f3 = swaplambda;
//    f3(x, y);
//    cout << x << " " << y << endl << endl;
//
//    map<std::string, std::function<void(int&, int&)>> CmdOp{
//        {"����ָ��", swap_func},
//        {"�º���", Swap()},
//        {"lambda", swaplambda},
//
//        //{"����ָ��", f1},
//        //{"�º���", f2},
//        //{"lambda", f3},
//    };
//
//    // ʹ��
//    CmdOp["����ָ��"](x, y);
//    cout << x << " " << y << endl << endl;
//
//    CmdOp["�º���"](x, y);
//    cout << x << " " << y << endl << endl;
//
//    CmdOp["lambda"](x, y);
//    cout << x << " " << y << endl << endl;
//
//    return 0;
//}




//int Sub(int a, int b)
//{
//    return a - b;
//}
//
//int main()
//{
//    function<int(int, int)> f1 = Sub;
//    cout << f1(10, 5) << endl;
//
//    // ��������˳��
//    function<int(int, int)> f2 = bind(Sub, placeholders::_2, placeholders::_1);
//    cout << f2(10, 5) << endl;
//
//    // ����������������Щ��������bindʱд��
//    function<int(int)> f3 = bind(Sub, 20, placeholders::_1);
//    cout << f3(5) << endl;
//
//    return 0;
//}
//

//#include <iostream>
//int main() {
//    auto func = [] (){ std::cout << "Hello, World!" << std::endl; };
//    func();
//    return 0;
//}

//double Divide(int a, int b)
//{
//    try
//    {
//        // ��b == 0ʱ�׳��쳣
//        if (b == 0)
//        {
//            string s("Divide by zero condition!");
//            throw s;
//        }
//        else
//        {
//            return ((double)a / (double)b);
//        }
//    }
//    catch (int errid)
//    {
//        cout << errid << endl;
//    }
//}
//
//void Func()
//{
//	int len, time;
//	cin >> len >> time;
//	try
//	{
//		cout << Divide(len, time) << endl;
//	}
//	catch (const char* errmsg)
//	{
//		cout << errmsg << endl;
//	}
//	cout << __FUNCTION__ << ":" << __LINE__ << "��ִ��" << endl;
//}
//
//int main()
//{
//	while (1)
//	{
//		try
//		{
//			Func();
//		}
//		catch (const string& errmsg)
//		{
//			cout << errmsg << endl;
//		}
//	}
//
//	return 0;
//}



// һ�������Ŀ����Ż�ʹ���쳣����������ģ�����һ������ļ���ģ��
// ÿ��ģ��ļ̳ж���Exception�������࣬ÿ��ģ���������Լ�������
// ��󲶻�ʱ�����ǲ������Ϳ���
#include <thread>
class Exception
{
public:
    Exception(const string& errmsg, int id)
        :_errmsg(errmsg)
        , _id(id)
    {
    }

    virtual string what() const
    {
        return _errmsg;
    }

    int getid() const
    {
        return _id;
    }

protected:
    string _errmsg;
    int _id;
};

class SqlException : public Exception
{
public:
    SqlException(const string& errmsg, int id, const string& sql)
        :Exception(errmsg, id)
        , _sql(sql)
    {
    }

    virtual string what() const
    {
        string str = "SqlException:";
        str += _errmsg;
        str += "->";
        str += _sql;
        return str;
    }
private:
    const string _sql;
};

class CacheException : public Exception
{
public:
    CacheException(const string& errmsg, int id)
        :Exception(errmsg, id)
    {
    }

    virtual string what() const
    {
        string str = "CacheException:";
        str += _errmsg;
        return str;
    }
};

class HttpException : public Exception
{
public:
    HttpException(const string& errmsg, int id, const string& type)
        :Exception(errmsg, id)
        , _type(type)
    {
    }

    virtual string what() const
    {
        string str = "HttpException:";
        str += _type;
        str += ":";
        str += _errmsg;
        return str;
    }
private:
    const string _type;
};

void SQLMgr()
{
    if (rand() % 7 == 0)
    {
        throw SqlException("Ȩ�޲���", 100, "select * from name = '����'");
    }
    else
    {
        cout << "SQLMgr ���óɹ�" << endl;
    }
}

void CacheMgr()
{
    if (rand() % 5 == 0)
    {
        throw CacheException("Ȩ�޲���", 100);
    }
    else if (rand() % 6 == 0)
    {
        throw CacheException("���ݲ�����", 101);
    }
    else
    {
        cout << "CacheMgr ���óɹ�" << endl;
    }
    SQLMgr();
}

void HttpServer()
{
    if (rand() % 3 == 0)
    {
        throw HttpException("������Դ������", 100, "get");
    }
    else if (rand() % 4 == 0)
    {
        throw HttpException("Ȩ�޲���", 101, "post");
    }
    else
    {
        cout << "HttpServer���óɹ�" << endl;
    }
    CacheMgr();
}
//
//int main()
//{
//	srand(time(0));
//	while (1)
//	{
//		this_thread::sleep_for(chrono::seconds(1));
//
//		try
//		{
//			HttpServer();
//		}
//		catch (const Exception& e) // ���ﲶ����࣬����������������󶼿��Ա�����
//		{
//			cout << e.what() << endl;
//		}
//		catch (...)
//		{
//			cout << "δ֪�쳣" << endl;
//		}
//	}
//	return 0;
//}

void _SeedMsg(const string& s)
{
	if (rand() % 3 == 0)
	{
		throw HttpException("���粻�ȶ�������ʧ��", 102, "put");
	}
	else if (rand() % 7 == 0)
	{
		throw HttpException("���Ѿ����Ƕ���ĺ��ѣ�����ʧ��", 103, "put");
	}
	else
	{
		cout << "���ͳɹ�" << endl;
	}
}

void SendMsg(const string& s)
{
	// ������Ϣʧ�ܣ���������3��
	for (size_t i = 0; i < 4; i++)
	{
		try
		{
			_SeedMsg(s);
			break;
		}
		catch (const Exception& e)
		{
			// �����쳣��if����102�Ŵ������粻�ȶ��������·���
			// �����쳣��else�в���102�Ŵ������쳣�����׳�
			if (e.getid() == 102)
			{
				// ���������Ժ��ʧ���ˣ���˵������̫���ˣ������׳��쳣
				if (i == 3)
					throw;

				cout << "��ʼ��" << i + 1 << "������" << endl;
			}
			else
			{
				throw;
			}
		}
	}
}

//int main()
//{
//	srand(time(0));
//	string str;
//	while (cin >> str)
//	{
//		try
//		{
//			SendMsg(str);
//		}
//		catch (const Exception& e)
//		{
//			cout << e.what() << endl << endl;
//		}
//		catch (...)
//		{
//			cout << "Unkown Exception" << endl;
//		}
//	}
//
//	return 0;
//}


//double Divide(int a, int b) noexcept
//{
//    // ��b == 0ʱ�׳��쳣
//    if (b == 0)
//    {
//        throw "Division by zero condition!";
//    }
//    return (double)a / (double)b;
//}
//
//int main()
//{
//    int i = 0;
//    cout << noexcept(Divide(1, 2)) << endl;
//    cout << noexcept(Divide(1, 0)) << endl;
//    cout << noexcept(++i) << endl;
//
//    try
//    {
//        int len, time;
//        cin >> len >> time;
//        cout << Divide(len, time) << endl;
//    }
//    catch (const char* errmsg)
//    {
//        cout << errmsg << endl;
//    }
//    catch (...)
//    {
//        cout << "Unkown Exception" << endl;
//    }
//
//    return 0;
//}
#include <functional>
//namespace lsl {
//    template <class T>
//    class shared_ptr
//    {
//    public:
//        explicit shared_ptr(T* ptr = nullptr)
//            : _ptr(ptr)
//            , _pcount(new int(1))
//        {
//        }
//
//        template<class D>
//        shared_ptr(T* ptr, D del)
//            :_ptr(ptr)
//            , _pcount(new int(1))
//            , _del(del)
//        {
//        }
//
//        shared_ptr(const shared_ptr<T>& sp)
//            :_ptr(sp._ptr)
//            , _pcount(sp._pcount)
//            , _del(sp._del)
//        {
//            ++*(_pcount);
//        }
//
//        void release()
//        {
//            if (--*(_pcount) == 0)
//            {
//                // ����
//                //delete _ptr;
//                _del(_ptr);
//                delete _pcount;
//            }
//        }
//
//        // sp1 = sp2
//        shared_ptr<T>& operator=(const shared_ptr<T>& sp)
//        {
//            if (_ptr != sp._ptr)
//            {
//                release();
//                _ptr = sp._ptr;
//                _pcount = sp._pcount;
//                ++(*_pcount);
//                _del = sp._del;
//            }
//            return *this;
//        }
//
//        T* get() const
//        {
//            return _ptr;
//        }
//
//        int use_count() const
//        {
//            return *(_pcount);
//        }
//
//        T& operator*()
//        {
//            return *_ptr;
//        }
//
//        T* operator->()
//        {
//            return _ptr;
//        }
//        
//        ~shared_ptr()
//        {
//            release();
//        }
//
//    private:
//        T* _ptr;
//        int* _pcount;
//		function<void(T*)> _del = [](T* ptr) {delete ptr;};
//    };
//    template<class T>
//    class weak_ptr
//    {
//    public:
//        weak_ptr()
//            :_ptr(nullptr)
//        {
//        }
//
//        weak_ptr(const shared_ptr<T>& we)
//            :_ptr(we.get())
//        {
//        }
//
//        weak_ptr<T>& operator=(const shared_ptr<T>& we)
//        {
//            _ptr = we.get();
//            return *this;
//        }
//
//
//        T& operator*()
//        {
//            return *_ptr;
//        }
//
//        T* operator->()
//        {
//            return _ptr;
//        }
//
//    private:
//        T* _ptr;
//    };
//}


struct Date
{
    int _year;
    int _month;
    int _day;
    Date(int year = 1, int month = 1, int day = 1)
        :_year(year)
        , _month(month)
        , _day(day)
    {}
    ~Date()
    {
        cout << "~Date()" << endl;
    }
};


//int main()
//{
//    auto_ptr<Date> ap1(new Date);
//    // ����ʱ������Ȩ��ת�ƣ�����������ap1����
//    auto_ptr<Date> ap2(ap1);
//    // ��ָ����ʣ�ap1�����Ѿ�����
//    //ap1->_year++;
//
//
//    unique_ptr<Date> up1(new Date);
//    // ��֧�ֿ���
//    //unique_ptr<Date> up2(up1);
//    // ֧���ƶ��������ƶ���up1Ҳ���գ�����ʹ���ƶ�Ҫ����
//    unique_ptr<Date> up3(move(up1));
//    
//    shared_ptr<Date> sp1(new Date);
//    // ֧�ֿ���
//    shared_ptr<Date> sp2(sp1);
//    shared_ptr<Date> sp3(sp2);
//    cout << sp1.use_count() << endl;
//    sp1->_year++;
//    cout << sp1->_year << endl;
//    cout << sp2->_year << endl;
//    cout << sp3->_year << endl;
//    // ֧���ƶ��������ƶ���sp1Ҳ���գ�����ʹ���ƶ�Ҫ����
//    shared_ptr<Date> sp4(move(sp1));
//    return 0;
//}

template<class T>
void DeleteArrayFunc(T* ptr)
{
    delete[] ptr;
}

template<class T>
class DeleteArray
{
public:
    void operator()(T* ptr)
    {
        delete[] ptr;
    }
};

class Fclose
{
public:
    void operator()(FILE* ptr)
    {
        cout << "fclose:" << ptr << endl;
        fclose(ptr);
    }
};

//int main()
//{
//    // ��Ϊnew[]����ʹ�ã�����unique_ptr��shared_ptr
//    // ʵ����һ���ػ��汾������ػ��汾����ʱ�õ�delete[]
//	//shared_ptr<Date[]> sp1(new Date[10]);
//    //unique_ptr<Date[]> up1(new Date[10]);
//
//    // ����ɾ����  ����ָ��/�º���/lambda
//    lsl::shared_ptr<Date> sp2(new Date[5], DeleteArray<Date>());
//    lsl::shared_ptr<Date> sp3(new Date[5], DeleteArrayFunc<Date>);
//
//	auto delArrOBJ = [](Date* ptr) {delete[] ptr; };
//    lsl::shared_ptr<Date> sp4(new Date[5], delArrOBJ);
//	// ʵ��������Դ�����ɾ����
//    lsl::shared_ptr<FILE> sp5(fopen("Test.cpp", "r"), Fclose());
//    lsl::shared_ptr<FILE> sp6(fopen("Test.cpp", "r"), [](FILE* ptr) {
//		    cout << "fclose:" << ptr << endl;
//		    fclose(ptr);
//		});
//
//    // ����Ҳ����
//    lsl::shared_ptr<Date> sp7(new Date);
//
//	unique_ptr<Date, DeleteArray<Date>> up2(new Date[5]);
//	unique_ptr<Date, void(*)(Date*)> up3(new Date[5], DeleteArrayFunc<Date>);
//	// decltype��������ͣ�decltype���Ƶ����������
//	unique_ptr<Date, decltype(delArrOBJ)> up4(new Date[5], delArrOBJ);
//
//	return 0;
//}

//int main()
//{
//	shared_ptr<Date> sp1(new Date(2024, 9, 11));
//	shared_ptr<Date> sp2 = make_shared<Date>(2024, 9, 11);
//	auto sp3 = make_shared<Date>(2024, 9, 11);
//	shared_ptr<Date> sp4;
//
//	if (sp1.operator bool())
//	//if (sp1) // �ȼ�
//		cout << "sp1 is not nullptr" << endl;
//
//	if (!sp4)
//		cout << "sp1 is nullptr" << endl;
//
//	// ������������ת��
//	//shared_ptr<Date> sp5 = new Date(2024, 9, 11);
//	//unique_ptr<Date> sp6 = new Date(2024, 9, 11);
//
//	return 0;
//}


//int main()
//{
//    std::shared_ptr<string> sp1(new string("111111"));
//    std::shared_ptr<string> sp2(sp1);
//    std::weak_ptr<string> wp = sp1;
//    cout << wp.expired() << endl;
//    cout << wp.use_count() << endl;
//    // sp1��sp2��ָ����������Դ����weak_ptr�͹�����
//    sp1 = make_shared<string>("222222");
//    cout << wp.expired() << endl;
//    cout << wp.use_count() << endl;
//    sp2 = make_shared<string>("333333");
//    cout << wp.expired() << endl;
//    cout << wp.use_count() << endl;
//    wp = sp1;
//    //std::shared_ptr<string> sp3 = wp.lock();
//    auto sp3 = wp.lock();
//    cout << wp.expired() << endl;
//    cout << wp.use_count() << endl;
//    *sp3 += "###";
//    cout << *sp1 << endl;
//    return 0;
//}


namespace lsl {
    template <class T>
    class shared_ptr
    {
    public:
        shared_ptr(T* ptr = nullptr)
            :_ptr(ptr)
            ,_pcount(new int(1))
        { }
 
        template <class D>
        shared_ptr(T* ptr, D del)
            :_ptr(ptr)
            ,_pcount(new int(1))
            ,_del(del)
        { }

        shared_ptr(const shared_ptr<T>& sp)
            :_ptr(sp._ptr)
            ,_pcount(sp._pcount)
        { 
            ++*_pcount;
        }

        void release()
        {
            if (--(*_pcount) == 0)
            {
                _del(_ptr);
                delete _pcount;
            }
        }
        // s1 = s2
        shared_ptr<T>& operator=(const shared_ptr<T>& sp)
        {
            if (_ptr != sp._ptr)
            {
                release(); // �ͷ�s1
                _ptr = sp._ptr;
                _pcount = sp._pcount;
                ++*_pcount;
                _del = sp._del;
            }
            return *this;
        }
        ~shared_ptr()
        {
            release();
        }
        T& operator*()
        {
            return *_ptr;
        }

        T* operator->()
        {
            return _ptr;
        }

        int use_count() const 
        {
            return *_pcount;
        }

        T* get() const 
        {
            return _ptr;
        }

    private:
        T* _ptr;
        atomic<int>* _pcount;
        function<void(T*)> _del = [](T* ptr) {delete ptr;};
    };

    template<class T>
    class weak_ptr
    {
    public:
        weak_ptr() = default;
        weak_ptr(const shared_ptr<T>& sp)
            :_ptr(sp.get())
        { }

        weak_ptr<T>& operator=(const shared_ptr<T>& sp)
        {
            _ptr = sp.get();
            return *this;
        }

    private:
        T* _ptr = nullptr;
    };
}
