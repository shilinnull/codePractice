
#include"Tree.h"
#include"Queue.h"


BTNode* BuyTreeNode(int x)
{
	BTNode*node = (BTNode*)malloc(sizeof(BTNode));
	assert(node);

	node->data = x;
	node->left = NULL;
	node->right = NULL;

	return node;
}

BTNode* CreateTree()
{
	BTNode* node1 = BuyTreeNode(1);
	BTNode* node2 = BuyTreeNode(2);
	BTNode* node3 = BuyTreeNode(3);
	BTNode* node4 = BuyTreeNode(4);
	BTNode* node5 = BuyTreeNode(5);
	BTNode* node6 = BuyTreeNode(6);
	BTNode* node7 = BuyTreeNode(7);

	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;
	node5->right = node7;

	return node1;
}

// 二叉树销毁
void BinaryTreeDestory(BTNode* root)
{
	if (root == NULL)
		return;

	BinaryTreeDestory(root->left);
	BinaryTreeDestory(root->right);
	free(root);
}
// 二叉树节点个数
int BinaryTreeSize(BTNode* root)
{
	return root == NULL ? 0 : BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}
// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;

	if (root->left == NULL && root->right == NULL)
		return 1;

	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}
// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	assert(k > 0);
	if (root == NULL)
		return 0;

	if (k == 1)
		return 1;

	return BinaryTreeLevelKSize(root->left, k - 1) + 
		   BinaryTreeLevelKSize(root->right, k - 1);
}
// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;

	if (root->data == x)
		return root;

	BTNode* ret1 = BinaryTreeFind(root->left,x);
	if (ret1)
		return ret1;

	BTNode* ret2 = BinaryTreeFind(root->right,x);
	if (ret2)
		return ret2;
	
	return NULL;
}
// 二叉树前序遍历 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%d ", root->data);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}
// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	BinaryTreeInOrder(root->left);
	printf("%d ", root->data);
	BinaryTreeInOrder(root->right);
}
// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	BinaryTreePostOrder(root->left);
	BinaryTreePostOrder(root->right);
	printf("%d ", root->data);
}
// 层序遍历
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	//如果节点为空就push节点
	if (root)
		QueuePush(&q, root);

	int levelSize = 1;
	//如果不为空就入队列
	while (!QueueEmpty(&q))
	{
		//走每层的个数
		while (levelSize--)
		{
			//取队头
			BTNode* front = QueueFront(&q);
			QueuePop(&q);
			
			printf("%d ", front->data);

			//遍历左子树
			if (front->left)
				QueuePush(&q, front->left);
			//遍历右子树
			if (front->right)
				QueuePush(&q, front->right);
		}
		printf("\n");

		//每层的结点个数
		levelSize = QueueSize(&q);
	}
	printf("\n");
	QueueDestroy(&q);
}
// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);

	//队列不为空就入队列
	while (!QueueEmpty(&q))
	{
		//取队头
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		//头为空就跳出循环
		if (front == NULL)
			break;

		//遍历左子树和右子树
		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
	}

	// 前面遇到空以后，后面还有非空就不是完全二叉树
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front)
		{
			QueueDestroy(&q);
			return false;
		}
	}

	QueueDestroy(&q);
	return true;
}

// 求树的高度
int TreeHeight(BTNode* root)
{
	if (root == NULL)
		return 0;

	BTDataType leftTreeHeight = TreeHeight(root->left);
	BTDataType rightTreeHeight = TreeHeight(root->right);

	return leftTreeHeight > rightTreeHeight ? leftTreeHeight + 1 : rightTreeHeight + 1;
}

