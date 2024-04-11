#include<iostream>
using namespace std;


//void Swap(int& left, int& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(double& left, double& right)
//{
//	double temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(char& left, char& right)
//{
//	char temp = left;
//	left = right;
//	right = temp;
//}

//
//template<typename T>
//
//void Swap(T& left, T& right)
//{
//	T tmp = left;
//	left = right;
//	right = tmp;
//}


//template<class T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.0, d2 = 20.0;
//	Add(a1, a2);
//	Add(d1, d2);
//
//	int a = 10;
//	double b = 20.0;
//	 
//	// 显式实例化
//	Add<int>(a, b);
//
//
//	return 0;
//}

//// 专门处理int的加法函数
//int Add(int left, int right)
//{
//	return left + right;
//}
//// 通用加法函数
//template<class T>
//T Add(T left, T right)
//{
//	return left + right;
//}
//void Test()
//{
//	Add(1, 2); // 与非函数模板类型完全匹配，不需要函数模板实例化
//	Add(1, 2.0); // 模板函数可以生成更加匹配的版本，编译器根据实参生成更加匹配的Add函数
//}

//template<class T>
//
//class Vector
//{
//public:
//	Vector(size_t capacity = 10)
//		: _pData(new T[capacity])
//		, _size(0)
//		, _capacity(capacity)
//	{}
//	// 使用析构函数演示：在类中声明，在类外定义。
//	~Vector();
//	void PushBack(const T& data)；
//		void PopBack()；
//		// ...
//		size_t Size() { return _size; }
//	T& operator[](size_t pos)
//	{
//		assert(pos < _size);
//		return _pData[pos];
//	}
//private:
//	T* _pData;
//	size_t _size;
//	size_t _capacity;
//};
//// 注意：类模板中函数放在类外进行定义时，需要加模板参数列表
//template <class T>
//Vector<T>::~Vector()
//{
//	if (_pData)
//		delete[] _pData;
//	_size = _capacity = 0;
//}
//
//
//
//// Vector类名，Vector<int>才是类型
//Vector<int> s1;
//Vector<double> s2;
//
//	


//namespace lsl
//{
//	// 定义一个模板类型的静态数组
//	// 非类型模板参数   类型  常量
//	template<class T, size_t N = 10>
//	class array
//	{
//	public:
//		T& operator[](size_t index) { 
//			size(1); // 这里明显是语法错误
//			return _array[index]; 
//		}
//		const T& operator[](size_t index)const { return _array[index]; }
//		size_t size()const { return _size; }
//		bool empty()const { return 0 == _size; }
//	private:
//		T _array[N];
//		size_t _size;
//	};
//}


//
//int main()
//{
//	lsl::array<int> a1;
//	a1[1] = 1;
//
//	return 0;
//}


//
//int main() 
//{
//	// 默认为数组为10
//	lsl::array<int> arr1;
//
//	// 指定大小
//	lsl::array<int, 1000> arr2;
//
//	cout << sizeof(arr1) << endl;
//	cout << sizeof(arr2) << endl;
//
//	return 0;
//}

//#include<array>
//int main()
//{
//	// C++11中的array
//	std::array<int, 10> arr1; // 默认不会初始化
//	// 普通数组
//	int arr2[10];// 默认不会初始化
//
//	// C++11中的array越界都会检查
//	arr1[10];
//	arr1[15] = 1;
//
//	// 普通数组越界写是抽查，读检查不出来
//	arr2[10];
//	arr2[15] = 1; // 不会报错
//
//	return 0;
//}

//#include<vector>
//
//int main()
//{
//	std::vector<int> a1(10, 0); // 可以初始化
//	for (auto &e : a1) {
//		cout << e << " ";
//	}
//
//	// 都会检查
//	a1[10];
//	a1[15] = 1;
//
//	return 0;
//}

class Date
{
public:
	friend ostream& operator<<(ostream& _cout, const Date& d);

	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

	bool operator<(const Date& d)const
	{
		return (_year < d._year) ||
			(_year == d._year && _month < d._month) ||
			(_year == d._year && _month == d._month && _day < d._day);
	}

	bool operator>(const Date& d)const
	{
		return (_year > d._year) ||
			(_year == d._year && _month > d._month) ||
			(_year == d._year && _month == d._month && _day > d._day);
	}
private:
	int _year;
	int _month;
	int _day;
};


ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}
//
//// 函数模板 -- 参数匹配
//template<class T>
//bool Less(T left, T right)
//{
//	return left < right;
//}
//
//// 模板特化
//template<>
//bool Less<Date*>(Date* left, Date* right)
//{
//	return *left < *right;
//}
//
//// 直接使用函数进行
//bool Less(Date* left, Date* right)
//{
//	return *left < *right;
//}

//int main()
//{
//	Date d1(2022, 7, 7);
//	Date d2(2022, 7, 8);
//
//	cout << Less(d1, d2) << endl; // 走的普通模板
//	Date* p1 = &d1;
//	Date* p2 = &d2;
//
//	cout << Less(p1, p2) << endl; // 走的是模板特化
//	return 0;
//}


//int main()
//{
//	cout << Less(1, 2) << endl; // 可以比较，结果正确
//
//	Date d1(2022, 7, 7);
//	Date d2(2022, 7, 8);
//	
//	cout << Less(d1, d2) << endl; // 可以比较，结果正确
//	Date* p1 = &d1;
//	Date* p2 = &d2;
//
//	cout << Less(p1, p2) << endl; // 可以比较，结果错误
//	return 0;
//}



//// 普通模板
//template<class T1, class T2>
//class Data
//{
//public:
//	Data() {
//		cout << "Data<T1, T2>" << endl;
//	}
//private:
//	T1 _d1;
//	T2 _d2;
//};
//
//// 模板特化
//template<>
//class Data<int, char>
//{
//public:
//	Data() {
//		cout << "Data<int, char>" << endl;
//	}
//private:
//	int _d1;
//	char _d2;
//};
//
//// 偏特化
//template <class T1>
//class Data<T1, int>
//{
//public:
//	Data() { 
//		cout << "Data<T1, int>" << endl; 
//	}
//private:
//	T1 _d1;
//	int _d2;
//};
//
////两个参数偏特化为指针类型
//template <typename T1, typename T2>
//class Data <T1*, T2*>
//{
//public:
//	Data() { cout << "Data<T1*, T2*>" << endl; }
//private:
//	T1 _d1;
//	T2 _d2;
//};
//
////两个参数偏特化为引用类型
//template <typename T1, typename T2>
//class Data <T1&, T2&>
//{
//public:
//	Data(const T1& d1, const T2& d2)
//		: _d1(d1)
//		, _d2(d2)
//	{
//		cout << "Data<T1&, T2&>" << endl;
//	}
//private:
//	const T1& _d1;
//	const T2& _d2;
//};
//
//
//int main()
//{
//
//	Data<double, int> d1; // 调用特化的int版本
//	Data<int, double> d2; // 调用基础的模板
//	Data<int, char> d3; // 调用全特化版本
//	Data<int*, int*> d4; // 调用特化的指针版本
//	Data<int&, int&> d5(1, 2); // 调用特化的指针版本
//
//	//Data<double, int> d1;
//	//Data<int, int> d1; // 匹配的是普通模板
//	//Data<int, char> d2; // 匹配的是模板特化
//	//Data<int, double> d3; // 偏特化	 
//
//	return 0;
//}

#include <vector>
#include <algorithm>

template<class T>
struct Less
{
	bool operator()(const T& x, const T& y) const
	{
		return x < y;
	}
};

// 对Less类模板按照指针方式特化
template<>
struct Less<Date*>
{
	bool operator()(const Date* x, const Date* y) const
	{
		return *x < *y;
	}
};

//int main()
//{
//	Date d1(2022, 7, 7);
//	Date d2(2022, 7, 6);
//	Date d3(2022, 7, 8);
//	vector<Date> v1;
//	v1.push_back(d1);
//	v1.push_back(d2);
//	v1.push_back(d3);
//
//	// 可以直接排序，结果是日期升序
//	sort(v1.begin(), v1.end(), Less<Date>());
//
//	vector<Date*> v2;
//	v2.push_back(&d1);
//	v2.push_back(&d2);
//	v2.push_back(&d3);
//
//	// 走的是模板特化
//	sort(v2.begin(), v2.end(), Less<Date*>());
//	return 0;
//}

// 主函数

#include"Test.h"

int main()
{
	Add(1, 2);
	Add(1.0, 2.0);
	return 0;
}
