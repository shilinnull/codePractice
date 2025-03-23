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
		cout << "�Ҳ���" << endl;
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
	// keyģ������
	// ���� ��ȥ�أ���������
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
		//*it = 1;// ����ʹ��
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

	// ɾ�����е�2
	auto ret = s1.equal_range(2);
	s1.erase(ret.first, ret.second);

	// ����ͳ��ɾ���˶��ٸ�2
	size_t n = s1.erase(2);  // Ҳ��������ֱ��ɾ��
	cout << n << endl;

	for (auto e : s1)
	{
		cout << e << " ";
	}
	cout << endl;

	// ͳ���м���1
	cout << s1.count(1) << endl;

}

void test_map1()
{
	map<string, string> dict;
	dict.insert(pair<string, string>("sort", "����"));
	dict.insert(pair<string, string>("inster", "����"));
	dict.insert(pair<const char*, const char*>("left", "��"));

	dict.insert(make_pair("right", "��"));
	
	string s1("xxx"), s2("yyy");
	dict.insert(make_pair(s1, s2));

	// 1. ���������
	map<string, string>::iterator it = dict.begin();
	while (it != dict.end())
	{
		cout << (*it).first << " " << (*it).second << endl;
		//cout << it->first << " " << it->second << endl;
		//cout << it.operator->()->first << " " << it.operator->()->second << endl;
		++it;
	}
	cout << endl;

	// 2. ���������
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
		// e.first += 'x';  // �����޸�
		e.second += 'x'; // �����޸�
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
	std::string arr[] = { "ƻ��", "����", "ƻ��", "����", "ƻ��", "ƻ��", "����","ƻ��", "�㽶", "ƻ��", "�㽶" };
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

		// һ�����ͳ��
		countMap[str]++;
	}
}



void test_map4()
{
	map<string, string> dict;
	dict.insert(pair<string, string>("sort", "����"));
	dict.insert(pair<string, string>("inster", "����"));
	dict.insert(pair<const char*, const char*>("left", "��"));

	dict.insert(make_pair("right", "��"));

	string s1("xxx"), s2("yyy");
	dict.insert(make_pair(s1, s2));

	dict["erase"];  // ����
	cout << dict["erase"] << endl; // ����
	dict["erase"] = "ɾ��"; // �޸�
	dict["test"] = "����";  // ����+�޸�
	dict["left"] = "��ߡ�ʣ��"; // �޸�

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
	dict.insert(pair<string, string>("sort", "����"));
	dict.insert(pair<string, string>("inster", "����"));
	dict.insert(pair<const char*, const char*>("left", "��"));

	dict.insert(make_pair("right", "��"));

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
