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
//	// ��ʽʵ����
//	Add<int>(a, b);
//
//
//	return 0;
//}

//// ר�Ŵ���int�ļӷ�����
//int Add(int left, int right)
//{
//	return left + right;
//}
//// ͨ�üӷ�����
//template<class T>
//T Add(T left, T right)
//{
//	return left + right;
//}
//void Test()
//{
//	Add(1, 2); // ��Ǻ���ģ��������ȫƥ�䣬����Ҫ����ģ��ʵ����
//	Add(1, 2.0); // ģ�庯���������ɸ���ƥ��İ汾������������ʵ�����ɸ���ƥ���Add����
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
//	// ʹ������������ʾ�������������������ⶨ�塣
//	~Vector();
//	void PushBack(const T& data)��
//		void PopBack()��
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
//// ע�⣺��ģ���к�������������ж���ʱ����Ҫ��ģ������б�
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
//// Vector������Vector<int>��������
//Vector<int> s1;
//Vector<double> s2;
//
//	


//namespace lsl
//{
//	// ����һ��ģ�����͵ľ�̬����
//	// ������ģ�����   ����  ����
//	template<class T, size_t N = 10>
//	class array
//	{
//	public:
//		T& operator[](size_t index) { 
//			size(1); // �����������﷨����
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
//	// Ĭ��Ϊ����Ϊ10
//	lsl::array<int> arr1;
//
//	// ָ����С
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
//	// C++11�е�array
//	std::array<int, 10> arr1; // Ĭ�ϲ����ʼ��
//	// ��ͨ����
//	int arr2[10];// Ĭ�ϲ����ʼ��
//
//	// C++11�е�arrayԽ�綼����
//	arr1[10];
//	arr1[15] = 1;
//
//	// ��ͨ����Խ��д�ǳ�飬����鲻����
//	arr2[10];
//	arr2[15] = 1; // ���ᱨ��
//
//	return 0;
//}

//#include<vector>
//
//int main()
//{
//	std::vector<int> a1(10, 0); // ���Գ�ʼ��
//	for (auto &e : a1) {
//		cout << e << " ";
//	}
//
//	// ������
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
//// ����ģ�� -- ����ƥ��
//template<class T>
//bool Less(T left, T right)
//{
//	return left < right;
//}
//
//// ģ���ػ�
//template<>
//bool Less<Date*>(Date* left, Date* right)
//{
//	return *left < *right;
//}
//
//// ֱ��ʹ�ú�������
//bool Less(Date* left, Date* right)
//{
//	return *left < *right;
//}

//int main()
//{
//	Date d1(2022, 7, 7);
//	Date d2(2022, 7, 8);
//
//	cout << Less(d1, d2) << endl; // �ߵ���ͨģ��
//	Date* p1 = &d1;
//	Date* p2 = &d2;
//
//	cout << Less(p1, p2) << endl; // �ߵ���ģ���ػ�
//	return 0;
//}


//int main()
//{
//	cout << Less(1, 2) << endl; // ���ԱȽϣ������ȷ
//
//	Date d1(2022, 7, 7);
//	Date d2(2022, 7, 8);
//	
//	cout << Less(d1, d2) << endl; // ���ԱȽϣ������ȷ
//	Date* p1 = &d1;
//	Date* p2 = &d2;
//
//	cout << Less(p1, p2) << endl; // ���ԱȽϣ��������
//	return 0;
//}



//// ��ͨģ��
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
//// ģ���ػ�
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
//// ƫ�ػ�
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
////��������ƫ�ػ�Ϊָ������
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
////��������ƫ�ػ�Ϊ��������
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
//	Data<double, int> d1; // �����ػ���int�汾
//	Data<int, double> d2; // ���û�����ģ��
//	Data<int, char> d3; // ����ȫ�ػ��汾
//	Data<int*, int*> d4; // �����ػ���ָ��汾
//	Data<int&, int&> d5(1, 2); // �����ػ���ָ��汾
//
//	//Data<double, int> d1;
//	//Data<int, int> d1; // ƥ�������ͨģ��
//	//Data<int, char> d2; // ƥ�����ģ���ػ�
//	//Data<int, double> d3; // ƫ�ػ�	 
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

// ��Less��ģ�尴��ָ�뷽ʽ�ػ�
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
//	// ����ֱ�����򣬽������������
//	sort(v1.begin(), v1.end(), Less<Date>());
//
//	vector<Date*> v2;
//	v2.push_back(&d1);
//	v2.push_back(&d2);
//	v2.push_back(&d3);
//
//	// �ߵ���ģ���ػ�
//	sort(v2.begin(), v2.end(), Less<Date*>());
//	return 0;
//}

// ������

#include"Test.h"

int main()
{
	Add(1, 2);
	Add(1.0, 2.0);
	return 0;
}
