
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
//	// 删除
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
	// 输入单词，查找单词对应的中文翻译
	key_value::BSTree<std::string, std::string> dict;
	dict.Insert("string", "字符串");
	dict.Insert("tree", "树");
	dict.Insert("left", "左边、剩余");
	dict.Insert("right", "右边");
	dict.Insert("sort", "排序");
	// 插入词库中所有单词
	std::string str;
	while (std::cin >> str)
	{
		key_value::BSTreeNode<std::string, std::string>* ret = dict.Find(str);
		if (ret == nullptr)
		{
			std::cout << "单词拼写错误，词库中没有这个单词:" << str << std::endl;
		}
		else
		{
			std::cout << str << "中文翻译:" << ret->_value << std::endl;
		}
	}
}
void TestBSTree2()
{
	// 统计水果出现的次数
	std::string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜","苹果", "香蕉", "苹果", "香蕉" };
	key_value::BSTree<std::string, int> countTree;
	for (const auto& str : arr)
	{
		// 先查找水果在不在搜索树中
		// 1、不在，说明水果第一次出现，则插入<水果, 1>
		// 2、在，则查找到的节点中水果对应的次数++
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

