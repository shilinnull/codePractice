#include "RBTree.h"
#include <vector>

// ���Դ���
void TestRBTree1()
{
	RBTree<int, int> t;
	// ����Ĳ�������
	//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	// ����Ĵ���˫�������Ĳ�������
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	for (auto e : a)
	{
		t.Insert({ e, e });
	}
	t.InOrder();
	cout << t.IsBalance() << endl;
}

void TestRBTree2()
{
	const int N = 100000000;
	std::vector<int> v;
	v.reserve(N);
	srand((unsigned int)time(0));

	for (size_t i = 0; i < N; i++)
	{
		v.push_back(rand() + i);
	}

	RBTree<int, int> t;
	for (size_t i = 0; i < v.size(); ++i)
	{
		t.Insert(make_pair(v[i], v[i]));
	}
	cout << t.IsBalance() << endl;
}

int main()
{
	TestRBTree2();

	return 0;
}