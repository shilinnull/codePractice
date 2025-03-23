#include "RB.h"

#if 0
int main()
{
	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	//int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	//int a[] = { 790,760,969,270,31,424,377,24,702 };
	RBTree<int, int> t;
	for (auto e : a)
	{
		cout << "Insert:" << e << "->";
		t.Insert(make_pair(e, e));
		cout << t.IsBalance() << endl;
	}
	t.InOrder();

	cout << t.IsBalance() << endl;

	return 0;
}
#endif


#include"MyMap.h"
#include"MySet.h"

void test_set()
{
	lsl::set<int> s;
	s.insert(4);
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(2);
	s.insert(0);
	s.insert(10);
	s.insert(5);

	lsl::set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		// *it += 1;

		cout << *it << " ";
		++it;
	}
	cout << endl;

	// keyĞŞ¸ÄÎÊÌâ
	it = s.begin();
	// *it = 100;

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_map()
{
	lsl::map<string, string> dict;
	dict.insert(make_pair("sort", "ÅÅĞò"));
	dict.insert(make_pair("sort", "xx"));
	dict.insert(make_pair("left", "×ó±ß"));
	dict.insert(make_pair("right", "ÓÒ±ß"));

	lsl::map<string, string>::iterator it = dict.begin();
	while (it != dict.end())
	{
		// keyĞŞ¸ÄÎÊÌâ
		// it->first += 'x';
		// it->second += 'y';

		cout << it->first << ":" << it->second << endl;
		++it;
	}
	cout << endl;

	string arr[] = { "Ïã½¶", "Ìğ¹Ï","Æ»¹û", "Î÷¹Ï", "Æ»¹û", "Î÷¹Ï", "Æ»¹û", "Æ»¹û", "Î÷¹Ï", "Æ»¹û", "Ïã½¶", "Æ»¹û", "Ïã½¶" };
	lsl::map<string, int> countMap;
	for (auto& e : arr)
	{
		countMap[e]++;
	}

	for (auto& kv : countMap)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
	cout << endl;
}

int main()
{
	test_map();
	// test_set();

	return 0;
}


