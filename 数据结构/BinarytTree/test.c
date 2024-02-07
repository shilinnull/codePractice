
#include"Tree.h"


int main()
{
	BTNode* root = CreateTree();

	printf("二叉树前序遍历:");
	BinaryTreePrevOrder(root);
	printf("\n");
	printf("\n");

	printf("二叉树中序遍历:");
	BinaryTreeInOrder(root);
	printf("\n");
	printf("\n");

	printf("二叉树后序遍历:");
	BinaryTreePostOrder(root);
	printf("\n");
	printf("\n");

	printf("二叉树的节点个数:%d", BinaryTreeSize(root));
	printf("\n");
	printf("\n");

	printf("二叉树的叶子节点个数:%d", BinaryTreeLeafSize(root));
	printf("\n");
	printf("\n");

	printf("二叉树的高度:%d", TreeHeight(root));
	printf("\n");
	printf("\n");
	
	printf("二叉树第k层节点个数:%d", BinaryTreeLevelKSize(root,4));
	printf("\n");
	printf("\n");

	printf("二叉树第k层的节点:%p", BinaryTreeFind(root, 5));
	printf("\n");
	printf("\n");
	
	printf("二叉树的层序遍历:\n");
	BinaryTreeLevelOrder(root);
	printf("\n");

	printf("二叉树是否完全二叉树:%d",BinaryTreeComplete(root));
	printf("\n");
	printf("\n");

	BinaryTreeDestory(root);
	root = NULL;
	return 0;
}

