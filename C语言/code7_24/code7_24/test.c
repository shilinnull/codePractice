#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//int main()
//{
//	int flag = 0;
//	if (flag)
//		printf("hehe");
//
//
//	return 0;
//}


//int main()
//{
//	int month = 0;
//	scanf("%d", &month);
//	if (month >= 3 && month <= 5)
//		printf("春季");
//
//
//	return 0;
//}

//能被4整除不能被100整除或者能被400整除就是闰年
//int main()
//{
//	int year = 0;
//	scanf("%d", &year);
//	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
//		printf("yes");
//
//
//	return 0;
//}

//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	while (n)
//	{
//		printf("%d ", n % 10);
//		n = n / 10;
//	}
//
//
//	return 0;
//}


//int main()
//{
//	int sum = 0;
//
//	int i = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		//判断i是不是3的倍数
//		if (i % 3 == 0)
//		{
//			sum += i;
//		}
//			
//		
//	}
//	printf("%d ", sum);
//
//
//
//
//	return 0;
//}


//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int count = 0;
//	do 
//	{
//		n = n / 10;
//		count++;
//	} while (n);
//	printf("%d\n", count);
//
//	return 0;
//}


c
//
//#include<math.h>
//int main()
//{
//	int count = 0;
//	int i = 0;
//	for (i = 101; i <= 200; i+=2) //这里优化了
//	{
//		int flag = 1;
//		int j = 0;
//		for (j = 2; j <= sqrt(i); j++)//sqrt是库函数，用来计算开平方的
//		{
//			if (i % j == 0)
//			{
//				flag = 0;
//				break;
//			}
//		}
//		if (flag == 1)
//		{
//			count++;
//			printf("%d ", i);
//		}
//	}
//	printf("\ncount = %d\n", count);
//	return 0;
//}

//
//#include <stdio.h>
//
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		if (i = 5)
//			printf("%d ", i);
//	}
//	return 0;
//}


//#include <stdio.h>
//
//int main()
//{
//    printf("%5d\n", 123456);
//    return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	for (i = 3; i <= 100; i+=3)
//	{
//		printf("%d ", i);
//	}
//	return 0;
//}
//
//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	scanf("%d %d %d", &a,&b,&c);
//	if (a < b)
//	{
//		int tmp = 0;
//		tmp = a;
//		a = b;
//		b = tmp;
//	}
//	if (a < c)
//	{
//		int tmp = a;
//		a = c;
//		c = tmp;
//	}
//	if (b < c)
//	{
//		int tmp = b;
//		b = c;
//		c = tmp;
//	}
//	printf("a=%d b=%d c=%d\n", a, b, c);
//
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	int b = 0;
//	float c = 0.0;
//	int r = 0;
//	r = scanf("%d %d %d", &a, &b, &c);
//	printf("a = %d , b = %d,c = %f,r = %d\n", a, b, c, r);
//
//	return 0;
//}

//int func(int a)
//{
//    int b;
//    switch (a)
//    {
//    case 1: b = 30;
//    case 2: b = 20;
//    case 3: b = 16;
//    default: b = 0;
//    }
//    return b;
//}

//#include <stdio.h>
//int main() {
//	int x = 3;
//	int y = 3;
//	switch (x % 2) {
//	case 1:
//		switch (y)
//		{
//		case 0:
//			printf("first");
//		case 1:
//			printf("second");
//			break;
//		default: printf("hello");
//		}
//	case 2:
//		printf("third");
//	}
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int a = 0, b = 0;
//	for (a = 1, b = 1; a <= 100; a++)
//	{
//		if (b >= 20) break;
//		if (b % 3 == 1)
//		{
//			b = b + 3;
//			continue;
//		}
//		b = b - 5;
//	}
//	printf("%d\n", a);
//	return 0;
//}
//#include <stdio.h>
//
//
//int main()
//{
//    int a = 0;
//    int b = 0;
//    int c = 0;
//    while (~scanf("%d %d %d", &a, &b, &c))
//    {
//        if ((a + b > c) && (a + c > b) && (b + c > a))
//        {
//            //三角形
//            if (a == b && b == c)//等边三角形
//            {
//                printf("Equilateral triangle!\n");
//            }
//            else if (((a == b) && (b != c)) || ((a == c) && (c != b)) || ((b == c) && (c != a)))//等腰
//            {
//                printf("Isosceles triangle!\n");
//            }
//            else
//            {
//                printf("Ordinary triangle!\n");
//            }
//        }
//        else
//        {
//            //不是三角形
//            printf("Not a triangle!\n");
//        }
//    }
//    return 0;
//}



//int main()
//{
//	int n = 0;
//	int b = 0;
//	for (n = 1; n <= 9; n++)
//	{
//		for (b = 1; b <= 9; b++)
//		{
//			printf("%d*%d=%2d ", b, n, n * b);
//		}
//		printf("\n");
//	}
//	return 0;
//}


/*
思路：
1. 采用循环的方式输入一个数组
2. 使用max标记数组中的最大值，采用循环的方式依次获取数组中的每个元素，与max进行比较，如果arr[i]大于 
max，更新max标记的最大值，数组遍历结束后，max中保存的即为数组中的最大值。
*/
//int main()
//{
//	int arr[10] = { 0 };
//	int i = 0;
//	int max = 0;
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	max = arr[0];
//	for (i = 1; i < 10; i++)
//	{
//		if (arr[i] > max)
//		{
//			max = arr[i];
//
//		}
//	} 
//	printf("%d", max);
//
//	return 0;
//}

/*
思路：
1. 从上述表达式可以分析出
   a. 该表达式主要由100项，基数项为正，偶数项为负
2. 设置一个循环从1~100，给出表达式中的每一项：1.0/i, 注意此处不能使用1，否则结果全部为0
	然后使用flag标记控制奇偶项，奇数项为正，偶数项为负
	然后将所有的项相加即可
*/

//int main()
//{
//	int i = 0;
//	double sum = 0.0;
//	int flag = 1;
//	for (i = 1; i < 100; i++)
//	{
//		sum += flag * 1.0 / i;
//		flag = -flag;
//	}
//	printf("%lf\n", sum);
//
//	return 0;
//
//}
//



//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 0; i <= 100; i++)
//	{
//		if (i % 10 == 0)
//			count++;
//		if (i / 10 == 0)
//			count++;
//	}
//	printf("%d\n", count);
//	return 0;
//}

//打印100~200的素数
int main()
{
	int count = 0;
	int i = 0;
	for (i = 100; i <= 200; i++)
	{
		int flag = 1;
		int j = 0;
		for (j = 2; j <= i-1; j++)
		{
			if (i % j == 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			count++;
			printf("%d ", i);
		}
	}
	printf("\ncount = %d\n", count);
	return 0;
}









