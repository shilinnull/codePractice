#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <list>
using namespace std;

//
//void Print(const vector<int>& v)
//{
//	// 1. 第一种这种可以直接使用
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
//	// 2. 如果直接使用的话，没有实例化时不知道这个const_iterator是什么类型
//	//vector<T>::const_iterator it = v.begin();
//	
//	// 所以在前面需要加上typename来告诉编译器
//	typename vector<T>::const_iterator it = v.begin();
//	//auto it = v.begin(); // 更简单的方式
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
//    string _name = "peter"; // 姓名
//    int _age = 18; // 年龄
//};
//
//class Student : public Person
//{
//protected:
//    int _stuid; // 学号
//};
//
//
//class Teacher : public Person
//{
//protected:
//    int _jobid; // 工号
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
//	string _name; // 姓名
//private:
//	int _age; // 年龄
//};
////class Student : protected Person
////class Student : private Person
//class Student : public Person
//{
//protected:
//	int _stunum; // 学号
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
//	// stack和vector的关系，既符合is-a，也符合has-a
//	template<class T>
//	class stack : public std::vector<T>
//	{
//	public:
//		void push(const T& x)
//		{
//			// 基类是类模板时，需要指定一下类域，
//			// 否则编译报错:error C3861: “push_back”: 找不到标识符
//			// 因为stack<int>实例化时，也实例化vector<int>了
//			// 但是模版是按需实例化，push_back等成员函数未实例化，所以找不到
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
//    string _name = "peter"; // 姓名
//    int _age = 18; // 年龄
//};
//
//class Student : public Person
//{
//protected:
//    int _stuid; // 学号
//    int _major; // 专业
//};
//
//int main()
//{
//    Student s;
//    Person p = s; // 只有公有继承才可以
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

//// C++11的方法
//class Base final
//{
//public:
//	void func5() { cout << "Base::func5" << endl; }
//protected:
//	int a = 1;
//private:
//	// C++98的方法
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
//    string _name; // 姓名
//};
//
//class Student : virtual public Person
//{
//protected:
//    int _num; //学号
//};
//
//class Teacher : virtual public Person
//{
//protected:
//    int _id; // 职工编号
//};
//
//class Assistant : public Student, public Teacher
//{
//protected:
//    string _majorCourse; // 主修课程
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
//    virtual void BuyTicket() { cout << "买票-全价" << endl; }
//};
//
//class Student : public Person {
//public:
//    void BuyTicket() { cout << "买票-半价" << endl; }
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
//		cout << "买票-全价" << endl;
//		return nullptr;
//	}
//};
//
//class Student : public Person {
//public:
//	virtual Person* BuyTicket()
//	{
//		cout << "买票-打折" << endl;
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
//    // 只有派生类B的析构函数重写了A的析构函数，下面的delete对象调用析构函数，
//    // 才能构成多态，才能保证p1和p2指向的对象正确的调用析构函数。
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
//    virtual void Drive() { cout << "Benz-舒适" << endl; }
//};

//class Car {
//public:
//    virtual void Drive() {}
//};
//class Benz :public Car {
//public:
//    virtual void Drive() override { cout << "Benz-舒适" << endl; }
//};


////抽象类（接口类）
//class Car
//{
//public:
//    //纯虚函数
//    virtual void Drive() = 0;
//};
////派生类
//class Benz : public Car
//{
//public:
//    //重写纯虚函数
//    virtual void Drive()
//    {
//        cout << "Benz-舒适" << endl;
//    }
//};
////派生类
//class BMW : public Car
//{
//public:
//    //重写纯虚函数
//    virtual void Drive()
//    {
//        cout << "BMW-操控" << endl;
//    }
//};
//
//int main()
//{
//    // 编译报错：error C2259: “Car”: 无法实例化抽象类
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
//    printf("静态区:%p\n", &a);
//    printf("栈:%p\n", &b);
//    printf("堆:%p\n", p1);
//    printf("代码段:%p\n", p2);
//    printf("虚表:%p\n", *((int*)&b1));
//    printf("虚函数地址:%p\n", &Base::func1);
//    printf("普通函数地址:%p\n", func);
//
//    return 0;
//}
//
// 

//
//class Person {
//public:
//    virtual void BuyTicket() { cout << "买票-全价" << endl; }
//};
//
//class Student : public Person {
//public:
//    virtual void BuyTicket() { cout << "买票-半价" << endl; }
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
//// 打印虚表
//typedef void(*VFPTR) ();
//void PrintVTable(VFPTR vTable[])
//{
//    // 依次取虚表中的虚函数指针打印并调用。调用就可以看出存的是哪个函数
//    cout << " 虚表地址>" << vTable << endl;
//    for (int i = 0; vTable[i] != nullptr; ++i)
//    {
//        printf(" 第%d个虚函数地址 :0X%x,->", i, vTable[i]);
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
//    cout << " 虚表地址>" << vTable << endl;
//    for (int i = 0; vTable[i] != nullptr; ++i)
//    {
//        printf(" 第%d个虚函数地址 :0X%x,->", i, vTable[i]);
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
//    // 这样也可以，发生切片
//    Base2* ptr = &d;
//    PrintVTable(((VFPTR*)*(int*)ptr));
//    return 0;
//}
#include <set>
#include <map>

void test_set1()
{
    // 去重+升序排序
    set<int> s1;
    // 去重+降序排序（给一个大于的仿函数）
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
        // *it = 1; // 不支持修改
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

    // 插入一段initializer_list列表值，已经存在的值插入失败
    set<int> s3;
    s3.insert({ 3,2,8,1,10,2 });
    for (auto e : s3)
    {
        cout << e << " ";
    }
    cout << endl;

    // 删除
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
        cout << "找不到" << endl;
    }

    for (auto e : s3)
    {
        cout << e << " ";
    }
    cout << endl;

    set<string> strset = { "sort", "insert", "add" };
    // 遍历string比较ascll码大小顺序遍历的
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
    // 算法库的查找 O(N)
    auto pos1 = find(s.begin(), s.end(), x);
    // set自身实现的查找 O(logN)
    auto pos2 = s.find(x);

    // 利用count间接实现快速查找
    cin >> x;
    if (s.count(x))
    {
        cout << x << "在！" << endl;
    }
    else
    {
        cout << x << "不存在！" << endl;
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
    dict.insert(pair<string, string>("sort", "排序"));
    dict.insert(pair<string, string>("inster", "插入"));
    dict.insert(pair<const char*, const char*>("left", "左"));
    // 推荐
    dict.insert(make_pair("right", "右"));
    // 单参数类型支持 隐式类型转换
    dict.insert({ "left", "左" });

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
    dict.insert(pair<string, string>("sort", "排序"));
    dict.insert(pair<string, string>("inster", "插入"));
    dict.insert(pair<const char*, const char*>("left", "左"));

    dict.insert(make_pair("right", "右"));

    string s1("xxx"), s2("yyy");
    dict.insert(make_pair(s1, s2));

    dict["erase"];  // 插入
    cout << dict["erase"] << endl; // 查找
    dict["erase"] = "删除"; // 修改
    dict["test"] = "测试";  // 插入+修改
    dict["left"] = "左边、剩余"; // 修改

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
//// 一切皆可用列表初始化，且可以不加=
//int main()
//{
//    //////////// C++98支持的 //////////////
//    int a1[] = { 1, 2, 3, 4, 5 };
//    int a2[5] = { 0 };
//    Point p = { 1, 2 };
//
//    /////////// C++11支持的 ///////////////
//    
//    // 内置类型支持
//    int x1 = { 2 };
//
//    // 自定义类型支持
//    // 这里本质是用{ 2025, 1, 1}构造一个Date临时对象
//    // 临时对象再去拷贝构造d1，编译器优化后合二为一变成{ 2025, 1, 1}直接构造初始化d1
//    // 运行一下，我们可以验证上面的理论，发现是没调用拷贝构造的
//    Date d1 = { 2025, 1, 1 };
//
//    // 这里d2引用的是{ 2024, 7, 25 }构造的临时对象
//    const Date& d2 = { 2024, 7, 25 };
//    
//    // 需要注意的是C++98支持单参数时类型转换，也可以不用{}
//    Date d3 = { 2025 };
//    Date d4 = 2025;
//    
//    // 可以省略掉=
//    Point p1{ 1, 2 };
//    int x2{ 2 };
//    Date d6{ 2024, 7, 25 };
//    const Date& d7{ 2024, 7, 25 };
//    
//    // 不支持下面这个，只有{}初始化，才能省略=
//    // Date d8 2025;
//    vector<Date> v;
//    v.push_back(d1);
//    v.push_back(Date(2025, 1, 1));
//
//    // 比起有名对象和匿名对象传参，这里{}更有性价比
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
//    // 这里begin和end返回的值initializer_list对象中存的两个指针
//    // 这两个指针的值跟i的地址跟接近，说明数组存在栈上
//    int i = 0;
//    cout << mylist.begin() << endl;
//    cout << mylist.end() << endl;
//    cout << &i << endl;
//    
//    // {}列表中可以有任意多个值
//    // 这两个写法语义上还是有差别的，第一个v1是直接构造，
//    // 第二个v2是构造临时对象+临时对象拷贝v2+优化为直接构造
//    vector<int> v1({ 1,2,3,4,5 });
//    vector<int> v2 = { 1,2,3,4,5 };
//    const vector<int>& v3 = { 1,2,3,4,5 };
//    // 这里是pair对象的{}初始化和map的initializer_list构造结合到一起用了
//    map<string, string> dict = { {"sort", "排序"}, {"string", "字符串"} };
//    // initializer_list版本的赋值支持
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
//    // 多参数构造类型转换  构造+拷贝构造->优化直接构造
//    // 跟对应构造函数参数个数匹配
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
//    pair<string, string> kv1("sort", "排序");
//    map<string, string> dict = { {"insert", "插入"}, {"get","获取"} };
//    for (auto& kv : dict)
//    {
//        cout << kv.first << ":" << kv.second << endl;
//    }
//
//    Date dd2 = { 2023, 11, 25 };
//    // Date dd3 = { 2023, 11, 25, 20}; // 报错
//
//    return 0;
//}

//int main()
//{
//    // 左值引用只能引用左值，不能引用右值。
//    int a = 10;
//    int& ra1 = a;
//
//    // ra为a的别名
//    int& ra2 = 10;   // 编译失败，因为10是右值
//    // const左值引用既可引用左值，也可引用右值。
//    const int& ra3 = 10;
//    const int& ra4 = a;
//    return 0;
//}
 

//int main()
//{
//    // 右值引用只能右值，不能引用左值。
//    int&& r1 = 10;
//
//    // error C2440: “初始化”: 无法从“int”转换为“int &&”
//    // message : 无法将左值绑定到右值引用
//    int a = 10;
//    int&& r2 = a;
//
//    // 右值引用可以引用move以后的左值
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
            cout << "string(char* str)-构造" << endl;
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
            cout << "string(const string& s) -- 拷贝构造" << endl;
            reserve(s._capacity);
            for (auto ch : s)
            {
                push_back(ch);
            }
        }
        // 移动构造
        string(string&& s)
        {
            cout << "string(string&& s) -- 移动构造" << endl;
            swap(s);
        }
        string& operator=(const string& s)
        {
            cout << "string& operator=(const string& s) -- 拷贝赋值" <<
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
        // 移动赋值
        string& operator=(string&& s)
        {
            cout << "string& operator=(string&& s) -- 移动赋值" << endl;
            swap(s);
            return *this;
        }
        ~string()
        {
            cout << "~string() -- 析构" << endl;
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
//    // 拷贝构造
//    lsl::string s2 = s1;
//    // 构造+移动构造，优化后直接构造
//    lsl::string s3 = lsl::string("yyyyy");
//    // 移动构造
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
//    // func1和func2的调用我们可以看到左值引用做参数减少了拷贝，提高效率的使用场景和价值
//    func1(s1);
//    func2(s1);
//
//    s1 += '!';
//    return 0;
//}



//int main()
//{
//    // 左值：可以取地址
//    // 以下的p、b、c、*p、s、s[0]就是常见的左值
//    int* p = new int(0);
//    int b = 1;
//    const int c = b;
//    *p = 10;
//    string s("111111");
//    s[0] = 'x';
//    double x = 1.1, y = 2.2;
//
//    // 左值引用给左值取别名
//    int& r1 = b;
//    int*& r2 = p;
//    int& r3 = *p;
//    string& r4 = s;
//    char& r5 = s[0];
// 
//    // 右值引用给右值取别名
//    int&& rr1 = 10;
//    double&& rr2 = x + y;
//    double&& rr3 = fmin(x, y);
//    string&& rr4 = string("11111");
//
//    // 左值引用不能直接引用右值，但是const左值引用可以引用右值
//    const int& rx1 = 10;
//    const double& rx2 = x + y;
//    const double& rx3 = fmin(x, y);
//    const string& rx4 = string("11111");
//
//    // 右值引用不能直接引用左值，但是右值引用可以引用move(左值)
//    int&& rrx1 = move(b);
//    int*&& rrx2 = move(p);
//    int&& rrx3 = move(*p);
//    string&& rrx4 = move(s);
//    string&& rrx5 = (string&&)s;
//
//    // b、r1、rr1都是变量表达式，都是左值
//    cout << &b << endl;
//    cout << &r1 << endl;
//    cout << &rr1 << endl;
//
//    // 这里要注意的是，rr1的属性是左值，所以不能再被右值引用绑定，除非move一下
//    int& r6 = r1;
//    // int&& rrx6 = rr1;
//    int&& rrx6 = move(rr1);
//    return 0;
//}


//int main()
//{
//    std::string s1 = "Test";
//    // std::string&& r1 = s1; // 错误：不能绑定到左值
//
//    const std::string& r2 = s1 + s1; // OK：到 const 的左值引用延长生存期
//    
//    // r2 += "Test"; // 错误：不能通过到 const 的引用修改
//    std::string&& r3 = s1 + s1; // OK：右值引用延长生存期
//    r3 += "Test"; // OK：能通过到非 const 的引用修改
//    
//    std::cout << r3 << '\n';
//    return 0;
//}


//void f(int& x)
//{
//    std::cout << "左值引用重载 f(" << x << ")\n";
//}
//void f(const int& x)
//{
//    std::cout << "到 const 的左值引用重载 f(" << x << ")\n";
//}
//void f(int&& x)
//{
//    std::cout << "右值引用重载 f(" << x << ")\n";
//}
//
//int main()
//{
//    int i = 1;
//    const int ci = 2;
//    f(i); // 调用 f(int&)
//    f(ci); // 调用 f(const int&)
//
//    f(3); // 调用 f(int&&)，如果没有 f(int&&) 重载则会调用 f(const int&)
//    f(std::move(i)); // 调用 f(int&&)
//
//    // 右值引用变量在用于表达式时是左值(注意)
//    int&& x = 1;
//    f(x); // 调用 f(int& x)
//    f(std::move(x)); // 调用 f(int&& x)
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
//    Print(); // 包里有0个参数
//    Print(1); // 包里有1个参数
//    Print(1, string("xxxxx")); // 包里有2个参数
//    Print(1.1, string("xxxxx"), x); // 包里有3个参数
//    return 0;
//}

//template <class ...Args>
//void Print(Args... args)
//{
//	// 可变参数模板编译时解析
//	// 下面是运行获取和解析，所以不支持这样用
//	cout << sizeof...(args) << endl;
//	for (size_t i = 0; i < sizeof...(args); i++)
//	{
//		cout << args[i] << " ";
//	}
//	cout << endl;
//}

//void ShowList()
//{
//    // 编译器时递归的终止条件，参数包是0个时，直接匹配这个函数
//    cout << endl;
//}
//template <class T, class ...Args>
//void ShowList(T x, Args... args)
//{
//    cout << x << " ";
//    // args是N个参数的参数包
//    // 调用ShowList，参数包的第一个传给x，剩下N-1传给第二个参数包
//    ShowList(args...);
//}
//// 编译时递归推导解析参数
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
//    // 注意GetArg必须返回或者到的对象，这样才能组成参数包给Arguments
//    Arguments(GetArg(args)...);
//}
//// 本质可以理解为编译器编译时，包的扩展模式
//// 将上面的函数模板扩展实例化为下面的函数
//// 是不是很抽象，C++11以后，只能说委员会的大佬设计语法思维跳跃得太厉害
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
//    // 传左值，跟push_back一样，走拷贝构造
//    lsl::string s1("111111111111");
//    lt.emplace_back(s1);
//    cout << "*********************************" << endl;
//
//    // 右值，跟push_back一样，走移动构造
//    lt.emplace_back(move(s1));
//    cout << "*********************************" << endl;
//
//    // 直接把构造string参数包往下传，直接用string参数包构造string
//    // 这里达到的效果是push_back做不到的
//    lt.emplace_back("111111111111");
//    cout << "*********************************" << endl;
//
//    lsl::list<pair<lsl::string, int>> lt1;
//    // 跟push_back一样
//    // 构造pair + 拷贝/移动构造pair到list的节点中data上
//    pair<lsl::string, int> kv("苹果", 1);
//    lt1.emplace_back(kv);
//    cout << "*********************************" << endl;
//
//    // 跟push_back一样
//    lt1.emplace_back(move(kv));
//    cout << "*********************************" << endl;
//
//    ////////////////////////////////////////////////////////////////////
//    // 直接把构造pair参数包往下传，直接用pair参数包构造pair
//    // 这里达到的效果是push_back做不到的
//    lt1.emplace_back("苹果", 1);
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
//    // 函数指针
//    function<void(int&, int&)> f1 = swap_func;
//    f1(x, y);
//    cout << x << " " << y << endl << endl;
//    // 类[匿名对象]
//    function<void(int&, int&)> f2 = Swap();
//    f2(x, y);
//    cout << x << " " << y << endl << endl;
//    // lambda
//    function<void(int&, int&)> f3 = swaplambda;
//    f3(x, y);
//    cout << x << " " << y << endl << endl;
//
//    map<std::string, std::function<void(int&, int&)>> CmdOp{
//        {"函数指针", swap_func},
//        {"仿函数", Swap()},
//        {"lambda", swaplambda},
//
//        //{"函数指针", f1},
//        //{"仿函数", f2},
//        //{"lambda", f3},
//    };
//
//    // 使用
//    CmdOp["函数指针"](x, y);
//    cout << x << " " << y << endl << endl;
//
//    CmdOp["仿函数"](x, y);
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
//    // 调整参数顺序
//    function<int(int, int)> f2 = bind(Sub, placeholders::_2, placeholders::_1);
//    cout << f2(10, 5) << endl;
//
//    // 调整参数个数，有些参数可以bind时写死
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
//        // 当b == 0时抛出异常
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
//	cout << __FUNCTION__ << ":" << __LINE__ << "行执行" << endl;
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



// 一般大型项目程序才会使用异常，下面我们模拟设计一个服务的几个模块
// 每个模块的继承都是Exception的派生类，每个模块可以添加自己的数据
// 最后捕获时，我们捕获基类就可以
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
        throw SqlException("权限不足", 100, "select * from name = '张三'");
    }
    else
    {
        cout << "SQLMgr 调用成功" << endl;
    }
}

void CacheMgr()
{
    if (rand() % 5 == 0)
    {
        throw CacheException("权限不足", 100);
    }
    else if (rand() % 6 == 0)
    {
        throw CacheException("数据不存在", 101);
    }
    else
    {
        cout << "CacheMgr 调用成功" << endl;
    }
    SQLMgr();
}

void HttpServer()
{
    if (rand() % 3 == 0)
    {
        throw HttpException("请求资源不存在", 100, "get");
    }
    else if (rand() % 4 == 0)
    {
        throw HttpException("权限不足", 101, "post");
    }
    else
    {
        cout << "HttpServer调用成功" << endl;
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
//		catch (const Exception& e) // 这里捕获基类，基类对象和派生类对象都可以被捕获
//		{
//			cout << e.what() << endl;
//		}
//		catch (...)
//		{
//			cout << "未知异常" << endl;
//		}
//	}
//	return 0;
//}

void _SeedMsg(const string& s)
{
	if (rand() % 3 == 0)
	{
		throw HttpException("网络不稳定，发送失败", 102, "put");
	}
	else if (rand() % 7 == 0)
	{
		throw HttpException("你已经不是对象的好友，发送失败", 103, "put");
	}
	else
	{
		cout << "发送成功" << endl;
	}
}

void SendMsg(const string& s)
{
	// 发送消息失败，则再重试3次
	for (size_t i = 0; i < 4; i++)
	{
		try
		{
			_SeedMsg(s);
			break;
		}
		catch (const Exception& e)
		{
			// 捕获异常，if中是102号错误，网络不稳定，则重新发送
			// 捕获异常，else中不是102号错误，则将异常重新抛出
			if (e.getid() == 102)
			{
				// 重试三次以后否失败了，则说明网络太差了，重新抛出异常
				if (i == 3)
					throw;

				cout << "开始第" << i + 1 << "次重试" << endl;
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
//    // 当b == 0时抛出异常
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
//                // 析构
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
//    // 拷贝时，管理权限转移，被拷贝对象ap1悬空
//    auto_ptr<Date> ap2(ap1);
//    // 空指针访问，ap1对象已经悬空
//    //ap1->_year++;
//
//
//    unique_ptr<Date> up1(new Date);
//    // 不支持拷贝
//    //unique_ptr<Date> up2(up1);
//    // 支持移动，但是移动后up1也悬空，所以使用移动要谨慎
//    unique_ptr<Date> up3(move(up1));
//    
//    shared_ptr<Date> sp1(new Date);
//    // 支持拷贝
//    shared_ptr<Date> sp2(sp1);
//    shared_ptr<Date> sp3(sp2);
//    cout << sp1.use_count() << endl;
//    sp1->_year++;
//    cout << sp1->_year << endl;
//    cout << sp2->_year << endl;
//    cout << sp3->_year << endl;
//    // 支持移动，但是移动后sp1也悬空，所以使用移动要谨慎
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
//    // 因为new[]经常使用，所以unique_ptr和shared_ptr
//    // 实现了一个特化版本，这个特化版本析构时用的delete[]
//	//shared_ptr<Date[]> sp1(new Date[10]);
//    //unique_ptr<Date[]> up1(new Date[10]);
//
//    // 定制删除器  函数指针/仿函数/lambda
//    lsl::shared_ptr<Date> sp2(new Date[5], DeleteArray<Date>());
//    lsl::shared_ptr<Date> sp3(new Date[5], DeleteArrayFunc<Date>);
//
//	auto delArrOBJ = [](Date* ptr) {delete[] ptr; };
//    lsl::shared_ptr<Date> sp4(new Date[5], delArrOBJ);
//	// 实现其他资源管理的删除器
//    lsl::shared_ptr<FILE> sp5(fopen("Test.cpp", "r"), Fclose());
//    lsl::shared_ptr<FILE> sp6(fopen("Test.cpp", "r"), [](FILE* ptr) {
//		    cout << "fclose:" << ptr << endl;
//		    fclose(ptr);
//		});
//
//    // 不传也可以
//    lsl::shared_ptr<Date> sp7(new Date);
//
//	unique_ptr<Date, DeleteArray<Date>> up2(new Date[5]);
//	unique_ptr<Date, void(*)(Date*)> up3(new Date[5], DeleteArrayFunc<Date>);
//	// decltype对象的类型，decltype是推导对象的类型
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
//	//if (sp1) // 等价
//		cout << "sp1 is not nullptr" << endl;
//
//	if (!sp4)
//		cout << "sp1 is nullptr" << endl;
//
//	// 报错，不能类型转换
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
//    // sp1和sp2都指向了其他资源，则weak_ptr就过期了
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
                release(); // 释放s1
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
