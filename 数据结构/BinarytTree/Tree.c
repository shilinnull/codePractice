
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

// ����������
void BinaryTreeDestory(BTNode* root)
{
	if (root == NULL)
		return;

	BinaryTreeDestory(root->left);
	BinaryTreeDestory(root->right);
	free(root);
}
// �������ڵ����
int BinaryTreeSize(BTNode* root)
{
	return root == NULL ? 0 : BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}
// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;

	if (root->left == NULL && root->right == NULL)
		return 1;

	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}
// ��������k��ڵ����
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
// ����������ֵΪx�Ľڵ�
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
// ������ǰ����� 
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
// �������������
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
// �������������
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
// �������
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	//����ڵ�Ϊ�վ�push�ڵ�
	if (root)
		QueuePush(&q, root);

	int levelSize = 1;
	//�����Ϊ�վ������
	while (!QueueEmpty(&q))
	{
		//��ÿ��ĸ���
		while (levelSize--)
		{
			//ȡ��ͷ
			BTNode* front = QueueFront(&q);
			QueuePop(&q);
			
			printf("%d ", front->data);

			//����������
			if (front->left)
				QueuePush(&q, front->left);
			//����������
			if (front->right)
				QueuePush(&q, front->right);
		}
		printf("\n");

		//ÿ��Ľ�����
		levelSize = QueueSize(&q);
	}
	printf("\n");
	QueueDestroy(&q);
}
// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);

	//���в�Ϊ�վ������
	while (!QueueEmpty(&q))
	{
		//ȡ��ͷ
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		//ͷΪ�վ�����ѭ��
		if (front == NULL)
			break;

		//������������������
		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
	}

	// ǰ���������Ժ󣬺��滹�зǿվͲ�����ȫ������
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

// �����ĸ߶�
int TreeHeight(BTNode* root)
{
	if (root == NULL)
		return 0;

	BTDataType leftTreeHeight = TreeHeight(root->left);
	BTDataType rightTreeHeight = TreeHeight(root->right);

	return leftTreeHeight > rightTreeHeight ? leftTreeHeight + 1 : rightTreeHeight + 1;
}

