#include"SeqList.h"

void SLtest() {
	SL sl;
	SLInit(&sl);
	//˳���ľ������
	//SLPushBack(&sl, 1);
	//SLPushBack(&sl, 2);
	//SLPushBack(&sl, 3);
	//SLPushBack(&sl, 4);//1 2 3 4
	//SLPrint(&sl);
	////ͷ��
	//SLPushFront(&sl, 5);//5 1 2 3 4
	//SLPushFront(&sl, 6);//6 5 1 2 3 4
	//SLPushFront(&sl, 7);//7 6 5 1 2 3 4
	//SLPrint(&sl);
	//βɾ
	SLPopBack(&sl);
	SLPrint(&sl);
	SLPopBack(&sl);
	SLPrint(&sl);
	SLDestroy(&sl);
}

void SLtest02()
{
	SL sl;
	SLInit(&sl);
	
}
int main() {
	//SLtest();	

	return 0;
}