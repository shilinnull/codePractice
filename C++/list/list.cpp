#include"list.h"

// #define DEBUG

#if defined(DEBUG)

int main()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	lt.sort();
	lt.sort(greater<int>());
	for (auto e : lt)
	{
		cout << e << " ";
	}

	lt.unique();
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	return 0;
}
#endif
int main()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	// ×ªÒÆ
	lt.splice(lt.end(), lt, lt.begin());
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	list<int> lt1;
	lt1.push_back(10);
	lt1.push_back(20);
	lt1.push_back(30);
	lt1.push_back(40);

	lt.splice(lt.begin(), lt1);
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;
}




