#include<iostream>
using namespace std;

//class Person {
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
//};
//
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }
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
//	virtual void Drive() { cout << "Benz-����" << endl; }
//};

//class Car {
//public:
//	 void Drive() {}
//};
//class Benz :public Car {
//public:
//	virtual void Drive() override { cout << "Benz-����" << endl; }
//};

////�����ࣨ�ӿ��ࣩ
//class Car
//{
//public:
//	//���麯��
//	virtual void Drive() = 0;
//};
//int main()
//{
//	Car c; //�����಻��ʵ����������error
//	return 0;
//}

////�����ࣨ�ӿ��ࣩ
//class Car
//{
//public:
//	//���麯��
//	virtual void Drive() = 0;
//};
////������
//class Benz : public Car
//{
//public:
//	//��д���麯��
//	virtual void Drive()
//	{
//		cout << "Benz-����" << endl;
//	}
//};
////������
//class BMV : public Car
//{
//public:
//	//��д���麯��
//	virtual void Drive()
//	{
//		cout << "BMV-�ٿ�" << endl;
//	}
//};
//int main()
//{
//	//��������д�˴��麯��������ʵ����������
//	Benz b1;
//	BMV b2;
//	//��ͬ�����û���ָ�����Drive��������ɲ�ͬ����Ϊ
//	Car* p1 = &b1;
//	Car* p2 = &b2;
//	p1->Drive();  //Benz-����
//	p2->Drive();  //BMV-�ٿ�
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
//	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
//};
//
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }
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
//	printf("��̬��:%p\n", &a);
//	printf("ջ:%p\n", &b);
//	printf("��:%p\n", p1);
//	printf("�����:%p\n", p2);
//	printf("���:%p\n", *((int*)&b1));
//	printf("�麯����ַ:%p\n", &Base::func1);
//	printf("��ͨ������ַ:%p\n", func);
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
//// ��ӡ���
//typedef void(*VFPTR) ();
//void PrintVTable(VFPTR vTable[])
//{
//	// ����ȡ����е��麯��ָ���ӡ�����á����þͿ��Կ���������ĸ�����
//	cout << " ����ַ>" << vTable << endl;
//	for (int i = 0; vTable[i] != nullptr; ++i)
//	{
//		printf(" ��%d���麯����ַ :0X%x,->", i, vTable[i]);
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
	cout << " ����ַ>" << vTable << endl;
	for (int i = 0; vTable[i] != nullptr; ++i)
	{
		printf(" ��%d���麯����ַ :0X%x,->", i, vTable[i]);
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
	// ����Ҳ����
	Base2* ptr = &d;
	PrintVTable(((VFPTR*)*(int*)ptr));
	Derive d;
	Base1* p1 = &d;
	p1->func1();

	Base2* p2 = &d;
	p2->func1();

	return 0;
}






