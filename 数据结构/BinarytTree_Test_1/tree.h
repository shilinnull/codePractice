#pragma once

#include<stdio.h>
#include<stdlib.h>


typedef char BTDataType;

typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTDataType val;
}BTNode;

#include"Queue.h"


//前序
void PrevOrder(BTNode* root);
//中序
void InOrder(BTNode* root);
//后序
void PostOrder(BTNode* root);

//节点的个数
void TreeSize_1(BTNode* root,int* psize);

int TreeSize_2(BTNode* root);

//求叶子结点的个数
int TreeLeafSize(BTNode* root);

//广度遍历
void Leve1Order(BTNode* root);

//销毁
void DestoryTree(BTNode* root);
