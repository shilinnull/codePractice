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
//	// 1.malloc/calloc/realloc��������ʲô��
//	int* p2 = (int*)calloc(4, sizeof(int));
//	int* p3 = (int*)realloc(p2, sizeof(int) * 10);
//	// ������Ҫfree(p2)��
//	free(p3);
//}




//
//void main()
//{
//	// ��̬����һ��int���͵Ŀռ�
//	int* ptr4 = new int;
//	
//	// ��̬����һ��int���͵Ŀռ䲢��ʼ��Ϊ10
//	int* ptr5 = new int(10);
//	
//	// ��̬����10��int���͵Ŀռ�
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
//	// new/delete �� malloc/free��������� new/delete���ڡ��Զ������͡����˿��ռ仹����ù��캯������������
//	A* p1 = (A*)malloc(sizeof(A));
//	A* p2 = new A(1);
//	free(p1);
//	delete p2;
//	
//	// ���������Ǽ�����һ����
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
//// �����Ĳ����ڱ�λ
//ListNode* CreateList(int n)
//{
//	ListNode head(-1);  // �ڱ�λ
//
//	ListNode* tail = &head;
//	int val;
//	printf("����������%d���ڵ��ֵ��>", n);
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
//	// 1���÷��ϣ�������
//	int* p0 = (int*)malloc(sizeof(int));
//	int* p1 = new int;
//	int* p2 = new int[10]; // new 10��int����
//
//	// 2�����Կ��Ƴ�ʼ��
//	int* p3 = new int(10); // new 1��int����,��ʼ����10
//	int* p4 = new int[10] { 1, 2, 3, 4, 5 };
//
//	// 3���Զ������ͣ����ռ�+���캯��
//	// 4��newʧ�����Ժ����쳣������Ҫ�ֶ����
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
//	// ���쳣
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
//			// ��������ڴ�ʧ���ˣ�������׳�bad_alloc �����쳣
//			static const std::bad_alloc nomem;
//			_RAISE(nomem);
//		}
//	return (p);
//}
///*
//operator delete: �ú���������ͨ��free���ͷſռ��
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
//free��ʵ��
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
//// ��λnew/replacement new
//int main()
//{
//	// p1����ָ���ֻ��������A������ͬ��С��һ�οռ䣬����������һ��������Ϊ���캯��û��ִ��
//	A* p1 = (A*)malloc(sizeof(A));
//	new(p1)A; // ע�⣺���A��Ĺ��캯���в���ʱ���˴���Ҫ����
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
//	// 1.�ڴ������������ͷ�
//	int* p1 = (int*)malloc(sizeof(int));
//	int* p2 = new int;
//	// 2.�쳣��ȫ����
//	int* p3 = new int[10];
//	Func(); // ����Func�������쳣���� delete[] p3δִ�У�p3û���ͷ�.
//	delete[] p3;
//}


//int main()
//{
//	int* p = new int[10];
//	// ���ú�������main����֮��ÿ�γ����˳���ʱ��ͻ����Ƿ�����ڴ�й©
//	_CrtDumpMemoryLeaks();
//	return 0;
//}
//////////////////////////////////////////////////////////
//// �����˳�������������п��Լ�⵽й©�˶����ֽڣ�����û�о����λ��
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
	A* ptr1 = new A;  // operator new + 1�ι���
	A* ptr2 = new A[10]; // operator new[] + 10�ι���

	delete ptr1; // 1������ + operator delete
	delete[] ptr2; // 10������ + operator delete[]

	Stack* pst = new Stack;
	delete pst;


	int* p1 = new int[10];
	return 0;
}