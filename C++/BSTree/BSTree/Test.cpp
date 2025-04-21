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
//	//// ���Ҷ���Ϊ��
//	//t.Erase(8);
//	//t.InOrder();
//
//	//t.Erase(3);
//	//t.InOrder();
//
//	//// ��Ϊ��
//	//t.Erase(14);
//	//t.InOrder();
//
//	////// ��Ϊ��
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
//	//	cout << "�ҵ��ˣ�" << endl;
//	//else
//	//	cout << "û�ҵ�" << endl;
//	//if (tree.Find(20))
//	//	cout << "�ҵ��ˣ�" << endl;
//	//else
//	//	cout << "û�ҵ�" << endl;
//
//	return 0;
//}

#include<string>

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
        key_value::BSTNode<std::string, std::string>* ret = dict.Find(str);
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
