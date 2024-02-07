#define _CRT_SECURE_NO_WARNINGS 1
/*
ʵ��һ�����������������ַ����е�k���ַ���
���磺
ABCD����һ���ַ��õ�BCDA

ABCD���������ַ��õ�CDAB
*/

#include<stdio.h>
#include<string.h>
//����һ��
/* 
void LeftRound(char* src, int k)
{
	int len = strlen(src);
	int count = k % len;
	//Ҫ�ƶ��Ĵ���
	for (int i = 0; i < count; i++)
	{
		//������ĵ�һ���ַ��洢����ʱtmp������
		char tmp = src[0];
		int j = 0;
		//�������е��ַ�����и���ǰ��
		for (j = 0; j < len - 1; j++)
		{
			src[j] = src[j + 1];
		}
		//�����ʱ������ֵ��ԭ�����У�����ƶ�
		src[j] = tmp;
	}
}
*/
//��������
/*

	char tmp[256] = { 0 };
	//��Ҫ�������ַ���������ʱ����tmp��
	strcpy(tmp, src + count);
	//ƴ�ӵ�ָ��λ��tmp,��src��ʼƴ��3��
	strncat(tmp, src, k);
	//��tmp���ַ�������src
	strcpy(src, tmp);
}
*/
//��������
#include<assert.h>
//�����ַ���
void Reverse(char* str, int right, int left)
{
	assert(str != NULL);
	while (left < right)
	{
		char tmp = str[left];
		str[left] = str[right];
		str[right] = tmp;
		right++;
		left--;
	}
}

void LeftRound(char* src, int k)
{
	int len = strlen(src);
	int count = k % len;
	//���������ַ���,��0������ļ����ַ�-1��������
	Reverse(src, 0, k - 1);
	//���������ַ���,��k���ܳ���-1��������
	Reverse(src, k, len - 1);
	//���������ַ���,��0���ܳ���-1��������
	Reverse(src, 0, len - 1);
}
int main()
{
	char arr[] = "abcd";
	int n = 0;
	printf("������Ҫ���򼸴�:>");
	scanf("%d", &n);
	//���ú�������ʵ��
	LeftRound(arr, n);
	printf("%s", arr);
	return 0;
}