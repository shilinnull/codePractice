#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//
//int main() {
//    int length, width, height;
//    int volume;
//
//    // ���볤����͸�
//    printf("�����볤����ĳ�: ");
//    scanf("%d", &length);
//
//    printf("�����볤����Ŀ�: ");
//    scanf("%d", &width);
//
//    printf("�����볤����ĸ�: ");
//    scanf("%d", &height);
//
//    // ���㳤��������
//    volume = length * width * height;
//
//    // ���������
//    printf("������������: %d\n", volume);
//
//    return 0;
//}

#include<stdio.h>
//int main()
//{
//	char ch = 0;
//	while ((ch = getchar()) != EOF)
//	{
//		putchar(ch);
//	}
//
//	return 0;
//}

#include <math.h>
//int main()
//{
//	//����100-200֮�����
//	int i = 0;
//	int j = 0;
//	for (i = 101; i <= 200; i+=2)
//	{
//		int flag = 1;//����1������
//
//		for (j = 2; j < sqrt(i); j++)
//		{
//			if (i % j == 0)
//			{
//				flag = 0;
//				break;
//			}
//
//		}
//		if (flag == 1)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}


//int main()
//{
//	int n = 0;
//	int m = 0;
//	scanf("%d%d", &n, &m);
//	int r = 0;
//	while (r = m % n)
//	{
//		m = n;
//		n = r;
//	}
//	printf("%d\n", n);
//	return 0;
//}

//��9�ĸ���

//int main()
//{
//	int count = 0;
//	for (int i = 1; i <= 100;i++)
//	{
//		if (i % 10 == 9)
//		{
//			count++;
//		}
//		else if (i / 10 == 9)
//		{
//			count++;
//		}
//	}
//	printf("%d", count);
//	return 0;
//}

int main()
{
	int i = 0;
	double sum = 0.0;
	int flag = 1;
	for (i = 1; i < 100; i++)
	{
		sum += flag*1.0 / i;
		flag = -flag;
	}
	printf("%lf", sum);
	return 0;
}