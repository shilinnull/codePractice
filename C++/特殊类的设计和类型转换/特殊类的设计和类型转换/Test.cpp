#include<iostream>

//class CopyBan {
//	// ...
//
//public: 
//	CopyBan(const CopyBan&) = delete;
//	CopyBan& operator=(const CopyBan&) = delete;
//	//... 
//};


//class HeapOnly
//{
//public:
//    static HeapOnly* CreateObject()
//    {
//        return new HeapOnly;
//    }
//private:
//    HeapOnly() {}
//    // C++98
//    // 1.ֻ����,��ʵ�֡���Ϊʵ�ֿ��ܻ���鷳�����㱾����Ҫ
//    // 2.������˽��
//    HeapOnly(const HeapOnly&);
//    
//    // C++11    
//    HeapOnly(const HeapOnly&) = delete;
//};

//class StackOnly
//{
//public:
//	static StackOnly CreateObj()
//	{
//		return StackOnly();
//	}
//	// ����operator new���԰�������new ���ÿ�������������������
//	// StackOnly obj = StackOnly::CreateObj();
//	// StackOnly* ptr3 = new StackOnly(obj);
//	void* operator new(size_t size) = delete;
//	void operator delete(void* p) = delete;
//private:
//	StackOnly()
//		:_a(0)
//	{}
//private:
//	int _a;
//};


// C++98�й��캯��˽�л����������е���������Ĺ��캯�������޷��̳�
//class NonInherit
//{
//public:
//	static NonInherit GetInstance()
//	{
//		return NonInherit();
//	}
//private:
//	NonInherit()
//	{}
//};


//class NonInherit final
//{
//public:
//	// ...
//};

//int main()
//{
//	int i = 1;
//	// ��ʽ����ת��
//	double d = i;
//	printf("%d, %.2f\n", i, d);
//	int* p = &i;
//
//	// ��ʾ��ǿ������ת��
//	int address = (int)p; 
//	printf("%x, %d\n", p, address);
//
//	return 0;
//}

using namespace std;
//
//int main()
//{
//	//double d = 3.14;
//	//int a = static_cast<int>(d);
//	//cout << a << endl;
//	//// ����ʹ��static_cast�ᱨ��Ӧ��ʹ��reinterpret_cast
//	//// int *p = static_cast<int*>(a);
//	//int* p = reinterpret_cast<int*>(a);
//
//
//	volatile const int a = 2;
//	int* p = const_cast<int*>(&a);
//	*p = 3;
//
//	cout << a << endl;
//	cout << *p << endl;
//
//	cout << (void*)&a << endl;
//	printf("%p\n", &a);
//	cout << p << endl;
//
//
//	return 0;
//}

//
//class A
//{
//public:
//	virtual void f() {}
//};
//class B : public A
//{};
//void fun(A* pa)
//{
//	// dynamic_cast���ȼ���Ƿ���ת���ɹ����ܳɹ���ת���������򷵻�
//	B* pb1 = static_cast<B*>(pa);
//	B* pb2 = dynamic_cast<B*>(pa);
//	cout << "pb1:" << pb1 << endl;
//	cout << "pb2:" << pb2 << endl;
//}
//int main()
//{
//	A a;
//	B b;
//	fun(&a);
//	fun(&b);
//	return 0;
//}



class A
{
public:
	virtual void f() {}
	int _a = 0;
};

class B : public A
{

public:
	int _b = 1;
};

//void fun(A* pa)
//{
//	// ����ת����ֱ��ת���ǲ���ȫ��
//	// ���pa��ָ����A���󣬴���Խ������
//	B* ptr = (B*)pa;
//	ptr->_a++;
//	ptr->_b++;
//}

// ���������ʹ��dynamic_cast
void fun(A* pa)
{
	B* ptr = dynamic_cast<B*>(pa);
	if (ptr)
	{
		ptr->_a++;
		ptr->_b++;
	}
	else
	{
		cout << "ת��ʧ��" << endl;
	}
}

int main()
{
	// ����ת�����򣺸��������ת����������󣬵��Ǹ���ָ������ÿ���ת������ָ�������
	B b1;
	A a;
	B b;
	fun(&a);
	fun(&b);

	return 0;
}