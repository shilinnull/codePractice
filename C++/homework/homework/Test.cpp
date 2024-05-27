#include "RB.h"


int main()
{
	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	//int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	//int a[] = { 790,760,969,270,31,424,377,24,702 };
	RBTree<int, int> t;
	for (auto e : a)
	{
		if (e == 702)
		{
			int i = 0;
		}

		cout << "Insert:" << e << "->";
		t.Insert(make_pair(e, e));
		cout << t.IsBalance() << endl;
	}
	t.InOrder();

	cout << t.IsBalance() << endl;

	return 0;
}