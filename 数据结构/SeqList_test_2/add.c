//
//
//#include"SepList.h"
//
//
//
////��ʼ��˳���
//void SLInit(SL* ps)
//{
//	assert(ps);
//
//	ps->a = NULL;
//	ps->capacity = ps->szie = 0;
//}
//
//
////����˳���
//void SLDestroy(SL* ps)
//{
//	assert(ps);
//
//	ps->a = NULL;
//	ps->capacity = ps->szie = 0;
//
//}
//
////�������
//
//void SLCheckCapacity(SL* ps)
//{
//	assert(ps);
//	if (ps->szie == ps->capacity)
//	{
//		SLDataType newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
//		SLDataType* tmp = (SLDataType*)realloc(ps->a, newcapacity * 2 * sizeof(SLDataType));
//		if (tmp == NULL)
//		{
//			perror("realloc fail!");
//			exit(-1);
//		}
//		ps->a = tmp;
//		ps->capacity = newcapacity;
//
//	}
//}
//
//
////β��
//void SLPushBack(SL* ps, SLDataType x)
//{
//	assert(ps);
//	SLCheckCapacity(ps);
//	ps->a[ps->szie++] = x;
//}
//
////ͷ��
//void SLPushFront(SL* ps, SLDataType x)
//{
//	assert(ps);
//	SLCheckCapacity(ps);
//
//	int end = ps->sz		ie - 1;
//	while (end >= 0)
//	{
//		ps->a[end + 1] = ps->a[end];
//		end--;
//	}
//
//	ps->a[0] = x;
//	ps->szie++;
//
//}
//
////βɾ
//void SLPopBack(SL* ps)
//{
//	assert(ps);
//
//	ps->szie--;
//}
//
//
////ͷɾ
//void SLPopFront(SL* ps)
//{
//	assert(ps);
//	for (size_t i = 0; i < ps->szie - 1; i++)
//	{
//		ps->a[i] = ps->a[i + 1];
//	}
//	ps->szie--;
//
//}
//
////��ӡ˳���
//void SLPrint(SL* ps)
//{
//	assert(ps);
//	for (size_t i = 0; i < ps->szie; i++)
//	{
//		printf("%d ", ps->a[i]);
//	}
//	printf("\n");
//
//}
//
//
////�ж��Ƿ�Ϊ��
//bool SLIsEmpty(SL* ps)
//{
//	assert(ps);
//	return ps->szie == 0;
//}
//
////������λ��֮ǰ����
//void SLInsert(SL* ps, int pos, SLDataType x)
//{
//	assert(ps);
//	assert(pos >= 0 && pos <= ps->szie);
//
//	SLCheckCapacity(ps);
//
//	int end = ps->szie;
//	while (end > pos)
//	{
//		ps->a[end] = ps->a[end - 1];
//		end--;
//	}
//
//	ps->a[pos - 1] = x;
//	ps->szie++;
//
//}
//
////������λ��֮ǰɾ��
//void SLErase(SL* ps, int pos)
//{
//	assert(ps);
//	assert(pos >= 0 && pos <= ps->szie);
//
//	int end = pos - 1;
//	while (end < ps->szie - 1)
//	{
//		ps->a[end] = ps->a[end + 1];
//		end++;
//	}
//	ps->szie--;
//}
//
////����˳���
//bool SLFind(SL* ps, SLDataType x)
//{
//	assert(ps);
//
//	for (size_t i = 0; i < ps->szie; i++)
//	{
//		if (ps->a[i] == x)
//		{
//			return true;
//		}
//	}
//	return false;
//}