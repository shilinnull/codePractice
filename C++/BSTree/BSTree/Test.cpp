#define _CRT_SECURE_NO_WARNINGS 1

#include "BSTree.h"

//int main()
//{
//	//int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
//    int a[] = { 7,2,4,6,3,1,5 };
//	key::BSTree<int> t;
//	for (size_t i = 0; i < sizeof(a) / sizeof(a[0]); i++)
//	{
//		t.Insert(a[i]);
//	}
//	t.InOrder();
//
//    t.Insert(8);
//    t.InOrder();
//
//	//t.Insert(16);
//	//t.InOrder();
//
//	//t.Insert(3);
//	//t.InOrder();
//
//	//// 左右都不为空
//	//t.Erase(8);
//	//t.InOrder();
//
//	//t.Erase(3);
//	//t.InOrder();
//
//	//// 右为空
//	//t.Erase(14);
//	//t.InOrder();
//
//	////// 左为空
//	//t.Erase(6);
//	//t.InOrder();
//
//	//for (auto e : a)
//	//{
//	//	t.Erase(e);
//	//	t.InOrder();
//	//}
//
//	//if (tree.Find(7))
//	//	cout << "找到了！" << endl;
//	//else
//	//	cout << "没找到" << endl;
//	//if (tree.Find(20))
//	//	cout << "找到了！" << endl;
//	//else
//	//	cout << "没找到" << endl;
//
//	return 0;
//}

#include<string>

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
        key_value::BSTNode<std::string, std::string>* ret = dict.Find(str);
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
        key_value::BSTNode<string, int>* ret = countTree.Find(str);
        // auto ret = countTree.Find(str);
        if (ret == nullptr)
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
    //TestBSTree1();
    //TestBSTree2();


    return 0;
}
