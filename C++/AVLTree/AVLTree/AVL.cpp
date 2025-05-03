#include "AVL.h"
#include <vector>
// 测试代码
void TestAVLTree1()
{
	AVLTree<int, int> t;
	// 常规的测试用例
	//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	// 特殊的带有双旋场景的测试用例
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	for (auto e : a)
	{
		t.Insert({ e, e });
	}
	t.InOrder();

	std::cout << t.IsBalanceTree() << std::endl;
}

// 插入一堆随机值，测试平衡，顺便测试一下高度和性能等
void TestAVLTree2()
{
	const int N = 100000000;
	vector<int> v;
	v.reserve(N);
	srand((unsigned int)time(0));

	for (size_t i = 0; i < N; i++)
		v.push_back(rand() + i);

	// 插入值
	//////////////////////////////////////////////////////
	size_t begin1 = clock();
	AVLTree<int, int> t;
	for (size_t i = 0; i < v.size(); ++i)
		t.Insert(make_pair(v[i], v[i]));
	size_t end1 = clock();
	cout << "Insert:" << end1 - begin1 << endl;
	//////////////////////////////////////////////////////

	// 检查是否平衡
	cout << t.IsBalanceTree() << endl;

	// 查看高度
	//////////////////////////////////////////////////////
	cout << "Height:" << t.Height() << endl;
	cout << "Size:" << t.Size() << endl;
	//////////////////////////////////////////////////////
	
	// 随机值查找
	size_t begin2 = clock();
	for (size_t i = 0; i < N; i++)
		t.Find((rand() + i));
	size_t end2 = clock();
	cout << "随机的值：Find:" << end2 - begin2 << endl;
	//////////////////////////////////////////////////////

	// 确定在的值查找
	size_t begin3 = clock();
	for (auto e : v)
		t.Find(e);
	size_t end3 = clock();
	cout << "确定的值：Find:" << end3 - begin3 << endl;
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
