#include"Tree.h"

int main()
{
	BTNode* root = CreateTree();

	printf("二叉树的前序遍历：");
	BinaryTreePrevOrder(root);
	printf("\n");
	printf("\n");

	printf("二叉树的中序遍历：");
	BinaryTreeInOrder(root);
	printf("\n");
	printf("\n");

	printf("二叉树的后序遍历：");
	BinaryTreePostOrder(root);
	printf("\n");
	printf("\n");

	printf("二叉树的节点个数：%d", BinaryTreeSize(root));
	printf("\n");
	printf("\n");

	printf("二叉树的叶子节点个数：%d", BinaryTreeLeafSize(root));
	printf("\n");
	printf("\n");


	printf("二叉树的叶子节点个数：%d", BinaryTreeLevelKSize(root,4));
	printf("\n");
	printf("\n");
	


	printf("二叉树的节点%p", BinaryTreeFind(root,4));
	printf("\n");
	printf("\n");

	printf("二叉树的高度：%d", TreeHeight(root));
	printf("\n");
	printf("\n");

	printf("层序遍历:");
	BinaryTreeLevelOrder(root);
	printf("\n");
	printf("\n");
	
	printf("层序遍历（一层一层的打印）:\n");
	_BinaryTreeLevelOrder(root);
	printf("\n");

	if (BinaryTreeComplete(root))
		printf("是二叉树\n");
	else
		printf("不是二叉树\n");

	BinaryTreeDestory(root);
	return 0;
}