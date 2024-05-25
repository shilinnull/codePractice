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
//    // 1.只声明,不实现。因为实现可能会很麻烦，而你本身不需要
//    // 2.声明成私有
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
//	// 禁掉operator new可以把下面用new 调用拷贝构造申请对象给禁掉
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


// C++98中构造函数私有化，派生类中调不到基类的构造函数。则无法继承
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
//	// 隐式类型转换
//	double d = i;
//	printf("%d, %.2f\n", i, d);
//	int* p = &i;
//
//	// 显示的强制类型转换
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
//	//// 这里使用static_cast会报错，应该使用reinterpret_cast
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
//	// dynamic_cast会先检查是否能转换成功，能成功则转换，不能则返回
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
//	// 向下转换：直接转换是不安全的
//	// 如果pa是指向父类A对象，存在越界问题
//	B* ptr = (B*)pa;
//	ptr->_a++;
//	ptr->_b++;
//}

// 解决方法：使用dynamic_cast
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
//		cout << "转换失败" << endl;
//	}
//}

//int main()
//{
//	// 向下转换规则：父类对象不能转换成子类对象，但是父类指针和引用可以转换子类指针和引用
//	B b1;
//	A a;
//	B b;
//	fun(&a);
//	fun(&b);
//
//	return 0;
//}

#include<map>

// 懒汉模式
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
//	// 构造函数私有
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
//// 在程序入口之前就完成单例对象的初始化
//A A::_inst;
//
//int main()
//{
//	// 无法创建
//	//A aa1;
//	//A aa2;
//
//	// 可以进行调用
//	A::GetInstance()->Add("sort", "排序");
//	A::GetInstance()->Add("left", "左边");
//	A::GetInstance()->Add("right", "右边");
//	A::GetInstance()->Print();
//
//	// 拷贝构造禁止使用
//	// A copy(*A::GetInstance());
//	// copy.Print();
//
//	// A::GetInstance()->Add("left", "剩余");
//	// copy.Print();
//	// A::GetInstance()->Print();
//
//	// 赋值也无法使用
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
		// 持久化：要求把数据写到文件
		cout << "数据写到文件" << endl;
	}

	B(const B& aa) = delete;
	B& operator=(const B& aa) = delete;

	map<string, string> _dict;
	int _n = 0;
	static B* _inst;

	// 期望main函数结束后自动调用
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

// 期望main函数结束后自动调用
B::gc B::_gc;

int main()
{
	B::GetInstance()->Add("sort", "排序");
	B::GetInstance()->Add("left", "左边");
	B::GetInstance()->Add("right", "右边");
	B::GetInstance()->Print();

	B::GetInstance()->Add("right", "xxx");
	B::GetInstance()->Print();
	
	// 显示的调用释放
	B::DelInstance();
	cout << "xxxxxxxxxxx" << endl;

	return 0;
}

















