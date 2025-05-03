#include "AVL.h"
#include <vector>
// ���Դ���
void TestAVLTree1()
{
	AVLTree<int, int> t;
	// ����Ĳ�������
	//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	// ����Ĵ���˫�������Ĳ�������
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	for (auto e : a)
	{
		t.Insert({ e, e });
	}
	t.InOrder();

	std::cout << t.IsBalanceTree() << std::endl;
}

// ����һ�����ֵ������ƽ�⣬˳�����һ�¸߶Ⱥ����ܵ�
void TestAVLTree2()
{
	const int N = 100000000;
	vector<int> v;
	v.reserve(N);
	srand((unsigned int)time(0));

	for (size_t i = 0; i < N; i++)
		v.push_back(rand() + i);

	// ����ֵ
	//////////////////////////////////////////////////////
	size_t begin1 = clock();
	AVLTree<int, int> t;
	for (size_t i = 0; i < v.size(); ++i)
		t.Insert(make_pair(v[i], v[i]));
	size_t end1 = clock();
	cout << "Insert:" << end1 - begin1 << endl;
	//////////////////////////////////////////////////////

	// ����Ƿ�ƽ��
	cout << t.IsBalanceTree() << endl;

	// �鿴�߶�
	//////////////////////////////////////////////////////
	cout << "Height:" << t.Height() << endl;
	cout << "Size:" << t.Size() << endl;
	//////////////////////////////////////////////////////
	
	// ���ֵ����
	size_t begin2 = clock();
	for (size_t i = 0; i < N; i++)
		t.Find((rand() + i));
	size_t end2 = clock();
	cout << "�����ֵ��Find:" << end2 - begin2 << endl;
	//////////////////////////////////////////////////////

	// ȷ���ڵ�ֵ����
	size_t begin3 = clock();
	for (auto e : v)
		t.Find(e);
	size_t end3 = clock();
	cout << "ȷ����ֵ��Find:" << end3 - begin3 << endl;
}
int main()
{
	try
	{
		TestAVLTree2();
	}
	catch (const exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
