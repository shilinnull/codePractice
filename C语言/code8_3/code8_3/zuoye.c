#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


//逆序输出
//
//int main()
//{
//    int arr[10] = { 0 };
//    for (int i = 0; i < 10; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    for (int j = 9; j >= 0; j--)
//    {
//        printf("%d", arr[j]);
//    }
//
//    return 0;
//}





//X形图案
//
//int main()
//{
//    int n = 0;
//    while (scanf("%d", &n))
//    {
//
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                if (i == j || (i + j) == n - 1)
//                {
//                    printf("*");
//                }
//                else
//                {
//                    printf(" ");
//                }
//            }
//            printf("\n");
//        }
//
//    }
//    return 0;
//}





//空心正方形图案
//
//int main()
//{
//    int n = 0;
//    while (scanf("%d", &n)!=EOF)
//    {
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                if (i == 0 || i == n - 1)
//                {
//                    printf("* ");
//                }
//                else if (j == 0 || j == n - 1)
//                {
//                    printf("* ");
//                }
//                else
//                {
//                    printf("  ");
//                }
//            }
//            printf("\n");
//
//        }
//    }
//
//    return 0;
//}

/*
给定两个数，求这两个数的最大公约数

例如：

输入：20 40

输出：20
*/


/*
最大公约数：即两个数据中公共约数的最大者。
求解的方式比较多，暴力穷举、辗转相除法、更相减损法、Stein算法算法
此处主要介绍：辗转相除法


思路：
例子：18和24的最大公约数
第一次：a = 18  b = 24  c = a%b = 18%24 = 18
      循环中：a = 24   b=18
第二次：a = 24   b = 18  c = a%b = 24%18 = 6
      循环中：a = 18   b = 6


第三次：a = 18   b = 6   c=a%b = 18%6 = 0
  循环结束

此时b中的内容即为两个数中的最大公约数。
*/

//
//int main()
//{
//	int a = 18;
//	int b = 24;
//	int c = 0;
//
//	while (c = a % b)
//	{
//		a = b;
//		b = c;
//	}
//
//	printf("%d\n", b);
//	return 0;
//}









//将数组A中的内容和数组B中的内容进行交换。（数组一样大）

//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6 };
//	int arr2[] = { 2,3,4,5,6,7 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	for (int i = 0; i < len; i++)
//	{
//		int tmp = arr[i];
//		arr[i] = arr2[i];
//		arr2[i] = tmp;
//	}
//
//	for (int i = 0; i < len; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	for (int i = 0; i < len; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//	return 0;
//}





/*
矩阵的转置
*/
//
//int main()
//{
//	int n = 0;
//	int m = 0;
//	scanf("%d %d", &n, &m);
//	int arr[n][m];
//
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < m; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//
//	for (i = 0; i < m; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			printf("%d ", arr[j][i]);
//		}
//		printf("\n");
//	}
//	return 0;
//}






/*
编写一个程序，从用户输入中读取10个整数并存储在一个数组中。然后，计算并输出这些整数的平均值。
*/
//#include<stdio.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int sum = 0;
//	for (int i = 0; i < sz; i++)
//	{
//		sum += arr[i];
//	}
//	printf("平均值是%f\n", sum * 1.0 / sz);
//
//	return 0;
//}

