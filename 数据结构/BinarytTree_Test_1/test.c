#define _CRT_SECURE_NO_WARNINGS 1

#include"tree.h"


int main()
{
	BTNode* A = (BTNode*)malloc(sizeof(BTNode));
	A->val = 'A';
	A->left = A->right = NULL;


	BTNode* B = (BTNode*)malloc(sizeof(BTNode));
	B->val = 'B';
	B->left = B->right = NULL;

	BTNode* C = (BTNode*)malloc(sizeof(BTNode));
	C->val = 'C';
	C->left = C->right = NULL;

	BTNode* D = (BTNode*)malloc(sizeof(BTNode));
	D->val = 'D';
	D->left = D->right = NULL;

	BTNode* E = (BTNode*)malloc(sizeof(BTNode));
	E->val = 'E';
	E->left = E->right = NULL;


	A->left = B;
	A->right = C;
	B->left = D;
	B->right = E;
	printf("前序\n");
	PrevOrder(A);
	printf("\n");

	printf("中序\n");
	InOrder(A);
	printf("\n");

	printf("后序\n");
	PostOrder(A);
	printf("\n");

	printf("------------------------------------\n");

	int Asize = 0;
	TreeSize_1(A, &Asize);
	printf("节点的个数是%d\n", Asize);
	
	int Bsize = 0;
	TreeSize_1(B, &Bsize);
	printf("节点的个数是%d\n", Bsize);

	printf("------------------------------------\n");

	printf("节点的个数是%d\n", TreeSize_2(A));
	printf("节点的个数是%d\n", TreeSize_2(B));

	printf("------------------------------------\n");

	printf("叶子节点的个数是%d\n", TreeLeafSize(A));

	printf("------------------------------------\n");

	printf("广度遍历\n");
	Leve1Order(A);

	DestoryTree(A);
	return 0;
}