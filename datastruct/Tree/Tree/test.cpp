#define _CRT_SECURE_NO_WARNINGS 1
#include "Tree.h"

int main()
{
	BTNode* root = CreateTree();
	BinaryTreePrevOrder(root);
	printf("\n");
	BinaryTreeInOrder(root);
	printf("\n");
	BinaryTreePostOrder(root);
	printf("\n");

	printf("size:%d\n", BinaryTreeSize(root));
	printf("size:%d\n", BinaryTreeSize(root));
	printf("leaf size:%d\n", BinaryTreeLeafSize(root));
	printf("K size:%d\n", BinaryTreeLevelKSize(root, 1));
	printf("K size:%d\n", BinaryTreeLevelKSize(root, 2));
	printf("K size:%d\n", BinaryTreeLevelKSize(root, 3));
	printf("depth:%d\n", BinaryTreeDepth(root));
	BTNode* find = BinaryTreeFind(root, 7);
	if (find == NULL)
		printf("未找到！\n");
	else
		printf("找到了！\n");
	BinaryTreeLevelOrder(root);

	if (BinaryTreeComplete(root))
		printf("是完全二叉树");
	else
		printf("不是完全二叉树");

	BinaryTreeDestory(&root);
	return 0;
}