#define _CRT_SECURE_NO_WARNINGS 1
#include "list.h"
#include "vector.h"


void test_list()
{
	lsl::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);

	lsl::list<int>::reverse_iterator rit = lt.rbegin();
	while (rit != lt.rend())
	{
		*rit += 1;
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	const lsl::list<int> lt1(lt);
	lsl::list<int>::const_reverse_iterator rit1 = lt1.rbegin();
	while (rit1 != lt1.rend())
	{
		//*rit1 += 1;

		cout << *rit1 << " ";
		++rit1;
	}
	cout << endl;
}

void test_vector()
{
	lsl::vector<int> v = { 1,2,3,4 };
	lsl::vector<int>::reverse_iterator rit = v.rbegin();
	while (rit != v.rend())
	{
		//*rit = 1;
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
}

int main() 
{
	//test_list();
	test_vector();
	return 0;
}