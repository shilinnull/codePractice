#define _CRT_SECURE_NO_WARNINGS 1

//
//
//#include<stdio.h>
//
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0;
//	for (i = 30; i >= 0; i-=2)
//	{
//		printf("%d ", (n >> i) & 1);
//	}
//	printf("\n");
//	for (i = 31; i >= 1; i -= 2)
//	{
//		printf("%d ", (n >> i) & 1);
//	}
//	return 0;
//}
//
//#include <stdio.h>
//int i;//0
//int main()
//{
//    i--;//-1
//    if (i > sizeof(i))//-1>4
//    {
//        printf(">\n");
//    }
//    else
//    {
//        printf("<\n");
//    }
//    return 0;
//}

//输入两个升序排列的序列，将两个序列合并为一个有序序列并输出。
/*
输入描述：
输入包含三行，
第一行包含两个正整数n, m，用空格分隔。n表示第二行第一个升序序列中数字的个数，
m表示第三行第二个升序序列中数字的个数。
第二行包含n个整数，用空格分隔。
第三行包含m个整数，用空格分隔。

输出描述：
输出为一行，输出长度为n+m的升序序列，
即长度为n的升序序列和长度为m的升序序列中的元素重新进行升序序列排列合并。
*/
//int main()
//{
//    int n = 0, m = 0;
//    scanf("%d %d", &n, &m);
//    int arr[5000] = { 0 };
//    //之前定义的数组元素个数为1000，测试用例通过但是提交不通过，找了好久也没发现哪里写错了，后来
//    //改成5000便通过了，我吐了哈...
//    int i = 0, j = 0, num = 0;
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d", &num);
//        arr[i] = num;
//    }
//    for (j = 0; j < m; j++)
//    {
//        scanf("%d", &num);
//        arr[i + j] = num;
//    }
//    //冒泡排序
//    for (i = 0; i < n + m; i++)
//    {
//        for (j = 0; j < n + m - i - 1; j++)
//        {
//            if (arr[j] > arr[j + 1])
//            {
//                int tmp = arr[j + 1];
//                arr[j + 1] = arr[j];
//                arr[j] = tmp;
//            }
//        }
//    }
//    for (i = 0; i < n + m; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}
//
//#include <stdio.h>
//
//int main() {
//    int y = 0;
//    int m = 0;
//    while (scanf("%d %d", &y, &m) != EOF)
//    {
//        int arr[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//        int day = arr[m-1];
//        if ((y % 4 == 0) && (y % 100 != 0) || (y % 400 == 0))
//        {
//            if (m == 2)
//                day += 1;
//        }
//        printf("%d", day);
//    }
//}
//#include <stdio.h>
//int i;
//int main()
//{
//    i--;
//    if (i > sizeof(i))
//    {
//        printf(">\n");
//    }
//    else
//    {
//        printf("<\n");
//    }
//    return 0;
//}

