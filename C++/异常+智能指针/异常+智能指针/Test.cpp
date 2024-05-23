#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

using namespace std;

//double Division(int a, int b)
//{
//	// 当b == 0时抛出异常
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
//		string s("除0错误");
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
//		catch (...)  // 走到这里说明有人没有按规范(约定)抛异常
//		{
//			cout << "未知异常" << endl;
//		}
//	}
//
//	return 0;
//}


//// 这里表示这个函数会抛出A/B/C/D中的某种类型的异常
//void fun() throw(A，B，C，D);
//// 这里表示这个函数只会抛出bad_alloc的异常
//void* operator new (std::size_t size) throw (std::bad_alloc);
//// 这里表示这个函数不会抛出异常
//void* operator delete (std::size_t size, void* ptr) throw();
//// C++11 中新增的noexcept，表示不会抛异常
//thread() noexcept;
//thread(thread&& x) noexcept;

#include <windows.h>

// 服务器开发中通常使用的异常继承体系
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
	string _errmsg; // 错误描述
	int _id;		// 错误编号
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
		throw SqlException("权限不足", 100, "select * from name = '张三'");
	}

	// throw "xxxxxx";
}

void CacheMgr()
{
	srand((unsigned int)time(0));
	if (rand() % 5 == 0)
	{
		throw CacheException("权限不足", 100);
	}
	else if (rand() % 6 == 0)
	{
		throw CacheException("数据不存在", 101);
	}

	SQLMgr();
}

void HttpServer()
{
	srand((unsigned int)time(0));
	if (rand() % 3 == 0) {
		throw HttpServerException("请求资源不存在", 100, "get");
	}
	else if (rand() % 4 == 0)
	{
		throw HttpServerException("权限不足", 101, "post");
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
//		catch (const Exception& e) // 这里捕获父类对象就可以
//		{
//			// 多态
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
//	// 当b == 0时抛出异常
//	if (b == 0)
//	{
//		throw "Division by zero condition!";
//	}
//	return (double)a / (double)b;
//}
//
//void Func()
//{
//	// 这里可以看到如果发生除0错误抛出异常，另外下面的array没有得到释放。
//	// 所以这里捕获异常后并不处理异常，异常还是交给外面处理，这里捕获了再
//	// 重新抛出去。
//	int* array1 = new int[10];
//	int* array2 = new int[20];
//
//
//	int len, time;
//	cin >> len >> time;
//	cout << Division(len, time) << endl;
//
//	//// 异常安全问题
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
//	//	throw;  // 捕到什么抛什么
//	//}
//
//
//	/*catch (const char* errmsg) // 或者这样写
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

// 使用RAII思想设计的SmartPtr类
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
//	cout << Division(len, time) << endl; // 除零异常
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
		// 1、只声明不实现
		// 2、限定为私有
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

		// 删除器
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
			// 防止自己给自己赋值
			if (_ptr != sp._ptr)
			{
				// 先释放原来的
				release();

				_pcount = sp._pcount;
				_ptr = sp._ptr;

				// ++现在的
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

	// 管理权转移，导致对象悬空
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

	// 自己给自己赋值
	sp3 = sp3;
	cout << *sp3 << endl;
	lsl::shared_ptr<string> sp2(sp1);
	sp1 = sp2; // 自己给自己赋值
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

	cout << "循环引用前：" << endl;
	cout << n1.use_count() << endl;
	cout << n2.use_count() << endl;

	// 循环引用
	n1->_next = n2;
	n2->_prev = n1;

	cout << "循环引用后：" << endl;
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
	// 定制删除器
	lsl::shared_ptr<ListNode> sp1(new ListNode[10], DelArray<ListNode>()); // 调用的仿函数
	lsl::shared_ptr<ListNode> sp2(new ListNode[10], [](ListNode* ptr) { delete[] ptr; }); // 使用lambda
	lsl::shared_ptr<FILE> sp3(fopen("Test.cpp", "r"), [](FILE* ptr) { fclose(ptr); });    // 使用lambda

	lsl::shared_ptr<ListNode> sp4(new ListNode); // 使用缺省参数
}

int main()
{
	// std::shared_ptr<ListNode> sp1;

	//test_shared_ptr2();

	test_shared_ptr3();
	return 0;
}