#define _CRT_SECURE_NO_WARNINGS 1
#include "list.h"
#include <list>

void Testlist1() {
	lsl::list<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	lsl::list<int> l2(10);
	lsl::list<int> l3(5,20);
	lsl::list<int> l4 = { 1,2,3,4,5,6 };
	lsl::list<int> l5(l4);
	lsl::list<int> l6 = l5;
	l6 = l5;
	

	for (auto& e: l6) {
		cout << e << " ";
	}

	cout << endl;
}

class A
{
public:
	A() = default;
	A(int a,int b)
		:_a(a)
		,_b(b)
	{}
//private:
	int _a;
	int _b;
};

// const������
void print(const lsl::list<int>& lt) {
	lsl::list<int>::const_iterator it = lt.begin();
	while (it != lt.end())
	{
		//*it += 1;
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void Testlist2() {
	lsl::list<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	lsl::list<int>::iterator it = l1.begin();
	while (it != l1.end())
	{
		cout << *it << endl;
		++it;
	}
	lsl::list<A> l2;
	l2.push_back({1,1});
	l2.push_back({2,2});
	l2.push_back({3,3});
	l2.push_back({4,4});
	
	lsl::list<A>::iterator it1 = l2.begin();
	while (it1 != l2.end())
	{
		//cout << (*it)._a << " " << (*it)._b << endl;
		cout << it1->_a << " " << it1->_b << endl;
		++it1;
	}

	lsl::list<int> l3;
	l3.push_back(1);
	l3.push_back(2);
	l3.push_back(3);
	l3.push_back(4);
	print(l3); // const������
}

void Testlist3() {
	lsl::list<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	l1.push_front(10);
	l1.push_front(20);
	for (auto& e : l1) {
		cout << e << " ";
	}
	cout << endl;

	l1.pop_front();
	l1.pop_back();
	for (auto& e : l1) {
		cout << e << " ";
	}
	cout << endl;

}

// �����д��
void TestListIterator1()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> l(array, array + sizeof(array) / sizeof(array[0]));
	auto it = l.begin();
	while (it != l.end())
	{
		// erase()����ִ�к�it��ָ��Ľڵ��ѱ�ɾ�������it��Ч������һ��ʹ��itʱ�������ȸ��丳ֵ
		l.erase(it);
		++it;
	}
}

// ����
void TestListIterator()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> l(array, array + sizeof(array) / sizeof(array[0]));
	auto it = l.begin();
	while (it != l.end())
	{
		l.erase(it++); // it = l.erase(it);
	}
}

int main() {
	Testlist2();

	return 0;
}