#include"Stack.h"

//int main()
//{
//	int ret = Add(1, 2);
//
//	return 0;
//}

//typedef std::map<std::string, std::string> Map;
//
//
//int main()
//{
//	std::map<std::string, std::string> m{ { "apple", "ƻ��" }, { "orange","����" },{"pear","��"} };
//	Map::iterator it = m.begin();
//
//	while (it != m.end())
//	{
//		//....
//	}
//	return 0;
//}

//typedef char* pstring;
//
//int main()
//{
//	const pstring p1; 
//	const pstring* p2; 
//	return 0;
//}




//int TestAuto()
//{
//	return 10;
//}
//int main()
//{
//	int a = 10;
//	auto b = a; // ����
//	auto c = 'a'; // �ַ�����
//	auto f = &a; //ָ������
//	auto d = TestAuto(); // ����ָ������
//	// auto e;  error ����Ҫ������г�ʼ��
//
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//	cout << typeid(f).name() << endl;
//	return 0;
//}


//#include <string>
//#include <map>
//int main()
//{
//	std::map<std::string, std::string> m{ { "apple", "ƻ��" }, { "orange","����" },{"pear","��"} };
//	auto it = m.begin();
//
//	//cout << typeid(it).name() << endl;
//	while (it != m.end())
//	{
//		//....
//	}
//	return 0;
//}

//
//void TestAuto()
//{
//	auto a = 1, b = 2;
//	auto c = 3, d = 4.0; 
//}
//
//int main()
//{
//	int x = 10;
//	auto a = &x;
//	auto* b = &x;
//	auto& c = x;
//
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	
//	*a = 20;
//	*b = 30;
//	c = 40;
//	return 0;
//}


//void main()
//{
//	int array[] = { 1, 2, 3, 4, 5 };
//
//	for (auto& e : array)
//		e *= 2;
//
//	for (auto e : array)
//		cout << e << " ";
//}

//#include<stddef.h>
//
//void f(int)
//{
//	cout << "f(int)" << endl;
//}
//void f(int*)
//{
//	cout << "f(int*)" << endl;
//}
//int main()
//{
//	f(0);
//	f(NULL);
//	f((int*)NULL);
//	f(nullptr);
//	return 0;
//}


//typedef int DataType;
//
//struct Stack
//{
//	// ��Ա����
//	void Init(size_t capacity = 4)
//	{
//		_array = (DataType*)malloc(sizeof(DataType) * capacity);
//		if (nullptr == _array)
//		{
//			perror("malloc����ռ�ʧ��");
//			return;
//		}
//		_capacity = capacity;
//		_size = 0;
//	}
//	void Push(const DataType& data)
//	{
//		// ����
//		_array[_size] = data;
//		++_size;
//	}
//	DataType Top()
//	{
//		return _array[_size - 1];
//	}
//	void Destroy()
//	{
//		if (_array)
//		{
//			free(_array);
//			_array = nullptr;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//	// ��Ա����
//	DataType* _array;
//	size_t _capacity;
//	size_t _size;
//};
//
//int main()
//{
//	Stack s;
//	s.Init(10);
//	s.Push(1);
//	s.Push(2);
//	s.Push(3);
//	cout << s.Top() << endl;
//	s.Destroy();
//	return 0;
//}

//class className
//{
//	// ���壺�ɳ�Ա�����ͳ�Ա�������
//}; // һ��Ҫע�����ķֺ�



//int main()
//{
//	Date d1;
//	class Date d2; // ����Ҳ�ǿ��Ե�
//	d1.Init(2024, 1, 26);
//	//d2._day++;
//	d1.print();
//
//	return 0;
//}



//int main()
//{
//	Stack s;
//	s.Init(10);
//	s.Push(1);
//	s.Push(2);
//	s.Push(3);
//	cout << s.Top() << endl;
//	s.Destroy();
//
//	Stack::
//
//	return 0;
//}
//class Person
//{
//public:
//	void PrintPersonInfo();
////private:
//	char _name[20];
//	char _gender[3];
//	int _age;
//};
//
//// ������Ҫָ��PrintPersonInfo������Person�������
//void Person::PrintPersonInfo()
//{
//	cout << _name << " " << _gender << " " << _age << endl;
//}
//
//int main()
//{
//	Person d1; // ���壻����ʵ����
//
//	//d1._age++; // �����Ϳ���
//
//	//Person._age = 100;
//	return 0;
//}

//class Date
//{
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1;
//	cout << sizeof(d1) << endl;
//}
