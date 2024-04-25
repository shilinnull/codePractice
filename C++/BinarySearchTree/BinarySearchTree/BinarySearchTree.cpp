
#include"BinarySearchTree.h"

//int main()
//{
//	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
//	key::BSTree<int> b;
//	for (auto e : a)
//	{
//		b.InsertR(e);
//	}
//	b.InOrder();
//	// ɾ��
//	b.EraseR(14);
//	b.InOrder();
//
//	b.EraseR(3);
//	b.InOrder();
//
//	b.EraseR(8);
//	b.InOrder();
//
//	for (auto e : a)
//	{
//		b.EraseR(e);
//		b.InOrder();
//	}
//
//	return 0;
//}


#include<string>

#if DEBUG
void TestBSTree1()
{
	// ���뵥�ʣ����ҵ��ʶ�Ӧ�����ķ���
	key_value::BSTree<std::string, std::string> dict;
	dict.Insert("string", "�ַ���");
	dict.Insert("tree", "��");
	dict.Insert("left", "��ߡ�ʣ��");
	dict.Insert("right", "�ұ�");
	dict.Insert("sort", "����");
	// ����ʿ������е���
	std::string str;
	while (std::cin >> str)
	{
		key_value::BSTreeNode<std::string, std::string>* ret = dict.Find(str);
		if (ret == nullptr)
		{
			std::cout << "����ƴд���󣬴ʿ���û���������:" << str << std::endl;
		}
		else
		{
			std::cout << str << "���ķ���:" << ret->_value << std::endl;
		}
	}
}
void TestBSTree2()
{
	// ͳ��ˮ�����ֵĴ���
	std::string arr[] = { "ƻ��", "����", "ƻ��", "����", "ƻ��", "ƻ��", "����","ƻ��", "�㽶", "ƻ��", "�㽶" };
	key_value::BSTree<std::string, int> countTree;
	for (const auto& str : arr)
	{
		// �Ȳ���ˮ���ڲ�����������
		// 1�����ڣ�˵��ˮ����һ�γ��֣������<ˮ��, 1>
		// 2���ڣ�����ҵ��Ľڵ���ˮ����Ӧ�Ĵ���++
		//BSTreeNode<string, int>* ret = countTree.Find(str);
		auto ret = countTree.Find(str);
		if (ret == NULL)
		{
			countTree.Insert(str, 1);
		}
		else
		{
			ret->_value++;
		}
	}
	countTree.InOrder();
}


int main()
{
	TestBSTree1();
	TestBSTree2();

	return 0;
}

#endif

