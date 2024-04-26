#include<iostream>
#include<map>
#include<set>
#include<string>
#include<vector>

using namespace std;

void test_set1()
{
	set<int> s1;
	s1.insert(1);
	s1.insert(11);
	s1.insert(3);
	s1.insert(1);
	s1.insert(4);
	s1.insert(2);

	set<int>::iterator it = s1.begin();
	while (it != s1.end())
	{
		//*it = 1;
		cout << *it << " ";
		++it;
	}
	cout << endl;

	vector<int> v = { 3,2,8,1,10,2 };
	set<int> s2(v.begin(), v.end());
	for (auto e : s2)
	{
		cout << e << " ";
	}
	cout << endl;

	set<int> s3 = { 3,2,8,1,10,2 };
	for (auto e : s3)
	{
		cout << e << " ";
	}
	cout << endl;
	s3.erase(8);
	s3.erase(18);
	for (auto e : s3)
	{
		cout << e << " ";
	}
	cout << endl;

	auto pos = s3.find(10);
	if (pos != s3.end())
	{
		cout << *pos << endl;
		s3.erase(pos);
	}
	else
	{
		cout << "找不到" << endl;
	}
	for (auto e : s3)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_set2()
{
	std::set<int> myset;
	for (int i = 1; i < 10; i++)
		myset.insert(i * 10); // 10 20 30 40 50 60 70 80 90

	for (auto e : myset)
	{
		cout << e << " ";
	}
	cout << endl;

	// [25,60)
	auto itlow = myset.lower_bound(25);      // >=val	
	auto itup = myset.upper_bound(60);       // >val

	myset.erase(itlow, itup);
	for (auto e : myset)
	{
		cout << e << " ";
	}
	cout << endl;

	auto ret = myset.equal_range(35);
	std::cout << *ret.first << std::endl; // >=val
	std::cout << *ret.second<< std::endl; // >val

}

void test_set3()
{
	// key模型搜索
	// 排序 不去重，允许冗余
	multiset<int> s1;
	s1.insert(1);
	s1.insert(11);
	s1.insert(3);
	s1.insert(1);
	s1.insert(4);
	s1.insert(2);
	s1.insert(4);
	s1.insert(2);
	s1.insert(2);
	s1.insert(2);
	s1.insert(1);
	s1.insert(2);
	s1.insert(2);
	s1.insert(1);

	multiset<int>::iterator it = s1.begin();
	while (it != s1.end())
	{
		//*it = 1;// 不能使用
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//auto pos = s1.find(2);
	//while (pos != s1.end() && *pos == 2)
	//{
	//	cout << *pos << " ";
	//	++pos;
	//}

	// 删除所有的2
	auto ret = s1.equal_range(2);
	s1.erase(ret.first, ret.second);
	
	// 还能统计删除了多少个2
	size_t n = s1.erase(2);  // 也可以这样直接删除
	cout << n << endl;

	for (auto e : s1)
	{
		cout << e << " ";
	}
	cout << endl;

	// 统计有几个1
	cout << s1.count(1) << endl;

}


int main()
{
	//test_set1();
	//test_set2();
	test_set3();


	return 0;
}
