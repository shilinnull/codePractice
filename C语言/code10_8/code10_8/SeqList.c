#include"SeqList.h"

void SLInit(SL* ps) {
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}
void SLDestroy(SL* ps) {
	if (ps->a)
		free(ps->a);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

void SLCheckCapacity(SL* ps) {
	if (ps->size == ps->capacity) {
		//�ռ䲻�����ٶ������һ������
		//����
		int newCapcity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		SLDataType* tmp = (SLDataType*)realloc(ps->a, newCapcity * sizeof(SLDataType));
		if (tmp == NULL) {
			perror("realloc fail!\n");
			return 1;
		}
		ps->a = tmp;
		ps->capacity = newCapcity;
	}
}

//β��
void SLPushBack(SL* ps, SLDataType x) {
	//assert(ps != NULL);
	//�����ķ�ʽ
	assert(ps);
	//��ͷ�ʽ
	//if (ps == NULL) {
	//	return;
	//}

	//1)�ռ��㹻��ֱ��β��
	//2���ռ䲻��������
	SLCheckCapacity(ps);
	//ֱ�Ӳ�������
	ps->a[ps->size++] = x;
}
//ͷ��
void SLPushFront(SL* ps, SLDataType x) {
	assert(ps);
	//�жϿռ��Ƿ��㹻,����������
	SLCheckCapacity(ps);
	//�ռ��㹻����ʷ���ݺ���һλ
	for (size_t i = ps->size; i > 0; i--)
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[0] = x;
	ps->size++;
}
//β��
void SLPopBack(SL* ps) {
	//�ж�˳����Ƿ�Ϊ��
	assert(ps);
	assert(!SLIsEmpty(ps));
	//ps->a[ps->size - 1] = 0;
	ps->size--;
}
void SLPopFront(SL* ps) {
	assert(ps);
	assert(!SLIsEmpty(ps));
	//�ú�������������ƶ�һλ
	for (size_t i = 0; i < ps->size - 1; i++)
	{
		//���һ�ν�����i��ֵΪps->size-1
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}
void SLPrint(SL* ps) {
	for (size_t i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
bool SLIsEmpty(SL* ps) {
	assert(ps);
	//�������ǲ��Եģ�����ֻ���жϿռ��Ƿ��㹻
	//return ps->size == ps->capacity;
	return ps->size == 0;
}