#include<iostream>
using namespace std;

//class Person {
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//};
//
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "买票-半价" << endl; }
//};
//
//void Func(Person& p)
//{
//	p.BuyTicket();
//}
//
//int main()
//{
//	Person ps;
//	Student st;
//	Func(ps);
//	Func(st);
//	return 0;
//}

//
//class A {};
//class B : public A {};
//
//class Person {
//public:
//	virtual A* f() { return new A; }
//};
//
//class Student : public Person {
//public:
//	virtual B* f() { return new B; }
//};

//class Person {
//public:
//	virtual ~Person() { cout << "~Person()" << endl; }
//};
//
//class Student : public Person {
//public:
//	virtual ~Student() { cout << "~Student()" << endl; }
//};
//
//int main()
//{
//	Person* p1 = new Person;
//	Person* p2 = new Student;
//
//	delete p1;
//	delete p2;
//	return 0;
//}
//class Car
//{
//public:
//	virtual void Drive() final {}
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive() { cout << "Benz-舒适" << endl; }
//};

//class Car {
//public:
//	 void Drive() {}
//};
//class Benz :public Car {
//public:
//	virtual void Drive() override { cout << "Benz-舒适" << endl; }
//};

////抽象类（接口类）
//class Car
//{
//public:
//	//纯虚函数
//	virtual void Drive() = 0;
//};
//int main()
//{
//	Car c; //抽象类不能实例化出对象，error
//	return 0;
//}

////抽象类（接口类）
//class Car
//{
//public:
//	//纯虚函数
//	virtual void Drive() = 0;
//};
////派生类
//class Benz : public Car
//{
//public:
//	//重写纯虚函数
//	virtual void Drive()
//	{
//		cout << "Benz-舒适" << endl;
//	}
//};
////派生类
//class BMV : public Car
//{
//public:
//	//重写纯虚函数
//	virtual void Drive()
//	{
//		cout << "BMV-操控" << endl;
//	}
//};
//int main()
//{
//	//派生类重写了纯虚函数，可以实例化出对象
//	Benz b1;
//	BMV b2;
//	//不同对象用基类指针调用Drive函数，完成不同的行为
//	Car* p1 = &b1;
//	Car* p2 = &b2;
//	p1->Drive();  //Benz-舒适
//	p2->Drive();  //BMV-操控
//	return 0;
//}

//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Base::Func1()" << endl;
//	}
//	virtual void Func2()
//	{
//		cout << "Base::Func2()" << endl;
//	}
//	void Func3()
//	{
//		cout << "Base::Func3()" << endl;
//	}
//private:
//	int _b = 1;
//};
//
//class Derive : public Base
//{
//public:
//	virtual void Func1()
//	{
//			cout << "Derive::Func1()" << endl;
//	}
//private:
//	int _d = 2;
//};
//
//int main()
//{
//	Base b;
//	Derive d;
//
//	return 0;
//}

//
//class Person {
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//};
//
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "买票-半价" << endl; }
//};
//
//void Func(Person p)
//{
//	p.BuyTicket();
//}
//
//int main()
//{
//	Person Mike;
//	Func(Mike);
//	Student Johnson;
//	Func(Johnson);
//	return 0;
//}

//class Base {
//public:
//	virtual void func1() { cout << "Base::func1" << endl; }
//	virtual void func2() { cout << "Base::func2" << endl; }
//private:
//	int a;
//};
//
//void func()
//{
//	cout << "void func()" << endl;
//}
//
//int main()
//{
//	Base b1;
//	Base b2;
//
//	static int a = 0;
//	int b = 0;
//	int* p1 = new int;
//	const char* p2 = "hello world";
//
//	printf("静态区:%p\n", &a);
//	printf("栈:%p\n", &b);
//	printf("堆:%p\n", p1);
//	printf("代码段:%p\n", p2);
//	printf("虚表:%p\n", *((int*)&b1));
//	printf("虚函数地址:%p\n", &Base::func1);
//	printf("普通函数地址:%p\n", func);
//
//	return 0;
//}


//class Base {
//public:
//	virtual void func1() { cout << "Base::func1" << endl; }
//	virtual void func2() { cout << "Base::func2" << endl; }
//private:
//	int a;
//};
//class Derive :public Base {
//public:
//	virtual void func1() { cout << "Derive::func1" << endl; }
//	virtual void func3() { cout << "Derive::func3" << endl; }
//	virtual void func4() { cout << "Derive::func4" << endl; }
//private:
//	int b;
//};
//
//// 打印虚表
//typedef void(*VFPTR) ();
//void PrintVTable(VFPTR vTable[])
//{
//	// 依次取虚表中的虚函数指针打印并调用。调用就可以看出存的是哪个函数
//	cout << " 虚表地址>" << vTable << endl;
//	for (int i = 0; vTable[i] != nullptr; ++i)
//	{
//		printf(" 第%d个虚函数地址 :0X%x,->", i, vTable[i]);
//		VFPTR f = vTable[i];
//		f();
//	}
//	cout << endl;
//}
//
//int main()
//{
//	Base b;
//	Derive d;
//
//	VFPTR* vTableb = (VFPTR*)(*(int*)&b);
//	PrintVTable(vTableb);
//	VFPTR* vTabled = (VFPTR*)(*(int*)&d);
//	PrintVTable(vTabled);
//
//	return 0;
//}


class Base1 {
public:
	virtual void func1() { cout << "Base1::func1" << endl; }
	virtual void func2() { cout << "Base1::func2" << endl; }
private:
	int b1;
};
class Base2 {
public:
	virtual void func1() { cout << "Base2::func1" << endl; }
	virtual void func2() { cout << "Base2::func2" << endl; }
private:
	int b2;
};

class Derive : public Base1, public Base2 {
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
private:
	int d1;
};

typedef void(*VFPTR) ();

void PrintVTable(VFPTR vTable[])
{
	cout << " 虚表地址>" << vTable << endl;
	for (int i = 0; vTable[i] != nullptr; ++i)
	{
		printf(" 第%d个虚函数地址 :0X%x,->", i, vTable[i]);
		VFPTR f = vTable[i];
		f();
	}
	cout << endl;
}

int main()
{
	Derive d;
	VFPTR* vTableb1 = (VFPTR*)(*(int*)&d);
	PrintVTable(vTableb1);
	VFPTR* vTableb2 = (VFPTR*)(*(int*)((char*)&d + sizeof(Base1)));
	
	PrintVTable(vTableb2);
	// 这样也可以
	Base2* ptr = &d;
	PrintVTable(((VFPTR*)*(int*)ptr));
	Derive d;
	Base1* p1 = &d;
	p1->func1();

	Base2* p2 = &d;
	p2->func1();

	return 0;
}






