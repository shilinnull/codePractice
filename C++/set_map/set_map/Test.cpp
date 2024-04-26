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
	std::cout << *ret.second << std::endl; // >val

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

void test_map1()
{
	map<string, string> dict;
	dict.insert(pair<string, string>("sort", "排序"));
	dict.insert(pair<string, string>("inster", "插入"));
	dict.insert(pair<const char*, const char*>("left", "左"));

	dict.insert(make_pair("right", "右"));
	
	string s1("xxx"), s2("yyy");
	dict.insert(make_pair(s1, s2));

	// 1. 正向迭代器
	map<string, string>::iterator it = dict.begin();
	while (it != dict.end())
	{
		cout << (*it).first << " " << (*it).second << endl;
		//cout << it->first << " " << it->second << endl;
		//cout << it.operator->()->first << " " << it.operator->()->second << endl;
		++it;
	}
	cout << endl;

	// 2. 反向迭代器
	map<string, string>::reverse_iterator rit = dict.rbegin();
	while (rit != dict.rend())
	{
		cout << (*rit).first << " " << (*rit).second << endl;
		++rit;
	}
	cout << endl;

	// 3. auto
	for (auto& e : dict)
	{
		// e.first += 'x';  // 不能修改
		e.second += 'x'; // 可以修改
		cout << e.first << " " << e.second << endl;
	}
	cout << endl;

	for (auto& kv : dict)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
}

void test_map2()
{
	std::string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜","苹果", "香蕉", "苹果", "香蕉" };
	map<string,int> countMap;
	for (auto& str : arr)
	{
		//auto ret = countMap.find(str);
		//if (ret == countMap.end())
		//{
		//	countMap.insert(make_pair(str, 1));
		//}
		//else
		//{
		//	ret->second++;
		//}

		// 一行完成统计
		countMap[str]++;
	}
}



void test_map4()
{
	map<string, string> dict;
	dict.insert(pair<string, string>("sort", "排序"));
	dict.insert(pair<string, string>("inster", "插入"));
	dict.insert(pair<const char*, const char*>("left", "左"));

	dict.insert(make_pair("right", "右"));

	string s1("xxx"), s2("yyy");
	dict.insert(make_pair(s1, s2));

	dict["erase"];  // 插入
	cout << dict["erase"] << endl; // 查找
	dict["erase"] = "删除"; // 修改
	dict["test"] = "测试";  // 插入+修改
	dict["left"] = "左边、剩余"; // 修改

	map<string, string>::iterator it = dict.begin();
	while (it != dict.end())
	{
		cout << (*it).first << " " << (*it).second << endl;
		++it;
	}
}

void test_map3()
{
	map<string, string> dict;
	dict.insert(pair<string, string>("sort", "排序"));
	dict.insert(pair<string, string>("inster", "插入"));
	dict.insert(pair<const char*, const char*>("left", "左"));

	dict.insert(make_pair("right", "右"));

	string s1("xxx"), s2("yyy");
	dict.insert(make_pair(s1, s2));

	map<string, string>::iterator pos = dict.find("sort");
	if (pos != dict.end())
	{
		cout << pos->second << endl;
	}
}

int main()
{
	//test_set1();
	//test_set2();
	//test_set3();
	//test_map1();
	//test_map2();
	//test_map4();
	test_map3();

	return 0;
}
