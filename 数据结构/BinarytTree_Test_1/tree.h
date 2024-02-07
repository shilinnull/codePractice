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


//ǰ��
void PrevOrder(BTNode* root);
//����
void InOrder(BTNode* root);
//����
void PostOrder(BTNode* root);

//�ڵ�ĸ���
void TreeSize_1(BTNode* root,int* psize);

int TreeSize_2(BTNode* root);

//��Ҷ�ӽ��ĸ���
int TreeLeafSize(BTNode* root);

//��ȱ���
void Leve1Order(BTNode* root);

//����
void DestoryTree(BTNode* root);
