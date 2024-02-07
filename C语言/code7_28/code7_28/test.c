#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
//int main()
//{
//    int i = 0;
//    int arr[10] = { 0 };
//    for (i = 0; i <= 9; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    for (i = 0; i <= 9; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//}

//
//#include<stdio.h>
//int main()
//{
//    int arr[] = { 1,2,3,4,5,6 };
//    //计算这个数组元素类型的大小单位是字节，这里是24个字节因为int类型在64位平台下是4个字节大小
//    printf("%d\n", sizeof(arr));
//    printf("%d\n", sizeof(arr) / sizeof(arr[0]));//这里就可以求出来这个数组的元素个数
//}
//



//#include<stdio.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 0;
//	scanf("%d", &k);
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int find = 0;
//	for (int i = 0; i < sz; i++)
//	{
//		if (k == arr[i])
//		{
//			printf("找到了，下标是%d！", i);
//			find = 1;
//			break;
//		}
//	}
//	if (find = 0)
//	{
//		printf("找不到");
//	}
//
//	return 0;
//}
//
//#include<stdio.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 0;
//	scanf("%d", &k);
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int left = 0;
//	int right = sz - 1;
//	int find = 0;
//	while (left <= right)
//	{
//		int mind = (left + right) / 2;
//		if (arr[mind] < k)
//		{
//			left = mind + 1;
//		}
//		else if (arr[mind] > k)
//		{
//			right = mind - 1;
//		}
//		else
//		{
//			printf("找到了下标是%d", mind);
//			find = 1;
//			break;
//		}
//	}
//	
//	if (find == 0)
//	{
//		printf("找不到");
//	}
//
//
//	return 0;
//}
//

//#include<stdio.h>
//int main()
//{
//    int i = 0;
//    int arr[10] = { 0 };
//    for (i = 0; i <= 9; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    for (i = 0; i <= 9; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//}

//
//#include<stdio.h>
//int main()
//{
//    int arr[] = { 1,2,3,4,5,6 };
//    //计算这个数组元素类型的大小单位是字节，这里是24个字节因为int类型在64位平台下是4个字节大小
//    printf("%d\n", sizeof(arr));
//    printf("%d\n", sizeof(arr) / sizeof(arr[0]));//这里就可以求出来这个数组的元素个数
//}
//



//#include<stdio.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 0;
//	scanf("%d", &k);
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int find = 0;
//	for (int i = 0; i < sz; i++)
//	{
//		if (k == arr[i])
//		{
//			printf("找到了，下标是%d！", i);
//			find = 1;
//			break;
//		}
//	}
//	if (find = 0)
//	{
//		printf("找不到");
//	}
//
//	return 0;
//}
// 
// 
// 二分查找
//
//#include<stdio.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 0;
//	scanf("%d", &k);
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int left = 0;
//	int right = sz - 1;
//	int find = 0;
//	while (left <= right)
//	{
//		//int mind = (left + right) / 2;
//		int mind = left + (right-left) / 2; 
//		if (arr[mind] < k)
//		{
//			left = mind + 1;
//		}
//		else if (arr[mind] > k)
//		{
//			right = mind - 1;
//		}
//		else
//		{
//			printf("找到了下标是%d", mind);
//			find = 1;
//			break;
//		}
//	}
//	
//	if (find == 0)
//	{
//		printf("找不到");
//	}
//	return 0;
//}
//
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 0;
//	scanf("%d", &k);
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int left = 0;
//	int right = sz - 1;
//	int find = 0;
//	while (left <= right)
//	{
//		int mind = left + (right - left) / 2;
//
//		if (arr[mind] < k)
//		{
//			left = arr[mind] + 1;
//		}
//		else if(arr[mind] > k)
//		{
//			right = arr[mind] + 1;
//		}
//		else
//		{
//			printf("找到了，下标是%d",mind);
//			find = 1;
//			break;
//		}
//	}
//	if (find == 0)
//		printf("找不到");
//	return 0;
//}
//

//#include<stdio.h>
//int main()
//{
//			//行 列
//	int arr[4][7] = { 1,2,3,4,5,6 };//不完全初始化
//	printf("%d", arr[0][0]);//这里打印arr[4][7]这个数组的第一个元素
//}


//#include<stdio.h>
//int main()
//{
//	int arr[3][4] = { {1,2,3},{1,2},{1} };
//	// 说的都是用下标表示
//	//{1,2,3}是放在第0行的第1，2，3列,arr[0][0],arr[0][1],arr[0][2]
//	//这里的{1,2}表示把1，2这两个数个放在下标第1行第1列和第一行第二列arr[1][0]和arr[1][1]
//	//{1}就是放在第三列arr[3][0]
//}
//

//
//#include <stdio.h>
//int main()
//{
//    int arr[2][5] = { 0 };
//    int i = 0;//遍历⾏
//    //输⼊
//    for (i = 0; i < 2; i++) //产⽣⾏号
//    {
//        int j = 0;
//        for (j = 0; j < 5; j++) //产⽣列号
//        {
//            scanf("%d", &arr[i][j]); //输⼊数据
//        }
//    }
//    printf("\n");
//    //输出数组
//    for (i = 0; i < 2; i++) //产⽣⾏号
//    {
//        int j = 0;
//        for (j = 0; j < 5; j++) //产⽣列号
//        {
//            printf("%d ", arr[i][j]); //输出数据
//        }
//        printf("\n");
//    }
//    return 0;
//}

