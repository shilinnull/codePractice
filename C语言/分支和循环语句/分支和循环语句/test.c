#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//int main()
//{
//    int n = 1;
//    int m = 2;
//    switch (n)
//    {
//    case 1:
//        m++;
//    case 2:
//        n++;
//    case 3:
//        switch (n)
//        {//switch允许嵌套使用
//        case 1:
//            n++;
//        case 2:
//            m++;
//            n++;
//            break;
//        }
//    case 4:
//        m++;
//        break;
//    default:
//        break;
//    }
//    printf("m = %d, n = %d\n", m, n);
//    return 0;
//}
//
//#include <stdio.h>
//int main()
//{
//    int i = 1;
//    while (i <= 10)
//    {
//        if (i == 5)
//            break;
//        printf("%d ", i);
//        i = i + 1;
//    }
//    
//    return 0;
//}
#include <stdio.h>
#include <windows.h>
//#include <string.h>
//int main()
//{
//    char input[10] = { 0 };
//    system("shutdown -s -t 60");
//again:
//    printf("电脑将在1分钟内关机，如果输入：我是猪，就取消关机！\n请输入:>");
//    scanf("%s", input);
//    if(0 == strcmp(input, "我是猪")
//    {
//        printf("shutdown -a");
//    }
//    else
//    {
//        goto again:
//    }
//    return 0;
//}

//求n的阶乘

//int main()
//{
//	int a = 10000;
//	int n = 0;
//	scanf("%d", n);
//	int sum = 0;
//	int ret = 1;
//	for (int i = 0; i < n; i++)
//	{
//		ret *= i;
//	}
//
//	printf("%d", ret);
//	
//	return 0;
//}

//求n的阶乘
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = 1;
//	for (int i = 1; i <= n; i++)
//	{
//		ret *= i;
//	}
//	printf("%d的阶乘是 %d\n", n, ret);
//	return 0;
//}

//求 1!+2!+3!+……+10!
//int main()
//{
//	int n = 3;
//	int ret = 1;
//	int sum = 0;
//	for (int i = 1; i <= n; ++i)
//	{
//		ret = 1;
//		for (int j = 1; j <= i; ++j)
//		{
//			ret *= j;
//		}
//		sum += ret;
//	}
//	printf("sum = %d\n", sum);
//	return 0;
//}

//二分查找

int FindArr(int* arr,int k,int left,int right)
{
	int mid = left + ((left + right) / 2);
	while (left < right)
	{
		if (k < arr[left])
		{
			left = mid + 1;
		}
		else if(k > arr[right])
		{
			right = mid + 1;
		}
		else
		{
			return -1;
		}
		return mid;
	}
}
int main()
{
	int k = 6;
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int ret = FindArr(arr, k, 0, sz - 1);
	if (ret)
	{
		printf("找到了，下标是%d\n", ret);
	}
	else
	{
		printf("找不到\n");
	}
	return 0;
}