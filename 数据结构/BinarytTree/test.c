
#include"Tree.h"


int main()
{
	BTNode* root = CreateTree();

	printf("������ǰ�����:");
	BinaryTreePrevOrder(root);
	printf("\n");
	printf("\n");

	printf("�������������:");
	BinaryTreeInOrder(root);
	printf("\n");
	printf("\n");

	printf("�������������:");
	BinaryTreePostOrder(root);
	printf("\n");
	printf("\n");

	printf("�������Ľڵ����:%d", BinaryTreeSize(root));
	printf("\n");
	printf("\n");

	printf("��������Ҷ�ӽڵ����:%d", BinaryTreeLeafSize(root));
	printf("\n");
	printf("\n");

	printf("�������ĸ߶�:%d", TreeHeight(root));
	printf("\n");
	printf("\n");
	
	printf("��������k��ڵ����:%d", BinaryTreeLevelKSize(root,4));
	printf("\n");
	printf("\n");

	printf("��������k��Ľڵ�:%p", BinaryTreeFind(root, 5));
	printf("\n");
	printf("\n");
	
	printf("�������Ĳ������:\n");
	BinaryTreeLevelOrder(root);
	printf("\n");

	printf("�������Ƿ���ȫ������:%d",BinaryTreeComplete(root));
	printf("\n");
	printf("\n");

	BinaryTreeDestory(root);
	root = NULL;
	return 0;
}

