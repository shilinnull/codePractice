#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>
//int main()
//{
//	int arr[10] = { 0 };//对数据进行初始化
//
//	printf("请依次输入数组个元素的值：\n");
//	for (int i = 0; i < 10; i++)//遍历数组
//	{
//		scanf("%d", &arr[i]);//从键盘上依次获取数据存入数组
//	}
//	printf("\n");//李海洋制作
//
//	printf("数组各元素逆序数粗：\n");
//	for (int i = 9; i >= 0; i--)//遍历数组
//	{
//		printf("%d ", arr[i]);//遍历数组进行打印
//	}
//	printf("\n");
//	printf("李海洋制作\n");
//	return 0;
//}

#include <stdio.h>  

//
//void bubbleSort(int arr[], int n) {
//    int i, j, temp;
//    for (i = 0; i < n - 1; i++) //排序n-1次
//    {
//        for (j = 0; j < n - i - 1; j++) //趟数
//        {
//            if (arr[j] > arr[j + 1]) //进行交换
//            {
//                // 交换 arr[j] 和 arr[j+1]  
//                temp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = temp;
//            }
//        }
//    }
//}
//
//int main() {
//    int arr[10];
//    int n, i;
//    printf("请输入一个正整数n(1<n≤10): ");
//    scanf("%d", &n);
//    printf("请输入%d个整数: ", n);
//    for (i = 0; i < n; i++) 
//    {
//        scanf("%d", &arr[i]);//输入数据
//    }
//    bubbleSort(arr, n);//调用函数
//    //李海洋制作
//    printf("排序后的数组: ");
//    for (i = 0; i < n; i++) 
//    {
//        printf("%d ", arr[i]);//打印数组排序后的数据
//    }
//    printf("\n");
//    printf("李海洋制作\n");
//    return 0;
//}

//#include <stdio.h>  
//
////3.有10个地区的面积，要求对它们按由小到大的顺序排列。
//int main() {
//    int areas[10] = { 23, 78, 34, 16, 95, 57, 43, 89, 61, 28 }; // 假设这是10个地区的面积  
//    int i, j, temp;
//
//    // 使用冒泡排序算法对面积进行排序  
//    for (i = 0; i < 9; i++) {
//        for (j = 0; j < 9 - i; j++) {
//            if (areas[j] > areas[j + 1]) {
//                temp = areas[j];
//                areas[j] = areas[j + 1];
//                areas[j + 1] = temp;
//            }
//        }
//    }
//    printf("李海洋制作\n");
//    // 输出排序后的结果  
//    printf("按面积从小到大排序后的结果：\n");
//    for (i = 0; i < 10; i++) {
//        printf("%d ", areas[i]);
//    }
//    printf("\n");
//
//    return 0;
//}

#include <stdio.h>  

//int main() {
//    int scr[10]; // 定义一个长度为10的数组来存储成绩  
//    int i;
//
//    // 循环输入每个数组元素，即每个同学的成绩  
//    printf("请输入10名同学的成绩：\n");
//    for (i = 0; i < 10; i++) {
//        scanf("%d", &scr[i]);
//    }
//    printf("李海洋制作\n");
//    // 循环输出每个数组元素，即每个同学的成绩  
//    printf("10名同学的成绩为：\n");
//    for (i = 0; i < 10; i++) {
//        printf("%d ", scr[i]);
//    }
//    printf("\n");
//
//    return 0;
//}


#include <stdio.h>  

int main() {
    int scr[10]; // 定义一个长度为10的数组来存储成绩  
    int i, sum = 0, max, min;
    double avg;

    // 循环输入每个数组元素，即每个同学的成绩  
    for (i = 0; i < 10; i++) {
        printf("请输入第%d个元素的值:",i + 1);
        scanf("%d", &scr[i]);
        sum += scr[i]; // 计算全班总成绩  
    }

    // 查找最大值和最小值  
    max = min = scr[0];
    for (i = 1; i < 10; i++) {
        if (scr[i] > max) {
            max = scr[i];
        }
        if (scr[i] < min) {
            min = scr[i];
        }
    }

    // 计算平均分  
    avg = sum / 10.0;

    printf("李海洋制作\n");

    // 循环输出每个数组元素，即每个同学的成绩  
    for (i = 0; i < 10; i++) {
        printf("%d ", scr[i]);
    }
    printf("\n");

    // 输出全班总成绩和平均分  
    printf("和是：%d\n", sum);
    printf("平均值是：%.2lf\n", avg);
    printf("最大值是：%d\n", max);
    printf("最小值是：%d\n", min);

    return 0;
}