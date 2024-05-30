

#include "Hash.h"


void TestHT1()
{
	int a[] = { 10001,11,55,24,19,12,31 };
	Close_Hash::HashTable<int, int> ht;
	for (auto e : a)
	{
		ht.Insert(make_pair(e, e));
	}

	cout << ht.Find(55) << endl;
	cout << ht.Find(31) << endl;

	ht.Erase(55);
	cout << ht.Find(55) << endl;
	cout << ht.Find(31) << endl;
}

void TestHT2()
{
	int a[] = { 10001,11,55,24,19,12,31 };
	Close_Hash::HashTable<int, int> ht;
	for (auto e : a)
	{
		ht.Insert(make_pair(e, e));
	}

	ht.Insert(make_pair(32, 32));
	ht.Insert(make_pair(32, 32));
}


int main()
{
	TestHT1();
	return 0;
}