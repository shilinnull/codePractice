#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <string>

using namespace std;


struct Point
{
	int _x;
	int _y;
};

//int main()
//{
//	int array1[] = { 1, 2, 3, 4, 5 };
//	int array2[5] = { 0 };
//	Point p = { 1, 2 };
//	return 0;
//}
//
//struct Point
//{
//	int _x;
//	int _y;
//};
//
//int main()
//{
//	int x1 = 1;
//	int x2{ 2 };
//	int array1[]{ 1, 2, 3, 4, 5 };
//	int array2[5]{ 0 };
//	Point p{ 1, 2 };
//
//	// C++11���б��ʼ��Ҳ����������new���ʽ��
//	int* pa = new int[4]{ 0 };
//	return 0;
//}

class Date
{
public:
	Date(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Date(int year, int month, int day)" << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

//int main()
//{
//	Date d1(2022, 1, 1); 
//
//	// C++11֧�ֵ��б��ʼ�����������ù��캯����ʼ��
//	Date d2{ 2022, 1, 2 };
//	Date d3 = { 2022, 1, 3 };
//	return 0;
//}


//int main()
//{
//	// the type of il is an initializer_list 
//	auto il = { 10, 20, 30 };
//	cout << typeid(il).name() << endl;
//	return 0;
//}

//int main()
//{
//	// ��������
//	int i = 0;
//	int j = { 0 };
//	int k{ 0 };
//	int array1[]{ 1, 2, 3, 4, 5 };
//	int array2[5]{ 0 };
//	
//	// �Զ�������
//	Point p{ 1, 2 };
//	Date d1(2023, 11, 25);
//
//	// ����ת��  ����+��������->�Ż�ֱ�ӹ���
//	Date d2 = { 2024, 5, 15 };
//	Date d3{ 2024, 5, 15 };
//
//	string s1 = "xxxx";
//
//	const Date& d4 = { 2023, 11, 25 };
//
//	// new ���ʽ
//	Date* p1 = new Date[3]{ d1, d2, d3 };
//	Date* p2 = new Date[3]{ {2022, 11, 25}, {2022, 11, 26}, {2022, 11, 27} };
//
//	return 0;
//}



//int main()
//{
//	vector<int> v1 = { 1,2,3,4 };
//	vector<int> v2 = { 1,2,3,4,5,6};
//
//	v1 = { 10,20,30 };
//
//	list<int> lt = { 10,20,30 };
//
//	// �������������ת��  ����+��������->�Ż�ֱ�ӹ���
//	// ����Ӧ���캯����������ƥ��
//	Date d2 = { 2023, 11, 25 };
//
//	// the type of il is an initializer_list 
//	auto il1 = { 10, 20, 30, 40, 50 };
//	cout << typeid(il1).name() << endl;
//
//	initializer_list<int> il2 = { 10, 20, 30};
//
//	initializer_list<int>::iterator it2 = il2.begin();
//	while (it2 != il2.end())
//	{
//		cout << *it2 << " ";
//		++it2;
//	}
//	cout << endl;
//	
//	//for (int e : il2)
//	for (auto e : il2)
//	{
//		cout << e << " ";
//	}
//	cout<< endl;
//
//	pair<string, string> kv1("sort", "����");
//	map<string, string> dict = {{"insert", "����"}, {"get","��ȡ"} };
//	for (auto& kv : dict)
//	{
//		cout << kv.first << ":" << kv.second << endl;
//	}
//
//	Date dd2 = { 2023, 11, 25 };
//	// Date dd3 = { 2023, 11, 25, 20}; // ����
//
//	return 0;
//}


namespace lsl
{
	template<class T>
	class vector {
	public:
		typedef T* iterator;

		vector(initializer_list<T> l)
		{
			_start = new T[l.size()];
			_finish = _start + l.size();
			_endofstorage = _start + l.size();
			iterator vit = _start;
			typename initializer_list<T>::iterator lit = l.begin();
			while (lit != l.end())
			{
				*vit++ = *lit++;
			}
		}
		vector<T>& operator=(initializer_list<T> l) {
			vector<T> tmp(l);
			std::swap(_start, tmp._start);
			std::swap(_finish, tmp._finish);
			std::swap(_endofstorage, tmp._endofstorage);
			return *this;
		}
	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};
}