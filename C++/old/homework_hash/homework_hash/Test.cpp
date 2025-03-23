
#include "unordered_map.h"
#include "unordered_set.h"


//void TestHT1()
//{
//	int a[] = { 10001,11,55,24,19,12,31 };
//	Close_Hash::HashTable<int, int> ht;
//	for (auto e : a)
//	{
//		ht.Insert(make_pair(e, e));
//	}
//
//	cout << ht.Find(55) << endl;
//	cout << ht.Find(31) << endl;
//
//	ht.Erase(55);
//	cout << ht.Find(55) << endl;
//	cout << ht.Find(31) << endl;
//}
//
//void TestHT2()
//{
//	int a[] = { 10001,11,55,24,19,12,31 };
//	Close_Hash::HashTable<int, int> ht;
//	for (auto e : a)
//	{
//		ht.Insert(make_pair(e, e));
//	}
//
//	ht.Insert(make_pair(32, 32));
//	ht.Insert(make_pair(32, 32));
//}


void Test_unordered_set()
{
	int a[] = { 10001,11,55,24,19,12,31 };
	lsl::unordered_set<int> s1;
	for (auto& e : a)
	{
		s1.insert(e);
	}
	for (auto& e : s1)
	{
		cout << e << endl;
	}

	s1.erase(11);

	for (auto& e : s1)
	{
		cout << e << endl;
	}
}

int main()
{

	Test_unordered_set();
	// TestHT1();
	return 0;
}