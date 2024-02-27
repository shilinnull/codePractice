#include<iostream>
#include<string>
#include<vector>
#include<list>
using namespace std;

//
//int main()
//{
//	string s1("hello world");
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << endl;
//		++it;
//	}
//
//	string::iterator it1 = s1.begin();
//	while (it1 != s1.end())
//	{
//		cout << *it1 << " ";
//		it1++;
//	}
//	cout << endl;
//
//	list<int> lt;
//	lt.push_back(1);
//	lt.push_back(2);
//	lt.push_back(3);
//	lt.push_back(4);
//
//	list<int>::iterator itt = lt.begin();
//	while (itt != lt.end())
//	{
//		cout << *itt << " ";
//		++itt;
//	}
//	cout << endl;
//
//	for (auto e : s1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	return 0;
//}

//int main()
//{
//	string s0;
//	string s1("hello world");
//	string s2(s1);
//	string s3(s1, 5, 3);
//	string s4(s1, 5, 10);
//	string s5(s1, 5);
//
//	cout << s0 << endl;
//	cout << s1 << endl;
//	cout << s2 << endl;
//	cout << s3 << endl;
//	cout << s4 << endl;
//	cout << s5 << endl;
//
//	string s6(10, '#');
//	cout << s6 << endl;
//	
//	s0 = s6;
//	cout << s0 << endl;
//	
//	return 0;
//}

void Test_string1()
{
	string s1("hello world");
	string::reverse_iterator rit = s1.rbegin();
	while (rit != s1.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl; 

	const string s2("hello world");
	string::const_iterator cit = s2.begin();
	while (cit != s2.end())
	{
		cout << *cit << " ";
		++cit;
	}
	cout << endl;
}
void Test_string2()
{
	string s1("hello world");
	cout << s1.max_size() << endl;
}
void Test_string3()
{
	string s1("hello");
	cout << s1.capacity() << endl;

	s1.resize(20);
	// s1.resize(30,'x');
	// s1.resize(0);
	cout << s1.capacity() << endl;
	cout << s1.empty() << endl;
	s1.shrink_to_fit();
	cout << s1.capacity() << endl;


	cout << s1.capacity() << endl;
	cout << s1.size() << endl;

	string s2("world");
	s1.swap(s2);
	cout << s2 << endl;

}















int main()
{
	Test_string3();





	return 0;
}





