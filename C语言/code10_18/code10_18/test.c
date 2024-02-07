#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//
//int main() {
//    int length, width, height;
//    int volume;
//
//    // 输入长、宽和高
//    printf("请输入长方体的长: ");
//    scanf("%d", &length);
//
//    printf("请输入长方体的宽: ");
//    scanf("%d", &width);
//
//    printf("请输入长方体的高: ");
//    scanf("%d", &height);
//
//    // 计算长方体的体积
//    volume = length * width * height;
//
//    // 输出计算结果
//    printf("长方体的体积是: %d\n", volume);
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
//	//产生100-200之间的数
//	int i = 0;
//	int j = 0;
//	for (i = 101; i <= 200; i+=2)
//	{
//		int flag = 1;//假设1是素数
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

//数9的个数

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