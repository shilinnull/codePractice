#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int n = 0;//½Ï´óÖµ
//	while (scanf("%d%d", &a, &b)!=EOF)
//	{
//		n = a > b ? a : b;
//		while (1)
//		{
//			if (n % a == 0 && n % b == 0)
//				break;
//			n++;
//		}
//		printf("%d\n", n);
//	}
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	int b = 0;
//	int i = 1;
//	while (scanf("%d%d", &a, &b) != EOF)
//	{
//		while (i * a % b != 0)
//		{
//			i++;
//		}
//		printf("%d\n", i * a);
//	}
//	return 0;
//}
#include<stdio.h>
#include<string.h>

void revers(char* left,char* right)
{
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
int main()
{
	char arr[101] = "I am a stu.";
	int len = strlen(arr);
	//1.ÄæÐò×Ö·û´®
	revers(arr, arr + len - 1);

	//´òÓ¡×Ö·û´®
	//printf("%s", arr);
	//2.ÄæÐòµ¥¸ö×Ö·û´®
	char* cur = arr;
	while (*cur)
	{
		char* start = cur;
		while (*cur != ' ' && *cur != '\0')
		{
			cur++;
		}
		char* end = cur - 1;
		revers(start, end);
		if (*cur == ' ')
			cur++;
	}
	printf("%s", arr);
	return 0;
}