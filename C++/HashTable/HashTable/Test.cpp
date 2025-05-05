#include"HashTable.h"

using namespace std;

void TestHT()
{
	int a[] = { 19, 30, 5, 36, 13, 20, 21, 12 };
	HashTable<int, int> ht;
	for (auto e : a)
	{
		ht.Insert({ e, e });
	}

	cout << ht.Find(20) << endl;
	cout << ht.Find(9) << endl;

	ht.Erase(30);

	cout << ht.Find(20) << endl;
	cout << ht.Find(9) << endl;
	cout << ht.Find(30) << endl;
}

int main()
{
	TestHT();

	return 0;
}