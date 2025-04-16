#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <list>
using namespace std;


void Print(const vector<int>& v)
{
	// 1. 第一种这种可以直接使用
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
	// 2. 如果直接使用的话，没有实例化时不知道这个const_iterator是什么类型
	//vector<T>::const_iterator it = v.begin();
	
	// 所以在前面需要加上typename来告诉编译器
	typename vector<T>::const_iterator it = v.begin();
	//auto it = v.begin(); // 更简单的方式
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


