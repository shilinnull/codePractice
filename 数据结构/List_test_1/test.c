
#include"SList.h"



slttest1()
{
	//���Դ�ӡ
	SLNode* node1 = (SLNode*)malloc(sizeof(SLNode));
	node1->val = 1;
	SLNode* node2 = (SLNode*)malloc(sizeof(SLNode));
	node2->val = 2;
	SLNode* node3 = (SLNode*)malloc(sizeof(SLNode));
	node3->val = 3;
	SLNode* node4 = (SLNode*)malloc(sizeof(SLNode));
	node4->val = 4;

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = NULL;

	SLNode* plist = node1;
	SLTPrint(plist);

}

slttest2()
{

	//����β��
	SLNode* plist = NULL;

	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	
	SLTPrint(plist);

}

slttest3()
{

	//����ͷ��
	SLNode* plist = NULL;

	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);

	SLTPushFront(&plist, 20);

	SLTPrint(plist);

}
slttest4()
{

	//����βɾ
	SLNode* plist = NULL;

	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPrint(plist);

	SLTPopBack(&plist);
	SLTPrint(plist);

	SLTPopBack(&plist);
	SLTPrint(plist);

	SLTPopBack(&plist);
	SLTPrint(plist);

	SLTPopBack(&plist);
	SLTPrint(plist);



}

slttest5()
{

	//����ͷɾ
	SLNode* plist = NULL;

	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPrint(plist);

	SLTPopFront(&plist);
	SLTPrint(plist);

	SLTPopFront(&plist);
	SLTPrint(plist);

	SLTPopFront(&plist);
	SLTPrint(plist);

	SLTPopFront(&plist);
	SLTPrint(plist);

}

slttest6()
{
	//��ָ��λ��֮ǰ��������
	SLNode* plist = NULL;

	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPrint(plist);
	//��һ���ڵ�
	SLNode* find1 = SListFind(&plist, 1);
	SLTInsert(&plist, find1, 20);

	SLNode* find2 = SListFind(&plist, 3);
	SLTInsert(&plist,find2,10);
	SLTPrint(plist);
}

slttest7()
{
	//��ָ��λ��֮���������
	SLNode* plist = NULL;

	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPrint(plist);
	//��һ���ڵ�
	SLNode* find1 = SListFind(&plist, 1);
	SLTInsertAfter(find1, 100);
	SLTPrint(plist);

	SLNode* find2 = SListFind(&plist, 4);
	SLTInsertAfter(find2,200);
	SLTPrint(plist);
}


slttest8()
{
	//ɾ��pos�ڵ�
	SLNode* plist = NULL;

	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPrint(plist);
	//��һ���ڵ�
	SLNode* find1 = SListFind(&plist, 1);
	SLTErase(&plist,find1);
	SLTPrint(plist);

	SLNode* find2 = SListFind(&plist, 4);
	SLTErase(&plist, find2);
	SLTPrint(plist);
}



slttest9()
{
	//ɾ��pos֮��Ľڵ�
	SLNode* plist = NULL;

	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPrint(plist);
	//��һ���ڵ�
	SLNode* find1 = SListFind(&plist, 3);
	SLTEraseAfter(find1);
	SLTPrint(plist);

	SLNode* find2 = SListFind(&plist, 1);
	SLTEraseAfter(find2);
	SLTPrint(plist);
}



slttest10()
{
	//����
	SLNode* plist = NULL;

	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPrint(plist);
	SListDesTroy(&plist);
	SLTPrint(plist);

}


int main()
{

	slttest9();


	return 0;
}


