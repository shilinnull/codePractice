#include<iostream>
using namespace std;





//int globalVar = 1;
//static int staticGlobalVar = 1;
//void Test()
//{
//	static int staticVar = 1;
//	int localVar = 1;
//	int num1[10] = { 1, 2, 3, 4 };
//	char char2[] = "abcd";
//	const char* pChar3 = "abcd";
//	int* ptr1 = (int*)malloc(sizeof(int) * 4);
//	int* ptr2 = (int*)calloc(4, sizeof(int));
//	int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4);
//	free(ptr1);
//	free(ptr3);
//}
//
//void Test()
//{
//	int* p1 = (int*)malloc(sizeof(int));
//	free(p1);
//	// 1.malloc/calloc/realloc的区别是什么？
//	int* p2 = (int*)calloc(4, sizeof(int));
//	int* p3 = (int*)realloc(p2, sizeof(int) * 10);
//	// 这里需要free(p2)吗？
//	free(p3);
//}




//
//void main()
//{
//	// 动态申请一个int类型的空间
//	int* ptr4 = new int;
//	
//	// 动态申请一个int类型的空间并初始化为10
//	int* ptr5 = new int(10);
//	
//	// 动态申请10个int类型的空间
//	int* ptr6 = new int[3];
//	
//	delete ptr4;
//	delete ptr5;
//	delete[] ptr6;
//}
//
//
//int main()
//{
//	int* p1 = new int[10];
//	int* p2 = new int[10] {1, 2, 3, 4, 5, 6, 7};
//
//
//
//
//	delete[] p1;
//	delete[] p2;
//
//	return 0;
//}


//class A
//{
//public:
//	A(int a = 0)
//		: _a(a)
//	{
//		cout << "A():" << this << endl;
//	}
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	// new/delete 和 malloc/free最大区别是 new/delete对于【自定义类型】除了开空间还会调用构造函数和析构函数
//	A* p1 = (A*)malloc(sizeof(A));
//	A* p2 = new A(1);
//	free(p1);
//	delete p2;
//	
//	// 内置类型是几乎是一样的
//	int* p3 = (int*)malloc(sizeof(int)); // C
//	int* p4 = new int;
//	free(p3);
//	delete p4;
//	
//	A* p5 = (A*)malloc(sizeof(A) * 10);
//	A* p6 = new A[10];
//	free(p5);
//	delete[] p6;
//	
//	
//	return 0;
//}


//
//struct ListNode
//{
//	ListNode* _next;
//	int _val;
//
//	ListNode(int val)
//		:_next(nullptr)
//		, _val(val)
//	{}
//};
//
//
//
//// 创建的不带哨兵位
//ListNode* CreateList(int n)
//{
//	ListNode head(-1);  // 哨兵位
//
//	ListNode* tail = &head;
//	int val;
//	printf("请依次输入%d个节点的值：>", n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> val;
//		tail->_next = new ListNode(val);
//		tail = tail->_next;
//	}
//
//	return head._next;
//}
//
//void func()
//{
//	int n = 1;
//	while (1)
//	{
//		int* p = new int[1024 * 1024 * 100];
//
//		cout << n << "->" << p << endl;
//		++n;
//	}
//}
//
//int main()
//{
//	// 1、用法上，变简洁了
//	int* p0 = (int*)malloc(sizeof(int));
//	int* p1 = new int;
//	int* p2 = new int[10]; // new 10个int对象
//
//	// 2、可以控制初始化
//	int* p3 = new int(10); // new 1个int对象,初始化成10
//	int* p4 = new int[10] { 1, 2, 3, 4, 5 };
//
//	// 3、自定义类型，开空间+构造函数
//	// 4、new失败了以后抛异常，不需要手动检查
//	ListNode* node1 = new ListNode(1);
//	ListNode* node2 = new ListNode(2);
//	ListNode* node3 = new ListNode(3);
//	//...
//	ListNode* list1 = CreateList(5);
//
//	delete p3;
//	delete[] p4;
//	delete p1;
//	delete[] p2;
//
//
//	// 抛异常
//	try
//	{
//		func();
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}


//void* __CRTDECL operator new(size_t size) _THROW1(_STD bad_alloc)
//{
//	// try to allocate size bytes
//	void* p;
//	while ((p = malloc(size)) == 0)
//		if (_callnewh(size) == 0)
//		{
//			// report no memory
//			// 如果申请内存失败了，这里会抛出bad_alloc 类型异常
//			static const std::bad_alloc nomem;
//			_RAISE(nomem);
//		}
//	return (p);
//}
///*
//operator delete: 该函数最终是通过free来释放空间的
//*/
//void operator delete(void* pUserData)
//{
//	_CrtMemBlockHeader* pHead;
//	RTCCALLBACK(_RTC_Free_hook, (pUserData, 0));
//	if (pUserData == NULL)
//		return;
//	_mlock(_HEAP_LOCK); /* block other threads */
//	__TRY
//		/* get a pointer to memory block header */
//		pHead = pHdr(pUserData);
//	/* verify block type */
//	_ASSERTE(_BLOCK_TYPE_IS_VALID(pHead->nBlockUse));
//	_free_dbg(pUserData, pHead->nBlockUse);
//	__FINALLY
//		_munlock(_HEAP_LOCK); /* release other threads */
//	__END_TRY_FINALLY
//		return;
//}
///*
//free的实现
//*/
//#define free(p) _free_dbg(p, _NORMAL_BLOCK)


//class A
//{
//public:
//	A(int a = 0)
//		: _a(a)
//	{
//		cout << "A():" << this << endl;
//	}
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//private:
//	int _a;
//};
//
//// 定位new/replacement new
//int main()
//{
//	// p1现在指向的只不过是与A对象相同大小的一段空间，还不能算是一个对象，因为构造函数没有执行
//	A* p1 = (A*)malloc(sizeof(A));
//	new(p1)A; // 注意：如果A类的构造函数有参数时，此处需要传参
//	p1->~A();
//	free(p1);
//	A* p2 = (A*)operator new(sizeof(A));
//	new(p2)A(10);
//	p2->~A();
//	operator delete(p2);
//	return 0;
//}
//void MemoryLeaks()
//{
//	// 1.内存申请了忘记释放
//	int* p1 = (int*)malloc(sizeof(int));
//	int* p2 = new int;
//	// 2.异常安全问题
//	int* p3 = new int[10];
//	Func(); // 这里Func函数抛异常导致 delete[] p3未执行，p3没被释放.
//	delete[] p3;
//}


//int main()
//{
//	int* p = new int[10];
//	// 将该函数放在main函数之后，每次程序退出的时候就会检测是否存在内存泄漏
//	_CrtDumpMemoryLeaks();
//	return 0;
//}
//////////////////////////////////////////////////////////
//// 程序退出后，在输出窗口中可以检测到泄漏了多少字节，但是没有具体的位置
//Detected memory leaks!
//Dumping objects ->
//{79} normal block at 0x00EC5FB8, 40 bytes long.
//Data: < > CD CD CD CD CD CD CD CD CD CD CD CD CD CD CD CD
//Object dump complete.


class A
{
public:
	A(int a = 0)
		: _a(a)
	{
		cout << "A():" << this << endl;
	}

	~A()
	{
		cout << "~A():" << this << endl;
	}
private:
	int _a;
};

//
//int main()
//{
//	int* p1 = new int[10];
//	delete[] p1;
//
//	A* p2 = new A[10];
//	delete[] p2;
//
//	return 0;
//}


class Stack
{
public:
	Stack()
	{
		_a = (int*)malloc(sizeof(int) * 4);
		_top = 0;
		_capacity = 4;
	}

	~Stack()
	{
		free(_a);
		_top = _capacity = 0;
	}
private:
	int* _a;
	int _top;
	int _capacity;
};

int main()
{
	A* ptr1 = new A;  // operator new + 1次构造
	A* ptr2 = new A[10]; // operator new[] + 10次构造

	delete ptr1; // 1次析构 + operator delete
	delete[] ptr2; // 10次析构 + operator delete[]

	Stack* pst = new Stack;
	delete pst;


	int* p1 = new int[10];
	return 0;
}