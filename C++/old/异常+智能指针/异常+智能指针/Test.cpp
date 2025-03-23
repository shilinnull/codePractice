#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

using namespace std;

//double Division(int a, int b)
//{
//	// ��b == 0ʱ�׳��쳣
//	if (b == 0)
//		throw "Division by zero condition!";
//	else
//		return ((double)a / (double)b);
//}
//void Func()
//{
//	int len, time;
//	cin >> len >> time;
//	cout << Division(len, time) << endl;
//}
//int main()
//{
//	try
//	{
//		Func();
//	}
//	catch (const char* errmsg)
//	{
//		cout << errmsg << endl;
//	}
//	catch (...)
//	{
//		cout << "unkown exception" << endl;
//	}
//
//}

//
//class A
//{
//public:
//	A()
//	{
//		cout << "A()" << endl;
//	}
//
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//};
//
//
//double Division(int len, int time)
//{
//	if (time == 0)
//	{
//		string s("��0����");
//		throw s;
//	}
//	else
//	{
//		return (double)len / (double)time;
//	}
//}
//
//void f1()
//{
//	throw 1;
//}
//
//void Func()
//{
//	A aa;
//
//	try {
//		int len, time;
//		cin >> len >> time;
//		cout << Division(len, time) << endl;
//	}
//	catch (const char s)
//	{
//		cout << s << endl;
//	}
//
//	f1();
//	cout << "xxxxxxxxxxxx" << endl;
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
//		catch (const string& s)
//		{
//			cout << s << endl;
//		}
//		catch (...)  // �ߵ�����˵������û�а��淶(Լ��)���쳣
//		{
//			cout << "δ֪�쳣" << endl;
//		}
//	}
//
//	return 0;
//}


//// �����ʾ����������׳�A/B/C/D�е�ĳ�����͵��쳣
//void fun() throw(A��B��C��D);
//// �����ʾ�������ֻ���׳�bad_alloc���쳣
//void* operator new (std::size_t size) throw (std::bad_alloc);
//// �����ʾ������������׳��쳣
//void* operator delete (std::size_t size, void* ptr) throw();
//// C++11 ��������noexcept����ʾ�������쳣
//thread() noexcept;
//thread(thread&& x) noexcept;

#include <windows.h>

// ������������ͨ��ʹ�õ��쳣�̳���ϵ
class Exception
{
public:
	Exception(const string& errmsg, int id)
		:_errmsg(errmsg)
		, _id(id)
	{}

	virtual string what() const
	{
		return _errmsg;
	}
protected:
	string _errmsg; // ��������
	int _id;		// ������
};

class SqlException : public Exception
{
public:
	SqlException(const string& errmsg, int id, const string& sql)
		:Exception(errmsg, id)
		, _sql(sql)
	{}

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
	{}

	virtual string what() const
	{
		string str = "CacheException:";
		str += _errmsg;
		return str;
	}
};

class HttpServerException : public Exception
{
public:
	HttpServerException(const string& errmsg, int id, const string& type)
		:Exception(errmsg, id)
		, _type(type)
	{}

	virtual string what() const
	{
		string str = "HttpServerException:";
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
	srand((unsigned int)time(0));
	if (rand() % 7 == 0)
	{
		throw SqlException("Ȩ�޲���", 100, "select * from name = '����'");
	}

	// throw "xxxxxx";
}

void CacheMgr()
{
	srand((unsigned int)time(0));
	if (rand() % 5 == 0)
	{
		throw CacheException("Ȩ�޲���", 100);
	}
	else if (rand() % 6 == 0)
	{
		throw CacheException("���ݲ�����", 101);
	}

	SQLMgr();
}

void HttpServer()
{
	srand((unsigned int)time(0));
	if (rand() % 3 == 0) {
		throw HttpServerException("������Դ������", 100, "get");
	}
	else if (rand() % 4 == 0)
	{
		throw HttpServerException("Ȩ�޲���", 101, "post");
	}

	CacheMgr();
}

//int main()
//{
//	while (1)
//	{
//		Sleep(500);
//
//		try {
//			HttpServer();
//		}
//		catch (const Exception& e) // ���ﲶ�������Ϳ���
//		{
//			// ��̬
//			cout << e.what() << endl;
//		}
//		catch (...)
//		{
//			cout << "Unkown Exception" << endl;
//		}
//	}
//
//	return 0;
//}
//
//double Division(int a, int b)
//{
//	// ��b == 0ʱ�׳��쳣
//	if (b == 0)
//	{
//		throw "Division by zero condition!";
//	}
//	return (double)a / (double)b;
//}
//
//void Func()
//{
//	// ������Կ������������0�����׳��쳣�����������arrayû�еõ��ͷš�
//	// �������ﲶ���쳣�󲢲������쳣���쳣���ǽ������洦�����ﲶ������
//	// �����׳�ȥ��
//	int* array1 = new int[10];
//	int* array2 = new int[20];
//
//
//	int len, time;
//	cin >> len >> time;
//	cout << Division(len, time) << endl;
//
//	//// �쳣��ȫ����
//	//try {
//	//	int len, time;
//	//	cin >> len >> time;
//	//	cout << Division(len, time) << endl;
//	//}
//	//catch (...)
//	//{
//	//	cout << "delete []" << array1 << endl;
//	//	delete[] array1;
//
//	//	cout << "delete []" << array2 << endl;
//	//	delete[] array2;
//
//	//	throw;  // ����ʲô��ʲô
//	//}
//
//
//	/*catch (const char* errmsg) // ��������д
//	{
//		cout << "delete []" << array << endl;
//		delete[] array;
//
//		throw errmsg;
//	}*/
//
//	cout << "delete []" << array1 << endl;
//	delete[] array1;
//
//	cout << "delete []" << array2 << endl;
//	delete[] array2;
//}
//
//int main()
//{
//	try
//	{
//		Func();
//	}
//	catch (const char* errmsg)
//	{
//		cout << errmsg << endl;
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}

// ʹ��RAII˼����Ƶ�SmartPtr��
//template<class T>
//class SmartPtr
//{
//public:
//	SmartPtr(T* ptr)
//		:_ptr(ptr)
//	{}
//
//	~SmartPtr()
//	{
//		delete[] ptr;
//		cout << "delete[]" << _ptr << endl;
//	}
//
//private:
//	T* _ptr;
//};
//
//double Division(int a, int b)
//{
//	if (b == 0)
//	{
//		throw invalid_argument("Division by zero condition!");
//	}
//	return (double)a / (double)b;
//}
//
//void Func()
//{
//	// RAII
//	SmartPtr<int> sp1(new int[10]);
//	SmartPtr<double> sp1(new double[10]);
//
//	int len, time;
//	cin >> len >> time;
//	cout << Division(len, time) << endl; // �����쳣
//}


//int mian()
//{
//	try
//	{
//		Func();
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}

template<class T>
class SmartPtr
{
public:
	// RAII
	SmartPtr(T* ptr)
		:_ptr(ptr)
	{}

	~SmartPtr()
	{
		cout << "~SmartPtr()->" << _ptr << endl;

		delete _ptr;
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}
private:
	T* _ptr;
};


#include <functional>
namespace lsl
{
	template<class T>
	class auto_ptr
	{
	public:
		auto_ptr(T* ptr)
			:_ptr(ptr)
		{}

		~auto_ptr()
		{
			if (_ptr)
			{
				cout << "~auto_ptr()" << endl;
				delete _ptr;
				_ptr = nullptr;
			}
		}
		auto_ptr(auto_ptr<T>& ap)
			:_ptr(ap._ptr)
		{
			_ptr = nullptr;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

	private:
		T* _ptr;
	};


	template<class T>
	class unique_ptr
	{
	public:
		unique_ptr()
			:_ptr(nullptr)
		{}

		~unique_ptr()
		{
			if (_ptr)
			{
				cout << "~unique_ptr()" << endl;
				delete _ptr;
				_ptr = nullptr;
			}
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		// C++11
		unique_ptr(const unique_ptr<T>& up) = delete;
		unique_ptr<T>& operator=(const unique_ptr<T>& up) = delete;

	private:
		// C++98
		// 1��ֻ������ʵ��
		// 2���޶�Ϊ˽��
		//unique_ptr(const unique_ptr<T>& up);
		//unique_ptr<T>& operator=(const unique_ptr<T>& up);
	private:
		T* _ptr;
	};


	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			, _pcount(new int(1))
		{}

		// ɾ����
		template<class D>
		shared_ptr(T* ptr, D del)
			: _ptr(ptr)
			, _pcount(new int(1))
			, _del(del)
		{}
		void release()
		{
			if (--(*_pcount) == 0)
			{
				// cout << "~shared_ptr()" << endl;
				// delete _ptr;

				_del(_ptr);
				delete _pcount;
				_ptr = nullptr;
			}
		}

		~shared_ptr()
		{
			release();
		}
		// sp1 = sp2
		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			// ��ֹ�Լ����Լ���ֵ
			if (_ptr != sp._ptr)
			{
				// ���ͷ�ԭ����
				release();

				_pcount = sp._pcount;
				_ptr = sp._ptr;

				// ++���ڵ�
				++(*_pcount);
			}
			return *this;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}
		T* get() const
		{
			return _ptr;
		}
		int use_count() const
		{
			return *_pcount;
		}
	private:
		T* _ptr;
		int* _pcount;
		function<void(T*)> _del = [](T* ptr) { delete ptr; };
	};

	template<class T>
	class weak_ptr
	{
	public:
		weak_ptr()
			:_ptr(nullptr)
		{}

		weak_ptr(const shared_ptr<T>& we)
			:_ptr(we.get())
		{}

		weak_ptr<T>& operator=(const shared_ptr<T>& we)
		{
			_ptr = we.get();
			return *this;
		}


		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

	private:
		T* _ptr;
	};
}


void TestSmartPtr1()
{
	SmartPtr<int> sp1(new int);
	*sp1 = 1;

	SmartPtr<pair<string, int>> sp2(new pair<string, int>("xxxx", 1));
	sp2->first += 'y';
	sp2->second += 1;
	sp2.operator->()->second += 1;
	cout << sp2->first << endl;
	cout << sp2->second << endl;
}

void test_auto_ptr1()
{
	lsl::auto_ptr<int> ap1(new int);
	lsl::auto_ptr<int> ap2 = ap1;

	// ����Ȩת�ƣ����¶�������
	(*ap1)++;
	(*ap2)++;
}

void test_unique_ptr1()
{
	std::unique_ptr<int> up1(new int(1));
	//std::unique_ptr<int> up2 = up1;

	std::unique_ptr<int> up3(new int(2));
	//up1 = up3;
}



void test_shared_ptr1()
{
	lsl::shared_ptr<string> sp1(new string("xxxxxxxxxxxxxxxxxx"));

	lsl::shared_ptr<string> sp3(new string("yyyyyyyyy"));

	sp1 = sp3;
	sp3 = sp1;

	// �Լ����Լ���ֵ
	sp3 = sp3;
	cout << *sp3 << endl;
	lsl::shared_ptr<string> sp2(sp1);
	sp1 = sp2; // �Լ����Լ���ֵ
}



struct ListNode
{
	lsl::weak_ptr<ListNode> _next;
	lsl::weak_ptr<ListNode> _prev;
	int val;

	~ListNode()
	{
		cout << "~ListNode()" << endl;
	}
};

void test_shared_ptr2()
{
	lsl::shared_ptr<ListNode> n1 = new ListNode;
	lsl::shared_ptr<ListNode> n2 = new ListNode;

	cout << "ѭ������ǰ��" << endl;
	cout << n1.use_count() << endl;
	cout << n2.use_count() << endl;

	// ѭ������
	n1->_next = n2;
	n2->_prev = n1;

	cout << "ѭ�����ú�" << endl;
	cout << n1.use_count() << endl;
	cout << n2.use_count() << endl;
}

template<class T>
struct DelArray
{
	void operator()(T* ptr)
	{
		delete[] ptr;
	}
};

void test_shared_ptr3()
{
	// ����ɾ����
	lsl::shared_ptr<ListNode> sp1(new ListNode[10], DelArray<ListNode>()); // ���õķº���
	lsl::shared_ptr<ListNode> sp2(new ListNode[10], [](ListNode* ptr) { delete[] ptr; }); // ʹ��lambda
	lsl::shared_ptr<FILE> sp3(fopen("Test.cpp", "r"), [](FILE* ptr) { fclose(ptr); });    // ʹ��lambda

	lsl::shared_ptr<ListNode> sp4(new ListNode); // ʹ��ȱʡ����
}

int main()
{
	// std::shared_ptr<ListNode> sp1;

	//test_shared_ptr2();

	test_shared_ptr3();
	return 0;
}