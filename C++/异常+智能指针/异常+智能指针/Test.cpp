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
	if (rand() % 3 == 0){
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

double Division(int a, int b)
{
	// ��b == 0ʱ�׳��쳣
	if (b == 0)
	{
		throw "Division by zero condition!";
	}
	return (double)a / (double)b;
}

void Func()
{
	// ������Կ������������0�����׳��쳣�����������arrayû�еõ��ͷš�
	// �������ﲶ���쳣�󲢲������쳣���쳣���ǽ������洦�����ﲶ������
	// �����׳�ȥ��
	int* array1 = new int[10];
	int* array2 = new int[20];


	int len, time;
	cin >> len >> time;
	cout << Division(len, time) << endl;

	//// �쳣��ȫ����
	//try {
	//	int len, time;
	//	cin >> len >> time;
	//	cout << Division(len, time) << endl;
	//}
	//catch (...)
	//{
	//	cout << "delete []" << array1 << endl;
	//	delete[] array1;

	//	cout << "delete []" << array2 << endl;
	//	delete[] array2;

	//	throw;  // ����ʲô��ʲô
	//}


	/*catch (const char* errmsg) // ��������д
	{
		cout << "delete []" << array << endl;
		delete[] array;

		throw errmsg;
	}*/

	cout << "delete []" << array1 << endl;
	delete[] array1;

	cout << "delete []" << array2 << endl;
	delete[] array2;
}

int main()
{
	try
	{
		Func();
	}
	catch (const char* errmsg)
	{
		cout << errmsg << endl;
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}

	return 0;
}