#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <list>
using namespace std;


void Print(const vector<int>& v)
{
	// 1. ��һ�����ֿ���ֱ��ʹ��
	vector<int>::const_iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

template<class T>
void Print(const vector<T>& v)
{
	// 2. ���ֱ��ʹ�õĻ���û��ʵ����ʱ��֪�����const_iterator��ʲô����
	//vector<T>::const_iterator it = v.begin();
	
	// ������ǰ����Ҫ����typename�����߱�����
	typename vector<T>::const_iterator it = v.begin();
	//auto it = v.begin(); // ���򵥵ķ�ʽ
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

template<class Container>
void Print(const Container& con)
{
	//typename Container::const_iterator it = con.begin();
	auto it = con.begin();
	while (it != con.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

int main()
{
	vector<int> v1 = { 1,2,3,4,5 };
	Print(v1);

	vector<double> v2 = { 11.1,2.2,33.3 };
	Print(v2);

	list<double> lt1 = { 11.1,2.2,33.3 };
	Print(lt1);

	return 0;
}


