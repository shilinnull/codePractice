#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//#include<string.h>
////�����ַ������ÿ������
//
//void revers(char* left,char* right)
//{
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//
//
//int	main()
//{
//	char arr[20] = "i am a stu";
//
//	//�����ַ���
//	int len = strlen(arr);
//	revers(arr, arr + len - 1);
//	//���򵥸��ַ���
//	char* cur = arr;
//	while (*cur)
//	{
//		char* start = cur;
//		while (*cur != ' ' && *cur != '\0')
//		{
//			cur++;
//		}
//		if (*cur == '\0')
//			cur++;
//	}
//
//
//
//	//��ӡ�ַ���
//	printf("%s", arr);
//
//	return 0;
//}
//int main()
//{
//	//���ļ�
//	FILE* pf = fopen("data.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//д�ļ�
//	char ch = 0;
//	for (ch = 'a'; ch <= 'z'; ch++)
//	{
//		if (ch % 5 == 0)
//		{
//			fputc('\n', pf);
//		}
//		fputc(ch, pf);
//	}
//	//fputc('a', pf);
//	//fputc('b', pf);
//	//fputc('c', pf);
//	//fputc('d', pf);
//
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

//
//int main()
//{
//	//���ļ�
//	//FILE* pf = fopen("data.txt", "r");
//	//if (pf == NULL)
//	//{
//	//	perror("fopen");
//	//	return 1;
//	//}
//	//���ļ�
//
//	//fputs("hello ", pf);
//	//fputs("word!", pf);
//	//
//	//int ch = 0;
//	//while ((ch = fgetc(pf)) != EOF)
//	//{
//	//	printf("%c", ch);
//	//}
//	//int ch = fgetc(pf);
//	//printf("%c ", ch);
//
//	//ch = fgetc(pf);
//	//printf("%c ", ch);
//
//	//ch = fgetc(pf);
//	//printf("%c ", ch);
//
//	//ch = fgetc(pf);
//	//printf("%c ", ch);
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	//���ļ�
//	FILE* pf = fopen("data.txt", "w");
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//д�ļ�
//	//fputc('a', pf);
//	//fputc('b', pf);
//	//fputc('c', pf);
//
//	//for (char ch = 'a'; ch <= 'z'; ch++)
//	//{
//	//	fputc(ch, pf);
//	//}
//
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

#include<stdio.h>
int main()
{
	//���ļ�
	FILE* pf = fopen("data.txt", "r");
	if (NULL == pf)
	{
		perror("fopen");
		return 1;
	}
	//���ļ�

	//int ch = fgetc(pf);
	//printf("%c", ch);

	//ch = fgetc(pf);
	//printf("%c", ch);

	//ch = fgetc(pf);
	//printf("%c", ch);

	//ch = fgetc(pf);
	//printf("%c", ch);


	//for (int i = 0; i < 26; i++)
	//{
	//	printf("%c", fgetc(pf));
	//}
	int ch = 0;
	while ((ch = fgetc(pf)) != EOF)
	{
		printf("%c", ch);
	}

	//�ر��ļ�
	fclose(pf);
	pf = NULL;

	return 0;
}