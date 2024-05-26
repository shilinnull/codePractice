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



//class A
//{
//public:
//	virtual void f() {}
//	int _a = 0;
//};
//
//class B : public A
//{
//
//public:
//	int _b = 1;
//};

//void fun(A* pa)
//{
//	// ����ת����ֱ��ת���ǲ���ȫ��
//	// ���pa��ָ����A���󣬴���Խ������
//	B* ptr = (B*)pa;
//	ptr->_a++;
//	ptr->_b++;
//}

// ���������ʹ��dynamic_cast
//void fun(A* pa)
//{
//	B* ptr = dynamic_cast<B*>(pa);
//	if (ptr)
//	{
//		ptr->_a++;
//		ptr->_b++;
//	}
//	else
//	{
//		cout << "ת��ʧ��" << endl;
//	}
//}

//int main()
//{
//	// ����ת�����򣺸��������ת����������󣬵��Ǹ���ָ������ÿ���ת������ָ�������
//	B b1;
//	A a;
//	B b;
//	fun(&a);
//	fun(&b);
//
//	return 0;
//}

#include<map>

// ����ģʽ
//class A
//{
//public:
//	static A * GetInstance()
//	{
//		return &_inst;
//	}
//
//	void Add(const string & key, const string & value)
//	{
//		_dict[key] = value;
//	}
//
//	void Print()
//	{
//		for (auto& kv : _dict)
//		{
//			cout << kv.first << ":" << kv.second << endl;
//		}
//		cout << endl;
//	}
//private:
//	// ���캯��˽��
//	A()
//	{}
//
//	A(const A & aa) = delete;
//	A& operator=(const A& aa) = delete;
//
//	map<string, string> _dict;
//	int _n = 0;
//
//	static A _inst;
//};
//
//// �ڳ������֮ǰ����ɵ�������ĳ�ʼ��
//A A::_inst;
//
//int main()
//{
//	// �޷�����
//	//A aa1;
//	//A aa2;
//
//	// ���Խ��е���
//	A::GetInstance()->Add("sort", "����");
//	A::GetInstance()->Add("left", "���");
//	A::GetInstance()->Add("right", "�ұ�");
//	A::GetInstance()->Print();
//
//	// ���������ֹʹ��
//	// A copy(*A::GetInstance());
//	// copy.Print();
//
//	// A::GetInstance()->Add("left", "ʣ��");
//	// copy.Print();
//	// A::GetInstance()->Print();
//
//	// ��ֵҲ�޷�ʹ��
//	// *A::GetInstance() = *A::GetInstance();
//
//	return 0;
//}


class B
{
public:
	static B* GetInstance()
	{
		if (_inst == nullptr)
		{
			_inst = new B;
		}

		return _inst;
	}

	void Add(const string& key, const string& value)
	{
		_dict[key] = value;
	}

	void Print()
	{
		for (auto& kv : _dict)
		{
			cout << kv.first << ":" << kv.second << endl;
		}
		cout << endl;
	}

	static void DelInstance()
	{
		if (_inst)
		{
			delete _inst;
			_inst = nullptr;
		}
	}

private:
	B()
	{}

	~B()
	{
		// �־û���Ҫ�������д���ļ�
		cout << "����д���ļ�" << endl;
	}

	B(const B& aa) = delete;
	B& operator=(const B& aa) = delete;

	map<string, string> _dict;
	int _n = 0;
	static B* _inst;

	// ����main�����������Զ�����
	class gc
	{
	public:
		~gc()
		{
			DelInstance();
		}
	};
	static gc _gc;
};

B* B::_inst = nullptr;

// ����main�����������Զ�����
B::gc B::_gc;

//int main()
//{
//	B::GetInstance()->Add("sort", "����");
//	B::GetInstance()->Add("left", "���");
//	B::GetInstance()->Add("right", "�ұ�");
//	B::GetInstance()->Print();
//
//	B::GetInstance()->Add("right", "xxx");
//	B::GetInstance()->Print();
//	
//	// ��ʾ�ĵ����ͷ�
//	B::DelInstance();
//	cout << "xxxxxxxxxxx" << endl;
//
//	return 0;
//}

#include<list>

// ����ת��
// 1����������֮�䣬������Ϳ���ת�� 
// 2�����캯������������ת�����Զ������ͣ��й��캯���Ϳ���֧��
//    �Զ������� <- ��������  �Զ������� <- �Զ�������
// 3��operator type()  �������� <- �Զ�������
class C
{
public:
	C(int x)
	{}
};

class D
{
public:
	D(const C& c)
	{}
};

class E
{
public:
	operator int()
	{
		// ...
		return 0;
	}
};

//int main()
//{
//	// ��ʾ����ת��
//	int* p = nullptr;
//	int i = (int)p;
//
//	// �Զ������� <- ��������
//	C c1 = 11;
//	string s1 = "xxxx";
//
//	// �Զ������� <- �Զ�������
//	D d = c1;
//
//	// �������� <- �Զ�������
//	E e;
//	int x = e;
//	cout << x << endl;
//
//	return 0;
//}
//



class Date
{
	friend ostream& operator << (ostream& out, const Date& d);
	friend istream& operator >> (istream& in, Date& d);
public:
	Date(int year = 1, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}

	operator bool()
	{
		// ����������д�ģ���������_yearΪ0�������
		if (_year == 0)
			return false;
		else
			return true;
	}
private:
	int _year;
	int _month;
	int _day;
};

istream& operator >> (istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	return in;
}

//ofs << winfo._date;
ostream& operator << (ostream& out, const Date& d)
{
	//out << d._year << "��" << d._month << "��" << d._day<<"��";
	//out << d._year << "/" << d._month << "/" << d._day;
	out << d._year << " " << d._month << " " << d._day;

	return out;
}

// C++ IO����ʹ���������+��������صķ�ʽ
// �ܸ��õļ����Զ������ͣ������������ȡ
int main()
{
	// �Զ�ʶ�����͵ı���--��������
	// �������Ϳ���ֱ��ʹ��--��Ϊ������ostream�����Ѿ�ʵ����
	int i = 1;
	double j = 2.2;
	cout << i << endl;
	cout << j << endl;

	// �Զ�����������Ҫ�����Լ�����<< �� >>
	Date d(2022, 4, 10);
	cout << d;
	while (d)
	{
		cin >> d;
		cout << d;
	}

	return 0;
}









