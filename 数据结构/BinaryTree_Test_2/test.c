#include"Tree.h"

int main()
{
	BTNode* root = CreateTree();

	printf("��������ǰ�������");
	BinaryTreePrevOrder(root);
	printf("\n");
	printf("\n");

	printf("�����������������");
	BinaryTreeInOrder(root);
	printf("\n");
	printf("\n");

	printf("�������ĺ��������");
	BinaryTreePostOrder(root);
	printf("\n");
	printf("\n");

	printf("�������Ľڵ������%d", BinaryTreeSize(root));
	printf("\n");
	printf("\n");

	printf("��������Ҷ�ӽڵ������%d", BinaryTreeLeafSize(root));
	printf("\n");
	printf("\n");


	printf("��������Ҷ�ӽڵ������%d", BinaryTreeLevelKSize(root,4));
	printf("\n");
	printf("\n");
	


	printf("�������Ľڵ�%p", BinaryTreeFind(root,4));
	printf("\n");
	printf("\n");

	printf("�������ĸ߶ȣ�%d", TreeHeight(root));
	printf("\n");
	printf("\n");

	printf("�������:");
	BinaryTreeLevelOrder(root);
	printf("\n");
	printf("\n");
	
	printf("���������һ��һ��Ĵ�ӡ��:\n");
	_BinaryTreeLevelOrder(root);
	printf("\n");

	if (BinaryTreeComplete(root))
		printf("�Ƕ�����\n");
	else
		printf("���Ƕ�����\n");

	BinaryTreeDestory(root);
	return 0;
}