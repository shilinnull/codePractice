#define _CRT_SECURE_NO_WARNINGS 1


#include"SepList.h"


sltest1()
{
	//��ʼ����β�����
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 1);

	SLPrint(&sl);
}

sltest2()
{
	//��ʼ����β�����
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 1);
	
	SLPushFront(&sl, 20);

	SLPrint(&sl);
}
sltest3()
{
	//��ʼ����ͷɾ����
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 1);
	SLPrint(&sl);

	SLPopFront(&sl);

	SLPrint(&sl);
}
sltest4()
{
	//������λ��֮ǰ����
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 1);
	SLPrint(&sl);

	SLInsert(&sl,2,30);

	SLPrint(&sl);
}


sltest5()
{
	//������λ��֮ǰɾ��
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 1);
	SLPrint(&sl);

	SLErase(&sl, 3);

	SLPrint(&sl);
}
sltest6()
{
	//������λ��֮ǰɾ��
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 1);
	SLPrint(&sl);

	if (SLFind(&sl, 5))
		printf("�ҵ���");
	else
		printf("�Ҳ���");


}


int main()
{
	sltest4();
	return 0;
}




