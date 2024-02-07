#define _CRT_SECURE_NO_WARNINGS 1

/*
【今日题目】：
请实现以下三个数组操作的函数：
  1. 请实现GetMaxValOfArray函数，该函数接收一个整形数组，
  及元素个数，功能求数组中元素最大值并返回
  2. 请实现GetMinValOfArray函数，该函数接收一个整形数组，
  及元素个数，功能求数组中元素最小值并返回
  3. 请实现函数PrintArray，打印数组中所有元素
*/




#include <stdio.h>
// 获取数组中的最大值
int getmaxvalofarray(int arr[], int n) {
    if (n <= 0) {
        printf("数组元素个数必须大于0\n");
        return -1; // 或者通过错误码表示异常情况
    }
    int max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    return max_val;
}
// 获取数组中的最小值
int getminvalofarray(int arr[], int n) {
    if (n <= 0) {
        printf("数组元素个数必须大于0\n");
        return -1; // 或者通过错误码表示异常情况
    }
    int min_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }

    return min_val;
}
// 打印数组中的所有元素
void printarray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int arr[] = { 3, 7, 1, 9, 4, 2, 6, 8, 5 };
    int num_elements = sizeof(arr) / sizeof(arr[0]);
    // 获取数组中的最大值并打印
    int max_val = getmaxvalofarray(arr, num_elements);
    printf("数组中的最大值为: %d\n", max_val);
    // 获取数组中的最小值并打印
    int min_val = getminvalofarray(arr, num_elements);
    printf("数组中的最小值为: %d\n", min_val);
    // 打印数组中的所有元素
    printf("数组中的所有元素: ");
    printarray(arr, num_elements);
    return 0;
}
