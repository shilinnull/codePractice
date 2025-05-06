#include"HashTable.h"

using namespace std;

namespace open_address
{
	void TestHT1()
	{
		int a[] = { 19, 30, 5, 36, 13, 20, 21, 12 };
		HashTable<int, int> ht;
		for (auto e : a)
		{
			ht.Insert({ e, e });
		}

		for (size_t i = 0; i < 50; i++)
		{
			ht.Insert({ rand(),1 });
		}

		cout << ht.Find(-20) << endl;
		cout << ht.Find(9) << endl;

		ht.Erase(30);

		cout << ht.Find(20) << endl;
		cout << ht.Find(9) << endl;
		cout << ht.Find(30) << endl;
	}

	void TestHT2()
	{
		HashTable<string, string> dict; // ��hashtable�н������ػ�
		dict.Insert({ "sort", "����" });
		dict.Insert({ "string", "�ַ���" });

		HashTable<double, int> ht;
		ht.Insert({ 1.23, 1 });

	}
}


namespace hash_bucket
{
	void TestHT1()
	{
		int a[] = { 19, 30, 5, 36, 13, 20, 21, 12, 58, 111 };
		HashTable<int, int> ht;
		for (auto e : a)
		{
			ht.Insert({ e, e });
		}

		ht.Erase(5);
		ht.Erase(58);
		ht.Erase(111);

		for (size_t i = 0; i < 50; i++)
		{
			ht.Insert({ rand(),1 });
		}

		HashTable<string, string> dict;
		dict.Insert({ "sort", "����" });
		dict.Insert({ "string", "�ַ���" });
	}
}


int main()
{
	//open_address::TestHT1();
	//open_address::TestHT2();

	hash_bucket::TestHT1();

	return 0;
}